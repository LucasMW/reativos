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



unsigned long old;
int ledState = HIGH;
void setup() 
{
  // initialize digital pin 13 as an output.
  pinMode(13, OUTPUT);
  old = millis();
  digitalWrite(13,ledState);
}
int time = 100;
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
  exit(0);
}

// the loop function runs over and over again forever
void loop() 
{
  unsigned long now = millis();
  
  if(now >= old + time) // time has passed
  {
    old=now;
    ledState = !ledState;
    digitalWrite(13, ledState); 
  }
    
  int but = digitalRead(11); 
  int but2 = digitalRead(12);
  
  if(but == 0 && but2 == 0 && now >= old + 500)
  {
    stop();
  }
  else
  {
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
}
