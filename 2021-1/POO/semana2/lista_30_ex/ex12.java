import java.util.Scanner;
    public class ex12 {
        public static void main(String[] args) throws Exception {
            Scanner ler = new Scanner(System.in);
            
            int n1, n2, maior=0, menor=0;
            boolean multiplo=false;
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
           
           if (maior%menor==0){multiplo = true;}

           if(multiplo)
            System.out.printf(menor+ " é multiplo do: " +maior +"\n");
           else
           System.out.printf(menor+ " não é multiplo do: " +maior +"\n");

           

            ler.close();
        }
    }