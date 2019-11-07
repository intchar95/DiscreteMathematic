#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int sumNumbers(FILE *file, int* pNumbers, int Index);

int sumNumbers(FILE *file, int* pNumbers, int Index)
{
	static int sum;
	// basis step
	if (Index <= 0)
	{
		return 0;
	}
	// recursive step
	else
	{
		sum += pNumbers[Index - 1];
		fprintf(file, "[%03d] %d\n", Index, sum);
		return sumNumbers(file, pNumbers, Index - 1);
	}
}

/*int sumNumbers(FILE *file, int* pNumbers, int Index) {
	fprintf(file, "%d", 13);
}
*/

int main(int argc, char* argv[]) {
	FILE *fp1, *fp2;
	char str[64];
	int i = 0;
	
	// read_file = argv[1]
	// write_file = argv[2]

	if ((fp1 = fopen(argv[1], "r")) == NULL) {
		printf("fale to open file.");
		return 0;
	}
	if ((fp2 = fopen(argv[2], "wt")) == NULL) {
		printf("fail to create file for write.");
		return 0;
	}

	int nNumber = atoi(fgets(str, sizeof(str), fp1));// read from the input file
	int* pNumbers = (int*)malloc(nNumber * sizeof(int));

	while (fgets(str, sizeof(str), fp1)) { // read a file and write to another file line by line
		pNumbers[i] = atoi(str);
		i++;
	}

	sumNumbers(fp2, pNumbers, nNumber);
	
	fprintf(fp2,"\n@)!&%#@&@)!&%#@&@)!&%#@&@)!&%#@&@)!&%#@&\n\n"
		"   Yong-Beom Cho\n"
		"   student ID : 20175327"
		"\n\n@)!&%#@&@)!&%#@&@)!&%#@&@)!&%#@&@)!&%#@&\n");

	free(pNumbers);

	fclose(fp1);
	fclose(fp2);

	return 0;
}