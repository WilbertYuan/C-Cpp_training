#include <stdio.h>
#include <math.h>


int main() 
{
    char f[100];
    //char proparr[40] = { 0 };
    char ad[50] = { 0 }, orr[50] = { 0 }, res[50] = { 0 }, dou[50] = { 0 };
    int adnum = 0, ornum = 0, resnum = 0, dounum = 0;
    int propnum = 0, relationnum = 0, fnum = 0, propnumf = 0;
    
    typedef struct Prop
    {
        char name;
        //int place;
        int tre;
    }Prop;

    typedef struct Propfull
    {
        char name = '0';
        int place = '-1';
        int tre = 1;
        int* ptr = new int[100];
    }Propfull;


    typedef struct Relation 
    {
        char name = '0';
        int value = 0;
        int place = -1;
        int ifcalcu = 0;
    }Relation;

    Prop proparr[40];
    Propfull proparrf[40];
    Relation relationarr[50];

    printf("请输入一个命题公式:\n");
    fgets(f, sizeof(f), stdin);
    //! & | > -
    
    for (int i = 0;; i++)
    {
        if (!f[i])
        {
            fnum = i;
            break;
        }
        else if (('a' <= f[i] && 'z' >= f[i]) || ('A' <= f[i] && 'Z' >= f[i]))
        {
            int flag = 1;
            for (int j = 0; j < propnum; j++)
            {
                if (f[i] == proparr[j].name)
                {
                    flag = 0;
                    break;
                }
            }
            if (flag)
            {
                proparr[propnum].name = f[i];
                //proparr[propnum].place = i;
                propnum++;
            }
            proparrf[propnumf].name = f[i];
            proparrf[propnumf].place = i;
            propnumf++;
        }
        else if (f[i] == '&')
        {
            relationarr[relationnum].name = '&';
            relationarr[relationnum].value = 400 - adnum;
            relationarr[relationnum].place = i;
            adnum++;
            relationnum++;
        }
        else if (f[i] == '|')
        {
            relationarr[relationnum].name = '|';
            relationarr[relationnum].value = 300 - ornum;
            relationarr[relationnum].place = i;
            ornum++;
            relationnum++;
        }
        else if (f[i] == '>')
        {
            relationarr[relationnum].name = '>';
            relationarr[relationnum].value = 200 - resnum;
            relationarr[relationnum].place = i;
            resnum++;
            relationnum++;
        }
        else if (f[i] == '-')
        {
            relationarr[relationnum].name = '-';
            relationarr[relationnum].value = 100 - dounum;
            relationarr[relationnum].place = i;
            dounum++;
            relationnum++;
        }
        else if (f[i] == '!')
        {

        }
    }

    // ! solution by initially deleting
    for (int i = 0; i < fnum-1; i++)
    {
        if (('a' <= f[i] && 'z' >= f[i]) || ('A' <= f[i] && 'Z' >= f[i]))
        {
            int trenum = 0;
            int j = i - 1;
            if (j >= 0)
            {
                while (f[j] == '!')
                {
                    if (j >= 1)
                    {
                        trenum++;
                        j--;
                    }
                    else
                    {
                        trenum++;
                        break;
                    }
                }
                if (f[j] != '!') j++;
                if (trenum > 0)
                {
                    if (trenum % 2 == 0)
                    {
                        for (int k = j; k <= i - 1; k++)
                        {
                            f[k] = '0';
                        }
                    }
                    else
                    {
                        for (int k = j; k <= i - 2; k++)
                        {
                            f[k] = '0';
                        }
                    }
                }
            }
        }
    }
    // allocating true lists initially
    int** p = new int* [propnum];
    for (int i = 0; i < propnum; i++)
    {
        *(p + i) = new int[int(pow(2.0, propnum))];
        int flag = 1;
        for (int jk = 0; jk<int(pow(2.0, i + 1)); jk++)
        {
            for (int k = 0; k < int(pow(2.0, propnum - i - 1)); k++)
            {
                *(*(p + i) + (jk * int(pow(2.0, propnum - i - 1))) + k) = (flag > 0);
            }
            flag *= (-1);
        }
    }

    //allocating true lists to all the props.
    for (int j = 0; j < propnum;j++)
    {
        for (int i = 0; i < propnumf; i++)
        {
            if (proparr[j].name == proparrf[i].name)
            {
                for (int k = 0; k < int(pow(2.0, propnum)); k++)
                {
                    *(proparrf[i].ptr + k) = *(*(p + j) + k);
                }
            }
        }
    }



    //scaning proparrf to delete !
    for (int i = 0; i < propnumf; i++)
    {
        if (f[proparrf[i].place - 1] == '!')
        {
            f[proparrf[i].place - 1] = '0';
            for (int j = 0; j<int(pow(2.0, propnum)); j++)
            {
                *(proparrf[i].ptr + j) = ~(*(proparrf[i].ptr + j));
            }
        }
    }
    
    // & | > - calculating
    for (int i = 0; i < relationnum; i++)
    {
        int max = 0,maxplace,maxid;
        for (int j = 0; j < relationnum; j++)
        {
            if ((!relationarr[j].ifcalcu) && (relationarr[j].value > max))
            {
                max = relationarr[j].value;
                maxplace = relationarr[j].place;
                maxid = j;
            }
        }
        relationarr[maxid].ifcalcu = 1;
        int left = maxplace - 1, right = maxplace + 1;
        while (!('a' <= f[left] && 'z' >= f[left] || ('A' <= f[left] && 'Z' >= f[left])))
        {
            left--;
        }
        while (!('a' <= f[right] && 'z' >= f[right] || ('A' <= f[right] && 'Z' >= f[right])))
        {
            right++;
        }
        // 4.9 接下来该写left与right做运算，在此之前需要调用到proparrf
    }

    // f[] test
    for (int i = 0; i < fnum-1; i++)
    {
        printf("%c", f[i]);
    }

    


    //真值表横向打印
    //for (int i = 0; i < propnum; i++)
    //{
    //    for (int j = 0; j<int(pow(2.0, propnum)); j++)
    //    {
    //        printf("%d", *(*(p + i) + j));
    //    }
    //    printf("\n");
    //}


    //释放空间
    for (int i = 0; i < propnum; i++)
    {
        delete[] * (p + 1);
    }
    delete[] p;

    for (int i = 0; i < 40; i++)
    {
        delete[] proparrf[i].ptr;
    }
    //for (int i = 0; i < relationnum; i++)
    //{
    //    printf("%c",proparr[i]);
    //}
    
    return 0;
}