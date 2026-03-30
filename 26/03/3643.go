package main

func reverseSubmatrix(grid [][]int, x int, y int, k int) [][]int {
	for i := 0; i < k/2; i++ {
		for j := range k {
			temp := grid[x+k-1-i][y+j]
			grid[x+k-1-i][y+j] = grid[x+i][y+j]
			grid[x+i][y+j] = temp
		}
	}
	return grid
}
