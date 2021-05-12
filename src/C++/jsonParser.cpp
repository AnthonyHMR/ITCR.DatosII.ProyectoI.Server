#include "jsonParser.h"
#include <fstream>

jsonParser::jsonParser() {}

void jsonParser::writeJson(string mem, string label, string value, string reference, basic_string<char> log) {
    json resultsJson;

    resultsJson["memoryAddress"] = mem;
    resultsJson["label"] = label;
    resultsJson["value"] = value;
    resultsJson["references"] = reference;
    resultsJson["log"] = log;

    ofstream writeResults("../results.json");
    writeResults<< std::setw(5) << resultsJson << std::endl;

    writeJsonBackup(resultsJson);
}

string jsonParser::readJson() {
    std::ifstream readResults("../results.json");
    json resultsJson;
    readResults >> resultsJson;

    return to_string(resultsJson);
}

void jsonParser::writeJsonBackup(json backupResults) {
    ifstream currentFile("../backupResults.json");
    json currentObject;
    currentFile >>currentObject;
    currentObject["Results"] += backupResults;
    ofstream writeJson;
    writeJson.open("../backupResults.json");
    writeJson <<currentObject;

    writeJson.close();
}

jsonParser::~jsonParser() {
}