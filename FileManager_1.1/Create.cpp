#include "Create.h"

struct stat buff;

void Create::createDirectory()
{
	string directt;
	cout << "������� ����, �� �������� ������� ����� " << endl;
	getline(cin, directt);
	const char* str = directt.c_str(); //������ �� ������ ����� ���

	if (!stat(str, &buff))
	{
		cout << "������ ";
	}
	else 
	{
		fs::create_directory(directt);
		cout << "\n����� ������� � " << directt << endl;
	}//�������� �� ������������� �����, ���� ����� ����������, �� ������ �� �����
	
	
}

void Create::createFile()
{
	string a;
	cout << "������� ��� � ��� ����� ";
	getline(cin, a);

	ofstream file(a);
	file.close();
	if (check(a))
		cout << "������ " << endl;
	
}

void Create::Remove()
{
	string rem;
	cout << "������� ����, �� �������� �������  �����/ ���� " << endl;
	getline(cin, rem);
	if (fs::remove_all(rem) > 0)
		cout << "������� ";
	else
		cout << "������ ";
	
	
}

void Create::Rename(bool what)
{
	string old, nNew;

	if (what)
	{
		cout << "��� ��������������� ?" << endl;
		getline(cin, old);
		cout << "�� ��� ��������������� ?" << endl;
		getline(cin, nNew);

		rename(old.c_str(), nNew.c_str());

		check(nNew);
	}
	else if(!what)
	{
		cout << "���� ������ " << endl;
		getline(cin, old);
		cout << "���� ���� " << endl;
		getline(cin, nNew);

		rename(old.c_str(), nNew.c_str());

		check(nNew);
	}

	

}


void Create::Copy()
{
	//static std::filesystem::path myPathFrom;
	//static std::filesystem::path myPathTo;
	string myPathFrom;
	string myPathTo;

	string from, to;

	cout << "���� �� ����, ��� �������� " << endl;
	getline(cin, from);
	cout << "����, ���� �������� " << endl;
	getline(cin, to);

	to.insert(to.end() , '1');
	myPathFrom = from;
	myPathTo = to;


	std::filesystem::copy_options myOptions;
	myOptions = std::filesystem::copy_options::none;

	try
	{
		std::filesystem::copy(myPathFrom, myPathTo, myOptions);
	}
	catch (const std::filesystem::filesystem_error& e)
	{
		std::cout << e.what() << std::endl;   //������ �� �������������, ��� ����������� �������.
	}
	
}

bool Create::getSize()
{
	string name;

	cout << "������� ���� �� �����, ������ �������� �� ������ ������ " << endl;
	getline(cin, name);

	fstream fileSize(name);
	float size = 0;
	fileSize.seekg(0, std::ios::end);
	size = fileSize.tellg();
	if (size < 0)
	{
		cout << "���� �� ���������� ";
		return false;
	}
		
	
	
	
	if (size > 1000000)
	{
		cout << "��� ���� ����� : " << size / 1000000 << " �����" << endl;
	}
	else if (size > 1000)
	{
		cout << "��� ���� ����� : " << size/1000 << " �����" << endl;
	}
	else
	{
		cout << "��� ���� ����� : " << size << " ����" << endl;
	}
	
	
	
	fileSize.close();
	return true;
	

}

bool Create::check(string mPath)
{
	ifstream check(mPath);
	if (check.bad())
	{
		cout << "�������! " << endl;
		return true;
		
	}
	else if (!check.bad())
	{
		cout << "���� �� ���������� " << endl;
		return false;
	}
	
}
