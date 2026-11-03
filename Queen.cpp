#include <bits/stdc++.h>
using namespace std;

bool chk(vector<vector<char>>& board, vector<int>& rowOcc, int row, int col)
{
    if (rowOcc[row] != -1)
        return false;

    int r = row, c = col;

    while (r >= 0 && c >= 0)
    {
        if (board[r][c] == 'Q')
            return false;

        r--;
        c--;
    }

    r = row;
    c = col;

    while (r < 4 && c >= 0)
    {
        if (board[r][c] == 'Q')
            return false;

        r++;
        c--;
    }

    return true;
}

void solve(vector<vector<char>> &board, vector<int> &rowOcc, int col, vector<vector<vector<char>>> &ans)
{
    if(col == 4)
    {
        ans.push_back(board);
        return;
    }

    for(int i = 0; i<4; i++)
    {
        if(chk(board, rowOcc, i, col))
        {
            board[i][col] = 'Q';
            rowOcc[i] = 1;
            solve(board, rowOcc, col+1, ans);
            board[i][col] = 'M';
            rowOcc[i] = -1;
        }
    }
}

int main()
{
    vector<vector<char>> board(4, vector<char> (4, 'M'));
    vector<vector<vector<char>>> ans;
    vector<int> rowOcc(4, -1);
    solve(board, rowOcc, 0, ans);
    for(auto i : ans)
    {
        for(auto j : i)
        {
            for(auto k : j)
            {
                cout<<k<<" ";
            }
            cout<<endl;
        }

        cout<<endl<<endl;;
    }
    return 0;
}
