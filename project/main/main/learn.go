package main
import "fmt"
func main() {
	v := 1
L1:
	fmt.Println(v)
	v++
	if v < 3 {
		goto L1
	}
}