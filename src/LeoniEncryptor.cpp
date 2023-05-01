
#include <iterator>
#include <iostream>
#include <vector>

#include "consts.h"
#include "encryptors.h"
using namespace std;

// Builders
LeoniEncryptor::LeoniEncryptor(vector<string>& data) :
		Encryptor(data),
		ModCaesarEncryptor(data),
		VigenereEncryptor(data),
		numIter(provideNumIter()){}
LeoniEncryptor::LeoniEncryptor(vector<string>& data, int numIter) :
		Encryptor(data),
		ModCaesarEncryptor(data),
		VigenereEncryptor(data),
		numIter(numIter){}

LeoniEncryptor::LeoniEncryptor(vector<string>& data, string baseKey) :
		Encryptor(data),
		ModCaesarEncryptor(data),
		VigenereEncryptor(data, baseKey),
		numIter(provideNumIter()){}

LeoniEncryptor::LeoniEncryptor(vector<string>& data, int numIter, string baseKey) :
		Encryptor(data),
		ModCaesarEncryptor(data),
		VigenereEncryptor(data, baseKey),
		numIter(numIter){}

LeoniEncryptor::LeoniEncryptor(vector<string>& data, int numIter, string baseKey, int maxLag) :
		Encryptor(data),
		ModCaesarEncryptor(data, maxLag),
		VigenereEncryptor(data, baseKey),
		numIter(numIter){}

// Destroyer
LeoniEncryptor::~LeoniEncryptor(){}

// Methods
void LeoniEncryptor::encrypts(){
	for(int i = 0; i < numIter; i++){
		VigenereEncryptor::encrypts();
		ModCaesarEncryptor::encrypts();
	}
}

void LeoniEncryptor::decrypts(){
	for(int i = 0; i < numIter; i++){
		ModCaesarEncryptor::decrypts();
		VigenereEncryptor::decrypts();
	}
}

int LeoniEncryptor::provideNumIter(){
	return baseKey.size();
}

string LeoniEncryptor::toString(){
	string res = "Leoni cipher";
	res.append(",");
	res.append(to_string(curMaxLag));
	res.append(",");
	res.append(baseKey);
	res.append(",");
	res.append(to_string(numIter));
	// res.append("\n");
	return res;
}

void LeoniEncryptor::print(){
	cout << "Num. of iterations: " << numIter << endl;
	cout << "Base key: " << baseKey << endl;
	cout << "Maximum lag: " << curMaxLag << endl;
}
