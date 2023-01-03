#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <assert.h>

// Answers: 67016, 200116

int main()
{
    std::cout << "=========================================\n";
    std::cout << "Advent of Code - Day 1\n";
    std::cout << "=========================================\n";

    std::ifstream input("input1");
    uint64_t elf_calories = 0;
    uint64_t most_calories = 0;
    std::vector<uint64_t> top_three(3);
    std::string line;
    while (std::getline(input, line))
    {
        uint64_t num = 0;
        for (auto const& ch: line) {
            if (ch >= '0' && ch <= '9') {
                num *= 10;
                num += ch - '0';
            } else {
                if (num) {
                    elf_calories += num;
                }
                num = 0;
            }
        }

        if (line[0] == '\r' || input.peek() == EOF)
        {
            // Part 1
            if (elf_calories > most_calories)
            {
                most_calories = elf_calories;
            }

            // Part 2
            auto it_min_element = std::min_element(top_three.begin(), top_three.end());
            if (elf_calories > *it_min_element)
            {
                *it_min_element = elf_calories;
            }
            assert(top_three.size() == 3);

            elf_calories = 0;
        }
    }
    input.close();

    std::cout << "Most calories: " << most_calories << "\n";
    std::cout << "Top three elves calories: " << std::accumulate(top_three.begin(), top_three.end(), decltype(top_three)::value_type(0)) << "\n";
}