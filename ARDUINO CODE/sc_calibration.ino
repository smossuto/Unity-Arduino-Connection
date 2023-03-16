#include "HX711.h" //This library can be obtained here http://librarymanager/All#Avia_HX711

#define LOADCELL1_DOUT_PIN  3
#define LOADCELL2_DOUT_PIN  4
#define LOADCELL3_DOUT_PIN  7
#define LOADCELL4_DOUT_PIN  8
#define LOADCELL_SCK_PIN  2

HX711 lc1;
HX711 lc2;
HX711 lc3;
HX711 lc4;

float calibration_factor_1 = -5620; //-7050 worked for my 440lb max scale setup
float calibration_factor_2 = -5620;
float calibration_factor_3 = -5620;
float calibration_factor_4 = -5620;

void setup() {
  Serial.begin(9600);
  Serial.println("HX711 calibration sketch");
  Serial.println("Remove all weight from scale");
  Serial.println("After readings begin, place known weight on scale");
  Serial.println("Press + or a to increase calibration factor");
  Serial.println("Press - or z to decrease calibration factor");

  lc1.begin(LOADCELL1_DOUT_PIN, LOADCELL_SCK_PIN);
  lc1.set_scale();
  lc1.tare();	//Reset the scale to 0
  
  lc2.begin(LOADCELL2_DOUT_PIN, LOADCELL_SCK_PIN);
  lc2.set_scale();
  lc2.tare();  //Reset the scale to 0

  lc3.begin(LOADCELL3_DOUT_PIN, LOADCELL_SCK_PIN);
  lc3.set_scale();
  lc3.tare();  //Reset the scale to 0

  lc4.begin(LOADCELL4_DOUT_PIN, LOADCELL_SCK_PIN);
  lc4.set_scale();
  lc4.tare();  //Reset the scale to 0

  long zero_factor = lc1.read_average(); //Get a baseline reading
  Serial.print("Zero factor: "); //This can be used to remove the need to tare the scale. Useful in permanent scale projects.
  Serial.println(zero_factor);
}

void loop() {

  lc1.set_scale(calibration_factor_1); //Adjust to this calibration factor
  lc2.set_scale(calibration_factor_2);
  lc3.set_scale(calibration_factor_3);
  lc4.set_scale(calibration_factor_4);

  // load cell 1
  Serial.print("Reading load cell 1: ");
  Serial.print(lc1.get_units(), 4);
  Serial.print(" lbs"); //Change this to kg and re-adjust the calibration factor if you follow SI units like a sane person
  Serial.print(" calibration_factor: ");
  Serial.print(calibration_factor_1);
  Serial.println();

  // load cell 2
  Serial.print("Reading load cell 2: ");
  Serial.print(lc2.get_units(), 4);
  Serial.print(" lbs"); //Change this to kg and re-adjust the calibration factor if you follow SI units like a sane person
  Serial.print(" calibration_factor: ");
  Serial.print(calibration_factor_2);
  Serial.println();

  // load cell 3
  Serial.print("Reading load cell 3: ");
  Serial.print(lc3.get_units(), 4);
  Serial.print(" lbs"); //Change this to kg and re-adjust the calibration factor if you follow SI units like a sane person
  Serial.print(" calibration_factor: ");
  Serial.print(calibration_factor_3);
  Serial.println();

  // load cell 4
  Serial.print("Reading load cell 4: ");
  Serial.print(lc4.get_units(), 4);
  Serial.print(" lbs"); //Change this to kg and re-adjust the calibration factor if you follow SI units like a sane person
  Serial.print(" calibration_factor: ");
  Serial.print(calibration_factor_4);
  Serial.println();

  if(Serial.available())
  {
    char temp = Serial.read();
    if(temp == '+' || temp == 'a')
      calibration_factor_1 += 10;
    else if(temp == '-' || temp == 'z')
      calibration_factor_1 -= 10;
  }

  delay(600);
}
