package A

import (
	"sort"
)

func minimumDifference(nums []int, k int) int {
	if k == 1 {
		return 0
	}
	n := len(nums)
	sort.Ints(nums)
	ans := nums[n-1] - nums[0]
	for i := 0; i+k-1 < n; i++ {
		temp := nums[i+k-1] - nums[i]
		if ans > temp {
			ans = temp
		}
	}
	return ans
}
