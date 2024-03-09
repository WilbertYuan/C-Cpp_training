//#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
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
	Student si;
	double sum[20];
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d %s %lf %lf %lf", &si.ID, si.name, &si.mathscore, &si.pscore, &si.englishscore);
		sum[i] = (si.mathscore + si.pscore + si.englishscore) / 3;
	}
	for (int j = 0; j < n; j++)
	{
		int m = 0;
		m = j + 1;
		printf("The average score of the %dth student is %d.\n", m, sum[j]);
	}
	return 0;
}