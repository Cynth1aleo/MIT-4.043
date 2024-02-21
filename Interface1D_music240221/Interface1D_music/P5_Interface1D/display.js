// This is used to aggregrate visual information from all objects before we display them. 
// First we populate display and then we show it to user.
// This is particularly helpful once you start outputting your game to an LED strip, of if you want to have two separate 'screens'


class Display {

    constructor(_displaySize, _pixelSize) {
  
      this.displaySize = _displaySize;
      this.pixelSize = _pixelSize;
      this.initColor = color(0, 0, 0);      // black color
      this.displayBuffer = [];
      this.colorBuffer = [];
      this.synthsArray = [];
      this.musicPlayerOne = [];
      this.musicPlayerTwo = [];
      this.musicPlayerThree = [];


      // Assign black to all pixels. Black = off
      for(let i = 0; i < this.displaySize; i++){
        this.displayBuffer[i] = this.initColor;
        this.colorBuffer[i] = this.initColor;
        this.synthsArray[i] = new Tone.Synth().toDestination();
        this.musicPlayerOne[i] = 0; // Initialize music array for player one
        this.musicPlayerTwo[i] = 0; // Initialize music array for player two
        this.musicPlayerThree[i] = 0; // Initialize music array for player two
      }
  
    }
  
    //add to color buffer
    setColorBuffer(_index, _color){
      this.colorBuffer[_index] = _color;
    }

     // Color a specific pixel in the buffer
    setPixel(  _index,  _color) {
        this.displayBuffer[_index]  = _color;
    }
    

    // Color all pixels in the buffer
    setAllPixels( _color) {
      
      for(let i = 0; i < displaySize; i++) { 
        display.setPixel(i, _color); 
      }
    }

    // Transfer colors from color buffer to display buffer
    transferColorBuffer() {
      for (let i = 0; i < this.displaySize; i++) {
        this.displayBuffer[i] = this.colorBuffer[i];
      }
    }

    //get color at a specific index
    getColor(_index) {
      return this.colorBuffer[_index];
    }


    // Now write it to screen
    // This is the only function in the entire software that writes something directly to the screen. I recommend you keep it this way.
    show() {
      for (let i =0; i< this.displaySize; i++) {
        //noStroke();
        fill(this.displayBuffer[i]);
        rect(i*this.pixelSize,0,this.pixelSize,this.pixelSize);
      }
    }


    
    // Let's empty the display before we start adding things to it again
    clear() {

        for(let i = 0; i < this.displaySize; i++) {    
        this.displayBuffer[i] = this.initColor; 
        }
    }

    clearColor() {

      for(let i = 0; i < this.displaySize; i++) {    
      this.colorBuffer[i] = this.initColor; 
      }
  }
    

  }