
var stringCreator = require("./createStringsForInserting");
var sourceEditor = require("../Helpers/SourceHelpers");
var sourceLocators = require("../Helpers/sourceLocators");

exports.processUsageFile = function (cContents, functionPrototypes) {

    var contentEditor = new sourceEditor.fileEditor(cContents);

    renameFAKE_FUNCToRESET_FAKE(contentEditor);

    var usedPrototypes = findStubbedFunctions(contentEditor, functionPrototypes);

    addExternIncludes(contentEditor, usedPrototypes);

    replaceResetFunctions(contentEditor);

    removeUsingFakes(contentEditor);

    return contentEditor.contents;
}

function findStubbedFunctions(contentEditor, functionPrototypes) {
    var usedPrototypes = [];
    functionPrototypes.forEach(function (prototype) {
        var isUsedInFile = contentEditor.indexOf(prototype.name) != -1;
        if (isUsedInFile) usedPrototypes.push(prototype);
    })
    return usedPrototypes;
}

function addExternIncludes(contentEditor, prototypes) {
    var externIncludes = "\n";
    prototypes.forEach(function (prototype) {
        externIncludes += stringCreator.createExternOriginalFunctionString(prototype.name, prototype.returnType, prototype.args) + '\n';
    })
    var lastInclude = sourceLocators.lastIncludeIndex(contentEditor);
    contentEditor.insertAtIndex(contentEditor.nextLineIndex(lastInclude), externIncludes);
}

function renameFAKE_FUNCToRESET_FAKE(contentEditor) {
    contentEditor.contents = contentEditor.contents.replace(/FAKE_FUNC/g, "RESET_FAKE");
}

function replaceResetFunctions(contentEditor) {
    contentEditor.forAllIndexesOf("RESET_FUNC", function (index) {
        var funcName = extractFuncName(contentEditor, index);
        var endOfLineIndex = contentEditor.indexOf(';', index);
        var fullLine = contentEditor.contents.slice(index, endOfLineIndex);
        var resetString = stringCreator.createResetFuncString(funcName);
        contentEditor.replace(fullLine, resetString);
    });
}

function extractFuncName(contentEditor, startIndex) {
    var bracetIndex = contentEditor.indexOf("(", startIndex);
    var spaceIndex = contentEditor.indexOf(")", startIndex);
    return contentEditor.contents.slice(bracetIndex + 1, spaceIndex);
}

function removeUsingFakes(contentEditor) {
    contentEditor.forAllIndexesOf("USING_FAKE", function (index) {
        var line = contentEditor.getLine(index);
        contentEditor.replace(line, "\n")
    })
}
