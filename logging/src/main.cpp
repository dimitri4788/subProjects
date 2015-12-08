#include "log.hpp"

int main(int argc, char **argv)
{
    LOG(LOG_DEBUG) << "I am a debug log.";
    LOG(LOG_ERROR) << "I am an error log.";
    LOG(LOG_INFO) << "I am an info log.";
    LOG(LOG_WARNING) << "I am a warning log.";

    return 0;
}
