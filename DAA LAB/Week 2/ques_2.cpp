#include<iostream>
using namespace std;

void find_triplets(int arr[],int n)
{
    int i,l,r;
    for(i=n-1;i>=2;i--)
    {
        l=0,r=i-1;
        while(l<r)
        {
            if((arr[l]+arr[r])==arr[i])
            {
                cout<<l+1<<" "<<r+1<<" "<<i+1<<endl;
                l++;
                r--;
                return;
            }    
            else if((arr[l]+arr[r])<arr[i])
            l++;
            else
            r--;
        }
    }
    cout<<"Not present";
    
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        cin>>arr[i];
        find_triplets(arr,n);
    }    
    return 0;
}