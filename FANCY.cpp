#include<iostream>
#include<string>

using namespace std;

int main() {
    int t, temp;
    string s;
    cin>>t;
    t++;
    while(t--) {
        temp = 0;
        getline(cin, s);
        for(int i=0; i<s.length(); i++) {
            if(s[i] == 'N' || s[i] == 'n') {
                if(s[i+1] == 'O' || s[i+1] == 'o') {
                    if(s[i+2] == 'T' || s[i+2] == 't') {
                        if((i == 0 || s[i-1] == ' ') && (s[i+3] == ' ' || s[i+3] == '\0')) {
                            temp = 1;
                            goto end;
                        }
                    }
                }
            }   
            else    cout<<"regularly fancy";
        }
        end: int x;
    }
}
