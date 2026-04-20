from typing import List

#private vars
password_length: int
password_option: chr
password: str

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


#genorator
def generate_password():
    global password_option
    match password_option:
        case 'a':
            print("letters only")

            items = open_file("data/alphabet.txt")
            print(items)

        case 'b':
            print("numbers only")
        case 'c':
            print("special characters only")
        case 'd':
            print("all elements")