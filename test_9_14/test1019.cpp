#include<iostream>
#include<math.h>
#define MAXS 31269
using namespace std;
unsigned a[MAXS];
unsigned s[MAXS];
void play_table(void)
{
	a[1] = s[1] = 1;
	for (int i = 2; i < MAXS; i++)
	{
		a[i] = a[i - 1] + (int)log10((double)i) + 1;
		s[i] = s[i - 1] + a[i];
	}
	return;
}
int compute(int n)
{
	int i = 1;
	while (s[i] < n)
		i++;
	int pos = n - s[i - 1];
	int len = 0;
	for (i = 1; len < pos; i++)
		len += (int)log10((double)i) + 1;

	return (i - 1) / (int)pow((double)10, len - pos) % 10;
}
int main(void)
{
	play_table();

	int test;
	cin >> test;
	while (test--)
	{
		int n;
		cin >> n;
		cout << compute(n) << endl;
	}
	return 0;
}