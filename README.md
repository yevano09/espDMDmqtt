# Dynamic Display in the P10 LED display board via MQTT 

### Idea 
The idea behing this repository is to have a P10 single color LED display board which is connected to ESP8266 Dev board and display the runtime inforamtion which it recieves in the Topic


### Current Status 
The current program does the following 

  a. Connects to the WIFI network 
  b. Subscribes to the specific Topic 
  c. Uses DMD2 for the ESP enhanced 
  d. Displays the Text in the Scrolling
  
  
### Enhancements needed 

  a. MQTT reconnect once WiFI is down and UP
  b. Register for At least last message QOS usage
  c. Get setting WIFI input via File / SD card 
  d. Select options for the FONT's 
  e. 
  
  
