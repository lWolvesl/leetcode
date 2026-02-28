package A

import "math/bits"

func concatenatedBinary(n int) int {
	var res int64 = 0
	const mod = 1e9 + 7
	for i := 0; i < n; i++ {
		b := bits.Len32(uint32(i + 1))
		res = ((res << b) + int64(i+1)) % mod
	}
	return int(res)
}
