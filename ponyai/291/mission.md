# chinese

291. 单词规律 II

给你一种规律 pattern 和一个字符串 str，请你判断 str 是否遵循其相同的规律。

这里我们指的是 完全遵循，例如 pattern 里的每个字母和字符串 str 中每个 非空 单词之间，存在着双向连接的对应规律。

示例1:

输入: pattern = "abab", str = "redblueredblue"
输出: true
示例2:

输入: pattern = "aaaa", str = "asdasdasdasd"
输出: true
示例2:

输入: pattern = "aabb", str = "xyzabcxzyabc"
输出: false
说明:
你可以默认 pattern 和 str 都只会包含小写字母。

# ENG

Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty substring in str.

Example 1:

Input: pattern = "abab", str = "redblueredblue"
Output: true
Example 2:

Input: pattern = pattern = "aaaa", str = "asdasdasdasd"
Output: true
Example 3:

Input: pattern = "aabb", str = "xyzabcxzyabc"
Output: false
Notes:
You may assume both pattern and str contains only lowercase letters.