package main

import "math"

func getHappyString(n int, k int) string {
	bt := int(math.Pow(2.0, float64(n-1)))
	maxK := 3 * bt
	if k > maxK {
		return ""
	}
	slice := []byte{'a', 'b', 'c'}
	sl := [][]byte{{'b', 'c'}, {'a', 'c'}, {'a', 'b'}}
	res := make([]byte, 0, n)
	if k <= bt {
		res = append(res, slice[0])
		bt = 0
	} else if k > bt && k <= 2*bt {
		res = append(res, slice[1])
	} else {
		res = append(res, slice[2])
		bt *= 2
	}
	for i := 1; i < n; i++ {
		temp := res[i-1]
		i1 := int(temp - 'a')
		bti := int(math.Pow(2.0, float64(n-i-1)))
		if k <= bt+bti {
			res = append(res, sl[i1][0])
		} else {
			res = append(res, sl[i1][1])
			bt += bti
		}
	}

	return string(res)
}
