import java.util.Scanner;
    public class ex14 {
        public static void main(String[] args) throws Exception {
            Scanner ler = new Scanner(System.in);
            
            double valor, v1, v2, v3; 
            System.out.printf("Informe o valor: ");
            valor = ler.nextInt();
            ler.nextLine(); // esvazia o buffer do teclado

            v1 = 46 * valor/100;
            v2 = 32 * valor/100;
            v3 = valor - v1 - v2;


           System.out.printf("Vencedor 1:" + v1 +"\n");
           System.out.printf("Vencedor 2:" + v2 +"\n");
           System.out.printf("Vencedor 3:" + v3 +"\n");

            ler.close();
        }
    }