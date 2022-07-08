#define echoPin 2 // attach pin D2 to pin Echo of HC-SR04
#define trigPin 3 //attach pin D3 to pin Trig of HC-SR04

long duration;
int distance;
const int RIGHT_MOTOR_1 = 10;
const int RIGHT_MOTOR_2 = 9;

const int LEFT_MOTOR_1 = 8;
const int LEFT_MOTOR_2 = 7;

const int SENSOR = A0;

void setup() {
  pinMode(RIGHT_MOTOR_1, OUTPUT);
  pinMode(RIGHT_MOTOR_2, OUTPUT);
  pinMode(LEFT_MOTOR_1, OUTPUT);
  pinMode(LEFT_MOTOR_2, OUTPUT);
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  Serial.println("Ultrasonic Sensor HC-SR04 Test");
  Serial.println("with Arduino UNO R3");
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  Serial.print(distance);
  Serial.println(" cm");
  if (distance < 20) {
    digitalWrite(RIGHT_MOTOR_1, LOW);
    digitalWrite(RIGHT_MOTOR_2, LOW);
    digitalWrite(LEFT_MOTOR_1, HIGH);
    digitalWrite(LEFT_MOTOR_2, LOW);

  }
  else {
    digitalWrite(RIGHT_MOTOR_1, HIGH);
    digitalWrite(RIGHT_MOTOR_2, LOW);
    digitalWrite(LEFT_MOTOR_1, HIGH);
    digitalWrite(LEFT_MOTOR_2, LOW);
  }
}
