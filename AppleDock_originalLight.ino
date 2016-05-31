/*---------------------------------------------------
 Controls an iPod through the dock connector's serial interface.
 -----------------------------------------------------
 
 Tx (output 1) ---[1k]-------------iPod pin13 Rx
 		           |     -----iPod pin21 Accessory
 		           |     |
 		           |     |
 			  ---   ---
 			   2k   500k
 			  ---   ---
 			   |     |
 			   |     |
 Gnd-----------------------------------------iPod pin11 Ground
 
 				gnd
 				 |
 				 |
 				---
 				10k
 				---
 				 |
 				 |
 digital inputs 0-4 -------/push button/--- +5v
 
 2/13/11 changed to be a little more adaptable for further projects
 -----------------------------------------------------
 v0.3 - Added switches code
 -----------------------------------------------------
 v0.2 - Added DEBUG mode
 Added the DEBUG switch to be able to read the output without having an iPod connected.
 -----------------------------------------------------
 v0.1 - Initial code
 iPod mode 2 (simple iPod remote) only.
 -----------------------------------------------------
 Resources used:
 
 http://www.rosiedaniel.com/search/label/ipod
 http://stud3.tuwien.ac.at/~e0026607/ipod_remote/ipod_ap.html
 http://instruct1.cit.cornell.edu/courses/ee476/FinalProjects/s2007/awr8_asl45/awr8_asl45/index.html
 http://ipodlinux.org/wiki/Apple_Accessory_Protocol
 http://pinouts.ru/Devices/ipod_pinout.shtml
 -----------------------------------------------------
 Mode 2 Commands
 Command 		|Purpose
 -----------------------------------------------------
 0x00 0x00		|Button Released
 0x00 0x01		|Play
 0x00 0x02		|Vol+
 0x00 0x04		|Vol-
 0x00 0x08		|Skip>
 0x00 0x10		|Skip<
 0x00 0x20		|Next Album
 0x00 0x40		|Previous Album
 0x00 0x80		|Stop
 -----------------------------------------------------
 */
 
#define NUMBUTTONS 4

// constants won't change. They're used here to set pin numbers:
const int buttonPin[NUMBUTTONS] = {6,7,8,9};     // the number of the pushbutton pin

// ipod mode 2 commands that we use
byte switchMode2[2]= {1,2};
byte buttonRelease[2]= {0,0};
byte playPause[2]= {0,1};
byte volUp[2]= {0,2};
byte volDown[2] = {0,4};
byte skipForward[2] = {0, 8};

int buttonCur[NUMBUTTONS];                         // the current reading from the input pin
int buttonPrev[NUMBUTTONS] = {LOW,LOW,LOW,LOW};    // the previous reading from the input pin
int i=0, j=0, k=0;
int debug=0;

// 2 for header + 1 for length + 1 for mode + 2 for command + up to 255 for params + 1 checkSum
byte msg[255+7]={0xff, 0x55};

// this isn't used, but if we wanted to go into ipod mode 4, we would fill this
// with the params needed and send it to the iPod
byte params[255];

// the following variables are long's because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long lastDebounceTime[NUMBUTTONS] = {0,0,0,0};  // the last time the output pin was toggled
long lastPushedTime[NUMBUTTONS]={0,0,0,0};
long debounceDelay = 50;    // the debounce time; increase if the output flickers
long pushDelay=500;

void setup() {
  // setup serial port
  Serial.begin(19200);

  // setup input for buttons
  for(int i=0; i<NUMBUTTONS; i++){
    pinMode(buttonPin[i], INPUT);
  }

  // setup the ipod for mode 2
  sendToPod(0, switchMode2, params, 0);
}

void loop() {
  // loop through all the buttons
  for(i=0;i<NUMBUTTONS;i++){
    // store the current button state
    buttonCur[i] = digitalRead(buttonPin[i]);

    // if it has changed, reset the debounce timer
    if (buttonCur[i] != buttonPrev[i])
      lastDebounceTime[i] = millis();

    // only wanna enter this section if the dbounce time has passed,
    // and if we didn't JUST push the button,
    // AND if the button is currently being pushed
    if ( millis() - lastDebounceTime[i] > debounceDelay && // debounce
      millis() - lastPushedTime[i] > pushDelay && // time out 
      buttonCur[i]==HIGH) // being pushed
    {
      lastPushedTime[i]= millis(); //reset timer

      switch(i){
        case(0): // play button
        sendToPod(2, playPause, params, 0);
        break;
        case(1): // pump up the volume button
        sendToPod(2, volUp, params, 0);
        break;
        case(2): // drop that baby down
        sendToPod(2, volDown, params, 0);
        break;
        case(3): // skip ahead !
        sendToPod(2, skipForward, params, 0);
        break;
      default: // no button
        sendToPod(2, buttonRelease, params, 0);  

      }
      // once we've sent the button push, we need to send the release!
      sendToPod(2, buttonRelease, params, 0);
    }

    // save the reading.  Next time through the loop it'll be the buttonPrev:
    buttonPrev[i] = buttonCur[i];
  }
}

// builds the msg that we want to send to the ipod
void sendToPod(byte mode, byte cmd[], byte parameter[], byte paramLength){
  // SIZE= 1 for mode + 2 for command + N for param
  msg[2]=(byte)1+2+paramLength;
  msg[3]=mode;
  msg[4]=cmd[0];
  msg[5]=cmd[1];

  // for now, length will always be zero.  if we entered mode 4 this might change...
  if(paramLength==0){
    msg[6]=0;
  }
  else{
    for(j=0; j<paramLength; j++){
      msg[6+j]=parameter[j];
    }
  }

  // load up the checksum
  msg[6+paramLength]=getCheckSum(paramLength);

  // send the message to the ipod!
  for(j=0; j<7 + paramLength; j++){
    if(debug){
      Serial.print(msg[j], HEX);
      Serial.print(" ");
    }
    else{
      Serial.print(msg[j], BYTE);        
    }
  }
  if(debug)
    Serial.print("\n");
}

// calculates and returns the checksum of what is currently in the msg[] buffer
byte getCheckSum(byte paramLength){
  byte checkSum=0;

  for(k=2; k< 6+ paramLength; k++)
    checkSum=checkSum+msg[k];

  return 0x100 - (checkSum & 0xFF);

}


