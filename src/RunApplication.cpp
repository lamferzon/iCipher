
#include <iostream>
#include <cstring>
#include <memory>

#include "application.h"
using namespace std;

void smartFunction(){
	unique_ptr<Application> appPtr (new Application());
	appPtr->startApplication();
	appPtr.release();
}

int main(){
	smartFunction();
}
