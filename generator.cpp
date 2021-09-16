#include "generator.hpp"

void Generator::GetNamesFile(std::string filename)
{
	string name, thrownString;
	nameFile.open(filename);

	if(!nameFile)
	{
		cout << "File failed to open! Closing Program." << endl;
		exit(1);
	}
	else
	{
		while(nameFile >> name >> thrownString >> thrownString >> thrownString)
		{
			names.push_back(name);
		}
		cout << "Read from file " << names.size() << " names." << endl;
	}
	nameFile.close();


}

vector<string> Generator::GetNames() 
{
	return names;
}

void Generator::AssignPasswds(int numNames)
{
	static const int PASSWD_LENGTH	= 9;
	static const char alphabet[26] = 
	{'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	string temp;

	srand((unsigned) time(NULL) * getpid());
	temp.reserve(PASSWD_LENGTH);

	for(int j = 0; j < numNames; ++j)
	{
		for(int i = 0; i < PASSWD_LENGTH; ++i)
		{
			temp += alphabet[rand() % sizeof(alphabet)];
		}
		passwds.push_back(names.at(j) + " " + temp);
		temp = "";
	}
}

vector<string> Generator::GetPasswds()
{
	return passwds;
}



