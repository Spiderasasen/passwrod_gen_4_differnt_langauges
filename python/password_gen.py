from typing import List
import random

#private vars
password_length: int
password_option: chr
password: str = ""

#setters
def setting_length(length: int):
    global password_length
    password_length = length

def setting_option(option: chr):
    global password_option
    password_option = option

def open_file(file: str):
    listing: List[chr(1)] = []

    with open(file, 'r') as f:
        for line in f:
            listing.append(line.strip())

    return listing

#makes the new password
def new_password(new_password_string: str, length: int, items) -> str:
    for i in range(length):
        rand: int = random.randint(0, len(items) - 1)
        new_password_string += items[rand]
    return new_password_string

#making the system to make a new password
def making_password(new_password_string: str, length: int, file: str) -> str:
    items = open_file(file)
    new_password_string = new_password(new_password_string, length, items)
    return new_password_string

#genorator
def generate_password():
    #calling the private vars
    global password_option
    global password_length
    global password

    match password_option:
        case 'a':
            print("letters only")

            password = making_password(password, password_length, "data/alphabet.txt")

            print("New password:", password)

        case 'b':
            print("numbers only")

            password = making_password(password, password_length, "data/numbers.txt")
            print("New password:", password)

        case 'c':
            print("special characters only")

            password = making_password(password, password_length, "data/special.txt")
            print("New password:", password)

        case 'd':
            print("all elements")