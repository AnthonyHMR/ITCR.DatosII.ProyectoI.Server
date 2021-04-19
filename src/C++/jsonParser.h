#ifndef ITCR_DATOSII_PROYECTOI_SERVER_JSONPARSER_H
#define ITCR_DATOSII_PROYECTOI_SERVER_JSONPARSER_H

#include <string>

using namespace std;

class jsonParser {
public:
    jsonParser(string jAddress, int nObjects);
    ~jsonParser();
    void writeJson(void*, string, string, string);
    string readJson();
private:
    string address;
    int objects;
};


#endif //ITCR_DATOSII_PROYECTOI_SERVER_JSONPARSER_H
