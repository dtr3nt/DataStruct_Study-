#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <time.h>

using namespace std;

enum Error_code { duplicate_error, not_present, success, overflow, underflow, range_err, fail };

int string_to_int(string s);
string lpad(string s, unsigned int str_len, string pad_s);
string rtrim(string str);