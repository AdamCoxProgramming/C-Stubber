
var fileLoader = require("./loadFile");
var fs = require("fs");
var recursive = require('recursive-readdir-synchronous');

exports.selectSourceFiles = function (directory, depNames) {

    if (directory == null || depNames == null) throw new Error(" nulls selectDependancys");

    var sourceFiles = [];
    depNames.forEach(function (depName) {

        var cSourceFile = fileLoader.loadFileContents(depName + ".c", directory);
        sourceFiles.push({ "fileName": depName + ".c", "contents": cSourceFile });

        var headerSourceFile = fileLoader.loadFileContents(depName + ".h", directory);
        sourceFiles.push({ "fileName": depName + ".h", "contents": headerSourceFile });
    });

    return sourceFiles;
}

exports.selectUsageFiles = function (directory, ignores) {
    var fileNames = getFilesFromPath(directory, ".c");
    var sourceFiles = [];
    fileNames.forEach(function (depName) {
        if (shouldExcludeName(depName, ignores)) return;

        var cSourceFile = fileLoader.loadFileContents(depName, directory);
        sourceFiles.push({ "fileName": depName, "contents": cSourceFile });
    });
    return sourceFiles;
}

function getFilesFromPath(path, extension) {
    var dir = findRecursivly(path);
    return dir.filter(fileName => { return fileName.endsWith(extension) });
}

function findRecursivly(path){
    let dirs = recursive(path);
    dirs.forEach(function(di,index){
        dirs[index] = di.split("\\")[di.split("\\").length -1]
    })
    return dirs;
}

function shouldExcludeName(name, ignores) {
    for (i = 0; i < ignores.length; i++) {
        if (name.includes(ignores[i])) {

            return true;
        }
    }
    return false;
}