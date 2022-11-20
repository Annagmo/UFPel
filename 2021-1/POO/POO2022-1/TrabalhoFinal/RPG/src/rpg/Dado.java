/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package rpg;
import java.util.Random;
/**
 *
 * @author Anna
 */
public class Dado extends Personagem {

    private final Random rand;
    private int sorte;
    
    public Dado(){
        this.rand = new Random();
        this.sorte = 1 + rand.nextInt(9);
    }
    switch(sorte)
    {
        case 1 : //upgrade vida
            super.vitalidade += 5;
            System.out.println("Você ganhou 5 de vitalidade"); 
            break;  

        case 2 : //upgrade armadura	
            super.armadura += 3;
            System.out.println("Você ganhou 3 de armadura"); 
            break; 

        case 3 : //upgrade forca
            super.forca += 3;
            System.out.println("Você ganhou 3 de força"); 
            break; 

        case 4 : //upgrade defesa
            super.defesa += 5;
            System.out.println("Você ganhou 5 de defesa"); 
            break;
        
        case 5 : //upgrade mana
            super.manaPoints += 5;
            System.out.println("Você ganhou 5 pontos de Mana"); 
            break;
        
        case 6 : //upgrade dano
            super.danoMinimo += 5;
            System.out.println("Você ganhou 5 de dano!"); 
            break;
            
        case 7 : //donwgrade dano
            if(super.danoMinimo>=5){
            super.danoMinimo -= 5;
            }else{super.danoMinimo=0;}
            
            System.out.println("Você perdeu 5 de dano."); 
            break;

        case 8 : //downgrade vida
            if(super.vitalidade>=5){
            super.vitalidade -= 5;
            }else{super.vitalidade=0;}
            
            System.out.println("Ouch! Enquanto jogava o dado teu inimigo te esfaqueou! Perdeste 3 pontos de vida"); 
            break; 

        case 9 : //downgrade inteligencia
            if(super.inteligencia>=3){
            super.inteligencia -= 3;
            }else{super.inteligencia=0;}
             
            System.out.println("Affe! Enquanto jogava o dado você se distraiu e ele sumiu! Perdeste 3 pontos de inteligência"); 
            break;                              
    }
}
