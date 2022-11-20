import java.util.Scanner;
    public class ex13 {
        public static void main(String[] args) throws Exception {
            Scanner ler = new Scanner(System.in);
            
            int n1, n2, n3;
            double media; 
            System.out.printf("Informe a primeira nota: ");
            n1 = ler.nextInt();
            ler.nextLine(); // esvazia o buffer do teclado

            System.out.printf("Informe a segunda nota: ");
            n2 = ler.nextInt();
            ler.nextLine(); // esvazia o buffer do teclado

            System.out.printf("Informe a terceira nota: ");
            n3 = ler.nextInt();
            ler.nextLine(); // esvazia o buffer do teclado
    
            media = (n1+n2+n3);
           if(media>=7) 
           System.out.printf("Media: " + media +"\nAPROVADO\n");
           else 
           System.out.printf("Media: " + media +"\nREPROVADO\n");

            ler.close();
        }
    }