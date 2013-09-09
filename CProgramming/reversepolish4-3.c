#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define NUMBER '0'

struct stack{
	double data;
	struct stack* next;
};

void push(struct stack** stk, double data)
{
	struct stack* cur = malloc(sizeof(struct stack));
	if(cur == NULL)
	{
		printf("\nstack overflow");
		return;
	}
	cur->data = data;
	cur->next = *stk;
	*stk = cur;
}

double pop(struct stack** stk)
{
	if(*stk == NULL)
	{
		printf("\nstack underflow");
		return -1;
	}
	struct stack* cur = *stk;
	*stk = cur->next;
	int data = cur->data;
	free(cur);
	return data;
}

int getop(char s[])
{
//	char* s = *str;
	int i = 0;
	int c;
	while((s[0] = c = getchar()) == ' ' || c == '\t')
		;
	s[1] = '\0';
printf("\ns in getop = %s\n", s);
	if(!isdigit(c) && c != '.')	//not a number (operator)
		return c;
printf("\ns 2nd in getop = %s\n", s);	
	if(isdigit(c))
		while(isdigit(c = getchar()))
			s[++i] = c;
printf("\ns 3rd in getop = %s\n", s);
	if(c == '.')	//fractional part
		while(isdigit(c = getchar()))
			s[++i] = c;

	s[i] = '\0';
	return NUMBER;
}

void main()
{
	int type;
	double op2;
	char s[1024];

	struct stack* stk = NULL;

	while((type = getop(s)) != 'q')
	{
		printf("\n s = %s\ntype = %c", s, type);
		switch(type)
		{
			case NUMBER:
					push(&stk, atof(s));
					break;
			case '+':
					push(&stk, pop(&stk) + pop(&stk));
					break;

			case '*':
					push(&stk, pop(&stk)*pop(&stk));
					break;

			case '-':
					op2 = pop(&stk);
					push(&stk, pop(&stk)-op2);
					break;
			case '/':
					op2 = pop(&stk);
					if(op2 != 0.0)
						push(&stk, pop(&stk)/op2);
					else
						printf("\nError zero division");
					break;

			case '\n':
					printf("\nresult = %lf\n", pop(&stk));
					break;

			default:
					printf("\nerror: unknown\n");
					break;

		}

	}
	printf("\nresult exp = %lf\n", pop(&stk));	
}
