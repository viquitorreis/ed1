package main

import "fmt"

func main() {
	nums := []int{3, 1, 2, 5, 4}
	quickSort(nums)
	println("-----------------")
	printArr(nums)
}

// Quicksort
// 	1. Picks a pivot element
//	2. Partition = Rearranges the array so that everything smaller than pivot goes to its left, everything large to its right.
//		After that, pivot is on its final position
//  3.

func quickSort(nums []int) {
	quickRec(nums, 0, len(nums)-1)
}

func quickRec(nums []int, min, max int) {
	if min < max {
		pivot := partition(nums, min, max)
		quickRec(nums, min, pivot-1)
		quickRec(nums, pivot+1, max)
	}
}

// partition:
//
//	rearranges the array -> everything smaller than pivot goes to its left, everything larger to its right
//	and returns the pivot
func partition(nums []int, min, max int) int {
	pivot := nums[min] // pivot -> first element
	least, greatest := min+1, max

	for least <= greatest {
		// finding elements on the left side that are too small
		for least <= max && nums[least] <= pivot {
			least++
		}

		// finding elements on the right side that are too small
		for greatest >= min && nums[greatest] > pivot {
			greatest--
		}

		// we can only swap if the pointers HAVENT crossed each other
		if least < greatest {
			swap(least, greatest, nums)
		}
	}

	nums[min] = nums[greatest]
	nums[greatest] = pivot

	return greatest
}

func swap(i, j int, nums []int) int {
	temp := nums[j]
	nums[j] = nums[i]
	nums[i] = temp
	return j
}

func printArr(arr []int) {
	fmt.Print("arr nums: ")
	for _, num := range arr {
		fmt.Printf("%d ", num)
	}

	println()
}
