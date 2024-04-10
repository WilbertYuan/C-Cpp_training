#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<random>
#include<iostream>
#include<chrono>

using namespace std;

int main()
{
	while (true)
	{
		int num = 0, num2 = 0;
		cout << "请输入集合元素的个数：" << endl;
		cin >> num;
		if (!num)
		{
			cout << endl << "不满足自反性" << endl << "满足反自反性" << endl << "满足对称性" << endl << "满足反对称性" << endl;
		}
		else
		{
			int** p = new int* [num];
			for (int i = 0; i < num; i++)
			{
				*(p + i) = new int[num];
			}

			std::default_random_engine generator(std::chrono::system_clock::now().time_since_epoch().count());
			//default_random_engine generator;
			uniform_int_distribution<int> distribution(0, 1);

			for (int i = 0; i < num; i++)
			{
				for (int j = 0; j < num; j++)
				{
					*(*(p + i) + j) = distribution(generator);
				}
			}

			cout << "以下是输出的随机矩阵：" << endl;
			for (int i = 0; i < num; i++)
			{
				for (int j = 0; j < num; j++)
				{
					cout << *(*(p + i) + j) << " ";
				}
				cout << endl;
			}

			int flag1 = 1;
			for (int j = 0; j < num; j++)
			{
				if (*(*(p + j) + j) == 0)
				{
					cout << "不满足自反性，矩阵的第" << j + 1 << "行，第" << j + 1 << "列应该为1" << endl;
					flag1 = 0;
					break;
				}
			}
			if (flag1) cout << "满足自反性" << endl;


			int flag2 = 1;
			for (int j = 0; j < num; j++)
			{
				if (*(*(p + j) + j) == 1)
				{
					cout << "不满足反自反性，矩阵的第" << j + 1 << "行，第" << j + 1 << "列应该为0" << endl;
					flag2 = 0;
					break;
				}
			}
			if (flag2) cout << "满足反自反性" << endl;

			int flag3 = 1;
			for (int i = 0; i < num; i++)
			{
				if (flag3)
				{
					for (int j = 0; j < num; j++)
					{
						if (*(*(p + i) + j) != *(*(p + j) + i))
						{
							cout << "不满足对称性，矩阵的第" << j + 1 << "行，第" << i + 1 << "列应该为" << *(*(p + i) + j) << endl;
							flag3 = 0;
							break;
						}
					}
				}
			}
			if (flag3) cout << "满足对称性" << endl;

			int flag4 = 1;
			for (int i = 0; i < num; i++)
			{
				if (flag4)
				{
					for (int j = 0; j < num; j++)
					{
						if ((*(*(p + i) + j) == 1) && (*(*(p + i) + j) == *(*(p + j) + i)) && (i != j))
						{
							cout << "不满足反对称性，矩阵的第" << j + 1 << "行，第" << i + 1 << "列应该为" << 0 << endl;
							flag4 = 0;
							break;
						}
					}
				}
			}
			if (flag4) cout << "满足反对称性" << endl;

			for (int i = 0; i < num; i++)
			{
				delete[] * (p + i);
			}
			delete[] p;
		}

		cout << endl << endl;
	}

	return 0;
}