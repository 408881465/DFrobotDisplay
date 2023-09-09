/*!
 * @file MPython_Display_I2C.cpp
 * @brief Define the basic structure of class MPython_Display_I2C
 * @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @licence     The MIT License (MIT)
 * @author [lixin](xin.li@dfrobot.com)
 * @version  V1.6.2
 * @date  2019-11-14
 */


#include "MPython_Display_I2C.h"


/**
  * Class definition for MPython_Display_I2C.
  *
  * Represents an instance of DFRobot_SSD1306 that accepts the I2C version of SSD1306
  */
MPython_Display_I2C::MPython_Display_I2C()
{

}

/**
  * @brief Set screen cache refresh range
  *
  * @param address: 8-bit I2C slave address [ addr | 0 ]
  *
  * @param reg: The address of the register in the device to write
  *
  * @param columnStart: Column start position
  *
  * @param columnEnd: End of column
  *
  * @param rowStart: Line start position
  *
  * @param rowEnd: End of line
  */
inline void MPython_Display_I2C::setRefreshRange(int address, uint8_t reg, int columnStart, int columnEnd, int rowStart, int rowEnd)
{
    // send a bunch of data in one xmission
    writeByte(address, reg, 0xB0 + rowStart);//set page address
    Serial.println("send a bunch of data in one xmission");
    Serial.print("");
    Serial.println();

    writeByte(address, reg, (2+columnStart) & 0xf);//set lower column address
    Serial.print("setRefreshRange address: ");
    Serial.println(address);
    writeByte(address, reg, 0x10 | ((2+columnStart) >> 4));//set higher column address
    Serial.print(" setRefreshRange reg:");
    Serial.println(reg);
    Serial.print("2+columnStart) & 0xf:");
    Serial.println(((2+columnStart) & 0xf));
    Serial.print("(2+columnStart) >> 4:");
    Serial.println(((2+columnStart) >> 4));
    Serial.print("");
    Serial.println();
    Serial.print("");
    Serial.println();
    // serial.print("");
    // Serial.println();

}


/**
  * @brief Write data to the register address in batches
  *
  * @param address: 8-bit I2C slave address [ addr | 0 ]
  *
  * @param reg: The address of the register in the device to write
  *
  * @param data: A pointer to a byte buffer containing the data to write
  *
  * @param length: The number of bytes to read
  *
  * @return Return the number of data
  */
inline int MPython_Display_I2C::writeBuffer(int address, uint8_t reg, unsigned char *data, int length)
{
    int count=0;
    SSD1306_I2CBEGIN();
    Wire.beginTransmission(address);
    Serial.print(" writeBuffer reg: ");
    Serial.print(reg);
    Wire.write(reg);
    while(count<length) {
        Wire.write(*data);
        data++;
        count++;
        Serial.print(" writeBuffer data:");
        Serial.print(*data);
        // delay(500);
        Serial.print(" writeBuffer length:");
        Serial.println(length);
        // delay(100);
    }
    Wire.endTransmission();
    // delay(100);
    return count;
}

/**
  * @brief Write a data to the register address
  *
  * @param address: 8-bit I2C slave address [ addr | 0 ]
  *
  * @param reg: The address of the register in the device to write.
  *
  * @param Data: to be written
  *
  * @return Return the number of data
  */
inline int MPython_Display_I2C::writeByte(uint8_t address, uint8_t reg, uint8_t data)
{
    SSD1306_I2CBEGIN();
    Wire.beginTransmission(address);
    Wire.write(reg);
    Wire.write(data);
    Wire.endTransmission();
    return 1;
}
