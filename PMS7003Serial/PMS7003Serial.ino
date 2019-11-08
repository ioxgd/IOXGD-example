int PM_SP_UG_1_0, PM_SP_UG_2_5, PM_SP_UG_10_0;
int PM_AE_UG_1_0, PM_AE_UG_2_5, PM_AE_UG_10_0;

void setup() {
  Serial.begin(9600);
  Serial1.begin(9600, 8, -1);

  Serial.println("PM2.5 Sensor");
}

void loop() {
  if (pms_process()) {
    Serial.print("PM2.5: ");
    Serial.println(PM_AE_UG_2_5);
  }

  delay(10);
}

bool pms_process() {
  if (!Serial1.available()) {
    return false;
  }
  uint8_t ch = Serial1.read();

  static uint8_t dataIndex = 0;
  static uint16_t checksum = 0;
  static uint16_t calculatedChecksum = 0;
  static uint16_t frameLen = 0;
  static uint8_t payload[30];

  switch (dataIndex) {
    case 0:
      if (ch != 0x42) {
        return false;
      }
      calculatedChecksum = ch;
      break;

    case 1:
      if (ch != 0x4D) {
        dataIndex = 0;
        return false;
      }
      calculatedChecksum += ch;
      break;

    case 2:
      frameLen = ch << 8;
      calculatedChecksum += ch;
      break;

    case 3:
      frameLen |= ch;
      calculatedChecksum += ch;
      break;

    default:
      if (dataIndex == frameLen + 2) {
        checksum = ch << 8;
      } else if (dataIndex == frameLen + 2 + 1) {
        checksum |= ch;

        if (calculatedChecksum == checksum) {
          PM_SP_UG_1_0 = (((uint16_t)payload[0]) << 8) | payload[1];
          PM_SP_UG_2_5 = (((uint16_t)payload[2]) << 8) | payload[3];
          PM_SP_UG_10_0 = (((uint16_t)payload[4]) << 8) | payload[5];

          PM_AE_UG_1_0 = (((uint16_t)payload[6]) << 8) | payload[7];
          PM_AE_UG_2_5 = (((uint16_t)payload[8]) << 8) | payload[9];
          PM_AE_UG_10_0 = (((uint16_t)payload[10]) << 8) | payload[11];
        } else {
          Serial.println("Error checksum");
        }

        dataIndex = 0;
        return true;
      } else {
        calculatedChecksum += ch;
        uint8_t payloadIndex = dataIndex - 4;

        if (payloadIndex < sizeof(payload)) {
          payload[payloadIndex] = ch;
        }
      }
  }

  dataIndex++;
  return false;
}
