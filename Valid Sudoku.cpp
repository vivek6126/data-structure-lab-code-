class Solution {
public:
    bool isValidSudoku(const std::vector<std::vector<char>>& board) {
        std::unordered_set<std::string> seen;

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char num = board[i][j];
                if (num == '.') continue;

                std::string row_check = "row" + std::to_string(i) + num;
                std::string col_check = "col" + std::to_string(j) + num;
                std::string box_check = "box" + std::to_string(i / 3) + std::to_string(j / 3) + num;

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
