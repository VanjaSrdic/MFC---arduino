const int numPins = 16;
int inputPins[numPins] = {A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15};

void setup() {
  for (int i = 0; i < numPins; i++) {
    pinMode(inputPins[i], INPUT);
  }

  Serial.begin(9600);
  Serial.println(",Celija1, Celija2, Celija3, Celija4, Celija5, Celija6, Celija7, Celija8, Celija9, Celija10, Celija11, Celija12, Celija13, Celija13, Celija15, Celija16");
}

void loop() {
  Serial.print(",");
  for (int i = 0; i < numPins; i++) {
    int cellValue = analogRead(inputPins[i]);
    float voltage = cellValue * (5.0 / 1024.0);

    Serial.print(voltage);
    if (i < numPins - 1) {
      Serial.print(", "); // print comma after each value, except for the last one
    } else {
  delay(1000); // delay for a second
}
