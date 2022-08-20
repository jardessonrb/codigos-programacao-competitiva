import java.io.File;
import java.util.Scanner;

public class LimparEXE {

    private static void ListaDiretorios(String path){
        System.out.println(path);
        File dir = new File(path);
        if (dir.exists()) {
            File[] files = dir.listFiles();
            if (files.length > 0) {
                for (int i = 0; i < files.length; i++) {
                    if(files[i].isFile()){
                        String extensao = files[i].getName().replaceAll("^.*\\.(.*)$", "$1");
                        if(extensao.equals("exe")){
                            System.out.println("Removendo arquivo: "+files[i].getName());
                            files[i].delete();
                        }
                    }else if(files[i].isDirectory()){
                        ListaDiretorios(path+"\\"+files[i].getName());
                    }
                }

            } else {
                System.out.println(path + " Diretorio esta vazio!");
            }
        }else {
            System.out.println(path + " Diretorio nao existe!");
        }
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.println("Caminho da pasta: ");
        String file = input.nextLine();
        ListaDiretorios(file);
    }
}