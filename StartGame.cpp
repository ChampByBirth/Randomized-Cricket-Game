#include<iostream>
#include<fstream>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<windows.h>
using namespace std;

class StartGame
{
	private:
		char team1[20],team2[20];
		int team2select, tossValue, totalOvers, totalRuns, wicket, runScored, currBall, currOver;
		int team1score,team2score, inning1Score, inning2Score,flag;
	
	public:
		
		void start()
		{
			cout<<"\n\t\t Begin Match!";
			cout<<"\n\t\t Select teams : ";
			cout<<"\n\t\t 1. Australia";
			cout<<"\n\t\t 2. India";
			cout<<"\n\t\t 3. Pakistan";
			cout<<"\n\t\t 4. England";
			t1:cout<<"\n\n\t\t Enter Team 1: ";
			cin>>team1;
			
			if(strcmp(team1,"Australia")!=0 && strcmp(team1,"India")!=0 && strcmp(team1,"Pakistan")!=0 && strcmp(team1,"England")!=0)
			{
				cout<<"\n\n\t\t Not a valid team!";
				goto t1;
			}
			
			t2:cout<<"\n\n\t\t Enter Team 2: ";
			cin>>team2;

			if((strcmp(team2,"Australia")!=0 && strcmp(team2,"India")!=0 && strcmp(team2,"Pakistan")!=0 && strcmp(team2,"England")!=0) || strcmp(team2,team1)==0)
			{
				cout<<"\n\n\t\t Not a valid team!";
				goto t2;
			}

			//select number of overs
			numOvers();
			
			cout<<"\n\n\t\t Teams Playing : "<<team1<<" vs "<<team2;
			Sleep(200);
			//calls toss method
			toss();


			if(tossValue==0)
			{
				//innings 1
				team1score = innings(1);
				cout<<"\n\n\t\t Total Score: "<<team1score<<"/"<<wicket;
				
				//innings 2
				team2score = innings(2);
				cout<<"\n\n\t\t Total Score: "<<team2score<<"/"<<wicket;
			}
			else if(tossValue==1)
			{
				//innings 1
				team2score = innings(1);
				cout<<"\n\n\t\t Total Score: "<<team2score<<"/"<<wicket;
				
				//innings 2
				team1score = innings(2); 			
				cout<<"\n\n\t\t Total Score: "<<team1score<<"/"<<wicket;
			}
			cout<<"\n\n\t\t *************";		
			whoWon();
			storeDetails();
			
		}
		
		void toss()
		{
			srand(time(NULL));
			tossValue = rand()%2;
			cout<<"\n\n\t\t **************************************************";
			
			//to select the toss winning team
			if(tossValue==0)
				cout<<"\n\t\t Team "<<team1<<" won the toss and chose to bat first";
			else
				cout<<"\n\t\t Team "<<team2<<" won the toss and chose to bat first";
			cout<<"\n\n\t\t **************************************************";
			Sleep(500);	
		}
		
		void numOvers()
		{
			//To select number of overs
			cout<<"\n\n\t\t Enter number of overs per innings (5 or 10): ";
			cin>>totalOvers;
		}
		
		int innings(int inn)
		{	
			currOver = 0;
			wicket=0;
			
			totalRuns=0;
			
			cout<<"\n\n\t\t Innings: "<<inn;
			
			Sleep(800);
			
			while(currOver<totalOvers)
			{
				
				runScored=0;
				currBall=0;
				
				cout<<"\n\t\t Over "<<(currOver+1)<<" : ";
				Sleep(100);
				while(currBall<6)
				{
					if(wicket==10)
						goto x;
					
					runScored = rand()%10;
					if(runScored <= 6)
					{
						totalRuns = totalRuns + runScored;
						cout<<runScored<<", ";
						currBall++;
					}
					else if(runScored==7)
					{
						totalRuns++;
						cout<<"nb, ";
					}
					else if(runScored==8)
					{
						totalRuns++;
						cout<<"wide, ";
					}
					else if(runScored==9)
					{
						wicket++;
						cout<<"W, ";
						currBall++;
					}
					
					Sleep(200);
					if(totalRuns>inning1Score)
						goto x;
				}
				currOver++;
				Sleep(800);
			}
			
			x:if(inn==1)
				inning1Score = totalRuns;
			else if(inn=2)
				inning2Score = totalRuns;
			
			
			return totalRuns;
		}
		
		void whoWon()
		{
			//to decide who won
			Sleep(800);
			if(team1score>team2score)
			{
				flag=0;
				cout<<"\n\n\t\t Team "<<team1<<" won!";
			}
			else if(team1score<team2score)
			{ 
				flag=1;
				cout<<"\n\n\t\t Team "<<team2<<" won!";
			}
			else
			{
				flag=2;
				cout<<"\n\n\t\t It is a tie!";			
			}
		}
		
		void storeDetails()
		{
			ofstream wfile;
			wfile.open("LastMatchDetails.dat",ios::out|ios::binary);
			wfile<<"\n\n\t\t***************";
			wfile<<"\n\t\t Match Details";
			wfile<<"\n\n\t\t Team "<<team1<<" vs "<<"Team "<<team2;
			if(tossValue==0)
				wfile<<"\n\n\t\t Toss: "<<team1<<" won and chose to bat first!";
			else
				wfile<<"\n\n\t\t Toss: "<<team2<<" won and chose to bat first!";
			wfile<<"\n\n\t\t Innings 1 : ";
			wfile<<"\n\t\t Total Runs: "<<inning1Score;
			wfile<<"\n\n\t\t Innings 2: ";
			wfile<<"\n\t\t Total Runs: "<<inning2Score;
			
			switch(flag)
			{
				case 0: wfile<<"\n\n\t\t Team "<<team1<<" won!";
						break;
				case 1: wfile<<"\n\n\t\t Team "<<team2<<" won!";
						break;
				case 2: wfile<<"\n\n\t\t The match was a tie";
						break;
								
			}
			
			wfile.close();
		}
		
};


