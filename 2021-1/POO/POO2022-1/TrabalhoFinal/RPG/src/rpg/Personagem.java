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
abstract public class Personagem {   
    //ATRIBUTOS
    
    protected static String nome;
    protected int vitalidade;
    protected int armadura;
    protected int forca;
    protected int inteligencia;
    protected int agilidade;
    protected int sorte;
    protected static int healthPoints;
    protected static int defesa;
    protected static int critico;
    protected static int danoMinimo; 
    protected static int danoMaximo; 

    //CONSTRUTOR
    
    public Personagem (String n, int vit, int arm, int f, int inte, int agi, int sor, int hp, int dMin, int dMax)
    {
        this.nome = n; 
        this.vitalidade = vit;
        this.armadura = arm; 
        this.forca = f;
        this.inteligencia = inte;
        this.agilidade = agi; 
        this.sorte = sor; 
        this.defesa += this.armadura; 
        this.critico = this.sorte / 100; 
        this.healthPoints = hp;
        this.danoMinimo = dMin;
        this.danoMaximo = dMax; 
    }
    
    //SETTERS 
    
    public void setNome (String nome)
    {
        this.nome = nome;
    }
    
    public void setDefesa (int defesa)
    {
        this.defesa = defesa;
    }
    
    public void setCritico (int critico)
    {
        this.critico = critico; 
    }
    
    public void setHealthPoints (int healthPoints)
    {
        this.healthPoints = healthPoints;
    }
    
   
    
    public void setDanoMinimo (int danoMinimo)
    {
        this.danoMinimo = danoMinimo;
    }
    
    public void setDanoMaximo (int danoMaximo)
    {
        this.danoMaximo = danoMaximo; 
    }
    
    //GETTERS
    
    public String getNome ()
    {
        return this.nome;
    }
    
    
    public int getDefesa ()
    {
        return this.defesa;
    }
    
    public int getCritico ()
    {
        return this.critico; 
    }
    
    public int getHealthPoints ()
    {
        return this.healthPoints;
    }
    
    public int getAgilidade ()
    {
        return this.agilidade;
    }
    
    public int getDanoMinimo ()
    {
        return this.danoMinimo;
    }
    
    public int getDanoMaximo ()
    {
        return this.danoMaximo;
    }

    public void Ataque (Personagem p)
    {
        Random rand = new Random();

        int ataque; 

        ataque = rand.nextInt(this.danoMaximo) + this.danoMinimo; 
        p.healthPoints = ataque - p.defesa; 

    }
    
    public void Curar(Personagem p)
    {
        Random rand = new Random();
        
        int cura;
        
        cura = rand.nextInt(this.sorte);
        p.healthPoints += cura; 
    }   
    
    
    public void Bloquear (Personagem p)
    {
        Random rand = new Random();
        
        int bloquear;
        
        bloquear = this.forca + 5;
        p.defesa += bloquear;
    }
    
    public void Esquivar (Personagem p)
    {
        Random rand = new Random();
        
        int esquiva;
        
        esquiva = this.agilidade;
        
        p.defesa += esquiva;
    }

    public void recebeDano (Personagem inimigo ,int ataque)
    {
        this.healthPoints = ataque - defesa;

    }
    
    public void Dado ()
    {
    }
 
}
