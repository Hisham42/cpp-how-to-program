#include "Stack.h"
#include "StackNode.h"

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

bool hasGreaterOrEqualPrecedenceThan(char op1, char op2) {

        int op1Pre = calculatePrecedence(op1);
        int op2Pre = calculatePrecedence(op2);

        if (op1Pre > op2Pre || op1Pre == op2Pre)
        {
            return true;
        }
        else
            return false;
    }

bool isOperator(char c) {
        std::array<char, 6> op = {'+', '-', '*', '/', '^', '%'};
        
        for (auto i = op.cbegin(); i != op.cend(); i++ )
        {
            if (c == *i)
                return true;
        }
        return false;
        
    }

std::string convertToPostfix(std::string infix) {
    
    std::string postfix;

    Stack<char> stack1('('); // 1
    infix.push_back(')'); //2

    auto i = infix.cbegin();
    while (!stack1.isempty() || i != infix.cend())
    {
        if (isdigit(*i)) {
            postfix.push_back(*i);
            postfix.push_back(' ');
        }
        
        else if (*i == '(') {
            stack1.push(*i);
            postfix.push_back(' ');
        }

        else if (isOperator(*i)) {
            while (isOperator(stack1.stackRight()) && hasGreaterOrEqualPrecedenceThan(stack1.stackRight(), *i))
            {
                postfix.push_back(stack1.stackRight());
                stack1.pop();
                postfix.push_back(' ');
            }

            stack1.push(*i);
            
        }

        else if (*i == ')') {
            while (isOperator(stack1.stackRight()) && hasGreaterOrEqualPrecedenceThan(stack1.stackRight(), *i))
            {
                postfix.push_back(stack1.stackRight());
                stack1.pop();
            }
            
            while (!stack1.isempty())
            {
                stack1.pop();
            }
            postfix.push_back(' ');    
        }
        i++;
    }
    return postfix;
}
    
int intValue(char c) {
    return c - '0';
}

int calculate(int op1, char operatorSign, int op2) {
    if (operatorSign == '+')
    {
        return op1 + op2;
    }
    else if (operatorSign == '-')
    {
        return op1 - op2;
    }
    else if (operatorSign == '*')
    {
        return op1 * op2;
    }
    else if (operatorSign == '/')
    {
        return op1 / op2;
    }
    else if (operatorSign == '%')
    {
        return op1 % op2;
    }
    return 0;
}

int evaluatePostfixExpression(std::string postfix) {
    
    Stack<int> stack2;

    auto i = postfix.cbegin();


    while (i != postfix.cend())
    {
        if (isdigit(*i)) {
            stack2.push(intValue(*i));
        }

        else if (isOperator(*i)) {
            int x = stack2.stackRight();
            stack2.pop();
            int y = stack2.stackRight();
            stack2.pop();
            stack2.push(calculate(y, *i, x));
        }
        i++;
    }

    return stack2.stackRight();

}


int main() {
    
    std::string infix = "(6 + 2) * 5 - 8 / 4";
    
    std::string postfix = convertToPostfix(infix);

    int x = evaluatePostfixExpression(postfix);

    std::cout << infix << std::endl;

    std::cout << postfix << std::endl;

    std::cout << x << std::endl;

}   