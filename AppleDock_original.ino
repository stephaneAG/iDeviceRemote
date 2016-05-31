#define NUMBUTTONS 4
#define READ_BUTTONS 0
#define TX_IPOD 1
#define RX_IPOD 2
#define UPDATE_LCD 3

#define LENGTH_INDEX 2
#define MODE_INDEX 3
#define COMMAND_INDEX 4
//ipod command setup
//   0    |    1   |   2    |    3   |    4   |    5   |   6    |   7    
// header | header | length |  mode  |command |command | param  |checksum
//  0xff  |  0x55  | 0-255  |   0-5  | 2bytes for most |        | 0x100-((L+M+C+P) &0xff)

//mode 0 - mode switching commands
byte M0_SWITCH_2[3]=  {0x00,0x01,0x02};
byte M0_GET_MODE[3]=  {0x00,0x01,0x03};
byte M0_SWITCH_4[3]=  {0x00,0x01,0x04};
byte changeMode[3]=  {0x00,0x01,0x00};

//below are the iPod Mode 2 commands, the first byte IS NOT part of the command.
//it is actuall the MODE, only included so that the routine can see what mode each command is,
//this will help make the code more robust!
//  |command name|last byte index|mode|command                  |
byte M2_BUTTON_RELEASE[4]=  {0x04,0x02,0x00,0x00};                    //
byte M2_PLAY_PAUSE[4]=      {0x04,0x02,0x00,0x01};                    //a
byte M2_VOL_UP[4]=          {0x04,0x02,0x00,0x02};                    //b
byte M2_VOL_DOWN[4]=        {0x04,0x02,0x00,0x04};                    //c
byte M2_SKIP_FORWARD[4]=    {0x04,0x02,0x00,0x08};                    //d
byte M2_SKIP_BACK[4]=       {0x04,0x02,0x00,0x10};                    //e
byte M2_NEXT_ALBUM[4]=      {0x04,0x02,0x00,0x20};                    //f
byte M2_PREV_ALBUM[4]=      {0x04,0x02,0x00,0x40};                    //g
byte M2_STOP_PLAY[4]=       {0x04,0x02,0x00,0x80};                    //h
byte M2_PLAY[5]=            {0x05,0x02,0x00,0x00,0x01};               //i
byte M2_PAUSE[5]=           {0x05,0x02,0x00,0x00,0x02};               //j
byte M2_TOGGLE_MUTE[5]=     {0x05,0x02,0x00,0x00,0x04};               //k
byte M2_NEXT_PLAYLIST[5]=   {0x05,0x02,0x00,0x00,0x20};               //l
byte M2_PREV_PLAYLIST[5]=   {0x05,0x02,0x00,0x00,0x40};               //m
byte M2_TOGGLE_SHUFFLE[5]=  {0x05,0x02,0x00,0x00,0x80};               //n
byte M2_TOGGLE_REPEAT[6]=   {0x06,0x02,0x00,0x00,0x00,0x01};          //o
byte M2_IPOD_OFF[6]=        {0x06,0x02,0x00,0x00,0x00,0x04};          //p
byte M2_IPOD_ON[6]=         {0x06,0x02,0x00,0x00,0x00,0x08};          //q
byte M2_MENU_BUTTON[6]=     {0x06,0x02,0x00,0x00,0x00,0x40};          //r
byte M2_CENTER_BUTTON[6]=   {0x06,0x02,0x00,0x00,0x00,0x80};          //s
byte M2_SCROLL_CCW[7]=      {0x07,0x02,0x00,0x00,0x00,0x00,0x01};     //t
byte M2_SCROLL_CW[7]=       {0x07,0x02,0x00,0x00,0x00,0x00,0x02};     //u

