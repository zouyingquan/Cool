#include "leetCode.h"

//1、两数之和
vector<int> Solution::twoSum(vector<int> &nums, int target)
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
ListNode* Solution::addTwoNumbers(ListNode *l1, ListNode *l2)
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

int Solution::lengthOfLongestSubstring(string s) 
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

//4、寻找两个正序数组的中位数
double Solution::findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
{
    int lenghtOfNums1 = nums1.size();
    int lenghtOfNums2 = nums2.size();
    int totalLength =  lenghtOfNums1 + lenghtOfNums2;
    int loopSize = (lenghtOfNums1 > lenghtOfNums2) ? lenghtOfNums1 : lenghtOfNums2;
    int mid = -1,left = -1,right = -1;
    
    mid = totalLength / 2;

    int index = -1;
    int i = 0, j = 0;
    while(i < lenghtOfNums1 && j < lenghtOfNums2)
    {
        if(nums1[i] < nums2[j])
        {
            left = right;
            right = nums1[i];
            ++i;
        }
        else
        {
            left = right;
            right = nums2[j];
            ++j;
        }
        if(++index == mid)
            break;
    }

    if(index != mid)
    {
        while(i < lenghtOfNums1)
        {
            left = right;
            right = nums1[i];
            ++i;
            if(++index == mid)
            break;
        }

        while(j < lenghtOfNums2)
        {
            left = right;
            right = nums2[j];
            ++j;
            if(++index == mid)
            break;
        }
    }
    if(totalLength % 2 == 0 && totalLength > 1)
        return (double)(right + left) / 2;
    else
        return right;
}

//5、最长回文子串
string Solution::longestPalindrome(string s) 
{

}

int Solution::maxArea(vector<int>& height) 
{
    #if 0
    int maxSize = -1;
    int len = height.size();
    for(int i = 0; i < len - 1; ++i)
    {
        for(int j = len - 1 ; j > i; --j)
        {
            int tmpSize = (j - i) * (height[i] > height[j] ? height[j] : height[i]);
            if(tmpSize > maxSize) 
                maxSize = tmpSize;
        }
    }
    return maxSize;
    #endif
    int maxSize = -1;
    int i = 0, j = height.size() - 1;
    while(i < j)
    {
        int tmpSize = (j - i) * (height[i] > height[j] ? height[j] : height[i]);
        if(tmpSize > maxSize) 
            maxSize = tmpSize;
        if(height[i] > height[j])
        {
            --j;
        }
        else
            ++i;
    }
    return maxSize;
}

//6.Z字变形
string Solution::convert(string s, int numRows)
{
    string ans;
    int length = s.length();
    int interval = numRows;
    int j = 0;
    int lineBase = (numRows - 1) * 2;
    int odd = 0 ,even = 0;
    int count = 0;

    if(numRows == 1)
        return s;

    for(int i = 0 ; i < numRows; ++i)
    {
        even = i * 2;
        if(even == 0) even = lineBase;
        
        odd = (numRows - 1 - i) * 2;
        if(odd == 0) odd = lineBase;
        j = i;
        count = 1;
        while(j < length)
        {
            ans.push_back(s[j]);
            if(count % 2)
            {
                j = j + odd;
            }
            else
            {
                j = j + even;
            }
            ++count;
        }
    }
    return ans;
}

//7、整数翻转
int Solution::reverse(int x) 
{
    if(x == 0)
        return x;
    
    long ans = 0;
    int type = (x > 0) ? 1 : -1;
    int num;
    bool flag = false;
    while(x != 0)
    {
        num = x % 10;
        if(num == 0 && flag == false)
        {
            x  = x / 10;
            continue;
        }
        flag = true;
        ans = ans * 10 + num;
        x  = x / 10;
    }
    return ans > INT_MAX || ans < INT_MIN ? 0 : ans;
}

//14. 最长公共前缀
string Solution::longestCommonPrefix(vector<string>& strs) 
{
    /*
        输入：strs = ["flower","flow","flight"]
        输出："fl"
    */
    string res;
    int length = strs[0].size();
    int compare_len = length;
    int compared_len = -1;
    for(unsigned int i = 1 ; i < strs.size(); ++i)
    {
        int index = 0;
        compared_len = strs[i].size();
        if(compared_len == 0 || compare_len == 0) return "";
        while(strs[0].at(index) == strs[i].at(index))
        {
            ++index;
            if(index == compare_len || index == compared_len)
            {
                break;
            }
        }

        if(index < length)
            length = index;
    }

    res = strs[0].substr(0,length);

    return res;

}

