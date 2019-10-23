#include <iostream>
using namespace std;

int main() 
{
	int t;
	char c;
	cin>>t;
	for(int i=0;i<t;i++)
	{
	    cin>>c;
	    if(c=='b'||c=='B')
	    {
	        cout<<"BattleShip"<<endl;
	    }
	    else if(c=='c'||c=='C')
	    {
	        cout<<"Cruiser"<<endl;
	    }
	    else if(c=='d'||c=='D')
	    {
	        cout<<"Destroyer"<<endl;
	    }
	    else
	    {
	        cout<<"Frigate"<<endl;
	    }
	  	}
	
	return 0;
}
