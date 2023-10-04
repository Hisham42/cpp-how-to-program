#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
#include <iterator>

int main() {

    #if 0
    std::array<int, 20> a {
        2, 2, 5, 5, 4,
        4, 3, 3, 0, 0,
        1, 1, 6, 6, 7,
        7, 8, 8, 9, 9
        };

    std::ostream_iterator<int> output{std::cout, " "};

    auto newEnd = std::unique(a.begin(), a.end());

    std::copy(a.begin(), newEnd, output);
    #endif

    std::vector<int> v;


    auto it = std::back_inserter(v);

    std::fill_n(it, 5, 2);

    std::fill_n(it, 5, 1);

    std::ostream_iterator<int> output2{std::cout, " "};
    std::copy(v.begin(), v.end(), output2);



    
    
}