#include<bits/stdc++.h>
using namespace std;

int matrix_chain(vector<int>r_c,int n)
{
    int arr[n][n];
    int i,j,k,l,q;
    for(i=1;i<n;i++)
    {
        arr[i][i]=0;
    }
    for(l=2;l<n;l++)
    {
        for(i=1;i<n-l+1;i++)
        {
            j=i+l-1;
            arr[i][j]=INT_MAX;
            for(k=i;k<=j-1;k++)
            {
                q=arr[i][k]+arr[k+1][j]+(r_c[i-1]*r_c[k]*r_c[j]);
                if(q<arr[i][j])
                arr[i][j]=q;
            }
        }
    }
    return arr[1][n-1];
}

int main()
{
    int n;
    cin>>n;
    vector<int>row_col;
    for(int i=0;i<n;i++)
    {
        int r;
        cin>>r;
        row_col.push_back(r);
    }
    cout<<matrix_chain(row_col,n); 
    return 0;

}