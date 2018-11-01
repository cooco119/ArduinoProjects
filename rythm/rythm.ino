
#include <MeggyJrSimple.h>
//#include "block.h"
#define LEN 150
#define SPEED 185

class block{
  public:
  int pos[2];
  int color;
  int vel;
  int flag;
  block(int _posX, int _posY, int _color, int _vel, int _flag);
};
block::block(int _posX, int _posY, int _color, int _vel, int _flag){
  this->pos[0] = _posX;
  this->pos[1] = _posY;
  this->color = _color;
  this->vel =_vel;
  this->flag = _flag;
};

int point = 0;

void Tone_Stop(int duration){
  Tone_Start(8000000, duration);
}

void playSnDuad(int noteA, int noteB){
  // 185ms for a sixteen note
  const int NOTEDELAY = 20;  //ms
  const int REPS = 4; //Number of loops for this chord
  int n;
  for (n = 0; n < REPS; n++) {
    Tone_Start(noteA, NOTEDELAY);
    delay(NOTEDELAY);
    Tone_Start(noteB, NOTEDELAY);
    delay(NOTEDELAY);
  }
  Tone_Stop(25);
  delay(25); //185ms total
}
void playQnDuad(int noteA, int noteB) {
  //740ms for a quarter note
  const int NOTEDELAY = 20;  //ms
  const int REPS = 18; //Number of loops for this chord
  int n;
  for (n = 0; n < REPS; n++) {
    Tone_Start(noteA, NOTEDELAY);
    delay(NOTEDELAY);
    Tone_Start(noteB, NOTEDELAY);
    delay(NOTEDELAY);
  }
  Tone_Stop(20);
  delay(20); //740ms total
}//playQnDuad()

void playEnDuad(int noteA, int noteB) {
  //370ms for an eighth note
  const int NOTEDELAY = 20;  //ms
  const int REPS = 9; //Number of loops for this chord
  int n;
  for (n = 0; n < REPS; n++) {
    Tone_Start(noteA, NOTEDELAY);
    delay(NOTEDELAY);
    Tone_Start(noteB, NOTEDELAY);
    delay(NOTEDELAY);
  }
  Tone_Stop(10);
  delay(10); //370ms total
}//playEnDuad()

void playQnTriad(int noteA, int noteB, int noteC) {
  //740ms for a quarter note
  const int NOTEDELAY = 15;  //ms
  const int REPS = 16; //Number of loops for this chord
  int n;
  for (n = 0; n < REPS; n++) {
    Tone_Start(noteA, NOTEDELAY);
    delay(NOTEDELAY);
    Tone_Start(noteB, NOTEDELAY);
    delay(NOTEDELAY);
    Tone_Start(noteC, NOTEDELAY);
    delay(NOTEDELAY);
  }
  Tone_Stop(20);
  delay(20); //740ms total
}//playQnTriad()



void playEnTriad(int noteA, int noteB, int noteC) {
  //370ms for an eighth note
  const int NOTEDELAY = 15;  //ms
  const int REPS = 8; //Number of loops for this chord
  int n;
  for (n = 0; n < REPS; n++) {
    Tone_Start(noteA, NOTEDELAY);
    delay(NOTEDELAY);
    Tone_Start(noteB, NOTEDELAY);
    delay(NOTEDELAY);
    Tone_Start(noteC, NOTEDELAY);
    delay(NOTEDELAY);
  }
  Tone_Stop(10);
  delay(10); //140ms total for the note
}//playEnTriad()

void playSnTriad(int noteA, int noteB, int noteC) {
  //185ms for an eighth note
  const int NOTEDELAY = 15;  //ms
  const int REPS = 4; //Number of loops for this chord
  int n;
  for (n = 0; n < REPS; n++) {
    Tone_Start(noteA, NOTEDELAY);
    delay(NOTEDELAY);
    Tone_Start(noteB, NOTEDELAY);
    delay(NOTEDELAY);
    Tone_Start(noteC, NOTEDELAY);
    delay(NOTEDELAY);
  }
  Tone_Stop(5);
  delay(5); //185ms total for the note
}//playSnTriad()

float NOTE_F7 = 8000000/2793.826;
  float NOTE_C8 = 8000000/4186.009;
  float NOTE_AS7 = 8000000/3729.310;
  float NOTE_D7 = 8000000/2349.318;
  float NOTE_D8 = 8000000/4698.636;
  float NOTE_D6 = 8000000/1174.659;
  float NOTE_F6 = 8000000/1396.913;
  float NOTE_G6 = 8000000/1567.982;
  float NOTE_AS5 = 8000000/932.3275;
  float NOTE_C6 = 8000000/1046.502;
  float NOTE_AS6 = 8000000/1864.655;
  float NOTE_C7 = 8000000/2093.005;
  float NOTE_A6 = 8000000/1760.000;
  float NOTE_G5 = 8000000/783.9909;
  
