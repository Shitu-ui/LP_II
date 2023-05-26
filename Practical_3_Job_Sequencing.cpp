#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct Job
{
    char id;
    int deadline;
    int profit;
};

bool comparision(Job a,Job b)
{
    return (a.profit>b.profit);
}
int totolProfit=0;
vector<Job>alljob;
void schedule(Job arr[],int n)
{
    sort(arr,arr+n,comparision);
    vector<bool>slot(n);
    for(int i=0;i<n;i++)
    {
        slot[i]=false;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=min(n,arr[i].deadline)-1;j>=0;j--)
        {
            if(slot[j]==false)
            {
                slot[j]=true;
                alljob.push_back(arr[i]);
                totolProfit+=arr[i].profit;
                break;
            }
        }
    }
}
int main()
{
    int n;
    cout<<"Enter number of jobs:";
    cin>>n;
    Job arr[n];
    for(int i=0;i<n;i++)
    {
        cout<<"Enter id:";
        cin>>arr[i].id;
        cout<<"Enter deadline:";
        cin>>arr[i].deadline;
        cout<<"Enter profit:";
        cin>>arr[i].profit;
        cout<<endl;
    }
    cout<<"All jobs:"<<endl;
    cout<<"Id"<<"\t"<<"deadline\t"<<"Profit"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i].id<<"\t"<<arr[i].deadline<<"\t"<<arr[i].profit<<endl;  
    }
    schedule(arr,n);
    cout<<"Id"<<"\t"<<"deadline\t"<<"Profit"<<endl;
     for(int i=0;i<alljob.size();i++)
     {
       cout<<alljob[i].id<<"\t"<<alljob[i].deadline<<"\t"<<alljob[i].profit<<endl;
     }
     cout<<"Total profit:"<<totolProfit;
     return 0;
}