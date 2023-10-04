/*
    Use an istream_iterator<int>, the copy algorithm and a
    back_inserter to read the contents of a text file that contains int values separated by whitespace.
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <sstream>

int main() {

    std::vector<int> vInts;

    std::ifstream txtFile("int.txt", std::ios::in);
    
    if (!txtFile)
    {
        std::cerr << "Cannot Open File" << std::endl;
    }
    
    std::istream_iterator<int> inputBegin(txtFile);
    std::istream_iterator<int> inputEnd;
    std::ostream_iterator<int> output(std::cout, " ");


    std::copy(inputBegin, inputEnd, std::back_inserter(vInts));

    std::copy(vInts.begin(), vInts.end(), output);
    
    
}