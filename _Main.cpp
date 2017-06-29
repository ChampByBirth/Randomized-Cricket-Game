#include<iostream>
#include"StartGame.cpp"
#include"TeamInfo.cpp"
#include"LastMatch.cpp"
using namespace std;

int main()
{
	int choice;
	char yn;
	StartGame sg;
	LastMatch lm;
	TeamInfo ti;
	
	cout<<"\n\n\t\t|------------------------|";
	cout<<"\n\n\t\t|	CricBuzz!   	 |";
	cout<<"\n\n\t\t|------------------------|";
	
	cout<<"\n\n\t\t  Welcome to the ScoreBoard!  ";
	cout<<"\n\n\t\t******************************";
		
	do
	{
		cout<<"\n\n\t\t 1. Watch Live!";
		cout<<"\n\t\t 2. Last Match Details";
		cout<<"\n\t\t 3. Team Info";
		cout<<"\n\t\t Enter your choice: ";
		cin>>choice;
		
		switch(choice)
		{
			case 1:
				sg.start();
				break;
			case 2:
				//TODO: Program to display last match details
				lm.display();
				break;
			case 3:
				ti.Display();
				break;
		}
		
		cout<<"\n\n\t\t Continue?(Y/N)";
		cin>>yn;
		
	}while(yn=='Y'||yn=='y');
}
