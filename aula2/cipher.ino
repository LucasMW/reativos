#include <stdint.h>

/* take 64 bits of data in v[0] and v[1] and 128 bits of key[0] - key[3] */

void encipher(unsigned int num_rounds, uint32_t v[2], uint32_t const key[4]) {
    unsigned int i;
    uint32_t v0=v[0], v1=v[1], sum=0, delta=0x9E3779B9;
    for (i=0; i < num_rounds; i++) {
        v0 += (((v1 << 4) ^ (v1 >> 5)) + v1) ^ (sum + key[sum & 3]);
        sum += delta;
        v1 += (((v0 << 4) ^ (v0 >> 5)) + v0) ^ (sum + key[(sum>>11) & 3]);
    }
    v[0]=v0; v[1]=v1;
}

void decipher(unsigned int num_rounds, uint32_t v[2], uint32_t const key[4]) {
    unsigned int i;
    uint32_t v0=v[0], v1=v[1], delta=0x9E3779B9, sum=delta*num_rounds;
    for (i=0; i < num_rounds; i++) {
        v1 -= (((v0 << 4) ^ (v0 >> 5)) + v0) ^ (sum + key[(sum>>11) & 3]);
        sum -= delta;
        v0 -= (((v1 << 4) ^ (v1 >> 5)) + v1) ^ (sum + key[sum & 3]);
    }
    v[0]=v0; v[1]=v1;
}


#define LED 13
#define VSIZE 400

uint32_t key[] = { 1, 2, 3, 4 };
uint32_t v[VSIZE]; 

void setup () 
{
  	int i;
    pinMode(LED, OUTPUT);
    Serial.begin(9600);
  	for(i=0;i<VSIZE; i++)
    {
  		v[i] = i*i;
    }
}
 


void loop () 
{
  int i;
    {
        static int led = 0;
        digitalWrite(LED, led=!led);
    }
  

    unsigned long t1 = millis();

    Serial.print("antes: \n ");
        Serial.print(v[0]);
        Serial.print(" ");
        Serial.println(v[1]);
	
   for(i=0;i<VSIZE-1;i+=2)
   {
    encipher(32, v+i, key);
   }
	
    Serial.print("durante: ");
        Serial.print(v[0]);
        Serial.print(" ");
        Serial.println(v[1]);
	for(i=0;i<VSIZE-1;i+=2)
    {
    decipher(32, v+i, key);
    }
	
    Serial.print("depois: ");
        Serial.print(v[0]);
        Serial.print(" ");
        Serial.println(v[1]);

    unsigned long t2 = millis();
    Serial.println(t2-t1);
}
