#include <iostream>
#include <vector>

using namespace std;

bool isPalindrome(vector<int>&);

int main() {
    
    vector<int> h{1, 2, 3 , 4, 3, 2, 1};

    vector<int> h1{1, 3, 3 , 4, 3, 2, 1};

    vector<int> h2{8, 2, 2 , 9, 3, 2, 8};
   
    isPalindrome(h);
    isPalindrome(h1);

    isPalindrome(h2);





}

bool isPalindrome(vector<int>&a) {

    auto Iterator = a.cbegin();
    for (auto reverseIterator = a.crbegin(); reverseIterator != a.crend() || Iterator != a.cend(); ++reverseIterator, ++Iterator)
    {
        if (*Iterator != *reverseIterator)
        {
            cout << "False" << endl;
            return false;
        }
        
    }
    cout << "True" << endl;
    return true;

}

