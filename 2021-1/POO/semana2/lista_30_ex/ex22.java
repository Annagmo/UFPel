import java.util.Scanner;
    public class ex22 {

        public static void main(String[] args) throws Exception {
            Scanner ler = new Scanner(System.in);
        
            int[] v = new int[10];
            String str_n;
            int i, n;

            System.out.printf("Informe o nr: ");
            n = ler.nextInt();
            ler.nextLine(); 
        
            while(n>10000){  
                System.out.printf("Informe o numero ate 10mil: ");  
                n = ler.nextInt();
                ler.nextLine();  // esvazia o buffer do teclado
  
            }
            ler.close();
            str_n = Integer.toString(n);

            for (i=0; i<v.length; i++){//inicializa a array
                v[i]=0;
            }

            for (i=0; i<str_n.length(); i++){
                if(str_n.charAt(i)=='0'){v[0]++;}
                else if(str_n.charAt(i)=='1'){v[1]+=1;}
                else if(str_n.charAt(i)=='2'){v[2]+=1;}
                else if(str_n.charAt(i)=='3'){v[3]+=1;}
                else if(str_n.charAt(i)=='4'){v[4]+=1;}
                else if(str_n.charAt(i)=='5'){v[5]+=1;}
                else if(str_n.charAt(i)=='6'){v[6]+=1;}
                else if(str_n.charAt(i)=='7'){v[7]+=1;}
                else if(str_n.charAt(i)=='8'){v[8]+=1;}
                else if(str_n.charAt(i)=='9'){v[9]+=1;}
            }

            for (i=0; i<v.length; i++){//inicializa a array
                if(v[i]!=0){
                    System.out.printf(i + ": " + v[i] + '\n');
                }
            }
        

        }
    }