
var _ = require("lodash");
var fileSelector = require("./dependancyLoader/selectDependancys");
var prototypeLoader = require("./loadFunctionConfig");
var config = require("./config");

exports.getInputDirectory = function () {
    return config.inputDirectory;
}

exports.getMainFileName = function () {
    return config.mainFileName;
}

exports.getDependancyNames = function () {
    return _.map(config.dependancys, "name");
}

exports.getPrototypes = function (dependancyName) {
    var dependancy = _.find(config.dependancys, (dependancy) => { return dependancy.name == dependancyName });
    return dependancy.prototypes;
}

exports.getOutputDirectory = function () {
    return config.outputDirectory;
}

exports.getTestsFolder = function () {
    return exports.getInputDirectory() + config.testsFolder;
}

exports.getExcludedSyncDirs = function () {
    return config.dontSyncDirs;
}

exports.getSourceFileDir = function () {
    return exports.getInputDirectory() + config.sourceDir;
}

exports.getAllFunctionPrototypes = function () {
    var protoypeNames = [];
    config.dependancys.forEach(function (dependancy) {
        if (dependancy.prototypes != null)
            protoypeNames = protoypeNames.concat(dependancy.prototypes);
    })
    return _.uniq(protoypeNames);
}

var usageSourceFiles = fileSelector.selectUsageFiles(exports.getTestsFolder(), [exports.getMainFileName()]);

config.dependancys = prototypeLoader.loadFunctionsConfig(usageSourceFiles);
