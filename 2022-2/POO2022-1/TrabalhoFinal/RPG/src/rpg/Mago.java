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
public class Mago extends Personagem{
    //ATRIBUTOS 
    public static int manaPoints; 
    
    //CONSTRUTOR
    public Mago(String n, int vit, int arm, int f, int inte, int agi, int sor, int hp, int dMin, int dMax, int mp)
    {
        super(n,vit, arm, f, inte, agi, sor, hp, dMin, dMax);
        this.manaPoints = mp;
    }
    
    //SETTERS
    
     public void setManaPoints (int manaPoints)
    {
        this.manaPoints = manaPoints;
    }
     
     //GETTERS
     
     public int getManaPoints ()
    {
        return this.manaPoints; 
    }
     
     @Override
     public void Ataque (Personagem p)
    {
        Random rand = new Random();

        int ataque; 

        ataque = rand.nextInt(this.danoMaximo) + this.danoMinimo + this.manaPoints; 
        p.healthPoints = ataque - p.defesa; 

    }
    
}
