
var fileType = require("../fileType");
var ussageProcessor = require("./processUsage");

exports.processUsageFiles = function (files, functionPrototypes) {
    var processedFiles = [];

    files.forEach(function (file) {
        var processedContents = file.contents;
        if (usesStubs(file.contents)) processedContents = ussageProcessor.processUsageFile(file.contents, functionPrototypes);
        processedFiles.push(fileType.createFile(file.fileName, processedContents));
    })
    return processedFiles;
}

function usesStubs(contentEditor) {
    return contentEditor.indexOf("USING_FAKE") != -1;
}