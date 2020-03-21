#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
//str中为单词,pattern中为字符
class Solution
{
public:
    bool wordPattern(string pattern, string str)
    {
        unordered_map<char, string> m;
        unordered_map<string, int> used;
        vector<string> vs;
        string s = "";
        int pos = 0, i = 0;

        while (pos != -1) //切割获取str中的单词，在291中估计得用其他方法
        {
            pos = str.find_first_of(' ', i);
            //注意，find_first_of这个用法
            string temp = str.substr(i, pos - i);
            //截取单词，注意substr
            vs.push_back(temp); //插入单词元素
            i = pos + 1;        //相当于每个单词的首位索引值(空格之后第一个字符)
        }

        if (vs.size() != pattern.size())
        {
            return false;
        }

        for (int i = 0; i < pattern.size(); i++)
        {
            s = vs[i];
            if (m.count(pattern[i]) == 0) //如果左边(pattern)数组出现新字母时,执行
            {
                if (used[s]) //有新的字符，但是还能找到以前匹配过的单词，不符合条件
                {
                    return false;
                }
                else
                {
                    m[pattern[i]] = s; //匹配键值对
                    //map常用操作，实现字符匹配单词
                    used[s]++; //相当于标记某个单词已经出现过
                }
            }
            else if (s != m[pattern[i]])
            //左边出现的是以前出现过的字符，此时只需要判断，这个字符所对应的单词，是否与历史的
            //匹配关系相一致
            {
                return false;
                //判断str中第i个字符串是否与映射表中第i位所对应的字符串相等
            }
        }
        return true;
    }
};

//需要注意的一些内容
