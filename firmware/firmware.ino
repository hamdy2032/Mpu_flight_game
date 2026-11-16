#include <Wire.h>
#include <MPU6050_light.h>

MPU6050 mpu(Wire);
unsigned long timer = 0;

void setup() {
  Serial.begin(115200);
  Wire.begin(21, 22); // SDA = 21, SCL = 22
  Wire.setClock(400000); // تفعيل وضع Fast I2C بسرعة 400kHz

  byte status = mpu.begin();
  while (status != 0) {
    Serial.println("MPU6050 connection failed! Check SDA/SCL wiring.");
    delay(1000);
    status = mpu.begin();
  }

  Serial.println("Calibrating MPU6050... Keep controller flat and still.");
  delay(1000);
  mpu.calcOffsets(); // معايرة الجيروسكوب والتسارع تلقائياً
  Serial.println("Calibration done!");
}

void loop() {
  mpu.update();

  if ((millis() - timer) > 10) { // إرسال البيانات بمعدل 100Hz (كل 10ms)
    // إرسال الزوايا بالترتيب الذي يتوقعه كود المتصفح
    Serial.print(mpu.getAngleZ()); // Yaw
    Serial.print(",");
    Serial.print(mpu.getAngleY()); // Pitch
    Serial.print(",");
    Serial.println(mpu.getAngleX()); // Roll

    timer = millis();
  }
}