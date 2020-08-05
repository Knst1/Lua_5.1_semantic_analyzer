#include <iostream>
#include <fstream>
#include "globals.h"

using namespace std;

int main(int argc, char** argv)
{
	if (argc < 3)
	{
		cout << "It takes 2 arguments: a file with program text and the name of the output file\n";
		return 0;
	}
	ofstream f(argv[2]);
	f << parse(argv[1]);
	close_input_file();
	f.close();
	return 0;
}
