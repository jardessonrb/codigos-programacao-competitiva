import java.io.IOException;
import java.util.Collections;
import java.util.Scanner;
import java.util.Vector;


class Piloto implements Comparable<Piloto> {
    
    public Vector<Long> tempoVoltas;
    public int numero;
    public Long total;
    public long melhorVoltaPiloto;

    public Piloto(int numero){
        this.numero = numero;
        this.tempoVoltas = new Vector<>();
        this.total = 0L;
        this.melhorVoltaPiloto = Long.MAX_VALUE;
    }
    
    public void add(Long temp){
        this.tempoVoltas.add(temp);
        this.total += temp;
        atualizar(temp);
    }

    public void atualizar(Long tempo){
        if(tempo < this.melhorVoltaPiloto){
            this.melhorVoltaPiloto = tempo;
        }
    }

    public Long getTotal(){
        return this.total;
    }

    @Override
    public int compareTo(Piloto o) {
        
        return this.total.compareTo(o.total);
    }
}

public class Main {

    public Vector<Piloto> pilotos = new Vector<>();
    public static long melhorVolta = Long.MAX_VALUE;
    public static long tempoMelhorVolta = 0;
    public static int piloto = 0;
    public static int voltaCorrida = 1001;

    public void atualizaTempo(Long tempo, Integer piloto, Integer volta, long voltaCalc){
        if(tempo <= melhorVolta){
            this.melhorVolta = tempo;
            if(voltaCalc < tempoMelhorVolta){
                this.piloto = piloto;
                this.voltaCorrida = volta;
                this.tempoMelhorVolta = voltaCalc;
            }
        }
    }

    public boolean isMelhorVolta(long volta){
        return volta < melhorVolta;
    }

    public void atualizaTempo(Piloto piloto){
        long calc = 0;
        for (int i = 0; i < piloto.tempoVoltas.size(); i++) {
            long tempo = piloto.tempoVoltas.get(i);
            calc += tempo;
            if(isMelhorVolta(tempo)){
                atualizaTempo(tempo, piloto.numero, i + 1, calc);
            }
        }
    }
    
    public static void main(String[] args) throws IOException {
        Scanner input = new Scanner(System.in);

        int N = input.nextInt();
        int V = input.nextInt();
        Main k = new Main();

        for (int j = 0; j < N; j++) {
            int pi = input.nextInt();
            int i = 0;
            Piloto  piloto = new Piloto(pi);
            while(i < V){
                String volta = input.next();
                String split[] = volta.replaceAll("\\s+","").split(":");
                Long voltaLong = (Long.parseLong(split[0]) * 60 * 1000) + (Long.parseLong(split[1]) * 1000) + Long.parseLong(split[2]);
                piloto.add(voltaLong);

                i++;
            }

            k.atualizaTempo(piloto);
            k.pilotos.add(piloto);
        }

        input.close();  
        Collections.sort(k.pilotos);
        int cont = 0;
        for (int i = 0; i < 10; i++) {
            if(k.pilotos.get(i).melhorVoltaPiloto == melhorVolta){
                cont++;
            }
        }

        if(cont >= 1){
            System.out.print(piloto);
        }else {
            System.out.print("NENHUM");
        }
    }
}
