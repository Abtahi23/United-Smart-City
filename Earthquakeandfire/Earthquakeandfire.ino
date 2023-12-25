//Viral Science www.youtube.com/c/viralscience
//Arduino Flame and Vibration Sensor

const int buzzerPin = 12;
const int flamePin = 11;
int Flame = HIGH;
int redled = 5;
int greenled = 6;

int LED_Pin = 9;
int vibr_Pin = 8;

void setup()
{
  pinMode(buzzerPin, OUTPUT);
  pinMode(redled, OUTPUT);
  pinMode(greenled, OUTPUT);

  pinMode(flamePin, INPUT);

  pinMode(LED_Pin, OUTPUT);
  pinMode(vibr_Pin, INPUT);

  Serial.begin(9600);
}

void loop()
{
  // Flame Sensor
  Flame = digitalRead(flamePin);
  if (Flame == LOW)
  {
    digitalWrite(buzzerPin, LOW);
    digitalWrite(redled, HIGH);
    digitalWrite(greenled, LOW);
  }
  else
  {
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(greenled, HIGH);
    digitalWrite(redled, LOW);
  }

  // Vibration Sensor
  long measurement = TP_init();
  delay(50);
  Serial.println(measurement);
  if (measurement > 1000)
  {
    digitalWrite(LED_Pin, HIGH);
  }
  else
  {
    digitalWrite(LED_Pin, LOW);
  }
}

long TP_init()
{
  delay(10);
  long measurement = pulseIn(vibr_Pin, HIGH);
  return measurement;
}

