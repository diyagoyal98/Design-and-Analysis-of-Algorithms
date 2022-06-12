
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int s,e;
    vector<pair<int,int>>timeline;
    vector<int>ans;
    for(int i=0;i<n;i++)
    {
        cin>>s>>e;
        timeline.push_back({e,s});
    }
    sort(timeline.begin(),timeline.end());
    int count=0,currEnd=-1;
    for(int i=0;i<n;i++)
    {
        if(timeline[i].second>currEnd)
        {
            count++;
            ans.push_back(i+1);
            currEnd=timeline[i].first;
        }
    }
    cout<<count<<endl;
    cout<<"Selected activity times are "<<endl;
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<"   ";
    }
    return 0;
}