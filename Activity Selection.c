#include <stdio.h>
#include<conio.h>
void printMaxActivities(int s[], int f[], int n)
{
    int i, j;
    int count=0;
    printf("Following activities are selected\n ");


    i = 0;
    printf("%d ", i);
    for (j =i+1; j < n; j++)
    {

        if (s[j] >= f[i])
        {
            printf("%d ", j);
            i=j;
            count++;
        }
    }
    printf(" \n\nMaximum Activities Selection  : %d ",count+1);
}
int main()
{
    int s[] = { 1,4, 3,8, 2, 2 };
    int f[] = { 4,7,5, 9, 15, 6 };
    int n = sizeof(s) / sizeof(s[0]);
    printMaxActivities(s,f,n);

    getch();
}

