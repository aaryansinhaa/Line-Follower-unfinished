const int MR1_PIN = 8;   // motor right 1
const int MR2_PIN = 9;   // motor right 2
const int ML1_PIN = 10;  // motor left 1
const int ML2_PIN = 11;  // motor left 2
const int IR_SENSOR_PIN = 6;  // infrared sensor
const int LED_PIN = 13;
const int ENR_PIN = 3; 
const int ENL_PIN = 5;

const int V_SPEED = 100;
const int T_SPEED = 255;
const int T_DELAY = 20;


void setup() {
  pinMode(MR1_PIN, OUTPUT);
  pinMode(MR2_PIN, OUTPUT);
  pinMode(ML1_PIN, OUTPUT);
  pinMode(ML2_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(IR_SENSOR_PIN, INPUT);

}

void loop() {
  int irValue = digitalRead(IR_SENSOR_PIN);

  if (irValue == LOW) {
    forward();  // move forward
  } else {
    if (/*to be filled*/) {
      turnLeft();
    } else if(/*to be filled*/) {
      turnRight();
    }else{
    stopMotors();
    }
  }
  

}

void forward() {
  digitalWrite(MR1_PIN, HIGH);
  digitalWrite(MR2_PIN, LOW);
  digitalWrite(ML1_PIN, HIGH);
  digitalWrite(ML2_PIN, LOW);
  analogWrite(ENR_PIN, V_SPEED);
  analogWrite(ENL_PIN, V_SPEED);
}

void turnLeft() {
  digitalWrite(MR1_PIN, HIGH);
  digitalWrite(MR2_PIN, LOW);
  digitalWrite(ML1_PIN, LOW);
  digitalWrite(ML2_PIN, HIGH);
  analogWrite(ENR_PIN, T_SPEED);
  analogWrite(ENL_PIN, T_SPEED);
  delay(T_DELAY);
}

void turnRight() {
  digitalWrite(MR1_PIN, LOW);
  digitalWrite(MR2_PIN, HIGH);
  digitalWrite(ML1_PIN, HIGH);
  digitalWrite(ML2_PIN, LOW);
  analogWrite(ENR_PIN, T_SPEED);
  analogWrite(ENL_PIN, T_SPEED);
  delay(T_DELAY);
}

void stopMotors() {
  analogWrite(ENR_PIN, 0);
  analogWrite(ENL_PIN, 0);
}
