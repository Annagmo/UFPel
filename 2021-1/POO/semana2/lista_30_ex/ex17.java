import java.util.Scanner;
    public class ex17 {
        public static void main(String[] args) throws Exception {
            Scanner ler = new Scanner(System.in);

            int n; 
            System.out.printf("Informe o nr: "); 
            n = ler.nextInt();
            ler.nextLine(); // esvazia o buffer do teclado

            if(n%3==0 || n%5==0 ){
                if (n%3==0 && n%5==0)
                    System.out.printf("");
                else if(n%3==0 || n%5!=0)
                    System.out.printf("E divisivel por 3\n");   
                else if(n%3!=0 || n%5==0)
                    System.out.printf("E divisivel por 5\n");
            }
            else
            System.out.printf("Nao e divisivel nem por 3 nem por 5\n");

            ler.close();
        }
    }