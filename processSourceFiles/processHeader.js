
var fakeStringCreator = require("./createStringsForInserting");
var helpers = require("../Helpers/helpers");
var sourceEditor = require("../Helpers/SourceHelpers");
var sourceLocators = require("../Helpers/sourceLocators");

exports.processHeader = function (header, prototypes) {

    var contentEditor = new sourceEditor.fileEditor(header);

    addDeclarationsAtTheEnd(contentEditor, prototypes);

    addFFFInclude(contentEditor);

    return contentEditor.contents;

}

function addDeclarationsAtTheEnd(contentEditor, prototypes) {
    var delaractions = ""
    prototypes.forEach(function (prototype) {
        delaractions += fakeStringCreator.createDeclarationString(prototype) + "\n"  ;
    })
    var EndIfIndex = sourceLocators.findEndIfIndex(contentEditor);
    contentEditor.insertAtIndex(contentEditor.prevLineIndex(EndIfIndex),  delaractions);
}

function addFFFInclude(contentEditor) {
    var includeString = fakeStringCreator.createIncludeString("fff");
    var safeGaurdIndex = sourceLocators.findSafeGuardIfIndex(contentEditor);
    contentEditor.insertAtIndex(contentEditor.nextLineIndex(safeGaurdIndex),"\n" + includeString);
}
