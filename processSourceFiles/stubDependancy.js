
var CProcessor = require("./processC");
var HeaderProcessor = require("./processHeader");
var _ = require("lodash");

var config = require("../configuration");

exports.processDependancys = function (dependancyNames, sourceFiles) {

    var processedSourceFiles = [];

    dependancyNames.forEach(function (name) {
        var cContents = getContentsForFileName(name + ".c", sourceFiles);
        var headerContents = getContentsForFileName(name + ".h", sourceFiles);

        var prototypes = config.getPrototypes(name);

        var newHeader = HeaderProcessor.processHeader(headerContents, prototypes);
        processedSourceFiles.push({ "fileName": name + ".h", "contents": newHeader });

        var newC = CProcessor.processC(cContents, prototypes);
        processedSourceFiles.push({ "fileName": name + ".c", "contents": newC });

    });
    return processedSourceFiles;
}

function getContentsForFileName(name, files) {
    var file = _.find(files, (file) => { return file.fileName == name });
    return file.contents;
}
