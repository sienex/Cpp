#include<iostream>
#include<ctime>
#include<sstream>
#include<string>//zi fu chaun
#include <algorithm>
#include<vector>
using namespace std;
int MainMenu();
bool isunavaiable(string s);
string getanswer();
string makeresult();
string compare(string result, string answer);
void playerguess();
int main()
{
	srand((unsigned)time(NULL));
	while (MainMenu());
}

string compare(string result, string answer)
{
	string X="0A0B";
	int x=0, y=0;
	for (int i = 0;i < 4;i++)
	{
		for (int j=0;j < 4;j++)
		{
			if (result[j] == answer[i])
			{
					if (i == j)
					{
								x++;
								
					}
							else
							{
								y++;
							}
			
			}
			
			
		}
	}
	X[0] = x+'0';X[2] = y+'0';
	return X;
}

string makeresult()
{
	char temp[]= "0123456789";
	random_shuffle(temp, temp + 10);//随机洗牌
	temp[4] = 0;//字符串强行截断
	return temp;	
}

string getanswer()
{
	string answer;
	while (1)
	{
		cin >> answer;
		if (answer == "0000")exit(0);
		if (!isunavaiable(answer))
		{
			break;
		}
	}
	
	return answer;
}

bool isunavaiable(string s)
{
	int count[10] = { 0 };//0~9十个数计数器
	for (int i = 0;i < 4;i++)
	{
		if (s[i] < '0'||s[i]>'9')//0~9
		{
			cout << "非法字符，请重新输入" << endl;
			system("pause");
			return true;
		}

		//检验重复性
		int n = s[i] - '0';
		count[n]++;
		if(count[n]>1)
		{
			cout << "有重复数字，请重新输入";
			system("pause");
			return true;
		}
	}
	return false;
}

void playerguess()
{
	string result = makeresult();
	char decision;
	system("cls");//清屏
	int round=0;//计数器
	for (;round < 15;round++)
	{
		string answer = getanswer();
		if (answer == result)
		{
			cout << "you are right"<<endl;
			break;
		}
		else
		{
			cout << compare(result, answer) << endl;
		}
	}
	if (round == 15)
	{
		cout << "you didn't guess the num";
		cout << "you want to try again? Y or N" << endl;
		cin >> decision;
		if (decision == 'Y')
		{
			playerguess();
		}
		else if (decision == 'N')
		{
			MainMenu();
		}
	}
	system("pause");
	return;
}

int MainMenu() //主菜单
{
	int choice;
	cout << "1.playerchoice"<<endl;
	cout << "2.out"<<endl;
	cin >> choice;
	switch (choice)
	{
	case 0:return 0;break;
	case 1:playerguess();break;
	default:cout << "again"<<endl;break;
	}
	return 1;
}
