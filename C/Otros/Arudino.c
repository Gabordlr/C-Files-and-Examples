/******************************************
      ACELEROMETRO MPU6500
 ****************************************/
#include <Wire.h>
#include <TaskScheduler.h>
/****************************************
   Define Constants
 ****************************************/

/****************************************
   Main Functions
 ****************************************/
// Other Constant
#define T1PERIOD 100
#define T2PERIOD 200

// Prototypes
void t1Callback(); // Runs every 100ms, check MQTT and read data
void t2Callback(); // Runs every 200ms, send data
void convertToChar(float val, char *buff);
void I2C_Write(uint8_t deviceAddress, uint8_t regAddress, uint8_t data);
void processData(int16_t AcX, int16_t AcY, int16_t AcZ);
void Read_RawValue(uint8_t deviceAddress, uint8_t regAddress);
void sendDataFromIMU(float localGForceX, float localGForceY, float localGForceZ, float localAbsIMU);
void setupMPU6050();

// Tasks and Schedulers
Task t1(T1PERIOD, TASK_FOREVER, &t1Callback);
Task t2(T2PERIOD, TASK_FOREVER, &t2Callback);
Scheduler runner;

// ======== IMU constants ========
// I2C address of the MPU-6050 - 0x68 or 0x69 if AD0 is pulled HIGH
// Select SDA and SCL pins for I2C communication
// const uint8_t scl = D6;
// const uint8_t sda = D7;
const uint8_t scl = A5;
const uint8_t sda = A4;
const uint8_t MPU6050SlaveAddress = 0x68;

// const uint16_t AccelScaleFactor = 16384;
const uint8_t MPU6050_REGISTER_SMPLRT_DIV = 0x19;
const uint8_t MPU6050_REGISTER_USER_CTRL = 0x6A;
const uint8_t MPU6050_REGISTER_PWR_MGMT_1 = 0x6B;
const uint8_t MPU6050_REGISTER_PWR_MGMT_2 = 0x6C;
const uint8_t MPU6050_REGISTER_CONFIG = 0x1A;
const uint8_t MPU6050_REGISTER_GYRO_CONFIG = 0x1B;
const uint8_t MPU6050_REGISTER_ACCEL_CONFIG = 0x1C;
const uint8_t MPU6050_REGISTER_FIFO_EN = 0x23;
const uint8_t MPU6050_REGISTER_INT_ENABLE = 0x38;
const uint8_t MPU6050_REGISTER_ACCEL_XOUT_H = 0x3B;
const uint8_t MPU6050_REGISTER_SIGNAL_PATH_RESET = 0x68;

// ======== IMU variables ========
float gForceX = 0, gForceY = 0, gForceZ = 0, absIMU = 0, prevAbsIMU = 0;
int16_t GyroX = 0, GyroY = 0, GyroZ = 0;
int16_t Temperature;
float AInclinacionX = 0, AInclinacionY = 0, ARotacion = 0;
uint8_t quietCycles = 0;

void setup()
{

  // Init scheduler
  runner.init();

  // Add tasks to scheduler
  runner.addTask(t1);
  runner.addTask(t2);

  Serial.begin(115200);

  // Init Communication protocols
  Wire.begin(); // I2C to communicate with MPU6050

  // Base setups
  setupMPU6050();

  // Enable tasks
  delay(100);
  t1.enable();
  t2.enable();
}

// Main loop to execute scheduler
void loop(void)
{
  runner.execute();
}

// Read value - 100ms
void t1Callback()
{
  Read_RawValue(MPU6050SlaveAddress, MPU6050_REGISTER_ACCEL_XOUT_H);
}

// Send data from IMU - 200ms
void t2Callback()
{
  float localGForceX = gForceX;
  float localGForceY = gForceY;
  float localGForceZ = gForceZ;
  float localAbsIMU = absIMU;
  float gap = 0.64;

  if (localAbsIMU <= prevAbsIMU - gap || localAbsIMU >= prevAbsIMU + gap)
  {
    prevAbsIMU = localAbsIMU;
    quietCycles = 0;
    sendDataFromIMU(localGForceX, localGForceY, localGForceZ, localAbsIMU);
  }
  else if (quietCycles < 5)
  {
    quietCycles++;
  }
  else
  {
    // Every 1800ms
    prevAbsIMU = localAbsIMU;
    quietCycles = 0;
    sendDataFromIMU(localGForceX, localGForceY, localGForceZ, localAbsIMU);
  }
}

