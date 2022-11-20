import java.util.Scanner;
public class ex8 {
    public static void main(String[] args) throws Exception {
        Scanner ler = new Scanner(System.in);
        
        int n1, n2, n3, n4, n5, soma,minimo, maximo;
        System.out.printf("Informe o primeiro Número Inteiro: ");
        n1 = ler.nextInt();
        ler.nextLine(); // esvazia o buffer do teclado

        System.out.printf("Informe o segundo Número Inteiro: ");
        n2 = ler.nextInt();
        ler.nextLine(); // esvazia o buffer do teclado

        System.out.printf("Informe o terceiro Número Inteiro: ");
        n3 = ler.nextInt();
        ler.nextLine(); // esvazia o buffer do teclado

        System.out.printf("Informe o quarto Número Inteiro: ");
        n4 = ler.nextInt();
        ler.nextLine(); // esvazia o buffer do teclado

        System.out.printf("Informe o quinto Número Inteiro: ");
        n5 = ler.nextInt();
        ler.nextLine(); // esvazia o buffer do teclado
        soma = n1 + n2 + n3 + n4 +n5;
        System.out.printf("A soma é: " + soma+"\n");
        System.out.printf("A média é: " + soma/5+"\n");
        minimo = minimo(n1, n2, n3, n4, n5);
        System.out.printf("minimo: " + minimo+"\n");

        maximo = maximo(n1, n2, n3, n4, n5);
        System.out.printf("maximo: " + maximo+"\n");
        ler.close();
    }

        
        public static int minimo(int n1, int n2, int n3, int n4, int n5) {
            if (n1 > n2)
                if(n2>n3)
                    if(n3>n4)
                        if(n4>n5)
                            return n5; // ordem 1-2-3-4-5
                        else
                            return n4; // ordem 1-2-3-5-4
                    else{ // ordem : n1 > n2 > n4 ... n3 Vs n5
                        if(n3>n5)
                            return n5; // ordem 1-2-4-3-5
                        else
                            return n3; //ordem 1-2-4-5-3
                    }
                else{ // ordem : n1 > n3  ... n2 Vs n4 Vs n5
                    if(n2>n4)
                        if(n4>n5)
                            return n5; // ordem 1-3-2-4-5
                        else
                            return n4; // ordem 1-3-2-5-4
                    else{
                        if(n2>n5)
                            return n5; // ordem 1-3-4-2-5 
                        else
                            return n2; // ordem 1-3-4-5-2
                    }
                }
            else{ //n2> n1
                if(n1>n3) //2-1
                    if(n3>n4)
                        if(n4>n5)
                            return n5; // ordem 2-1-3-4-5
                        else
                            return n4; // ordem 2-1-3-5-4
                    else{ // ordem : n2 > n1 > n4 ... n3 Vs n5
                        if(n3>n5)
                            return n5; // ordem 2-1-4-3-5
                        else
                            return n3; //ordem 2-1-4-5-3
                    }
                else{ // ordem : 2-3
                    if(n1>n4)
                        if(n4>n5)
                            return n5; // ordem 2-3-1-4-5
                        else
                            return n4; // ordem 2-3-1-5-4
                    else{
                        if(n1>n5)
                            return n5; // ordem 2-3-4-1-5 
                        else
                            return n1; // ordem 2-3-4-5-1
                    }
                }
            }    
        }
    
        public static int maximo(int n1, int n2, int n3, int n4, int n5) { 
            // tu pega toda a dor de cabeça do minimo e inverte todos os sinais. pronto. Máximo.
            if (n1 < n2)
            if(n2<n3)
                if(n3<n4)
                    if(n4<n5)
                        return n5; 
                    else
                        return n4; 
                else{
                    if(n3<n5)
                        return n5; 
                    else
                        return n3; 
                }
            else{ 
                if(n2<n4)
                    if(n4<n5)
                        return n5; 
                    else
                        return n4;
                else{
                    if(n2<n5)
                        return n5; 
                    else
                        return n2; 
                }
            }
        else{ 
            if(n1<n3) 
                if(n3<n4)
                    if(n4<n5)
                        return n5;
                    else
                        return n4; 
                else{
                    if(n3<n5)
                        return n5; 
                    else
                        return n3; 
                }
            else{
                if(n1<n4)
                    if(n4<n5)
                        return n5;
                    else
                        return n4; 
                else{
                    if(n1<n5)
                        return n5; 
                    else
                        return n1; 
                }
            }
        }    
    }

    }

