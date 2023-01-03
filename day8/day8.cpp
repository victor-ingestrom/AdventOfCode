#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// Answers: 1851, 574080

template<typename T>
uint64_t get_number_of_visible(T begin, T end, const uint16_t& tree_height)
{
    uint64_t visible_trees = 0;
    for (auto it = begin; it != end; ++it)
    {
        if (*it >= tree_height)
        {
            visible_trees++;
            break;
        }
        visible_trees++;
    }
    return visible_trees;
}

int main()
{
    std::cout << "=========================================\n";
    std::cout << "Advent of Code - Day 8\n";
    std::cout << "=========================================\n";

    // Read file content into vector of vectors
    std::ifstream input("input8");
    std::string line;
    std::vector<std::vector<uint16_t>> trees;
    uint16_t row = 0;
    while (std::getline(input, line)) {
        trees.emplace_back();
        for (auto const ch: line) {
            if (ch >= '0' && ch <= '9') {
                trees[row].push_back(ch - '0');
            }
        }
        row++;
    }

    // Check visibility for each tree
    uint64_t n_visible = 0;
    uint64_t best_scenic_score = 0;
    for (size_t i = 0; i < trees.size(); i++)
    {
        for (size_t j = 0; j < trees[i].size(); j++)
        {
            if (i == 0 || i == trees.size() - 1 || j == 0 || j == trees[i].size() - 1)
            {
                // All trees on the edges are visible
                n_visible++;
                continue;
            }

            const uint16_t tree_height = trees[i][j];
            auto check_if_visible = [&tree_height](uint16_t test) -> bool
            {
                if (test < tree_height)
                {
                    return true;
                }
                return false;
            };

            uint64_t scenic_score = 1;
            // Check row left
            bool is_visible = std::all_of(trees[i].begin(), trees[i].begin() + static_cast<int>(j), check_if_visible);
            scenic_score *= get_number_of_visible(trees[i].rend() - static_cast<int>(j), trees[i].rend(), tree_height);

            // Check row right
            is_visible = is_visible || std::all_of(trees[i].begin() + static_cast<int>(j) + 1, trees[i].end(), check_if_visible);
            scenic_score *= get_number_of_visible(trees[i].begin() + static_cast<int>(j) + 1, trees[i].end(), tree_height);

            // Check column up
            std::vector<uint16_t> col_up{};
            for (size_t r = 0; r < i; r++)
            {
                col_up.push_back(trees[r][j]);
            }
            is_visible = is_visible || std::all_of(col_up.begin(), col_up.end(), check_if_visible);
            scenic_score *= get_number_of_visible(col_up.rbegin(),col_up.rend(), tree_height);

            // Check column down
            std::vector<uint16_t> col_down{};
            for (size_t r = i + 1; r < trees.size(); r++)
            {
                col_down.push_back(trees[r][j]);
            }
            is_visible = is_visible || std::all_of(col_down.begin(), col_down.end(), check_if_visible);
            scenic_score *= get_number_of_visible(col_down.begin(), col_down.end(), tree_height);

            // Part 1
            if (is_visible)
            {
                n_visible++;
            }

            // Part 2
            if (scenic_score > best_scenic_score)
            {
                best_scenic_score = scenic_score;
            }
        }
    }
    input.close();

    std::cout << "Answer 1 - Number of visible: " << n_visible << "\n";
    std::cout << "Answer 2 - Best scenic score: " << best_scenic_score << "\n";
}
