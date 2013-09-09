#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void printlistcontaininggivenword(char* list[], char* word, int lstcnt)
{
	int* cnt = calloc(256, sizeof(char));
	int i, l = strlen(word);
	for(i = 0; i< l; i++)
		cnt[word[i]]++;

	int j = 0, chk = 0, k = 0;
	while(j < lstcnt)
	{
		for(i = 0; i< strlen(list[j]); i++)
		{
			if(cnt[list[j][i]])
			{
				cnt[list[j][i]]--;
				chk++;
			}
			if(chk == l)
			{
				printf("\n %s", list[j]);
				break;
			}
		}
		j++;
		chk = 0;
		for(i = 0; i< l; i++)
			cnt[word[i]]++;
	}
}

void main()
{
	char* list[] = {"geeksforgeeks", "utensils", "houses", "road"};
	char* word = "sse";
	printlistcontaininggivenword(list, word, 4);
}
