package main
import "fmt"
func test1 (a int) int {
	a = a + 1
	return a
}

func test2 (a *int) int {
	*a = *a + 1
	return *a
}

func suma(arr ...int) int {
	sum := 0
	for _, v := range arr {
		sum += v
	}
	return sum
}

func main() {
	// b := 1
	// test1(b)
	// fmt.Println(b)
	// test2(&b)
	// fmt.Println(b)
// 	v := 1
// L1:
// 	fmt.Println(v)
// 	v++
// 	if v < 3 {
// 		goto L1
// 	}
	fmt.Println(suma(1, 2, 3, 4))
}