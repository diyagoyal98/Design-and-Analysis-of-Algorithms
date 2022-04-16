#include<iostream>
#include<cstdlib>

using namespace std;

int comp=0;
int swaps=0;


int random_num(int l,int r) //to generate a random number b/w the range
{
    int random = rand() % (r-l+1)+l;
    return random;
}

int partition(int arr[],int l,int r)
{
    int ra=random_num(l,r);
    swap(arr[l],arr[ra]);
    swaps++;

    int pivot=arr[l];
    int count=0;
    for(int i=l+1;i<=r;i++)
    {
        if(arr[i]<pivot)
        count++;
    }
    int pivot_idx=l+count;
    swap(arr[l],arr[pivot_idx]);
    swaps++;

    int i=l,j=r;
    while(i<pivot_idx && j>pivot_idx)
    {
        comp++;
        while(arr[i]<pivot)
        {
            comp++;
            i++;
        }    
        comp++;
        while(arr[j]>pivot)
        {
            comp++;
            j--;
        }
        if(i<pivot_idx && j>pivot_idx)
        {
            swap(arr[i++],arr[j--]);
            swaps++;
        }    
    }
    return pivot_idx;
}



void quicksort(int arr[],int l,int r)
{
    if(l>=r)
    return ;

    int p=partition(arr,l,r);

    quicksort(arr,l,p-1);
    quicksort(arr,p+1,r);
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
        quicksort(arr,0,n-1);
        cout<<"Comparsions "<<comp<<endl; 
        cout<<"Swaps "<<swaps<<endl;
        for(int i=0;i<n;i++)
        cout<<arr[i]<<"   ";
    }    
    return 0;
}