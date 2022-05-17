#include<bits/stdc++.h>
using namespace std;

const int n=1e3+10;
vector<int>adj[n];
vector<bool>visited(n,false);

bool is_cycle(int i,int par)
{
    visited[i]=true;
    bool is_loop=false;
    for(auto child:adj[i])
    {
        if(visited[child]==true && child==par) continue;
        if(visited[child])return true;

        is_loop|=is_cycle(child,i);
    }
    return is_loop;
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }
    bool loop=false;
    for(int i=0;i<n;i++)
    {
        if(visited[i]) continue;
        if(is_cycle(i,-1))
        {
            loop=true;
            break;
        }
    }
    if(loop==true)
    cout<<"Yes exists ";
    else
    cout<<"Not exists ";
    return 0;
}