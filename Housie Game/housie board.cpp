/*
	Author:Gaurav Jain
	Created on:May 2020
*/
#include <bits/stdc++.h>
#include <stdlib.h>
#include <Windows.h>
#define pb push_back
#define ll long long 
using namespace std;
HANDLE out=GetStdHandle(STD_OUTPUT_HANDLE);


vector <ll int>v;//this is used for searching purpose for the 'q' query
int chooseRandom(int s,int e,int count)
{
	int i; 
    for (i = 0; i < count; i++) 
	{ 
        int num = (rand() % (e - s + 1)) + s; 
        return num; 
    } 
}

void fontsize(int a, int b)
{  
  PCONSOLE_FONT_INFOEX lpConsoleCurrentFontEx = new CONSOLE_FONT_INFOEX();  
  lpConsoleCurrentFontEx->cbSize = sizeof(CONSOLE_FONT_INFOEX);  
  GetCurrentConsoleFontEx(out, 0, lpConsoleCurrentFontEx);  
  lpConsoleCurrentFontEx->dwFontSize.X = a;  
  lpConsoleCurrentFontEx->dwFontSize.Y = b;  
  SetCurrentConsoleFontEx(out, 0, lpConsoleCurrentFontEx);  
} 
  
int main()
{
	system("COLOR 56");
	fontsize(20,25);
	ll int arr[9][10]={1,2,3,4,5,6,7,8,9,10,
11,12,13,14,15,16,17,18,19,20,
21,22,23,24,25,26,27,28,29,30,
31,32,33,34,35,36,37,38,39,40,
41,42,43,44,45,46,47,48,49,50,
51,52,53,54,55,56,57,58,59,60,
61,62,63,64,65,66,67,68,69,70,
71,72,73,74,75,76,77,78,79,80,
81,82,83,84,85,86,87,88,89,90
};
	ll int num,flag;
	char str;
    string option;
    srand(time(0));
    ll int i,j,i1,j1,count=0;
    bool visited[9][10];
    for(i=0;i<9;i++)
    {
        for(j=0;j<10;j++)
        visited[i][j]=false;
    }
    cout<<"\t\t\t\t\t\tHOUSIE BOARD\n\n";
    cout<<"Choose y for proceeding,n for terminating and q for searching a value\n";
    while(count!=90)
    {
    	cout<<"choose an option y/n/q"<<endl;
        cin>>option;
    	if(option.length()==1)
    	{
			
	        if(option=="y")
	        {
	        	label1:
	        	{
						
		        	label://for exception handling
		        	{
				
			            i1=chooseRandom(0,8,1);
			            j1=chooseRandom(0,9,1);
			            if(arr[i1][j1]==0||arr[i1][j1]>90)
			            goto label;
		        	}
		        	if(visited[i1][j1]==false)
		        	{
						visited[i1][j1]=true;
		        	}
		        	v.pb(arr[i1][j1]);
					count++;
		            cout<<"Chosen number is  "<<arr[i1][j1]<<"\n";
		            arr[i1][j1]=0;
		            cout<<"\n\t--------------------------------------------------------------------------------------\n";
					for(i=0;i<9;i++)
		            {
		            	cout<<"\t|";
						cout<<"\t";
		            	for(j=0;j<10;j++)
		            	{
		            		if(arr[i][j]==0)
		            		cout<<"     |\t";
		            		else
							cout<<arr[i][j]<<"   |\t"; 
						}
						cout<<"\n\t--------------------------------------------------------------------------------------\n";
					
					}
		        }
			}
	        else if(option=="n")
	        {
	            cout<<"terminating"<<endl;
	            break;
	        }
	        else if(option=="q")
	        {
	        	label3:
	        	{
				
		        	cout<<"what are you searching?\n";
		        	cin>>num;
		        	for(i=0;i<v.size();i++)
		        	{
		        		if(num==v[i])
		        		{
			        		flag=1;
			        		break;
		        		}
		        		else
		        		{
		        			flag=0;
		        		}
					}
					if(flag==1)
					cout<<"This number is done\n";
					else
					cout<<"This number is not done\n";
				}
			}
	        if(count==90)
	        {
	        	cout<<"Board is over\n";
	        	break;
			}
		}
		else //multiple chars
		{
			//cout<<"Only one character will be considered\n";
			str=option[0];
			if(str=='n')
			{			
				cout<<"terminated\n";
				break;
			}
			if(str=='y')
			goto label1;
			if(str=='q')
			goto label3;
		}
    }
    
	return 0;
}

