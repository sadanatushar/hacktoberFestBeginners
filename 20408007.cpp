#include <iostream>
using namespace std;

int main() {
	int t,a,b;
	cin>>t;
	for(int i=0;i<t;i++)
	{
	    cin>>a;
	    cin>>b;
	    if(a>=b)
	    {
	     cout<<a;
	    cout<<" "<<a+b;
	    }
	    else
	    {
	        cout<<b;
	        cout<<" "<<a+b;
	    }
	    cout<<endl;
	}
	return 0;
}
