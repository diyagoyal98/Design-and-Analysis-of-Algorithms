#include<bits/stdc++.h>
using namespace std;

const int n=1e3+!0;
vector<int>adj[n];
vector<int>colour(n,-1);

bool bipartite(int i,int n)
{
    queue<int>q;
    q.push(i);
    colour[i]=1;
    while(!q.empty())
    {
        int node =q.front();
        q.pop();
        for(auto child : adj[node])
        {
            if(colour[child]==-1)
            {
                colour[child]=1-colour[node];
                q.push(child);
            }
            else if(colour[child]==colour[node])
            return false;
        }
    }
    return true;

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
    for(int i=0;i<n;i++)
    {
        if(colour[i]==-1)
        {
            if(!bipartite(i,n))
            {
                cout<<"Not bipartite ";
                exit(0);
            }
        }
    }
    cout<<"Yes bipartite ";
    return 0;
}