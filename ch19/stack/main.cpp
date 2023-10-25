#include "Stack.h"
#include "List.h"

int main() {
    Stack<char> stack;
    List<char> list;

    stack.push('a');
    stack.push('b');
    stack.push('c');
    stack.push('d');
    stack.print();

    list.insert(stack.pop());
    list.insert(stack.pop());
    list.insert(stack.pop());
    list.insert(stack.pop());
    stack.print();
    list.print();
}