#ifndef _COMMON_H_
#define _COMMON_H_

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <memory>
#include <fstream>
#include <algorithm>

#include <glog/logging.h>

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void signal_handle(const char* data, int size);





#endif 