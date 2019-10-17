
Pacman = {}

var dots = [[9,7], [11,7], [13,7]]
var pacmanPosition;
var ghostPosition;
function getImage(t){
    if (t % 50 < 25) {
        return Resources.PACMAN_OPEN;
    }
    return Resources.PACMAN_CLOSED;
}
Pacman.setup = function(){
    pacmanPosition = [0,3];
    ghostPosition = [-10, 3];
};

Pacman.loop = function(t){
    var pacmanImageData = getImage(t);
    Image(pacmanPosition, pacmanImageData); 
    Image(ghostPosition, Resources.GHOST); 
    $.each(dots, function(i, dot){
        if (dot[0] > (pacmanPosition[0] + 7)){
            Image(dot, [[0,0,'white']]);
        }
    })
    if (t % 40 === 0){
        pacmanPosition[0]++;
        ghostPosition[0]++;
    }
}

Pacman.isDone = function(){
    return ghostPosition[0] > 15;
}