#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <numeric>
#include <sstream>
#include <bitset>
#include <algorithm>

#define ZERO '0'
#define ONE '1'

enum Criteria {MOST_COMMON, LEAST_COMMON};

std::string recursiveMatchBitCriteria(std::vector<std::string>, Criteria, int);
int convertBinaryStringToInt(std::string);

int main()
{
    std::ifstream file("input.txt");
    std::string line;
    std::vector<std::string> strings;

    if (file.is_open())
    {
        while (file)
        {
            std::getline (file, line);
            if (!line.empty())
                strings.push_back(line);
        }
    }
    file.close();
    std::string o2generatorString(recursiveMatchBitCriteria(strings, MOST_COMMON, 0));
    std::string co2scrubberString(recursiveMatchBitCriteria(strings, LEAST_COMMON, 0));
    
    int o2generator = convertBinaryStringToInt(o2generatorString);
    int co2scrubber = convertBinaryStringToInt(co2scrubberString);
    
    std::cout << "O2 generator rating = " << o2generator << std::endl;
    std::cout << "CO2 scrubber rating = " << co2scrubber << std::endl;
    std::cout << "Total rating = " << co2scrubber*o2generator << std::endl;

    return 0;
}

std::string recursiveMatchBitCriteria(std::vector<std::string> vector, Criteria criteria, int index) 
{
    int size = vector.size();
    if (1 == size)
    {
        return vector.front();
    }

    int onesCount = 0;
    char mostCommon;
    bool equal = false;
    std::vector<std::string> newVector = vector;

    for (int i=0; i < size; i++)   
        if (newVector[i][index] == ONE) 
                onesCount++;

    if (onesCount >= size - onesCount) mostCommon = ONE;
    else mostCommon = ZERO;
    

    switch (criteria)
    {
    case MOST_COMMON:
        if (mostCommon == ONE)
        {
            auto it = remove_if(newVector.begin(), newVector.end(), [&](auto a){return a[index]==ZERO;});
            newVector.erase(it, newVector.end());
        }else
        {
            auto it = remove_if(newVector.begin(), newVector.end(), [&](auto a){return a[index]==ONE;});
            newVector.erase(it, newVector.end());
        }
        break;
    
    case LEAST_COMMON:
        if (mostCommon == ONE)
        {
            auto it = remove_if(newVector.begin(), newVector.end(), [&](auto a){return a[index]==ONE;});
            newVector.erase(it, newVector.end());
        }else
        {
            auto it = remove_if(newVector.begin(), newVector.end(), [&](auto a){return a[index]==ZERO;});
            newVector.erase(it, newVector.end());
        }
        break;
    
    default:
        break;
    }
    return recursiveMatchBitCriteria(newVector, criteria, ++index);
}

int convertBinaryStringToInt(std::string string)
{
    auto f = [&] (auto a, auto i)
    {
        if (a[i] == ONE)
            return 1;
        else
            return 0;
    };

    int result = 0;
    int size = string.size();
    for (auto i = 0; i < size; i++)
    {
        int raise = pow(2 * f(string, i), size - i - 1);
        result += raise;
    }
    return result;
}