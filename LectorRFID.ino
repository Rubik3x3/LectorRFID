//Proyecto empezado el 19 de Noviembre de 2021

#include <SPI.h>
#include <MFRC522.h>

const int RST_PIN = 9;            
const int SS_PIN = 10;    
        
MFRC522 lectorRFID(SS_PIN, RST_PIN);  

void printArray(byte *buffer, byte bufferSize) {
  
   for (byte i = 0; i < bufferSize; i++) {
      Serial.print(buffer[i] < 0x10 ? " 0" : " ");
      Serial.print(buffer[i], HEX);
   }
}
void setup()
{
   Serial.print("SDSJAJDS");
   Serial.begin(9600);    
   SPI.begin();        
   lectorRFID.PCD_Init();    
}
void loop()
{
   // Detectar tarjeta RFID
   if (lectorRFID.PICC_IsNewCardPresent())
   {
      if (lectorRFID.PICC_ReadCardSerial())
      {
         //Muestra el ID de la tarjeta
         
         Serial.print(F("ID:"));
         printArray(lectorRFID.uid.uidByte, lectorRFID.uid.size);
         Serial.println();
         
         //Finaliza
         
         lectorRFID.PICC_HaltA();
      }
   }
   delay(100);
}
