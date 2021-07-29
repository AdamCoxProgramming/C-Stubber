
var fakeStringCreator = require("./createStringsForInserting");
var helpers = require("../Helpers/helpers");
var sourceEditor = require("../Helpers/SourceHelpers");
var sourceLocators = require("../Helpers/sourceLocators");

exports.processC = function (cContents, prototypes) {

    var contentEditor = new sourceEditor.fileEditor(cContents);

    AddDefinitionsAfterLastInclude(contentEditor, prototypes);

    RenameOringinalImplementations(contentEditor, prototypes);

    makeOriginalImpsGlobal(contentEditor, prototypes);

    return contentEditor.contents;
}

function AddDefinitionsAfterLastInclude(contentEditor, prototypes) {
    var defineString = "\n";
    prototypes.forEach(function (prototype) {
        defineString += fakeStringCreator.createDefinitionString(prototype) + "\n";
    })
    var insertIndex = sourceLocators.lastIncludeIndex(contentEditor);
    contentEditor.insertAtIndex(contentEditor.nextLineIndex(insertIndex), defineString);
}

function RenameOringinalImplementations(contentEditor, prototypes) {
    prototypes.forEach(function (prototype) {
        var endIndex = sourceLocators.findFunctionDefinition(contentEditor, prototype.name, prototype.returnType) + prototype.name.length;
        contentEditor.insertAtIndex(endIndex, fakeStringCreator.originalPrefix);
    })
}

function makeOriginalImpsGlobal(contentEditor, prototypes) {
    prototypes.forEach(function (prototype) {
        var endIndex = sourceLocators.findFunctionDefinition(contentEditor, prototype.name + fakeStringCreator.originalPrefix , prototype.returnType);
        var line = contentEditor.getLine(endIndex);
        contentEditor.replace(line, line.replace("static", ""));
    })
}
