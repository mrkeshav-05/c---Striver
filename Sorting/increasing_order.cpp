#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <cmath>
using namespace std;
int main(){
    int n;
    cout<<"enter size of array";
    cin>>n;

    cout<<"enter all elements of array";
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    // int mini=0;
    for(int i=0; i<n-1; i++){
        int mini=i;
        for(int j=i+1; j<n; j++){
            if(arr[mini]>arr[j]){
                mini=j;
            }
        }
        int temp=mini;
        arr[mini]=arr[i];
        arr[i]=temp;
    }

    cout<<"After sorting"<<endl;
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

return 0;
}

