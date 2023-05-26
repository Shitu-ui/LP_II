#include<iostream>
#include<cmath>
#include<limits.h>
using namespace std;
int g=0;
void Print(int puzzle[])
{
    for(int i=0;i<9;i++)
    {
        if(i%3==0)
        {
            cout<<endl;
        }
        if(puzzle[i]==-1)
        {
            cout<<"_ ";
        }
        else
        {
            cout<<puzzle[i]<<" ";
        }
    }
    cout<<endl<<endl;
}
void moveLeft(int start[],int pos)
{
    swap(start[pos],start[pos-1]);
}
void moveRight(int start[],int pos)
{
    swap(start[pos],start[pos+1]);
}
void moveUp(int start[],int pos)
{
    swap(start[pos],start[pos-3]);
}
void moveDown(int start[],int pos)
{
    swap(start[pos],start[pos+3]);
}
void Copy(int temp[],int real[])
{
    for(int i=0;i<9;i++)
    {
        temp[i]=real[i];
    }
}
int heuristic(int start[],int goal[])
{
    int h=0;
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(start[i]==goal[j] && start[i]!=-1)
            {
                h+=abs((j-i)/3)+abs((j-i)%3);
            }
        }
    }
    return h+g;
}
void moveTile(int start[],int goal[])
{
    int emptyAt=0;
    for(int i=0;i<9;i++)
    {
        if(start[i]==-1)
        {
            emptyAt=i;
            break;
        }
    }
    
    int f1=INT_MAX,f2=INT_MAX,f3=INT_MAX,f4=INT_MAX;
    int t1[9],t2[9],t3[9],t4[9];
    Copy(t1,start);
    Copy(t2,start);
    Copy(t3,start);
    Copy(t4,start);
    int row=emptyAt/3;
    int col=emptyAt%3;
    if(col-1>=0)
    {
        moveLeft(t1,emptyAt);
        f1=heuristic(t1,goal);
    }
    if(col+1<3)
    {
        moveRight(t2,emptyAt);
        f2=heuristic(t2,goal);
    }
    if(row+1<3)
    {
        moveDown(t3,emptyAt);
        f3=heuristic(t3,goal);
    }
    if(row-1>=0)
    {
        moveUp(t4,emptyAt);
        f4=heuristic(t4,goal);
    }
    
    if(f1<=f2 && f1<=f3 && f1<=f4)
    {
        moveLeft(start,emptyAt);
    }
    else if(f2<=f1 && f2<=f3 && f2<=f4)
    {
        moveRight(start,emptyAt);
    }
    else if(f3<=f1 && f3<=f2 && f3<=f4)
    {
        moveDown(start,emptyAt);
    }
    else
    {
        moveUp(start,emptyAt);
    }
}
void solveEight(int start[],int goal[])
{
    g++;
    moveTile(start,goal);
    Print(start);
    int f=heuristic(start,goal);
    if(f==g)
    {
        cout<<"Solution found "<<f<<" moves"<<endl;
        return;
    }
    solveEight(start,goal);
}
bool solvable(int start[])
{
    int invr=0;
    for(int i=0;i<9;i++)
    {
        if(start[i]<=1)
        {
            continue;
        }
        for(int j=i+1;j<9;j++)
        {
            if(start[j]==-1)
            {
                continue;
            }
            if(start[i]>start[j])
            {
                invr++;
            }
        }
    }
    return invr&1?false:true;
}
int main()
{
    int start[9];
    cout<<"Enter the start state:";
    for(int i=0;i<9;i++)
    {
        cin>>start[i];
    }
    int goal[9];
    cout<<"Enter goal state:";
    for(int i=0;i<9;i++)
    {
        cin>>goal[i];
    }
    Print(start);
    if(solvable(start))
    {
        solveEight(start,goal);
    }
    else
    {
        cout<<"Solution does not exist"<<endl;
    }
    return 0;
}