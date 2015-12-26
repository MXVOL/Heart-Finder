#include <iostream>  
#include <vector>    
#include <fstream>   
#include <cstdlib>   
#include <map>       
#include <windows.h> 
#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <iomanip>
#include <ctime>
#include <string>
#include <cctype>
#include <sstream>

using namespace std;


int main()
{
	SetConsoleTitle("Heart finder");
	int il2=0;
	int w=119, s=115, a=97, d=100;
	srand(time(NULL));
	char map[100][100];
	for(int x=0; x<100; x++)
	{
		for(int y=0; y<100; y++)
		{
			int n = ( rand() % 6 ) + 1;
			if(n == 6)
			{
				map[x][y] = '\5';
			}
			else
			{
				map[x][y] = ' ';
			}
		}
	}
	
	map[4][4] = '@';
	
	int ob1=4;
	int ob2=4;
	int wh=1;
	int zycie = 3;
	
	for(int i=0; i<20; i++)
	{
		int m = ( rand() % 80 ) + 10;
		int m2 = ( rand() % 80 ) + 10;
		if(map[m][m2] == '\3') i--;
		if(map[m][m2] != '\3') map[m][m2] = '\3';
	}
	
	for(int i=0; i<50; i++)
	{
		int m = ( rand() % 80 ) + 10;
		int m2 = ( rand() % 80 ) + 10;
		if(map[m][m2] != '\3') map[m][m2] = '*';
	}
	
	system("mode 20,20");
  	
	for(int i=0; wh=1; i++)
	{
		char k2;
		int x;
		int y;
		for(x = ob1-3; x<ob1+4; x++)
		{
			for(y = ob2-3; y<ob2+4; y++)
			{
				if(map[x][y] == '@')
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 78);
				}
				if(map[x][y] == '\5')
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 74);
				}
				if(map[x][y] == '\3')
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 73);
				}
				if(map[x][y] == '*')
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 72);
				}
				if(map[x][y] == ' ')
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 68);
				}
				cout<<map[x][y];
			}
			cout<<endl;
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 73);
		cout<<"Hearths:"<<il2<<endl;
		if(zycie == 1)
		{
			cout<<" \3     "<<endl;
		}
		if(zycie == 2)
		{
			cout<<" \3 \3   "<<endl;
		}
		if(zycie == 3)
		{
			cout<<" \3 \3 \3 "<<endl;
		}
		k2 = getch();
        int k=(int)k2;
        if(k == w)
        {
        	if(ob1-1>=2)
        	{
				map[ob1][ob2] = ' ';
				ob1--;
				if(map[ob1][ob2] == '\3') il2++;
				if(map[ob1][ob2] == '*') zycie--;
				map[ob1][ob2] = '@';
			}
		}
		if(k == s)
		{
			if(ob1+1<=97)
			{
				map[ob1][ob2] = ' ';
				ob1++;
				if(map[ob1][ob2] == '\3') il2++;
				if(map[ob1][ob2] == '*') zycie--;
				map[ob1][ob2] = '@';
			}
		}
		if(k == a)
        {
			if(ob2-1>=2)
        	{
				map[ob1][ob2] = ' ';
				ob2--;
				if(map[ob1][ob2] == '\3') il2++;
				if(map[ob1][ob2] == '*') zycie--;
				map[ob1][ob2] = '@';
			}
		}
		if(k == d)
        {
			if(ob2+1<=97)
        	{
				map[ob1][ob2] = ' ';
				ob2++;
				if(map[ob1][ob2] == '\3') il2++;
				if(map[ob1][ob2] == '*') zycie--;
				map[ob1][ob2] = '@';
			}
		}
		system("cls");
		if(il2 == 20)
		{
			cout<<"WINNER!"<<endl;
			getchar();getchar();
			exit(0);
		}
		if(zycie == 0)
		{
			cout<<"GAME OVER!!!"<<endl;
			getchar();getchar();
			exit(0);
		}
	}
}
