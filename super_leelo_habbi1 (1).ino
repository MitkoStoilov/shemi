int animationspeed = 0;
int testSpeed = 0;
//int i = 0;

void setup()
{
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(5, OUTPUT);
}
void loop()
{
  /*animationspeed = 400;
  digitalWrite(13, HIGH);
  delay(animationspeed); // Wait for animationspeed millisecond(s)
  digitalWrite(13, LOW);
  delay(animationspeed); // Wait for animationspeed millisecond(s)
  digitalWrite(12, HIGH);
  delay(animationspeed); // Wait for animationspeed millisecond(s)
  digitalWrite(12, LOW);
  delay(animationspeed); // Wait for animationspeed millisecond(s)
  for (i = 0; i <= 255; i += 5) {
    analogWrite(11, i);
    delay(30); // Wait for 30 millisecond(s)
  }
  for (i = 255; i >= 0; i -= 5) {
    analogWrite(11, i);
    delay(30); // Wait for 30 millisecond(s)
  }*/
  	digitalWrite(5, HIGH);
  
	/*digitalWrite(7, HIGH);
    delay(1);
  	digitalWrite(7, LOW);
  	delay(1);*/
  	
  	
    for(int i = 0; i < 10; i++)
    {
    	digitalWrite(7, LOW);
    	delay(200-20*i);
  		digitalWrite(7, HIGH);
  		//delay(1000-100*i);
    }
  	for(int i = 0; i < 10; i++)
    {
    	digitalWrite(7, HIGH);
    	delay(200-20*i);
  		digitalWrite(7, LOW);
  		delay(1000);
    }
  	/*digitalWrite(13, HIGH);
  	delay(1);
  	digitalWrite(13, LOW);
  	delay(4);
  	digitalWrite(12, HIGH);
  	delay(4);
  	digitalWrite(12, LOW);
  	delay(1);*/
  
}