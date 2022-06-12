#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int>arr;
    for(int i=0;i<n;i++)
    {
        int p;
        cin>>p;
        arr.push_back(p);
    }
    int count=1,m_count=INT_MIN;
    sort(arr.begin(),arr.end());

    for(int i=0,j=i+1;i<n-1 && j<n;i++,j+=i)
    {
        if(arr[i]==arr[i+1])
        {
            count+=1;
        }
        else
        {
            if(count>m_count)
            m_count=count;
            count=1;
        }
    }
    //cout<<endl<<count;
    if(count>n/2)
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }
    if(n%2!=0)
    {
        cout<<arr[n/2];
    }
    else
    {
        int p;
        cout<<(arr[((n/2)-1)]+arr[n/2])/2;
    }


}