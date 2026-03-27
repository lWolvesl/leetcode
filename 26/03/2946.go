package main

import "fmt"

func areSimilar(mat [][]int, k int) bool {
	lenX := len(mat)
	lenY := len(mat[0])
	shift := k % lenY

	for i := 0; i < lenX; i++ {
		for j := 0; j < lenY; j++ {
			next := 0
			if i%2 == 0 {
				next = (j + shift) % lenY
			} else {
				next = (j - shift + lenY) % lenY
			}
			if mat[i][j] != mat[i][next] {
				return false
			}
		}
	}

	return true
}

func main() {
	fmt.Println(areSimilar([][]int{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}, 4))
	fmt.Println(areSimilar([][]int{{1, 2, 1, 2}, {5, 5, 5, 5}, {6, 3, 6, 3}}, 2))
	fmt.Println(areSimilar([][]int{{2, 2}, {2, 2}}, 3))
}
