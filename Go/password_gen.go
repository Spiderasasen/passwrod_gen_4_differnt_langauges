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
func openingFile(filename string) ([]string, error) {
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
func newPassword(pass string, length int, list []string) string {
	var index int

	for i := 0; i < length; i++ {
		index = rand.Intn(len(list))
		pass = pass + list[index]
	}
	return pass
}

// making a simple copier
func copyNewPassword(pass string, length int, fileName string) string {
	//opens a file
	items, err := openingFile(fileName)

	//if there is an error while opening it, it will yell
	if err != nil {
		fmt.Println(err)
	}

	pass = newPassword(pass, length, items)

	return pass
}

// main function
func mainGen() {
	//setting the seed
	rand.Seed(time.Now().UnixNano())

	switch password_options_private {
	case "a":
		fmt.Println("letters only")

		password = copyNewPassword(password, password_length_private, "../data/alphabet.txt")

		fmt.Println("Your password: ", password)

		break
	case "b":
		fmt.Println("numbers only")

		password = copyNewPassword(password, password_length_private, "../data/numbers.txt")
		fmt.Println("Your password: ", password)

		break
	case "c":
		fmt.Println("symbols only")

		password = copyNewPassword(password, password_length_private, "../data/special.txt")
		fmt.Println("Your password: ", password)

		break
	case "d":
		fmt.Println("all options")
		break
	}
}
