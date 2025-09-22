package main

import (
	"fmt"
)

func maxFrequencyElements(nums []int) int {
	m := make(map[int]int)
	ans := 0
	max := 0
	for _, x := range nums {
		m[x]++
		c := m[x]
		if c > max {
			max = c
			ans = c
		} else if c == max {
			ans += c
		}
	}
	return ans
}

func main() {
	// 示例测试
	nums := []int{1, 2, 2, 3, 1, 4}
	fmt.Println(maxFrequencyElements(nums)) // 输出: 4
}
