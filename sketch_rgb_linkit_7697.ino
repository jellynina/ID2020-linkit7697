#include <LRemote.h>

#define R_PIN A3    // P17  why?
#define G_PIN A2    // P16
//#define B_PIN A1    // P15
#define B_PIN 58


// Remote Elements
LRemoteSwitch powerSwitch;
LRemoteLabel titleLable;
LRemoteSlider R_slider;
LRemoteSlider G_slider;
LRemoteSlider B_slider;

LRemoteLabel LableRval;
LRemoteLabel LableGval;
LRemoteLabel LableBval;
//int r, g, b;
//int r_dir = 1, g_dir = 1, b_dir = 1;
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

  R_slider.setPos(0, 1);
  G_slider.setPos(0, 2);
  B_slider.setPos(0, 3);
  LableRval.setPos(0, 4);
  LableGval.setPos(1, 4);
  LableBval.setPos(2, 4);

  LableRval.setSize(1, 1);
  LableGval.setSize(1, 1);
  LableBval.setSize(1, 1);
  LableRval.setText("Red Value");
  LableGval.setText("G Value");
  LableBval.setText("B Value");
  R_slider.setValueRange(0, 255, 0);
  G_slider.setValueRange(0, 255, 255);
  B_slider.setValueRange(0, 255, 0);

  R_slider.setText("RED");
  G_slider.setText("Green");
  B_slider.setText("Blue");

  R_slider.setSize(3,1);
  G_slider.setSize(3,1);
  B_slider.setSize(3,1);

  R_slider.setColor(RC_PINK);
  G_slider.setColor(RC_GREEN);
  B_slider.setColor(RC_BLUE);

  LRemote.addControl(R_slider);
  LRemote.addControl(G_slider);
  LRemote.addControl(B_slider);
  LRemote.addControl(LableRval);
  LRemote.addControl(LableGval);
  LRemote.addControl(LableBval);

  LRemote.begin();

  // initialize the pin directions
  pinMode(R_PIN, OUTPUT);
  pinMode(G_PIN, OUTPUT);
  pinMode(B_PIN, OUTPUT);
 

}

void loop() {
  
  if(!LRemote.connected()){
    Serial.println("waiting for connection");
    delay(1000);
  }else{
    delay(500);
  }
  LRemote.process();
  
  if(R_slider.isValueChanged() || G_slider.isValueChanged() || B_slider.isValueChanged()){
    Serial.println("slider value is changed");
    delay(500);
  }

}



int rgbInit( int x , int y, int z){
  analogWrite(R_PIN, x);
  analogWrite(G_PIN, y);
  analogWrite(B_PIN, z);
}
