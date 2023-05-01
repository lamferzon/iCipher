
#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>

#include "application.h"
#include "consts.h"
#include "encryptors.h"
using namespace std;

// Builder
Application::Application() : CSVName("null"), CSVFlag(false){
	en = new CaesarEncryptor(data);
	progNum = 1;
}

// Destroyer
Application::~Application() {}

// Methods
void Application::startApplication(){
	cout << "** iCipher **" << endl;
	cout << "Copyright 2023 Lorenzo Leoni (UniBG)\n";
	chooseLogFileCreation();
	chooseEncryptor();
	cout << "\nBye bye!";
}

void Application::chooseLogFileCreation(){
	cout << endl;
	string choice;
	do{
		cout << "Do you want to create a log file? (Y/N) ";
		cin >> choice;
		for(size_t i = 0; i < choice.size(); i++){
			choice[i] = toupper(choice[i]);
		}
	}while(choice.compare("Y") != 0 && choice.compare("N") != 0);
	if(choice.compare("Y") == 0){
		CSVFlag = true;
		CSVName = createCSV();
	}else{
		CSVFlag  = false;
	}
}

void Application::chooseEncryptor(){
	bool flag = true;
	do{
		string stringChoice;
		cout << "\nWhich encryptor do you want to use? \n";
		cout << "1. Caesar cipher.\n";
		cout << "2. Modified Caesar cipher.\n";
		cout << "3. Vigenère cipher.\n";
		cout << "4. Leoni cipher.\n";
		cout << "0. Exit.\n";
		do{
			cout << "Your choice: ";
			cin >> stringChoice;
		}while(!checkChoice(stringChoice, 4));

		int numChoice = stoi(stringChoice);
		switch(numChoice){
		case 1:
			setCaesarCipher();
			chooseAction();
			break;
		case 2:
			if(setModCaesarCipher()){
				chooseAction();
			}
			break;
		case 3:
			if(setVigenereCipher()){
				chooseAction();
			}
			break;
		case 4:
			if(setLeoniCipher()){
				chooseAction();
			}
			break;
		case 0:
			flag = false;
			break;
		}
	}while(flag);
}

void Application::chooseAction(){
	bool flag = true;
	do{
		string stringChoice;
		cout << "\nWhat do you want to do? \n";
		cout << "1. Encrypting.\n";
		cout << "2. Decrypting.\n";
		cout << "0. Come back.\n";
		do{
			cout << "Your choice: ";
			cin >> stringChoice;
		}while(!checkChoice(stringChoice, 2));

		int numChoice = stoi(stringChoice);
		switch(numChoice){
		case 1:
			performEncryption();
			break;
		case 2:
			performDecryption();
			break;
		case 0:
			flag = false;
			break;
		}
	}while(flag);
}

void Application::performEncryption(){
	cout << "\nInsert passwords (" << KeywordConst::EXIT_WORD << " to exit, "
		 << KeywordConst::STOP_WORD << " to stop): \n";

	data.clear();
	copyData.clear();
	bool flag = true;
	string pw;
	int count = 0;
	do{
		cout << count << ") ";
		cin >> pw;
		if(pw.compare(KeywordConst::EXIT_WORD) == 0){
			data.clear();
			return;
		}
		if(pw.compare(KeywordConst::STOP_WORD) == 0){
			flag = false;
		}else{
			data.push_back(pw);
		}
		count += 1;
	}while(flag);

	cout << endl << "Crypted passwords: \n";
	copyData = data;
	en->encrypts();
	for(size_t i = 0; i < data.size(); i++){
		cout << i << ") " << copyData[i] << endl;
		cout << "-> " << data[i] << endl;
	}
	if(CSVFlag){
		writeCSV();
	}
}

void Application::performDecryption(){
	cout << "\nInsert crypted passwords (" << KeywordConst::EXIT_WORD << " to exit, "
			<< KeywordConst::STOP_WORD << " to stop): \n";

	data.clear();
	copyData.clear();
	bool flag = true;
	string pw;
	int count = 0;
	do{
		cout << count << ") ";
		cin >> pw;
		if(pw.compare(KeywordConst::EXIT_WORD) == 0){
			data.clear();
			return;
		}
		if(pw.compare(KeywordConst::STOP_WORD) == 0){
			flag = false;
		}else{
			data.push_back(pw);
		}
		count += 1;
	}while(flag);

	cout << endl << "Passwords: \n";
	copyData = data;
	en->decrypts();
	for(size_t i = 0; i < data.size(); i++){
		cout << i << ") " << copyData[i] << endl;
		cout << "-> " << data[i] << endl;
	}
}

void Application::setCaesarCipher(){
	cout << "\nCaesar cipher settings: \n";
	delete en;
	en = new CaesarEncryptor(data);
	en->print();
}

