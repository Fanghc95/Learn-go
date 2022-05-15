package main
import "fmt"
func printSlice(s []int) {
    fmt.Printf("len=%d cap=%d %p %v\n", len(s), cap(s), s, s)
}


type person struct {
	name string
	age int
}
type couple struct {
	fname *person
	mname *person
}
func main()  {
	// a := 1
	// p := &a
	// fmt.Println(p)
	// fmt.Println(*p)
	// // fmt.Println(a)
	// b := []int {1, 3, 4, 5, 6}
	// fmt.Println(cap(b))
	// d := make([]int, 3, 4)
	// printSlice(d)
	// d = append(d, 1)
	// printSlice(d)
	// f := d[0:3]
	// printSlice(f)
	// f = append(f, 1, 2, 3)
	// printSlice(f)
	// // copy(f, d)
	// // printSlice(f)
	// var dmMap map[string]int // 定义并未初始化
	// dmMap = make(map[string]int)
	// dmMap["111"] = 1
	// dmMap["222"] = 2
	
	// delete(dmMap, "222")
	// for k, v := range dmMap {
	// 	fmt.Println("key = ", k , "  value = ", v)
	// }
	p := person{
		name: "aaaa",
		age: 12,
	}
	hereC := couple{
		fname: &p,
		mname: &p,
	}
	fmt.Println(hereC.fname)
}