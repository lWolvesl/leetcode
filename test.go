package main

import (
	"fmt"
	"sort"
)

func sorts(arr []int) {
	sort.Ints(arr)
	fmt.Println(arr)
}

func main() {
	sorts([]int{3, 8, -10, 23, 19, -4, -14, 27})
}
