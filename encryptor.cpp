#include "encryptor.hpp"

void Encryptor::GetRawData(string filename)
{
	inFS.open(filename);

	if(!inFS)
	{
		cout << "File failed to open! Closing Program." << endl;
		exit(1);
	}
	else
	{
		string name, passwd;

		while(inFS >> name >> passwd)
		{
			names.push_back(name);
			passwds.push_back(passwd);
		}
	}
}

void Encryptor::GenerateKey(string key)
{
	int passwdLength = passwds.at(0).size();
	this->key = key;
	int i = 0;
	
	while(this->key.size() != passwdLength)
	{
		this->key += key[i];
		++i;
	}
}

void Encryptor::Encrypt()
{
	for(int j = 0; j < passwds.size(); ++j)
	{
		string toEncrypt = passwds[j];
		string temp = "";

		for(int i = 0; i < toEncrypt.size(); ++i)
		{
			char c = (toupper(toEncrypt[i]) + toupper(key[i])) % 26;
			c += 'a';
			temp.push_back(c);
		}
		encryptedData.push_back(names.at(j) + " " + temp);
	}
}

vector<string> Encryptor::GetEncryptedData()
{
	return encryptedData;
}