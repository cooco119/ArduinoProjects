#include <MeggyJrSimple.h>
char shapeList[4] = {'L','I','S','Z'};

class block{
  public:
  int pos[2] = {0, 0};
  char shape = 'L';
  int dir = 1;  // 0은 북, 1는 동, 2은 남, 3는 서
  int** dots;
  int color;
  block(int _posX, int _posY, char _shape, int _dir);
  void setInfo(int _posX, int _posY, char _shape, int _dir);
};

void rotBlock(block *_block){
  _block->dir += 1;
  _block->dir = _block->dir%4;
}

block::block(int _posX, int _posY, char _shape, int _dir){
  this->pos[0] = _posX;
  this->pos[1] = _posY;
  int x = this->pos[0];
  int y = this->pos[1];
  this->shape = _shape;
  this->dir = _dir;
  this->dots = (int**) malloc ( sizeof(int*) * 4 );
  for(int i=0; i<4; i++){
      this->dots[i] = (int*) malloc ( sizeof(int) * 2 );
  }

  if (this->shape == 'L'){
    this->color = Yellow;
    if (this->dir == 0){
      this->dots[0][0] = x;
      this->dots[0][1] = y;
      this->dots[1][0] = x+1;
      this->dots[1][1] = y;
      this->dots[2][0] = x;
      this->dots[2][1] = y+1;
      this->dots[3][0] = x;
      this->dots[3][1] = y+2;
    }
    else if (this->dir == 1){
      this->dots[0][0] = x;
      this->dots[0][1] = y;
      this->dots[1][0] = x+1;
      this->dots[1][1] = y;
      this->dots[2][0] = x+2;
      this->dots[2][1] = y;
      this->dots[3][0] = x;
      this->dots[3][1] = y-1;
    }
    else if (this->dir == 2){
      this->dots[0][0] = x;
      this->dots[0][1] = y;
      this->dots[1][0] = x+1;
      this->dots[1][1] = y;
      this->dots[2][0] = x+1;
      this->dots[2][1] = y-1;
      this->dots[3][0] = x+1;
      this->dots[3][1] = y-2;
    }
    else if (this->dir == 3){
      this->dots[0][0] = x;
      this->dots[0][1] = y;
      this->dots[1][0] = x;
      this->dots[1][1] = y+1;
      this->dots[2][0] = x-1;
      this->dots[2][1] = y;
      this->dots[3][0] = x-2;
      this->dots[3][1] = y;
     
      
    }
  }
  if (this->shape == 'I'){
    this->color = Blue;
    if (this->dir == 0 || this->dir == 2){
      this->dots[0][0] = x;
      this->dots[0][1] = y;
      this->dots[1][0] = x;
      this->dots[1][1] = y+1;
      this->dots[2][0] = x;
      this->dots[2][1] = y+2;
      this->dots[3][0] = x;
      this->dots[3][1] = y+3;
    }
    else if(this->dir == 1 || this->dir == 3){
     this->dots[0][0] = x;
     this->dots[0][1] = y;
     this->dots[1][0]= x+1;
     this->dots[1][1] = y;
     this->dots[2][0] = x+2;
     this->dots[2][1] = y;
     this->dots[3][0] = x+3;
     this->dots[3][1] = y;
    
    }
  }
    
  
  if (this->shape == 'S'){
    this->color = Red;
    this->dots[0][0] = x;
    this->dots[0][1] = y;
    this->dots[1][0] = x+1;
    this->dots[1][1] = y;
    this->dots[2][0] = x;
    this->dots[2][1] = y+1;
    this->dots[3][0] = x+1;
    this->dots[3][1] = y+1;
  }
  if (this->shape == 'Z'){
    this->color = Green;
    if(this->dir == 0 || this->dir == 2){
      this->dots[0][0] = x;
      this->dots[0][1] = y;
      this->dots[1][0] = x+1;
      this->dots[1][1] = y;
      this->dots[2][0] = x+1;
      this->dots[2][1] = y+1;
      this->dots[3][0] = x+2;
      this->dots[3][1] = y+1;
  }
  if(this->dir == 1 || this->dir == 3){
    this->dots[0][0] = x;
    this->dots[0][1] = y;
    this->dots[1][0] = x;
    this->dots[1][1] = y+1;
    this->dots[2][0] = x+1;
    this->dots[2][1] = y+1;
    this->dots[3][0] = x+1;
    this->dots[3][1] = y+2;
  }
  }
}

