# Limitation of the Prototype:

the use of the servo here is not good since need a calibration everytime it is restarted. plus they are using battery, servo used a lot of current which the servo performance affected as the battery discharge. Also , the use servo with Arduino is not good enough for maintain accuracy and precision when dealing with servo.

The usage of battery here is not effecient because of motor using a lot of current, the playing time will be limited and short.

there is no sensor to detect wether the ball really push up and down or not, if there is a failure, no sensor to detect it.

the use of USB connection here is a hassle and tidious.

the ball need to be inserted manually each time the game finish


# Improvement can be made:
 
instead on using servo, better to use 5V push and pull selonoid electromagnetic which cost around the same as the TowerPro sg90 micro servo.

need a direct power supply instead of battery to maintain performance.

add a simple digital proximity sensor to detect the ball has been fall down ad the middle or top before the next ball can be pushed.

the connection can be improved by using wireless connection like HC-05 bluetooth (RM12 x3) but it will also require additional microcontroller ( Arduino Pro Mini RM10 x 2)

create a mechanism that can return automatically to the start point like additional push and pull solenoid to push the ball up to the starting point. Alternatively, can replace the whole thing with OLED digital display for the whole thing instead of using physical ball and servo motor. with digital OLED we can just press one reset button and it will back to the start again.
