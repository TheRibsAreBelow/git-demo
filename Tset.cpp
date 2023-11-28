#include<iostream>
#include<vector>
#include<set>
using namespace std;
const int N=2e5+1;
int n,m,Son,cnt[N],col[N],siz[N],son[N],sum,res,L[N],R[N],dfn,id[N];
vector<int>G[N];
multiset<int>st;
void dfs1(int x,int f)
{
    L[x]=++dfn;
    id[dfn]=x;
    siz[x]=1;
    for(int y:G[x])
    {
        if(y==f)
            continue;
        dfs1(y,x);
        siz[x]+=siz[y];
        if(!son[x]||siz[y]>siz[son[x]])
            son[x]=y;
    }
    R[x]=dfn;
    return;
}
void add(int x)
{
    if(cnt[col[x]])
        st.erase(st.find(cnt[col[x]]));
    cnt[col[x]]++;
    st.insert(cnt[col[x]]);
    return;
}
void del(int x)
{
    st.erase(st.find(cnt[col[x]]));
    cnt[col[x]]--;
    if(cnt[col[x]])
        st.insert(cnt[col[x]]);
    return;
}
void dfs2(int x,int f,bool keep)
{
    for(int y:G[x])
    {
        if(y==f||y==son[x])
            continue;
        dfs2(y,x,false);
    }
    if(son[x])
        dfs2(son[x],x,true);
    for(int y:G[x])
    {
        if(y==f||y==son[x])
            continue;
        for(int i=L[y];i<=R[y];i++)
            add(id[i]);
    }
    add(x);
    int mi=*st.begin(),ma=*prev(st.end());
    if(mi==ma)
        res++;
    if(!keep)
        for(int i=L[x];i<=R[x];i++)
            del(id[i]);
    return;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>col[i]>>x;
        G[x].push_back(i);
        G[i].push_back(x);
    }
    dfs1(1,0);
    dfs2(1,0,0);
    cout<<res;
    return 0;
}