import java.util.Scanner;
    public class ex9 {
        public static void main(String[] args) throws Exception {
            Scanner ler = new Scanner(System.in);
            
            int tempo, horas, minutos;
            System.out.printf("Informe o tempo em minutos: ");
            tempo = ler.nextInt();
            horas = tempo / 60;
            minutos = tempo - (horas*60);
    
           
            System.out.printf("horas: " + horas +"\n");
            System.out.printf("minutos: " + minutos+"\n");
       
            ler.close();
        }
    }