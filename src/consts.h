
#ifndef CONSTS_H_
#define CONSTS_H_

#include <iostream>
using namespace std;

struct ASCIIConst{
	const static int START = 32;
	const static int END = 127;
};

struct CaesarConst{
	const static int LAG = 3;
};

struct ModCaesarConst{
	const static int MIN_LAG = 7;
	const static int MAX_LAG = 25;
};

struct VigenereConst{
	const static int MIN_NUM = 48;
	const static int MAX_NUM = 57;
	const static int MIN_CHAR = 65;
	const static int MAX_CHAR = 90;
	static const string DEF_KEY;
};

struct DefConst{
	const static string NAN_STR;
};

struct KeywordConst{
	const static string EXIT_WORD;
	const static string DEF_WORD;
	const static string STOP_WORD;
};

struct TimeConst{
	const static int YEAR_DELTA = 1900;
	const static int MONTH_DELTA = 1;
	const static int HOUR_DELTA = 0;
};

#endif /* CONSTS_H_ */
