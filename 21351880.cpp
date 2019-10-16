#include <iostream>
#include<algorithm>
using namespace std;

int main() 
{
	int t,n,a[5000],b[3000];
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	    }
	    sort(a,a+n);
	    for(int i=0;i<n-1;i++)
	    {
	        b[i]=a[i+1]-a[i];
	        
	    }
	    sort(b,b+n-1);
	    cout<<b[0]<<endl;
	}
	return 0;
}
