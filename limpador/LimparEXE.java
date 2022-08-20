import java.io.File;
import java.util.Scanner;

public class LimparEXE {

    private static void ListaDiretorios(String path, String extensao){
        File dir = new File(path);
        if (dir.exists()) {
            File[] files = dir.listFiles();
            if (files.length > 0) {
                for (int i = 0; i < files.length; i++) {
                    if(files[i].isFile()){
                        String extensaoFile = files[i].getName().replaceAll("^.*\\.(.*)$", "$1");
                        if(extensaoFile.equals(extensao)){
                            System.out.println("Removendo arquivo: "+files[i].getName());
                            files[i].delete();
                        }
                    }else if(files[i].isDirectory()){
                        ListaDiretorios(path+"\\"+files[i].getName(), extensao);
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
        System.out.println("Caminho da pasta: (Ex: C:\\ufpi)");
        String file = input.nextLine();
        System.out.println("Digite a extensão para exclusão(Ex: exe ou json): ");
        String extensao = input.nextLine();
        ListaDiretorios(file, extensao);
    }
}