#ifndef SENSOR_READ_H
#define SENSOR_READ_H

#include "Adafruit_SHT31.h"
#include "deviceState.h"
#include "utils.h"
#include "hardwareDefs.h"
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

bool mpuInit(Adafruit_MPU6050 *mpu)
{
  if (!mpu->begin())
  {
    DEBUG_PRINTLN("Couldn't find MPU6050");
    return false;
  }
  mpu->setHighPassFilter(MPU6050_HIGHPASS_0_63_HZ);
  mpu->setMotionDetectionThreshold(1);
  mpu->setMotionDetectionDuration(20);
  mpu->setInterruptPinLatch(true);	// Keep it latched.  Will turn off when reinitialized.
  mpu->setInterruptPinPolarity(true);
  mpu->setMotionInterrupt(true);
  return true;
}


#endif
