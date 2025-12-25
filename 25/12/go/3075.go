package A

import (
	"slices"
)

func maximumHappinessSum(happiness []int, k int) int64 {
	ans := int64(0)
	slices.SortFunc(happiness, func(a, b int) int {
		return b - a
	})
	for i, v := range happiness {
		if v < i || i > k-1 {
			break
		}
		ans += int64(v - i)
	}
	return ans
}
