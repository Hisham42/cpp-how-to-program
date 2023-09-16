#ifndef TOOL_H
#define TOOL_H
#include <iostream>

using namespace std;

class Tool
{
private:
    unsigned int record, quantity;
    char toolName[20];
    double cost;
public:
    Tool(unsigned int=0, const string& = "", unsigned int=0, double=0);
    ~Tool();

    void setRecord(unsigned int);
    void setToolName(const string&);
    void setQuantity(unsigned int);
    void setCost(double);

    unsigned int getRecord() const;
    string getToolName() const;
    unsigned int getQuantity() const;
    double getCost() const;



};



#endif
