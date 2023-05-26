#include<iostream>
#include<vector>
using namespace std;
bool isSafe1(int row,int col,vector<string>board,int n)
{
    int dupRow=row;
    int dupCol=col;
    while(row>=0 && col>=0)
    {
        if(board[row][col]=='Q')
        {
            return false;
        }
        row--;
        col--;
    }
    col=dupCol;
    row=dupRow;
    while(col>=0)
    {
        if(board[row][col]=='Q')
        {
            return false;
        }
        col--;
    }
    col=dupCol;
    row=dupRow;
    while(row<n && col>=0)
    {
        if(board[row][col]=='Q')
        {
            return false;
        }
        row++;
        col--;
    }
    return true;
}
void solve(int col,vector<string>&board,vector<vector<string>>&ans,int n)
{
    if(col==n)
    {
        ans.push_back(board);
        return;
    }
    for(int row=0;row<n;row++)
    {
        if(isSafe1(row,col,board,n))
        {
            board[row][col]='Q';
            solve(col+1,board,ans,n);
            board[row][col]='.';
        }
    }
}
void solvebnb(int col,vector<string>&board,vector<vector<string>>&ans,vector<int>&leftRow,vector<int>&upperDiagonal,vector<int>&lowerDiagonal,int n)
{
    if(col==n)
    {
        ans.push_back(board);
        return;
    }
    for(int row=0;row<n;row++)
    {
        if(leftRow[row]==0 && lowerDiagonal[row+col]==0 && upperDiagonal[col-row+n-1]==0)
        {
            board[row][col]='Q';
            leftRow[row]=1;
            upperDiagonal[col-row+n-1]=1;
            lowerDiagonal[col+row]=1;
            solvebnb(col+1,board,ans,leftRow,upperDiagonal,lowerDiagonal,n);
            board[row][col]=0;
            upperDiagonal[col-row+n-1]=0;
            lowerDiagonal[col+row]=0;
            leftRow[row]=0;
        }
    }
}
vector<vector<string>>solveNQueensbnb(int n)
{
    vector<vector<string>>ans;
    vector<string>board(n);
    vector<int>leftRow(n,0);
    string s(n,'.');
    for(int i=0;i<n;i++)
    {
        board[i]=s;
    }
    vector<int>lowerDiagonal(2*n-1,0);
    vector<int>upperDiagonal(2*n-1,0);
    solvebnb(0,board,ans,leftRow,upperDiagonal,lowerDiagonal,n);
    return ans;
}
vector<vector<string>>solveNQueen(int n)
{
    vector<vector<string>>ans;
    vector<string>board(n);
    string s(n,'.');
    for(int i=0;i<n;i++)
    {
        board[i]=s;
    }
    solve(0,board,ans,n);
    return ans;
}
int main()
{
    int n;
    cout<<"Enter size of board:";
    cin>>n;
    int ch=-1;
    vector<vector<string>>ans=solveNQueen(n);
    vector<vector<string>>answer=solveNQueensbnb(n);
    cout<<"************MENU***********"<<endl;
    cout<<"1.Backtracking"<<endl;
    cout<<"2.Branch and Bound"<<endl;
    cin>>ch;
    switch(ch)
    {
        case 1:
            if(ans.empty())
            {
                cout<<"Solution does not exist"<<endl;
            }
            else
            {
                for(int i=0;i<ans.size();i++)
                {
                    cout<<"Arrangement "<<i+1<<endl;
                    for(int j=0;j<ans[0].size();j++)
                    {
                        cout<<ans[i][j];
                        cout<<endl;
                    }
                    cout<<endl;
                }
            }
            break;
        case 2:
            if(answer.empty())
            {
                cout<<"Solution does not exist"<<endl;
            }
            else
            {
                for(int i=0;i<answer.size();i++)
                {
                    cout<<"Arrangement "<<i+1<<endl;
                    for(int j=0;j<answer[0].size();j++)
                    {
                        cout<<answer[i][j];
                        cout<<endl;
                    }
                     cout<<endl;
                }
            }
            break;
        default:
            cout<<"\nPlease enter correct choice!!!";
            break;
    }
    return 0;
}