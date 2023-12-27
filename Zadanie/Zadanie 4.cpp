#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<int> queens(n, -1); 
        solveNQueensUtil(result, queens, 0, n);
        return result;
    }

private:
    void solveNQueensUtil(vector<vector<string>>& result, vector<int>& queens, int row, int n) {
        if (row == n) {
            result.push_back(generateBoard(queens, n));
            return;
        }

        for (int col = 0; col < n; col++) {
            if (isValid(queens, row, col)) {
                queens[row] = col;
                solveNQueensUtil(result, queens, row + 1, n);
                queens[row] = -1;
            }
        }
    }

    bool isValid(vector<int>& queens, int row, int col) {
        for (int i = 0; i < row; i++) {
            if (queens[i] == col || queens[i] == col + row - i || queens[i] == col - row + i) {
                return false;
            }
        }
        return true;
    }

    vector<string> generateBoard(vector<int>& queens, int n) {
        vector<string> board(n, string(n, '.'));
        for (int i = 0; i < n; i++) {
            board[i][queens[i]] = 'Q';
        }
        return board;
    }
};

int main() {
    int n;
    cout << "Board Size: ";
    cin >> n;

    Solution sol;
    vector<vector<string>> result = sol.solveNQueens(n);

    cout << "Variants:" << endl;
    for (const auto& board : result) {
        for (const auto& row : board) {
            cout << row << endl;
        }
        cout << endl;
    }

    return 0;
}