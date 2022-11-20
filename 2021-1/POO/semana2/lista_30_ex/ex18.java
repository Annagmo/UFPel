import java.util.Scanner;
    public class ex18 {
        public static void main(String[] args) throws Exception {
            Scanner ler = new Scanner(System.in);

            int km, l, media=0; 
            System.out.printf("Informe a quilometragem: "); 
            km = ler.nextInt();
            ler.nextLine(); // esvazia o buffer do teclado

            System.out.printf("Informe o litro: "); 
            l = ler.nextInt();
            ler.nextLine(); // esvazia o buffer do teclado

            media = km/l;

            if(media <8)
                    System.out.printf("Venda o carro!\n");
            else if(media >=8 && media <=14)
                    System.out.printf("Economico\n");   
            else if(media>14)
                    System.out.printf("Super economico\n");
            

            ler.close();
        }
    }