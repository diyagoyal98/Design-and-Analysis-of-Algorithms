//Bubble sort
#include<iostream>
using namespace std;
void bubble_sort(int *p,int n)
{
    int i=0,j=0;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(*(p+i)>*(p+j))
            swap(*(p+i),*(p+j));
        }
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
        bubble_sort(arr,n);
        for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    }
}