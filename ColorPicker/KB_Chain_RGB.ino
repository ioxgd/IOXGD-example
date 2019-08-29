
void setColor(uint32_t c) {
  Wire.beginTransmission(0x3A);
  Wire.write(0x01);
  for (int i=0;i<4;i++) {
    Wire.write((c>>16)&0xFF);
    Wire.write((c>>8)&0xFF);
    Wire.write((c)&0xFF);
  }
  Wire.endTransmission();
}
