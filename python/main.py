from python.password_gen import setting_length, setting_option, generate_password


def main():
    #private vars
    password_length: int = 0
    password_option = ''
    options = ["a. Password of letters only", "b. Password or numbers only", "c. Password of spical characters", "d. Password with all"]

    #checking if the length is a number
    while password_length == 0 or password_length < 0:
        try:
            password_length = int(input("Enter password length: "))
        except ValueError:
            password_length = 0

    #seeing what option the user selected
    while password_option == '':
        print("Please choose an option: \n")
        for option in options:
            print(option)

        password_option = input("Enter option: ")
        if is_valid_option(password_option):
            password_option = ''
            continue

        #calling the genorator
        setting_length(password_length)
        setting_option(password_option)
        generate_password()

        break

def is_valid_option(option: chr) -> bool:
    if option == 'a' or option == 'b' or option == 'c' or option == 'd':
        return False
    return True


if __name__ == '__main__':
    main()