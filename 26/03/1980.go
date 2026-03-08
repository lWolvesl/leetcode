package main

import (
	"fmt"
	"strconv"
)

func findDifferentBinaryString(nums []string) string {
	n := len(nums)
	m := make(map[int]int)
	mx := 1 << n
	for _, v := range nums {
		temp := 0
		for i, b := range v {
			if b == '1' {
				temp += 1 << (n - 1 - i)
			}
		}
		m[temp] = 1
	}
	for i := range mx {

		if _, ok := m[i]; !ok {
			s := strconv.FormatInt(int64(i), 2)
			return fmt.Sprintf("%0*s", n, s)
		}
	}
	return ""
}
