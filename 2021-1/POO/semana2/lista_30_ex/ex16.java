import java.util.Scanner;
    public class ex16 {
        public static void main(String[] args) throws Exception {
            Scanner ler = new Scanner(System.in);

            int ano; 
            System.out.printf("Informe o ano: "); 
            ano = ler.nextInt();
            ler.nextLine(); // esvazia o buffer do teclado

            while(ano>9999){  
                System.out.printf("Informe um ano valido: "); 
                ano = ler.nextInt();
                ler.nextLine(); // esvazia o buffer do teclado
            }

            if(ano%400==0 || (ano%4==0 && ano%100!=0)){
                System.out.printf("E um ano bissexto\n");   
            }
            else
            System.out.printf("Nao e um ano bissexto\n");   

            ler.close();
        }
    }