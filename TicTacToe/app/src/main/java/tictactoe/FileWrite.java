package tictactoe;

import java.io.FileWriter;
import java.io.IOException;

public class FileWrite {

    public void write(int p1, int p2, int ties) {

        try {

            FileWriter w = new FileWriter("game.txt");

            w.write("Final Game Log\n\n");
            w.write("Player 1 Wins: " + p1 + "\n");
            w.write("Player 2 Wins: " + p2 + "\n");
            w.write("Ties: " + ties + "\n");

            w.close();

        } catch (IOException e) {
            System.out.println("File error");
        }
    }
}