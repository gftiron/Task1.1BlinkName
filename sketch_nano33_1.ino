
// Define pin numbers
const int buttonPin = 2;    // Push button pin
const int ledPin = LED_BUILTIN;  // Built-in LED pin

// Morse code for the letters in the name "GEORGE"
const int morseCode[] = {
  // G
  HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, LOW, LOW,  // --.
  // E
  HIGH, LOW, LOW, LOW,  // .
  // O
  HIGH, HIGH, HIGH, LOW, HIGH, HIGH, HIGH, LOW,  // ---
  // R
  HIGH, HIGH, HIGH, LOW, HIGH, HIGH, LOW, LOW,  // .-.
  // G 
  HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, LOW, LOW,  // --.
  // E 
  HIGH, LOW, LOW, LOW,  // .
};

// Define Morse code timings (milliseconds)
const int dotDuration = 200;
const int dashDuration = dotDuration * 3;
const int interElementPause = dotDuration;
const int interCharacterPause = dotDuration * 3;
const int interWordPause = dotDuration * 7;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);  // Set button pin as input
  pinMode(ledPin, OUTPUT);           // Set LED pin as output
}

void loop() {
  if (digitalRead(buttonPin) == LOW) {  // If the button is pressed
    // Loop through the Morse code and blink the LED accordingly
    for (int i = 0; i < sizeof(morseCode) / sizeof(morseCode[0]); i++) {
      int duration = (morseCode[i] == HIGH) ? dotDuration : interElementPause;
      digitalWrite(ledPin, morseCode[i]);
      delay(duration);
    }
    // Pause before restarting the loop
    delay(interWordPause);
  }
}
