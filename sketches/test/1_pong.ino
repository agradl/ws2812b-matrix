class Pong : public Routine {
  public:
    int time;
    int pathIndex = 0;
    int games = 0;
    void setup(){
      time = 0;
      pathIndex = 0;
    }
    bool loop(){
      
      EVERY_N_MILLISECONDS( 100 ) {
        update(time++); 
      }
      if (pathIndex >= ballPath1().size()){
        setup();
        games++;
        if (games >= 3){
          return false;
        }
      }
      return true;
    }

    void update(int t){
      clearLEDs();
      std::vector<int> coords = ballPath1().at(pathIndex);
      
      setLED(coords.at(0), coords.at(1), 0xffffff);

      Image(0, paddlePath1().at(pathIndex), paddle());

      Image(15, paddlePath2().at(pathIndex), paddle());
      
      pathIndex++;
    }

    std::vector<std::vector<unsigned int>> paddle(){
      std::vector<std::vector<unsigned int>> imageData = {{0,0,0xffffff}, {0,1,0xffffff}, {0,2,0xffffff}, {0,3,0xffffff}};
      return imageData;
    }

    std::vector<int> paddlePath1(){
      std::vector<int> pathData = {11,10,9,8,7,6,5,5,5,5,6,7,7,7,7,7,7,7,7,8,8,7,6,6,6,6,6,6,6,6,6,6,6,6,6,7,8,9,10,11,12,12,12,12,12,12,12,12,11,10,9,8,7,6,5,4,3,2,1,0,1,2,3,4,5,5,5,5,5};
      return pathData;
    }
    
    std::vector<int> paddlePath2(){
      std::vector<int> pathData = {0,1,2,3,4,5,5,5,5,5,6,7,8,9,10,10,9,8,7,6,5,4,3,2,1,0,0,1,2,3,4,5,5,5,5,5,6,7,8,9,10,10,9,8,7,6,5,4,3,2,1,0,1,2,3,4,5,5,5,5,5};
      return pathData;
    }

    std::vector<std::vector<int>> ballPath1(){
      std::vector<std::vector<int>> pathData = {{8,11},{9,11},{10,10},{11,10},{12,9},{13,9},{14,8},{13,8},{12,8},{11,8},{10,8},{9,8},{8,8},{7,8},{6,8},{5,8},{4,8},{3,8},{2,8},{1,8},{2,7},{3,6},{4,5},{5,4},{6,3},{7,2},{8,1},{9,0},{10,1},{11,2},{12,3},{13,4},{14,5},{13,6},{12,6},{11,7},{10,7},{9,8},{8,8},{7,9},{6,9},{5,10},{4,10},{3,11},{2,11},{1,12},{2,13},{3,14},{4,15},{5,14},{6,13},{7,12},{8,11},{9,10},{10,9},{11,8},{12,7},{13,6},{14,5},{15,4}};
      return pathData;
    }

};
