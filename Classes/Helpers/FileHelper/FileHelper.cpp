#include "FileHelper.h"
#include <fstream>
#include <iostream>

FileHelper::FileHelper()
{
}

std::string FileHelper::GetFileContent(char* filePath)
{
	std::ifstream file(filePath);
	std::string content((std::istreambuf_iterator<char>(file)),
		(std::istreambuf_iterator<char>()));
	return content;

}
