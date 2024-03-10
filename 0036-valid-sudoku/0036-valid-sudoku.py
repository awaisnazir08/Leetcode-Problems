def checkGrid(arr):
    dic = {}
    for val in arr:
        if val not in dic:
            dic[val] = 1
        elif val == ".":
            continue
        else:
            return False
    return True
class Solution(object):
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        for i in range(0,9):
            dic_row = {}
            dic_col = {}
            for j in range(0,9):
                # Check rows
                if board[i][j] not in dic_row or board[i][j] == ".":
                    dic_row[board[i][j]] = 1
                else:
                    return False

                # Check columns
                if board[j][i] not in dic_col:
                    dic_col[board[j][i]] = 1
                elif board[j][i] == ".":
                    continue
                else:
                    return False

        # Check 3x3 grids
        for ii in range(0, 9, 3):
            for jj in range(0, 9, 3):
                window = []
                for x in range(ii, ii+3):
                    for y in range(jj, jj+3):
                        window.append(board[x][y])
                if not checkGrid(window):
                    return False

        return True
