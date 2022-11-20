package ex;


public class ex1 {
    public static void main(String[] args) throws Exception {
        int i,meio_do_caminho=0,boleana=0;      
        int num=2;
        meio_do_caminho=num/2;  

        if(num==0||num==1){  
         System.out.println("\n" + num+" nao e um numero primo");      
        }
        else{  
         for(i=2;i<=meio_do_caminho;i++){      
            if(num%i==0){      
            System.out.println("\n" + num+" nao e um numero primo");      
            boleana=1;      
            break;      
            }      
         }      
         if(boleana==0){ System.out.println("\n" + num+" e um numero primo"); }  
        } 
    }
}
