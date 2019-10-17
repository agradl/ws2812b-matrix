

class Pacman : public Routine {
public:
int dots[3][2] = {{5,8}, {9,8}, {13,8}};
int pacmanX;
int pacmanY;
int ghostX;
int ghostY;
int dir;
int time;
  void setup(){
      Serial.println("pacman setup");
      initialized = true;
      pacmanX = -8;
      pacmanY = 4;
      ghostX = -18;
      ghostY = 4;
      dir = 1;
      time = 0;
  }
  bool loop(){
      
      EVERY_N_MILLISECONDS( 200 ) {
        update(time); 
      }
      if (pacmanX < -8){
        setup();
        return false;
      }
      return true;
    }

    void update(int t){
      clearLEDs();
      pacmanX += dir;
      ghostX += dir;

      Image(0, 0, border());
      for (int i = 0; i < 3; i++){
        if (dots[i][0] > (pacmanX + 6) && dir > 0){
          Image(dots[i][0], dots[i][1], dot(), 0xffffff);  
        }
      }

      if (pacmanX % 2 == 0){
        if (dir > 0){
          Image(pacmanX, pacmanY, pacmanOpen());     
        } else {
          Image(pacmanX, pacmanY, pacmanOpenLeft());   
        }
      } else {
        Image(pacmanX, pacmanY, pacmanClosed());   
      }
      if (dir > 0){
        Image(ghostX, ghostY, ghost1());   
      } else {
        Image(ghostX, ghostY, ghost2());   
      }
      
      if (ghostX > 15){
        dir = -1;
      }
    }

    std::vector<std::vector<unsigned int>> dot(){
      std::vector<std::vector<unsigned int>> dotImageData = {{0,0,0xffffff}};
      return dotImageData;
    }

