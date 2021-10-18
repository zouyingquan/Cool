#ifndef _SAMPLE_H_
#define _SAMPLE_H_

#include "common.h"

class CSample
{
public:
    CSample(const std::string &name);
    ~CSample();
    
    CSample(const CSample& obj);
    CSample(CSample&& obj);

    void add(const int &num);

    std::string m_name;

private:
    std::vector<int> m_filter;
    int divsior;

};



#endif 