#include <iostream>
#include <string>

using namespace std;

void showHelp()
{
	printf("\nHELP\n");
	printf("  (!) This programe is used to change back slash to common slash and double back slash!\n");
	printf("  (!) Version: 1.0.0.2\n");
	printf("  (!) Written by: Tran Quang Manh\n");
	printf("  (!) Tuesday, January 11, 2022 08:28 PM\n\n");
	printf("  (!) Command:\n");
	printf("      changeSlash path\n\n");
}

void fixPath(string& path)
{
	string pathResult;

	int i = 0;

	while(i < path.size())
	{
		if (path[i] == '\\')
		{
			pathResult += '\\';
			while(path[i] == '\\')
			{
				i++;
			}
		}

		while(path[i] == '/')
		{
			i++;
		}

		pathResult += path[i];
		i++;
	}

	path = pathResult;
}

int main(int argc, char* argv[])
{
	if(argc == 1)
	{
		showHelp();
		return 0;
	}

	string path = argv[1];

	if(path == "-h" || path == "/?")
	{
		showHelp();
		return 0;
	}
	
	fixPath(path);

	string commonSlash, doubleBackSlash;
	for(int i = 0; i < path.size(); i++)
	{
		if(path[i] == '\\')
		{
			commonSlash += '/';

			doubleBackSlash += "\\\\";
		}
		else
		{
			commonSlash += path[i];
			doubleBackSlash += path[i];
		}
	}

	cout << "\n" << commonSlash << "\n";
	cout << "\n" << doubleBackSlash << "\n\n";

	return 0;
}
