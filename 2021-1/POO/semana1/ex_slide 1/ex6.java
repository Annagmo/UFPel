package ex;

public class ex6 {

  
    public static void main(String[] args) throws Exception {
        int num = 10;
        double res = 1;

        if (num==0){System.out.println(1);}
        else{
        do{
            res = res * num;
            num--;
        }while(num!=1);
        System.out.println(res);
        }
    }
}  

