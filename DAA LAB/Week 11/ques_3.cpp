#include<bits/stdc++.h>
using namespace std;

bool is_subset(vector<int>a,int n,int sum)
{
    if(sum==0)
    return true;
    if(n==0 && sum!=0)
    return false;

    if(a[n-1]>sum)
    return is_subset(a,n-1,sum);

    return is_subset(a,n-1,sum) || is_subset(a,n-1,sum-a[n-1]);
}

bool check(vector<int>a,int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=a[i];
    }
    if(sum%2!=0)
    return false;
    
    return is_subset(a,n,sum/2);
}

int main()
{
    int n;
    cin>>n;
    vector<int>arr;
    for(int i=0;i<n;i++)
    {
        int m;
        cin>>m;
        arr.push_back(m);
    }    

    if(check(arr,n))
    cout<<"Yes";
    else
    cout<<"No";
    return 0;
}
