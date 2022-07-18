#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <numeric>
#include <sstream>



int main()
{
    std::ifstream file("input.txt");
    std::string line;

    int horizontal = 0;
    int depth = 0;
    int aim = 0;

    enum Direction {FORWARD, DOWN, UP};

    if (file.is_open())
    {
        while (file)
        {
            std::getline (file, line);
            if (!line.empty())
            {
                std::vector<int> instruction;
                std::istringstream iss (line);
                std::string in;
                while (std::getline(iss, in, ' '))
                {
                    if ("forward" == in) instruction.push_back(FORWARD);
                    else if ("down" == in) instruction.push_back(DOWN);
                    else if ("up" == in) instruction.push_back(UP);
                    else instruction.push_back(std::stoi(in));
                }                
                switch (instruction[0])
                {
                case FORWARD:
                    horizontal += instruction[1];
                    depth += instruction[1] * aim;
                    break;
                case DOWN:
                    aim += instruction[1];
                    break;
                case UP:
                    aim -= instruction[1];
                    break;
                
                default:
                    break;
                }
            }
            

        }
        std::cout << "horizontal: " << horizontal << std::endl;
        std::cout << "depth: " << depth << std::endl;
        std::cout << "total: " << horizontal * depth << std::endl;
    }
    return 0;
}
