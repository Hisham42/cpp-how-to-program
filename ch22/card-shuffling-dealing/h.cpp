#include <iostream>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {

        string str{""};
        int sSize = s.size();
        int z = -1;
        int stringSize{0};

        for (int i = 0; i < sSize; i++)
        {
            z = s.find_last_of(s[i], sSize);
            stringSize = z - i + 1;
            if (z > i)
            {
                while (z != i)
                {
                    if (str.size() < stringSize && checkPalindrome(s, i, stringSize))
                    {   
                        str = "";
                        for (int c = i; c < z +1; c++)
                        {
                            str.push_back(s[c]);
                        }
                    
                        
                    }
                    else
                    {
                        z = s.find_last_of(s[i], z-1);
                        stringSize = z - i + 1;
                    }
                }
            }
            else {
                if (str.size() < stringSize)
                {
                    str = "";
                    for (int c = i; c < z +1; c++)
                    {
                        str.push_back(s[c]);
                    } 
                }

            }
        }

       return str;
    }
    bool checkPalindrome(string& s, int start, int size)
    {
        int last = start + size - 1;
        for (int i = 1; start + i < last - i; i++ )
        {
            if(s[start + i] != s[last - i])
            {
                return false;
            }
            
        }
        return true;
    }
};




int main() {

    string a = "aabbccaa";
    Solution s;

    cout << s.longestPalindrome(a) << endl;
}   

/*




*/