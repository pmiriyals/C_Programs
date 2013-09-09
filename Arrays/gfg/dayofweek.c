#include<stdio.h>

int dayofweek(int d, int m, int y)
{
    static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
	printf("\n y = %d\n", y);
    y -= m < 3;
	printf("\n y = %d\n", y);
    return ( y + y/4 - y/100 + y/400 + t[m-1] + d) % 7;
}
 
/* Driver function to test above function */
int main()
{
    int day = dayofweek(28, 1, 2013);
	char* days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    printf ("\nday = %d", day);
 	printf("\n day = %s\n", days[day]);
    return 0;
}