void sendDataFromIMU(float localGForceX, float localGForceY, float localGForceZ, float localAbsIMU)
{
  char mpu6050X[100] = "";
  char mpu6050Y[100] = "";
  char mpu6050Z[100] = "";
  char mpu6050ABS[100] = "";

  convertToChar(localGForceX, mpu6050X);
  convertToChar(localGForceY, mpu6050Y);
  convertToChar(localGForceZ, mpu6050Z);
  convertToChar(localAbsIMU, mpu6050ABS);
  Serial.println("Temperature °C: " + String(Temperature));
  Serial.print(" localAbsIMU: " + String(localAbsIMU));
  Serial.print(" mpu6050ABS: " + String(mpu6050ABS));
  Serial.print(" localGForceX: " + String(localGForceX) + "g");
  Serial.print(" localGForceY: " + String(localGForceY) + "g");
  Serial.println(" localGForceZ: " + String(localGForceZ) + "g");
  Serial.print(" AInclinacionX: " + String(AInclinacionX) + "°/s");
  Serial.print(" AInclinacionY: " + String(AInclinacionX) + "°/s");
  Serial.print(" GyroX : " + String(GyroX) + "°/s");
  Serial.print(" GyroY: " + String(GyroY) + "°/s");
  Serial.print(" GyroZ: " + String(GyroZ) + "°/s");
}

void I2C_Write(uint8_t deviceAddress, uint8_t regAddress, uint8_t data)
{
  Wire.beginTransmission(deviceAddress);
  Wire.write(regAddress);
  Wire.write(data);
  Wire.endTransmission();
}

// read all 14 register
void Read_RawValue(uint8_t deviceAddress, uint8_t regAddress)
{
  int16_t AcX, AcY, AcZ;
  // int16_t GyroX, GyroY, GyroZ;
  // int16_t Temperature;
  Wire.beginTransmission(deviceAddress);
  Wire.write(regAddress);
  Wire.endTransmission();
  Wire.requestFrom(deviceAddress, (uint8_t)14);

  AcX = (((int16_t)Wire.read() << 8) | Wire.read()); // lee parte alta y suma parte baja
  AcY = (((int16_t)Wire.read() << 8) | Wire.read());
  AcZ = (((int16_t)Wire.read() << 8) | Wire.read());

  Temperature = (((int16_t)Wire.read() << 8) | Wire.read());
  Temperature = Temperature / 340 + 36.53;
  GyroX = (((int16_t)Wire.read() << 8) | Wire.read());
  2 GyroY = (((int16_t)Wire.read() << 8) | Wire.read());
  GyroZ = (((int16_t)Wire.read() << 8) | Wire.read());

  gForceX = (AcX * 9.81) / 16384.0;
  gForceY = (AcY * 9.81) / 16384.0;
  gForceZ = (AcZ * 9.81) / 16384.0;

  AInclinacionX = atan(AcX / sqrt(pow(AcY, 2) + pow(AcZ, 2))) * (180.0 / 3.14);
  AInclinacionY = atan(AcY / sqrt(pow(AcX, 2) + pow(AcZ, 2))) * (180.0 / 3.14);

  absIMU = sqrt(pow(gForceX, 2) + pow(gForceY, 2)); //+ pow(gForceZ -7.7 , 2));
}

// configure MPU6050
void setupMPU6050()
{
  delay(50);

  I2C_Write(MPU6050SlaveAddress, MPU6050_REGISTER_SMPLRT_DIV, 0x07);
  I2C_Write(MPU6050SlaveAddress, MPU6050_REGISTER_PWR_MGMT_1, 0x01);
  I2C_Write(MPU6050SlaveAddress, MPU6050_REGISTER_PWR_MGMT_2, 0x00);
  I2C_Write(MPU6050SlaveAddress, MPU6050_REGISTER_CONFIG, 0x00);
  I2C_Write(MPU6050SlaveAddress, MPU6050_REGISTER_GYRO_CONFIG, 0x00); // set +/-250 degree/second full scale

  I2C_Write(MPU6050SlaveAddress, MPU6050_REGISTER_ACCEL_CONFIG, 0x00); // set +/- 2g full scale
  I2C_Write(MPU6050SlaveAddress, MPU6050_REGISTER_FIFO_EN, 0x00);
  I2C_Write(MPU6050SlaveAddress, MPU6050_REGISTER_INT_ENABLE, 0x01);
  I2C_Write(MPU6050SlaveAddress, MPU6050_REGISTER_SIGNAL_PATH_RESET, 0x00);
  I2C_Write(MPU6050SlaveAddress, MPU6050_REGISTER_USER_CTRL, 0x00);
}

// Convert value to string
void convertToChar(float val, char *buff)
{
  int elements = sizeof(buff) / sizeof(buff[0]);

  for (int i = 0; i < elements; i++)
  {
    dtostrf(val, 6, 4, buff); // 4 is mininum width, 6 is precision
  }
}