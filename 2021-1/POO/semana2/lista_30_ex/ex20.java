import java.util.Scanner;
    public class ex20 {

        public static void main(String[] args) throws Exception {
            Scanner ler = new Scanner(System.in);
            ex20 instancia = new ex20(); // instancia serve para poder utilizar um metodo nao estatico dentro do main que e estatico

            int n;
            System.out.printf("Informe o nr: "); 
            n = ler.nextInt();
            ler.nextLine(); // esvazia o buffer do teclado


            
            System.out.println("\nS: " + instancia.Serie(n));
            ler.close();
        }


        double Serie(int n)
        {
            int i, cont=0;
            double somatorio = 0.0, monomio;
            for(i = 1; i <= n; ++i)
            {
                monomio = 1 / Math.pow(i, 2); //monomio e a fraçao individual no conjunto da sequencia
                System.out.println("S"+cont + ": " + monomio); // isso daqui  para printar o resultado de cada fraçao, para ficar mais visual

                somatorio += monomio;
                cont+=1;
            }
            return somatorio;
        }
    }