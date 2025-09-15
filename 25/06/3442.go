package main

func maxDifference(s string) int {
	m := make(map[rune]int)

	maxOdd := 0
	minEven := len(s)
	for _, c := range s {
		m[c]++
	}
	for _, v := range m {
		if v%2 == 1 {
			maxOdd = max(maxOdd, v)
		} else {
			minEven = min(minEven, v)
		}
	}
	return maxOdd - minEven
}
