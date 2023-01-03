#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include <stack>
#include <algorithm>

// Answers: 919137, 2877389

constexpr uint64_t DISK_SIZE = 70000000;
constexpr uint64_t SPACE_FOR_UPDATE = 30000000;

int main()
{
    std::cout << "=========================================\n";
    std::cout << "Advent of Code - Day 7\n";
    std::cout << "=========================================\n";

    std::ifstream input("input7");
    std::string line;
    std::map<std::string, uint64_t> dirs;
    std::deque<std::string> path;
    while (std::getline(input, line)) {
        // Remove carriage return at the end of line
        if (!line.empty() && line[line.size() - 1] == '\r')
        {
            line.erase(line.size() - 1);
        }

        if (line[0] == '$')
        {
                // Read directory name and change directory
                auto cd_pos = line.find("cd ");
                if (cd_pos != std::string::npos) // command was cd
                {
                    std::string dir = line.substr(5, line.size());

                    if (dir == "..") {
                        path.pop_back();
                    } else {
                        path.emplace_back(dir);
                    }
                }
        }
        else if (line[0] >= '0' && line[0] <= '9')
        {
            uint64_t num = 0;
            for (auto const ch: line) {
                if (ch >= '0' && ch <= '9') {
                    num *= 10;
                    num += ch - '0';
                } else {
                    if (num) {
                        std::string dir_key{};
                        std::for_each(path.begin(), path.end(), [&dirs, &num, &dir_key](std::string const& dir){
                            dir_key += dir == "/" ? dir : dir + "/";
                            dirs[dir_key] += num;
                        });
                    }
                    num = 0;
                }
            }
        }
    }
    input.close();

    uint64_t space_needed = SPACE_FOR_UPDATE - (DISK_SIZE - dirs["/"]);
    uint64_t small_dir_sum = 0;
    uint64_t dir_to_remove_size = DISK_SIZE;
    for (auto const& dir : dirs)
    {
        const auto dir_size = dir.second;

        // Part 1
        if (dir_size < 100000)
        {
            small_dir_sum += dir_size;
        }

        // Part 2
        if (dir_size > space_needed && dir_size < dir_to_remove_size)
        {
            dir_to_remove_size = dir_size;
        }
    }

    std::cout << "First answer: " << small_dir_sum << "\n";
    std::cout << "Second answer: " << dir_to_remove_size << "\n";
}