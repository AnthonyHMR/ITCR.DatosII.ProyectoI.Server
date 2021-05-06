#ifndef ITCR_DATOSII_PROYECTOI_SERVER_JSONPARSER_H
#define ITCR_DATOSII_PROYECTOI_SERVER_JSONPARSER_H

#include <string>
#include <nlohmann/json.hpp>
#include <iomanip>
#include "../DataStructures/LinkedList.h"

using namespace std;
using json = nlohmann::json;
/**
 * @class jsonParser takes the post-memory-allocation info and sends it to the client.
 * This data is the memory address, the data name, the data value and the data references count
 */
class jsonParser {
private:
    void writeJsonBackup(json);
public:
    /**
     * @brief Class constructor
     */
    jsonParser();
    /**
     * @brief Class destructor
     */
    ~jsonParser();
    /**
     * @brief readJson reads the data generated after the allocation
     * and casts it to string
     * @return the result a json-string type of string easy to stream
     */
    string readJson();

protected:
    /**
     * @brief writeJson writes all the data generated post-memory-allocation in a Json file
     *
     * @param mem is the memory address where the data was allocated
     * @param label is the data's name
     * @param value is the data's value
     * @param reference is the data's number of reference count
     */
    void writeJson(string mem, string label, string value, string reference, basic_string<char>);
};


#endif //ITCR_DATOSII_PROYECTOI_SERVER_JSONPARSER_H
