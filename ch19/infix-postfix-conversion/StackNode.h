#ifndef STACKNODE_H
#define STACKNODE_H
#include <array>

template<typename T>
class StackNode
{
private:
    int calculatePrecedence (char& Operator) {
        enum class Category {Default=0, One=1, Two, Three};
        
        Category precedence = Category::Default;

        if (Operator == '+' || Operator == '-')
        {
            precedence = Category::One;
        }
        else if (Operator == '*' || Operator == '/')
        {
            precedence = Category::Two;
        }
        else if (Operator == '%' || Operator == '^')
        {
            precedence = Category::Three;
        }
        
        return static_cast<int>(precedence);
    }
public:
    T value;
    StackNode<T>* right;

    StackNode(T data) : value(data), right(nullptr) {}
    StackNode() : value(T()), right(nullptr) {}
    
    bool isOperator() {
        std::array<char, 6> op = {'+', '-', '*', '/', '^', '%'};
        
        for (auto i = op.cbegin(); i != op.cend(); i++ )
        {
            if (value == *i)
                return true;
        }
        return false;
        
    }

    bool hasGreaterOrEqualPrecedenceThan(StackNode<char> op2) {

        int op1Pre = calculatePrecedence(this->value);
        int op2Pre = calculatePrecedence(op2.value);

        if (op1Pre > op2Pre || op1Pre == op2Pre)
        {
            return true;
        }
        else
            return false;
    }

    
};



#endif 