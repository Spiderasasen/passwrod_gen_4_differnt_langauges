import java.util.InputMismatchException;
import java.util.Scanner;
import java.lang.Character;

public class Main {
    public static void main(String[] args) {
        //calling the scanner
        Scanner scan = new Scanner(System.in);

        //calling the genorator
        password_genoration pas = new password_genoration();

        //private vars
        int password_length = 0;
        char password_option;
        String[] options = {"a. Password of letters only", "b. Password or numbers only", "c. Password of spical characters", "d. Password with all"};

        //checking if the number is a number
        while (true){
            System.out.println("Please enter the length of the password: ");
            try{
                password_length = scan.nextInt();
                break;
            }
            catch (InputMismatchException e){
                scan.nextLine();
            }
        }

        //for the option tag
        while (true){
            System.out.println("Please select an option: ");
            for (String option : options){
                System.out.println(option);
            }
            char choice = scan.next().charAt(0);
            choice = Character.toLowerCase(choice);
            if (!(choice == 'a' || choice == 'b' || choice == 'c' || choice == 'd')){
                continue;
            }
            password_option = choice;
            break;
        }

        //calling the setters
        pas.setting_length(password_length);
        pas.set_option(password_option);
    }
}