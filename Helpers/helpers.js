
var fs = require('fs');
var path = require('path');
var stringCreator = require("../processSourceFiles/createStringsForInserting");
var _ = require("lodash");

exports.insertAtIndex = function (str, index, add) {
    var count = str.length;
    var firstBit = str.slice(0, index);
    var endBit = str.slice(index, count);
    return firstBit + add + endBit
}

exports.findFile = function (fileName, directory) {

    if (fileName == null || directory == null) throw new Error("file name and directory should not be null when find a file");

    var files = exports.searchRecursive(directory, fileName);

    if (files.length == 0) throw new Error("could not find : " + fileName + " in directory : " + directory);
    else if (files.length > 1) {
        console.log(files);
        throw new Error("multiples files with the name : " + fileName + " were found in the output directory");
    }

    return files[0];
}

exports.searchRecursive = function (directory, pattern) {
    // This is where we store pattern matches of all files inside the directory
    var results = [];
    var dir = _.clone(directory);

    //console.log(pattern);

    // Read contents of directory
    fs.readdirSync(dir).forEach(function (dirInner) {
        // Obtain absolute path
        dirInner = path.resolve(dir, dirInner);

        // Get stats to determine if path is a directory or a file
        var stat = fs.statSync(dirInner);

        // If path is a directory, scan it and combine results
        if (stat.isDirectory()) {
            results = results.concat(exports.searchRecursive(dirInner, pattern));
        }

        // If path is a file and ends with pattern then push it onto results
        if (stat.isFile()) {
            var asArray = dirInner.split('\\');
            var listFileName = asArray[asArray.length - 1];
            if (listFileName.toLowerCase() == pattern.toLowerCase() ) results.push(dirInner);
        }
    });

    return results;
};

exports.isIndexInComment = function (string, index) {
    var lineEndIndex = string.lastIndexOf('\n', index);
    var lastSingleLineComment = string.lastIndexOf('//', index);
    if (lastSingleLineComment > lineEndIndex) return true;

    var openComment = string.lastIndexOf('/*', index);
    var closeComment = string.lastIndexOf('*/', index);
    if (openComment > closeComment) return true;

    return false;
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

exports.addExternIncludesAtTop = function (prototypes, contents) {
    var externIncludes = "";
    prototypes.forEach(function (prototype) {
        externIncludes += stringCreator.createExternOriginalFunctionString(prototype.name, prototype.returnType, prototype.args) + '\n';
    })
    return "\n" + externIncludes + '\n' + contents;
}

exports.extractLine = function (index, contents) {

    var prevLineEndIndex = contents.lastIndexOf('\n', index) + 1;
    var lineEnd = contents.indexOf('\n', index) + 1;
    return contents.slice(prevLineEndIndex, lineEnd);
}

exports.isEquivalent = function (a, b) {
    // Create arrays of property names
    var aProps = Object.getOwnPropertyNames(a);
    var bProps = Object.getOwnPropertyNames(b);

    // If number of properties is different,
    // objects are not equivalent
    if (aProps.length != bProps.length) {
        return false;
    }

    for (var i = 0; i < aProps.length; i++) {
        var propName = aProps[i];

        // If values of same property are not equal,
        // objects are not equivalent
        if (a[propName] !== b[propName]) {
            return false;
        }
    }

    // If we made it this far, objects
    // are considered equivalent
    return true;
}