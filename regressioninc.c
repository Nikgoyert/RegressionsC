#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
	char data;
	struct node* next;
}node;

/*struct node* build_row() {
	struct node* l = NULL;
	l = malloc(sizeof(struct node));
	
	/*while (l>0){
		int t = 1 - l;	
		while (t>0){
			struct node* l= NULL;
			l = malloc(sizeof(struct node));
			l->data = l;
			l->next = l + 1; 
	
	second->data = 2;
	second->next = third;
	
	third->data = 3;
	third->next = NULL;
	
	return head;
}
*/
char *clean(char *unclean){
	int i;
	for (i=0; i<200; i++){
		if (unclean[i] == '\n')
		{
			unclean[i] = '\0';
			break;
		}
	}
}

int main (int argc, const char * argv[]) {
    FILE *fp;
	FILE *fq;
	FILE *fr;
	char file[200];
	char depv[10];
	char ESC=27;
	fputs("Input filename of regressional interest: ", stdout);
	fflush(stdout);
	fgets(file, sizeof file, stdin);
	clean(file);
	fp=fopen(file, "r");
	fq = fp;
	fr = fp;
	if (fp == NULL){
		perror("ERROR: File not found");
		return EXIT_FAILURE;
	}
	printf("OK;\n");
	int vars;
	char x[2];
	char allvars[10];
	printf("Input number of variables in dataset:");
	scanf("%d", &vars);
	int loop = 0;
	printf("Headers:");
	while (loop<vars){
		fscanf(fp, "%s", allvars);
		printf(" %s ", allvars);
		loop++;
	}
	char newvars[10];
	fgets(x, sizeof x, stdin);
	fputs("\nInput the dependant variable header (<10 characters): ", stdout);
	fflush(stdout);
	fgets(depv, sizeof depv, stdin);
	clean(depv);
	int count = 0;
	while (depv != newvars){
		fscanf(fq, "%s", newvars);
		printf("%s", newvars);
		count++;
	}
	printf("%d", count);
	
    return 0;
}
