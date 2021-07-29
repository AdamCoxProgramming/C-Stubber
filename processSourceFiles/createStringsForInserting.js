
exports.originalPrefix = "_Original";
const fakePrefix = "_fake"

exports.createDeclarationString = function (prototype) {
    return createFFFAnouncementString(prototype, "DECLARE");
}

exports.createDefinitionString = function (prototype) {

    return createFFFAnouncementString(prototype, "DEFINE");
}

function createFFFAnouncementString(prototype, type) {
    if (prototype.returnType == null || prototype.name == null) throw new Error("nulls createString");

    var funcType;
    if (prototype.returnType == null || prototype.returnType.includes("void")) funcType = "VOID"
    else funcType = "VALUE";

    var string = type + "_FAKE_" + funcType + "_FUNC( ";

    if (funcType != "VOID") string = string + prototype.returnType + " , ";

    string = string + prototype.name;

    if (prototype.args != null && prototype.args.length != 0) string = string += " , " + prototype.args.join(" , ");

    return string + " )";
}

exports.createIncludeString = function (depName) {
    return '#include "' + depName + '.h"';
}

exports.createSetOriginalFuncString = function (functionName) {
    return functionName + fakePrefix + ".custom_fake = " + functionName + exports.originalPrefix + ';';
}

exports.createExternOriginalFunctionString = function (functionName, returnType, args) {
    return "extern " + returnType + " " + functionName + exports.originalPrefix + "( " + args.join(' , ') + " );";
}

exports.createResetFuncString = function (functionName) {
    return functionName + fakePrefix + ".custom_fake = " + functionName + exports.originalPrefix;
}
