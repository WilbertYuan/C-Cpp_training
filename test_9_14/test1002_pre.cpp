//#include <bits/stdc++.h>
//#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
typedef struct tele
{
    int tele_num;
    int count;
}tele;
int main()
{
    int num = 0, tele_n = 0,teleprint[10000] = { 0 };
    tele telelist[10000];
    //scanf("%d",&num);
    cin >> num;
    char testch;
    getchar();
    for (int i = 0; i < num; i++)
    {
        int example[7] = { 0 };
        int wholenum = 0;
        for (int j = 0; j < 15; j++)
        {
            //cin >> testch;
            //scanf("%d", &testch);
            testch = getchar();
            int testnum = 0;
            if (testch != '-' && testch != '\n')
            {
                if (testch >= 'A' && testch <= 'O')
                {
                    testnum = (testch - 'A') / 3 + 2;
                }
                else if (testch >= 'P' && testch <= 'S')
                {
                    testnum = 7;
                }
                else if (testch >= 'T' && testch <= 'Y')
                {
                    testnum = (testch - 'A' - 1) / 3 + 2;
                }
                else
                {
                    testnum = testch - '0';
                }
                example[wholenum] = testnum;
                wholenum++;
            }
            if (wholenum >= 7)
                break;
        }
        int telenum = 0;
        for (int j = 0; j < 7; j++)
        {
            telenum = telenum * 10 + example[j];
            
        }
        bool found = false;
        for (int j = 0; j < tele_n; j++)
        {
            if (telelist[j].tele_num == telenum)
            {
                telelist[j].count++;
                found = true;
                break;
            }
        }
        if (!found)
        {
            telelist[tele_n].tele_num = telenum;
            telelist[tele_n].count = 1;
            tele_n++;
        }
    }
    for (int j = 0; j < tele_n; j++)
    {
        teleprint[j] = telelist[j].tele_num;
    }
    sort(teleprint, teleprint + tele_n);
    if (tele_n == 0)
    {
        printf("No duplicates.");
        return 0;
    }
    for (int i = 0; i < tele_n; i++)
    {
        for (int j = 0; j < tele_n; j++)
		{
			if (teleprint[i] == telelist[j].tele_num && telelist[j].count>1)
			{
				printf("%03d-%04d %d\n", telelist[j].tele_num / 10000, telelist[j].tele_num % 10000, telelist[j].count);
			}
		}
    }
    return 0;
}
int cmp(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}