void block::setInfo(int _posX, int _posY, char _shape, int _dir){
  this->pos[0] = _posX;
  this->pos[1] = _posY;
  int x = this->pos[0];
  int y = this->pos[1];
  this->shape = _shape;
  this->dir = _dir;
//  this->dots = (int**) malloc ( sizeof(int*) * 4 );
//  for(int i=0; i<4; i++){
//      this->dots[i] = (int*) malloc ( sizeof(int) * 2 );
//  }

  if (this->shape == 'L'){
    this->color = Yellow;
    if (this->dir == 0){
      this->dots[0][0] = x;
      this->dots[0][1] = y;
      this->dots[1][0] = x+1;
      this->dots[1][1] = y;
      this->dots[2][0] = x;
      this->dots[2][1] = y+1;
      this->dots[3][0] = x;
      this->dots[3][1] = y+2;
    }
    else if (this->dir == 1){
      this->dots[0][0] = x;
      this->dots[0][1] = y;
      this->dots[1][0] = x+1;
      this->dots[1][1] = y;
      this->dots[2][0] = x+2;
      this->dots[2][1] = y;
      this->dots[3][0] = x;
      this->dots[3][1] = y-1;
    }
    else if (this->dir == 2){
      this->dots[0][0] = x;
      this->dots[0][1] = y;
      this->dots[1][0] = x+1;
      this->dots[1][1] = y;
      this->dots[2][0] = x+1;
      this->dots[2][1] = y-1;
      this->dots[3][0] = x+1;
      this->dots[3][1] = y-2;
    }
    else if (this->dir == 3){
      this->dots[0][0] = x;
      this->dots[0][1] = y;
      this->dots[1][0] = x;
      this->dots[1][1] = y+1;
      this->dots[2][0] = x-1;
      this->dots[2][1] = y;
      this->dots[3][0] = x-2;
      this->dots[3][1] = y;
     
      
    }
  }
  if (this->shape == 'I'){
    this->color = Blue;
    if (this->dir == 0 || this->dir == 2){
      this->dots[0][0] = x;
      this->dots[0][1] = y;
      this->dots[1][0] = x;
      this->dots[1][1] = y+1;
      this->dots[2][0] = x;
      this->dots[2][1] = y+2;
      this->dots[3][0] = x;
      this->dots[3][1] = y+3;
    }
    else if(this->dir == 1 || this->dir == 3){
     this->dots[0][0] = x;
     this->dots[0][1] = y;
     this->dots[1][0]= x+1;
     this->dots[1][1] = y;
     this->dots[2][0] = x+2;
     this->dots[2][1] = y;
     this->dots[3][0] = x+3;
     this->dots[3][1] = y;
    
    }
  }
    
  
  if (this->shape == 'S'){
    this->color = Red;
    this->dots[0][0] = x;
    this->dots[0][1] = y;
    this->dots[1][0] = x+1;
    this->dots[1][1] = y;
    this->dots[2][0] = x;
    this->dots[2][1] = y+1;
    this->dots[3][0] = x+1;
    this->dots[3][1] = y+1;
  }
  if (this->shape == 'Z'){
    this->color = Green;
    if(this->dir == 0 || this->dir == 2){
      this->dots[0][0] = x;
      this->dots[0][1] = y;
      this->dots[1][0] = x+1;
      this->dots[1][1] = y;
      this->dots[2][0] = x+1;
      this->dots[2][1] = y+1;
      this->dots[3][0] = x+2;
      this->dots[3][1] = y+1;
  }
  if(this->dir == 1 || this->dir == 3){
    this->dots[0][0] = x;
    this->dots[0][1] = y;
    this->dots[1][0] = x;
    this->dots[1][1] = y+1;
    this->dots[2][0] = x+1;
    this->dots[2][1] = y+1;
    this->dots[3][0] = x+1;
    this->dots[3][1] = y+2;
  }
  }
  
}
int color1 = Yellow;
int color2 = Red;
int color3 = Blue;
int color4 = Green;
int color5 = Orange;
int color6 = DimRed;
int color7 = White;
int color8 = DimOrange;
int t2= millis();
int ot2 = t2;

