#include <esp_now.h>
#include <WiFi.h>


uint8_t broadcastAddress[] = {0x84, 0xCC, 0xA8, 0x5E, 0xDB, 0x5C};//mac address of the reciever board



typedef struct struct_message {
  char mvmnt;
  
} struct_message;

struct_message myData;

esp_now_peer_info_t peerInfo;

void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
  Serial.print("\r\nLast Packet Send Status:\t");
  Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Delivery Success" : "Delivery Fail");
}
 
void setup() {

  Serial.begin(115200);
 
  WiFi.mode(WIFI_STA);

  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }


  esp_now_register_send_cb(OnDataSent);
  
  memcpy(peerInfo.peer_addr, broadcastAddress, 6);
  peerInfo.channel = 0;  
  peerInfo.encrypt = false;
      
  if (esp_now_add_peer(&peerInfo) != ESP_OK){
    Serial.println("Failed to add peer");
    return;
  }
}
 
void loop() {

  int x = analogRead(32);
  int y = analogRead(33);
  
  if (x > 1023 && x < 3072 && y > 1023 && y < 3072)
  {
    myData.mvmnt = 's';
  }
  if (x == 4095)
  {
    myData.mvmnt = 'f';
  }
  if (x == 0)
  {
    myData.mvmnt = 'r';
  }
  if (y == 0)
  {
    myData.mvmnt = 'l';
  }
  if (y == 4095)
  {
    myData.mvmnt = 't';
  }
  if (x == 0 && y ==0)
  {
    myData.mvmnt = 'x';
  }
  if (x == 0 && y == 4095)
  {
    myData.mvmnt = 'y';
  }

  esp_err_t result = esp_now_send(broadcastAddress, (uint8_t *) &myData, sizeof(myData));
   
  if (result == ESP_OK) {
    Serial.println("Sent with success");
  }
  else {
    Serial.println("Error sending the data");
  }
}
