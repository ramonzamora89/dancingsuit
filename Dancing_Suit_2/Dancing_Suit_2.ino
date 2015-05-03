//The Dancing Suit. 
/*The idea is to have a body suit with various sensors placed around the body, when the user moves and changes the resitence of one of the sensors, the speaker will output a note. 
This is the first iteration of the project, so I will just be using 6 sensors to do so, placed in the crook of the elbows, in the armpits, and in the hands. 
For the notes I will be using the pitches.h library.*/

#include "pitches.h" //to get the pitches.h file go to http://www.arduino.cc/en/Tutorial/Tone.
                     //You will need to open a new tab name it pitches.h and copy the code at the end of that side.
                     //This will give tone library that you use for the keyboard.
                     
/*The way the keyboard works is by using thresholds. With the threshold you are defining a value of resistence. 
When one of the sensor passes the threhold, the specified note will play in the speaker*/

const int thresholdP = 100;   //threshold for sensors on the armpit.

const int thresholdE = 100;   //threshold for the sensors on the rook of the elbow

const int thresholdF = 100;   //threshold for the sensors in the hand

/*I created three arrays, one for each body part where the sensor are going to be placed.*/
 
uint8_t FlexP[] = {A4, A5};    //This array is for the flex (or force) sensor located in the armpit of the suit

uint8_t FlexE[] = {A2, A3};    //This array is for the flex (or force) sensor located in the crook of the elbow of the suit

uint8_t Force[] = {A0, A1};    //This array is for the force sensor located in the palm of your hands of the suit

int speakerPinR = 8;       //pin number for the speaker

const int noteDuration =20;  // play notes for 20 ms

int newtone=2;  //the newtone constant specifies which of the tones the speaker need to play. In this case the third one.

int sensorReading = 0;

// notes to play, corresponding to each sensors:
int note[] {
  NOTE_A4, NOTE_B4, NOTE_C3, NOTE_C1, NOTE_D1, NOTE_D8};

void setup() {
 //you don't need anything here. If you want, you can add Analog Read Serial code, to see the values of the different sensors.
 //This is helpful to figure out the values of resistance that the sensors have when you are interacting with them to set up the thresholds

 // initialize serial communication at 9600 bits per second:
 Serial.begin(9600);
 
}

void loop() {
    
  newtone= 2;
  
  
   for (int i = 0; i < 2; i++) {    //for more inforamtion about for statements check out this http://www.arduino.cc/en/Reference/For . 
                                    //If you were to change the condition of the for statement (in this case two) for a lower or higher
                                    //value, this would change the number of inputs or pins.
  
// get a sensor reading:     
sensorReading = analogRead(Force[i]);     //This line here is telling the arduino to read the input of the array Force (A0, A1) and run it through
                                          // the for loop i.
  
// if the sensor is pressed hard enough:     
if (sensorReading > thresholdF) { 
 
      Serial.print("Forcereading "); Serial.println(sensorReading); //This line here will print the resistence of the sensor in
                                                                    //array Force. It is useful to place this line after the sensorReading
                                                                    //because this will only print the values in the serial monitor if
                                                                    //the sensor are pressed.
      tone(speakerPinR,note[newtone], 20);        // play the note corresponding to the array Force
    }
    else
    {
      noTone(speakerPinR);                        //the noTone fuction is just to make sure that the speaker stops playing the note once 
                                                  //once you stop pressing or bending the sensors.
    }
    
  }
  
  for (int j = 0; j < 2; j++) {    
  
// get a sensor reading:     
sensorReading = analogRead(FlexE[j]);     
     
if (sensorReading > thresholdE) { 
 Serial.print("Flexereading "); Serial.println(sensorReading);  
      tone(speakerPinR, note[newtone], 20); 
    }
    else
    {
      noTone(speakerPinR);
    }
    
  }
  for (int k = 0; k < 2; k++) {    
  
     
sensorReading = analogRead(FlexP[k]);     
   
    
if (sensorReading > thresholdP) {
 Serial.print("FlexPreading "); Serial.println(sensorReading);

      tone(speakerPinR, note[newtone], 20);
    }
    else
    {
      noTone(speakerPinR);
    }
   
  }

}
