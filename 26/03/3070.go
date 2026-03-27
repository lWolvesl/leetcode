package main

import "fmt"

func countSubmatrices(grid [][]int, k int) int {
	m := len(grid)
	n := len(grid[0])
	res := 0
	perfix := make([][]int, m)
	for i := range perfix {
		perfix[i] = make([]int, n)
	}

	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if i == 0 && j == 0 {
				perfix[i][j] = grid[0][0]
			} else if i == 0 {
				perfix[i][j] = perfix[i][j-1] + grid[i][j]
			} else if j == 0 {
				perfix[i][j] = perfix[i-1][j] + grid[i][j]
			} else {
				perfix[i][j] = perfix[i-1][j] + perfix[i][j-1] - perfix[i-1][j-1] + grid[i][j]
			}
			if perfix[i][j] <= k {
				res++
			}
		}
	}
	return res
}

func main() {
	fmt.Println(countSubmatrices([][]int{{7, 2, 9}, {1, 5, 0}, {2, 6, 6}}, 18))
}
