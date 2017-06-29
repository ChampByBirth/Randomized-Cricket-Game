#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class LastMatch
{

	char *buffer;
	int buff_size;
	
	public:
	void display()
	{
		ifstream rfile;
		rfile.open("LastMatchDetails.dat",ios::in|ios::ate);
		//rfile.read((char*)&rec,sizeof(rec));
		
		buff_size= rfile.tellg();
		rfile.seekg(0,ios::beg);
		
		if(rfile.is_open())
		{
			rfile.read(buffer,buff_size);
			cout<<buffer;
		}			
						
		rfile.close();
	}	
};
