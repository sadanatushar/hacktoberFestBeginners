#include <bits/stdc++.h>
using namespace std;

int main()
 {
    int n,c1=0,c2=0,c3=0;
    cin >> n;
    
 vector<int> arr(n);
    
 for(int arr_i = 0;arr_i < n;arr_i++)
 {
       cin >> arr[arr_i];
        
 if(arr[arr_i]>0)
        {
         c1++;
 }    
        if(arr[arr_i]<0)
        {
         c2++;
     }
        if(arr[arr_i]==0)
        {
         c3++;
        }
        cout<<setprecision(6)<<(float)c1/n<<endl;
        cout<<setprecision(6)<<(float)c2/n<<endl;
        cout<<setprecision(6)<<(float)c3/n<<endl;
    return 0;
}
