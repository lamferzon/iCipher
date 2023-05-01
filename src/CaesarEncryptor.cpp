
#include <iterator>
#include <iostream>
#include <vector>

#include "consts.h"
#include "encryptors.h"
using namespace std;

// Builder
CaesarEncryptor::CaesarEncryptor(vector<string>& data) : Encryptor(data){}

// Destroyer
CaesarEncryptor::~CaesarEncryptor(){}

// Methods
void CaesarEncryptor::encrypts(){
	for(string& s : data){
		startAlgorithm(s, CaesarConst::LAG);
	}
}

void CaesarEncryptor::decrypts(){
	for(string& s : data){
		startAlgorithm(s, -CaesarConst::LAG);
	}
}

void CaesarEncryptor::startAlgorithm(string& s, int shift){
	for(size_t i = 0; i < s.size(); i++){
		int char2Num = (int) s[i];
		char2Num += shift;
		if(shift > 0){
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

string CaesarEncryptor::toString(){
	string res = "Caesar cipher";
	res.append(",");
	res.append(to_string(CaesarConst::LAG));
	res.append(",");
	res.append(DefConst::NAN_STR);
	res.append(",");
	res.append(DefConst::NAN_STR);
	// res.append("\n");
	return res;
}

void CaesarEncryptor::print(){
	cout << "Lag: " << CaesarConst::LAG << endl;
}
