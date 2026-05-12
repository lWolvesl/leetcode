package A

type node1559 struct {
	x, y   int
	px, py int
}

func containsCycle(grid [][]byte) bool {
	m := len(grid)
	n := len(grid[0])
	if m < 2 || n < 2 {
		return false
	}

	visited := make([][]bool, m)
	for i := range visited {
		visited[i] = make([]bool, n)
	}

	dirs := [][2]int{{0, -1}, {0, 1}, {-1, 0}, {1, 0}}

	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if visited[i][j] {
				continue
			}

			visited[i][j] = true
			stack := []node1559{{x: i, y: j, px: -1, py: -1}}

			for len(stack) > 0 {
				top := stack[len(stack)-1]
				stack = stack[:len(stack)-1]

				for _, dir := range dirs {
					nx := top.x + dir[0]
					ny := top.y + dir[1]
					if nx < 0 || nx >= m || ny < 0 || ny >= n {
						continue
					}
					if grid[nx][ny] != grid[top.x][top.y] {
						continue
					}

					if !visited[nx][ny] {
						visited[nx][ny] = true
						stack = append(stack, node1559{x: nx, y: ny, px: top.x, py: top.y})
					} else if nx != top.px || ny != top.py {
						return true
					}
				}
			}
		}
	}

	return false
}
