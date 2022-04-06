#ifndef _LEETCODE_H_
#define _LEETCODE_H_

#include "common.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution 
{
public:
    Solution(){}
    ~Solution(){}
    vector<int> twoSum(vector<int> &nums, int target);                      //1.两数之和
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2);                    //2.两数相加
    int lengthOfLongestSubstring(string s);
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);  //4.寻找两个正序数组的中位数
    string longestPalindrome(string s);                                     //5.最长回文子串
    string convert(string s, int numRows);                                  //6.Z字变形
    int reverse(int x);                                                     //7.整数翻转
    int myAtoi(string s);                                                   //8. 字符串转换整数 (atoi)
    int maxArea(vector<int>& height);                                       //11.盛最多水的容器
    string longestCommonPrefix(vector<string>& strs);                       //14. 最长公共前缀
    ListNode* mergeKLists(vector<ListNode*>& lists);                        //23. 合并K个升序链表
    vector<int> spiralOrder(vector<vector<int>>& matrix);                   //54. 螺旋矩阵
    vector<vector<int>> generateMatrix(int n);                              //59. 螺旋矩阵 II

};
#endif