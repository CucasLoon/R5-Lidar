/*
 * Purpose is to Run an YDLidar X2 Lidar using the serial pin and a relay through an Arduino
 * This closes relay, gathers data from the lidar, opens the relay 
 * then sorts then maps the data recieved.
 * This is then repeated as necessary
 */

const int DATASIZE = 100;
int i = 0;
int array[360][2];

void intangles(); // Intermediate Angle Function Definition
int angle(int x); // Angle Function Definition
int math(int a, int b);

//STARTING SIGNAL IS 7 BYTES

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  //Create a connection with the relay module

}


///////////////////////////////////////////////////////////////////////////////
//The Following Loop will only be used to gather data via serial through the Lidar
//To Gather the data Comment out the Second Loop() function and uncomment this one
//////////////////////////////////////////////////////////////////////////////

/*
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
*/
////////////////////////////////////////////////////////
/*
 * Sorting Function will consist of 
 * "INPUT_SIZE" amount of Bytes, with the 
 * first 2 Bytes denoting the beginning of the scan command (0xA55A)
 * Then find the First Packet head 0x55AA, 
 * then stepping through to gather the distant points from the point cloud
 */
////////////////////////////////////////////////////////
/* To use this loop() coment out the top loop and remove the comment here
 * ----------------------------------------------------------------------------
 */
const int INPUT_SIZE = 2000; //Amount of bytes that will be sorted each time the relay is triggered
int storage[INPUT_SIZE];
bool processing = 0;
//int sample_rate = 0;
//int Start = 0;
//int End = 0;

void loop() {
  while (!processing)
  {
    //Trigger the Relay Remove the serial availabe, once relay is triggered start storing data
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


///////////////////////////////////////////////////////////////////////////////
//Function used to make the "intermediate Angles"
//Pre: sample_rate, a global variable; array of int called angle of sample size
//Post: Returns nothing but fills in array with intermediate angles
//Future: Probably will merge into main loop() function, Need to inclu
//////////////////////////////////////////////////////////////////////////////
//void intangles()
//{
//  int x = sample_rate;
  //for(int i=2; i<x; i++)
  //{
//    angle[i] = (((End-Start)/(x-1))*(i-1)+Start);
 // }
  //return;
//}


///////////////////////////////////////////////////////////////////////////////
//Function used to calculate the start and end angles
//Pre: Requires an angle after calculated from the "math function"
//Post: Returns the angle post calculations 
//Future: will remain as is
//////////////////////////////////////////////////////////////////////////////
int angle(int x)
{
  int theta = 0;
  theta = x >> 1;
  theta = theta/64;
  return theta;
}



///////////////////////////////////////////////////////////////////////////////
//Function used to place 2 Bytes in MSB, LSB order
//Pre: 2 Bytes recieved from the lidar
//Post: Returns a single int after being the bytes have been merged
//Future: No changes seen to be neccessary
//////////////////////////////////////////////////////////////////////////////
int math(int a, int b)
{
  int storage = b;
  Serial.println(b, BIN);
  storage= b<<8;
  Serial.println(storage, BIN);
  storage = storage|a;
  //Serial.println(value, BIN);
  return storage;
}
