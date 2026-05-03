```cpp
int buttonPin = 12;   // Button pin
int ledPin = 13;      // LED pin
int count = 0;        // Press counter

void setup() {
  pinMode(buttonPin, INPUT_PULLUP); // Internal pull-up
  pinMode(ledPin, OUTPUT);          // LED output
  Serial.begin(9600);               // Start Serial Monitor
}

void loop() {
  count = 0; // Reset counter

  // Read button 10 times in 1 second (100ms × 10)
  for (int i = 0; i < 10; i++) {
    if (digitalRead(buttonPin) == LOW) {
      count++;
      digitalWrite(ledPin, HIGH);
      delay(200);
      digitalWrite(ledPin, LOW);

      while (digitalRead(buttonPin) == LOW); // Wait until release
    }
    delay(100);
  }

  // Print the count to serial monitor
  Serial.print("Press count: ");
  Serial.println(count);

  // Task based on press count
  if (count == 1) {
    Serial.println("Running Task 1: Simple LED blink");
    digitalWrite(ledPin, HIGH);
    delay(500);
    digitalWrite(ledPin, LOW);
  } 
  else if (count == 2) {
    Serial.println("Running Task 2: Fast LED blink 3 times");
    for (int i = 0; i < 3; i++) {
      digitalWrite(ledPin, HIGH);
      delay(100);
      digitalWrite(ledPin, LOW);
      delay(100);
    }
  }
  else if (count == 3) {
    Serial.println("Running Task 3: Long LED ON");
    digitalWrite(ledPin, HIGH);
    delay(1500);
    digitalWrite(ledPin, LOW);
  } 
  else {
    Serial.println("No valid task assigned for this count.");
  }

  delay(2000); // Wait before next cycle
}

About

No description, website, or topics provided.
Resources
 Readme
 Activity
Stars
 1 star
Watchers
 0 watching
Forks
 0 forks
Releases

No releases published
Create a new release
Packages

No packages published
Publish your first package
Contributors
1

@XunidEmon
XunidEmon Emon
Footer
© 2026 GitHub, Inc.
