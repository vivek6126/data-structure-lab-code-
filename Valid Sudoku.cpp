#include <vector>
#include <unordered_set>
#include <string>
using namespace std;

class Solution {
public:
    bool isValidSudoku(const vector<vector<char>>& board) {
        unordered_set<string> seen;

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char num = board[i][j];
                if (num == '.') continue;

                string row_check = "row" + to_string(i) + num;
                string col_check = "col" + to_string(j) + num;
                string box_check = "box" + to_string(i / 3) + to_string(j / 3) + num;

                if (seen.count(row_check) || seen.count(col_check) || seen.count(box_check)) {
                    return false;
                }

                seen.insert(row_check);
                seen.insert(col_check);
                seen.insert(box_check);
            }
        }
        return true;
    }
};