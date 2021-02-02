package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
)

func main() {
	num, maxPart, wantedSum := getData()

	parts := make([]int, 0)
	result := sliceNum(toArray(num), maxPart, wantedSum, 0, &parts)

	summarize(num, result, parts)
}

func toArray(num int) []int {
	str := strconv.Itoa(num)
	res := make([]int, len(str))

	for i, l := range str {
		res[i], _ = strconv.Atoi(string(l))
	}

	return res
}

func toDigit(num []int) int {
	res := 0
	for i, el := range num {
		res += int(math.Pow(10.0, float64(len(num)-i-1))) * el
	}
	return res
}

func sliceNum(num []int, maxPart, wantedSum, curSum int, parts *[]int) int {
	if curSum > wantedSum {
		return 0
	}

	for i := 1; i <= maxPart; i++ {
		if i > len(num) {
			return 0
		}

		myN := toDigit(num[:i])

		if myN+curSum > wantedSum {
			return 0
		}

		for j := 0; j < len(num); j++ {
			res := sliceNum(num[i:], maxPart, wantedSum, myN+curSum, parts)
			if res+myN+curSum == wantedSum {
				*parts = append(*parts, myN)
				return res + toDigit(num[:i])
			}
		}
	}

	return 0
}

func getData() (num int, maxParts int, wantedSum int) {
	scanner := bufio.NewScanner(os.Stdin)

	println("Please provide a number:")
	scanner.Scan()
	num, err := strconv.Atoi(scanner.Text())
	for err != nil {
		println("Please provide a number:")
	}

	println("Please provide max part length:")
	scanner.Scan()
	maxParts, err = strconv.Atoi(scanner.Text())
	for err != nil {
		println("Please provide max part length:")
	}

	println("Please provide wanted sum:")
	scanner.Scan()
	wantedSum, err = strconv.Atoi(scanner.Text())
	for err != nil {
		println("Please provide wanted sum:")
	}

	return
}

func summarize(num, res int, parts []int) {
	if res != 0 {
		fmt.Printf("Number:  %d\n", num)
		fmt.Printf("Parts: ")
		for i := range parts {
			fmt.Printf("%d  ", parts[len(parts)-i-1])
		}
		return
	}

	println("It is impossible, try again")
}
