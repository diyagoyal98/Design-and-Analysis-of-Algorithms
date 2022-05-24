//Bellman ford


#include<bits/stdc++.h>
using namespace std;
struct node
{
    int u;
    int v;
    int wt;
    node(int first,int second,int weight)
    {
        u=first;
        v=second;
        wt=weight;
    }
};



int main()
{
    int n,m;
    cin>>n>>m;
    vector<node>adj;
    for(int i=0;i<m;i++)
    {
        int u,v,wt;
        cin>>u>>v>>wt;
        adj.push_back({u,v,wt});
    }
    int src;
    cin>>src;

    vector<int>distance(n,1e3);
    distance[src]=0;

    for(int i=1;i<=n-1;i++)
    {
        for(auto it:adj)
        {
            if(distance[it.u]+it.wt<distance[it.v])
            {
                distance[it.v]=distance[it.u]+it.wt;
            }
        }
    }
    int cycle=0;
    for(auto it:adj)
    {
        if(distance[it.u]+it.wt<distance[it.v])
        {
            cycle=1;
            cout<<"Negative cycle exists ";
            exit(0);
        }
    }
    if(!cycle)
    {
        for(int i=0;i<n;i++)
        {
            cout<<i<<"  "<<distance[i]<<endl;
        }
    }

}
