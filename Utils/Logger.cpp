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

void Logger::logging(float data1, float data2)
{
    fprintf(log_file, "%f,%f\n", data1, data2);
}