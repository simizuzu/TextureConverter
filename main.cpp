#include <cstdio>
#include <cstdlib>

int main(int argc, char* argv[]) {
	//argcの数だけ繰り出す
	for (int i = 0; i < argc; i++)
	{
		printf(argv[i]);
		printf("\n");
	}
	system("pause");

	return 0;
}