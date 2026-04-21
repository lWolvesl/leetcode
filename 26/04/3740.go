package leetcode

import "math"

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func minimumDistance(nums []int) int {
	m := make(map[int]([]int))
	for i, v := range nums {
		_, ok := m[v]
		if !ok {
			m[v] = make([]int, 0)
		}
		m[v] = append(m[v], i)
	}
	ans := math.MaxInt
	for _, v := range m {
		if len(v) < 3 {
			continue
		}
		for i := 0; i+2 < len(v); i++ {
			temp := abs(v[i]-v[i+1]) + abs(v[i]-v[i+2]) + abs(v[i+1]-v[i+2])
			ans = min(ans, temp)
		}
	}
	if ans == math.MaxInt {
		return -1
	}
	return ans
}
