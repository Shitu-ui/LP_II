#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<vector<int>>graph;
vector<bool>visited;
void dfs(int v)
{
    visited[v]=true;
    cout<<v<<" ";
    for(auto child:graph[v])
    {
        if(!visited[child])
        {
            dfs(child);
        }
    }
}
vector<int>path;
bool flag=false;
void search(int v,int node)
{
    visited[v]=true;
    path.push_back(v);
    if(v==node)
    {
        flag=true;
        return;
    }
    for(auto child:graph[v])
    {
        if(!visited[child])
        {
            search(child,node);
        }
    }
}

queue<int>q;
void bfs()
{
    if(q.empty())
    {
        return;
    }
    int v=q.front();
    q.pop();
    cout<<v<<" ";
    for(auto child:graph[v])
    {
        if(!visited[child])
        {
            visited[child]=true;
            q.push(child);
        }
    }
    bfs();
}
int main()
{
    int v,e;
    cout<<"Enter number of vertices:";
    cin>>v;
    cout<<"Enter number of edges:";
    cin>>e;
    graph.resize(v+1);
    visited.resize(v+1);
    for(int i=0;i<e;i++)
    {
        int v1,v2;
        cout<<"Enter vertex 1:";
        cin>>v1;
        cout<<"Enter vertex 2:";
        cin>>v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
        cout<<"Edge added successfully"<<endl;
    }
    for(int i=1;i<graph.size();i++)
    {
        cout<<i<<":";
        for(int j=0;j<graph[i].size();j++)
        {
            cout<<graph[i][j];
        }
        cout<<endl;
    }
    int start;
    cout<<"Enter start vertex:";
    cin>>start;
    cout<<"DFS:";
    dfs(start);
    for(int i=0;i<v+1;i++)
    {
        visited[i]=false;
    }
    cout<<endl;
    cout<<"BFS:";
    visited[start]=true;
    q.push(start);
    bfs();
    cout<<endl;
    for(int i=0;i<v+1;i++)
    {
        visited[i]=false;
    }
    int node;
    cout<<"Enter node to find path:";
    cin>>node;
    search(start,node);
    for(auto it:path)
    {
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}