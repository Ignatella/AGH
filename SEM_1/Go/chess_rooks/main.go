package main

import (
	"fmt"
	"math/rand"
	"sort"
	"time"
)

const minRand = -5
const maxRand = 5
const chessboardSize = 5
const rookCount = 3

type position struct {
	x, y int
}

func main() {
	chessboard := createChessboard(chessboardSize, chessboardSize)
	fillArray(chessboard)
	printArray(chessboard)
	poss := placeRooks(chessboard, rookCount)
	for _, pos := range poss {
		fmt.Println(pos)
	}

	fmt.Println("The End.")
}

func placeRooks(chessboard [][]int, rookCount int) []position {
	sums := make(map[int]position)

	for i := range chessboard {
		for j := range chessboard[i] {
			pos := position{x: i, y: j}
			sum := getSum(chessboard, pos)
			sums[sum] = pos
		}
	}

	arr := make([]int, len(sums))

	i := 0
	for k := range sums {
		arr[i] = k
		i++
	}

	sort.Sort(sort.Reverse(sort.IntSlice(arr)))

	res := make([]position, rookCount)

	for i := 0; i < rookCount; i++ {
		res[i] = sums[arr[i]]
	}

	return res
}

func getSum(chessboard [][]int, pos position) (res int) {
	res = 0
	for i := range chessboard {
		res += chessboard[i][pos.y]
	}

	for _, el := range chessboard[pos.x] {
		res += el
	}

	res -= 2 * chessboard[pos.x][pos.y]

	return
}

func fillArray(arr [][]int) {
	rand.Seed(time.Now().UnixNano())
	for i := range arr {
		for j := range arr[i] {
			arr[i][j] = rand.Intn(maxRand+1-minRand) + minRand
		}
	}
}

func printArray(array [][]int) {
	for i := range array {
		for j := range array[i] {
			fmt.Printf("%5d", array[i][j])
		}
		fmt.Println()
	}
}

func createChessboard(xSize, ySize int) [][]int {
	chessboard := make([][]int, xSize)
	for i := range chessboard {
		chessboard[i] = make([]int, ySize)
	}

	return chessboard
}
