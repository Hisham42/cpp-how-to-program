#include "Tool.h"

Tool::Tool(unsigned int rec, const string& nam, unsigned int quan, double cos)
{
    setRecord(rec);
    setToolName(nam);
    setQuantity(quan);
    setCost(cos);
}

Tool::~Tool()
{
}

void Tool::setRecord(unsigned int r) {
    record = r;
}
void Tool::setToolName(const string& tName) {

    size_t length{tName.length()};
    length = (length < 20 ? length : 19);
    tName.copy(toolName, length);
    toolName[length] = '\0';

}
void Tool::setQuantity(unsigned int q) {
    quantity = q;
}
void Tool::setCost(double c) {
    cost = c;
}

unsigned int Tool::getRecord() const {
    return record;
}

string Tool::getToolName() const {
    return toolName;
}

unsigned int Tool::getQuantity() const {
    return quantity;
}

double Tool::getCost() const {
    return cost;
}


