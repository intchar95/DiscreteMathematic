#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

int main(int argc, char *argv[]){
	int i,sum=0;
	

		 for(i=0;i<argc/2;i++){
			
			if(strcmp(argv[2*i+1],"+") == 0){
				
				sum += atoi(argv[2*i+2]);
				
			}else (strcmp(argv[2*i+1],"+") != 0){
			
				sum -=  atoi(argv[2*i+2]);
				
			}
		} 

	printf("%d\n\n\n",sum);

	return 0;
}
