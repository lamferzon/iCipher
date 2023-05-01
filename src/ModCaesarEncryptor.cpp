
#include <iterator>
#include <iostream>
#include <vector>
#include <time.h>

#include "consts.h"
#include "encryptors.h"
using namespace std;

// Builders
ModCaesarEncryptor::ModCaesarEncryptor(vector<string>& data) :
		Encryptor(data),
		CaesarEncryptor(data),
		curMaxLag(ModCaesarConst::MAX_LAG){
	srand(time(0));
}

ModCaesarEncryptor::ModCaesarEncryptor(vector<string>& data, int maxLag) :
		Encryptor(data),
		CaesarEncryptor(data){
	srand(time(0));
	curMaxLag = checkMaxLag(maxLag);
}

// Destroyer
ModCaesarEncryptor::~ModCaesarEncryptor(){}

// Methods
void::ModCaesarEncryptor::encrypts(){
	for(string& s : data){
		int lag = getLag(s);
		startAlgorithm(s, lag);
		s += (char)(lag*5 + 2);
	}
}

void::ModCaesarEncryptor::decrypts(){
	for(string& s : data){
		int lag = (((int) s[s.size()-1]) - 2)/5;
		s.erase(s.size()-1);
		startAlgorithm(s, -lag);
	}
}

int::ModCaesarEncryptor::getLag(string& s){
	return ModCaesarConst::MIN_LAG + (rand()%(curMaxLag - ModCaesarConst::MIN_LAG + 1));
}

int ModCaesarEncryptor::checkMaxLag(int toCheck){
	if(toCheck < ModCaesarConst::MIN_LAG){
		return ModCaesarConst::MIN_LAG;
	}else if(toCheck > ModCaesarConst::MAX_LAG){
		return ModCaesarConst::MAX_LAG;
	}else{
		return toCheck;
	}
}

string ModCaesarEncryptor::toString(){
	string res = "Modified Caesar cipher";
	res.append(",");
	res.append(to_string(curMaxLag));
	res.append(",");
	res.append(DefConst::NAN_STR);
	res.append(",");
	res.append(DefConst::NAN_STR);
	// res.append("\n");
	return res;
}

void ModCaesarEncryptor::print(){
	cout << "Minimum lag: " << ModCaesarConst::MIN_LAG << endl;
	cout << "Maximum lag: " << curMaxLag << endl;
}
