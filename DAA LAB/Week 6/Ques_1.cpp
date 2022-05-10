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