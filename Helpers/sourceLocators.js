
exports.firstIncludeIndex = function (contentEditor) {
    var firstIncludeIndex = contentEditor.indexOf("include");
    return contentEditor.lastIndexOf("#", firstIncludeIndex);
}

exports.findSafeGuardIfIndex = function (contentEditor) {
    return contentEditor.indexOf("#define");

}

exports.findEndIfIndex = function (contentEditor) {
    return contentEditor.lastIndexOf("#endif");
}

exports.lastIncludeIndex = function (contentEditor) {
    var lastInclude = contentEditor.lastIndexOf("#include");
    return contentEditor.lastIndexOf("#", lastInclude);
}

exports.findFunctionDefinition = function (contentEditor, functionName, returnType) {

    var cContents = contentEditor.contents;
    var fromIndex = 0;

    while (fromIndex <= cContents.length) {

        var startIndex = contentEditor.indexOf(functionName, fromIndex);

        if (isPrototype(cContents, startIndex) || isNotFullName(cContents, startIndex, functionName)) {
            if (fromIndex >= startIndex + 1) break;
            fromIndex = startIndex + 1;
            continue;
        }

        var retIndex = cContents.lastIndexOf(returnType, startIndex);

        var subStr = cContents.slice(retIndex, startIndex);

        var noWhiteSpace = subStr.replace(/[\n\r\s\t]+/g, '');

        if (noWhiteSpace.length == returnType.length) return startIndex;
        else fromIndex = startIndex + 1;
    }

    throw new Error("could not find function defintion for : " + functionName);
}

function isPrototype(contents, index) {
    var openBracketIndex = contents.indexOf('{', index);
    var semiColonIndex = contents.indexOf(';', index);
    if (semiColonIndex > openBracketIndex) return false
    else return true;
}

function isNotFullName(contents, index, name) {
    var openBracketIndex = contents.indexOf('(', index);
    var semiColonIndex = contents.indexOf(' ', index);
    var next = Math.min(openBracketIndex, semiColonIndex);

    var funcName = contents.slice(index, next);
    if (funcName != name) return true
    else return false;

}