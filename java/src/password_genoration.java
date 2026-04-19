import java.util.ArrayList;
import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;

public class password_genoration {
    private int passwordLength = 0;
    private char passwordOption;
    private String password;

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

    public void genoration(){
        switch(passwordOption){
            case 'a':
                System.out.println("letters only");
                ArrayList<Character> list = opening_files("data/alphabet.txt");
                System.out.println(list);
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