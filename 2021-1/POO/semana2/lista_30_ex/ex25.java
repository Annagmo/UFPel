import java.util.Scanner;
    public class ex25 {

        public static void main(String[] args) throws Exception {
            Scanner ler = new Scanner(System.in);
        
            int op=0; 
            double v = 0.0;

            while (op!=3){
                System.out.printf("\nBem vindo ao menu de conversao de velocidades!: \n");
                System.out.printf("Opçoes: \n");
                System.out.printf("1:\t Km/h ---> m/s: \n");
                System.out.printf("2:\t m/s ---> Km/h: \n");
                System.out.printf("3:\t Sair \n");
                System.out.printf("Digite: ");
                op = ler.nextInt();
                ler.nextLine(); 
                switch(op) {
                case 1:
                    System.out.printf("Digite o valor a ser transformado (,): ");
                    v = ler.nextDouble();
                    ler.nextLine(); 
                    System.out.printf("\nEm m/s:" + v/3.6 + "\n");
                    break;
                case 2:
                    System.out.printf("Digite o valor a ser transformado (,) : ");
                    v = ler.nextDouble();
                    ler.nextLine(); 
                    System.out.printf("\nEm km/h:" + v*3.6 + "\n");
                    break;
                case 3:
                break;

                default:
                System.out.printf("\n\nOPCAO INVALIDA!\n");

               }
               
            }
            ler.close();

        }
    }


