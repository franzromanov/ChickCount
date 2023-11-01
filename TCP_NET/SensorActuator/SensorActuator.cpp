#include <SensorActuator.h>

//ACTIVATE_HCSR04
void HCSR04_ON(int trig){

  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

}

int SINSIDE_LOGIC(sinside sense){
	//PIR_SECTION
	int PIR_VAL = digitalRead(sense.PIR);

	//HCSR04_SECTION
	HCSR04_ON(sense.ultra.Trig);
	float dur = pulseIn(sense.ultra.Echo, HIGH);
 	float length = (dur*.0343)/2;

	int buffer_length=;
	if(length<buffer_length && PIR_VAL==1)return 1;
	else return 0;

}//output_logic_for_inside_sensor

void BackDoor(HCSR04 ultra,Servo BackGate){

        int deg_open,deg_close;
        HCSR04_ON(ultra.Trig);
        float dur = pulseIn(ultra.Echo, HIGH);
        float length = (dur*.0343)/2;
        float buffer_length=;
        //changes_trigger
        if(sinside_bool==1){
        while(length>=buffer_length)Servo.Write(deg_open);
        Servo.write(deg_close);
        }else Servo.write(deg_close);


}//open_if_proximityHCSR04_less_than_buffer

void ChickCount(unsigned int *count,int sinside_bool){
	recv(c_sock,count,sizeof(count),0);
        if(sinside_bool==1)*count++;
	else *count;
	send(c_sock,count,sizeof(count),0);

}//counting_system



void FrontDoor(int sinside_bool,Servo FrontGate, HCSR04 ultra){
	int deg_open,deg_close;
        HCSR04_ON(ultra.Trig);
        float dur = pulseIn(ultra.Echo, HIGH);
        float length = (dur*.0343)/2;
	float buffer_length=;
	//changes_trigger
	if(sinside_bool==1){
	while(length>=buffer_length)Servo.Write(deg_open);
	Servo.write(deg_close);
	}else Servo.write(deg_close);




}//open_if_sinside==TRUE

