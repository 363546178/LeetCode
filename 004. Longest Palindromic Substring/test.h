#include <string>
#include <algorithm>
using namespace std;
//暴力法 该方法只能通过43个测试用例
class Solution0
{
public:
    string longestPalindrome(string s)
    {
        string result = ""; //结果
        string temp = "";

        if (s.length() == 1)
        {
            return s;
        }

        for (int i = 0; i < s.length(); i++)
        {
            for (int j = i; j < s.length(); j++)
            {
                temp += s[j];
                string temp_revise = temp;
                std::reverse(temp_revise.begin(), temp_revise.end()); //反转字符串，注意这里的特殊操作
                if (temp == temp_revise)
                {
                    result = result.length() > temp.length() ? result : temp;
                }
            }
            temp = "";
        }
        return result;
    }
};
//将字符串 s 反转得到字符串 rev，再求他们的最长公共子串，
//再判断该最长公共子串是否就是我们要找的最长回文子串

//错误解法，必须要有2个循环，外循环遍历正常方向，内循环遍历反向后的子串，同时要判断最大相同字符子串是否能够反向，这个也是LeetCode官方答案的第一个解法
class Solution
{
public:
    string longestPalindrome(string s)
    {
        string result = "";
        string temp = "";

        if (s.length() == 1)
        {
            return s;
        }

        string s_revise = s;
        std::reverse(s_revise.begin(), s_revise.end());

        if (s == s_revise)
        {
            return s;
        }
        string tem = "";
        string tem_revise = "";
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == s_revise[i]) //第一个条件，两个字符相同
            {
                tem += s[i]; //记录字符信息
                tem_revise = tem;
                std::reverse(tem_revise.begin(), tem_revise.end());
                if (tem == tem_revise)
                {
                    result = result.length() > tem.length() ? result : tem;
                }
                else //字符相同但子串结果不同，暂时保留子串
                {
                }
            }
            else //若两个字符不相同，肯定不是
            {
                result = ""; //结果清空
                tem = "";
                tem_revise = "";
            }
        }
        return result;
    }
};