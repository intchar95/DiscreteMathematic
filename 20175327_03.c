#include <stdio.h>

void main(void){

    int i, j,num=0;

    char arr[4] = { 'a', 'b', 'c', 'd' };

    int n = 4;
	int k=1;

    for (i = 1; i < 1<<n; i++){

        for (j = 0; j < n; j++){
		
		if(num==0){
			k++;
			printf("[%04d]",k);
			num=1;
		}
            if (i & (1 << j)){
			
                printf("%c ",arr[j]);

            }

        }
		num=0;
        printf("\n");

    }
}
