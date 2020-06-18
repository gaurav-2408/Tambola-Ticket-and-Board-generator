/*
	Author:Gaurav Jain
	Created on:25th May 2020
*/
#define _WIN32_WINNT 0x0502
#include <bits/stdc++.h>
#include <stdlib.h>
#include <Windows.h>
#define ll long long 
#define pb push_back
using namespace std;
HANDLE out=GetStdHandle(STD_OUTPUT_HANDLE);
HWND hwnd = GetConsoleWindow();

set <int>s1;
vector <int>v1;
set <int>s2;
vector <int>v2;
set <int>s3;
vector <int>v3;

void fontsize(int a, int b)
{  
  PCONSOLE_FONT_INFOEX lpConsoleCurrentFontEx = new CONSOLE_FONT_INFOEX();  
  lpConsoleCurrentFontEx->cbSize = sizeof(CONSOLE_FONT_INFOEX);  
  GetCurrentConsoleFontEx(out, 0, lpConsoleCurrentFontEx);  
  lpConsoleCurrentFontEx->dwFontSize.X = a;  
  lpConsoleCurrentFontEx->dwFontSize.Y = b;  
  SetCurrentConsoleFontEx(out, 0, lpConsoleCurrentFontEx);  
}  
 
void  changecolor(int desirecolor)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),desirecolor);	
}

int chooseRandom(int s,int e,int count)
{
	int i; 
    for (i = 0;i<count;i++) 
	{ 
        int num = (rand() % (e - s + 1)) + s; 
        return num; 
    } 
}

int main()
{
	if( hwnd != NULL )
	{ 
		SetWindowPos(hwnd ,0,0,0,800,600 ,SWP_SHOWWINDOW|SWP_NOMOVE); 
	}
	srand(time(0));
	system("COLOR 56");
	fontsize(10,25);
	int i1,j1,tickets,count=0;    
	int i,j,val,val1;
	int r=3,c=9,temp;
	ll int arr[r][c];
	bool visited[91];
	char arr1[r][c];
	//changecolor(7);
	cout<<"\t\t\t\t\t\tHOUSIE TICKETS\n";
	cout<<"\tHow many tickets do you want?\n\t";
	cin>>tickets;
	while(tickets--!=0)
	{
		for(i=0;i<101;i++)
		visited[i]=false;
		cout<<"\t\t\t\t\t\t Ticket No."<<count+1<<"\n";
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				arr[i][j]=0;
			}
		}
		while(s1.size()!=5)
		{
			s1.insert(chooseRandom(0,8,1));
		}
		while(s2.size()!=5)
		{
			s2.insert(chooseRandom(0,8,1));
		}
		while(s3.size()!=5)
		{
			s3.insert(chooseRandom(0,8,1));
		}
		
		set<int>::iterator it;
		//1st row,i=0
		for(it=s1.begin();it!=s1.end();++it)
		v1.pb(*it);
		for(i=0;i<v1.size();i++)
		arr[0][v1[i]]=1;
		//2nd row,i=1
		for(it=s2.begin();it!=s2.end();++it)
		v2.pb(*it);
		for(i=0;i<v2.size();i++)
		arr[1][v2[i]]=1;
		//3rd row,i=2
		for(it=s3.begin();it!=s3.end();++it)
		v3.pb(*it);
		for(i=0;i<v3.size();i++)
		arr[2][v3[i]]=1;

