
var helpers = require("../Helpers/helpers");
var stringCreator = require("./createStringsForInserting");
var sourceEditor = require("../Helpers/SourceHelpers");
var sourceLocators = require("../Helpers/sourceLocators");
var _ = require("lodash");

exports.processMain = function (cContents, dependancyNames, functionPrototypes) {

    var contentEditor = new sourceEditor.fileEditor(cContents);

    addExternIncludesAtTop(functionPrototypes, contentEditor);

    addFFFGlobalDefines(contentEditor);

    addIncludesAtTop(dependancyNames, contentEditor);

    var functionNames = _.map(functionPrototypes, "name");

    setOriginalBehaviour(functionNames, contentEditor);

    return contentEditor.contents;
}

function addExternIncludesAtTop(prototypes, contentEditor) {
    prototypes.forEach(function (prototype) {
        var externDef = stringCreator.createExternOriginalFunctionString(prototype.name, prototype.returnType, prototype.args);
        contentEditor.insertAtIndex(0, externDef + '\n');
    })
}

function addFFFGlobalDefines(contentEditor) {
    contentEditor.insertAtIndex(0, "DEFINE_FFF_GLOBALS\n");
}

function addIncludesAtTop(dependancyNames, contentEditor) {
    dependancyNames.forEach(function (name) {
        contentEditor.insertAtIndex(0, stringCreator.createIncludeString(name) + '\n');
    })
}

function setOriginalBehaviour(functionNames, contentEditor) {
    var resetSection = "";
    functionNames.forEach(function (name) {
        if (name != "main")
            resetSection += (stringCreator.createSetOriginalFuncString(name) + '\n');//This is to stop a bug/special case, should be looked into
    })
    var braceIndex = findMainOpenBraceIndex(contentEditor.contents);
    contentEditor.insertAtIndex(braceIndex + 1, "\n" + resetSection);
}

function findMainOpenBraceIndex(contents) {
    var mainIndex = contents.indexOf("int main()");
    return contents.indexOf('{', mainIndex);
}