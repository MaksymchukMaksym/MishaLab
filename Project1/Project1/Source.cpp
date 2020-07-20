/*
������ 12. �������� ���� Aqueue � ��������� ���� �����, �� �������� �� ����� ��������� ����������� ������.
�����������, ��� ����� ���� ��������� �������� �������� ����, �� ������� ����������� ����� string.
����������� ������� � ����� ����� ��� ��������� ����� ��������:
�dd() � ������� � ����� ������ ��������;
pop() � ������ � �������� �������� �� �����;
print() � ������� �� �������� �� ����� �� �����;
num() � ��������� ������� �������, �� ����������� � ����;
isempty() � ��������� �������� true (��� bool), ���� ����� �����.

\\���� �� ���
*/

#include <iostream>
#include <Windows.h>
using namespace std;

class aQueue
{
public:
	aQueue();
	aQueue(string x);
	~aQueue();
private:
	class data
	{
	public:
		data(string x)
		{
			this->dani = x;
			this->next = nullptr;
		}
		~data()
		{
			delete next;
		}
		string Getdata() { return dani; }
		data* next;
	private:
		string dani;
	};

	data* head;
	data* tail;

public:

	void add(string x)
	{
		if (head == nullptr)
		{
			tail = head = new data(x);
		}
		else
		{
			tail->next = new data(x);
			tail = tail->next;
		}
	}

	string pop()
	{
		string x = head->Getdata();
		data* del = head;
		head = head->next;
		del->next = nullptr;
		delete del;
		return x;
	}

	void print()
	{
		cout << "�� ��� � ����:" << endl;
		data* scroll = head;
		while (scroll != nullptr)
		{
			cout << scroll->Getdata() << " " << endl;
			scroll = scroll->next;
		}
	}
	int num()
	{
		int num = 0;
		data* scroll = head;
		while (scroll != nullptr)
		{
			num++;
			scroll = scroll->next;
		}
		return num;
	}
	bool isempty()
	{
		if (head == nullptr)
		{
			return true;
		}
	}

};

aQueue::aQueue()
{
	tail = head = nullptr;
}

aQueue::aQueue(string x)
{
	tail = head = new data(x);
}

aQueue::~aQueue()
{
	delete head;
	delete tail;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	aQueue x;
	x.add("lol");
	x.add("x");
	x.add("z");

	x.print();
	x.pop();
	x.print();
	//cout << "Hello World!\n";
}
