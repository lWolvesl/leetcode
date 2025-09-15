package main

func differenceOfSums(n int, m int) int {
	nums2 := 0
	for i := 0; i*m <= n; i++ {
		nums2 += i * m
	}
	return n*(n+1)/2 - nums2*2
}
