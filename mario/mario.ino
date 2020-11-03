  //#include <LiquidCrystal.h> 
#include "pitches.h"
/*
Intro e,e,,e,c,e,g

C G E
A B A# A 
G E G A F G
E C D B
*/
#define REST     1
int speakerpin = 6;
//LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
byte newChar[8] = { B00000, B01111, B01001, B01001, B01011, B11011, B11000, B00000 };
int Row = 0;
int Col = 0;


// notes in the intro:
int Intro_melody[] = {
  NOTE_E4, NOTE_E4, REST, NOTE_E4, 
  REST, NOTE_C4, NOTE_E4, REST,
  NOTE_G4, REST, REST, NOTE_G3, REST
};

int Intro_Notes[] = {
  4, 4, 4, 4,
  4, 4, 4, 4,
  4, 2, 4, 2, 2
};

const int num_elements_in_Intro = sizeof(Intro_Notes)/sizeof(Intro_Notes[0]);

// notes in the melody:
int Mario_melody[] = {
  NOTE_C4, REST, REST, NOTE_G3,
  REST, NOTE_E3, REST,
  REST, NOTE_A3, REST, NOTE_B3,   
  REST, NOTE_AS3, NOTE_A3, REST,
  
  NOTE_G3, NOTE_E4, NOTE_G4,
  NOTE_A4, REST, NOTE_F4, NOTE_G4, 
  REST, NOTE_E4, REST, NOTE_C4, 
  NOTE_D4, NOTE_B3, //REST
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int Mario_Notes[] = {
  4, 4, 4, 4,
  2, 4, 4,
  4, 4, 4, 4,  
  4, 4, 4, 4,
  
  4, 2, 4,
  4, 4, 4, 4,
  4, 4, 4, 4, 
  4, 4, 2
  };
  
  const int num_elements_in_arr = sizeof(Mario_Notes)/sizeof(Mario_Notes[0]);
 

void setup() {
  
  /*lcd.createChar(1, newChar); 
  lcd.begin(20,4);
  lcd.setCursor(Col, Row);
  lcd.write(1); */
  
  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < num_elements_in_Intro; thisNote++) {
  // to calculate the note duration, take one second
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 500/Intro_Notes[thisNote];
    tone(speakerpin, Intro_melody[thisNote],noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(speakerpin);
    
    if(thisNote % 8 == 0){
       Note_Anim(); 
    }     
  }    
}

void loop() {

  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < num_elements_in_arr; thisNote++) {

    // to calculate the note duration, take one second
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 500/Mario_Notes[thisNote];
    tone(speakerpin, Mario_melody[thisNote],noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(speakerpin);
    
    if(thisNote % 8 == 0){
       Note_Anim(); 
    }    
  }
}

void Note_Anim(){ 
  
  if (Col > 20){
    Col = 0;
  }
  
  /*int introw = (int) (sin( Col + 2) *4);
  Row = (int) map(introw, -3, 3, 0, 3); 
  lcd.clear();
  lcd.setCursor(Col, Row);
  lcd.write(1); 
  Col++;*/

} 
