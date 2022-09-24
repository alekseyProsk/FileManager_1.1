#pragma once
#include <stdio.h>
#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <fstream>
#include <cstdlib>
#include <filesystem>
#include <winioctl.h>
#include <string>
#include <algorithm>
#include <sys/stat.h>	

using namespace std;
namespace fs = std::filesystem;

class FileSystem
{
public:
	FileSystem() = default;
	FileSystem(const string& name) : nameDisk{ name }
	{
		string standart = ":\\\ ";
		this->nameDisk = name + standart;
		/*nameDisk.erase(nameDisk.end() - 1);*/
	}
	
	void getDiskInfo();

protected:
	string nameDisk;

};