bool Application::setModCaesarCipher(){
	cout << "\nModified Caesar cipher settings (" << KeywordConst::EXIT_WORD << " to exit): \n";

	string choosenMaxLag;
	do{
		cout << "- Maximum lag (" << KeywordConst::DEF_WORD
			 << " to default (" << ModCaesarConst::MAX_LAG << ")): ";
		cin >> choosenMaxLag;
		if(choosenMaxLag.compare(KeywordConst::EXIT_WORD) == 0){
			data.clear();
			return false;
		}
	}while(!checkChoice(choosenMaxLag) && choosenMaxLag.compare(KeywordConst::DEF_WORD) != 0);

	if(choosenMaxLag.compare(KeywordConst::DEF_WORD) == 0){
		choosenMaxLag = to_string(ModCaesarConst::MAX_LAG);
	}

	cout << endl;
	delete en;
	en = new ModCaesarEncryptor(data, stoi(choosenMaxLag));
	en->print();
	return true;
}

bool Application::setVigenereCipher(){
	cout << "\nVigenère cipher settings (" << KeywordConst::EXIT_WORD << " to exit): \n";

	string choosenBaseKey;
	cout << "- Base key (" << KeywordConst::DEF_WORD
		 << " to default (" << VigenereConst::DEF_KEY << ")): ";
	cin >> choosenBaseKey;
	if(choosenBaseKey.compare(KeywordConst::EXIT_WORD) == 0){
		return false;
	}

	if(choosenBaseKey.compare(KeywordConst::DEF_WORD) == 0){
		choosenBaseKey = VigenereConst::DEF_KEY;
	}

	cout << endl;
	delete en;
	en = new VigenereEncryptor(data, choosenBaseKey);
	en->print();
	return true;
}

bool Application::setLeoniCipher(){
	cout << "\nLeoni cipher settings (" << KeywordConst::EXIT_WORD << " to exit): \n";

	string choosenNumIter;
	do{
		cout << "- Num. iterations (" << KeywordConst::DEF_WORD
			 << " to default (" << VigenereConst::DEF_KEY.size() << ")): ";
		cin >> choosenNumIter;
		if(choosenNumIter.compare(KeywordConst::EXIT_WORD) == 0){
			return false;
		}
	}while(!checkChoice(choosenNumIter) && choosenNumIter.compare(KeywordConst::DEF_WORD) != 0);

	string choosenMaxLag;
	do{
		cout << "- Maximum lag (" << KeywordConst::DEF_WORD
		     << " to default (" << ModCaesarConst::MAX_LAG << ")): ";
		cin >> choosenMaxLag;
		if(choosenMaxLag.compare(KeywordConst::EXIT_WORD) == 0){
			return false;
		}
	}while(!checkChoice(choosenMaxLag) && choosenMaxLag.compare(KeywordConst::DEF_WORD) != 0);

	string choosenBaseKey;
	cout << "- Base key (" << KeywordConst::DEF_WORD
			<< " to default (" << VigenereConst::DEF_KEY << ")): ";
	cin >> choosenBaseKey;
	if(choosenBaseKey.compare(KeywordConst::EXIT_WORD) == 0){
		return false;
	}

	if(choosenBaseKey.compare(KeywordConst::DEF_WORD) == 0){
		choosenBaseKey = VigenereConst::DEF_KEY;
	}
	if(choosenNumIter.compare(KeywordConst::DEF_WORD) == 0){
		choosenNumIter = to_string(VigenereConst::DEF_KEY.size());
	}
	if(choosenMaxLag.compare(KeywordConst::DEF_WORD) == 0){
		choosenMaxLag = to_string(ModCaesarConst::MAX_LAG);
	}

	cout << endl;
	delete en;
	en = new LeoniEncryptor(data, stoi(choosenNumIter), choosenBaseKey, stoi(choosenMaxLag));
	en->print();
	return true;
}

string Application::createCSV(){
	fstream CSVFile;
	time_t now = time(0);
	tm *ltm = localtime(&now);

	string name = "LOG (";
	name.append(to_string(TimeConst::YEAR_DELTA + ltm->tm_year));
	name.append("-");
	name.append(to_string(TimeConst::MONTH_DELTA + ltm->tm_mon));
	name.append("-");
	name.append(to_string(ltm->tm_mday));
	name.append(" ");
	name.append(to_string(TimeConst::HOUR_DELTA + ltm->tm_hour));
	name.append("-");
	name.append(to_string(ltm->tm_min));
	//name.append(";");
	//name.append(to_string(ltm->tm_sec));
	name.append(").csv");

	CSVFile.open(name, ios::out | ios::trunc);
	CSVFile << "ProgNum,Password,EncryptorType,MaxLag,BaseKey,NumIter,(CryptedPw)" << "\n";
	CSVFile.close();
	return name;
}

void Application::writeCSV(){
	fstream CSVFile;
	CSVFile.open(CSVName, ios::out | ios::app);
	for(size_t i = 0; i < data.size(); i++){
		CSVFile << progNum++ << "," << copyData[i]  << ","
				<< en->toString() << ",(" << data[i] << ")" << endl;
	}
	CSVFile.close();
}

bool Application::checkChoice(string toCkeck){
	try{
		stoi(toCkeck);
	}catch(...){
		return false;
	}
	return true;
}

bool Application::checkChoice(string toCkeck, int up){
	int numChoice;
	try{
		numChoice = stoi(toCkeck);
	}catch(...){
		return false;
	}
	if(numChoice < 0 || numChoice > up){
		return false;
	}else{
		return true;
	}
}
