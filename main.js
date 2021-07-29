
var fileSelector = require("./dependancyLoader/selectDependancys");
var Processor = require("./processSourceFiles/stubDependancy");
var fileSaver = require("./fileSaver/saveSourceFiles");
var fileLoader = require("./dependancyLoader/loadFile");
var mainProcessor = require("./processSourceFiles/processMain");
var processUsage = require("./processSourceFiles/processUsageFiles");
var fileType = require("./fileType");
var dirSyncer = require("./folderSync/syncDirs");
var _ = require("lodash");

var config = require("./configuration")

var fffHeaderPath = "./fff.h"

function processProject () {

    var sourceFiles = loadSourceFiles();

    var processedSourceFiles = processFiles(sourceFiles);

    syncDirectorys(processedSourceFiles);

    saveFiles(processedSourceFiles);
}

function loadSourceFiles() {
    console.log("loading files ...");
    return fileSelector.selectSourceFiles(config.getInputDirectory(), config.getDependancyNames());
}

function processFiles(sourceFiles) {
    console.log("processing files ...");
    var processedSourceFiles = Processor.processDependancys(config.getDependancyNames(), sourceFiles);

    var usageSourceFiles = fileSelector.selectUsageFiles(config.getTestsFolder(), [config.getMainFileName()]);

    var processedUsageFiles = processUsage.processUsageFiles(usageSourceFiles, config.getAllFunctionPrototypes());

    processedSourceFiles = processedSourceFiles.concat(processedUsageFiles);

    var mainContents = fileLoader.loadFileContents(config.getMainFileName() + ".c", config.getInputDirectory());

    var processedMainContents = mainProcessor.processMain(mainContents, config.getDependancyNames(), config.getAllFunctionPrototypes());

    processedSourceFiles.push(fileType.createFile(config.getMainFileName() + ".c", processedMainContents));

    return processedSourceFiles;
}

function syncDirectorys(processedSourceFiles) {
    console.log("syncing directorys ...");
    dirSyncer.addFileToDir(fffHeaderPath,config.getSourceFileDir());

    dirSyncer.copyAcrossNewFiles(config.getInputDirectory(), config.getOutputDirectory(), config.getExcludedSyncDirs());

    dirSyncer.removeDeletedFiles(config.getInputDirectory(), config.getOutputDirectory(),config.getExcludedSyncDirs());

    var filesNotToUpdate = _.map(processedSourceFiles, "fileName").concat(config.getExcludedSyncDirs());

    dirSyncer.updateFiles(config.getInputDirectory(), config.getOutputDirectory(), filesNotToUpdate);
}

function saveFiles(files) {
    console.log("saving processed files that have changed:");
    fileSaver.replaceFiles(files, config.getOutputDirectory());
}

processProject();