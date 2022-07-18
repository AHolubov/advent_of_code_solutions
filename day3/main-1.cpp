#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <numeric>
#include <sstream>
#include <bitset>


int main()
{
    std::ifstream file("input.txt");
    std::string line;
    std::vector<int> result;
    int lineCounter = 0;
    int gamma;
    int epsilon;

    if (file.is_open())
    {
        while (file)
        {
            std::getline (file, line);
            if (!line.empty())
            {
                lineCounter++;
                int len = line.size();
                for (auto i = 0; i < len; i++)
                {
                    if (result.size() < i + 1) result.push_back(0);
                    result[i] += std::stoi(line.substr(i, 1));
                }
            }
        }


        std::string gammaString;
        std::string epsilonString;
        for (const auto& r: result)
        {
            if (lineCounter-r > lineCounter/2)
            {
                gammaString += '0';
                epsilonString += '1';
            }
            else
            {
                gammaString += '1';
                epsilonString += '0';
            }
        }

        std::bitset<16> gammaBitset(gammaString);
        std::bitset<16> epsilonBitset(epsilonString);

        gamma = gammaBitset.to_ulong();
        epsilon = epsilonBitset.to_ulong();

        std::cout << "Gamma: " << gamma << std::endl;       
        std::cout << "Epsilon: " << epsilon << std::endl;       
        std::cout << "Total: " << gamma * epsilon << std::endl;       
    }
    return 0;
}