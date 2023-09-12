#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]) {

    // program to write integers to a text and a binary files
    // program should read values to vectors

    int startingInt = stoi(argv[1]);
    int numOfValues = stoi(argv[2]);

    fstream binFile;

    binFile.open("binary.bin", ios::out | ios::binary);

    for (int i = startingInt; i < numOfValues + startingInt; i++)
    {
        binFile.write(reinterpret_cast<const char*>(&i), sizeof(int));

    }

    binFile.close();
    
    binFile.open("binary.bin", ios::in | ios::binary);
    while (binFile)
    {
        int i;
        binFile.read(reinterpret_cast<char*>(&i), sizeof(int));

        
    }
    
    

}

