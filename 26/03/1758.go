package main

func minOperations(s string) int {
	a := 0
	for i := 0; i < len(s); i++ {
		expected := byte('0' + i%2)
		if s[i] == expected {
			a++
		}
	}
	b := len(s) - a
	if a < b {
		return a
	}
	return b
}
