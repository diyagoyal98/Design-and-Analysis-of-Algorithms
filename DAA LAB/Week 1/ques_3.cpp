//Week 1 lab question 3
#include<iostream>
#include<math.h>
using namespace std;

void jump_search(int arr[],int n,int key)
{
    int low=0,count=0,c=0;
    int jump=sqrt(n);
    for(int i=0;i<n;i+=jump)
    {
        count++;
        if(arr[i]==key)
        {
            cout<<"Present "<<count;
            return ;
        }
        if(arr[i]<key)
        low=i;
        if(arr[i]>key)
        break;
    }
    for(int i=low;i<n;i++)
    {
        c++;
            if(arr[i]==key)
            {
                cout<<"Present "<<c;
                return ;
            }
    }    
    cout<<"Not present "<<count;

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
        jump_search(arr,n,key);
    }
}