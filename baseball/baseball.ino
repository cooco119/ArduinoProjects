#define MAX_TRY 10
//#define DEBUG 

int a, b, c, d;
int answer[4] = {0};
int input[4] = {0};
int strike, ball;
bool finishingCond;
int count;

void startMessage(){
  Serial.println("Welcome to Baseball game!\n\n");
  Serial.println("Random number generated.. Start guessing!\n\n-----------------------------------------------\n");
}

void initialize(){
  count = 1;
  finishingCond = false;
  randomSeed(analogRead(0));
  do {
    a = random(0,10);
    b = random(0,10);
    c = random(0,10);
    d = random(0,10);
  }
  while (a==b || a==c || a==d || b==c || b==d || c==d);
  answer[0] = a;
  answer[1] = b;
  answer[2] = c;
  answer[3] = d;
  startMessage();
}

int getInput(){
  int tmp = -1;
  while ( tmp <0){
    tmp = Serial.read() - 48;
  }
  return tmp;
}

void checkStrikeBall(){
  for (int i = 0; i < 4; i++){
    if (input[i] == answer[i]){
      strike += 1;
      continue;
    }
    else {
      for (int j = 0; j < 4; j++){
        if (j != i){
          if (input[i] == answer[j]){
            ball += 1;
            break;
          }
        }
      }
    }
  }
}

bool testFinish(){
  Serial.print("Strike: ");
  Serial.print(strike);
  Serial.print("\tBall: ");
  Serial.println(ball);
  if (strike == 4){
    Serial.println("\n\nYou Win!!");
    return true;
  }
  else {
    return false;
  }
}

void ifRestart(){
  char tmp;
  Serial.println("Retry? (y/n) ");
  tmp = getInput() + 48;
  Serial.println(tmp);
  if (tmp == 'y'){
    return;
  }
  else if(tmp == 'n'){
    Serial.println("Goodbye~");
    Serial.end();
    return;
  }
  else {
    Serial.println("Wrong input.. type 'y' or 'n'");
    ifRestart();
    return;
  }
  
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  initialize();                 //초기화
  
  while (!finishingCond){
    #ifdef DEBUG
    Serial.println("\nDebug mode.. showing answer");
    for (int i = 0; i < 4; i++){
      Serial.print(answer[i]);
      Serial.print(" ");
    }
    Serial.println();
    #endif

    
    strike = 0;
    ball = 0;
    Serial.print("\n");
    Serial.print(count);
    Serial.println("th try..\n");
    Serial.println("Enter four numbers");
    
    for (int i = 0; i < 4; i++){
      input[i] = getInput();
    }/// 입력 받는 곳
    
    Serial.print("Your input is : ");
    for (int i = 0; i < 4; i++){
      Serial.print(input[i]);
      Serial.print(" ");
    }
    Serial.println();

    
    checkStrikeBall();
    finishingCond = testFinish();
    if (count >= MAX_TRY){
      Serial.print("You failed to get answer in ");
      Serial.print(MAX_TRY);
      Serial.println(" tries.");
      break;
    }
    count += 1;
  }
  ifRestart();
  
  
}


