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
    std::vector<int> measurement;
    if (file.is_open())
    {
        std::getline (file, line);
        measurement.push_back(std::stoi(line));
        std::getline (file, line);
        measurement.push_back(std::stoi(line));
        std::getline (file, line);
        measurement.push_back(std::stoi(line));
        int number = std::accumulate(measurement.begin(), measurement.end(), 0);
        while (file)
        {
            std::getline (file, line);
            if (!line.empty())
            {
                measurement.push_back(std::stoi(line));
                measurement.erase(measurement.begin());
                int nextNumber = std::accumulate(measurement.begin(), measurement.end(), 0);
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
