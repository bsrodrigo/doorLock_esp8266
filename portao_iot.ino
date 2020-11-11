#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "yKsZqxh5lBLR6UFs2nsIHmH8MS5xrVo3";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "marinho";
char pass[] = "marinho153060";

const int mainGateRele = 2;

void setup(){
  Serial.begin(9600);
  delay(10);
  delay(10);  
  digitalWrite(mainGateRele, HIGH);
  Blynk.begin(auth, ssid, pass);
}

void loop(){
  Blynk.run();  
}


BLYNK_WRITE(V0){  
  pinMode(mainGateRele, OUTPUT);
  int pinValue = param.asInt();
  Serial.println(pinValue);
  if (pinValue == 1) {    
    Serial.println("LIGOU");
    digitalWrite(mainGateRele, LOW);
  } else {    
    Serial.println("DESLIGOU");
    digitalWrite(mainGateRele, HIGH);
  }
}
