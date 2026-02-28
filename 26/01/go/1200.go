package A

import "sort"

func minimumAbsDifference(arr []int) [][]int {
	sort.Slice(arr, func(i, j int) bool {
		return arr[i] < arr[j]
	})
	ans := [][]int{}
	n := len(arr)
	minDiff := arr[1] - arr[0]
	for i := 1; i < n; i++ {
		temp := arr[i] - arr[i-1]
		if minDiff > temp {
			minDiff = temp
		}
	}
	for i := 1; i < n; i++ {
		temp := arr[i] - arr[i-1]
		if temp == minDiff {
			ans = append(ans, []int{arr[i-1], arr[i]})
		}
	}
	return ans
}
