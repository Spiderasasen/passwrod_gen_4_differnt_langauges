package main

import "fmt"

// vars
var password_length_private int
var password_options_private string
var password string

// setters
func settingLength(length int) {
	password_length_private = length
}
func settingOptions(options string) {
	password_options_private = options
}

func mainGen() {
	switch password_options_private {
	case "a":
		fmt.Println("letters only")
		break
	case "b":
		fmt.Println("numbers only")
		break
	case "c":
		fmt.Println("symbols only")
		break
	case "d":
		fmt.Println("all options")
		break
	}
}
