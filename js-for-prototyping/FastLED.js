FastLED = {};
    CRGB = {};
    
    FastLED.showColor = function(hex){
        $.each(leds, function(i, led){
            led(hex);
        });
    }

    FastLED.addLeds = function(arr, num, coordToIndexFn){
        $('.row').each(function(rIndex, row){
            $(row).find('.cell').each(function(cIndex, cell){
                var index = coordToIndexFn(cIndex, rIndex);
                arr[index] = function(hex){
                    $(cell).css('background-color', hex).data('color', hex);
                }
            });
        });
    }

    CRGB.Black = 'black';