//
// Created by 舰长 on 2023/11/27.
//
#include "bits/stdc++.h"

using namespace std;

#define L 8
#define N 100

int main(){
    int propose[L + 1];
    int vote[L+1];
    int hash[L+1];
    int i,j;
    int count,n,majority;
    memset(propose, 0, sizeof(propose));
    memset(vote,0,sizeof(vote));
    propose[L - 2]=N;
    for(i=L-3;i>0;i--)
    {
//        majority=(L-i)/2+1;
        if((L-i)%2==0){
            majority= (L - i) / 2;
        }
        else{
            majority= (L - i) / 2 + 1;
        }
        memset(hash,0,sizeof(hash));
        count=0;
        n=0;
        for(j=i;j<=L;j++)
        {
            if(j==i){
                vote[j]=1;
            }
            else if(j==(i+1)){
                vote[j]=0;
            }
            else if(propose[j] == 0 && count < majority){
                vote[j]=1;
                hash[j]++;
                count++;
            }
        }

        for(j=i+2;j<=L;j++){
            if(!hash[j]){
                if(count < majority && propose[j] < 2){
                    vote[j]=1;
                    count++;
                }
                else{
                    vote[j]=0;
                }
            }
        }
        propose[i + 1]=0;
        for(j=i+2;j<=L;j++){
            if(vote[j]==1){
                propose[j]++;
            }
            else{
                propose[j]=0;
            }
        }
        for(int z:propose){
            n+=z;
        }
        propose[i]= N - n;
    }
    for(i=1;i<=L;i++){
        cout << propose[i] << " " << endl;
    }
    return 0;
}