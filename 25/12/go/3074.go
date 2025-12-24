package A

import "slices"

func minimumBoxes(apple []int, capacity []int) int {
	sum := 0
	for _, i := range apple {
		sum += i
	}
	slices.SortFunc(capacity, func(a, b int) int { return b - a })
	ans := 0
	for _, i := range capacity {
		sum -= i
		ans++
		if sum <= 0 {
			break
		}
	}
	return ans
}
