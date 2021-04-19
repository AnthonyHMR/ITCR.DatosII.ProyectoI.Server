#include "jsonParser.h"
#include <fstream>

jsonParser::jsonParser() {}

void jsonParser::writeJson(void *memoryAddress, string label, string value, string references) {
    json resultsJson;
    resultsJson["memoryAddress"] = *static_cast<std::string*>(memoryAddress);
    resultsJson["label"] = label;
    resultsJson["value"] = value;
    resultsJson["references"] = references;

    ofstream writeResults("../results.json");
    writeResults<< std::setw(4) << resultsJson << std::endl;
}

string jsonParser::readJson() {
    std::ifstream readResults("../results.json");
    json resultsJson;
    readResults >> resultsJson;

    return to_string(resultsJson);
}

jsonParser::~jsonParser() {

}