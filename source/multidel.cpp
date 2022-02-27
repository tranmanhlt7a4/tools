#include <stdio.h>
#include <Windows.h>
#include <string.h>

void showHelp()
{
	printf("\nHELP!\n");
	printf("  (!) This programe is used to delete multifiles!\n");
	printf("  (!) Version: 1.0.0.0\n");
	printf("  (!) Written by: Tran Quang Manh\n");
	printf("  (!) Tuesday, January 11, 2022 07:57 PM\n\n");
	printf("  (!) Command:\n");
	printf("      multidel file_1 file_2 ....\n\n");
}

int main(int argc, char* argv[])
{
	if (argc == 1)
	{
		showHelp();
	}

	for(int i = 1; i < argc; i++)
	{
		char Command[100];
		if(strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "/?") == 0)
		{
			showHelp();
			break;
		}

		printf("\nDELETING: %s\n", argv[i]);
		sprintf(Command, "del %s", argv[i]);
		system(Command);
		printf("COMPLETED!\n");
	}

	return 0;
}
