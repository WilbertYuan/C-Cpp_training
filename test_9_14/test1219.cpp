#include <cstdio>
#include <string>
#include <iostream>
#include <cstring>
using namespace std;

char in[100], str[100];

int upper(string t)
{
    for (int i = 0; i < 5; i++)
    {
        if ('A' > t[i] || 'Z' < t[i])
            return 0;
    }
    return 1;
}
void change(string t, string& last)
{
    int flag[10],j;
    memset(flag, 0, sizeof(flag));
    for (int i = 0; i < 5; i++)
    {
        if (t[i] == in[i]) flag[i] = 1;
    }
    for (int i = 0; i < 5; i++)
    {
        if (t[i] == in[i]) last += t[i];
        else
        {
            for (j = 0; j < 5; j++)
            {
                if (t[i] == in[j] && !flag[j])
                {
                    last += in[j] - 'A' + 'a';
                    flag[j] = 1;
                    break;
                }
            }
            if (5 == j) last += ".";
        }
    }
}

int main()
{
    getchar();
    while (gets(in) && 0 != strcmp(in, "LINGO"))
    {
        putchar(10);
        printf("%c....\n", in[0]);
        string t, gin = in, last;
        last = in[0];
        last += "....";
        int i, j, flag = 0;
        for (i = 0; i < 6; i++)
        {
            gets(str);
            t = str;
            if (t == gin)
            {
                printf("%s\n", gin.c_str());
                break;
            }
            else if (t == "")
            {
                flag = 1;
                break;
            }
            else
            {
                if (5 == t.length() && upper(t))
                {
                    last = "";
                    change(t, last);
                }
                if (5 == i)
                {
                    flag = 1;
                    break;
                }
                printf("%s\n", last.c_str());
            }
        }
        if (flag)
        {
            for (j = 0; j < 5; j++)
                printf("%c", gin[j] - 'A' + 'a');
            putchar(10);
        }
        while (0 != strcmp(str, ""))
        {
            gets(str);
        }
    }
    return 0;
}