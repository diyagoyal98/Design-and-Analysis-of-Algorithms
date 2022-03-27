#include<iostream>
using namespace std;

int first_occurance(int arr[],int l,int r,int key,int n)
{
    if(r>=l)
    {
        int mid=(l+r)/2;
        if((mid==0 || key>arr[mid-1] ) && arr[mid]==key)
        return mid;
        else if(arr[mid]<key)
        return first_occurance(arr,mid+1,r,key,n);
        else
        return first_occurance(arr,l,mid-1,key,n);
    }    
    return -1;
}
int last_occurance(int arr[],int l,int r,int key,int n)
{
    if(r>=l)
    {
        int mid=(l+r)/2;
        if((mid==n-1 || key<arr[mid+1] ) && arr[mid]==key)
        return mid;
        else if(key<arr[mid])
        return last_occurance(arr,l,mid-1,key,n);
        else
        return last_occurance(arr,mid+1,r,key,n);
    }
    return -1;
}
int dublicate_count(int arr[],int key,int n)
{
    
    int i,j;
    i=first_occurance(arr,0,n-1,key,n);
    if(i==-1)
    return -1;
    j=last_occurance(arr,i,n-1,key,n);
    return j-i+1;
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
        int ans=dublicate_count(arr,key,n);
        cout<<ans;
    }
    return 0;
}