#include<iostream>
using namespace std;

int comp=0;
int merge_both(int *arr,int s ,int e)
{
    int mid=(s+e)/2;
    int len1=mid-s+1;
    int len2=e-mid;
    int invr=0;

    int k=s;
    int *first=new int [len1];
    int *second=new int [len2];

    for(int i=0;i<len1;i++)
    {
        first[i]=arr[k++];
    }
    k=mid+1;
    for(int i=0;i<len2;i++)
    {
        second[i]=arr[k++];
    }

    int index1=0,index2=0;
    k=s;
    while(index1<len1 && index2<len2)
    {
        comp++;
        if(first[index1]<second[index2])
        {
            arr[k]=first[index1];
            index1++;
            k++;
        }
        else
        {
            arr[k]=second[index2];
            k++;
            index2++;
            invr=invr+(len1-index1);
        }
    }
    while(index1<len1)
    {
        arr[k]=first[index1];
        index1++;
        k++;
    }
    while(index2<len2)
    {
        arr[k]=second[index2];
        index2++;
        k++;
    }
    return invr;
}

int merge_sort(int *arr,int s,int e)
{
    int invr=0;
    if(s>=e)
    return 0;
    int mid=(s+e)/2;
    invr+=merge_sort(arr,s,mid);
    invr+=merge_sort(arr,mid+1,e);

    invr+=merge_both(arr,s,e);
    return invr;
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
        int inv=merge_sort(arr,0,n-1);
        cout<<"Inversion "<<inv<<endl;
        cout<<"Comparsions "<<comp<<endl;
        for(int i=0;i<n;i++)
        cout<<arr[i]<<"  ";
    }
    return 0;
}