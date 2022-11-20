package ex;

public class ex4 {

  
    public static void main(String[] args) throws Exception {
        int a = 2;
        int b = -5;
        int c = 3;

        int min = Math.min(a,b);
        int min2 = Math.min(min,c);

        System.out.println("O menor dos numeros e: " + min2);
        

        if(a >0 || b > 0 || c > 0){
            System.out.println("\nPositivos: " );
            if(a>0){
                if (b>0){System.out.println("a: " + a + " b: " + b ); }
                else if (c>0){System.out.println("a: " + a + " c: " + c ); }
                else  System.out.println("a: " + a);
            }
            else if(b>0){
                if (a>0){System.out.println("a: " + a + " b: " + b ); }
                else if (c>0){System.out.println("b: " + b + " c: " + c ); }
                else  System.out.println("b: " + b);
            }
            else if(c>0){
                if (a>0){System.out.println("a: " + a + " c: " + c ); }
                else if (b>0){System.out.println("b: " + b + " c: " + c ); }
                else  System.out.println("c: " + c);
            }
        }
        else System.out.println("nao ha elementos positivos");
    }
}  

