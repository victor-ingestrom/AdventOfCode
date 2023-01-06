#include <fstream>
#include <iostream>

// Answers: 2=--00--0220-0-21==1, -

std::string num2snafu(int64_t num)
{
    std::string snafu{};
    while(num)
    {
        auto rem = num % 5;
        if (rem < 3)
        {
            snafu.push_back('0'+rem);
        }
        num /= 5;
        if (rem >= 3){
            snafu.push_back(rem == 3 ? '=' : '-');
            num++;
        }
    }
    return {snafu.rbegin(), snafu.rend()};
}

int64_t convert_snafu(std::string const& x)
{
    int64_t num = 0;
    for (auto const& c : x)
    {
        if (c >= '0' && c <= '2')
        {
            num *= 5;
            num += (c - '0');
        }
        else if (c == '-')
        {
            num *= 5;
            num += -1;
        }
        else if (c == '=')
        {
            num *= 5;
            num += -2;
        }
    }
    return num;
}

int main()
{
    std::cout << "=========================================\n";
    std::cout << "Advent of Code - Day 25\n";
    std::cout << "=========================================\n";

    std::ifstream input("input25");
    std::string line;
    int64_t fuel_sum = 0;
    while (std::getline(input, line))
    {
//        std::cout << "SNAFU: " << line << " Decimal: " << convert_snafu(line) << "\n";
        fuel_sum += convert_snafu(line);
    }
    input.close();

    std::cout << "Part 1: " << num2snafu(fuel_sum) << "\n";
    std::cout << "Part 2: " << "n/a" << "\n";
}