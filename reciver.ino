#include <SimpleEspNowConnection.h>
#include <WiFi.h>
typedef struct struct_message {

    char mvmnt;
    
    

} struct_message;
struct_message myData;


void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len) 
{ 
  pinMode(21, OUTPUT);
  pinMode(22, OUTPUT);
  pinMode(25, OUTPUT);
  pinMode(23, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  memcpy(&myData, incomingData, sizeof(myData));
  Serial.print("Bytes received: ");
  Serial.println(len);
  Serial.print("MOVEMENT: ");
  Serial.println(myData.mvmnt);
  Serial.println();
  if (myData.mvmnt == 's')
  {
    Serial.print(myData.mvmnt);
    digitalWrite(21, LOW);
    digitalWrite(22, LOW);
    digitalWrite(23, LOW);
    digitalWrite(25, LOW);

  }
  if (myData.mvmnt == 'r')
  {
    Serial.print(myData.mvmnt);
    digitalWrite(21, HIGH);
    digitalWrite(22, LOW);
    digitalWrite(23, HIGH);
    digitalWrite(25, LOW);

  }
  if (myData.mvmnt == 'f')
  {
    
    Serial.print(myData.mvmnt);
    digitalWrite(21, LOW);
    digitalWrite(22, HIGH);
    digitalWrite(23, LOW);
    digitalWrite(25, HIGH);

  }

  
  if (myData.mvmnt == 'l')
  {
    Serial.print(myData.mvmnt);
    digitalWrite(21, HIGH);
    digitalWrite(22, LOW);
    digitalWrite(23, LOW);
    digitalWrite(25, HIGH);

  }
  if (myData.mvmnt == 't')
  {
    Serial.print(myData.mvmnt);
    digitalWrite(21, LOW);
    digitalWrite(22, HIGH);
    digitalWrite(23, HIGH);
    digitalWrite(25, LOW);


  }
  if (myData.mvmnt == 'x')
  {
    Serial.print(myData.mvmnt);
    digitalWrite(21, LOW);
    digitalWrite(22, LOW);
    digitalWrite(23, LOW);
    digitalWrite(25, HIGH);


  }
  if (myData.mvmnt == 'Y')
  {
    Serial.print(myData.mvmnt);
    digitalWrite(21, LOW);
    digitalWrite(22, HIGH);
    digitalWrite(23, LOW);
    digitalWrite(25, LOW);


  }
}
 
void setup() {

  Serial.begin(115200);
  

  WiFi.mode(WIFI_STA);


  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }
  
  esp_now_register_recv_cb(OnDataRecv);
}
 
void loop() {

}
