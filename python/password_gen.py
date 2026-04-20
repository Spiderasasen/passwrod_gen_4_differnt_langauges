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



#genorator
def generate_password():
    global password_option
    match password_option:
        case 'a':
            print("letters only")
        case 'b':
            print("numbers only")
        case 'c':
            print("special characters only")
        case 'd':
            print("all elements")