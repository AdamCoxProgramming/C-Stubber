
var helpers = require("./Helpers/helpers");
var sourceEditor = require("./Helpers/SourceHelpers");
var sourceLocators = require("./Helpers/sourceLocators");
var _ = require("lodash");

exports.loadFunctionsConfig = function (files) {

    var dependancys = [];

    files.forEach(function (file) {
        var filesPrototypes = getFakeRequests(file.contents);
        if (filesPrototypes != null) addToDependancy(dependancys, filesPrototypes);
    });
    return dependancys;
}

function getFakeRequests(contents) {
    var contentEditor = new sourceEditor.fileEditor(contents);
    var prototypes = [];
    contentEditor.forAllIndexesOf("USING_FAKE", function (index) {
        var line = contentEditor.getLine(index);
        var prototype = extractPrototype(line);
        if (prototype != null) prototypes.push(prototype);
    })
    return prototypes;
}

function extractPrototype(line) {
    try {
        var input = line.slice(line.indexOf('(') + 1, line.indexOf(']'));
        var inputArgs = input.split(",");

        var prototype = {};

        prototype.dependancyName = removeUnwantedChars(inputArgs[0]);
        prototype.name = removeUnwantedChars(inputArgs[1]);
        prototype.returnType = removeUnwantedChars(inputArgs[2]);

        var argsRaw = line.slice(line.indexOf('[') + 1, line.indexOf(']')).split(',');

        prototype.args = [];

        argsRaw.forEach(function (arg) {
            var processedArg = removeUnwantedChars(arg);
            if (processedArg != '') prototype.args.push(processedArg);
        })
        return prototype;
    } catch (err) {
        throw new Error("incorrect USING_FAKE defintion : " + line +
            'format expected : USING_FAKE( "filename" , "functionName" , "returnType"  , ["arg1","arg2" ... ] );');
    }
}

function removeUnwantedChars(val) {
    var noQuote = val.replace(/"/g, '');
    return noQuote.trim();
}

function addToDependancy(dependancys, prototypes) {
    prototypes.forEach(function (prototype) {
        var dep = getDependancy(dependancys, prototype.dependancyName);
        if (dep == null) {
            dep = { "name": prototype.dependancyName, "prototypes": [] };
            var edited = prototype;
            delete edited.dependancyName;
            dep.prototypes.push(edited);
            dependancys.push(dep);
        } else {
            var edited = prototype;
            delete edited.dependancyName;
            if (!prototypeAllreadyDefined(edited, dep.prototypes)) dep.prototypes.push(edited)
        }
    })
}

function prototypeAllreadyDefined(prototype, prototypes) {
    var res = false;
    prototypes.forEach(function (p) {
        if (p.name == prototype.name) {
            res = true;
        }
    })
    return res;
}

function getDependancy(dependancys, dependancyName) {
    return _.filter(dependancys, (dep) => { return dep.name == dependancyName })[0];
}