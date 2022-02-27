#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void showHelp()
{
	cout << "\nHELP\n";
	cout << "  (!) This programe is used to change tabs in files to 4 spaces!\n";
	cout << "  (!) Version: 1.0.0.2\n";
	cout << "  (!) Written by: Tran Quang Manh\n";
	cout << "  (!) Tuesday, January 11, 2022 08:10 PM\n\n";
	cout << "  (!) Command:\n";
	cout << "      changeTab file_1 file_2 ....\n\n";
}

int main(int argc, char* argv[])
{
	if(argc == 1)
	{
		showHelp();
	}

	for(int i = 1; i < argc; i++)
	{
		string path = argv[i];
		if(path == "-h" || path == "/?")
		{
			showHelp();
			break;
		}

		ifstream fileIn(path.c_str());
		if(!fileIn)
		{
			cout << "\nCan't open file: " << path << "\n\n";
		}
		else
		{
			cout << "\nFile: " << path << "\n";
			string line, contentFixed;

			while(getline(fileIn, line))
			{
				for(int j = 0; j < line.size(); j++)
				{
					if(line[j] == '\t')
					{
						contentFixed += "    ";
					}
					else
					{
						contentFixed += line[j];
					}
				}
				contentFixed += '\n';
			}
			
			ofstream fileOut(path.c_str());
			if(!fileOut)
			{
				cout << "\nCan't creat file: " << path << "\n\n";
			}
			else
			{
				fileOut << contentFixed;
				cout << "\nFile: " << path << " completed!\n\n";
			}
		}
	}

	return 0;
}
