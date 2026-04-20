package main

import (
	"fmt"
)

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
	fmt.Println(password_length_private)
	fmt.Println(password_options_private)
	fmt.Println(password)
}
