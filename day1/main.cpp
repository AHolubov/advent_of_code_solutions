#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <numeric>

int main()
{
    std::ifstream file("input.txt");
    std::string line;
    int increaseCounter = 0;
    if (file.is_open())
    {
        std::getline (file, line);
        int number = std::stoi(line);
        while (file)
        {
            std::getline (file, line);
            if (!line.empty())
            {
                int nextNumber = std::stoi(line);
                if (nextNumber > number)
                {
                    increaseCounter++;
                }
                number = nextNumber;
            }
        }
        std::cout << "Number of increases: " << increaseCounter << std::endl;
    }
    return 0;
}
