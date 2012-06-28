unsigned long animationStart = 0;
unsigned long animationTime = 0;
int frequency = 0;

typedef void (* AnimationFunction) ();
AnimationFunction animation = IdleAnimation;

void animationLoop()
{
  animationTime = millis() - animationStart;
  animation();
}

int AnimationCommandState()
{
  if (animation == IdleAnimation) return 0;
  else if (animation == MovingAnimation) return 1;
  else if (animation == ArmingAnimation) return 2;
  else if (animation == ArmedAnimation) return 3;
  else if (animation == FiringAnimation) return 4;
  else if (animation == FiredAnimation) return 5;
}

void AnimationCommand(int animationId)
{
  switch(animationId)
  {
    case '0':
      animation = IdleAnimation;
      break;
    case '1':
      animation = MovingAnimation;
      break;
    case '2':
      animation = ArmingAnimation;
      break;
    case '3':
      animation = ArmedAnimation;
      break;
    case '4':
      animation = FiringAnimation;
      break;
    case '5':
      animation = FiredAnimation;
      break;
    case '6':
      animation = MovingDisabledAnimation;
      break;
  }
  
  // Reset to defaults
  digitalWrite(RedLight, LOW);
  digitalWrite(GreenLight, LOW);
  digitalWrite(BlueLight, LOW);
  frequency = 0;
  animationStart = millis();
}

void IdleAnimation()
{
  frequency = 0;
  noTone(Speaker);
  animationStart = millis();
}

void MovingAnimation()
{
  if (animationTime < 150)
  {
    tone(Speaker, 660);
    digitalWrite(RedLight, HIGH);
    digitalWrite(GreenLight, HIGH);
    digitalWrite(BlueLight, HIGH);
  }

  else if (animationTime < 1000)
  {
    noTone(Speaker);
    digitalWrite(RedLight, LOW);
    digitalWrite(GreenLight, LOW);
    digitalWrite(BlueLight, LOW);
  }
  else
  {
    animationStart = millis();
  }
}

void MovingDisabledAnimation()
{
  if (animationTime < 150)
  {
    tone(Speaker, 660);
    digitalWrite(RedLight, HIGH);
    digitalWrite(GreenLight, HIGH);
    digitalWrite(BlueLight, LOW);
  }

  else if (animationTime < 1000)
  {
    noTone(Speaker);
    digitalWrite(RedLight, LOW);
    digitalWrite(GreenLight, LOW);
    digitalWrite(BlueLight, LOW);
  }
  else
  {
    animationStart = millis();
  }
}

void ArmingAnimation()
{
  if (frequency == 0)
  {
    digitalWrite(RedLight, HIGH);
    digitalWrite(GreenLight, HIGH);
    digitalWrite(BlueLight, LOW);
    frequency = 222;
  }
  else if (animationTime < 1250) frequency += 1;
  else if (animationTime < 1500)
  {
    digitalWrite(RedLight, LOW);
    digitalWrite(GreenLight, LOW);
    digitalWrite(BlueLight, LOW);
    frequency = 465;
  }
  else if (animationTime < 1700) frequency -= 6;
  else if (animationTime < 2000) frequency = -1; // Off
  else
  {
    frequency = 0;
    animationStart = millis();
  }
  
  if (frequency > 0)
    tone(Speaker, frequency);
  else
    noTone(Speaker);
}

void ArmedAnimation(){

  noTone(Speaker);

  if (animationTime < 4000)
  {
    digitalWrite(RedLight, HIGH);
    digitalWrite(GreenLight, HIGH);
    digitalWrite(BlueLight, LOW);
  }
  else if (animationTime < 8000)
  {
    digitalWrite(RedLight, LOW);
    digitalWrite(GreenLight, LOW);
    digitalWrite(BlueLight, LOW);
  }
  else
  {
    animationStart = millis();
  }
}

void FiringAnimation()
{
  if (frequency == 0)
  {
    frequency = 215;
  }
  else if (animationTime < 75)
  {
    digitalWrite(RedLight, HIGH);
    digitalWrite(GreenLight, LOW);
    digitalWrite(BlueLight, LOW);
    frequency += 5;
  }
  else if (animationTime < 325)
  {
    digitalWrite(RedLight, LOW);
    digitalWrite(GreenLight, LOW);
    digitalWrite(BlueLight, LOW);
    frequency = 290;
  }
  else if (animationTime < 400)
  {
    digitalWrite(RedLight, HIGH);
    digitalWrite(GreenLight, LOW);
    digitalWrite(BlueLight, LOW);
    frequency -= 5;
  }
  else if (animationTime < 650)
  {
    digitalWrite(RedLight, LOW);
    digitalWrite(GreenLight, LOW);
    digitalWrite(BlueLight, LOW);
    frequency = 215;
  }
  else if (animationTime < 725)
  {
    digitalWrite(RedLight, HIGH);
    digitalWrite(GreenLight, LOW);
    digitalWrite(BlueLight, LOW);
    frequency += 5;
  }
  else if (animationTime < 975)
  {
    digitalWrite(RedLight, LOW);
    digitalWrite(GreenLight, LOW);
    digitalWrite(BlueLight, LOW);
    frequency = 290;
  }
  else if (animationTime < 1050)
  {
    digitalWrite(RedLight, HIGH);
    digitalWrite(GreenLight, LOW);
    digitalWrite(BlueLight, LOW);
    frequency -= 5;
  }
  else if (animationTime < 1300)
  {
    digitalWrite(RedLight, LOW);
    digitalWrite(GreenLight, LOW);
    digitalWrite(BlueLight, LOW);
    frequency = 215;
  }
  else
  {
    animation = IdleAnimation;
  }
  
  if (frequency > 0)
    tone(Speaker, frequency);
  else
    noTone(Speaker);
}

void FiredAnimation()
{
  if (animationTime < 100) digitalWrite(RedLight, HIGH);
  else if (animationTime < 200) digitalWrite(RedLight, LOW);
  else if (animationTime < 300) digitalWrite(RedLight, HIGH);
  else if (animationTime < 400) digitalWrite(RedLight, LOW);
  else if (animationTime < 500) digitalWrite(RedLight, HIGH);
  else if (animationTime < 600) digitalWrite(RedLight, LOW);
  else if (animationTime < 700) digitalWrite(RedLight, HIGH);
  else
  {
    digitalWrite(RedLight, LOW);
    
    animation = IdleAnimation;
  }
}
