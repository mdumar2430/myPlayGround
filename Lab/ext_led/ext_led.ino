int blue = 9;
int green = 15;
int red = 4;
int dtime = 130;

void setup() {
  // put your setup code here, to run once:
  pinMode(blue, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(blue, 1);
  delay(dtime);
  digitalWrite(blue, 0);
  delay(dtime);
  digitalWrite(green, 1);
  delay(dtime);
  digitalWrite(green, 0);
  delay(dtime);
  digitalWrite(red, 1);
  delay(dtime);
  digitalWrite(red, 0);
  delay(dtime);
}
