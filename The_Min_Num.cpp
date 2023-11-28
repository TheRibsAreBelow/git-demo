
#include "bits/stdc++.h"

using namespace std;

int main(){
    string input;
    vector<int> A;
    cin>>input;
    int count=0;
    for (char digitChar : input) {
        if (isdigit(digitChar)) {
            // 将字符转换为数字并添加到数组中
            A.push_back(digitChar - '0');
        }
    }
//    for(int s=0;s<A.size();s++){
//        cout<<"A."<<s<<"="<<A[s]<<endl;
//    }


    for(int i=0;i<A.size();i++){
        for(int j=i+1;j<A.size();j++){
            if(A[i]>A[j]){
                count++;
            }
            else if(A[i]==A[j]){
                for(int a=i+1,b=j-1;a<b;a++,b--){
                    if(A[a]>A[b]){
                        count++;
                        break;
                    }
                    else if (A[a]<A[b]){
                        break;
                    }
                }
            }
        }
    }
    cout <<count;
    return 0;
}