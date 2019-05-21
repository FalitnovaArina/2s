// ConsoleApplication44.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include<iostream>
#include<windows.h>
using namespace std;

class bilet
{
public:
	int  rno;
	virtual double getNomer() = 0;
};

class student :public bilet
{
protected:
	int  m1, m2;
public:
	void operator ++()
	{
		m1 = m1 + 1;
	}
	void operator --()
	{
		m1 = m1 - 1;
	}
	void operator +(int c)
	{
		m1 = m1 + c;
	}
	double getNomer()
	{
		return rno;
	}
	student()
		{
		cout << "Vvedite nomer bileta :";
		cin >> rno;
		cout << "Vvedite pervuyu otmetku   :";
		cin >> m1;
		cout << "Vvedite vtoruyu otmetku   :";
		cin >> m2;
	}
};
class sports
{
private:
	int sm;

public:
	sports(int sm1)
	{
		this->sm = sm1;
	}
	sports()
	{
		cout << "\nVvedite otmetku po sportu :";
		cin >> sm;
	}
	~sports()
	{

	}
	int  getsm()
	{
		return sm;
	}
	friend void setData(int, sports&);

};
void setData(int w, sports& a)
{
	a.sm = w;
}
class statement : public student, public sports
{
	int tot, avg;
public:
	statement()
	{
		sports();
		student();
	}

	void display()
	{
		tot = (m1 + m2 + getsm());
		avg = tot / 3;
		cout << "\n\n\tNomer bileta    : " << rno << "\n\tVsego      : " << tot;
		cout << "\n\tSredniy ball    : " << avg;
	}
};
void main()
{
	statement obj;
	obj.display();
	system("pause");
}