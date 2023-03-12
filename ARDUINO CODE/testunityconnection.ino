//joystick code

#define SW 8
#define joy_x A0
#define joy_y A3

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(SW, INPUT_PULLUP);
  pinMode(joy_x, INPUT);
  pinMode(joy_y, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  float joy_rx = analogRead(joy_x);
  float joy_ry = analogRead(joy_y);

  joy_rx = map(joy_rx, 1, 1024, -500, 500);   // raw values are 1 to 1024, remapped to -500 to 500
  joy_ry = map(joy_ry, 1, 1024, -500, 500);

  Serial.print(joy_rx - 8);   //scuffed fix to stop sliding
  Serial.print(",");
  Serial.print(joy_ry);
  Serial.print(",");
  Serial.println(!digitalRead(SW));
  //delay(50);   //comment this line out, might make the unity model lag behind input
}
