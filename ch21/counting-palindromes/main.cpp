#include <iostream>
#include <string>
#include <sstream>
int main() {
    
    std::stringstream ss;
    std::string aa;
    std::string bb;


    getline(std::cin, aa);

    ss << aa;
    int count{0};

    while (!ss.eof())
    {
        ss >> bb;
        if (bb[bb.size() - 1] == '.')
        {
            bb.erase(bb.size() - 1);
        }
        
        int j{0};
        int num{0};
        for (size_t i = 0; i < bb.size(); i++)
        {
            if (i == bb.size() - 1 - j)
            {
                break;
            }
            
            if (bb[i] != bb[bb.size()-1 - j])
            {
                num++;
            }
            j++;
            
        }
        if (num == 0)
        {
            count++;
        }
        
    }
    

    std::cout << count << std::endl;

    

}