package main

func distributeCandies(n int, limit int) int64 {
	var res int64 = 0
	for i := 0; i <= min(n, limit); i++ {
		last := n - i
		if last > 2*limit {
			continue
		}
		res += int64(min(last, limit) - max(0, last-limit) + 1)
	}
	return res
}
