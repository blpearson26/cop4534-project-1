#include "encryptor.hpp"
#include "generator.hpp"


int main()
{
/*	VARIABLE DECLARATION		*/
	
	static const string outputFile = "rawdata.txt";
	static const string inputFile = "names.txt";
	static const string encryptedFile = "encrypteddata.txt";
	static const string key = "jones";
	Generator g;
	Encryptor e;
	vector<string> names, passwds, encryptedData;	
	ofstream outFS;
	
/*	GETTING NAMES AND ASSIGNING PASSWORDS	*/

	g.GetNamesFile("names.txt");
	g.AssignPasswds(g.GetNames().size());
	passwds = g.GetPasswds();

/*	OUTPUTTING TO RAW DATA FILE   */

	outFS.open(outputFile);
	for(int i = 0; i < passwds.size(); ++i)
	{
		outFS << passwds[i] << endl;
	}
	outFS.close();

/*	Encryption		*/

	e.GetRawData(outputFile);
	e.GenerateKey(key);
	e.Encrypt();
	encryptedData = e.GetEncryptedData();

/*	OUTPUTTING ENCRYPTED DATA TO FILE 	*/

	outFS.open(encryptedFile);
	for(int i = 0; i < encryptedData.size(); ++i)
	{
		outFS << encryptedData[i] << endl;
	}
	outFS.close();





	return 0;
}
