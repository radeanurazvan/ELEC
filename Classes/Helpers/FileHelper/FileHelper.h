#pragma once
#include <string>

class FileHelper
{
private:
	FileHelper();
public:
	static std::string GetFileContent(char* path);
};

