
var helpers = require("../Helpers/helpers");

var fs = require('fs');


exports.loadFileContents = function (fileName, directory) {

    if (fileName == null || directory == null) throw new Error("nulls load file");

    var filePath = helpers.findFile(fileName, directory);

    var contents = fs.readFileSync(filePath, 'utf8');

    return contents;
}
