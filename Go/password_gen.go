package main

import (
	"fmt"
	"math/rand"
	"os"
	"strings"
	"time"
)

// vars
var password_length_private int
var password_options_private string
var password string = ""

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

// making the new password
func new_password(pass string, length int, list []string) string {
	var index int

	for i := 0; i < length; i++ {
		index = rand.Intn(len(list))
		pass = pass + list[index]
	}
	return pass
}

// main function
func mainGen() {
	//setting the seed
	rand.Seed(time.Now().UnixNano())

	switch password_options_private {
	case "a":
		fmt.Println("letters only")

		//allows me to use the list
		items, err := opening_file("../data/alphabet.txt")
		if err != nil {
			fmt.Println(err)
		}

		password = new_password(password, password_length_private, items)

		fmt.Println("Your password: ", password)

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
