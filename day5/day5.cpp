#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <assert.h>

// Answers: DHBJQJCCW , WJVRLSJJT

void print_top_boxes(std::vector<std::deque<char>>& boxes)
{
    for (auto const& stack : boxes)
    {
        if (!stack.empty()) {
            std::cout << stack.back();
        }
    }
    std::cout << "\n";
}

int main()
{
    std::cout << "=========================================\n";
    std::cout << "Advent of Code - Day 5\n";
    std::cout << "=========================================\n";

    std::ifstream input("input5");
    std::string line;
    std::vector<std::deque<char>> boxes{50};
    std::vector<std::vector<uint64_t>> move_instructions;
    while (std::getline(input, line))
    {
        uint16_t n_char = 0;
        uint16_t col = 0;
        bool read_box = false;
        if (line[0] != 'm')
        {
            // Place boxes in a vector of deque
            for (auto const c : line)
            {
                if (read_box)
                {
                    boxes[col].push_front(c);
                    read_box = false;
                }

                if (c == '[')
                {
                    read_box = true;
                }

                if (n_char != 0 && n_char % 4 == 0)
                {
                    col++;
                }
                n_char++;
            }
        }
        else
        {
            // Read move instructions
            move_instructions.emplace_back();
            std::vector<uint64_t>& move_info = move_instructions.back();
            uint16_t num = 0;
            for (auto const& ch : line)
            {
                if (ch >= '0' && ch <= '9')
                {
                    num *= 10;
                    num += ch - '0';
                }
                else
                {
                    if (num)
                    {
                        move_info.push_back(num);
                    }
                    num = 0;
                }
            }
            assert(move_info.size() == 3);
            assert(move_info[0] > 0);
            assert(move_info[1] > 0);
            assert(move_info[2] > 0);
        }
    }
    input.close();
    auto boxes2 = boxes; // Make a copy for part 2

    for (auto const& move_info : move_instructions)
    {
        const uint64_t n_boxes = move_info[0];
        std::deque<char>& source_stack = boxes[move_info[1] - 1];
        std::deque<char>& destination_stack = boxes[move_info[2] - 1];
        std::deque<char>& source_stack2 = boxes2[move_info[1] - 1];
        std::deque<char>& destination_stack2 = boxes2[move_info[2] - 1];

        // Move boxes part 1
        destination_stack.insert(destination_stack.end(),  source_stack.rbegin(), source_stack.rbegin() + static_cast<int>(n_boxes));
        source_stack.erase(source_stack.end() - static_cast<int>(n_boxes), source_stack.end());

        // Move boxes part 2
        destination_stack2.insert(destination_stack2.end(), source_stack2.end() - static_cast<int>(n_boxes), source_stack2.end());
        source_stack2.erase(source_stack2.end() - static_cast<int>(n_boxes), source_stack2.end());
    }

    std::cout << "Top boxes part 1:";
    print_top_boxes(boxes);

    std::cout << "Top boxes part 2:";
    print_top_boxes(boxes2);
}









