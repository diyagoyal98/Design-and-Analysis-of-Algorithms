#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;


void find_pair(vector<int>a,int n,int k)
{
    sort(a.begin(),a.end());
    int i=0,j=n-1;
    vector<int>ans;
    for(i=0,j=n-1;i<n && j>=0;)
    {
        if(a[i]+a[j]==k)
        {
            ans.push_back(a[i]);
            ans.push_back(a[j]);
            i++;
            j--;
        }
        if((a[i]+a[j])>k)
        j--;
        else
        i++;
    }
    cout<<"Pairs are ";
    for(i=0;i<ans.size();i++)
    cout<<ans[i]<<"  ";
}




int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>arr(n);
        for(int i=0;i<n;i++)
        cin>>arr[i];
        int key;
        cin>>key;
        find_pair(arr,n,key);
    }
    return 0;
}
