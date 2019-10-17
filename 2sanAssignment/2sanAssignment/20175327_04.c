#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <io.h>
#include <fcntl.h>
#include <wchar.h>
#define _CRT_SECURE_NO_WARNINGS

void main(int argc, char *argv[]) {
	errno_t err1,err2;
	FILE *fp1, *fp2;
	char str[500];
	int i, j, num;
	int k = 2;

	_setmode(_fileno(stdout), _O_U16TEXT);

	if ((err1 = fopen_s(&fp1, argv[0], "r")) != 0) {
		printf(fp1, "fail to open file.");
		return ;
	}
	
	if ((err2 = fopen_s(&fp2, argv[1], "wt")) != 0) {
		printf(fp2, "fail to create file for write.");
		return ;
	}
	
	fprintf(fp2, "[0001]");
	fwprintf(fp2, L"%c \n", 155);

	for (i = 1; i < 1 << argc - 2; i++) {
		num = 0;
		fprintf(fp2, "[%04d]", k);
		k++;

		for (j = 0; j < argc - 2; j++) {

			if (i & (1 << j)) {

				if (num == 1)
					fprintf(fp2, ", ");

				fprintf(fp2, "%s", argv[j + 2]);
				num = 1;
			}

		}

		fprintf(fp2, "\n");

	}

	fprintf(fp2, "\n");
	fprintf(fp2, "@)!&%#@&@)!&%#@&@)!&%#@&@)!&%#@&@)!&%#@&\n\n"
		"   Yong-Beom Cho\n"
		"   student ID : 20175327\n\n"
		"@)!&%#@&@)!&%#@&@)!&%#@&@)!&%#@&@)!&%#@&\n");

	//	fclose(fp1);
	fclose(fp2);

}
