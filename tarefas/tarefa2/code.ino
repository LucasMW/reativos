//  _ ___ _______     ___ ___ ___  ___ _   _ ___ _____ ___ 
// / |_  )__ /   \   / __|_ _| _ \/ __| | | |_ _|_   _/ __| 
// | |/ / |_ \ |) | | (__ | ||   / (__| |_| || |  | | \__ \ 
// |_/___|___/___/   \___|___|_|_\\___|\___/|___| |_| |___/ 
// 
// Tarefa2
// 
// Made by great lucas
// License: CC-BY-SA 3.0
// Downloaded from: https://123d.circuits.io/circuits/1739467-tarefa2


void setup() {
  // initialize digital pin 13 as an output.
  pinMode(13, OUTPUT);
}
int time = 1000;
void increaseSpeed()
{
  if(time == 0)
    time = 0;
  else
    time /= 2;
}
void decreaseSpeed()
{
  if(time == 0)
    time = 1; 
  else 
    time*=2;
}
void stop()
{
  while(1);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(time);              // wait for a second
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(time); 
  
  int but = digitalRead(11); 
  int but2 = digitalRead(12);
  
  if(but == 0 && but2 == 0)
  {
    stop();
  }
  
  if(but2 == 0)
  {
    decreaseSpeed();
  }
  
  // 0 = pushed ; 1 = unpushed
  if (but == 0) 
  {
    increaseSpeed();
  }
}
