#include<iostream>
#include <fstream>
#include<cstring>
using namespace std;


class TeamInfo
{
	
	int PlayerNumber;
	char PlayerName[20];
	
	public:	
		void Display()
		{
			ifstream rf;
			TeamInfo rec;
			cout<<"\n\t\t Enter Team Name: ";
			char TeamName[20];
			cin>>TeamName;
			if(strcmp(TeamName,"Australia")==0||strcmp(TeamName,"australia")==0)
				rf.open("C:/Users/user/Downloads/Documents/PBL/PBL PROJECT/teams/australia.dat",ios::in|ios::binary);
			else if(strcmp(TeamName,"india")==0||strcmp(TeamName,"India")==0)
				rf.open("teams/india.dat",ios::in|ios::binary);
			else if(strcmp(TeamName,"England")==0||strcmp(TeamName,"england")==0)
				rf.open("teams/england.dat",ios::in|ios::binary);
			else if(strcmp(TeamName,"pakistan")==0||strcmp(TeamName,"Pakistan")==0)
				rf.open("teams/pakistan.dat",ios::in|ios::binary);
			else if(rf)
			{
				cout<<"\n\t\t FILE NOT FOUND";
				return ;
			}
			
			if(!rf.is_open())
				cerr<<"\n\n\t\tFile not open!";
			rf.read((char*)&rec,sizeof(rec));
			cout<<"\n\t\t Team "<<TeamName;
			while(!rf.eof())
			{
				cout<<"\n\t\t "<<rec.PlayerNumber<<"\t"<<rec.PlayerName;
				rf.read((char*)&rec,sizeof(rec));
			}
			
						
			rf.close();
			
			
		}
	
};
