#include <fstream>
#include <iostream>
#include <assert.h>

// Answers: 12679, 14470

int main()
{
    std::cout << "=========================================\n";
    std::cout << "Advent of Code - Day 2\n";
    std::cout << "=========================================\n";

    std::ifstream input("input2");
    char me;
    char u;
    uint64_t total_score = 0;
    uint64_t total_score2 = 0;
    while (input >> u) {
        input >> me;

        switch (u) {
            case 'A':
                if (me == 'X') // Draw - Lose
                {
                    total_score += 4;
                    total_score2 += 3;
                    break;
                }
                else if (me == 'Y') // Win - Draw
                {
                    total_score += 8;
                    total_score2 += 4;
                    break;
                }
                else if (me == 'Z') // Lose - Win
                {
                    total_score += 3;
                    total_score2 += 8;
                    break;
                }
            case 'B':
                if (me == 'X') // Lose
                {
                    total_score += 1;
                    total_score2 += 1;
                    break;
                }
                else if (me == 'Y') // Draw
                {
                    total_score += 5;
                    total_score2 += 5;
                    break;
                }
                else if (me == 'Z') // Win
                {
                    total_score += 9;
                    total_score2 += 9;
                    break;
                }
            case 'C':
                if (me == 'X') // Win - Lose
                {
                    total_score += 7;
                    total_score2 += 2;
                    break;
                }
                else if (me == 'Y') // Lose - Draw
                {
                    total_score += 2;
                    total_score2 += 6;
                    break;
                }
                else if (me == 'Z') // Draw - Win
                {
                    total_score += 6;
                    total_score2 += 7;
                    break;
                }
            default:
                assert(false);
        }
    }
    input.close();

    std::cout << "Total score: " << total_score << "\n";
    std::cout << "Total score2: " << total_score2 << "\n";
}