import java.util.Scanner;
    public class ex11 {
        public static void main(String[] args) throws Exception {
            Scanner ler = new Scanner(System.in);
            
            int n1, n2, maior=0, menor=0,diferenca=0;
            System.out.printf("Informe o primeiro Número Inteiro: ");
            n1 = ler.nextInt();
            ler.nextLine(); // esvazia o buffer do teclado

            System.out.printf("Informe o segundo Número Inteiro: ");
            n2 = ler.nextInt();
            ler.nextLine(); // esvazia o buffer do teclado
    
           if(n1>n2){
                maior = n1;
                menor = n2;
           }
           else{
            maior = n2;
            menor = n1;
           }
           diferenca = maior-menor;
            System.out.printf("Maior - menor: " + diferenca +"\n");

            ler.close();
        }
    }