//
// Created by juanpr on 12/4/21.
//

#include "Request.h"

const string &Request::getDataType() const {
    return dataType;
}

void Request::setDataType(const string &dataType) {
    Request::dataType = dataType;
}

const string &Request::getLabel() const {
    return label;
}

void Request::setLabel(const string &label) {
    Request::label = label;
}

const string &Request::getExpression() const {
    return expression;
}

void Request::setExpression(const string &expression) {
    Request::expression = expression;
}


bool Request::isReference1() const {
    return isReference;
}

void Request::setIsReference(bool isReference) {
    Request::isReference = isReference;
}

const string &Request::getValue() const {
    return value;
}

void Request::setValue(const string &value) {
    Request::value = value;
}