#ifndef MIKONKUBOT_H
#define MIKONKUBOT_H

class MikonkuBot {
public:
    MikonkuBot(int ENA = 11, int IN1 = 10, int IN2 = 9, int IN3 = 8, int IN4 = 7, int ENB = 6);
    void begin();
    void setSpeed(int LEFT = 200, int RIGHT = 200);
    void light(bool state = true,int pin = 13);
    void goForward(int delayTime = 10);
    void goBackward(int delayTime = 10);
    void goTurnLeft(int delayTime = 10);
    void goTurnRight(int delayTime = 10);
    void stop(unsigned int delayTime = 0);
    void setPinENA(int pin);
    void setPinIN1(int pin);
    void setPinIN2(int pin);
    void setPinIN3(int pin);
    void setPinIN4(int pin);
    void setPinENB(int pin);

private:
    int ENA_pin, IN1_pin, IN2_pin, IN3_pin, IN4_pin, ENB_pin;
};

#endif