void DrawVerLine(int x, int Color){
  for (int i = 0; i < 8; i++){ 
   DrawPx(x,i,Color);
}
  DisplaySlate();
}

void startDisplay(){
    while((t2 - ot2) < 2000){
    color1 = (color1++)% 8 + 1;
    color2 = (color2++)% 8 + 1;
    color3 = (color3++)% 8 + 1;
    color4 = (color4++)% 8 + 1;
    color5 = (color5++)% 8 + 1;
    color6 = (color6++)% 8 + 1;
    color7 = (color7++)% 8 + 1;
    color8 = (color8++)% 8 + 1;
  DrawVerLine(0, color1);
  DrawVerLine(1, color2);
  DrawVerLine(2, color3);
  DrawVerLine(3, color4);  
  DrawVerLine(4, color5);
  DrawVerLine(5, color6);
  DrawVerLine(6, color7);
  DrawVerLine(7, color8);
  t2 = millis();
  delay(100);    
  }
}

void setup() {
  // put your set
  MeggyJrSimpleSetup();
  randomSeed(analogRead(2));
  Serial.begin(115200);
  
  
}




int x1 = random(100)%7;
//int x1 = 3;
int y1 = 7;
block *Block1 = new block(x1, y1, shapeList[random(199)%4], random(192)%4);
//block *Block1 = new block(x1, y1, 'S', 0);
int t = millis();
int ot = t;
int mapInfo[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0}};
int mapColor[8][8];
int point = 0;
int start = 1;

void gameOverFunc(){
  delay(1000);
  for (int i = 0; i < 8; i++){
    Serial.println("Game Over");
  }
  x1 = random(100)%8;
  y1 = 7;
  Block1->setInfo(x1, y1, shapeList[random(199)%4], random(192)%4);
  t = millis();
  ot = t;
  for (int i = 0; i < 8; i++){
    for (int j = 0; j < 8; j++){
      mapInfo[i][j] = 0;
      mapColor[i][j] = 0;
    }
  }
  point = 0;
  startDisplay();
}

