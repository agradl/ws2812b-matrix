

Test = {};

var hearts;
var phrase;
var time = 0;
var phraseCoords;
var phrase;
var heartCoords = [];
var heartColor = 'pink';
var R = Resources;

Test.loop = function(){
    Util.clearLEDs();
            
    $.each(hearts, function(i, coords){
        Image(coords, Resources.HEART, heartColor);
    })

    if (button_clicked){
        button_clicked = false;
        phrase = [R.H,R.E,R.L,R.L,R.O,R.SPACE,R.M,R.Y,R.SPACE,R.N,R.A,R.M,R.E];
        phraseCoords = [30, 1];
    }

    if (phrase){
        Phrase(phrase, phraseCoords, CHSV(220,120,120));
        if (time % 15 === 0){
            phraseCoords[0] -= 1;
        }
    }
    time++;
};

Test.setup = function(){
    hearts = [[0,7], [9,7]];
};

Test.isDone = function(){
    return false;
}