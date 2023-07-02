// package URI.camisetas1258;

// import java.util.ArrayList;
// import java.util.Collections;
// import java.util.List;
// import java.util.Scanner;

// class Pessoa implements Comparable<Pessoa> {
//     public String nome;
//     public String cor;
//     public Character tamanho;

//     public Pessoa(String n, String c, Character t){
//         this.nome = n;
//         this.cor  = c;
//         this.tamanho = t;
//     }

//     @Override
//     public int compareTo(Pessoa p) {
//         if(p.cor.compareTo(cor) > 0) return 1;

//         if(p.cor.compareTo(cor) == 0 && p.tamanho < tamanho) return 1;

//         if(p.cor.compareTo(cor) == 0 && p.tamanho == tamanho && p.nome.compareTo(nome) > 0) return 1;

//         return -1;
//     }
// }

// public class Main {

//     public static void main(String[] args) {
        
//         while(true){
//             Scanner scanner = new Scanner(System.in);
//             int casos = Integer.parseInt(scanner.next());
//             List<Pessoa> pessoas = new ArrayList<>();

//             if(casos == 0) break;

//             boolean isPar = true;
//             String nome = "", cor = "";
//             Character tamanho;
//             for (int i = 0; i < (casos * 2); i++) {
//                 if(isPar){
//                     nome = scanner.nextLine();
//                     isPar = false;
//                 }else {
//                     isPar = true;
//                     String  line = scanner.nextLine();
//                     String spliters[] = line.split(" ");
//                     cor = spliters[0];
//                     tamanho = spliters[1].charAt(0);

//                     System.out.println(nome+" "+cor+" "+tamanho);

//                     Pessoa pessoa = new Pessoa(nome, cor, tamanho);

//                     pessoas.add(pessoa);
//                 }
//             }

//             scanner.close();

//             Collections.sort(pessoas);

//             pessoas.forEach(pessoa -> {
//                 System.out.println(String.format("%s %c %s", pessoa.cor, pessoa.tamanho, pessoa.nome));
//             });

//             System.out.println();
//         }
//     }
// }
