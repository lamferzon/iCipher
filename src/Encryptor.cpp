
#include <iostream>
#include <vector>

#include "consts.h"
#include "encryptors.h"
using namespace std;

// Builder
Encryptor::Encryptor(vector<string>& d) : data(d){}

// Destroyer
Encryptor::~Encryptor(){}
