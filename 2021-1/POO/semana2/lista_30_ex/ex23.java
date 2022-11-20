import java.util.Scanner;
    public class ex23 {

        public static void main(String[] args) throws Exception {
            Scanner ler = new Scanner(System.in);
        
    
            int i,j, n;

            System.out.printf("Informe o nr: ");
            n = ler.nextInt();
            ler.nextLine(); 
        
            while(n<0){  
                System.out.printf("Informe o numero positivo: ");  
                n = ler.nextInt();
                ler.nextLine();  // esvazia o buffer do teclado
  
            }

            ler.close();

            char[][] v = new char[n][n];

            for (i=0;i<n;i++){
                for (j=0;j<n;j++){
                    if(i!=j){v[i][j] = '-';};
                    if(i==j){v[i][j] = '*';};
                }
            }

            for (i=0;i<n;i++){
                for (j=0;j<n;j++){
                    System.out.print(v[i][j]);
                }
                System.out.printf("\n");
            }



        }
    }