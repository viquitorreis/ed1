package main

import (
	"fmt"
)

func main() {
	people := []Person{
		{
			Name: "César",
			Age:  49,
		},
		{
			Name: "Cícero",
			Age:  42,
		},
		{
			Name: "Victor",
			Age:  26,
		},
	}

	printArr(quickSortPersons(people, 0, len(people)-1))
}

type Person struct {
	Name string
	Age  int
}

// order by persons age
func quickSortPersons(arr []Person, low, high int) []Person {
	if low < high {
		pivot := partition(arr, low, high)
		quickSortPersons(arr, low, pivot-1)
		quickSortPersons(arr, pivot+1, high)
	}

	return arr
}

//  2. partition
//     return new pivots idx (j)
//     i -> slide left finding each that is lower than pivot
//     j -> slide right finding each bigger than pivot
//     loop until i <= j
//     swap pivot to new correct position -> arr[j]
//     new pivot index = j, return j
func partition(arr []Person, min, max int) int {
	piv := arr[min]
	i, j := min+1, max

	for i <= j {
		for i <= max && arr[i].Age <= piv.Age {
			i++
		}

		for j > min && arr[j].Age > piv.Age {
			j--
		}

		if i < max {
			arr[i], arr[j] = arr[j], arr[i]
		}
	}

	arr[min] = arr[j]
	arr[j] = piv

	return j
}

func printArr(arr []Person) {
	for i := range arr {
		fmt.Printf("person %d: %s - %d\n", i+1, arr[i].Name, arr[i].Age)
	}
}