//		cout<<"\n\t-----------------------------------------------------------------------------\n";
//		for(i=0;i<r;i++)	//display section
//		{
//			cout<<"\t|";
//			cout<<"\t";
//			for(j=0;j<c;j++)
//			{
//				cout<<arr[i][j]<<"   |\t";
//			}
//			cout<<"\n\t-----------------------------------------------------------------------------\n";
//		}
//		cout<<"\n";
		//placing random numbers in place of 1's in array 'arr'
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
					if(arr[i][j]==1&&j==0)	//goto statement used to avoid number duplicate in same column of a ticket  
					{
						label1:
							arr[i][j]=chooseRandom(1,9,1);
						if(visited[arr[i][j]+1]==false)
						visited[arr[i][j]+1]=true;
						else if(arr[i][j]<arr[i-1][j]&&visited[arr[i-1][j]+1]==true&&i!=0)
						arr[i][j]=chooseRandom(arr[i-1][j],9,1);
						else
						goto label1;
					}
					else if(arr[i][j]==1&&j==1)
					{
						label2:
							arr[i][j]=chooseRandom(10,19,1);
						if(visited[arr[i][j]+1]==false)
						visited[arr[i][j]+1]=true;
						else if(arr[i][j]<arr[i-1][j]&&visited[arr[i-1][j]+1]==true&&i!=0)
						arr[i][j]=chooseRandom(arr[i-1][j],19,1);
						else
						goto label2;
					}
					else if(arr[i][j]==1&&j==2)
					{
						label3:
							arr[i][j]=chooseRandom(20,29,1);
						if(visited[arr[i][j]+1]==false)
						visited[arr[i][j]+1]=true;
						else if(arr[i][j]<arr[i-1][j]&&visited[arr[i-1][j]+1]==true&&i!=0)
						arr[i][j]=chooseRandom(arr[i-1][j],29,1);
						else
						goto label3;
					}
					else if(arr[i][j]==1&&j==3)
					{
						label4:
							arr[i][j]=chooseRandom(30,39,1);
						if(visited[arr[i][j]+1]==false)
						visited[arr[i][j]+1]=true;
						else if(arr[i][j]<arr[i-1][j]&&visited[arr[i-1][j]+1]==true&&i!=0)
						arr[i][j]=chooseRandom(arr[i-1][j],39,1);
						else
						goto label4;
					}
					else if(arr[i][j]==1&&j==4)
					{
						label5:
							arr[i][j]=chooseRandom(40,49,1);
						if(visited[arr[i][j]+1]==false)
						visited[arr[i][j]+1]=true;
						else if(arr[i][j]<arr[i-1][j]&&visited[arr[i-1][j]+1]==true&&i!=0)
						arr[i][j]=chooseRandom(arr[i-1][j],49,1);
						else
						goto label5;
					}
					else if(arr[i][j]==1&&j==5)
					{
						label6:
							arr[i][j]=chooseRandom(50,59,1);
						if(visited[arr[i][j]+1]==false)
						visited[arr[i][j]+1]=true;
						else if(arr[i][j]<arr[i-1][j]&&visited[arr[i-1][j]+1]==true&&i!=0)
						arr[i][j]=chooseRandom(arr[i-1][j],59,1);
						else
						goto label6;
					}
					else if(arr[i][j]==1&&j==6)
					{
						label7:
							arr[i][j]=chooseRandom(60,69,1);
						if(visited[arr[i][j]+1]==false)
						visited[arr[i][j]+1]=true;
						else if(arr[i][j]<arr[i-1][j]&&visited[arr[i-1][j]+1]==true&&i!=0)
						arr[i][j]=chooseRandom(arr[i-1][j],69,1);
						else
						goto label7;
					}
					else if(arr[i][j]==1&&j==7)
					{
						label8:
							arr[i][j]=chooseRandom(70,79,1);
						if(visited[arr[i][j]+1]==false)
						visited[arr[i][j]+1]=true;
						else if(arr[i][j]<arr[i-1][j]&&visited[arr[i-1][j]+1]==true&&i!=0)
						arr[i][j]=chooseRandom(arr[i-1][j],79,1);
						else
						goto label8;
					}
					else if(arr[i][j]==1&&j==8)
					{
						label9:
							arr[i][j]=chooseRandom(80,90,1);
						if(visited[arr[i][j]+1]==false)
						visited[arr[i][j]+1]=true;
						else if(arr[i][j]<arr[i-1][j]&&visited[arr[i-1][j]+1]==true&&i!=0)
						arr[i][j]=chooseRandom(arr[i-1][j],90,1);
						else
						goto label9;
					}
			}
		}
		
		cout<<"\n\t\t-------------------------------------------------------------------------------\n";
		for(i=0;i<r;i++)	//display section
		{
			cout<<"\t\t|";
			cout<<"   ";
			for(j=0;j<c;j++)
			{
				if(arr[i][j]==0)
				cout<<"      |\t";
				else if(arr[i][j]==0&&j==0)
				cout<<"   |";

				else
				cout<<" "<<arr[i][j]<<"   |\t";
			}
			cout<<"\n\t\t-------------------------------------------------------------------------------\n";
		}
		cout<<"\n";
		s1.clear();
		v1.clear();
		s2.clear();
		v2.clear();
		s3.clear();
		v3.clear();
		count++;
		for(i=0;i<56;i++)
		cout<<"~~";
		cout<<"\n";
	}
	return 0;	
}
