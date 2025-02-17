package main

import (
	"fmt"
)

func GetArrayFromInput(count int, prompt string) []int {
	if count == 0 {
		return []int{}
	}

	fmt.Print(prompt)

	v := make([]int, count)
	for i := 0; i < count; i++ {
		fmt.Scan(&v[i])
	}

	return v
}

func Count(v []int, n int) int {
	count := 0
	for _, i := range v {
		if i == n {
			count++
		}
	}

	return count
}

func Equal(v1 []int, v2 []int) bool {
	if len(v1) != len(v2) {
		return false
	}

	for i := 0; i < len(v1); i++ {
		if Count(v1, v1[i]) != Count(v2, v1[i]) {
			return false
		}
	}

	return true
}

func Exists(vv [][]int, v []int) bool {
	for _, vec := range vv {
		if Equal(vec, v) {
			return true
		}
	}

	return false
}

func GetFourSum(vec []int, target, index int, quadruple []int, result *[][]int) {
	if target == 0 && len(quadruple) == 4 {
		if !Exists(*result, quadruple) {
			v := make([]int, 4)
			copy(v, quadruple)
			*result = append(*result, v)
		}
		return
	}

	if index == len(vec) {
		return
	}

	if len(quadruple) == 4 {
		return
	}

	for i := index; i < len(vec); i++ {
		quadruple = append(quadruple, vec[i])
		GetFourSum(vec, target-vec[i], i+1, quadruple, result)
		quadruple = quadruple[:len(quadruple)-1]
	}
}

func FourSum(A []int, target int) [][]int {
	var result [][]int
	var quadruple []int

	GetFourSum(A, target, 0, quadruple, &result)
	return result
}

func main() {
	for {
		fmt.Print("Number of elements: ")
		var count int
		fmt.Scan(&count)
		if count == 0 {
			break
		}

		vec := GetArrayFromInput(count, "Please enter the array: ")

		fmt.Print("Please enter the sum of the quadruplet: ")
		var target int
		fmt.Scan(&target)

		result := FourSum(vec, target)

		fmt.Println("The Quadruples: ", result)
	}
}
