unsigned long lastHeartbeat = 0;
int heartbeatPeriod = 200;

void sendHeartbeat()
{
  if (millis() - lastHeartbeat > heartbeatPeriod)
  {
    Serial.write(192);
    
    Serial.print('a'); // Controller State
    Serial.print(':');
    Serial.print(AnimationCommandState());
    Serial.print(':');
  
    Serial.print('l'); // Light State
    Serial.print(':');
    Serial.print(digitalRead(RedLight));
    Serial.print(':');
    Serial.print(digitalRead(GreenLight));
    Serial.print(':');
    Serial.print(digitalRead(BlueLight));
    Serial.print(':');
  
    Serial.print('p'); // Pan Servo State
    Serial.print(':');
    Serial.print(pan.read());
    Serial.print(':');
    
    Serial.print('t'); // Tilt Servo State
    Serial.print(':');
    Serial.print(tilt.read());
    Serial.print(':');
    
    Serial.print('z'); // Pressure Sensor
    Serial.print(':');
    Serial.print(analogRead(PressureSensor));
    Serial.print(':');
    
    Serial.print('c'); // Compressor State
    Serial.print(':');
    Serial.print(digitalRead(Compressor));
    Serial.print(':');
    
    Serial.print('v'); // Valve State
    Serial.print(':');
    Serial.print(digitalRead(ValveClosed));
    Serial.print(':');
    Serial.print(digitalRead(ValveOpen));
    Serial.println(':');
    
    Serial.write(192);
    
    lastHeartbeat = millis();
  }
}