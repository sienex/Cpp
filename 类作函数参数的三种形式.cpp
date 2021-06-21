#include<iostream>

/*对象直接作参数*/

using namespace std;

class Counter
{
private:
	int value;
public:
	void add(int v);
	Counter(int v)
	{
		value = v;
	}
	void show();
};

void Counter::add(int v)
{
	value += v;
}

void Counter::show()
{
	cout << value << endl;
}

Counter func(Counter obj)
{
	obj.add(6);
	return obj;
}

void func2(Counter& obj)
{
	obj.add(6);
}

void func3(Counter *ptr)
{
	ptr->add(6);
}

int main()
{
	Counter b1 = 5;
  Counter c1 = func(b1);
	b1.show();
	c1.show();
	return 0;
}





#include<iostream>

/*对象指针作参数*/

using namespace std;

class Counter
{
private:
	int value;
public:
	void add(int v);
	Counter(int v)
	{
		value = v;
	}
	void show();
};

void Counter::add(int v)
{
	value += v;
}

void Counter::show()
{
	cout << value << endl;
}

Counter func(Counter obj)
{
	obj.add(6);
	return obj;
}

void func2(Counter& obj)
{
	obj.add(6);
}

void func3(Counter *ptr)
{
	ptr->add(6);
}

int main()
{
	Counter b1 = 5;
	b1.show();
	func3(&b1);
	b1.show();
	return 0;
}





#include<iostream>

/*对象引用作为参数*/

using namespace std;

class Counter
{
private:
	int value;
public:
	void add(int v);
	Counter(int v)
	{
		value = v;
	}
	void show();
};

void Counter::add(int v)
{
	value += v;
}

void Counter::show()
{
	cout << value << endl;
}

Counter func(Counter obj)
{
	obj.add(6);
	return obj;
}

void func2(Counter& obj)
{
	obj.add(6);
}

void func3(Counter *ptr)
{
	ptr->add(6);
}

int main()
{
	Counter b1 = 5;
	b1.show();
	func2(b1);
	b1.show();
	return 0;
}
