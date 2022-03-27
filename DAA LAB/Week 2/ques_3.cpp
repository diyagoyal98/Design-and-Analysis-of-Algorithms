#include<iostream>
using namespace std;

void find_difference(int arr[],int n,int key)
{
    int l=0,r=0;
    int count=0;
    while(r<n && l<n)
    {
        if(arr[r]-arr[l]==key)
        {
            count++;
            l++;
            r++;
        }    
        else if(arr[r]-arr[l]>key)
        l++;
        else
        r++;
    }
    cout<<count;
}
void sort(int *p,int n)
{
    int i,j,min_idx;
    for(i=0;i<n-1;i++)
    {
        min_idx=i;
        for(j=i+1;j<n;j++)
        {
            if(*(p+j)<*(p+min_idx))
            min_idx=j;
        }
        int tmp;
        tmp=*(p+min_idx);
        *(p+min_idx)=*(p+i);
        *(p+i)=tmp;
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
        sort(arr,n);
        find_difference(arr,n,key);
    }
    return 0;
}