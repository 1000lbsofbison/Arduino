
int redPin = 9;
int greenPin = 11;
int bluePin = 10;
int counter = 0;
int redVal = 255;
int greenVal = 0;
int blueVal = 0;
char output[] = ""; 


void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  if (counter ==1530) 
    {
      counter = 0;
    }
  else 
    {
      counter++;
    }
 if (counter >= 0 && counter <255)
 {
   blueVal++;
 }
 if (counter >= 255  && counter <510 && redVal >0)
 {
   redVal--;
 }
 if (counter >= 510  && counter <765)
 {
   greenVal++;
 }
 if (counter >= 765  && counter <1020 && blueVal >0)
 {
   blueVal--;
 }
 if (counter >=1020   && counter <1275)
 {
   redVal++;
 }
 if (counter >=1275   && counter <1530 && greenVal >0)
 {
   greenVal--;
 }
 
 setColor(redVal, greenVal, blueVal);
 //Serial.print("R: ");
 //Serial.print(redVal);
 //Serial.print("  G: ");
 //Serial.print(greenVal);
 //Serial.print("  B: ");
 //Serial.println(blueVal);




 
    

delay (1);

}

void setColor(int red, int green, int blue)
{
 analogWrite(redPin, 255-red);
 analogWrite(bluePin, 255-blue);
 analogWrite(greenPin, 255-green);
}

int rgbToHSL(int r, int g, int b)
{
  float rp = r/255;
  float gp = g/255;
  float bp = g/255;
  
  float cMax = max(max(rp, gp), bp);
  float cMin = min(min(rp, gp), bp);
  float delta = cMax-cMin;
  
  float h = 0;
  float s = 0;
  float L = 0;
  
  switch (cMax){
   case rp:
      hue = 60*(((gp-bp)/delta)%6);
      break;
   case gp:
      hue = 60*(((bp-rp)/delta)+2);
      break;
   case bp:
      hue = 60*(((rp-gp)/delta)+4);
      break;
   }     
   
   L = (cMax+cMin)/2;
   
   if (delta == 0)
   {
     s = 0;
   }
   else
   {
     s = delta/(1-abs(2*L-1);
   }
      
     
  
}


