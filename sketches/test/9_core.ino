int mode = 0;
bool isSetup = false;
Routine* currentRoutine;
int availableRoutines = 6;
unsigned int routineCount = 0;
bool isOn = false;
void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(14, OUTPUT);
    Serial.begin(74880);  
    toggleLight();
    delay( 3000 ); // power-up safety delay
    toggleLight();
    Serial.println("setup");  
    FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);
    FastLED.setBrightness(BRIGHTNESS);
//    fill_solid( leds, 2, CHSV( HSVHue::HUE_PINK, 255, 255));
    delay( 2000 ); // power-up safety delay
    clearLEDs();
    FastLED.show();
    switchRoutine();
    if (!currentRoutine){
      Serial.println("creating new pacman");
      currentRoutine = new Pacman();
    }
    Serial.println("done with setup");
}

void toggleLight(){
  if (isOn) {
    digitalWrite(LED_BUILTIN, HIGH);
    digitalWrite(14, LOW);
  } else {
    digitalWrite(LED_BUILTIN, LOW);
    digitalWrite(14, HIGH);
  }
  isOn = !isOn;
}

bool tested = false;
void loop()
{
    if (!tested){
      powerUpTest();
      tested = true;
    }
    bool isRunning = currentRoutine->doLoop();
    FastLED.show();
    delay(10);
    if (!isRunning){
      switchRoutine();
    }
}

void switchRoutine(){
  toggleLight();
  if (currentRoutine){
    delete currentRoutine;
  }
  if (routineCount % availableRoutines == 0){
    Serial.println("starting Pacman");
    currentRoutine = new Pacman();
  }
  if (routineCount % availableRoutines == 1){
    Serial.println("starting Ufo");
    currentRoutine = new Ufo();
  }
  if (routineCount % availableRoutines == 2){
    Serial.println("starting Pong");
    currentRoutine = new Pong();
  }
  if (routineCount % availableRoutines == 3){
    Serial.println("starting Noise");
    currentRoutine = new Noise();
  }
  if (routineCount % availableRoutines == 4){
    Serial.println("starting Rainbow");
    currentRoutine = new Rainbow();
  }
  if (routineCount % availableRoutines == 5){
    Serial.println("starting Stereo");
    currentRoutine = new Stereo();
  }
  routineCount++;
}

void powerUpTest(){
  Serial.println("power up test");
  for (int x = 0; x < 16; x++){
    for(int y = 0; y < 16; y++){
      setLED(x,y,CHSV( HSVHue::HUE_PINK, 255, 255));
      
    }
    Serial.println("added row.");
    FastLED.show();
    delay(100);
  }
  Serial.println("done with power up test");
}

void clearLEDs(){
  fill_solid( leds, NUM_LEDS, CRGB::Black);
}
