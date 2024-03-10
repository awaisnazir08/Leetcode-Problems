class Solution(object):
    def bfs(self, grid, start):
        my_queue = [start]
        rows, cols = len(grid), len(grid[0])

        while my_queue:
            current = my_queue.pop(0)
            row, col = current

            if row - 1 >= 0 and grid[row-1][col] == "1":
                my_queue.append((row - 1, col))
                grid[row - 1][col] = "0"
            if row + 1 < rows and grid[row+1][col] == "1":
                my_queue.append((row + 1, col))
                grid[row + 1][col] = "0"
            if col - 1 >= 0 and grid[row][col-1] == "1":
                my_queue.append((row, col - 1))
                grid[row][col - 1] = "0"
            if col + 1 < cols and grid[row][col + 1] == "1":
                my_queue.append((row, col + 1))
                grid[row][col + 1] = "0"

    def numIslands(self, grid):
        islands = 0
        rows, cols = len(grid), len(grid[0])

        for row in range(rows):
            for col in range(cols):
                if grid[row][col] == "1":
                    self.bfs(grid, (row, col))
                    islands += 1

        return islands
