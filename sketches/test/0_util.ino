int getLEDIndex(int x, int y) {
  if (x % 2 == 1) {
    //odd
    return 16 * x + (15 - y);
  } else {
    return 16 * x + y;
  }
}

bool setLED(int x, int y, unsigned int hex) {
  if (x < 0 || y < 0 || x > 15 || y > 15) {
    return false;
  }
  leds[getLEDIndex(x, y)] = hex;
  return true;
};

bool setLED(int x, int y, const struct CRGB & color) {
  if (x < 0 || y < 0 || x > 15 || y > 15) {
    return false;
  }
  leds[getLEDIndex(x, y)] = color;
  return true;
};

void Image(int xOffset, int yOffset, std::vector<std::vector<unsigned int> > imageData) {
  for (int i = 0; i < imageData.size(); i++) {
    setLED(((int)imageData.at(i).at(0)) + xOffset, ((int)imageData.at(i).at(1)) + yOffset, imageData.at(i).at(2));
  }
}

void Image(int xOffset, int yOffset, std::vector<std::vector<unsigned int> > imageData, unsigned int overrideColor) {
  for (int i = 0; i < imageData.size(); i++) {
    setLED(((int)imageData.at(i).at(0)) + xOffset, ((int)imageData.at(i).at(1)) + yOffset, overrideColor);
  }
}


void Image(int xOffset, int yOffset, std::vector<std::vector<unsigned int> > imageData, const struct CRGB & overrideColor) {
  for (int i = 0; i < imageData.size(); i++) {
    setLED(((int)imageData.at(i).at(0)) + xOffset, ((int)imageData.at(i).at(1)) + yOffset, overrideColor);
  }
}
