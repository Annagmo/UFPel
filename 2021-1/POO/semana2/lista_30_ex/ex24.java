import java.util.Scanner;
    public class ex24 {

        public static void main(String[] args) throws Exception {
            Scanner ler = new Scanner(System.in);
        
            int i,j,k=1,n, qtd_dias;
            int[][] v = new int[6][7]; //um calendario pode ter ate 6 linhas, e os 7 dias da semana

 
            System.out.printf("Em qual dia da semana começa o mes?: \n");

            System.out.printf("1-Domingo\n");
            System.out.printf("2-Segunda\n");
            System.out.printf("3-Terça\n");
            System.out.printf("4-Quarta\n");
            System.out.printf("5-Quinta\n");
            System.out.printf("6-Sexta\n");
            System.out.printf("7-Sábado\n");

            System.out.printf("\nDigite:");
            n = ler.nextInt();
            ler.nextLine(); 

            while(n<0|| n>7){  //apenas aceita 7 dias
                System.out.printf("Informe entre 1 e 7: ");  
                n = ler.nextInt();
                ler.nextLine();  // esvazia o buffer do teclado
  
            }
        
            System.out.printf("\nQuantos dias o mes possui?:");
            qtd_dias = ler.nextInt();
            ler.nextLine(); 

            while(n<0|| n>31){  //apenas aceita 31 dias do mes
                System.out.printf("Informe entre 1 e 31: ");  
                qtd_dias = ler.nextInt();
                ler.nextLine();  // esvazia o buffer do teclado
  
            }

            ler.close();

            n=n-1; //a matriz começa em 0, entao o n=1 domingo e na verdade n = 0.

            for (i=0;i<6;i++){ //inicializa a matriz com 0s
                for (j=0;j<7;j++){
                    v[i][j] = 0;
                }
            }

            for (i=0;i<6;i++){
                for (j=0;j<7;j++){
                    if(i==0){ // se estamos na primeira linha
                        while(n!=7){ // a primeira linha vale ate o final da semana
                            v[0][n] = k; // preenche na posicao que comeca o mes
                            n++; //vai aumentando as posicoes da primeira semana
                            k++; //contagem dos dias
                            }
                        }
                    else{
                            if(k>=(qtd_dias+1)){ //apenas os dias validos
                                break;
                            }
                        else {
                        v[i][j] = k; 
                        k++; //continua a contagem dos dias
                        }
                    }
                }
            }
            
            System.out.printf("D\tS\tT\tQ\tQ\tS\tS\n\n");

            for (i=0;i<6;i++){
                for (j=0;j<7;j++){
                    System.out.print(v[i][j]);
                    System.out.printf("\t");  //para ficar alinhado
                }
                System.out.printf("\n"); //proxima linha do calendario
            }


        }
    }


