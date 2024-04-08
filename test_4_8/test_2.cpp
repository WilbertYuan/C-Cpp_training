//实验题目2 定义一个时间类Time，有三个私有成员变量Hour、Minute、Second，定义构造函数、析构函数
//以及用于改变、获取、输出时间信息的公有函数，主函数中定义时间对象，并通过调用各种成员函数完成时间
// 的设定、改变、获取、输出等功能。
//① 按要求完成类的定义与实现。
//② 修改数据成员的访问方式，观察编译结果。
//③ 在Time类中定义一个成员函数，用于实现时间增加一秒的功能，主函数中通过对象调用该函数，并输出增
// 加一秒后的时间信息。
//④ 定义一个普通函数。
// 
//void f(Time  t)
//{
//	t.PrintTime();
//}
// 
//在Time类中增加拷贝构造函数的定义，主函数中调用该函数，运用调试工具跟踪，分析整个程序调用构造函
// 数（包括拷贝构造函数）和析构函数的次数；再将f函数的形式参数分别修改为引用参数和指针参数（此时
// 函数代码修改为{ t->PrintTime(); }, 主函数中调用，再分析此时调用构造函数和析构函数的次数。
#include<iostream>
#include<string>
using namespace std;
class Time 
{
private:
	int Hour,Minute,Second;
public:
	//Time(int _Hour, int _Minute, int _Second);
	Time(const Time& t);
	~Time();
	void PrintTime();
	void IncreseOneSecond();

};

//Time::Time(int _Hour,int _Minute,int _Second):Hour(_Hour),Minute(_Minute),Second(_Second)
//{
//	cout << "constuct" << Second << endl;
//}


//在上题中我已经将进位的函数融合在了copy constructor函数中，以下是它的代码，
//不过我还是把IncreaceOneSecond()函数又写了一下，在此段代码下面
Time::Time(const Time& t)
{
	Second = t.Second;
	Minute = t.Minute;
	Hour = t.Hour;
	if (Second <= 59)
	{
		Second = t.Second + 1;
	}
	else if (Minute <= 59)
	{
		Second = 0;
		Minute = t.Minute + 1;
	}
	else
	{
		Minute = 0;
		Hour = t.Hour + 1;
	}
	cout << "copy constuct" << Second << endl;
}
void Time::IncreseOneSecond()
{
	if (Second <= 59)
	{
		Second++;
	}
	else if (Minute <= 59)
	{
		Second = 0;
		Minute++;
	}
	else
	{
		Minute = 0;
		Hour++;
	}
}
Time::~Time()
{
	cout << "destruct" << Second << endl;
}
void Time::PrintTime()
{
	cout << Hour << "-" << Minute << "-" << Second << endl;
}

void f(Time* t)
{
	t->PrintTime();
}

int main()
{
	Time t1;
	Time t2 = t1;
	Time t3 = t2;
	cout << t3.Hour << "-" << t3.Minute << "-" << t3.Second << endl;
	f(&t3);
	return 0;
}