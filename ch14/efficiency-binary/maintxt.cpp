#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]) {

    // program to write integers to a text and a binary files
    // program should read values to vectors

    int startingInt = stoi(argv[1]);
    int numOfValues = stoi(argv[2]);

    fstream txtFile("text.txt", ios::out);

    for (size_t i = startingInt; i < numOfValues + startingInt; i++)
    {
        txtFile << i << endl;

    }
    

}

