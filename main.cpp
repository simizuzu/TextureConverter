#include <cstdio>
#include <cstdlib>

int main(int argc, char* argv[]) {
	//argc‚Ì”‚¾‚¯ŒJ‚èo‚·
	for (int i = 0; i < argc; i++)
	{
		printf(argv[i]);
		printf("\n");
	}
	system("pause");

	return 0;
}