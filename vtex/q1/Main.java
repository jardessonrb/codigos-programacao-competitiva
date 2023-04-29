package vtex.q1;
import java.util.*; 
import java.io.*;


class Main {

  public static String PTLetterCount(String str) {
    List<Map<Character, Integer>> contagem = new ArrayList<>();
    
    String palavras[] = str.split(" ");

    for (int i = 0; i < palavras.length; i++) {
        Map<Character, Integer> contagemPalavra = new HashMap<>();
        for (int j = 0; j < palavras[i].length(); j++) {
            if(contagemPalavra.containsKey(palavras[i].charAt(j))){
                contagemPalavra.replace(palavras[i].charAt(j), contagemPalavra.get(palavras[i].charAt(j)) + 1);
            }else {
                contagemPalavra.put(palavras[i].charAt(j), 1);
            }
        }

        contagem.add(contagemPalavra);
    }

    int max = 0;
    int index = -1;
    for (int i = 0; i < contagem.size(); i++) {
        Integer cont = 0;
        for (Integer valor : contagem.get(i).values().stream().toList()) {
            if(valor > 1) {
                cont++;
            }
        }

        if(cont > max){
            index = i;
            max = cont;
        }
        
    }

    if(index < 0){
        return "-1";
    }

    return palavras[index];
  }

  public static void main (String[] args) {  
    // keep this function call here     
    Scanner s = new Scanner(System.in);
    System.out.print(PTLetterCount(s.nextLine())); 
  }

}