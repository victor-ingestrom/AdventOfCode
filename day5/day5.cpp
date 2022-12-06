
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <stack>
#include <assert.h>


int main()
{
    std::cout << "Advent of Code - Day 5\n\n";

    // Read file content into stack
    std::ifstream input("input5");
    std::string line;
    std::vector<std::deque<char>> boxes{50};
    while (std::getline(input, line))
    {
        uint16_t n_char = 0;
        uint16_t col = 0;
        bool read_box = false;

        std::cout << line << "\n";

        if (line[0] != 'm')
        {
            // Place boxes in a vector of queues
            for (auto const c : line)
            {
                if (read_box)
                {
                    boxes.at(col).push_front(c);
                    std::cout << "Added " << boxes.at(col).front() << " to column " << col << "\n";
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
            std::vector<uint16_t> move_info;
            uint16_t num = 0;
            for (auto const ch : line)
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
            assert(move_info[1] > 0);


            // Move boxes
            for (auto i = 0; i < move_info[0]; i++)
            {
                const uint16_t n_boxes = move_info[0];
                std::deque<char>& source_stack = boxes.at(move_info[1] - 1);
                std::deque<char>& destination_stack = boxes.at(move_info[2] - 1);

                char box_to_move = source_stack.at(source_stack.size() - n_boxes + i);
                std::cout << "box2move: " << box_to_move << "\n";
                std::cout << "size: " << source_stack.size() << "\n";
                destination_stack.push_back(box_to_move);
                source_stack.erase(source_stack.begin() + source_stack.size() - n_boxes + i);
            }
        }
    }

    // Print top boxes
    std::cout << "Top boxes:\n";
    for (auto b : boxes)
    {
        if (!b.empty()) {
            std::cout << b.back();
        }
    }


}









