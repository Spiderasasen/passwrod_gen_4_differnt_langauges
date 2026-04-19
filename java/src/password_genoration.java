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

    public void genoration(){
        switch(passwordOption){
            case 'a':
                System.out.println("letters only");
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