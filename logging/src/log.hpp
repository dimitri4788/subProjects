#ifndef LOGGING_FRAMEWORK_HPP
#define	LOGGING_FRAMEWORK_HPP

#include <sstream>

enum LOG_LEVEL
{
    LOG_DEBUG = 0,
    LOG_ERROR,
    LOG_INFO,
    LOG_WARNING,
    LOG_UNKNOWN
};

class Log
{
    public:
        Log();
        ~Log();

        /**
         * @brief This function formats and accumulates the user-supplied data
         *  and returns it as an ostringstream stream.
         *
         * @param logLevel This signifies the input LOG_LEVEL
         *
         * @return It returns the output string stream
         */
        std::ostringstream& getOutputStream(LOG_LEVEL logLevel);

        /**
         * @brief This function converts LOG_LEVEL to a string format.
         *
         * @param logLevel This signifies the input LOG_LEVEL
         *
         * @return It returns the LOG_LEVEL in the string format
         */
        std::string toString(LOG_LEVEL logLevel);

        /**
         * @brief This function returns an output FILE stream where data
         *  is written. The output stream will either be standard error stream
         *  stderr or a file output stream (a file on disk).
         *
         * @param streamTypeToUse This signifies the output stream type to use,
         *  either stderr or a file stream
         *
         * @return It returns an output FILE pointer as reference
         */
        FILE*& stream(std::string streamTypeToUse);

        /**
         * @brief This funtions writes the @msg to the output FILE stream
         *
         * @param msg The message that needs to be written to the output FILE stream
         */
        void output(const std::string& msg);

        std::string getLogFileName() const;

    private:
        std::ostringstream _os;
        std::string _logFileName;
};

#define LOG(level) \
    if(level < LOG_DEBUG || level > LOG_WARNING); \
    else Log().getOutputStream(level)

#endif	/* LOGGING_FRAMEWORK_HPP */
