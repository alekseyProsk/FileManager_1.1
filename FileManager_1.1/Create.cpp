#include "Create.h"

struct stat buff;

void Create::createDirectory()
{
	string directt;
	cout << "¬ведите путь, по которому создать папку " << endl;
	getline(cin, directt);
	const char* str = directt.c_str(); //ƒелаем из стринг конст чар

	if (!stat(str, &buff))
	{
		cout << "ќшибка ";
	}
	else 
	{
		fs::create_directory(directt);
		cout << "\nѕапка создана в " << directt << endl;
	}//ѕроверка на существование папки, если така€ существует, то вводим по новой
	
	
}

void Create::createFile()
{
	string a;
	cout << "¬ведите им€ и тип файла ";
	getline(cin, a);

	ofstream file(a);
	file.close();
	if (check(a))
		cout << "ќшибка " << endl;
	
}

void Create::Remove()
{
	string rem;
	cout << "¬ведите путь, по которому удалить  папку/ файл " << endl;
	getline(cin, rem);
	if (fs::remove_all(rem) > 0)
		cout << "”спешно ";
	else
		cout << "ќшибка ";
	
	
}

void Create::Rename(bool what)
{
	string old, nNew;

	if (what)
	{
		cout << "„то переименовываем ?" << endl;
		getline(cin, old);
		cout << "¬о что переименовываем ?" << endl;
		getline(cin, nNew);

		rename(old.c_str(), nNew.c_str());

		check(nNew);
	}
	else if(!what)
	{
		cout << "ѕуть откуда " << endl;
		getline(cin, old);
		cout << "ѕуть куда " << endl;
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

	cout << "ѕуть до того, что копируем " << endl;
	getline(cin, from);
	cout << "ѕуть, куда копируем " << endl;
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
		std::cout << e.what() << std::endl;   //ќшибки не отлавливаютс€, все завершаетс€ успешно.
	}
	
}

bool Create::getSize()
{
	string name;

	cout << "¬ведите путь до файла, размер которого вы хотите узнать " << endl;
	getline(cin, name);

	fstream fileSize(name);
	float size = 0;
	fileSize.seekg(0, std::ios::end);
	size = fileSize.tellg();
	if (size < 0)
	{
		cout << "‘айл не существует ";
		return false;
	}
		
	
	
	
	if (size > 1000000)
	{
		cout << "¬аш фа…л весит : " << size / 1000000 << " ћбайт" << endl;
	}
	else if (size > 1000)
	{
		cout << "¬аш фа…л весит : " << size/1000 << "  ба…т" << endl;
	}
	else
	{
		cout << "¬аш фа…л весит : " << size << " ба…т" << endl;
	}
	
	
	
	fileSize.close();
	return true;
	

}

bool Create::check(string mPath)
{
	ifstream check(mPath);
	if (check.bad())
	{
		cout << "”спешно! " << endl;
		return true;
		
	}
	else if (!check.bad())
	{
		cout << "‘айл не существует " << endl;
		return false;
	}
	
}
