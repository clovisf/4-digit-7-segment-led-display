#define LATCH 12
#define CLK 11
#define DATA 13

const int display3= 6;
const int display4= 7;

//This is the hex value of each number stored in an array by index num
//byte digitOne[10]= {0x6F, 0x09, 0x73, 0x3B, 0x1D, 0x3E, 0x7C, 0x0B, 0x7F, 0x1F};
//byte digitTwo[10]= {0x7B, 0x11, 0x67, 0x37, 0x1D, 0x3E, 0x7C, 0x13, 0x7F, 0x1F};
byte digitOne[10]= {B0000110,B1011011,B1001111,B1100110,B1101101,B1111100,B0000111,B1111111,B1100111,B0111111};
byte digitTwo[10]= {0x00, 0x0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

int i;

void setup(){
 
  pinMode(LATCH, OUTPUT);
  pinMode(CLK, OUTPUT);
  pinMode(DATA, OUTPUT);
  pinMode(display3, OUTPUT);
  pinMode(display4, OUTPUT);

}

void loop(){
 
  for(int i=0; i<10; i++){
    for(int j=0; j<10; j++){
      digitalWrite(LATCH, LOW);
      digitalWrite(display4,HIGH);
      //digitalWrite(display3,HIGH);
      shiftOut(DATA, CLK, MSBFIRST, ~digitTwo[i]); // digitTwo
      shiftOut(DATA, CLK, MSBFIRST, ~digitOne[j]); // digitOne
      digitalWrite(LATCH, HIGH);
      delay(500);
      digitalWrite(display4,LOW);
      //digitalWrite(display3,LOW);
    }
  }
}
