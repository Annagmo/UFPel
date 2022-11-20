import java.util.Scanner;
    public class ex21 {

        public static void main(String[] args) throws Exception {
            Scanner ler = new Scanner(System.in);

            int dividendo, num=2, res=0;
            System.out.printf("Informe o nr: "); 
            dividendo = ler.nextInt();
            ler.nextLine(); // esvazia o buffer do teclado

            while(res!=1){
                if(dividendo%num!=0)
                num+=1;
                else{
                    res = dividendo/num;
                    System.out.printf(dividendo + "|" + num+ "\n"); 
                    dividendo = res;
                    
                }

            }
            if (res==1)
                System.out.printf(res + "\n" ); 
        
            ler.close();
        }
    }

