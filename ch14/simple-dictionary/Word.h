#ifndef WORD_H
#define WORD_H
#include <iostream>

using namespace std;

class Word
{
private:
    char word[20];
    char translation[20];
public:
    Word(const string& = "", const string& = "");
    ~Word();

    void setWord(const string&);

    void setTranslation(const string&);

    string getWord() const;

    string getTranslation() const;

};



#endif
