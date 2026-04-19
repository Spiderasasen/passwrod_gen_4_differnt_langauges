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

    public void genoration(){
        switch(passwordOption){
            case 'a':
                System.out.println("letters only");

                //opening a file
                ArrayList<Character> list = opening_files("data/alphabet.txt");

                password = new_password(password, passwordLength, list);

                System.out.println(password);

                break;
            case 'b':
                System.out.println("numbers only");
                break;
            case 'c':
                System.out.println("special only");
                break;
            case 'd':
                System.out.println("all sections");
                break;
        }
    }
}