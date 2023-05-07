
#include <iostream>
#include <cstring>
#include <memory>

#include "application.h"
using namespace std;

void smartFunction(unique_ptr<Application>& app){
	app->startApplication();
	app.release();
}

int main(){
	unique_ptr<Application> appPtr (new Application());
	smartFunction(appPtr);
}