int Solution::myAtoi(string s)
{
    int ans = 0;
    int len = s.size();
    unsigned int i = 0;
    int sign = 1;

    while( i < len && s.at(i) == ' ')
    {
        ++i;
    }

    int start = i;
    for(;i < len ; ++i)
    {
        if( i == start && s.at(i) == '+')
            sign = 1;
        else if( i == start && s.at(i) == '-')
            sign = -1;
        else if(s[i] >= '0' && s[i] <= '9')
        {
            int num = s[i] - '0';
            if(ans > INT_MAX/10 || (ans == INT_MAX / 10 && num > INT_MAX % 10))
            {
                return INT_MAX;
            }

            if(ans < INT_MIN / 10 || (ans == INT_MIN / 10 && -num < INT_MIN % 10))
            {
                return INT_MIN;
            }

            ans = ans*10+sign*num;
        }
        else
        {
            break;
        }
    }

    return ans;
}

ListNode* Solution::mergeKLists(vector<ListNode*>& lists) 
{
    ListNode *ans = nullptr;

    auto cmp = [&](ListNode *a , ListNode *b){ return a->val > b->val;};

    std::priority_queue<ListNode* , std::vector<ListNode*> , decltype(cmp)> q(cmp);

    for(auto &node : lists)
    {
        if(node)
            q.push(node);
    }

    ListNode *head = new ListNode();
    ListNode *tail = head;

    while(!q.empty())
    {
        ListNode *node = q.top();
        q.pop();
        tail->next = node;
        tail = tail->next;
        if(node->next) 
            q.push(node->next);
    }

    return head->next;
}

vector<int> Solution::spiralOrder(vector<vector<int>>& matrix) 
{
    int startX = 0;
    int startY = 0;
    int endX = matrix[0].size();
    int endY = matrix.size();
    const int turnLeft = 1;
    const int turnDown = 2;
    const int turnRight = 3;
    const int turnUp = 4;
    int i = 0;
    int status = turnRight;
    
    vector<int> ans;
    while(endX != startX && endY != startY)
    {
        switch (status)
        {
            case turnRight:
                {
                    for(i = startX; i < endX; ++i)
                    {
                        ans.push_back(matrix[startY][i]);
                    }
                    ++startY;
                    status = turnDown;
                    break;
                }
            case turnDown:
                {
                    for(i = startY; i < endY; ++i)
                    {
                        ans.push_back(matrix[i][endX - 1]);
                    }
                    --endX;
                    status = turnLeft;
                    break;
                }
            case turnLeft:
                {
                    for(i = endX - 1; i >= startX; --i)
                    {
                        ans.push_back(matrix[endY - 1][i]);
                    }
                    --endY;
                    status = turnUp;
                    break;
                }
            case turnUp:
                {
                    for(i = endY - 1; i >= startY; --i)
                    {
                        ans.push_back(matrix[i][startX]);
                    }
                    ++startX;
                    status = turnRight;
                    break;
                }

            default:
                break;
        }
    }

    return ans;
}

vector<vector<int>> Solution::generateMatrix(int n) 
{
    int startX = 0;
    int startY = 0;
    int endX = n;
    int endY = n;

    const int turnLeft = 1;
    const int turnDown = 2;
    const int turnRight = 3;
    const int turnUp = 4;
    int i = 0;
    int index = 1;
    int status = turnRight;

    vector<vector<int>> matrix;
    int j = 0;
    while(j < n)
    {
        vector<int> tmp;
        for(int i = 1; i < n; ++i)
        {
            tmp.push_back(i);
        }
        ++j;
        matrix.push_back(tmp);
    }


    while(endX != startX && endY != startY)
    {
        switch (status)
        {
            case turnRight:
                {
                    for(i = startX; i < endX; ++i)
                    {
                        matrix[startY][i] = index;
                        ++index;
                    }
                    ++startY;
                    status = turnDown;
                    break;
                }
            case turnDown:
                {
                    for(i = startY; i < endY; ++i)
                    {
                        matrix[i][endX - 1] = index;
                        ++index;
                    }
                    --endX;
                    status = turnLeft;
                    break;
                }
            case turnLeft:
                {
                    for(i = endX - 1; i >= startX; --i)
                    {
                        matrix[endY - 1][i] = index;
                        ++index;
                    }
                    --endY;
                    status = turnUp;
                    break;
                }
            case turnUp:
                {
                    for(i = endY - 1; i >= startY; --i)
                    {
                        matrix[i][startX] = index;
                        ++index;
                    }
                    ++startX;
                    status = turnRight;
                    break;
                }

            default:
                break;
        }
    }

    return matrix;
}