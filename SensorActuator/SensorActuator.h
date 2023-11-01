#include <Arduino.h>
#include <Servo.h>

//DEFINE_STRUCT
typedef struct hcsr04{
  int Trig;
  int Echo;

}HCSR04;

typedef struct Sinside{
	HCSR04 ultra;
	int PIR;

}sinside;



//ACTIVATE_HCSR04
void HCSR04_ON(int trig);

int SINSIDE_LOGIC(sinside sense);//output_logic_for_inside_sensor

void BackDoor(HCSR04 ultra,Servo BackGate);//open_if_proximityHCSR04_less_than_buffer

void ChickCount(unsigned int *count,int sinside_bool);//counting_system

void FrontDoor(int sinside_bool,Servo FrontGate);//open_if_sinside==TRUE
