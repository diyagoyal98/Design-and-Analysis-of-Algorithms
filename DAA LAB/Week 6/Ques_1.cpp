#include<iostream>
using namespace std;
const int n=1e3+10;
int adj[n][n];
bool status[n];

int dfs(int s,int e)
{
    if(s==e)
    return 1;
    status[s]=true;
    for(int child :adj[s])
    {
        if(status[child]) continue;  
        if(dfs(child,e))
        return 1;
    }
    
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>adj[i][j]; //input of adjacency matrix 
        }
    }

    int start,end;
    cin>>start>>end;

    /*cout<<"Graph ";
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            cout<<i<<"--->"<<j<<endl;
        }
    }*/
    int a=dfs(start,end);
    if(a==1)
    cout<<"Yes Path Exists "<<endl;
    else
    cout<<"Not exists ";
    return 0;

}

//By adjacency list 

#include<bits/stdc++.h>
using namespace std;

bool find_path_dfs(int src,int des,vector<int>adj[],vector<int>&visited)
{
    if(src==des)
    {
        return true;
    }    
    visited[src]=1;
    bool ans;
    for(auto child :adj[src])
    {
        
        if(visited[child]!=1)
        {
            ans|=find_path_dfs(child,des,adj,visited);
        }
    }
    visited[src]=0;
    return ans;
}




int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>adj[n];
    vector<int>visited(n,0);
    for(int i=0;i<m;i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        adj[v1].push_back(v2);
        //adj[v2].push_back(v1);
    }

    int src,des;
    cin>>src>>des;

    if(find_path_dfs(src,des,adj,visited))
    cout<<"Yes path exists ";
    else
    cout<<"No path doesn't exists ";

    return 0;

}



