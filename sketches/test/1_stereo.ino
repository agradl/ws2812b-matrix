
class Stereo : public Routine {
  public:
    int time;
    void setup(){
      time = 0;
      
    }

    void fadeAll(){
      for(int i = 0; i < NUM_LEDS; i++){
        leds[i].nscale8(200);
      }
    }

    
    
    bool loop(){
      int pos[16] = {15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15};

      while(true){
        for(int x = 0; x < 16; x++){
          if (pos[x] == 15){
            pos[x] = random(0,14);
          } else {
            for (int y = 15; y > pos[x]; y--){
              setLED(x, y, CHSV(90 + pos[x] * 10, 255, 255));
            }
            pos[x] = pos[x] + 1;
          }
        }
        FastLED.show();
        fadeAll();
        delay(30);
        if (time > 600){
          return false;
        }
        time++;
      }
      
      return true;
    }
};
