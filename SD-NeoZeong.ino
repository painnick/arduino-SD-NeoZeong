// Group A : PWM
#define GREEN_LED_1 6
#define GREEN_LED_2 9

// Group B : Always On
#define SKIRT_BOTTOM 1
#define SKIRT_BACK 8
#define SHOULDER 3
#define TURN_TABLE 4

// Group C : Changing
#define FINGER 5
#define POINT_ORANGE 7
#define POINT_BLUE 2

#define DELAY_MS 200

#define GREEN_BRIGHT_STEPS 9
int GREEN_BRIGHT[GREEN_BRIGHT_STEPS];

#define FINGER_LED_TICKS 8
#define POINT_ORANGE_LED_TICKS 8
#define POINT_BLUE_LED_TICKS 6

void setup() {
  // Init. GREEN_BRIGHT
  GREEN_BRIGHT[0] = 63;
  GREEN_BRIGHT[1] = 127;
  GREEN_BRIGHT[2] = 191;
  GREEN_BRIGHT[3] = 255;
  GREEN_BRIGHT[4] = 191;
  GREEN_BRIGHT[5] = 127;
  GREEN_BRIGHT[6] = 15;
  GREEN_BRIGHT[7] = 0;
  GREEN_BRIGHT[8] = 0;

  // Group A
  pinMode(GREEN_LED_1, OUTPUT);
  pinMode(GREEN_LED_2, OUTPUT);
  // Group B
  pinMode(SKIRT_BOTTOM, OUTPUT);
  pinMode(SKIRT_BACK, OUTPUT);
  pinMode(SHOULDER, OUTPUT);
  pinMode(TURN_TABLE, OUTPUT);
  // Group C
  pinMode(FINGER, OUTPUT);
  pinMode(POINT_ORANGE, OUTPUT);
  pinMode(POINT_BLUE, OUTPUT);
  
  // Group A
  analogWrite(GREEN_LED_1, 255);
  analogWrite(GREEN_LED_2, 255);
  // Group B
  digitalWrite(SKIRT_BOTTOM, HIGH);
  digitalWrite(SKIRT_BACK, HIGH);
  digitalWrite(SHOULDER, HIGH);
  digitalWrite(TURN_TABLE, HIGH);
  // Group C
  digitalWrite(FINGER, HIGH);
  digitalWrite(POINT_ORANGE, HIGH);
  digitalWrite(POINT_BLUE, HIGH);
}

int tick = 0;
void loop() {
  tick = (++tick) % (GREEN_BRIGHT_STEPS * FINGER_LED_TICKS * POINT_BLUE_LED_TICKS * POINT_ORANGE_LED_TICKS);
  flashGreen(tick);
  flashFinger(tick);
  flashPointOrange(tick);
  flashPointBlue(tick);
  delay(DELAY_MS);
}


void flashGreen(int tick) {
  int index = tick % GREEN_BRIGHT_STEPS;
  int bright = GREEN_BRIGHT[index];
  analogWrite(GREEN_LED_1, bright);
  analogWrite(GREEN_LED_2, bright);
}

void flashFinger(int tick) {
  int value = tick % GREEN_BRIGHT_STEPS;
  if(value < 3) {
   digitalWrite(FINGER, HIGH);
 } else {
   digitalWrite(FINGER, LOW);
 }
}

void flashPointOrange(int tick) {
  int value = tick % POINT_ORANGE_LED_TICKS;
  if(value < 3) {
   digitalWrite(POINT_ORANGE, HIGH);
 } else {
   digitalWrite(POINT_ORANGE, LOW);
 }
}

void flashPointBlue(int tick) {
  int value = tick % POINT_BLUE_LED_TICKS;
  if(value < (POINT_BLUE_LED_TICKS / 2)) {
   digitalWrite(POINT_BLUE, HIGH);
 } else {
   digitalWrite(POINT_BLUE, LOW);
 }
}