package main

import (
	"crypto/md5"
	"fmt"
	"os"
)

func main() {
	argLen := len(os.Args)
	if argLen == 1 {
		fmt.Println("Specify string as an argument to calculate its MD5")
		os.Exit(-1)
	}
	byteArray := []byte(os.Args[1])
	fmt.Printf("%x", md5.Sum(byteArray))
}
