#include<bits/stdc++.h>
using namespace std;

const int n=1e3+10;
vector<pair<int,int>>adj[n];

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int v1,v2,wt;
        cin>>v1>>v2>>wt;
        adj[v1].push_back({v2,wt});
        adj[v2].push_back({v1,wt});
    }

    int key[n];
    bool mst[n];
    int parent[n];
    for(int i=0;i<n;i++)
    {
        key[i]=INT_MAX;
        mst[i]=false;
        parent[i]=-1;
    }
    
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    key[0]=0;
    pq.push({0,0});
    for(int count=0;count<n-1;count++)
    {
        int u=pq.top().second;
        pq.pop();
        mst[u]=true;
        for(auto child : adj[u])
        {
            int v=child.first;
            int weight=child.second;
            if(mst[v]==false && weight<key[v])
            {
                parent[v]=u;
                pq.push({key[v],v});
                key[v]=weight;
            }
        }
    }

    for(int i=1;i<n;i++)
    {
        cout<<parent[i]<<"  ";
    }
    int weight=0;


    for(int i=1;i<n;i++)
    {
        for(auto it :adj[i])
        {
            if(parent[i]==it.first)
            {
                weight+=it.second;
            }
        }
    }
    cout<<endl<<"Minimum weight "<<weight;
    return 0;
}