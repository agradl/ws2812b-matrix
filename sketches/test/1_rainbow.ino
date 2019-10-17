
class Rainbow : public Routine {
  public:
    int time;
    void setup(){
      time = 0;
      
    }

    void fadeAll(){
      for(int i = 0; i < NUM_LEDS; i++){
        leds[i].nscale8(230);
      }
    }
    
    bool loop(){
      int hue = 0;
      int index = 0;
      while(true){
        for (int i = 0; i < 32; i++){
          setLED(i % 16, (16 - i) + (index % 16), CHSV(hue + (15 * i), 255, 255));
        }
        index++;
        hue = hue + 15;
        if (hue > 255){
          hue = 0;
        }
        FastLED.show();
        fadeAll();
        delay(50);
        if (index > 500){
          return false;
        }
      }
      
      return true;
    }
};
