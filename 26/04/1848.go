package leetcode

import "math"

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func getMinDistance(nums []int, target int, start int) int {
	ans := math.MaxInt
	for i, v := range nums {
		if v == target {
			ans = min(abs(i-start), ans)
		}
	}
	return ans
}
