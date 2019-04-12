#include <iostream>
#include <algorithm>
#include <string>
#include <stdexcept>

#include <stdio.h>


class Solution
{
public:
    int reverse(int x)
    {
        std::string str = std::to_string(x);
        std::reverse(str.begin(), str.end());
        try
        {
            int num = std::stoi(str);
            if (x > 0)
            {
                return num;
            }
            else
            {
                return -1 * num;
            }
        }
        catch (const std::out_of_range &e)
        {
            return 0;
        }
    }
};

int main()
{
    std::string str = std::to_string(-123);
    std::reverse(str.begin(), str.end());
    printf("%s\n", str.c_str());
    std::cout << std::stoi("123abcdxxy") << std::endl;
    printf("%d\n", atoi("123abcdxxy"));
}