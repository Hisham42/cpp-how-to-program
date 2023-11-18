#include <iostream>
#include <random>
#include <array>

std::string toU(std::string& a) {
    a[0] = toupper(a[0]);

    return a;
}


int main() {

    std::array<std::string, 5> article = {"the", "a", "one", "some", "any"};
    std::array<std::string, 5> noun = {"boy", "girl", "dog", "town", "car"};
    std::array<std::string, 5> verb = {"drove", "jumbed", "ran", "walked", "skipped"};
    std::array<std::string, 5> preposition = {"to", "from", "over", "under", "on"};

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(0, 4);


    for (size_t i = 0; i < 5; i++)
    {
        /* code */
    
    

        std::string sentence =  toU(article[distribution(gen)]) + " "  + noun[distribution(gen)] + " "
                                + verb[distribution(gen)] + " " + preposition[distribution(gen)] + " " +
                                article[distribution(gen)] + " " + noun[distribution(gen)] + ".";


        std::cout << sentence << std::endl;

    }

}