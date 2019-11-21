#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


void print(FILE *fp, char *arr, int n) {
	int i;
	for (i = 0; i < n; i++) {
		fprintf(fp, "%c", arr[i]);
	}
	fprintf(fp, "\n");
}

void swap(char *arr, int i, int j) {
	char tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

void perm(FILE *fp, char *arr,int index,int n) {
	int i;
	if (index == (n - 1))
		print(fp, arr, n);
	else {
		for (i = index; i < n; i++) {
			swap(arr, index, i);
			perm(fp, arr, index + 1, n);
			swap(arr, i, index);
		}
	}

}

int main(int argc, char *argv[]) {
	FILE *fp1, *fp2;

	if (argc != 3) {
		printf("program input output");
		exit(1);
	}
	if (fopen_s(&fp1, argv[1], "r") != 0 || fopen_s(&fp2, argv[2], "w") != 0) {
		printf("file error");
		exit(1);
	}

	char ch;
	int i = 0;
	int size; 

	fscanf_s(fp1, "%d", &size);
	char *arr = (char*)malloc( size * sizeof(char));
	while ((ch = fgetc(fp1)) != EOF) {
		if (ch != '\n') {
			arr[i] = ch;
			i++;
		}
	}

	perm(fp2, arr, 0, size);

	free(arr);
	fclose(fp1);
	fclose(fp2);

	return 0;
}