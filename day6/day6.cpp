#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <assert.h>


// Answers: 1702, 3559

int main() {
    std::cout << "Advent of Code - Day 6\n\n";

    // Read file content into stack
    std::ifstream input("input6");
    std::string line;
    char c;

    std::vector<char> seq;
    uint16_t n_char = 0;
    while (input.get(c))
    {
        n_char++;
        auto it = std::find(seq.begin(), seq.end(), c);
        if (it != seq.end())
        {
            seq.erase(seq.begin(), it + 1);
        }
        seq.push_back(c);

        // DEBUG
        for (auto const &s : seq)
        {
            std::cout << s;
        }
        std::cout << "\n";


        if (seq.size() >= 14)
        {
            break;
        }


    }

    std::cout << "offset:" << n_char << "\n";

}