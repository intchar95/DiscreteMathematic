#include <stdio.h>
#include <locale.h>
#include <string.h>

void main(int argc, char *argv[]){

    int i, j, num=0;
	int k=1;
	
	system("chcp 437");
	
	printf("\n[0001]%c\n",155);
	
    for (i = 1; i < 1<<argc-1; i++){

        for (j = 0; j < argc-1; j++){
		
		if(num==0){
			k++;
			printf("[%04d]",k);
			num=1;
		}
            if (i & (1 << j)){
			
                printf("%s ",argv[j+1]);

            }

        }
		num=0;
        printf("\n");

    }
}