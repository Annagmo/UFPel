/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package rpg;

import java.util.Random;

/**
 *
 * @author Lucas
 */
public class Guerreiro extends Personagem{
    
    //CONSTRUTOR
    public Guerreiro(String n, int vit, int arm, int f, int inte, int agi, int sor, int hp, int dMin, int dMax)
    {
        super(n,vit, arm, f, inte, agi, sor, hp, dMin, dMax);
    }
    
    
     @Override
     public void Ataque (Personagem p)
    {
        Random rand = new Random();

        int ataque; 

        ataque = rand.nextInt(this.danoMaximo) + this.danoMinimo + this.forca; 
        p.healthPoints = ataque - p.defesa; 

    } 
}
