#include <stdio.h>

void main(void){

    int i, j;

    char arr[4] = { 'a', 'b', 'c', 'd' };

    int n = 4;
	int k;

    for (i = 1; i < 1<<n; i++){

        for (j = 0; j < n; j++){
		
            if (i & (1 << j)){
			
                printf("%c ",arr[j]);

            }

        }

        printf("\n");

    }

	printf("%d",1<<n);
}
