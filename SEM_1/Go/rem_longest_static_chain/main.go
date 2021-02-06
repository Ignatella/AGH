package main

import (
	"fmt"
)

type node struct {
	value int
	next  *node
}

func main() {
	n1 := node{20, nil}
	n2 := node{10, &n1}
	n3 := node{10, &n2}
	n4 := node{10, &n3}
	n5 := node{30, &n4}
	n6 := node{1, &n5}
	n7 := node{0, &n6}
	n8 := node{2, &n7}
	n9 := node{2, &n8}
	//n10 := node{2, &n9}
	n1.next = &n9
	printChain(&n2)

	remConstChain(&n2)

	printChain(&n2)
	printChain(&n1)
}

func remConstChain(root *node) int {
	var cur = root

	if root.next == root {
		return 0
	}

	var head *node = nil
	var tail *node = nil
	var max *node = nil
	loopD := false
	mLen := 0
	c := 0
	for ok := true; ok; ok = !loopD || c > 0 {
		if cur.value == cur.next.value {
			if c == 0 {
				c++
				head = cur
			}

			tail = cur.next
			c++
		} else {
			c = 0
		}

		if c > mLen {
			mLen = c
			max = nil
		}

		if max == nil && c == mLen {
			max = head
		}

		cur = cur.next
		if cur == root {
			loopD = true
		}
	}

	if max != nil && max != head {
		return 0
	}

	if head != nil && tail != nil {
		findParent(head).next = tail.next
		tail.next = head
	}

	return mLen
}

func findParent(n *node) *node {
	cur := n.next

	for cur != n {
		if cur.next == n {
			return cur
		}

		cur = cur.next
	}

	return nil
}

func printChain(root *node) {
	var cur *node = root
	for ok := true; ok; ok = cur != root {
		fmt.Printf(" %d ----> ", cur.value)

		cur = cur.next
	}

	fmt.Println()
}
