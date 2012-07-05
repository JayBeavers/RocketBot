void FireCommand()  // ' ' == 32, '#' == 35, '-' == 45, '7' == 55
{
 digitalWrite(ValveClosed, LOW);
 digitalWrite(ValveOpen, HIGH);
 delay(10);
 
 digitalWrite(ValveClosed, HIGH);
 digitalWrite(ValveOpen, LOW);

 delay(reflectaFunctions::pop());
 digitalWrite(ValveClosed, LOW);
 
 animation = FiredAnimation;
}

void LightCommand()
{
  int parameter = reflectaFunctions::pop();
 
  digitalWrite(RedLight, ((parameter - '0') & 0x01) == 0x01);
  digitalWrite(GreenLight, ((parameter - '0') & 0x02) == 0x02);
  digitalWrite(BlueLight, ((parameter - '0') & 0x04) == 0x04);
}

void PanCommand()
{
  pan.write(reflectaFunctions::pop());
}

void TiltCommand()
{
  tilt.write(reflectaFunctions::pop());
}

void CompressorCommand()
{
  digitalWrite(Compressor, reflectaFunctions::pop() == '1');
}

void ValveCommand()
{
  switch (reflectaFunctions::pop())
  {
    case '0':
      digitalWrite(ValveOpen, LOW);
      digitalWrite(ValveClosed, LOW);
      break;
    case '2':
      digitalWrite(ValveOpen, LOW);
      digitalWrite(ValveClosed, HIGH);
      break;
    case '4':
      digitalWrite(ValveOpen, HIGH);
      digitalWrite(ValveClosed, LOW);
      break;
  }
}
