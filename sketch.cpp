

int servo = 11;


int servoUpPos = 90;
int servoDownPos = 180;

int servoPos = 140;

int sensLo = 400;
int sensHi = 600;

// the setup routine runs once when you press reset:
void setup() {
  strLen = servoUpPos - servoDownPos;
  pinMode(servo, OUTPUT);
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  if(sensorValue < sensLo) {
    servoPos++;
  }
  if(sensorValue > sensHi) {
    servoPos--;
  }

  if(servoPos < 20) {
    servoPos = 20;
  }

  if(servoPos > 180) {
    servoPos = 180;
  }
  analogWrite(servo, servoPos);
  // print out the value you read:
  Serial.println(sensorValue);
  delay(10);        // delay in between reads for stability
}
