//Insertion sort
#include<iostream>
using namespace std;

void insertion_sort(int *arr,int n)
{
    int i,j,tmp;
    int comp=0,shifts=0;
    for(i=1;i<n;i++)
    {
        tmp=*(arr+i);
        j=i-1;
        while(j>=0 && *(arr+j)>tmp)
        {
            comp++;
            *(arr+(j+1))=*(arr+j);
            shifts++;
            j=j-1;
        }
        *(arr+j+1)=tmp;
        shifts++;
    }

    for(i=0;i<n;i++)
    cout<<*(arr+i)<<"  ";

    cout<<endl<<"Comparsions  "<<comp;
    cout<<endl<<"Shifts  "<<shifts<<endl;
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
        insertion_sort(arr,n);
        
    }
}