int melody[LEN] = {NOTE_F7, NOTE_C8, NOTE_AS7, NOTE_D7, 0, NOTE_AS7, NOTE_C8, NOTE_D8, NOTE_C8, NOTE_AS7, NOTE_C8,
              NOTE_F7, NOTE_C8, NOTE_AS7, NOTE_D7, 0, NOTE_AS7, NOTE_C8, NOTE_D8, NOTE_C8, NOTE_AS7, NOTE_C8, 
              NOTE_F7, NOTE_C8, NOTE_AS7, NOTE_D7, 0, NOTE_AS7, NOTE_C8, NOTE_D8, NOTE_C8, NOTE_AS7, NOTE_C8, 
              NOTE_F7, NOTE_C8, NOTE_AS7, NOTE_D7, 0, NOTE_AS5, NOTE_D6, NOTE_F6,
              NOTE_G6, NOTE_G6, NOTE_G6, NOTE_F6, 0, 0, 0, NOTE_AS5,
              NOTE_C6, NOTE_C6, 0, NOTE_C6, NOTE_D6, 0, 0, NOTE_D6, NOTE_F6,
              NOTE_G6, NOTE_A6, NOTE_G6, NOTE_F6, NOTE_D6, NOTE_C6, NOTE_AS5, NOTE_AS5, NOTE_G5,
              NOTE_C6, NOTE_C6, NOTE_AS5, NOTE_AS5, NOTE_AS5, 0, NOTE_D6, NOTE_F6,
              NOTE_G6, 0, NOTE_F6, NOTE_F6, 0, 0, NOTE_AS5,
              NOTE_C6, NOTE_C6, NOTE_AS5, NOTE_C6, NOTE_D6, NOTE_D6, NOTE_D6, NOTE_F6,
              NOTE_G6, NOTE_AS6, NOTE_C7, NOTE_D7, NOTE_C7, NOTE_AS6, NOTE_G6, NOTE_G6,
              NOTE_C7, NOTE_C7, NOTE_AS6, NOTE_AS6, 0, NOTE_F6, NOTE_G6,
              NOTE_C7, NOTE_C7, NOTE_AS6, NOTE_AS6, NOTE_AS6, NOTE_AS6};

int duration[LEN] = {'e', 'e', 'e', 'e', 'e', 's', 's','s','s','s','s',
                'e', 'e', 'e', 'e', 'e', 's', 's','s','s','s','s',
                'e', 'e', 'e', 'e', 'e', 's', 's','s','s','s','s',
                'e','e','e','e','e','e','e','e',
                'e','e','e','e','q','e','s','s',
                'e','e','e','s','s','q','e','s','s',
                'e','e','e','e','e','e','e','s','s',
                'e','e','e','e','q','e','s','s',
                'q','e','e','q','e','s','s',
                'e','e','e','s','s','q','e','e',
                'e','e','e','e','e','e','e','e',
                'e','e','e','e','q','e','e',
                'e','e','e','q','q','q'};

int blocks[LEN] = {1,2,3,4,1,2,4,3,2,3,4,1,2,1,3,4,1,2,3,4,4,3,2,3,1,2,3,2,1,2,4,3,2,3,1,2,3,4,4,3,2,3,1,2,3,1,2,3,4
                  
};

//
//int base[LEN] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
//                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
//                0, 0, 0,0,0,0,0,0,0,0,0,
//                0,0,0,0,0,0,0,0,
//                0,0,0,NOTE_D6,0,0,0,0,
//                0,0,0,0,0,0,0,0,0,
//                0,0,0,0,0,0,0,0,0,
//                0,0,0,0,0,0,0,0,
//                NOTE_D6,0,NOTE_D6,NOTE_D6,0,0,0,
//                0,0,0,0,0,0,0,0,
//                0,0,0,0,0,0,0,0,
//                0,0,0,NOTE_F6,0,0,0,
//                NOTE_AS6,NOTE_AS6,0,NOTE_F6,NOTE_F6,NOTE_F6};
//
//int base2[LEN] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
//                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
//                0, 0, 0,0,0,0,0,0,0,0,0,
//                0,0,0,0,0,0,0,0,
//                0,0,0,0,0,0,0,0,
//                0,0,0,0,0,0,0,0,0,
//                0,0,0,0,0,0,0,0,0,
//                0,0,0,0,0,0,0,0,
//                0,0,0,0,0,0,0,
//                0,0,0,0,0,0,0,0,
//                0,0,0,0,0,0,0,0,
//                0,0,0,NOTE_D6,0,0,0,
//                NOTE_G6,NOTE_G6,0,NOTE_D6,NOTE_D6,NOTE_D6};

