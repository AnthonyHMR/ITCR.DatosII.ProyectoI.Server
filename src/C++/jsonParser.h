#ifndef ITCR_DATOSII_PROYECTOI_SERVER_JSONPARSER_H
#define ITCR_DATOSII_PROYECTOI_SERVER_JSONPARSER_H

#include <string>
#include <nlohmann/json.hpp>
#include <iomanip>

using namespace std;
using json = nlohmann::json;

class jsonParser {
public:
    jsonParser();
    ~jsonParser();
    string readJson();
protected:
    void writeJson(string mem, string, string, string);
};


#endif //ITCR_DATOSII_PROYECTOI_SERVER_JSONPARSER_H
