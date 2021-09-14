#include "common.h"

void signal_handle(const char* data, int size)
{
    std::ofstream fs("core_dump.log",std::ios::app);
    std::string str = std::string(data,size);

    fs<<str;
    LOG(ERROR)<<str;

    fs.close();
}