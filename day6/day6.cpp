#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

// Answers: 1702, 3559

int main()
{
    std::cout << "=========================================\n";
    std::cout << "Advent of Code - Day 6\n";
    std::cout << "=========================================\n";

    constexpr uint64_t SEQ_LENGTH_PART1 = 4; // Change to 4 to get answer for first part
    constexpr uint64_t SEQ_LENGTH_PART2 = 14; // Change to 4 to get answer for first part

    std::ifstream input("input6");
    char c;
    std::vector<char> seq;
    uint64_t n_char = 0;
    uint64_t part1_offset = 0;
    while (input.get(c))
    {
        n_char++;
        auto it = std::find(seq.begin(), seq.end(), c);
        if (it != seq.end())
        {
            seq.erase(seq.begin(), it + 1);
        }
        seq.push_back(c);

        // Part 1
        if (seq.size() >= SEQ_LENGTH_PART1 && !part1_offset)
        {
            part1_offset = n_char;
        }

        // Part 2
        if (seq.size() >= SEQ_LENGTH_PART2)
        {
            break;
        }
    }
    input.close();

    std::cout << "Offset Part 1: " << part1_offset << "\n";
    std::cout << "Offset Part 2: " << n_char << "\n";

}