package main

import (
	"strconv"
	"strings"
)

func maxDiff(num int) int {
	replace := func(s string, x, y rune) string {
		return strings.ReplaceAll(s, string(x), string(y))
	}

	num_max := strconv.Itoa(num)
	num_min := num_max

	for _, c := range num_max {
		if c != '9' {
			num_max = replace(num_max, c, '9')
			break
		}
	}

	for i, c := range num_min {
		if i == 0 && c != '1' {
			num_min = replace(num_min, c, '1')
			break
		}
		if c != '0' && c != rune(num_min[0]) {
			num_min = replace(num_min, c, '0')
			break
		}
	}

	x, _ := strconv.Atoi(num_max)
	y, _ := strconv.Atoi(num_min)

	return x - y
}
