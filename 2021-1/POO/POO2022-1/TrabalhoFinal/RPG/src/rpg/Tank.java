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
public class Tank extends Personagem{
    
    //CONSTRUTOR
    public Tank(String n, int vit, int arm, int f, int inte, int agi, int sor, int hp, int dMin, int dMax)
    {
        super(n,vit, arm, f, inte, agi, sor, hp, dMin, dMax);
    }
    
    @Override
    public void Bloquear (Personagem p)
    {
        Random rand = new Random();
        
        int bloquear;
        
        bloquear = this.forca + 10;
        p.defesa += bloquear;
    }
    
}
