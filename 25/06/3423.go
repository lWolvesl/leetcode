package main

import "math"

func maxAdjacentDistance(nums []int) int {
	n := len(nums)
	max := int(math.Abs(float64(nums[0] - nums[n-1])))
	for i := 0; i < n-1; i++ {
		max = int(math.Max(float64(max), float64(math.Abs(float64(nums[i]-nums[i+1])))))
	}
	return max
}
