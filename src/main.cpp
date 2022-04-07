
#include "common.h"
#include "leetCode.h"
#include "Sample.h"

#include <list>

#define USE_GLOG 0

std::shared_ptr<CSample> test()
{
    std::shared_ptr<CSample> ptr = std::make_shared<CSample>();
    ptr->setName("1");
    
    return ptr;
}


int main(int argc, char* argv[])
{
    #if USE_GLOG
    google::InitGoogleLogging(argv[0]);
    FLAGS_minloglevel = google::INFO;
    FLAGS_stderrthreshold=google::FATAL;
    FLAGS_colorlogtostderr=true;
    FLAGS_logbufsecs = 0 ;    
    FLAGS_max_log_size = 200; //MB
    google::SetLogDestination(google::GLOG_INFO, "/tmp/info");
    
    google::InstallFailureSignalHandler();
    google::InstallFailureWriter(&signal_handle);  
    #endif
    Solution leetcode;
    LOG(INFO) << "cool start ..";
    ListNode *a = new ListNode(0);
    
    ListNode *b = new ListNode(1);
    ListNode *c = new ListNode(2);

    a->next = b;
    b->next = c;

    ListNode *index = a;
    while(index)
    {
        LOG(INFO) << index->val;
        index = index->next;
    }


    ListNode *ans = leetcode.rotateRight(a,1);

    leetcode.PrintList(ans);

    #if USE_GLOG
    google::ShutdownGoogleLogging();
    #endif

    return 0;
}

