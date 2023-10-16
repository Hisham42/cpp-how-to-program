#include "Word.h"

Word::Word(const string& wor, const string& tra)
{
    setWord(wor);
    setTranslation(tra);
}

Word::~Word()
{
}

void Word::setWord(const string& wor) {

    size_t length{wor.length()};
    length = (length < 20 ? length : 19);
    wor.copy(word, length);
    word[length] = '\0';

}

void Word::setTranslation(const string& tra) {

    size_t length{tra.length()};
    length = (length < 20 ? length : 19);
    tra.copy(translation, length);
    translation[length] = '\0';

}

string Word::getWord() const {
    return word;
}

string Word::getTranslation() const {
    return translation;
}
