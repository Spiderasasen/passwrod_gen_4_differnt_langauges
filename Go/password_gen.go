package main

import (
	"fmt"
	"os"
	"strings"
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

// opening a file
func opening_file(filename string) ([]string, error) {
	data, err := os.ReadFile(filename)
	if err != nil {
		return nil, err
	}

	// convert file contents into a slice of strings
	lines := strings.Split(string(data), "\n")

	// trim whitespace + remove empty lines
	var result []string
	for _, line := range lines {
		line = strings.TrimSpace(line)
		if line != "" {
			result = append(result, line)
		}
	}

	return result, nil
}

// main function
func mainGen() {
	switch password_options_private {
	case "a":
		fmt.Println("letters only")

		items, err := opening_file("../data/alphabet.txt")
		if err != nil {
			fmt.Println(err)
		}

		fmt.Println(items)

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
