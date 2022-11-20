import java.util.Scanner;
    public class ex15 {
        public static void main(String[] args) throws Exception {
            Scanner ler = new Scanner(System.in);

            int n, rev=0; 
            System.out.printf("Informe o numero: "); 
            n = ler.nextInt();
            ler.nextLine(); // esvazia o buffer do teclado

            while(n>999){  
                System.out.printf("Informe o numero de at 3 digitos: "); 
                n = ler.nextInt();
                ler.nextLine(); // esvazia o buffer do teclado
            }

           System.out.printf("Original " + n + '\n');

           while(n != 0) {
                int digito = n % 10;
                rev = rev * 10 + digito; // * 10 pq? pq se no, soma todos os digitos de n num so
                n /= 10;
            }
            System.out.println("Revertido: " + rev);


            ler.close();
        }
    }