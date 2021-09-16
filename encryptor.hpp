#ifndef ENCRYPTOR_HPP
#define ENCRYPTOR_HPP
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <vector>
#include <unistd.h>
#include <ctime>
#include <algorithm>
using namespace std;

class Encryptor 
{
private:
	ifstream inFS;
	vector<string> names;
	vector<string>passwds;
	vector<string> encryptedData;
	string key;


public:
	void GetRawData(string filename);
	void GenerateKey(string key);
	void Encrypt();
	vector<string> GetEncryptedData();
	
	

};

#endif