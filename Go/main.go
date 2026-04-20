package main

import (
	"fmt"
)

func main() {
	//private vars
	var passwordLength int
	//var passwordOption string

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
}
