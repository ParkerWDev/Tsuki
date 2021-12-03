const int relayLeftPin = A1; // assigns pin 2 as terminal for left turn relay 
const int voltageSensorPin = A0; // assigns pin A0 to voltage sensor 

//Floats for ADC voltage & Input voltage
float adc_voltage = 0.0;
float in_voltage = 0.0;

//Floats for resistor values in divider (in ohms)
float R1 = 30000.0;
float R2 = 7500.0;

//Floats for Reference Voltage
float ref_voltage = 5.0;

//Integer for ADC value
int adc_value = 0;





void setup() {
  // Setup Serial Monitor
  pinMode(relayLeftPin, OUTPUT);// connect to S terminal of Relay
  Serial.println("DC Volatage Test");
     Serial.begin(9600); 

}
void loop() {

  // Sensor Setup
    // Read the Analog Input
    adc_value = analogRead(voltageSensorPin);
      
    //Determine voltage at ADC input
    adc_voltage = (adc_value * ref_voltage) / 1024.0;
        
    //Calculate voltage at divider input
    in_voltage = adc_voltage / (R2/(R1+R2));

  // Prints Sensor Status 
  if (in_voltage > 4 ){
    Serial.print("Voltage Reading - ");
    Serial.print(in_voltage, 3);      // Prints voltage to 3 decimal places
    Serial.println("v");
    }
   else {
    Serial.print("Connection not established!   ");
    Serial.print("Current Reading - ");
    Serial.print(in_voltage, 3);
    Serial.println("v");
    }
    digitalWrite(relayLeftPin, HIGH), Serial.println("Relay ON");
/*
  // Relay
  if (in_voltage > 2) {
    digitalWrite(relayLeftPin, HIGH), Serial.println("Relay ON");
    Serial.print('\n');
    delay(1000);
    } 
   else {
    digitalWrite(relayLeftPin, LOW), Serial.println("Relay OFF");
    Serial.print('\n');
    delay(1000);
    }
*/
   
}
