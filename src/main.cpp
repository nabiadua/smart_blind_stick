
#include <Arduino.h>

#define TRIG 11
#define ECHO 10
#define BUZZER 13

long duration;
int distance;

void setup() {
    pinMode(TRIG, OUTPUT);
    pinMode(ECHO, INPUT);
    pinMode(BUZZER, OUTPUT);

    Serial.begin(9600);
}

void loop() {

    digitalWrite(TRIG, LOW);
    delayMicroseconds(2);

    digitalWrite(TRIG, HIGH);
    delayMicroseconds(10);

    digitalWrite(TRIG, LOW);

    duration = pulseIn(ECHO, HIGH, 30000);

    if (duration == 0) {
        noTone(BUZZER);
        delay(100);
        return;
    }

    distance = duration * 0.0343 / 2;

    Serial.print("Obstacle Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    if (distance <= 30) {
        tone(BUZZER, 2000);
        delay(100);
        noTone(BUZZER);
        delay(100);
    }
    else if (distance <= 60) {
        tone(BUZZER, 1500);
        delay(150);
        noTone(BUZZER);
        delay(400);
    }
    else if (distance <= 100) {
        tone(BUZZER, 1000);
        delay(150);
        noTone(BUZZER);
        delay(800);
    }
    else {
        noTone(BUZZER);
        delay(100);
    }
}