void drawBlock(block* _block){
  if (_block->flag == 0){
    return;
  }
  int x = _block->pos[0];
  int y = _block->pos[1];
  int color = _block->color;
  DrawPx(x, y, color);
  DrawPx(x+1, y, color);
}
  
void setup(){
  MeggyJrSimpleSetup();
//  Serial.begin(115200);

}
int t = millis();
int ot = t;
int t2 = millis();
int ot2 = t2;
block *Block1 = new block(0, 7, Yellow, 1, 0);
block *Block2 = new block(2, 7, Red, 1, 0);
block *Block3 = new block(4, 7, Blue, 1, 0);
block *Block4 = new block(6, 7, Green, 1, 0);
block *Block5 = new block(0, 7, Yellow, 1, 0);
block *Block6 = new block(2, 7, Red, 1, 0);
block *Block7 = new block(4, 7, Blue, 1, 0);
block *Block8 = new block(6, 7, Green, 1, 0);
block *Block9 = new block(0, 7, Yellow, 1, 0);
block *Block10 = new block(2, 7, Red, 1, 0);
block *Block11 = new block(4, 7, Blue, 1, 0);
block *Block12 = new block(6, 7, Green, 1, 0);

int blockCounter = 0;
int timer = 0;
int playTimer = 0;
int setTimer = 0;
int startCounter = 7;
int setPlayTimer = 0;
int playCounter = 0;

