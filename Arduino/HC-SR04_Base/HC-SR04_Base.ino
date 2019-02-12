/*****************************
* HC-SR04 base control module
* Version: 1.0.0
* Author: Zachary Tomlinson
******************************/

class HC_SR04 {
  private:
    long DELAY;
    double DISTANCE;
    int TRIG;
    int ECHO;
 
  public:
    HC_SR04(int, int);
    double GetDistance();
};

HC_SR04::HC_SR04(int trig, int echo)
{
  this->TRIG = trig;
  this->ECHO = echo;
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

double HC_SR04::GetDistance()
{
  digitalWrite(this->TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(this->TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(this->TRIG, LOW);
  this->DELAY = pulseIn(this->ECHO, HIGH);
  this->DISTANCE = this->DELAY * 0.0135039 / 2;
  return this->DISTANCE;
}

const int TRIG_1 = 9;
const int ECHO_1 = 10;
HC_SR04 DEV_1 = HC_SR04(TRIG_1, ECHO_1);
double DISTANCE_1;

void setup() {
  Serial.begin(9600); //9600 Baud
}

void loop() {
  DISTANCE_1 = DEV_1.GetDistance();
  Serial.print("Distance: ");
  Serial.println(DISTANCE_1);
  // Rest
  delay(500);
}

