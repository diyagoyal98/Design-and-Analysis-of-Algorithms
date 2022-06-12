#include<bits/stdc++.h>
using namespace std;

int count(vector<int>a,int n,int s)
{
    if(s==0)
    return 1;
    if(s<0)
    return 0;
    if(n<=0 && s>=1)
    return 0;

    return count(a,n-1,s)+count(a,n,s-a[n-1]);
}

int main()
{
    int n;
    cin>>n;
    vector<int>value;
    for(int i=0;i<n;i++)
    {
        int m;
        cin>>m;
        value.push_back(m);
    }
    int sum;
    cin>>sum;
    cout<<count(value,n,sum);
}