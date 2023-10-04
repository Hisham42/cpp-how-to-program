#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <list>

int main() {

    std::list<std::string> list1 {"Ahmed", "Magdy", "Hisham", "Handy"};

    std::list<std::string> list2 {"Hamza", "Fairouz", "Dalida", "Mousa"};
    std::list<std::string> list3;

    list1.sort();
    list2.sort();
    

    std::merge(list1.begin(), list1.end(), list2.begin(), list2.end(), std::back_inserter(list3));

    std::ostream_iterator<std::string> output(std::cout, "\n");

    std::copy(list3.begin(), list3.end(), output);
    
}