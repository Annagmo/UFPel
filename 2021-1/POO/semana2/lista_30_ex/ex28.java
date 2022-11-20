import java.util.Scanner;
    public class ex28 {

        public static void main(String[] args) throws Exception {
            Scanner ler = new Scanner(System.in);
                int a, b;

                System.out.printf("Quais e o primeiro numero: ");
                a = ler.nextInt();
                ler.nextLine(); 

                System.out.printf("Quais e o segundo numero: ");
                b = ler.nextInt();
                ler.nextLine(); 
                ler.close();

                while(b<a){ 
                    System.out.printf("Informe b maior que a: ");  
                    b = ler.nextInt();
                    ler.nextLine();  // esvazia o buffer do teclado
      
                }
      
                int num, i, soma_primo=0, inicio;
                boolean bool_primo;
                inicio = a;

                while(a<2) // para o caso de a<0 || a ==0 || a ==1.
                    a++;

                for (num=a; num<=b; num++) {
                    bool_primo = true;
                    for (i=2; i<num; i++) {
                        if (num % i == 0){bool_primo = false;}    
                    }

                    if (bool_primo == true){soma_primo += num;}
                } 
                    if (soma_primo > 0)
                    System.out.printf("\nA soma dos primos no intervalo [" + inicio +","+ b +"] e: " + soma_primo + "\n");
                    
                    else
                    System.out.printf("\nNao existem primos no intervalo [" + inicio +","+ b +"]");
        }
    }
