// ConsoleApplication46.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <windows.h>
using namespace std;
class bilet
{
	virtual double getNomer() = 0;
};
class student : public bilet
{
private:
	int rno;
protected:
	int  m1, m2;
public:
	double getNomer() override
	{
		return rno;
	}
	student()
	{
		char crno[100];
		while (true)
		{
			cout << "Vvedite nomer bileta :";
			cin >> crno;
			bool b = true;
			for (unsigned int i = 0; i<strlen(crno); i++)
			{
				if (!isdigit(crno[i]))
				{
					b = false;
				}
			}
			if (b == true)
			{
				rno = atoi(crno);
				break;
			}
			else
			{
				cout << "Neverniy vhod\n";
			}
		}

		char cm1[100];
		while (true)
		{
			cout << "Vvedite pervuyu otmetku   :";
			cin >> cm1;
			if (strlen(cm1) == 1 && (cm1[0] == '1' || cm1[0] == '2' || cm1[0] == '3' || cm1[0] == '4' || cm1[0] == '5'))
			{
				m1 = cm1[0] - 48;
				break;
			}
			else
			{
				cout << "Neverniy vhod\n";
			}
		}


		char cm2[100];
		while (true)
		{
			cout << "Vvedite vtoruyu otmetku   :";
			cin >> cm2;
			if (strlen(cm2) == 1 && (cm2[0] == '1' || cm2[0] == '2' || cm2[0] == '3' || cm2[0] == '4' || cm2[0] == '5'))
			{
				m2 = cm2[0] - 48;
				break;
			}
			else
			{
				cout << "Neverniy vhod\n";
			}
		}
	}
};

class sports
{
private:
	int sm;

public:
	sports()
	{
		cout << "Vvedite otmetku po sportu :";
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

	}
	void display()
	{
		tot = (m1 + m2 + getsm());
		avg = tot / 3;
		cout << "\n\n\tNomer bileta    : " << getNomer() << "\n\tVsego      : " << tot;
		cout << "\n\tSredniy ball    : " << avg;
	}
};

int main()
{
	statement obj;
	char csportGrade[10];
	int sportGrade;
	while (true)
	{
		cin >> csportGrade;
		if (strlen(csportGrade) == 1 && (csportGrade[0] == '1' || csportGrade[0] == '2' || csportGrade[0] == '3' || csportGrade[0] == '4' || csportGrade[0] == '5'))
		{
			sportGrade = csportGrade[0] - 48;
			setData(sportGrade, obj);
			break;
		}
		else
		{
			cout << "Neverniy vhod\nVvedite otmetku po sportu :";
		}

	}
	obj.display();
	system("pause");
	return 0;
}
