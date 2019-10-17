function getLEDIndex(x, y) {
  if (y % 2 === 1) {
    //odd
    return 16 * y + (15 - x);
  } else {
    return 16 * y + x;
  }
}


Util = {};
var BASE_COLOR = 'darkgrey';
Util.BASE_COLOR = BASE_COLOR;
Util.addGrid = function(rootEl, xSize, ySize) {
  var gridEl = $("<div></div>");
  for (var y = 0; y < ySize; y++) {
    var row = $('<div class="row"></div>');
    gridEl.append(row);
    for (var x = 0; x < xSize; x++) {
      var cell = $('<div class="cell"></div>');
      cell.data({ x: x, y: y });
      row.append(cell);
    }
  }
  rootEl.append(gridEl);
};


Util.getLEDIndex = getLEDIndex;

Util.setLED = function setLED(x, y, hex) {
  if (x < 0 || y < 0 || x > 15 || y > 15) {
    return false;
  }
  leds[getLEDIndex(x, y)](hex);
  return true;
};

Util.init = function(setup, loop) {
  setup();
  setInterval(loop, 10);
};

Util.clearLEDs = function() {
  FastLED.showColor(BASE_COLOR);
};

Util.copyToClipboard = function(str) {
  const el = document.createElement("textarea");
  el.value = str;
  el.setAttribute("readonly", "");
  el.style.position = "absolute";
  el.style.left = "-9999px";
  document.body.appendChild(el);
  const selected =
    document.getSelection().rangeCount > 0
      ? document.getSelection().getRangeAt(0)
      : false;
  el.select();
  document.execCommand("copy");
  document.body.removeChild(el);
  if (selected) {
    document.getSelection().removeAllRanges();
    document.getSelection().addRange(selected);
  }
};
