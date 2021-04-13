//
// Created by juanpr on 12/4/21.
//

#ifndef ITCR_DATOSII_PROYECTOI_SERVER_REQUEST_H
#define ITCR_DATOSII_PROYECTOI_SERVER_REQUEST_H
#include <string>

using namespace std;
class Request {


public:
    const string &getDataType() const;

    void setDataType(const string &dataType);

    const string &getLabel() const;

    void setLabel(const string &label);

    const string &getExpression() const;

    void setExpression(const string &expression);

    bool isReference1() const;

    void setIsReference(bool isReference);

public:
    string dataType = "";
    string label = "";
    string expression = "";
    string value= "";

    const string &getValue() const;

    void setValue(const string &value);

    bool isReference = false;

};


#endif //ITCR_DATOSII_PROYECTOI_SERVER_REQUEST_H