void loop() {
  // put your main code here, to run repeatedly:
  // 1초마다 자동으로 떨어짐
  if (start == 1){
    startDisplay();
    start = 0;
  }

  // A누르면 돌리기
  CheckButtonsPress();
  if (Button_A){
    rotBlock(Block1);
    Block1->setInfo(Block1->pos[0], Block1->pos[1], Block1->shape, Block1->dir);
  }

  // B 누르면 떨어뜨리기
  if (Button_B){
    y1 -= 1;
    Block1->setInfo(Block1->pos[0], y1, Block1->shape, Block1->dir);
  }

  
  // 블럭 이동
  if (Button_Left){
    for (int k = 0; k < 4; k++){
      if (Block1->dots[k][0] > 0){
        if (mapInfo[Block1->dots[k][0]-1][Block1->dots[k][1]] != 0){
          goto NOLEFT;
        }
      }
      else if (Block1->dots[k][0] == 0){
        goto NOLEFT;
      }
    }
    x1 -= 1;
    Block1->setInfo(x1, y1, Block1->shape, Block1->dir);
  }
  NOLEFT:
  
  if (Button_Right){
    for (int k = 0; k < 4; k++){
      if (Block1->dots[k][0] < 7){
        if (mapInfo[Block1->dots[k][0]+1][Block1->dots[k][1]] != 0){
          goto NORIGHT;
        }
      }
      else if (Block1->dots[k][0] == 7){
        goto NORIGHT;
      }
    }
    x1 += 1;
    Block1->setInfo(x1, y1, Block1->shape, Block1->dir);
  }
  NORIGHT:

  


  // 화면 업데이트
  ClearSlate();
  for (int i = 0; i < 4; i++){
    if (Block1->dots[i][0] >= 0 && Block1->dots[i][0] <=7){
      if (Block1->dots[i][1] >=0 && Block1->dots[i][1] <= 7){
        DrawPx(Block1->dots[i][0], Block1->dots[i][1], Block1->color);
      }
    }
  }

  for (int i = 0; i < 8; i++){
    for (int j = 0; j < 8; j++){
      if (mapInfo[i][j] != 0){
        DrawPx(i, j, mapColor[i][j]);
      }
    }
  }
  DisplaySlate();

  t = millis();
  if ((t-ot)>1000){
    y1 -= 1;
    Block1->setInfo(x1, y1, Block1->shape, Block1->dir);
//    Serial.print("dot1 : "); Serial.print(Block1->dots[0][0]); Serial.print(", "); Serial.println(Block1->dots[0][1]);
//    Serial.print("dot2 : "); Serial.print(Block1->dots[1][0]); Serial.print(", "); Serial.println(Block1->dots[1][1]);
//    Serial.print("dot3 : "); Serial.print(Block1->dots[2][0]); Serial.print(", "); Serial.println(Block1->dots[2][1]);
//    Serial.print("dot4 : "); Serial.print(Block1->dots[3][0]); Serial.print(", "); Serial.println(Block1->dots[3][1]);
    Serial.print("point : "); Serial.println(point);
    ot = t;
  }

  // 바닥 도달 시 map에 그리기 
  for (int k = 0; k < 4; k++){
    if (Block1->dots[k][1] == 0){
      for (int i = 0; i < 4; i++){
        if (Block1->dots[i][0] < 8 && Block1->dots[i][1] <8){
          mapInfo[Block1->dots[i][0]][Block1->dots[i][1]] = 1;
          mapColor[Block1->dots[i][0]][Block1->dots[i][1]] = Block1->color;
        }
      }
      x1 = random(192)%7;
      y1 = 7;
  //    free(Block1);
  //    block *Block1 = new block(x1, y1, random(1828)%4, random(27)%4);
      Block1->setInfo(x1, y1, shapeList[random(192)%4], random(27)%4);
      break;
    }
  }
  

  // 이미 쌓여있는 블록 위에 도달시
  for (int k = 0; k < 4; k++){
    if (mapInfo[Block1->dots[k][0]][Block1->dots[k][1]-1] != 0){
      for (int i = 0; i < 4; i++){
        if (Block1->dots[i][0] < 8 && Block1->dots[i][1] <8){
          mapInfo[Block1->dots[i][0]][Block1->dots[i][1]] = 1;
          mapColor[Block1->dots[i][0]][Block1->dots[i][1]] = Block1->color;
        }
      }
      x1 = random(192)%8;
      y1 = 7;
      Block1->setInfo(x1, y1, shapeList[random(1828)%4], random(27)%4);
//      Serial.print("Hellooo");
      break;
    }
  }

  // 게임 오버
  for (int i = 0; i < 8; i++){
    if (mapInfo[i][7] > 0){
      gameOverFunc();
      break;
    }
  }

  // 맵에서 한 줄 꽉 차면 지우고 점수 업
  for (int i = 0; i < 7; i++){
    int sum = 0;
    for (int j = 0; j < 8; j++){
      sum += mapInfo[j][i];
    }
    if (sum == 8){
      point += 10;
      for (int k = 0; k < 7 - i; k++){
        for (int j = 0; j < 8; j++){
          mapInfo[j][k] = mapInfo[j][k+1];
        }
      }
    }
  }
  
}
