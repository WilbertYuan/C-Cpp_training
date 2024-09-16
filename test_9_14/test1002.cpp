#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#define MAXLEN 100000
using namespace std;
int cmp(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}
int main()
{
    int count = 0,typecount = 0,n = 0,Noduplicates = 0,sum = 0;
    char ch;
    int* telelist = (int*)malloc(sizeof(int) * MAXLEN);
    if (telelist == NULL) return 0;
    cin >> count;
    ch = getchar();
    for (n = 0; n < count; n++)
    {
        sum = 0;
        ch = getchar();
        while (ch != '\n')
        {
            if (ch >= '0' && ch <= '9')
            {
                sum = sum * 10 + ch - '0';
            }
            else if (ch >= 'A' && ch <= 'P')
            {
                sum = sum * 10 + (ch - 65) / 3 + 2;
            }
            else if (ch >= 'R' && ch <= 'Y')
            {
                sum = sum * 10 + (ch - 66) / 3 + 2;
            }
            ch = getchar();
        }
        telelist[n] = sum;
    }

    qsort(telelist, count, sizeof(int), cmp);
    for (n = 0, typecount = 1; n < count - 1; n++)
    {
        typecount = 1;
        while (telelist[n] == telelist[n + 1])
        {
            n++;
            typecount++;
        }
        if (typecount > 1)
        {
            Noduplicates = 1;
            printf("%03d-%04d %d\n", telelist[n] / 10000, telelist[n] % 10000, typecount);
        }
    }
    if (Noduplicates == 0)
    {
        printf("No duplicates.\n");
    }
    ch = getchar();
    return 0;
}
