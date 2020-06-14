int buzzer = 8 ;
void setup ()
{
pinMode (buzzer, OUTPUT) ;
}
void loop ()
{
digitalWrite (buzzer, HIGH) ; 
delay (2) ;
digitalWrite (buzzer, LOW) ; 
delay (2) ;
}