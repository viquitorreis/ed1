package main

import "fmt"

func main() {
	nums := []int{3, 1, 4, 1, 5, 9, 2, 6}
	printArr(quickSort(nums))
}

func quickSort(nums []int) []int {
	return sortRec(0, len(nums)-1, nums)
}

func sortRec(min, max int, nums []int) []int {
	if min < max {
		piv := partition(min, max, nums)
		sortRec(min, piv-1, nums)
		sortRec(piv+1, max, nums)
	}

	return nums
}

func partition(min, max int, nums []int) int {
	piv := nums[min]
	i, j := min+1, max

	// for i <= j {
	for {
		// 1. movemos o ponteiro i++ (p/ direita) até achar um elemento menor que o pivô
		for i <= max && nums[i] <= piv {
			i++
		}
		// 2. movemos o ponteiro j-- (p/ esquerda) até achar um elemento maior que o pivô
		for j > min && nums[j] > piv {
			j--
		}

		if i >= j {
			break
		}

		// 3. swap só se min < max
		if i < max {
			nums[i], nums[j] = nums[j], nums[i]
		}
	}

	// swap piv = nums[j] (elemento agora menor)
	nums[min] = nums[j]
	nums[j] = piv

	return j
}

func printArr(arr []int) {
	for _, num := range arr {
		fmt.Printf("%d ", num)
	}
	println()
}
