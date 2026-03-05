package main

import (
	"slices"
)

var cache = []byte("0")

func init() {
	for range 20 {
		temp := append([]byte(nil), cache...)
		for i := range len(temp) {
			if temp[i] == '1' {
				temp[i] = '0'
			} else {
				temp[i] = '1'
			}
		}
		slices.Reverse(temp)
		cache = append(cache, '1')
		cache = append(cache, temp...)
	}
}

func findKthBit(n int, k int) byte {
	return cache[k-1]
}
