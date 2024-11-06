#include <Servo.h>  // Include biblioteca Servo pentru a controla servomotoarele
Servo myservo;  // Creează un obiect Servo pentru a controla servomotorul

// Definește pinii pentru senzorul ultrasonic
#define echoPin 5  // Pinul de la care se primește semnalul de ecou
#define trigPin 6  // Pinul care trimite semnalul de triggerc:\Users\vigna\Documents\Programare (macar incerc)\Arduinoooooooooooooooooooooooooooooooo\incercare_masinuta\incercare_masinuta.ino

int distance;  // Variabila pentru a stoca distanța măsurată
int duration;  // Variabila pentru a stoca durata impulsului de ecou

void setup() {
  myservo.attach(9);  // Atașează servomotorul la pinul digital 9
  pinMode(trigPin, OUTPUT);  // Setează pinul trigPin ca ieșire
  pinMode(echoPin, INPUT);  // Setează pinul echoPin ca intrare
  Serial.begin(115200);  // Inițializează comunicația serială la 115200 bauds
  delay(0);  // Mică întârziere pentru a stabiliza sistemul (opțional)
}

void ionel_voinic(int pos) {
  myservo.write(pos);  // Setează servomotorul la poziția specificată

  // Trimite un impuls scurt de trigger
  digitalWrite(trigPin, LOW);  // Setează trigPin la LOW
  delayMicroseconds(2);  // Așteaptă 2 microsecunde
  digitalWrite(trigPin, HIGH);  // Setează trigPin la HIGH
  delayMicroseconds(10);  // Așteaptă 10 microsecunde
  digitalWrite(trigPin, LOW);  // Setează trigPin la LOW

  // Citește durata impulsului de ecou
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.0344 / 2;  // Calculează distanța în centimetri

  // Trimite distanța măsurată la monitorul serial
  Serial.print(distance);
  //Serial.print();  // Această linie nu are niciun parametru, va cauza o eroare de compilare
  delay(17);  // Mică întârziere pentru a preveni suprasolicitarea senzorului
}

void loop() {
  // Mută servomotorul de la 180 la 0 grade
  for (int pos = 180; pos > 0; pos--) {
    ionel_voinic(pos); 
  }

  // Mută servomotorul de la 0 la 180 grade
  for (int pos = 0; pos < 180; pos++) {
    ionel_voinic(pos);                                  
  }
}
