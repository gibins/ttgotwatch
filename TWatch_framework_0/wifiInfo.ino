// Show the wifi information

void appWifi() {
  
  
  ttgo->tft->fillScreen(TFT_BLACK);
  //ttgo->tft->setTextSize(1);
  ttgo->tft->setTextColor(TFT_YELLOW, TFT_BLACK);
  ttgo->tft->drawString("WiFi Mode",  20, 8, 1);
    
  ttgo->tft->println("Wifi Scanning");
  Serial.println("Serial Wifi mod");

 
  ttgo->tft->fillScreen(TFT_BLACK);

  // WiFi.scanNetworks will return the number of networks found
    int n = WiFi.scanNetworks();

    for (int i = 0; i < n; ++i) {
            // Print SSID and RSSI for each network found
           ttgo->tft->println("Wifi Info ");
           ttgo->tft->println(WiFi.SSID(i));
        
            ttgo->tft->println(WiFi.RSSI(i));
            
            ttgo->tft->println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN)?" ":"*");
            delay(10);
        }
  vTaskDelay(8000 / portTICK_PERIOD_MS);
  ttgo->tft->fillScreen(TFT_BLACK);
}
