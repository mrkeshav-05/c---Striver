#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <cmath>
using namespace std;

int smallervalue(int array[], int n){
       int min=MAX_INPUT;
       int index;
    for(int i = 0; i < n;i++){
        if(array[i]<min){
            min=array[i];
            index=i;
        }
    }

    return min,index;
}
int main(){
    int n;
    cout<<"enter size of array: ";
    cin >> n;

    cout<<"enter all elements of array: ";
    int array[n];
    for(int i = 0; i < n;i++){
        cin>>array[i];
    }

    cout<<"smallest value is: "<<smallervalue(array, n)<<endl;
    cout<<index;


return 0;
}