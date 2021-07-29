
exports.fileEditor = class Editor {
    constructor(contents) {

        this.contents = contents;

        this.insertAtIndex = function (index, add) {
            if (index < 0) throw new Error("invalid index");
            if (index == null || add == null) throw new Error("nulls")
            var count = this.contents.length;
            var firstBit = this.contents.slice(0, index);
            var endBit = this.contents.slice(index, count);
            this.contents = firstBit + add + endBit
        }

        this.prevLineIndex = function (index) {
            return Math.max( this.contents.lastIndexOf('\n', index),0);
        }

        this.nextLineIndex = function (index) {
            return indexOfNoComments(this.contents, '\n', index);
        }

        this.getLine = function (index) {
            var prevLineEndIndex = this.contents.lastIndexOf('\n', index) + 1;
            var lineEnd = this.contents.indexOf('\n', index) + 1;
            return this.contents.slice(prevLineEndIndex, lineEnd);
        }

        this.indexOf = function (string, index) {
            return indexOfNoComments(this.contents, string, index);
        }

        this.lastIndexOf = function (string, index) {
            return lastIndexOfNoComments(this.contents, string, index);
        }

        this.forAllIndexesOf = function (string, callback) {
            var index = 0;
            while (indexOfNoComments(this.contents, string, index) != -1) {
                index = indexOfNoComments(this.contents, string, index);
                callback(index);
                index++;
            }
        }

        this.replace = function (pattern, string) {
            this.contents = this.contents.replace(pattern, string)
        }

    }
}

function indexOfNoComments(string, pattern, from) {
    if (from == null) from = 0;
    var index = from;
    while (string.indexOf(pattern, index) != -1) {
        var localIndex = string.indexOf(pattern, index);
        if (!indexIsInComment(string, localIndex)) return localIndex;
        else index = localIndex +1;
    }
    return -1;
}

function lastIndexOfNoComments(string, pattern, from) {
    if (from == null) from = string.length;
    var index = from;
    while (string.lastIndexOf(pattern, index) != -1) {
        var localIndex = string.lastIndexOf(pattern, index);
        if (!indexIsInComment(string, localIndex)) return localIndex;
        else index = localIndex - 1;
    }
    return -1;
}

function indexIsInComment(string, index) {
    var lineEndIndex = string.lastIndexOf('\n', index);
    var lastSingleLineComment = string.lastIndexOf('//', index);
    if (lastSingleLineComment > lineEndIndex) return true;

    var openComment = string.lastIndexOf('/*', index);
    var closeComment = string.lastIndexOf('*/', index);
    if (openComment > closeComment) return true;

    return false;
}
