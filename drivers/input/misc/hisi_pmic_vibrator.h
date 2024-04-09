#ifndef _HISI_PMIC_VIBRATOR_H
#define _HISI_PMIC_VIBRATOR_H

#define HISI_PMIC_VIBRATOR_DEFAULT_NAME "vibrator"
#define HISI_PMIC_VIBRATOR_CDEVIE_NAME "haptics"
#define HISI_PMIC_VIBRATOR_HAPTIC_CFG_STR "haptics-cfg"

#define HISI_PMIC_VIBRATOR_ON 0xA000
#define HISI_PMIC_VIBRATOR_BRAKE 0xA001

#define HISI_PMIC_VIBRATOR_DUTY_NORMAL_CFG_L 0xA010
#define HISI_PMIC_VIBRATOR_DUTY_NORMAL_CFG_H 0xA011

#define HISI_PMIC_VIBRATOR_OUT_NML_VBEMF_L 0xA041
#define HISI_PMIC_VIBRATOR_OUT_NML_VBEMF_H 0xA042
#define HISI_PMIC_VIBRATOR_UREAL_DATA_L 0xA045
#define HISI_PMIC_VIBRATOR_UREAL_DATA_H 0xA046
#define HISI_PMIC_VIBRATOR_ADC_ZERO_L 0xA04B
#define HISI_PMIC_VIBRATOR_ADC_ZERO_H 0xA04C
#define HISI_PMIC_VIBRATOR_KFIT_DATA_L 0xA04D
#define HISI_PMIC_VIBRATOR_KFIT_DATA_H 0xA04E
#define HISI_PMIC_VIBRATOR_LRA_NML_TIME_L 0xA091
#define HISI_PMIC_VIBRATOR_LRA_NML_TIME_M 0xA092
#define HISI_PMIC_VIBRATOR_LRA_NML_TIME_H 0xA093
#define HISI_PMIC_VIBRATOR_LRA_NML_BEML_L 0xA094
#define HISI_PMIC_VIBRATOR_LRA_NML_BEML_H 0xA095

#define HISI_PMIC_VIBRATOR_SPEL_TIME_REG0 0xA050
#define HISI_PMIC_VIBRATOR_SPEL_TIME_REG6 0xA056
#define HISI_PMIC_VIBRATOR_SPEL_TIME_REG_NUM 4
#define HISI_PMIC_VIBRATOR_LADD_PARA_REG 0xA02B
#define HISI_PMIC_VIBRATOR_LADD_PARA_REG_NUM 20
#define HISI_PMIC_VIBRATOR_SPEL_DUTY_REG 0xA05B
#define HISI_PMIC_VIBRATOR_REG_CFG_NUM HISI_PMIC_VIBRATOR_LADD_PARA_REG_NUM

#define HISI_PMIC_VIBRATOR_SPEL_TIME_REG2 0xA052
#define HISI_PMIC_VIBRATOR_SPEL_TIME_VALUE2_6 0x2A
#define HISI_PMIC_VIBRATOR_SPEL_TIME_REG3 0xA053
#define HISI_PMIC_VIBRATOR_SPEL_TIME_VALUE3_6 0x23
#define HISI_PMIC_VIBRATOR_SPEL_TIME_VALUE3_8 0x2E
#define HISI_PMIC_VIBRATOR_SPEL_TIME_REG4 0xA054
#define HISI_PMIC_VIBRATOR_SPEL_TIME_VALUE4_8 0x23
#define HISI_PMIC_VIBRATOR_SPEL_TIME_VALUE4_10 0x30
#define HISI_PMIC_VIBRATOR_SPEL_TIME_REG5 0xA055
#define HISI_PMIC_VIBRATOR_SPEL_TIME_VALUE5_10 0x23
#define HISI_PMIC_VIBRATOR_HAPTIC_NUM 10
#define HISI_PMIC_VIBRATOR_HAPTIC_1 1
#define HISI_PMIC_VIBRATOR_HAPTIC_2 2
#define HISI_PMIC_VIBRATOR_HAPTIC_3 3
#define HISI_PMIC_VIBRATOR_HAPTIC_4 4
#define HISI_PMIC_VIBRATOR_HAPTIC_5 5

