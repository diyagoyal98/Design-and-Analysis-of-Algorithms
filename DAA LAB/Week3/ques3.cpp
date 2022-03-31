//Selection sort 
#include<iostream>
using namespace std;

void selection_sort(int *arr,int n)
{
    int i,j,min_idx;
    int comp=0,swapc=0;
    for(i=0;i<n-1;i++)
    {
        min_idx=i;
        for(j=i+1;j<n;j++)
        {
            comp++;
            if(*(arr+j)<*(arr+min_idx))
            min_idx=j;
        }
        swap(*(arr+i),*(arr+min_idx));
        swapc++;
    }
    for(int i=0;i<n;i++)
    cout<<*(arr+i)<<"   ";
    cout<<endl<<"Comparsion  "<<comp<<endl;
    cout<<"Swaps  "<<swapc<<endl;
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
        selection_sort(arr,n);
    }
}