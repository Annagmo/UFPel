/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package rpg;
        
import java.util.Scanner;
import java.util.Random; 

/**
 *
 * @author Lucas
 */
public class RPG {

    /**
     * @param args the command line arguments
     */ 
    static Scanner scanf = new Scanner(System.in);
    static Random  rand  = new Random();
    static int classe;
    static Personagem jogador;
    static Personagem inimigo;

    public static void main(String[] args)
    {
    	Introducao();
        Inimigo();
    	telaPersonagem();
    	chamaTurno();
    	jogadorTurno();
    	cpuTurno();
    	vitoria();

    }

    public static void Introducao ()
    {
    	System.out.println("SEJA BEM-VINDO A ARENA. DIGA SEU NOME: "); 
        // String name = input.next();
    	jogador.setNome("LUCAS"); 
    	inimigo.setNome("LUCASdoMAU"); 
        System.out.println("ESCOLHA A SUA CLASSE: "); 
        System.out.println("1- Mago "); 
        System.out.println("2 - Guerreiro"); 
        System.out.println("3 - Healer");  
        System.out.println("4 - Tank"); 
        int escolha = scanf.nextInt(); 
      
        switch(escolha)
        {
            case 1 : 
                jogador = new Mago("Lucas", 10, 10, 5, 15, 10, 10, 10, 10, 100, 20); //str name
                break;
            case 2 : 
                jogador = new Guerreiro("Lucas",10, 15, 15, 5, 8, 10, 10, 25, 100); //str name
                break;
            case 3 : 
                jogador = new Healer("Lucas", 15, 10, 3, 15, 10, 10, 10, 100, 80); //str name
                break;
            case 4 : 
                jogador = new Tank("Lucas", 30, 20, 5, 5, 8, 10, 10, 10, 50); //str name
                break;
        }
    	
    }

    public static void Inimigo(){ //a ordem é: vital, armad, forc, intel, agil, sorte, healthP, danoMin, danoMax
        classe = 1 + rand.nextInt(3);    
        if(classe==1){
            inimigo = new Mago("Inimigo", 10, 10, 5, 15, 10, 10, 10, 10, 100, 20); // , manaP
        }
        if(classe==2){
            inimigo = new Guerreiro("Inimigo",10, 15, 15, 5, 8, 10, 10, 25, 100);
        }
        if(classe==3){
            inimigo = new Healer("Inimigo", 15, 10, 3, 15, 10, 10, 10, 100, 80);
        }
        else{
            inimigo = new Tank("Inimigo", 30, 20, 5, 5, 8, 10, 10, 10, 50);
        }
        
    }
    
    
    public static void telaPersonagem() // MOSTRA A TELA COM INFORMAÇÕES DOS PERSONAGENS 
    {
    	System.out.println("NOME: " + jogador.getNome() + "					    NOME:" + inimigo.getNome());
		System.out.println("HP: " + jogador.getHealthPoints() + "				HP: "  + inimigo.getHealthPoints());
		System.out.println("MP: " + jogador.getManaPoints() + "					MP: "  + inimigo.getManaPoints());

    }

    public static void chamaTurno() 
    {

    	int jogadorAgi; 
    	int cpuAgi; 

    	do
    	{

    	jogadorAgi = rand.nextInt(1) + jogador.getAgilidade(); 
    	cpuAgi = rand.nextInt(1) + inimigo.getAgilidade(); 

    		if(jogadorAgi > cpuAgi)
    		{
    			jogadorTurno(); 

    		} else
    		{


    		}

    	} while(jogadorAgi != cpuAgi);

    }

    public static void jogadorTurno()
    {
    	int acao; 

    	do
    	{

    		System.out.println("SEU TURNO"); 
    		System.out.println(""); 
    		System.out.println("Escolha uma acao"); 
    		System.out.println("1 - Atacar");  
                System.out.println("2 - Teste sua sorte, gire o dado");
                System.out.println("3 - Curar");
                System.out.println("4 - Bloquear");
                System.out.println("5 - Esquivar");
    		acao = scanf.nextInt(); 
    		switch(acao)
    		{
    			case 1 : 
    				jogador.Ataque(inimigo);
    				System.out.println("Ataque realizado com sucesso"); 
                                telaPersonagem();
    				chamaTurno(); 
    				break; 
                                
                        case 2 : 
    				jogador.Dado(); 
                                telaPersonagem();
    				chamaTurno(); 
    				break; 
                                
                        case 3 : 
    				jogador.Curar(jogador); 
                                telaPersonagem();
    				chamaTurno(); 
    				break;
                                
                        case 4 : 
    				jogador.Bloquear(jogador); 
                                telaPersonagem();
    				chamaTurno(); 
    				break;
                                
                        case 5 : 
    				jogador.Esquivar(jogador); 
                                telaPersonagem();
    				chamaTurno(); 
    				break;
                                
    			default : 
    				System.out.println("Digite um comando valido"); 
    		}	

    	} while(jogador.healthPoints != 0 || jogador.healthPoints < 0); 

    }

    public static void cpuTurno()
    {
    	int acao; 

    	acao = rand.nextInt(1) + 3;

    	System.out.println("TURNO INIMIGO"); 

    	do
    	{
    		switch (acao)
    		{
    			case 1:
    				inimigo.Ataque(jogador); 
    				System.out.println("Você e atacado com sucesso"); 
    				chamaTurno();
    				break;

    			case 2: 
    				inimigo.Ataque(jogador); 
    				System.out.println("Você e atacado com sucesso"); 
    				chamaTurno(); 
    				break;

    			case 3:
    				inimigo.Ataque(jogador); 
    				System.out.println("Você e atacado com sucesso");  
    				break;
    		}
    	} while(inimigo.healthPoints != 0 || inimigo.healthPoints <= 0);

    }

    public static void vitoria()
    {
    	if(jogador.healthPoints == 0)
    	{
    		System.out.println("voce perdeu!");
    	}

    	if(inimigo.healthPoints == 0)
    	{
    		System.out.println("voce venceu!");
    	}
    }
    
}
    
    

