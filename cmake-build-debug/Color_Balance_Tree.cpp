//
// Created by 舰长 on 2023/11/22.
//
#include "bits/stdc++.h"

using namespace std;



class T{
public:
    int pare;
    vector<int> son;
    int color;
//    void pr(int n){
//        cout<<"T["<<n<<"] pare is "<<pare<<" and color is "<<color<<endl;
//    }
    void in(){
        son.push_back(1);
    }
};

vector<int> hashs(T * tree,vector<int> hash,int zu){
    if(empty(tree[zu].son)){
        return hash;
    }
    else{
        hash[tree[zu].color]++;
        for(int i : tree[zu].son){
            hashs(tree,hash,i);
        }
    }
}

int main(){
    int n,i,j;
    int s=0;
    cin>>n;
    int count=0;
    T *tree=(T*)malloc((n+1)*sizeof (T));
    vector<int> hash;
//    init hash
    hash.push_back(0);
    for(i=1;i<=n;i++){
        hash.push_back(0);
    }
//    init tree
    for(i=1;i<=n;i++){
        int a,b;
        int cb;
        cb=i;
        cin>>a>>b;
        tree[i].color=a;
        tree[i].pare=b;
//        tree[b].in();
//        hash[a]++;
    }

    for(i=1;i<=n;i++){
        s=0;
        for(j=0;j<=n;j++){
            hash[j]=0;
        }
        hash= hashs(tree,hash,i);
        int max= *max_element(hash.begin()+1,hash.end());
        int min=*min_element(hash.begin()+1,hash.end());
        if( min==0||min==max) {
            for (int z: hash)
            {
                if(z!=max||z!=min){
                    s=1;
                    break;
                }
            }
            if(s==0)
                count++;
        }
    }
    cout<<count;

//    for(i=1;i<=n;i++){
//        tree[i].pr(i);
//    }
//    for(i=0;i<=n;i++){
//        cout<<"hash["<<i<<"] is "<<hash[i]<<endl;
//    }
    return 0;
}