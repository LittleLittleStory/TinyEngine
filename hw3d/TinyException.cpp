#include "TinyException.h"
#include <sstream>

TinyException::TinyException(int line, const char* file)noexcept
	:line(line), file(file)
{}

const char* TinyException::what()const noexcept
{
	std::ostringstream oss;
	oss << GetType() << std::endl
		<< GetOriginString();
	whatBuffer = oss.str();
	return whatBuffer.c_str();
}

const char* TinyException::GetType()const noexcept
{
	return "Tiny Expection";
}

int TinyException::GetLine()  const noexcept
{
	return line;
}

const std::string& TinyException::GetFile() const noexcept
{
	return file;
}

std::string TinyException::GetOriginString()const noexcept 
{
	std::ostringstream oss;
	oss << "[File]" << file << std::endl
		<< "[Line]" << line;
	return oss.str();
}
