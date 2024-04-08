#include<iostream>
#include<string>

using namespace std;

class BookCard 
{	
private:
	string id;
	string name;
	int number;
public:
	BookCard(string id = "B19010250", string name = "Ñ©·å", int number = 4);
	void display();
	bool borrow();
};


BookCard::BookCard(string _id, string _name, int _number)
{
	id = _id;
	name = _name;
	number = _number;
	//cout << "con" << endl;
	//constructor function
}

bool BookCard::borrow(void)
{
	if (number < 10) return true;
	else return false;
}

void BookCard:: display()
{
	cout << id << " " << name << " " << number << endl;
}

void f(BookCard& bk)
{
	if (!bk.borrow())
	{
		bk.display();
		cout << "you have borrowed 10 books,can not borrow any more!" << endl;
	}
	else
		bk.display();
}

int main()
{
	BookCard bk1("B20190620", "¶«Æ½", 10), bk2;
	f(bk1);
	f(bk2);
	return 0;
}
