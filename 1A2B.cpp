#include<iostream>
#include<string>
#include<algorithm>
#include<ctime>

using namespace std;

int MainMenu();
string MakeResult();//构造一个四位不重复的随机数作为返回结果
string GetAnswer();//判断输入的数时候正确，否则一直输入
void PlayGuess();
void ComputerGuess();
void RankList();
bool IsUnavaiable(string s);
string Compare(string result,string answer);



int main()
{
	srand(unsigned (time(0)));
	while (MainMenu());
}


int MainMenu()
{
	system("cls");
	cout << "1.我想你猜" << endl;
	cout << "2.你想我猜" << endl;
	cout << "3.排行榜" << endl;
	cout << "0.退出" << endl;

	int choice;
	cout << "请输入你的选择" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:PlayGuess(); break;
	case 2:ComputerGuess(); break;
	case 3:RankList(); break;
	case 0:return 0;
	default:cout << "输入错误请重新输入" << endl;
		system("pause");
		break;
	}
	return 1;
}


string GetAnswer()
{
	string answer;
	while (1) {
		cin >> answer;
		if (answer == "0000")exit(0);
		if (!IsUnavaiable(answer)); break;
	}
	return answer;
}


string MakeResult()
{
	char temp[] = "0123456789";
	random_shuffle(temp, temp + 10);
	temp[4] = 0;//截断
	return temp;
}


void PlayGuess()
{
	string result = "9012";///MakeResult
	system("cls");
	int round = 0;
	for (; round < 15; round++)
	{
		string answer = GetAnswer();
		if (answer == result)
		{
			cout << "恭喜你答对了" << endl; system("pause"); break;
		}
		else
		{
			cout << Compare(result, answer) << endl;

		}
	}

	if (round >= 15)
	{
		cout << "您没有在规定回合内猜出" << result << endl;
	}
	system("pasue");
	return;
}


string Compare(string result, string answer)
{
	string temp = "0A0B";
	int A = 0, B = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j=0; j < 4; j++)
		{
			if (answer[i] == result[j])
			{
				if (i == j)
				{
					A++;
				}
				else
				{
					B++;
				}
			}
		}
	}

	temp[0] = A + '0';
	temp[2] = B + '0';
	return temp;
}


bool IsUnavaiable(string s)
{
	int count[10] = { 0 };
	for (int i = 0; i < 4; i++)
	{
		if (s[i] < '0' || s[i]>'9')
		{
			cout << "存在非法字符" << endl;
			return true;
		}

		int n = s[i] = '0';
		count[n]++;
		if (count[n] > 1)
		{
			cout << "存在重复数字" << endl;
			return true;
		}
		
	}
	return false;
}


void ComputerGuess()
{
	
}


void RankList()
{

}
