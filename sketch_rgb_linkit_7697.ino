#include <LRemote.h>




#define R_PIN A3    // P17  why?
#define G_PIN A2    // P16
//#define B_PIN A1    // P15
#define B_PIN 58
#define Volt_PIN 39 //P3
#define MAX_STEP (10) //  陣列

#define IS_OVER(x) (((x) >> 8) != 0)
#define CLAMP(x)   (((x) < 0)? 0: 255)

// Remote Elements
LRemoteSwitch powerSwitch;
LRemoteLabel titleLable;

int r, g, b;
int r_dir = 1, g_dir = 1, b_dir = 1;
void setup() {
  Serial.begin(9600);
  
  // Remote
  LRemote.setName("ikea RGB_light");
  LRemote.setOrientation(RC_PORTRAIT);
  LRemote.setGrid(3, 5);
  titleLable.setPos(0,0);
  titleLable.setText("RGB燈號控制小練習");
  titleLable.setSize(3, 1);
  titleLable.setColor(RC_GREY);
  LRemote.addControl(titleLable);

  powerSwitch.setPos(0, 1);
  powerSwitch.setText("開關");
  powerSwitch.setSize(3, 1);
  LRemote.addControl(powerSwitch);
  LRemote.begin();

  // initialize the pin directions
  pinMode(R_PIN, OUTPUT);
  pinMode(G_PIN, OUTPUT);
  pinMode(B_PIN, OUTPUT);
  pinMode(Volt_PIN, OUTPUT);

}

void loop() {
  LRemote.process();
  
  if(!LRemote.connected()){
    Serial.println("waiting for connection");
    delay(1000);
  }else{
    delay(500);
  }
  if(powerSwitch.isValueChanged()){
    Serial.print("偵測到變化, powerSwitch=");
    Serial.println(powerSwitch.getValue());
    digitalWrite(Volt_PIN, powerSwitch.getValue());
    if(powerSwitch.getValue()) {
      rbgRandom();
      Serial.println("get in get value");
    }else{
      analogWrite(R_PIN, 255);
      analogWrite(G_PIN, 0);
      analogWrite(B_PIN, 0);
    }
  }
  

  delay(100);

}

int rbgRandom(){
// walk in a random step
  r += random(MAX_STEP) * r_dir;
  g += random(MAX_STEP) * g_dir;
  b += random(MAX_STEP) * b_dir;

  // check if it walks out of the boundary and thus needs to turn back
  if (IS_OVER(r)) { r = CLAMP(r); r_dir = -r_dir; }
  if (IS_OVER(g)) { g = CLAMP(g); g_dir = -g_dir; }
  if (IS_OVER(b)) { b = CLAMP(b); b_dir = -b_dir; }

  // Set the output value
  analogWrite(R_PIN, r);
  analogWrite(G_PIN, g);
  analogWrite(B_PIN, b);
}
