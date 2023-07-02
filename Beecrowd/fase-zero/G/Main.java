import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {

    boolean isNumber(char charar){
        return Character.isDigit(charar);
    }

    public boolean isValido(int pos, String palavra){
        if(Character.isDigit(palavra.charAt(pos))) return true;

        if(palavra.charAt(pos) == ' ' || palavra.charAt(pos) == '.' || palavra.charAt(pos) == ',') return true;

        return false;
    }

    public List<Double> getValores(String palavra){
        List<Double> valores = new ArrayList<>();
        StringBuilder builder = new StringBuilder();

        for (int j = 0; j < palavra.length(); j++) {
            if(isValido(j, palavra)){
                builder.append(palavra.charAt(j));
            }
        }
        palavra = builder.toString();
        builder = new StringBuilder();
        double valor = 0;
        for (int j = 0; j < palavra.length(); j++) {
            if(!Character.isDigit(palavra.charAt(j))){
                if(j + 1 < palavra.length() && !Character.isDigit(palavra.charAt(j+1))){
                    if(!(builder.length() == 0)){
                        valor = Double.parseDouble(builder.toString());
                        valores.add(valor);
                        builder = new StringBuilder();
                        continue;
                    }
                }else if(j + 1 < palavra.length() && Character.isDigit(palavra.charAt(j+1))){
                    continue;
                }

            }else {
                builder.append(palavra.charAt(j));
            }
        }

        if(!(builder.length() == 0)) valores.add(Double.parseDouble(builder.toString()));

        return valores;
    }


    public static void main(String[] args) throws IOException {
        Main main = new Main();
        Scanner scanner = new Scanner(System.in);

        int linhas = Integer.parseInt(scanner.nextLine());

        List<String> palavras = new ArrayList<>();
        
        for (int i = 0; i < linhas; i++) {
            String palavra = scanner.nextLine();
            
            if(!palavra.isEmpty())
                palavras.add(palavra);
        }

        List<Double> valores =  new ArrayList<>();
        for (int i = 0; i < palavras.size(); i++) {
            List<Double> vl =  main.getValores(palavras.get(i));
            valores.addAll(vl);
        }

        if(valores.isEmpty() || valores.size() < 3){
            System.out.println(":)");
        }else {
            int cont = 0;
            for (int i = 1; i < valores.size(); i++) {
                Double sub = valores.get(i) -  valores.get(i - 1);
                if(sub.compareTo(Double.parseDouble("1.0")) == 0){
                    cont++;
                }
            }

            System.out.println(cont >= 2 ? "123" : ":)");
        }
        scanner.close();
    }
}