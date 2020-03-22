#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    bool wordPatternMatch(string pattern, string str)
    {
        cout << "pattern:" << pattern << " str:" << str << endl;
        unordered_map<char, string> m; //?这个变量作用？
        return backtrace(pattern, 0, str, 0, m);
    }
    bool backtrace(string pattern, int pattern_cnt, string str, int str_cnt, unordered_map<char, string> &m)
    {
        cout << "backtrace pattern_cnt:" << pattern_cnt << " str_cnt:" << str_cnt << endl;
        if (pattern_cnt == pattern.size() && str_cnt == str.size())
        {
            cout << "backtrace return true!" << endl;
            return true;
        }
        if (pattern_cnt == pattern.size() || str_cnt == str.size())
        {
            cout << "backtrace return false!" << endl;
            cout << "pattern size:" << pattern.size() << " str size:" << str.size() << endl;
            cout << "pattern_cnt:" << pattern_cnt << " str_cnt:" << str_cnt << endl;
            return false;
        }
        char key = pattern[pattern_cnt];
        for (int i = str_cnt; i < str.size(); i++)
        {
            string value = str.substr(str_cnt, i - str_cnt + 1);
            cout << "pattern cnt:" << pattern_cnt << " str_cnt:" << str_cnt << " i:" << i << " value:" << value << endl;
            if (m.count(key) && m[key] == value)
            {
                cout << "m.count(key) && m[key] == value KEY:" << key << " value:" << value << endl;
                if (backtrace(pattern, pattern_cnt + 1, str, i + 1, m)) //递归自身
                {
                    cout << "return true"
                         << " pattern_cnt:" << pattern_cnt << " str_cnt:" << str_cnt << endl;
                    return true;
                }
            }
            else if (!m.count(key))
            {
                cout << "no this key" << endl;
                bool flag = false;
                for (auto it : m) //遍历所有哈希表，判断是否有重复的映射值
                {
                    if (it.second == value)
                    {
                        flag = true;
                        break; //有重复的映射值跳出此循环，继续遍历输入字符串str
                    }
                }
                if (!flag)
                {
                    m[key] = value;
                    cout << "add key! KEY:" << key << " value:" << value << endl;
                    if (backtrace(pattern, pattern_cnt + 1, str, i + 1, m)) //递归调用
                    {
                        cout << "return true if (!flag) "
                             << " pattern_cnt:" << pattern_cnt << " str_cnt:" << str_cnt << endl;
                        return true;
                    }
                    cout << "erase this key" << endl;
                    m.erase(key); //递归return false时执行，将这个key和对应的value都进行移除
                }
            }
            else
            {
                cout << "continue !" << endl;
            }
        }
        cout << "can't find key,return false!" << endl;
        return false;
    }
};