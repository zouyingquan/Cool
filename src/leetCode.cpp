#include "common.h"

using std::vector;
using std::string;

//1、两数之和
vector<int> twoSum(vector<int> &nums, int target)
{
    std::map<int, int> mSum;
    for (int i = 0; i < nums.size(); i++)
    {
        int anotherNum = target - nums[i];
        if (std::find_if(mSum.begin(), mSum.end(), [&](std::pair<int, int> it) -> bool
                         { return it.first == anotherNum; }) != mSum.end())
        {
            return std::vector<int>{i, mSum[anotherNum]};
        }
        mSum[nums[i]] = i;
    }
    return std::vector<int>{};
}

//2、两数相加
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *ans = nullptr;
    ListNode *ansIndex = nullptr;
    ListNode *pLeft = l1;
    ListNode *pRight = l2;
    int tmpSum = 0;
    int nextAdd = 0;
    while (pLeft != nullptr || pRight != nullptr)
    {
        tmpSum = ((pLeft) ? pLeft->val : 0) + ((pRight) ? pRight->val : 0) + nextAdd;
        if (ans == nullptr)
        {
            ans = new ListNode(((tmpSum >= 10) ? tmpSum - 10 : tmpSum));
            ansIndex = ans;
        }
        else
        {
            ansIndex->next = new ListNode(((tmpSum >= 10) ? tmpSum - 10 : tmpSum));
            ansIndex = ansIndex->next;
        }

        nextAdd = (tmpSum >= 10) ? 1 : 0;

        if (pLeft)
            pLeft = pLeft->next;
        if (pRight)
            pRight = pRight->next;
    }

    if(nextAdd == 1)
    {
        ansIndex->next = new ListNode(1);
    }

    return ans;
}

int lengthOfLongestSubstring(string s) 
{
    int start = -1,maxlen = 0;
    vector<int> dir(256,-1);
    int len = s.length();
    int i = 0;
    while(i < len)
    {
        if(dir[s[i]] > start)
            start = dir[s[i]];
        
        dir[s[i]] = i;
        
        maxlen = ((i - start) > maxlen)?(i-start):maxlen;
        i++;
    }
    return maxlen;
}