//Week 1 lab question 2
#include<iostream>
using namespace std;

void b_search(int arr[],int l,int r,int key)
{
    int flag=1;
    int count=0;
    while(l<=r)
    {

        int mid=(l+r)/2;
        count++;
        if(arr[mid]==key)
        {
            flag=0;
            cout<<"Present "<<" "<<count<<endl;
        }
        if(arr[mid]<key)
        {
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }    
    }
    if(flag==1)
    {
        cout<<"Not present "<<" "<<count<<endl;
    }
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
        int key;
        cin>>key;
        b_search(arr,0,n-1,key);
    }
    return 0;
}