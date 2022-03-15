#include "Sample.h"


CSample::CSample(const std::string &name)
:divsior(5)
{
    LOG(INFO) << "call CSample";
    m_name = name;
}

CSample::CSample()
{
    LOG(INFO) << "call CSample init";
}

CSample::~CSample()
{
    LOG(INFO) << "call ~CSample " << m_name;
}

CSample::CSample(const CSample& obj)
{
    LOG(INFO) << "call copy construction";
}

CSample::CSample(CSample&& obj)
{
     LOG(INFO) << "call move construction";
}

void CSample::add(const int &num)
{
    auto lam = [=](int value){return (value % divsior == 0) ? num : -1 ;};
    m_filter.push_back(lam(num));
}