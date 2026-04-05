package tictactoe;

public class TicTacToe {

    public String[] game = {"1","2","3","4","5","6","7","8","9"};
    public String[] reset = {"1","2","3","4","5","6","7","8","9"};
    public boolean win1 = false;
    public boolean win2 = false;
    public boolean tie = false;
    public boolean input = true;

    public void board() {
        
        for(int i = 0;i < 9;i++){

            System.out.print("  " + game[i] + "  ");

            if(i != 2 && i != 5 && i != 8){ 
                System.out.print("|");
            }
            
            if (i == 2 || i == 5) {
                System.out.println("\n-----+-----+------");
                
            }   
        }  
    } 

    public void resetGame() {
        for(int i = 0; i < 9; i++){
            game[i] = Integer.toString(i + 1);
        }
        win1 = false;
        win2 = false;
        tie = false;
        input = true;
    }

    int playerOne(int x){
        game[x - 1] = "X"; 
        return 0;
    }

    int playerTwo(int x){
        game[x - 1] = "O";
        return 0;
    }

    void inputCheck(int x){   
        if (x < 1 || x > 9 || game[x - 1].equals("X") || game[x - 1].equals("O")) {
            input = false;
        }
        else{
            input = true;
        }
    }

    void checkOne(){

        for(int i = 0; i < 9; i++){
            if(i == 0 || i == 1 || i == 2){
                if(game[i].equals("X") && game[i + 3].equals("X") && game[i + 6].equals("X")){
                    win1 = true;
                }
            }
            if(i == 0 || i == 3 || i == 6){
                if(game[i].equals("X") && game[i + 1].equals("X") && game[i + 2].equals("X")){
                    win1 = true;
                }
            }
            if(i == 0){
                if(game[0].equals("X") && game[4].equals("X") && game[8].equals("X")){
                    win1 = true;
                }
            }
            if(i == 2){
                if(game[2].equals("X") && game[4].equals("X") && game[6].equals("X")){
                    win1 = true;
                }
            }
        }
    }

    void checkTwo(){

        for(int i = 0; i < 9; i++){
            if(i == 0 || i == 1 || i == 2){
                if(game[i].equals("O") && game[i + 3].equals("O") && game[i + 6].equals("O")){
                    win2 = true;
                }
            }
            if(i == 0 || i == 3 || i == 6){
                if(game[i].equals("O") && game[i + 1].equals("O") && game[i + 2].equals("O")){
                    win2 = true;
                }
            }
            if(i == 0){
                if(game[0].equals("O") && game[4].equals("O") && game[8].equals("O")){
                    win2 = true;
                }
            }
            if(i == 2){
                if(game[2].equals("O") && game[4].equals("O") && game[6].equals("O")){
                    win2 = true;
                }
            }
        }
    }

    void checkTie(){
        int count = 0;
        
        for(int i = 0; i < 9; i++){
            if(game[i].equals("X") || game[i].equals("O")){
                count++;
            }
        }

        if (count == 9 && win1 == false && win2 == false){
            tie = true;
        }
    }
}