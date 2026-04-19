import java.util.ArrayList;
import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Random;

public class password_genoration {
    private int passwordLength = 0;
    private char passwordOption;
    private String password = "";

    //setters
    public void setting_length(int passwordLength){
        this.passwordLength = passwordLength;
    }
    public void set_option(char passwordOption){
        this.passwordOption = passwordOption;
    }

    private ArrayList<Character> opening_files(String file) {
        ArrayList<Character> list = new ArrayList<>();

        try (Scanner fileReader = new Scanner(new File(file))) {
            while (fileReader.hasNextLine()) {
                String line = fileReader.nextLine().trim();
                if (!line.isEmpty()) {
                    list.add(line.charAt(0));
                }
            }
        } catch (FileNotFoundException ex) {
            System.out.println("File not found: " + file);
        }

        return list;
    }

    private String new_password(String password, int passwordLength, ArrayList<Character> list) {
        Random rand = new Random();
        StringBuilder passwordBuilder = new StringBuilder(password);
        for (int i = 0; i < passwordLength; i++) {
            int index = rand.nextInt(list.size());
            passwordBuilder.append(list.get(index));
        }
        password = passwordBuilder.toString();
        return password;
    }

    private String making_password(String password, int passwordLength, String file){
        ArrayList<Character> list = opening_files(file);
        return password = new_password(password, passwordLength, list);
    }

    public void genoration(){
        switch(passwordOption){
            case 'a':
                System.out.println("letters only");

                password = making_password(password, passwordLength, "data/alphabet.txt");
                System.out.println("Your password: " + password);

                break;
            case 'b':
                System.out.println("numbers only");

                password = making_password(password, passwordLength, "data/numbers.txt");
                System.out.println("Your password: " + password);

                break;
            case 'c':
                System.out.println("special only");

                password = making_password(password, passwordLength, "data/special.txt");
                System.out.println("Your password: " + password);

                break;
            case 'd':
                System.out.println("all sections");

                Random rand = new Random();

                ArrayList<Character> leters = opening_files("data/alphabet.txt");
                ArrayList<Character> numbers = opening_files("data/numbers.txt");
                ArrayList<Character> specials = opening_files("data/special.txt");

                for(int i = 0; i < passwordLength; i++){
                    int number = rand.nextInt(1, 4);
                    switch(number){
                        case 1:
                            password = new_password(password, 1, leters);
                            break;
                        case 2:
                            password = new_password(password, 1, numbers);
                            break;
                        default:
                            password = new_password(password, 1, specials);
                    }
                }

                System.out.println("Your password: " + password);

                break;
        }
    }
}