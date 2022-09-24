#pragma once
#include"FileSystem.h"
#include <algorithm>
#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <fstream>
#include <cstdlib>
#include <filesystem>
#include <winioctl.h>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <sys/stat.h>

class Create : public FileSystem
{
public:
	Create() = default;
	Create(FileSystem& disk, const string& pathUS) : FileSystem{ disk }
	{
		string buff;
		buff = pathUS;
		replace(buff.begin(), buff.end(), '\ ', '\\');
		path = nameDisk + buff;
	}

	void createDirectory();
	void createFile();
	void Remove();
	void Rename(bool what);
	bool getSize();
	bool check(string mPath);
	void Copy();

protected:
	string path;
};

