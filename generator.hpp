#ifndef GENERATOR_HPP
#define GENERATOR_HPP
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <vector>
#include <unistd.h>
#include <algorithm>
#include <ctime>
using namespace std;

class Generator 
{
private:
	ifstream nameFile;
	vector<string> names;
	vector<string> passwds;


public:
	void GetNamesFile(string filename);
	vector<string> GetNames();
	void AssignPasswds(int numNames);
	vector<string> GetPasswds();
	

};

#endif