    std::vector<std::vector<unsigned int>> pacmanOpen(){
      std::vector<std::vector<unsigned int>> imageData = {{2,1,0xfffb00},{1,2,0xfffb00},{0,3,0xfffb00},{0,4,0xfffb00},{0,5,0xfffb00},{6,2,0xfffb00},{5,3,0xfffb00},{1,6,0xfffb00},{2,7,0xfffb00},{6,6,0xfffb00},{5,5,0xfffb00},{4,5,0xfffb00},{5,2,0xfffb00},{5,1,0xfffb00},{4,1,0xfffb00},{3,1,0xfffb00},{3,2,0xfffb00},{4,2,0xfffb00},{4,3,0xfffb00},{3,3,0xfffb00},{2,2,0xfffb00},{2,3,0xfffb00},{1,3,0xfffb00},{1,4,0xfffb00},{2,4,0xfffb00},{3,4,0xfffb00},{3,5,0xfffb00},{2,5,0xfffb00},{1,5,0xfffb00},{2,6,0xfffb00},{3,6,0xfffb00},{3,7,0xfffb00},{4,7,0xfffb00},{4,6,0xfffb00},{5,7,0xfffb00},{5,6,0xfffb00}};
      return imageData;
    }
    std::vector<std::vector<unsigned int>> pacmanOpenLeft(){
      std::vector<std::vector<unsigned int>> imageData = {{2,1,0xfffb00},{1,2,0xfffb00},{6,2,0xfffb00},{5,3,0xfffb00},{1,6,0xfffb00},{2,7,0xfffb00},{6,6,0xfffb00},{5,5,0xfffb00},{4,5,0xfffb00},{5,2,0xfffb00},{5,1,0xfffb00},{4,1,0xfffb00},{3,1,0xfffb00},{3,2,0xfffb00},{4,2,0xfffb00},{4,3,0xfffb00},{3,3,0xfffb00},{2,2,0xfffb00},{2,3,0xfffb00},{3,5,0xfffb00},{2,5,0xfffb00},{2,6,0xfffb00},{3,6,0xfffb00},{3,7,0xfffb00},{4,7,0xfffb00},{4,6,0xfffb00},{5,7,0xfffb00},{5,6,0xfffb00},{6,3,0xfffb00},{4,4,0xfffb00},{5,4,0xfffb00},{6,4,0xfffb00},{6,5,0xfffb00},{7,3,0xfffb00},{7,4,0xfffb00},{7,5,0xfffb00}};
      return imageData;
    }
    std::vector<std::vector<unsigned int>> pacmanClosed(){
      std::vector<std::vector<unsigned int>> imageData = {{2,1,0xfffb00},{1,2,0xfffb00},{0,3,0xfffb00},{0,4,0xfffb00},{0,5,0xfffb00},{6,2,0xfffb00},{5,3,0xfffb00},{1,6,0xfffb00},{2,7,0xfffb00},{6,6,0xfffb00},{5,5,0xfffb00},{4,5,0xfffb00},{5,2,0xfffb00},{5,1,0xfffb00},{4,1,0xfffb00},{3,1,0xfffb00},{3,2,0xfffb00},{4,2,0xfffb00},{4,3,0xfffb00},{3,3,0xfffb00},{2,2,0xfffb00},{2,3,0xfffb00},{1,3,0xfffb00},{1,4,0xfffb00},{2,4,0xfffb00},{3,4,0xfffb00},{3,5,0xfffb00},{2,5,0xfffb00},{1,5,0xfffb00},{2,6,0xfffb00},{3,6,0xfffb00},{3,7,0xfffb00},{4,7,0xfffb00},{4,6,0xfffb00},{5,7,0xfffb00},{5,6,0xfffb00},{6,3,0xfffb00},{6,4,0xfffb00},{6,5,0xfffb00},{5,4,0xfffb00},{4,4,0xfffb00},{7,5,0xfffb00},{7,4,0xfffb00},{7,3,0xfffb00}};
      return imageData;
    }
    std::vector<std::vector<unsigned int>> ghost1(){
      std::vector<std::vector<unsigned int>> imageData = {{0,7,0xff00d9},{0,6,0xff00d9},{0,5,0xff00d9},{1,4,0xff00d9},{1,3,0xff00d9},{1,2,0xff00d9},{2,1,0xff00d9},{3,0,0xff00d9},{4,0,0xff00d9},{6,2,0xff00d9},{5,1,0xff00d9},{5,2,0xff00d9},{6,3,0xff00d9},{6,4,0xff00d9},{6,5,0xff00d9},{7,5,0xff00d9},{7,6,0xff00d9},{7,7,0xff00d9},{4,1,0xff00d9},{3,1,0xff00d9},{3,2,0xff00d9},{2,4,0xff00d9},{3,4,0xff00d9},{4,4,0xff00d9},{5,4,0xff00d9},{1,5,0xff00d9},{2,5,0xff00d9},{3,5,0xff00d9},{4,5,0xff00d9},{5,5,0xff00d9},{1,6,0xff00d9},{2,6,0xff00d9},{3,6,0xff00d9},{4,6,0xff00d9},{5,6,0xff00d9},{6,6,0xff00d9},{5,7,0xff00d9},{2,7,0xff00d9},{2,3,0xffffff},{2,2,0xffffff},{4,3,0xffffff},{4,2,0xffffff},{3,3,0x000000},{5,3,0x000000}};
      return imageData;
    }
    std::vector<std::vector<unsigned int>> ghost2(){
      std::vector<std::vector<unsigned int>> imageData = {{3,0,0x2d2dff},{4,0,0x2d2dff},{4,1,0x2d2dff},{2,2,0xc4c08c},{3,1,0x2d2dff},{2,1,0x2d2dff},{5,1,0x2d2dff},{6,2,0x2d2dff},{6,3,0x2d2dff},{6,4,0x2d2dff},{6,5,0x2d2dff},{7,5,0x2d2dff},{6,6,0x2d2dff},{7,6,0x2d2dff},{7,7,0x2d2dff},{5,7,0x2d2dff},{5,6,0x2d2dff},{5,4,0x2d2dff},{4,5,0x2d2dff},{4,6,0x2d2dff},{3,4,0x2d2dff},{3,6,0x2d2dff},{2,7,0x2d2dff},{2,6,0x2d2dff},{2,5,0x2d2dff},{1,3,0x2d2dff},{1,2,0x2d2dff},{1,4,0x2d2dff},{1,6,0x2d2dff},{0,7,0x2d2dff},{0,6,0x2d2dff},{0,5,0x2d2dff},{3,2,0x2d2dff},{3,3,0x2d2dff},{5,3,0x2d2dff},{2,3,0x2d2dff},{4,3,0x2d2dff},{4,2,0x2d2dff},{5,2,0xc4c08c},{1,5,0xc4c08c},{2,4,0xc4c08c},{3,5,0xc4c08c},{4,4,0xc4c08c},{5,5,0xc4c08c}};
      return imageData;
    }
    std::vector<std::vector<unsigned int>> border(){
      std::vector<std::vector<unsigned int>> imageData = {{0,0,0x0000d9},{1,0,0x0000d9},{2,0,0x0000d9},{3,0,0x0000d9},{4,0,0x0000d9},{5,0,0x0000d9},{6,0,0x0000d9},{7,0,0x0000d9},{8,0,0x0000d9},{9,0,0x0000d9},{10,0,0x0000d9},{11,0,0x0000d9},{12,0,0x0000d9},{13,0,0x0000d9},{14,0,0x0000d9},{15,0,0x0000d9},{15,2,0x0000d9},{13,2,0x0000d9},{14,2,0x0000d9},{12,2,0x0000d9},{10,2,0x0000d9},{11,2,0x0000d9},{9,2,0x0000d9},{7,2,0x0000d9},{8,2,0x0000d9},{5,2,0x0000d9},{6,2,0x0000d9},{4,2,0x0000d9},{3,2,0x0000d9},{2,2,0x0000d9},{1,2,0x0000d9},{0,2,0x0000d9},{0,13,0x0000d9},{2,13,0x0000d9},{1,13,0x0000d9},{3,13,0x0000d9},{4,13,0x0000d9},{5,13,0x0000d9},{6,13,0x0000d9},{7,13,0x0000d9},{8,13,0x0000d9},{10,13,0x0000d9},{9,13,0x0000d9},{11,13,0x0000d9},{12,13,0x0000d9},{13,13,0x0000d9},{14,13,0x0000d9},{15,13,0x0000d9},{15,15,0x0000d9},{14,15,0x0000d9},{13,15,0x0000d9},{12,15,0x0000d9},{11,15,0x0000d9},{10,15,0x0000d9},{9,15,0x0000d9},{8,15,0x0000d9},{7,15,0x0000d9},{6,15,0x0000d9},{5,15,0x0000d9},{4,15,0x0000d9},{3,15,0x0000d9},{2,15,0x0000d9},{0,15,0x0000d9},{1,15,0x0000d9}};
      return imageData;
    }
};
