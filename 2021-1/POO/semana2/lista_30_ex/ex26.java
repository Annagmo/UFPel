//import java.util.Scanner;
    public class ex26 {

        public static void main(String[] args) throws Exception {
            //Scanner ler = new Scanner(System.in);
        
            double c=1.50, z=1.10; 
            int cont_anos=0;
            
            while(z<=c){
                cont_anos++;
                c += 0.02;
                z += 0.03;
            }
            System.out.printf("Zé será mais alto que Chico em "+ cont_anos + " anos.\n");


        }
    }


