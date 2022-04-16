#include<iostream>
using namespace std;
#include<bits/stdc++.h>
#include<vector>

void find_common(int a[],int m,int b[],int n)
{
    int i,j;
    vector<int>ans;
    for(i=0,j=0;i<m &&j<n;)
    {
        if(a[i]==b[j])
        {
            ans.push_back(a[i]);
            i++;
            j++;
        }
        else if(a[i]>b[j])
        j++;
        else
        i++;
    }
    cout<<"Size of ans is "<<ans.size()<<endl;
    for(i=0;i<ans.size();i++)
    cout<<ans[i]<<"  ";
}

int main()
{
    int m,n;
    cin>>m;
    int a[m];
    for(int i=0;i<m;i++)
    cin>>a[i];
    cin>>n;
    int b[n];
    for(int i=0;i<n;i++)
    cin>>b[i];
    find_common(a,m,b,n);

    return 0;
}