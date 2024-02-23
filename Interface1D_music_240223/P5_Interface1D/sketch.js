/* /////////////////////////////////////

  4.043 / 4.044 Design Studio: Interaction Intelligence
  February 9, 2024
  Marcelo Coelho

*/ /////////////////////////////////////


let displaySize = 30;   // how many pixels are visible in the game
let pixelSize = 30;     // how big each 'pixel' looks on screen

//(0.2, 0.2, 0.2)

let playerOne;    // Adding 2 players to the game
let playerTwo;
let playerThree;

let audioInitialized = false;




let display;      // Aggregates our final visual output before showing it on the screen

let controller;   // This is where the state machine and game logic lives


function setup() {

  if (!audioInitialized) {
    Tone.start();
    audioInitialized = true;
  }

  createCanvas((displaySize*pixelSize), pixelSize);     // dynamically sets canvas size

  display = new Display(displaySize, pixelSize);        //Initializing the display

  playerOne = new Player(color(255, 173, 173)  , 0, displaySize);   // Initializing players
  playerTwo = new Player(color(253, 255, 182) , 0, displaySize);
  playerThree = new Player(color(160, 196, 255)  , 0, displaySize);

  //target = new Player(color(255,255,0), parseInt(random(0,displaySize)), displaySize);    // Initializing target using the Player class 

  controller = new Controller();            // Initializing controller


}

function draw() {

  // start with a blank screen
  background(0, 0, 0);    

  // Runs state machine at determined framerate
  controller.update();

  // After we've updated our states, we show the current one 
  display.show();


}


