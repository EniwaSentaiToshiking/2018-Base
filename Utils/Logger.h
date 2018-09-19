#ifndef LOGGER_H
#define LOGGER_H

#include <stdio.h>

class Logger
{
private:
	FILE *log_file;

public:
	Logger(const char *file_name);
	void logging(float data);
	void logging(float, float);

	virtual ~Logger();
};
#endif