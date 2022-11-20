package ex;

public class ex2 {
  
    public static void main(String[] args) throws Exception {
        int peso = 23;
       if(peso<=0 && peso < 20){System.out.println("Magro");}
       else if (20 <= peso && peso < 25){System.out.println("Normal");}
       else if (25 <= peso && peso < 29){System.out.println("Acima do Peso");}
       else if (29 <= peso && peso < 30){System.out.println("Obeso");}
       else{System.out.println("muito obeso");}


    }
}  
