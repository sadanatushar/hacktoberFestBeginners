#include <iostream>
#include <math.h>
#include <typeinfo>
using namespace std;

int getValueToAdd(int num){
    while(num / 10 != 0){
        num = num/10;
    }    
    return num;
}

int otherMaxExists(int num){
    int lastDigit = getValueToAdd(num);
    int Newnum = num + lastDigit;
    if(lastDigit != getValueToAdd(Newnum)){
        return Newnum;
    }else{
        return 0;
    }
}

int getTheResult(int k){
    int TotalSteps=2;
    int largestValue = 9;
    if(k == 2){
        return largestValue;
    }else if(k==3){
        return ++largestValue;
    }else{
        largestValue = largestValue + 1;
        TotalSteps++;
        while(true){
            if(TotalSteps == k){
                int MaxNumber = otherMaxExists(largestValue);
                if(MaxNumber != 0){
                    return MaxNumber;
                }
                largestValue = largestValue - getValueToAdd(largestValue);
                return largestValue;
            }
            largestValue = largestValue + getValueToAdd(largestValue);
            TotalSteps++; 
        }
    }
}
void check(int num){
    int TotalSteps=1;
    cout<<"Num :"<<num<<"Steps :"<<TotalSteps<<endl;
    TotalSteps++;
    while(num/10 != 0){
        num = num - getValueToAdd(num);
        cout<<"Num :"<<num<<"Steps :"<<TotalSteps<<endl;
        TotalSteps++;
    }
    cout<<"Num :"<<0<<"Steps :"<<TotalSteps<<endl;
    cout<<"TotalSteps"<<TotalSteps+1<<endl;
}
int main() {
	
    int testcases;
    cin>>testcases;
    
    for(int i = 0 ; i < testcases ;i++){
        int k;
        cin>>k;
        getTheResult(k);
        cout<<getTheResult(k)<<endl;
    }
    
	return 0;
}
