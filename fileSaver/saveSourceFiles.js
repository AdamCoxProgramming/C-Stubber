
var helpers = require("../Helpers/helpers");
var _ = require("lodash");
const fs = require('fs');


exports.replaceFiles = function (filesToSave, outputDirectory) {

    filesToSave.forEach(function (file) {
        try {
            var path = helpers.findFile(file.fileName, outputDirectory);
            saveFile(file.contents, path);
        } catch (e) {
            // this only gets called if tempoary files are in use by the ide, we dont need to update these so they are okay to skip
        }
    })
}

function saveFile(contents, path) {
    try {
        if (!filesContentsMatchString(path, contents)) {
            fs.writeFileSync(path, contents);
            console.log(path.split('\\').pop());
        }
    } catch (err) {
        throw new Error("Error saving file :  " + path + err.toString());
    }
}

function filesContentsMatchString(path, content) {
    var data = fs.readFileSync(path);
    var buf = Buffer.from(content, 'utf8');
    return data.equals(buf);
}
