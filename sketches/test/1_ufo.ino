class Ufo : public Routine {
  public:
    int phase;
    int ufoY;
    int dino1X;
    int dino2X;
    int time;
    CHSV dinoDimGreen = CHSV(HSVHue::HUE_GREEN, 255, 120);
    CHSV dinoBrightGreen = CHSV(HSVHue::HUE_PURPLE, 255, 255);
    void setup(){
      time = 0;
      dino1X = -7;
      dino2X = 15;
      ufoY = -10;
      phase = 1;
    }
    bool loop(){
      
      EVERY_N_MILLISECONDS( 200 ) {
        update(time++); 
      }
      if (time > 50){
        setup();
        return false;
      }
      return true;
    }

    void update(int t){
      clearLEDs();
      //dinos walking out
      if (phase == 1){
        Image(dino1X, 11 + (dino1X % 2), dino1(), dinoDimGreen);
        Image(dino2X, 11 - (dino2X % 2), dino2(), dinoDimGreen);
        if (t % 2 == 0){
          dino1X++;
          dino2X--;  
        }
        
      }

      //ufo descending
      if (phase == 2){
        Image(0, ufoY, ufo());
        Image(dino1X, 11, dino1(), dinoDimGreen);
        Image(dino2X, 11, dino2(), dinoDimGreen);
        if (ufoY < 0){
          ufoY++;  
        }
      }

      //beam
      if (phase == 3){
        Image(0, ufoY, ufo());
        if (t % 3 != 0){
          Image(0, 0, beam());  
          Image(dino1X, 11, dino1(), dinoBrightGreen);
          Image(dino2X, 11, dino2(), dinoBrightGreen);
        } else {
          Image(dino1X, 11, dino1(), dinoDimGreen);
          Image(dino2X, 11, dino2(), dinoDimGreen);  
        }
        
        
      }
      

      if (phase == 1 && dino1X == 0){
        phase++;
      }
      if (phase ==2 && ufoY == 0 && t % 5 == 0){
        phase++;
      }
    }

    std::vector<std::vector<unsigned int>> dino2(){
      std::vector<std::vector<unsigned int>> dinoImageData2 = {{3,1,0x00aa00},{3,0,0x00aa00},{2,1,0x00aa00},{0,2,0x00aa00},{1,2,0x00aa00},{2,2,0x00aa00},{3,2,0x00aa00},{4,1,0x00aa00},{4,2,0x00aa00},{5,2,0x00aa00},{6,3,0x00aa00},{7,2,0x00aa00},{4,3,0x00aa00},{4,4,0x00aa00},{2,3,0x00aa00},{2,4,0x00aa00}};
      return dinoImageData2;
    }

    std::vector<std::vector<unsigned int>> dino1(){
      std::vector<std::vector<unsigned int>> dinoImageData1 = {{0,4,0x00ff00},{1,4,0x00ff00},{2,3,0x00ff00},{3,3,0x00ff00},{3,4,0x00ff00},{4,3,0x00ff00},{5,4,0x00ff00},{3,2,0x00ff00},{4,2,0x00ff00},{5,2,0x00ff00},{4,1,0x00ff00},{5,0,0x00ff00},{6,0,0x00ff00}};
      return dinoImageData1;
    }

    std::vector<std::vector<unsigned int>> beam(){
      std::vector<std::vector<unsigned int>> beamImageData = {{6,8,0xffff00},{7,8,0xffff00},{8,8,0xffff00},{9,8,0xffff00},{10,9,0xffff00},{11,10,0xffff00},{12,11,0xffff00},{13,12,0xffff00},{14,13,0xffff00},{15,14,0xffff00},{15,15,0xffff00},{14,15,0xffff00},{14,14,0xffff00},{13,14,0xffff00},{13,15,0xffff00},{12,14,0xffff00},{11,14,0xffff00},{11,15,0xffff00},{12,15,0xffff00},{10,14,0xffff00},{10,15,0xffff00},{9,15,0xffff00},{9,14,0xffff00},{8,14,0xffff00},{8,15,0xffff00},{7,15,0xffff00},{7,14,0xffff00},{6,14,0xffff00},{6,15,0xffff00},{5,15,0xffff00},{5,14,0xffff00},{4,14,0xffff00},{4,15,0xffff00},{3,14,0xffff00},{3,15,0xffff00},{2,15,0xffff00},{2,14,0xffff00},{1,14,0xffff00},{1,15,0xffff00},{0,14,0xffff00},{0,15,0xffff00},{5,9,0xffff00},{4,10,0xffff00},{3,11,0xffff00},{2,12,0xffff00},{1,13,0xffff00},{2,13,0xffff00},{3,13,0xffff00},{3,12,0xffff00},{4,12,0xffff00},{4,13,0xffff00},{4,11,0xffff00},{5,11,0xffff00},{5,12,0xffff00},{5,13,0xffff00},{6,13,0xffff00},{6,12,0xffff00},{6,11,0xffff00},{6,10,0xffff00},{5,10,0xffff00},{6,9,0xffff00},{7,9,0xffff00},{7,10,0xffff00},{7,11,0xffff00},{7,12,0xffff00},{7,13,0xffff00},{8,13,0xffff00},{8,12,0xffff00},{8,11,0xffff00},{8,10,0xffff00},{8,9,0xffff00},{9,10,0xffff00},{9,9,0xffff00},{9,11,0xffff00},{9,12,0xffff00},{9,13,0xffff00},{10,13,0xffff00},{10,12,0xffff00},{10,11,0xffff00},{10,10,0xffff00},{11,11,0xffff00},{11,12,0xffff00},{11,13,0xffff00},{12,13,0xffff00},{12,12,0xffff00},{13,13,0xffff00}};
      return beamImageData;
    }

    std::vector<std::vector<unsigned int>> ufo(){
      std::vector<std::vector<unsigned int>> ufoImageData = {{3,3,0xff2fe0},{2,3,0xff2fe0},{1,4,0xff2fe0},{1,5,0xff2fe0},{2,5,0xff2fe0},{3,5,0xff2fe0},{4,5,0xff2fe0},{6,6,0xff2fe0},{5,5,0xff2fe0},{7,6,0xff2fe0},{8,6,0xff2fe0},{9,6,0xff2fe0},{10,5,0xff2fe0},{12,5,0xff2fe0},{11,5,0xff2fe0},{13,5,0xff2fe0},{14,5,0xff2fe0},{14,4,0xff2fe0},{13,3,0xff2fe0},{12,3,0xff2fe0},{5,3,0xff2fe0},{4,3,0xff2fe0},{4,4,0xff2fe0},{3,4,0xff2fe0},{2,4,0xff2fe0},{5,4,0xff2fe0},{6,4,0xff2fe0},{7,5,0xff2fe0},{6,5,0xff2fe0},{7,4,0xff2fe0},{8,4,0xff2fe0},{8,5,0xff2fe0},{9,5,0xff2fe0},{9,4,0xff2fe0},{10,3,0xff2fe0},{10,4,0xff2fe0},{11,3,0xff2fe0},{11,4,0xff2fe0},{12,4,0xff2fe0},{13,4,0xff2fe0},{3,6,0xff2fe0},{4,6,0xff2fe0},{5,6,0xff2fe0},{10,6,0xff2fe0},{11,6,0xff2fe0},{12,6,0xff2fe0},{6,7,0xff2fe0},{7,7,0xff2fe0},{8,7,0xff2fe0},{9,7,0xff2fe0},{4,2,0xffcaf8},{5,2,0xffcaf8},{6,3,0xffcaf8},{7,3,0xffcaf8},{6,2,0xffcaf8},{6,1,0xffcaf8},{5,1,0xffcaf8},{7,0,0xffcaf8},{7,1,0xffcaf8},{7,2,0xffcaf8},{8,0,0xffcaf8},{8,1,0xffcaf8},{8,2,0xffcaf8},{8,3,0xffcaf8},{9,3,0xffcaf8},{9,2,0xffcaf8},{9,1,0xffcaf8},{10,1,0xffcaf8},{10,2,0xffcaf8},{11,2,0xffcaf8}};
      return ufoImageData;
    }
};
