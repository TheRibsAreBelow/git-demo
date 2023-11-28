//
// Created by 舰长 on 2023/11/10.
//
#include "bits/stdc++.h"

using namespace std;

class T{
public:
    int p=0;
    vector<int> sun;
    int c=0;
};

int main(){
     int n;
     int i,j;
     int c,p;
     cin>>n;
     T t[n+1];
     int *hash=new int[n+1];
     for(i=0;i<n+1;i++){
         hash[i]=0;
     }
     for(i=1;i<=n;i++){
         cin>>c>>p;
         t[i].c=c;
        if(i==1){
            t[i].p=1;
        }
        else
        t[i].p=p;
        t[p].sun.push_back(i);
        hash[c]++;
     }
      
    return 0;
}