// mode 4
byte M4_RX_FEEDBACK[3]=       {0x04,0x00,0x01};
byte M4_TX_GET_POD_TYPE[3]=   {0x04,0x00,0x12};
byte M4_RX_GET_POD_TYPE[3]=   {0x04,0x00,0x13};
byte M4_TX_GET_POD_NAME[3]=   {0x04,0x00,0x14};
byte M4_RX_GET_POD_NAME[3]=   {0x04,0x00,0x15};
byte M4_TX_GO_2_LIB[3]=       {0x04,0x00,0x16};
byte M4_TX_SWITCH_ITEM[3]=    {0x04,0x00,0x17};
byte M4_TX_GET_COUNT_TYPE[3]= {0x04,0x00,0x18};
byte M4_RX_GET_COUNT_TYPE[3]= {0x04,0x00,0x19};
byte M4_TX_GET_NAMES_RANGE[3]={0x04,0x00,0x1a};
byte M4_RX_GET_NAMES_RANGE[3]={0x04,0x00,0x1b};
byte M4_TX_GET_TIME_STATUS[3]={0x04,0x00,0x1c};
byte M4_RX_GET_TIME_STATUS[3]={0x04,0x00,0x1d};
byte M4_TX_GET_POS_PL[3]=     {0x04,0x00,0x1e};
byte M4_RX_GET_POS_PL[3]=     {0x04,0x00,0x1f};
byte M4_TX_GET_TITLE_SONG[3]= {0x04,0x00,0x20};
byte M4_RX_GET_TITLE_SONG[3]= {0x04,0x00,0x21};
byte M4_TX_GET_ARTIST_SONG[3]={0x04,0x00,0x22};
byte M4_RX_GET_ARTIST_SONG[3]={0x04,0x00,0x23};
byte M4_TX_GET_ALBUM_SONG[3]= {0x04,0x00,0x24};
byte M4_RX_GET_ALBUM_SONG[3]= {0x04,0x00,0x25};
byte M4_TX_POLLING_MODE[3]=   {0x04,0x00,0x26};
byte M4_RX_POLLING_MODE[3]=   {0x04,0x00,0x27};
byte M4_TX_START_PL_SONG[3]=  {0x04,0x00,0x28};
byte M4_TX_PLAY_BACK[3]=      {0x04,0x00,0x29};
byte M4_TX_GET_SHUF_MODE[3]=  {0x04,0x00,0x2c};
byte M4_RX_GET_SHUF_MODE[3]=  {0x04,0x00,0x2d};
byte M4_TX_SET_SHUF_MODE[3]=  {0x04,0x00,0x2e};
byte M4_TX_GET_REP_MODE[3]=   {0x04,0x00,0x2f};
byte M4_RX_GET_REP_MODE[3]=   {0x04,0x00,0x30};
byte M4_TX_SET_REP_MODE[3]=   {0x04,0x00,0x31};
byte M4_TX_UPLOAD_PIC[3]=     {0x04,0x00,0x32};
byte M4_TX_GET_MAX_SCREEN[3]= {0x04,0x00,0x33};
byte M4_RX_GET_MAX_SCREEN[3]= {0x04,0x00,0x34};
byte M4_TX_GET_NUM_SONG_PL[3]={0x04,0x00,0x35};
byte M4_RX_GET_NUM_SONG_PL[3]={0x04,0x00,0x36};
byte M4_TX_JUMP_SONG_PL[3]=   {0x04,0x00,0x37};

//header(2) + length(1) + mode(1) + command(2->5) + param(1->255) + cs(1)
byte txBuffer[265]=    {0xff,0x55};

boolean dbug = false;

void setup(){
  // initialize serial port
  Serial.begin(19200);

}

void loop(){
  if(Serial.available()>0){
    int inByte = Serial.read();
    
    switch(inByte){
      case 'a':
        sendMsg(M2_PLAY_PAUSE);
        break;
      case 'b':
        sendMsg(M2_VOL_UP);
        break;
      case 'c':
        sendMsg(M2_VOL_DOWN);
        break;  
      case 'd':
        sendMsg(M2_SKIP_FORWARD);
        break;
      case 'e':
        sendMsg(M2_SKIP_BACK);
        break;
      case 'f':
        sendMsg(M2_NEXT_ALBUM);
        break;
      case 'g':
        sendMsg(M2_PREV_ALBUM);
        break;
      case 'h':
        sendMsg(M2_STOP_PLAY);
        break;
      case 'i':
        sendMsg(M2_PLAY);
        break;
      case 'j':
        sendMsg(M2_PAUSE);
        break;
      case 'k':
        sendMsg(M2_TOGGLE_MUTE);
        break;
      case 'l':
        sendMsg(M2_NEXT_PLAYLIST);
        break;
      case 'm':
        sendMsg(M2_PREV_PLAYLIST);
        break;
      case 'n':
        sendMsg(M2_TOGGLE_SHUFFLE);
        break;
      case 'o':
        sendMsg(M2_TOGGLE_REPEAT);
        break;
      case 'p':
        sendMsg(M2_IPOD_OFF);
        break;
      case 'q':
        sendMsg(M2_IPOD_ON);
        break;
      case 'r':
        sendMsg(M2_MENU_BUTTON);
        break;
      case 's':
        sendMsg(M2_CENTER_BUTTON);
        break;
      case 't':
        sendMsg(M2_SCROLL_CCW);
        break;
      case 'u':
        sendMsg(M2_SCROLL_CW);
        break;        
      default:
        break;
    }
    sendMsg(M2_BUTTON_RELEASE);
  }
  
  
  
}
void sendMsg(byte cmd[]){
  // because MODE is included as the first byte of our commands,
  // we only need to add one more for the checksum
  // DONT FORGET WE NEED TO ADD THE PARAM IF YOU WANNA ADD MODE 4 SUPPORT
  txBuffer[LENGTH_INDEX]=(cmd[0]-1);
  txBuffer[MODE_INDEX]=cmd[1];
  
  // copy the command (starting at the 3rd byte) in to the tx buffer (starting at the 5th byte)
  for(int i=0;i< cmd[0]-2; i++)
    txBuffer[COMMAND_INDEX+i]=cmd[2+i];
    
  txBuffer[LENGTH_INDEX + txBuffer[LENGTH_INDEX] + 1] = getCheckSum();

  for(int i=0; i< LENGTH_INDEX + txBuffer[LENGTH_INDEX] + 2 ; i++){
    if(dbug){
      Serial.print(txBuffer[i], HEX);
      Serial.print(" ");
    }
    else{
      Serial.print(txBuffer[i], BYTE);
    }
  }
  if(dbug)
    Serial.print("\n");
}

byte getCheckSum(){
  byte checkSum=0;
  //
  for(int i=LENGTH_INDEX; i< LENGTH_INDEX + txBuffer[LENGTH_INDEX] +1; i++ ){
    checkSum=checkSum+txBuffer[i];   
  }
  return 0x100 - (checkSum & 0xff);
}