void loop() {
  if(Block1->pos[0] == 0&&Block1->pos[1] == 0){
    if(Button_Left){
     point +=1;
    }
   else{
      point -=1;
    }
  } 

  if(Block2->pos[0] == 3&&Block2->pos[1] == 0){
    if(Button_Right){
     point +=1;
   }
  else{
    point -=1;
  }
} 

  if(Block3->pos[0] == 5&&Block3->pos[1] == 0){
    if(Button_B){
      point +=1;
    }
   else{
     point -=1;
  }
} 

  if(Block4->pos[0] == 7&&Block4->pos[1] == 0){
    if(Button_A){
     point +=1;
   }
   else{
      point -=1;
  }
}
  if (setTimer == 0){
    if (duration[blockCounter] == 's'){
      timer = 1;
      setTimer = 1;
    }
    else if (duration[blockCounter] == 'e'){
      timer = 2;
      setTimer = 1;
    }
    else if (duration[blockCounter] == 'q'){
      timer = 4;
      setTimer = 1;
    }
    if (melody[blockCounter] != 0){
      if (blocks[blockCounter] == 1){
        if (Block5->flag == 1){
          Block9->flag = 1;
        }
        else if (Block1->flag == 1){
          Block5->flag = 1;
        }
        else{
          Block1->flag = 1;
        }
      }
      if (blocks[blockCounter] == 2){
        if (Block6->flag == 1){
          Block10->flag = 1;
        }
        else if (Block2->flag == 1){
          Block6->flag = 1;
        }
        else{
          Block2->flag = 1;
        }
      }
      if (blocks[blockCounter] == 3){
        if (Block7->flag == 1){
          Block11->flag = 1;
        }
        else if (Block3->flag == 1){
          Block7->flag == 1;
        }
        else {
          Block3->flag = 1;
        }
      }
      if (blocks[blockCounter] == 4){
        if (Block8->flag == 1){
          Block12->flag = 1;
        }
        else if (Block4->flag == 1){
          Block8->flag = 1;
        }
        else {
          Block4->flag = 1;
        }
      }
    }
  }

  if (startCounter == 0){
    if (setPlayTimer == 0){
      if (duration[playCounter] == 's'){
        playTimer = 1;
        setPlayTimer = 1;
      }
      else if (duration[playCounter] == 'e'){
        playTimer = 2;
        setPlayTimer = 1;
      }
      else if (duration[playCounter] == 'q'){
        playTimer = 4;
        setPlayTimer = 1;
      }
    }
    Tone_Start(melody[playCounter], SPEED*playTimer);
  }

  ClearSlate();
  drawBlock(Block1);
  drawBlock(Block2);
  drawBlock(Block3);
  drawBlock(Block4);
  drawBlock(Block5);
  drawBlock(Block6);
  drawBlock(Block7);
  drawBlock(Block8);
  drawBlock(Block9);
  drawBlock(Block10);
  drawBlock(Block11);
  drawBlock(Block12);
  DisplaySlate();
  
  t = millis();
  if((t-ot) > 185){
    timer -= 1;
    if (startCounter > 0){ startCounter -= 1;}
    if (startCounter == 0){ playTimer -= 1;}
    if (Block1->flag == 1){ Block1->pos[1] -= 1;}
    if (Block2->flag == 1){ Block2->pos[1] -= 1;}
    if (Block3->flag == 1){ Block3->pos[1] -= 1;}
    if (Block4->flag == 1){ Block4->pos[1] -= 1;}
    if (Block5->flag == 1){ Block5->pos[1] -= 1;}
    if (Block6->flag == 1){ Block6->pos[1] -= 1;}
    if (Block7->flag == 1){ Block7->pos[1] -= 1;}
    if (Block8->flag == 1){ Block8->pos[1] -= 1;}
    if (Block9->flag == 1){ Block9->pos[1] -= 1;}
    if (Block10->flag == 1){ Block10->pos[1] -= 1;}
    if (Block11->flag == 1){ Block11->pos[1] -= 1;}
    if (Block12->flag == 1){ Block12->pos[1] -= 1;}
//    Serial.print("timer :        "); Serial.println(timer);
//    Serial.print("blockCounter : "); Serial.println(blockCounter);
//    Serial.print("playTimer :    "); Serial.println(playTimer);
//    Serial.print("playCounter :  "); Serial.println(playCounter);
//    Serial.print("startCounter : "); Serial.println(startCounter);
//    Serial.print("block # :      "); Serial.println(blocks[blockCounter]);
//    Serial.print("Block1 Flag :  "); Serial.print(Block1->flag);
//    Serial.print("\tBlock2 Flag :  "); Serial.print(Block2->flag);
//    Serial.print("\tBlock3 Flag :  "); Serial.print(Block3->flag);
//    Serial.print("\tBlock4 Flag :  "); Serial.println(Block4->flag);
//    Serial.print("Block5 Flag :  "); Serial.print(Block5->flag);
//    Serial.print("\tBlock6 Flag :  "); Serial.print(Block6->flag);
//    Serial.print("\tBlock7 Flag :  "); Serial.print(Block7->flag);
//    Serial.print("\tBlock8 Flag :  "); Serial.println(Block8->flag);
    ot = t;
  }
  
  if (timer == 0){
    setTimer = 0;
    blockCounter++;
    if (blockCounter == LEN){
      blockCounter %= LEN;
    }
  }

  if (startCounter == 0){
    if (playTimer == 0){
      setPlayTimer = 0;
      playCounter++;
      if (playCounter == LEN){
        playCounter %= LEN;
        startCounter = 7;
      }
    }
  }


  if (Block1->pos[1] < 0){
    Block1->flag = 0;
    Block1->pos[1] = 7;
  }
  if (Block2->pos[1] < 0){
    Block2->flag = 0;
    Block2->pos[1] = 7;
  }
  if (Block3->pos[1] < 0){
    Block3->flag = 0;
    Block3->pos[1] = 7;
  }
  if (Block4->pos[1] < 0){
    Block4->flag = 0;
    Block4->pos[1] = 7;
  }
  if (Block5->pos[1] < 0){
    Block5->flag = 0;
    Block5->pos[1] = 7;
  }
  if (Block6->pos[1] < 0){
    Block6->flag = 0;
    Block6->pos[1] = 7;
  }
  if (Block7->pos[1] < 0){
    Block7->flag = 0;
    Block7->pos[1] = 7;
  }
  if (Block8->pos[1] < 0){
    Block8->flag = 0;
    Block8->pos[1] = 7;
  }
  if (Block9->pos[1] < 0){
    Block9->flag = 0;
    Block9->pos[1] = 7;
  }
  if (Block10->pos[1] < 0){
    Block10->flag = 0;
    Block10->pos[1] = 7;
  }
  if (Block11->pos[1] < 0){
    Block11->flag = 0;
    Block11->pos[1] = 7;
  }
  if (Block12->pos[1] < 0){
    Block12->flag = 0;
    Block12->pos[1] = 7;
  }
  
  
}

//bpm = 185ms
