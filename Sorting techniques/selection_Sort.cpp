#include<iostream>
#include<vector>
// #include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int>arr;
    int x;
    int cnt=0;
    while(cnt < 6){
        cin >> x;
        arr.push_back(x);
        cnt++;
    }

    //  selection sort
    int n=arr.size();
    for(int i=0;i<n;i++){
        int it=i;
        for(int j=i+1;j<n;j++){
            if(arr[j] < arr[it]){
                it = j;
            }
        }
        swap(arr[i], arr[it]);
    }
    for(int i =0;i<n;i++){
        cout << arr[i]<<" ";
    }
}

