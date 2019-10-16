#include<iostream>
int arr1[100000],arr2[100000],i,j,count1,count2,s,t,a,b,m,n;
using namespace std;
int countAppleAndOranges(int s,int t,int a,int b,int m,int n)
{
        for(int i =0;i<m;i++)
        {
            cin>>arr1[i];
        }
        
        for(int j=0;j<n;j++)
        {
            cin>>arr2[j];
        }
        for(i=0;i<m;i++)
        {
            if(arr1[i]+a>=s && arr1[i]+a <=t)
            {
                count1++;
            }
        }
        for(j=0;j<n;j++)
        {
            if(arr2[j]+b>=s && arr2[j]+b<=t)
            {
                count2++;
            }
        }
        return count1;
        return count2;
}
int main()
{
        cin>>s>>t;
        cin>>a>>b;
        cin>>m>>n;
        countAppleAndOranges(s,t,a,b,m,n);
        cout<<count1<<endl<<count2;
}
