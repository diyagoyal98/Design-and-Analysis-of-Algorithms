#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int found (char a[],char k)
{
    int i;
    for(i=0;i<26;i++)
    {
        if(a[i]==k)
        {
            return i;
        }    
    }
    return i;
}
void count_sort(char arr[],int n)
{
    char a[26];
    char c='a';
    for(int i=0;i<26;i++,c++)
    {
        a[i]=c;
    }
    int count[26];
    for(int i=0;i<26;i++)
    count[i]=0;
    int j=0;
    for(int i=0;i<n;i++)
    {
        j=found(a,arr[i]);
        count[j]++;
    }
    int max=0;
    int ans=INT_MIN;
    for(int i=0;i<26;i++)
    {
        if(count[i]>max)
        {
            max=count[i];
            ans=i;
        }
    }
    cout<<"MAx occurence is "<<max<<" "<<"Element is "<<a[ans];
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        char arr[n];
        for(int i=0;i<n;i++)
        cin>>arr[i];
        count_sort(arr,n);
    }
    return 0;
}