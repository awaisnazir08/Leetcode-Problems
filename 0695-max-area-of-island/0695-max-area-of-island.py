def bfs(grid, start):
    my_queue = [start]
    rows, cols = len(grid), len(grid[0])
    area = 0
    while my_queue:
        current = my_queue.pop(0)
        row, col = current

        if row - 1 >= 0 and grid[row-1][col] == 1:
            my_queue.append((row - 1, col))
            area +=1
            grid[row - 1][col] = 0
        if row + 1 < rows and grid[row+1][col] == 1:
            my_queue.append((row + 1, col))
            area +=1
            grid[row + 1][col] = 0
        if col - 1 >= 0 and grid[row][col-1] == 1:
            my_queue.append((row, col - 1))
            area +=1
            grid[row][col - 1] = 0
        if col + 1 < cols and grid[row][col + 1] == 1:
            my_queue.append((row, col + 1))
            grid[row][col + 1] = 0
            area +=1
    if area == 0:
        return 1
    return area
class Solution(object):
    def maxAreaOfIsland(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        max_area = 0
        rows, cols = len(grid), len(grid[0])
        # if rows ==cols == 1 and grid[0][0] == 1:
        #     return 1
        for row in range(rows):
            for col in range(cols):
                if grid[row][col] == 1:
                    area = bfs(grid, (row, col))
                    max_area = max(max_area, area)
        return max_area
        