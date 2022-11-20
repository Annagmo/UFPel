import java.util.Scanner;
    public class ex19 {
        public static void main(String[] args) throws Exception {
            Scanner ler = new Scanner(System.in);

            int n, soma=0, cont=0, pos=0, neg =0, maior=0, menor=0,pares=0,cont_pares=0; 
            double media=0, media_par=0;
            System.out.printf("Informe o nr: "); 
            n = ler.nextInt();
            ler.nextLine(); // esvazia o buffer do teclado
            while(n!=-1){
                cont+=1;
                soma+=n;
                 media = (float) soma/cont;
                if(n<0)
                    neg+=1;
                else
                    pos+=1;

                if(cont==1){
                    maior = n;
                    menor=n;
                }
                else{
                    if(n>maior)
                        maior = n;
                    else if (n<menor)
                        menor = n;
                }
                if(n%2==0){
                    pares+=n;
                    cont_pares+=1;
                    media_par= pares/cont_pares;
                }
                System.out.printf("Soma:" +soma + "\n"); 
                System.out.printf("Quantidade de nr:" +cont + "\n"); 
                System.out.printf("media:" +media + "\n"); 


                System.out.printf("positivos:" +pos + "\n"); 
                System.out.printf("negativos:" +neg + "\n"); 
                System.out.printf("maior:" +maior + "\n"); 
                System.out.printf("menor:" +menor + "\n"); 
                System.out.printf("media dos nrs pares:" +media_par + "\n"); 


                System.out.printf("\n\nInforme o nr: "); 
                n = ler.nextInt();
                ler.nextLine(); // esvazia o buffer do teclado



            }



            ler.close();
        }
    }