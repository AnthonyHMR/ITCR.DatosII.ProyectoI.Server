//
// Created by juanpr on 12/4/21.
//

#ifndef ITCR_DATOSII_PROYECTOI_SERVER_REQUEST_H
#define ITCR_DATOSII_PROYECTOI_SERVER_REQUEST_H
#include <string>

using namespace std;
/**
 * @class Request object represents the data types info sended by the client
 */
class Request {
public:
    /**
     * Request data type getter
     * @return data type attribute
     */
    const string &getDataType() const;
    /**
     * Request data type setter
     */
    void setDataType(const string &dataType);
    /**
     * Request label getter
     * @return label attribute
     */
    const string &getLabel() const;
    /**
     * Request label setter
     */
    void setLabel(const string &label);
    /**
     * Request expression getter
     * @return expression attribute
     */
    const string &getExpression() const;
    /**
     * Request expression setter
     */
    void setExpression(const string &expression);
    /**
     * Request value getter
     * @return value attribute
     */
    const string &getValue() const;
    /**
     * Request value setter
     */
    void setValue(const string &value);
    /**
     * Request reset getter
     * @return reset attribute
     */
    const string &getReset() const;
    /**
     * Request reset setter
     */
    void setReset(const string &reset);

public:
    string dataType = "";
    string label = "";
    string expression = "";
    string value= "";
    string reset = "";
};


#endif //ITCR_DATOSII_PROYECTOI_SERVER_REQUEST_H