#define HISI_PMIC_VIBRATOR_MODE_STANDBY 0x00
#define HISI_PMIC_VIBRATOR_MODE_RTP 0x01
#define HISI_PMIC_VIBRATOR_MODE_HAPTICS 0x02
#define HISI_PMIC_VIBRATOR_BRK_EN 0x01

#define HISI_PMIC_VIBRATOR_OVDR_DUTY_L 0xA00D
#define HISI_PMIC_VIBRATOR_OVDR_DUTY_H 0xA00E

#define HISI_PMIC_VIBRATOR_TH_BOOST_L 0xA01A
#define HISI_PMIC_VIBRATOR_TH_BOOST_H 0xA01B

#define HISI_PMIC_VIBRATOR_DRV_NMU 0xA002
#define HISI_PMIC_VIBRATOR_DRV_NUM_VALUE 0x94

#define HISI_PMIC_VIBRATOR_BRAKE_DUTY_L 0xA013
#define HISI_PMIC_VIBRATOR_BRAKE_DUTY_H 0xA014

#define HISI_PMIC_VIBRATOR_GATE_VOLTAGE1_L 0xA01C
#define HISI_PMIC_VIBRATOR_GATE_VOLTAGE1_VALUE_L 0xA0
#define HISI_PMIC_VIBRATOR_GATE_VOLTAGE1_H 0xA01D
#define HISI_PMIC_VIBRATOR_GATE_VOLTAGE1_VALUE_H 0x0
#define HISI_PMIC_VIBRATOR_GATE_VOLTAGE2_L 0xA01E
#define HISI_PMIC_VIBRATOR_GATE_VOLTAGE2_VALUE_L 0x60
#define HISI_PMIC_VIBRATOR_GATE_VOLTAGE2_H 0xA01F
#define HISI_PMIC_VIBRATOR_GATE_VOLTAGE2_VALUE_H 0x0
#define HISI_PMIC_VIBRATOR_GATE_VOLTAGE3_L 0xA020
#define HISI_PMIC_VIBRATOR_GATE_VOLTAGE3_VALUE_L 0x20
#define HISI_PMIC_VIBRATOR_GATE_VOLTAGE3_H 0xA021
#define HISI_PMIC_VIBRATOR_GATE_VOLTAGE3_VALUE_H 0x0
#define HISI_PMIC_VIBRATOR_STATUS 0xA04F

#define OVDR_DUTY_A 94060
#define OVDR_DUTY_B 35914000

#define TH_BOOST_A 273147
#define TH_BOOST_B 371927000

#define BRAKE_DUTY_A 135169
#define BRAKE_DUTY_B 40406000

#define LRA_NML_TIME 0x411
#define LRA_CYCLE_NUM 0x10
#define LRA_TIME_NUM 0x3D090
#define LRA_TIME_NUM1 0x61A8
#define LRA_HAPTIC_NUM 0xA
#define LRA_HAPTIC_NUM1 0x5
#define LRA_DEFAULT_FREQ 0x4FC97

#define PMIC_VIBRATOR_BRAKE_TIME_OUT 100
#define POWER_USED_BOOST_5V 1
#define POWER_NOTUSED_BOOST_5V 0
#define PMIC_VIBRATOR_POWER_ON 1
#define PMIC_VIBRATOR_POWER_OFF 0
#define LED_VIBRATOR_OFF 0

#define PMIC_VIBRATOR_FREQ_MAX 0x53554
#define PMIC_VIBRATOR_FREQ_MIN 0x4C87C

#define DUTY_NUM 240
#define VOLTAGE_NUM 3200

#define PMIC_VIBRATOR_HAP_BUF_LENGTH 16
#define PMIC_VIBRATOR_VOL_LEVEL_1 1
#define PMIC_VIBRATOR_VOL_LEVEL_10 10
#define PMIC_VIBRATOR_VOL_LEVEL_16 16
#define PMIC_VIBRATOR_STRENGTH_STEP1 200 // 200mv
#define PMIC_VIBRATOR_STRENGTH_STEP2 500 // 500mv

#define HISI_PMIC_VIBRATOR_IRQ_COUNTS 5

#endif
