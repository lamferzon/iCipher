
#ifndef ENCRYPTORS_H_
#define ENCRYPTORS_H_

#include <iostream>
#include <vector>
using namespace std;

// class Encryptor
struct Encryptor{
protected:
	// Field
	vector<string>& data;

	// Builder
	Encryptor(vector<string>&);

public:
	// Destroyer
	virtual ~Encryptor();

	// Not-implemented methods
	virtual void encrypts() = 0;
	virtual void decrypts() = 0;
	virtual string toString() = 0;
	virtual void print() = 0;

public:
	// Implemented method
	void setNewData(vector<string>& newData){
		data = newData;
	}
};

// class CaesarEncryptor
struct CaesarEncryptor : virtual Encryptor{
public:
	// Builder
	CaesarEncryptor(vector<string>&);

	// Destroyer
	virtual ~CaesarEncryptor();

	// Methods
	virtual void encrypts();
	virtual void decrypts();
	virtual string toString();
	virtual void print();

protected:
	virtual void startAlgorithm(string&, int);
};

// class ModCaesarEncryptor
struct ModCaesarEncryptor : CaesarEncryptor{
protected:
	// Fields
	int curMaxLag;

public:
	// Builders
	ModCaesarEncryptor(vector<string>&);
	ModCaesarEncryptor(vector<string>&, int);

	// Destroyer
	virtual ~ModCaesarEncryptor();

	// Methods
	void encrypts();
	void decrypts();
	void setMaxLag(int newMaxlag){
		curMaxLag = checkMaxLag(newMaxlag);
	}
	int getMaxLag(){
		return curMaxLag;
	}
	virtual string toString();
	virtual void print();

protected:
	int getLag(string&);
	int checkMaxLag(int);
};

// class VigenereEncryptor
struct VigenereEncryptor : virtual Encryptor{
protected:
	// Field
	string baseKey;

public:
	// Builders
	VigenereEncryptor(vector<string>&);
	VigenereEncryptor(vector<string>&, string);

	// Destroyer
	virtual ~VigenereEncryptor();

	// Methods
	void encrypts();
	void decrypts();
	void setBaseKey(string newBaseKey){
		if(checkBaseKey(newBaseKey)){
			baseKey = newBaseKey;
		}
	}
	static bool checkBaseKey(string);
	string getBaseKey(){
		return baseKey;
	}
	virtual string toString();
	virtual void print();

protected:
	void startAlgorithm(string&, string&, int sign);
	string getKey(string&);
};

// class LeoniEncryptor
struct LeoniEncryptor : ModCaesarEncryptor, VigenereEncryptor{
private:
	// Field
	int numIter;

public:
	// Builder
	LeoniEncryptor(vector<string>&);
	LeoniEncryptor(vector<string>&, int);
	LeoniEncryptor(vector<string>&, string);
	LeoniEncryptor(vector<string>&, int, string);
	LeoniEncryptor(vector<string>&, int, string, int);

	// Destroyer
	virtual ~LeoniEncryptor();

	// Methods();
	void encrypts();
	void decrypts();
	void setNumIter(int newNumIter){
		numIter = newNumIter;
	}
	int getNumIter(){
		return numIter;
	}
	virtual string toString();
	virtual void print();

private:
	int provideNumIter();
};

#endif /* ENCRYPTORS_H_ */
