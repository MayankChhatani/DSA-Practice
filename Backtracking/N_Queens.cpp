/*
Problem: N-Queens
Platform: LeetCode
Problem Link: https://leetcode.com/problems/n-queens/

Problem Statement:
Place N queens on an N x N chessboard such that no two queens attack each other.

Approach (Backtracking):
- We place one queen in each row.
- For every column in the current row, we check:
  1. Same column upward
  2. Upper-left diagonal
  3. Upper-right diagonal
- If the position is safe:
  - Place the queen
  - Move to the next row using recursion
  - Backtrack by removing the queen

Core Backtracking Rule:
Place -> Explore -> Undo

Time Complexity: O(N!)
Space Complexity: O(N^2)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Checks whether it is safe to place a queen at (row, col)
    bool safe(int row, int col, int n, vector<string>& board){

        // Check the same column upward
        for(int i = 0; i < row; i++){
            if(board[i][col] == 'Q'){
                return false;
            }
        }

        // Check the upper-left diagonal
        for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--){
            if(board[i][j] == 'Q'){
                return false;
            }
        }

        // Check the upper-right diagonal
        for(int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++){
            if(board[i][j] == 'Q'){
                return false;
            }
        }

        return true;
    }

    // Backtracking function to place queens row by row
    void helper(int row, int n, vector<vector<string>>& ans, vector<string>& board){

        // Base case: all rows are filled
        if(row == n){
            ans.push_back(board);
            return;
        }

        // Try each column in the current row
        for(int col = 0; col < n; col++){

            if(safe(row, col, n, board)){

                board[row][col] = 'Q';        // Place queen
                helper(row + 1, n, ans, board); // Explore next row
                board[row][col] = '.';        // Backtrack (undo)
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));

        helper(0, n, ans, board);

        return ans;
    }
};

// Driver code for local testing
int main() {
    int n;
    cin >> n;

    Solution sol;
    vector<vector<string>> result = sol.solveNQueens(n);

    for(int i = 0; i < result.size(); i++){
        cout << "Solution " << i + 1 << ":\n";
        for(auto &row : result[i]){
            cout << row << endl;
        }
        cout << endl;
    }

    return 0;
}
