#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Student
{
	int ID;
	char name[20];
	double mathscore;
	double pscore;
	double englishscore;
};
typedef struct Student Student;
int main()
{
	int n;
	scanf_s("%d", &n);
	Student s1 = { 1001,"Zhang",100,90,80 };
	//Student si;
	//一开始把它改了，但后来发现不写动态数组也可以。
	Student* p = (Student*)malloc(n * sizeof(Student));
	double*sum = (double*)malloc(n*sizeof(double));
	if (p == NULL || sum == NULL) exit(1);
	for (int i = 0; i < n; i++)
	{
		//scanf_s("%d %s %lf %lf %lf", &si.ID, si.name, &si.mathscore, &si.pscore, &si.englishscore);
		scanf_s("%d %s %lf %lf %lf", &p[i].ID, p[i].name,20, &p[i].mathscore, &p[i].pscore, &p[i].englishscore);
		//注意！我们再VS2022中使用的scanf_s与fscanf_s在读入字符串的过程中都会在字符串后面加入长度这一unsigned int 参数！
		// （微软认为原先的scanf和fscanf不够安全，于是重新写了这个函数）
		//如果觉得麻烦请在VS2022编译环境的开头加入#define _CRT_SECURE_NO_WARNINGS 1这样的语句来使用scanf与fscanf语句！
		sum[i] = (p[i].mathscore + p[i].pscore + p[i].englishscore) / 3;
	}
	for (int j = 0; j < n; j++)
	{
		//int m = 0;
		//m = j + 1;
		//printf("The average score of the %dth student is %d.\n",m, sum[j]);
		printf("The average score of the %dth student is %lf.\n", j + 1, sum[j]);//sum里面是double类型的数！用lf
	}
	free(p);
	free(sum);
	return 0;
}