#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void readAndPrint(const string& path)
{
	ifstream input(path.c_str());
	
	if(!input)
	{
		cout << "\n (x) Can't read file in " << path << "\n\n";
	}
	else
	{
		cout << "\n (!) " << path << "\n\n";
		string line = "";
		while(getline(input, line))
		{
			cout << line << "\n";
		}
	}
	cout << "\n (!) End of file " << path << "\n\n";
}

void help()
{
	cout << "HELP:\n";
	cout << "  + This program only is used to read text file (*.txt, ...)\n";
	cout << "  + Command: read path_to_file_1, path_to_file 2 ...\n\n";
}

int main(int argc, char** argv) {
	if(argc > 1)
	{
		for(int i = 1; i < argc; i++)
		{
			readAndPrint(argv[i]);
		}	
	}
	else
	{
		help();
	}
	return 0;
}
