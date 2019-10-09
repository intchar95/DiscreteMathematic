#include <stdio.h>

void main(int argc, char *argv[]){

    int i, j, num=0;
	int k=1;

	printf("[0001]%c\n",65);
	
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
