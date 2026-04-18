const byte ROWS[8] = {2, 3, 4, 5, 6, 7, 8, 9};
const byte COLS[8] = {13, 12, 11, 10, A2, A3, A4, A5};

byte frame[8];

void setup() {
  for (byte i = 0; i < 8; i++) {
    pinMode(ROWS[i], OUTPUT);
    pinMode(COLS[i], OUTPUT);
  }
}

void loop() {
  runWaveDown();
  runWaveUp();
  runExpandFromCenter();
  runCheckerAnimation();
  runRandomSparkle();
}

void renderFrame() {
  for (byte row = 0; row < 8; row++) {

    for (byte i = 0; i < 8; i++) {
      digitalWrite(ROWS[i], LOW);
      digitalWrite(COLS[i], HIGH);
    }

    digitalWrite(ROWS[row], HIGH);

    for (byte col = 0; col < 8; col++) {
      bool ledState = bitRead(frame[row], 7 - col);
      digitalWrite(COLS[col], ledState ? LOW : HIGH);
    }

    delayMicroseconds(800);
  }
}

void clearFrame() {
  for (byte i = 0; i < 8; i++) {
    frame[i] = 0;
  }
}

void showFrame(byte times) {
  for (byte i = 0; i < times * 8; i++) {
    renderFrame();
  }
}

void runWaveDown() {
  for (byte i = 0; i < 8; i++) {
    clearFrame();
    frame[i] = B11111111;
    showFrame(5);
  }
}

void runWaveUp() {
  for (int i = 7; i >= 0; i--) {
    clearFrame();
    frame[i] = B11111111;
    showFrame(5);
  }
}

void runExpandFromCenter() {
  clearFrame();

  for (byte i = 0; i <= 3; i++) {
    frame[3 - i] = B11111111;
    frame[4 + i] = B11111111;
    showFrame(5);
  }
}

void runCheckerAnimation() {
  for (byte cycle = 0; cycle < 4; cycle++) {

    for (byte r = 0; r < 8; r++) {
      frame[r] = (r % 2 == 0) ? B10101010 : B01010101;
    }
    showFrame(5);

    for (byte r = 0; r < 8; r++) {
      frame[r] = (r % 2 == 0) ? B01010101 : B10101010;
    }
    showFrame(5);
  }
}

void runRandomSparkle() {
  for (byte t = 0; t < 30; t++) {
    clearFrame();

    for (byte i = 0; i < 10; i++) {
      byte r = random(0, 8);
      byte c = random(0, 8);
      bitWrite(frame[r], 7 - c, 1);
    }

    showFrame(3);
  }
}