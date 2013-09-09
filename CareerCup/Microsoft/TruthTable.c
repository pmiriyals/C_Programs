#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

void TruthTable(int num)
{
	int i, j, temp;
	for(i = 0; i < pow(2, num); i++)
	{
		printf("\n");
		temp = i;
		for(j = 0; j < num; j++)
		{
			if(temp & 1)
				printf(" T ");
			else
				printf(" F ");
			temp >>= 1;
		}
	}
}

//from careercup
void print_table(int n, char *s, int index, int* c)
{
  if (n == 0) {
    printf("%s\n", s);
	++(*c);
    return;  
  }

	*c = *c + 1;
  print_table(n-1, (strcpy(s+index, "T"), s), index + 1, c);
	*c = *c + 1;
  print_table(n-1, (strcpy(s+index, "F"), s), index + 1, c);

  return;
}


void main()
{
	int num;
	printf("\nPlease enter a num = ");
	scanf("%d", &num);
	char s[100];
	int c = 0;
	print_table(num, s, 0, &c);
	printf("\nc = %d\n", c);
	TruthTable(num);
}
