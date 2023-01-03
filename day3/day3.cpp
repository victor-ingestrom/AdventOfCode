#include <fstream>
#include <iostream>
#include <string>
#include <vector>

// Answers: 7597, 2607

uint64_t calc_prio_sum(const std::vector<char>& prios)
{
    uint64_t sum = 0;
    for (auto const& ch : prios)
    {
        uint64_t val = 0;
        if (ch >= 'a' && ch <= 'z')
        {
            val = ch - 'a' + 1;
        }
        else if (ch >= 'A' && ch <= 'Z')
        {
            val = ch - 'A' + 27;
        }
        sum += val;
    }
    return sum;
}

int main()
{
    std::cout << "=========================================\n";
    std::cout << "Advent of Code - Day 3\n";
    std::cout << "=========================================\n";

    std::ifstream input("input3");
    std::string line;
    std::vector<char> items;
    std::vector<std::string> groups;
    std::vector<char> badges;
    while (input.good()) {
        std::getline(input, line);
        // Remove carriage return at the end of line
        if (!line.empty() && line[line.size() - 1] == '\r')
        {
            line.erase(line.size() - 1);
        }

        // Part 1
        size_t len = line.size();
        for (size_t i = 0; i < len/2; i++)
        {
            if (line.substr(len/2, len).find(line[i]) != std::string::npos)
            {
                items.push_back(line[i]);
                break;
            }
        }

        // Part 2
        groups.push_back(line);
        if (groups.size() == 3)
        {
            for (const char& c : groups[0])
            {
                if (groups[1].find(c) != std::string::npos && groups[2].find(c) != std::string::npos)
                {
                    badges.push_back(c);
                    break;
                }
            }
            groups.clear();
        }
    }
    input.close();

    uint64_t items_sum = calc_prio_sum(items);
    uint64_t badge_sum = calc_prio_sum(badges);

    std::cout << "Answer 1: " << items_sum << "\n";
    std::cout << "Answer 2: " << badge_sum << "\n";
}