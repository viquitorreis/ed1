package main

import "fmt"

func main() {
	list := NewList(10)
	head := list.Traverse()
	fmt.Println("head: ", head)
	fmt.Println("removed:", list.Remove(5))
	list.Traverse()

	list2 := NewList(3)
	list2.Traverse()
	fmt.Println("-----")
	list2 = list2.Remove(1)
	list2.Traverse()
}

type ListNode struct {
	Val  int
	Next *ListNode
}

type LinkedList interface {
	Add(num int)
	Traverse() *ListNode
	Remove(num int) *ListNode
}

func NewList(n int) LinkedList {
	if n < 1 {
		return nil
	}

	head := &ListNode{Val: 1}

	for i := 2; i <= n; i++ {
		head.Add(i)
	}

	return head
}

func (l *ListNode) Add(num int) {
	for l != nil {
		if l.Next == nil {
			l.Next = &ListNode{Val: num}
			break
		}
		l = l.Next
	}
}

func (l *ListNode) Traverse() *ListNode {
	head := l
	for l != nil {
		fmt.Printf("node: %d\n", l.Val)
		l = l.Next
	}
	return head
}

func (l *ListNode) Remove(num int) *ListNode {
	dummy := &ListNode{Next: l} // dummy aponta pro head verdadeiro
	curr := dummy               // comeca do dummy, nao do head. Pois o next dele é o head

	for curr.Next != nil {
		if curr.Next.Val == num {
			curr.Next = curr.Next.Next
			break
		}

		curr = curr.Next
	}

	return dummy.Next
}
