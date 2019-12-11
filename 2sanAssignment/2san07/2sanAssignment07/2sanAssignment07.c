#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFERSIZE 30

struct llst {
	char *wrd;
	int cnt;
	struct llst *next;
};

typedef struct llst node;
typedef node* link;

link createNode(char *);
link append(link, link);
int searchNode(link, char *);
void printfList(link);

link createNode(char *wrd) {
	link cur;
	cur = (node *)malloc(sizeof(node));

	if (cur == NULL) {
		printf("노드 할당 문제\n");
		return NULL;
	}

	cur->wrd = (char *)malloc(sizeof(char) * (strlen(wrd) + 1));
	strcpy(cur->wrd, wrd);
	cur->cnt = 1;
	cur->next = NULL;

	return cur;
}

link append(link head, link cur) {
	link nextNode = head;

	if (head == NULL) {
		head = cur;
		return head;
	}

	while (nextNode->next != NULL) 
		nextNode = nextNode->next;
	
	nextNode->next = cur;

	return head;
}

int searchNode(link head, char *wrd) {
	link nextNode = head;

	while (nextNode != NULL) {
		if (!strcmp(nextNode->wrd, wrd)) {
			nextNode->cnt++;
			return 0;
		}
		nextNode = nextNode->next;
	}

	return 1;
}

void printfList(link head) {
	int total = 0, wrdCnt = 0;   //총 단어 개수
	link nextNode = head;

	while (nextNode != NULL) {
		printf("[%05d] %s (%d)\n", ++wrdCnt, nextNode->wrd, nextNode->cnt);
		total += head->cnt;
		nextNode = nextNode->next;
	}
	printf("[total] %05d", total);
}

int main(int argc, char *argv[]) {
	FILE *fp_in, *fp_out;
	
	char ch;
	int i = 0,j; // loop

	if (argc != 3) {
		printf("잘못입력함");
		exit(1);
	}
	if (fopen_s(&fp_in, argv[1], "r") != 0) {
		printf("파일 오류");
		exit(1);
	}
/*	if (fopen_s(&fp_out, argv[2], "w") != 0) {
		printf("파일 오류");
		exit(1);
	}
	*/

	char wrdBuff[BUFFERSIZE];
	link head = NULL;
	link cur = NULL;

	int flag = 0;

	int k = 0;
	while (!feof(fp_in)) {
		ch = fgetc(fp_in);
		if (isalnum(ch)) {
			wrdBuff[k++] = ch;
		}
		else if(wrdBuff[0] != '\0'){
			wrdBuff[k] = '\0';

			
			if (head != NULL) {
				if (searchNode(head, wrdBuff)) {
					cur = createNode(wrdBuff);
					if (cur == NULL) {
						printf("동적할당 문제");
						exit(1);
					}
					head = append(head, cur);
				}
			}
			if (flag == 0) {
				cur = createNode(wrdBuff);
				if (cur == NULL) {
					printf("동적할당 문제");
					exit(1);
				}
				head = append(head, cur);
				flag = 1;
			}
			
///			printf("%s111\n", wrdBuff);
			k = 0;
			wrdBuff[0] = '\0';
		}
	}
	printfList(head);




	printf("\n@)!&%#@&@)!&%#@&@)!&%#@&@)!&%#@&@)!&%#@&\n\n"
		"   Yong-Beom Cho\n"
		"   student ID : 20175327"
		"\n\n@)!&%#@&@)!&%#@&@)!&%#@&@)!&%#@&@)!&%#@&\n");

	return 0;
}