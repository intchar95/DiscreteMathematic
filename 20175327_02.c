#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

int main(int argc, char *argv[]){
	int i,sum=0;
	
	
	if(argc <= 201){
		 for(i=0;i<argc/2;i++){
			
			if(strcmp(argv[2*i+1],"+") == 0){
				
				sum += atoi(argv[2*i+2]);
				
			}else{
			
				sum -=  atoi(argv[2*i+2]);
				
			}
		} 
	}else{
		printf("������ �ִ� 100������ �����մϴ�.");
	}
	printf("%d\n\n\n",sum);
	
	printf("@)!&%#@&@)!&%#@&@)!&%#@&@)!&%#@&@)!&%#@&\n\n");
	printf("   Yong-Beom Cho\n");
	printf("   student ID : 20175327\n\n");
	printf("@)!&%#@&@)!&%#@&@)!&%#@&@)!&%#@&@)!&%#@&\n");
	
	return 0;
}
