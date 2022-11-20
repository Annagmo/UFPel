import java.util.Scanner;
    public class ex27 {

        public static void main(String[] args) throws Exception {
            Scanner ler = new Scanner(System.in);
    
            int notas[]= {100, 50, 20, 10, 5, 2, 1}, res=1, i=0, saque;
            int[] usadas = new int[7];


            System.out.printf("Quanto queres sacar? ");
            saque = ler.nextInt();
            ler.nextLine(); 
            ler.close();

            for(i=0;i<=6;i++){
                usadas[i] = 0;//inicializa usadas
            }

            i=0;

            while(res!=0){
                if(saque-notas[i]>=0){
                    res = saque - notas[i];
                    usadas[i]+=1;
                    saque = res;   
                }
                else
                i++;

            }
            System.out.printf("\n");

            for(i=0;i<=6;i++){
                System.out.printf(notas[i]+ ":" + usadas[i] + "\n" ); }
        
            ler.close();
        }
    }


