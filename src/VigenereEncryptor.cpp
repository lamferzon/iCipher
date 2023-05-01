
#include <iterator>
#include <iostream>
#include <vector>

#include "consts.h"
#include "encryptors.h"
using namespace std;

// Builders
VigenereEncryptor::VigenereEncryptor(vector<string>& data) : Encryptor(data),
		baseKey(VigenereConst::DEF_KEY){}

VigenereEncryptor::VigenereEncryptor(vector<string>& data, string baseKey) : Encryptor(data){
	if(checkBaseKey(baseKey)){
		this->baseKey = baseKey;
	}else{
		this->baseKey = VigenereConst::DEF_KEY;
	}
}

// Destroyer
VigenereEncryptor::~VigenereEncryptor(){}

// Methods
void VigenereEncryptor::encrypts(){
	for(string& s : data){
		string key = getKey(s);
		startAlgorithm(s, key, +1);
	}
}

void VigenereEncryptor::decrypts(){
	for(string& s : data){
		string key = getKey(s);
		startAlgorithm(s, key, -1);
	}
}

void VigenereEncryptor::startAlgorithm(string& s, string& key, int sign){
	for(size_t i = 0; i < s.size(); i++){
		int char2Num = (int) s[i];
		char2Num += ((int) key[i])*sign;
		if(sign > 0){
			if(char2Num > ASCIIConst::END){
				int diff = char2Num - ASCIIConst::END;
				char2Num = ASCIIConst::START + diff - 1;
			}
		}else{
			if(char2Num < ASCIIConst::START){
				int diff = ASCIIConst::START - char2Num;
				char2Num = ASCIIConst::END - diff + 1;
			}
		}
		s[i] = (char) char2Num;
	}
}

string VigenereEncryptor::getKey(string& s){
	string key = "";
	for(size_t i = 0; i < s.size(); i += baseKey.size()){
		key += baseKey;
	}
	return key.substr(0, s.size());
}

bool VigenereEncryptor::checkBaseKey(string toCheck){
	for(size_t i = 0; i < toCheck.size(); i++){
		if((toCheck[i] < VigenereConst::MIN_NUM || toCheck[i] > VigenereConst::MAX_NUM) &&
				(toCheck[i] < VigenereConst::MIN_CHAR || toCheck[i] > VigenereConst::MAX_CHAR)){
			return false;
		}
	}
	return true;
}

string VigenereEncryptor::toString(){
	string res = "Vigenere cipher";
	res.append(",");
	res.append(DefConst::NAN_STR);
	res.append(",");
	res.append(baseKey);
	res.append(",");
	res.append(DefConst::NAN_STR);
	// res.append("\n");
	return res;
}

void VigenereEncryptor::print(){
	cout << "Base key: " << baseKey << endl;
}
