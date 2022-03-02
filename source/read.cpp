#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void readAndPrint(const string& path)
{
	ifstream inputFile(path.c_str());
	
	if(inputFile)
	{
		cout << "\n--------------------------------------------------------\n";
		cout << " (!) " << path;
		cout << "\n--------------------------------------------------------\n\n";
		string line = "";
		while(getline(inputFile, line))
		{
			cout << line << "\n";
		}
		cout << "\n--------------------------------------------------------\n";
		cout << " (!) End of file " << path;
		cout << "\n--------------------------------------------------------\n\n";
	}
	else
	{
		cout << "\n-------------------------------------------------------\n";
		cout << "  (x) Can't read file " << path;
		cout << "\n--------------------------------------------------------\n\n";
	}
}

void help()
{
	cout << "HELP:\n";
	cout << "  + This program is only used to read text file (*.txt, ...)\n";
	cout << "  + Command: read path_to_file_1, path_to_file 2 ...\n\n";
}

int main(int argc, char* argv[]) {
	if(argc > 1)
	{
		for(int i = 1; i < argc; i++)
		{
			string path = argv[i];
			readAndPrint(path);
		}	
	}
	else
	{
		help();
	}
	return 0;
}
