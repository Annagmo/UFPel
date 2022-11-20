import java.util.Scanner;
import java.lang.Math;
    public class ex10 {
        public static void main(String[] args) throws Exception {
            Scanner ler = new Scanner(System.in);
            
            int a,b;
            double potencia;

            System.out.printf("Informe a base: ");
            a = ler.nextInt();
            ler.nextLine(); // esvazia o buffer do teclado
    
            System.out.printf("Informe a potencia: ");
            b = ler.nextInt();
            ler.nextLine(); // esvazia o buffer do teclado
       
            potencia = Math.pow(a,b);
       
            System.out.printf("a potencia b : " + potencia+"\n");
            
            ler.close();
        }
    }