const int DATASIZE = 100;
int i = 0;
int array[360][2];


//STARTING SIGNAL IS 7 BYTES

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

}

void loop() {
  // put your main code here, to run repeatedly:  
 //  Serial.read();
 if(Serial.available())
 { 
  for(i; i < DATASIZE; i++)
  {
    Serial.println(Serial.read()); //This lines displays the Decimal Values from the lidar
    //Serial.println(Serial.read(), HEX);  //USE THIS LINE TO FIND THE STARTING VALUES
  }
 }
}

/* To use this loop() coment out the top loop and remove the comment here
 * ----------------------------------------------------------------------------
 *
int INPUT_SIZE = 2000;
int storage[INPUT_SIZE];
bool processing = 0;

void loop() {
  while (!processing)
  {
    if(Serial.available())
    {
     for(int j = 0; j < INPUT_SIZE; j++)
     {
       storage[j] = Serial.read();
     }
     if((storage[0] == 0xA5) && (storage[1] == 0x5A))
     {
      processing = 1; //Starts doing "Post-processing of current lidar sample set
     }
     else
     {
      //Trigger Relay to restart lidar
      Serial.println(storage[0], HEX);
      Serial.println(storage[1], HEX);
     }
    }
  }
  while(processing)
  {
    //This is where the processing code to "sort" the data through the array
  }
}
*/

// Intermediate Angles Function Header
void intangles(samplerate);
// Intermediate Angles Function Definition
samplerate = 40;
void intangles(samplerate)
{
  int angle[x];

  for(i=2; i<x; i++)
  {
    angle[i] = (((LSA-FSA)/(x-1))*(i-1)+FSA);
  }
  return;
}

// Calculate Angle Function Header (From LSB and MSB)
int angle(x);
// Calculate Angle Function Definition (From LSB and MSB)
int angle(x)
{
  x >> 1;
  x = x/64;
  return x;
}

}
