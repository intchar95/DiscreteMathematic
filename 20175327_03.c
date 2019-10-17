#include <stdio.h>
#include <locale.h>
#include <string.h>

void main(int argc, char *argv[]){

    int i, j, num;
	int k=2;

	system("chcp 437");
	
	printf("\n[0001]%c\n",155);
	
    for (i = 1; i < 1<<argc-2; i++){
		num = 0;
		printf("[%04d]", k);
		k++;

        for (j = 0; j < argc-2; j++){

			if (i & (1 << j)) {

				if (num == 1)
					printf(", ");

				printf("%s", argv[j + 2]);
				num = 1;
			}

        }
		
        printf("\n");

    }
	
	printf("\n");
	printf( "@)!&%#@&@)!&%#@&@)!&%#@&@)!&%#@&@)!&%#@&\n\n"
			"   Yong-Beom Cho\n"
			"   student ID : 20175327\n\n"
			"@)!&%#@&@)!&%#@&@)!&%#@&@)!&%#@&@)!&%#@&\n");
			
}
