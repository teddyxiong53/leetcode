#include <string>
#include <map>
#include <iostream>

using std::string;

class Solution {
public:
    string intToRoman(int num) {
        std::map<int, string> map = {{1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},
                                     {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};
        string ret;
        for (auto iter = map.rbegin(); iter != map.rend(); ++iter) {
            std::cout << iter->first << std::endl;
            while (num >= iter->first)
            {
                ret += map[iter->first];
                std::cout << ret << std::endl;
                num -= iter->first;
            }
        }
        return ret;
    }
};

int main()
{
    Solution* s = new Solution();
    std::cout << s->intToRoman(3999) <<std::endl;
}
