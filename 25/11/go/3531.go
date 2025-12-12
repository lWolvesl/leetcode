package L12

import "math"

func countCoveredBuildings(n int, buildings [][]int) int {
	ans, minX, maxX, minY, maxY := 0, make([]int, n+1), make([]int, n+1), make([]int, n+1), make([]int, n+1)
	for i := range minX {
		minX[i], minY[i], maxX[i], maxY[i] = math.MaxInt, math.MaxInt, math.MinInt, math.MinInt
	}

	for _, building := range buildings {
		x := building[0]
		y := building[1]
		minX[y], maxX[y], minY[x], maxY[x] = min(minX[y], x), max(maxX[y], x), min(minY[x], y), max(maxY[x], y)
	}

	for _, building := range buildings {
		x := building[0]
		y := building[1]
		if x < maxX[y] && x > minX[y] && y < maxY[x] && y > minY[x] {
			ans++
		}
	}
	return ans
}
