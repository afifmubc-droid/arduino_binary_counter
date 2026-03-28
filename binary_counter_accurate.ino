int dec_of_binary ;
int ledArray[] = {10,9,8,7,6,5,4,3} ;
int counter[8] ;
int state[8] ;
int delayTime = 500;

void setup() {

  for (int i=0 ; i<8 ; i++){
    pinMode (ledArray[i],OUTPUT) ;
  }
  Serial.begin(9600) ;
  Serial.print ("Upto what Decimal number do you want to count in Binary? ") ;
}

void loop() {
 
   if(Serial.available()>0){
    
        dec_of_binary = Serial.parseInt() ;
   
   }
 
   for (int i=0 ; i<=dec_of_binary ; i++){
    counter[0] = i ;
    
    for (int j = 1 ; j<8 ; j++){
      counter[j] = counter[j-1]/2 ;
    }

    for (int k=0 ; k<8 ; k++){
      if (counter[k]%2 == 1){
        state[k] = HIGH ;
      }else state[k] = LOW ;
    }
  
    for (int l=0 ; l<8 ; l++){
     digitalWrite(ledArray[l],state[l]) ;
    }
     delay (delayTime) ; 
  }
}