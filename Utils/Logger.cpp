#include "Logger.h"

Logger::Logger(const char *file_name)
{
    log_file = fopen(file_name, "w");
}

Logger::~Logger()
{
    fclose(log_file);
}

void Logger::logging(float data)
{
    fprintf(log_file, "%f\n", data);
}