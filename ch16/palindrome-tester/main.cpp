#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <iterator>

void palindromeTester(std::string);

int main() {

    palindromeTester("able was i  , ere i sa;w elba");
    
    
    
}


void palindromeTester(std::string userInput) {
    

    
   
    auto it = std::remove_if(userInput.begin(), userInput.end(), 
    [](char x) {
            if (isalpha(x)) {
                return false;
            } else {
                return true; 
            }
        });


    userInput.erase(it, userInput.end());


    std::string strCopy;

    std::reverse_copy(userInput.begin(), userInput.end(), std::back_inserter(strCopy));   

    if (userInput == strCopy)
        std::cout << "is a palindrome" << std::endl;
    else
        std::cout << "is not a palindrome" << std::endl;
}