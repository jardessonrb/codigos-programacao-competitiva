package lib.java;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class TesteInput {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner scanner = new Scanner(System.in); 

        // while(scanner.hasNext()){
        //     String nome = scanner.next();
        //     int idade = scanner.nextInt();

        //     System.out.println("Sou "+nome+" e tenho "+idade+" de idade");
        // }

        scanner.close();
    }
}
