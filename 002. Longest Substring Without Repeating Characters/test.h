#include <string>
#include <unordered_map>
#include <algorithm>
using std::max;
using std::string;
using std::unordered_map;

class Solution
{
    int lengthOfLongestSubstring(string s)
    {
        size_t ret = 0, start = 0;
        unordered_map<char, size_t> trace;
        for (size_t i = 0; i < s.size(); ++i)
        {
            auto found = trace.find(s[i]);
            //找到了历史存在的字符 且 序号要大于start
            if (found != trace.end() && found->second >= start)
            { //获取当前的最大不重复字符串
                //要么为历史ret值，要么为当前值与start的差值
                ret = max(ret, i - start);
                start = found->second + 1; //更新start为当前的下一个字符
            }
            trace.emplace(s[i], i);
        }
        return max(ret, s.size() - start);
    }
};

//这道题的操作方式，和第一道题很相似，都是采用了unordered_map的方式实现
//同时，这个题目也只是要求找出最大不错重复子串的长度，其实并未要求输出最大不重复的子串
//可以拓展下，如果还要再实现找出最大不重复的子串长度并输出，要如何实现?
//