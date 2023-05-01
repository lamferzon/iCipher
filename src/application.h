
#ifndef APPLICATION_H_
#define APPLICATION_H_

#include <iostream>
#include <vector>
#include <fstream>

#include "consts.h"
#include "encryptors.h"
using namespace std;

// class Application
class Application {
private:
	// Fields
	vector<string> data;
	vector<string> copyData;
	string CSVName;
	bool CSVFlag;
	int progNum;
	Encryptor* en;

public:
	// Builder
	Application();

	// Destroyer
	~Application();

	// Methods
	void startApplication();

private:
	void chooseLogFileCreation();
	void chooseEncryptor();
	void chooseAction();
	void performEncryption();
	void performDecryption();

	void setCaesarCipher();
	bool setModCaesarCipher();
	bool setVigenereCipher();
	bool setLeoniCipher();

	string createCSV();
	void writeCSV();
	bool checkChoice(string);
	bool checkChoice(string, int);
};

#endif /* APPLICATION_H_ */
