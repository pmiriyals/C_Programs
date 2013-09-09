#include<stdio.h>
#include<string.h>

struct node{
	double b;
	int c;
	char a;
};

void main()
{
	printf("\nsizeof(int) = %d", sizeof(int));
	printf("\nsizeof(int*) = %d", sizeof(int*));
	printf("\nsizeof(void) = %d", sizeof(void));
	printf("\nsizeof(void*) = %d", sizeof(void*));
	printf("\nsizeof(char) = %d", sizeof(char));
	printf("\nsizeof(char*) = %d", sizeof(char*));
	printf("\nsizeof(long) = %d", sizeof(long));
	printf("\nsizeof(long*) = %d", sizeof(long*));
	printf("\nsizeof(float) = %d", sizeof(float));
	printf("\nsizeof(float*) = %d", sizeof(float*));
	printf("\nsizeof(double) = %d", sizeof(double));	
	printf("\nsizeof(double*) = %d", sizeof(double*));		
	printf("\nsizeof(struct node) = %d", sizeof(struct node));
	printf("\nsizeof(struct node*) = %d", sizeof(struct node*));
	char s[] = "hello";
	printf("\nstring size using strlen = %d\n", strlen(s));
	printf("string size using sizeof(s)/sizeof(char) = %d\n", sizeof(s)/sizeof(char));
}
