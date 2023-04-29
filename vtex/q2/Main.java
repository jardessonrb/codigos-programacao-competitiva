package vtex.q2;
import java.util.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import java.io.*;

class Main {

    public static int[] convert(String str){

        Pattern p = Pattern.compile("[0-9]+");
        Matcher m = p.matcher(str);

        List<String> lista = new ArrayList<>();
        while (m.find()) {
            lista.add(m.group().trim());
        }

        int numeros[] = new int[lista.size()];
        for (int i = 0; i < lista.size(); i++) {
            numeros[i] = Integer.parseInt(lista.get(i));
            System.out.print(numeros[i]+" ");
        }

        return numeros;
    }

  public static String PTArithGeo(int[] arr) {

    int diferenca = 0;
    int resto = 0;
    if(arr.length > 1){
        diferenca = arr[1] - arr[0];
        resto = arr[1] % arr[0];
    }

    boolean isAri = true, isGeo = true;

    for (int i = 1; i < arr.length; i++) {
        int calcDif = arr[i] - arr[i - 1];
        int calcRes = arr[i] % arr[i - 1];
        if(calcDif != diferenca){
            isAri = false;
        } 
        if(calcRes != resto){
            isGeo = false;
        }
    }
    
    if((!isAri && !isGeo) || (isAri && isGeo)) {
        return "-1";
    }

    if(isAri && !isGeo){
        return "Arithmetic";
    }

    if(!isAri && isGeo) {
        return "Geometric";
    }

    return "-1";
  }

  public static void main (String[] args) {  
    // keep this function call here     
    Scanner s = new Scanner(System.in);
    System.out.print(PTArithGeo(convert(s.nextLine()))); 
  }

}