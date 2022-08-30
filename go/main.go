package main

import (
	"fmt"
	"time"
)

type Album struct {
	id     string
	title  string
	artist string
	price  float64
	rating int
}

func makeAlbums(n int) []Album {
	albums := make([]Album, n)
	for i := 0; i < n; i++ {
		albums[i] = Album{
			id:     fmt.Sprintf("%d", i),
			title:  fmt.Sprintf("Album %d", i),
			artist: "Artist",
			price:  float64(i),
			// random rating between 1 and 10
			rating: i,
		}
	}
	return albums
}

func mergeSort(albums []Album) []Album {
	if len(albums) <= 1 {
		return albums
	}
	mid := len(albums) / 2
	left := mergeSort(albums[:mid])
	right := mergeSort(albums[mid:])
	return merge(left, right)
}

func merge(left, right []Album) []Album {
	var result []Album
	for len(left) > 0 && len(right) > 0 {
		if left[0].rating < right[0].rating {
			result = append(result, left[0])
			left = left[1:]
		} else {
			result = append(result, right[0])
			right = right[1:]
		}
	}
	result = append(result, left...)
	result = append(result, right...)
	return result
}

func main() {
	start := time.Now()

	num := 10000000

	albums := makeAlbums(num)

	mergeSort(albums)

	count := 0

	for i := 0; i < num; i++ {
		count++
	}

	fmt.Printf("\nRan %v times\n", count)

	elapsed := time.Since(start)

	fmt.Printf("Code executed in %v milliseconds\n\n", elapsed.Milliseconds())
}
