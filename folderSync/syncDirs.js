
const fs = require('fs-extra');
var recursive = require('recursive-readdir-synchronous');

exports.addFileToDir = function (filePath, dir) {
    dir += "\\" + filePath
    fs.copyFileSync(filePath, dir);
}

var ignores = [];

exports.copyAcrossNewFiles = function (srcDir, targetDir, ignoresArr) {
    ignores = ignoresArr;
    fs.copySync(srcDir, targetDir, shouldCopy);
}

const shouldCopy = (src, dest) => {
    if (isPathToAFile(dest) && fs.existsSync(dest)) {
        return false;
    }
    return !shouldExcludePath(src);
}

exports.removeDeletedFiles = function (InputDirectory, OutputDirectory, ExcludedSyncDirs) {
    var allFiles = recursive(OutputDirectory);
    var filterdFiles = [];
    allFiles.forEach(function (file) {
        var inputPath = correspondingPathInInput(file, InputDirectory);
        if (!fs.existsSync(inputPath) && !shouldExcludePath(inputPath)) fs.removeSync(file);
    });
}

function correspondingPathInInput(inputDir, InputDirectoryRel) {
    var noDir = inputDir.split("\\");
    noDir.shift();
    var noDirPath = noDir.join('/');
    return InputDirectoryRel + "/" + noDirPath;
}

exports.updateFiles = function (srcDir, targetDir, filesNotToKeepUpdated) {
    ignores = filesNotToKeepUpdated;
    fs.copySync(srcDir, targetDir, shouldSyncAtPath);
}

const shouldSyncAtPath = (src, dest) => {
    return !shouldExcludePath(src);
}

function isPathToAFile(path) {
    return path.lastIndexOf('.') > path.lastIndexOf('/');
}

function shouldExcludePath(path) {
    for (i = 0; i < ignores.length; i++) {
        if (path.includes(ignores[i])) return true;
    }
    return false;
}
