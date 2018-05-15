#include <LiquidCrystal.h> 

const byte DETECT_PIN_1   = A2; // detection liee au joueur 1
const byte DETECT_PIN_2   = A3; // detection liee au joueur 2

int val1        = 0;  // tension de reference lorsque l inductance n est pas infliencee 
int val2        = 0;
int valf1       = 0;  // tension mesuree a chaque instant par l arduino
int valf2       = 0;
int score1      = 0;  // score des joueurs
int score2      = 0;
int adc_key_in  = 0;  // valeur des boutons de l ecran LCD

#define btnRIGHT  0
#define btnUP     1
#define btnDOWN   2
#define btnLEFT   3
#define btnSELECT 4
#define btnNONE   5

LiquidCrystal Ecran(8, 9, 4, 5, 6, 7);  // code repris pour le fonctionnement des boutons

int read_LCD_buttons()
{               // read the buttons
    adc_key_in = analogRead(0);       // read the value from the sensor 

    // my buttons when read are centered at these values: 0, 144, 329, 504, 741
    // we add approx 50 to those values and check to see if we are close
    // We make this the 1st option for speed reasons since it will be the most likely result

    if (adc_key_in > 1000) return btnNONE; 

    // For V1.1 us this threshold
    if (adc_key_in < 50)   return btnRIGHT;  
    if (adc_key_in < 250)  return btnUP; 
    if (adc_key_in < 450)  return btnDOWN; 
    if (adc_key_in < 650)  return btnLEFT; 
    if (adc_key_in < 850)  return btnSELECT;  

    return btnNONE;                // when all others fail, return this.
}
 
void setup() //setup du code (prise des valeurs et init* ecran)
{
  pinMode(DETECT_PIN_1, INPUT); // initialisation des pins de detection
  pinMode(DETECT_PIN_2, INPUT);
  
  Ecran.begin(16,2); // initialisation de l interface de l ecran LCD
  Ecran.clear();
  Ecran.setCursor(0,0);
  Ecran.print("Player 1: ");
  Ecran.setCursor(10,0);
  Ecran.print("0");
  Ecran.setCursor(0,1);
  Ecran.print("Player 2: ");
  Ecran.setCursor(10,1);
  Ecran.print("0");

  val1 = analogRead(DETECT_PIN_1); // prise des valeurs de référence des tensions de sortie
  val2 = analogRead(DETECT_PIN_2);
}
/*
sjfj
kdkde
/*
void loop() 
{
     while(score1 < 10 && score2 < 10) // boucle tant que les 2 scors sont en dessous de 10
     {
         valf1 = analogRead(DETECT_PIN_1); // prise des tensions de sortie (varie si une balle passe dans l inductance)
         valf2 = analogRead(DETECT_PIN_2);
   
         if(valf1 < val1 -1) // detection de goal par la joueur 1 
         {
             score1 = score1 +1; 
             Ecran.setCursor(10,0); // score +1 et affichage du score sur l ecran 
             Ecran.print(score1);
             delay(1000); // attente pour eviter un double goal avec une seule balle
         }
   
        if(valf2 < val2 -1) // detection de goal par le joiueur 2
        {
             score2 = score2 +1;
             Ecran.setCursor(10,1);
             Ecran.print(score2);
             delay(1000);
         }
     }  
     if (score1 >= 10) // detection du joueur vainqueur
     {
         Ecran.clear();
         Ecran.setCursor(0,0);
         Ecran.print("Player 1 WIN !!!"); // affichage du joueur vainqueur
         delay(1000);
     }
     if (score2 >= 10)
     {
         Ecran.clear();
         Ecran.setCursor(0,0);
         Ecran.print("Player 2 WIN !!!");
         delay(1000);  
     }
 }
