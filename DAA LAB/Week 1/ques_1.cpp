//Week 1 lab question 1
#include<iostream>
using namespace std;

int search(int arr[],int n,int key)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(arr[i]==key)
        return i;
    }
    return i;
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
        int ans=search(arr,n,key);
        if(ans==n)
        cout<<"Not present"<<" "<<ans;
        else
        cout<<"Present"<<" "<<ans+1;
    }
    return 0;
}