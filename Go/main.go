package main

import (
	"fmt"
	"strings"
)

func main() {
	//private vars
	var passwordLength int
	var passwordOption string
	options := []string{"a. Password of letters only", "b. Password or numbers only", "c. Password of spical characters", "d. Password with all"}

	//for the password length
	for {

		fmt.Println("Please enter the password length: ")

		//checking if the scan was a number
		_, err := fmt.Scan(&passwordLength)
		if err != nil {
			fmt.Println("Invalid password, please press y to continue ")
			var trash string
			fmt.Scan(&trash)
			continue
		}
		break
	}

	//getting the options
	for {
		fmt.Println("Please enter the password option: ")
		for _, option := range options {
			fmt.Println(option)
		}
		fmt.Scan(&passwordOption)
		passwordOption := strings.ToLower(passwordOption)
		if !(passwordOption == "a" || passwordOption == "b" || passwordOption == "c" || passwordOption == "d") {
			continue
		}
		break
	}

	//setting the functions
	settingLength(passwordLength)
	settingOptions(passwordOption)
	//
	////area to generate the password
	mainGen()
}
