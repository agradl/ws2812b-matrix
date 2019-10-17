
class Routine {
  public:
    bool initialized = false;
    virtual void setup() = 0;
    virtual bool loop() = 0;
    void doSetup(){
      setup();
      initialized = true;
    }
    bool doLoop(){
      if (!initialized){
        doSetup();        
      }
      return loop();
    }
};
