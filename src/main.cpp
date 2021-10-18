
#include "common.h"
#include "Sample.h"

#define USE_GLOG 0


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

    LOG(INFO) << "cool start ..";


    #if USE_GLOG
    google::ShutdownGoogleLogging();
    #endif

    return 0;
}

