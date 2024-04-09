/*
 * Copyright (c) 2016 Synopsys, Inc.
 *
 * Synopsys DP TX Linux Software Driver and documentation (hereinafter,
 * "Software") is an Unsupported proprietary work of Synopsys, Inc. unless
 * otherwise expressly agreed to in writing between Synopsys and you.
 *
 * The Software IS NOT an item of Licensed Software or Licensed Product under
 * any End User Software License Agreement or Agreement for Licensed Product
 * with Synopsys or any supplement thereto. You are permitted to use and
 * redistribute this Software in source and binary forms, with or without
 * modification, provided that redistributions of source code must retain this
 * notice. You may not view, use, disclose, copy or distribute this file or
 * any information contained herein except pursuant to this license grant from
 * Synopsys. If you do not agree with this notice, including the disclaimer
 * below, then you are not authorized to use the Software.
 *
 * THIS SOFTWARE IS BEING DISTRIBUTED BY SYNOPSYS SOLELY ON AN "AS IS" BASIS
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE HEREBY DISCLAIMED. IN NO EVENT SHALL SYNOPSYS BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
 * DAMAGE.
 */

/*
* Copyright (c) 2017 Hisilicon Tech. Co., Ltd. Integrated into the Hisilicon display system.
*/
#ifndef __DPTX_REG_H__
#define __DPTX_REG_H__

#ifdef CONFIG_HISI_FB_V510
/*DP & USB control REG*/
#define DPTX_DP_AUX_CTRL 0x05C
#endif

/* Constants */
#define DPTX_MP_SINGLE_PIXEL		0
#define DPTX_MP_DUAL_PIXEL		1
#define DPTX_MP_QUAD_PIXEL		2

/* Controller Version Registers */
#define DPTX_VER_NUMBER			0x00
#define DPTX_VER_100a			0x31303061

#define DPTX_VER_TYPE			0x04

#define DPTX_ID				0x08
#define DPTX_ID_DEVICE_ID               0x9001
#define DPTX_ID_VENDOR_ID		0x16c3

/* DPTX Configuration Register */
#define DPTX_CONFIG1			0x100

/* CoreControl Register */
#define DPTX_CCTL			0x200
#define DPTX_SRST_CTRL			0x204

/* MST */
#define DPTX_MST_VCP_TABLE_REG_N(n)	(0x210 + (n) * 4)
#define DP_DPRX_ESI_LEN 14

/* Video Registers. N=0-3 */
#ifdef CONFIG_HISI_FB_V510
#define DPTX_VSAMPLE_CTRL_N(n)		(0x300  + 0x10000 * (n))
#define DPTX_VSAMPLE_RESERVED1_N(n)	(0x304  + 0x10000 * (n))
#define DPTX_VSAMPLE_RESERVED2_N(n)	(0x308  + 0x10000 * (n))
#define DPTX_VSAMPLE_POLARITY_CTRL_N(n)	(0x30C  + 0x10000 * (n))
#define DPTX_VIDEO_CONFIG1_N(n)		(0x310  + 0x10000 * (n))
#define DPTX_VIDEO_CONFIG2_N(n)		(0x314  + 0x10000 * (n))
#define DPTX_VIDEO_CONFIG3_N(n)		(0x318  + 0x10000 * (n))
#define DPTX_VIDEO_CONFIG4_N(n)		(0x31c  + 0x10000 * (n))
#define DPTX_VIDEO_CONFIG5_N(n)		(0x320  + 0x10000 * (n))
#define DPTX_VIDEO_MSA1_N(n)		(0x324  + 0x10000 * (n))
#define DPTX_VIDEO_MSA2_N(n)		(0x328  + 0x10000 * (n))
#define DPTX_VIDEO_MSA3_N(n)		(0x32C  + 0x10000 * (n))
#define DPTX_VG_CONFIG1_N(n)		(0x3804 + 0x10000 * (n))
#define DPTX_VG_CONFIG2_N(n)		(0x3808 + 0x10000 * (n))
#define DPTX_VG_CONFIG3_N(n)		(0x380C + 0x10000 * (n))
#define DPTX_VG_CONFIG4_N(n)		(0x3810 + 0x10000 * (n))
#define DPTX_VG_CONFIG5_N(n)		(0x3814 + 0x10000 * (n))
#define DPTX_VG_SWRST_N(n)		(0x3800 + 0x10000 * (n))
#else
#define DPTX_VSAMPLE_CTRL_N(n)		(0x300)
#define DPTX_VSAMPLE_RESERVED1_N(n)	(0x304)
#define DPTX_VSAMPLE_RESERVED2_N(n)	(0x308)
#define DPTX_VSAMPLE_POLARITY_CTRL_N(n)	(0x30C)
#define DPTX_VIDEO_CONFIG1_N(n)		(0x310)
#define DPTX_VIDEO_CONFIG2_N(n)		(0x314)
#define DPTX_VIDEO_CONFIG3_N(n)		(0x318)
#define DPTX_VIDEO_CONFIG4_N(n)		(0x31c)
#define DPTX_VIDEO_CONFIG5_N(n)		(0x320)
#define DPTX_VIDEO_MSA1_N(n)		(0x324)
#define DPTX_VIDEO_MSA2_N(n)		(0x328)
#define DPTX_VIDEO_MSA3_N(n)		(0x32C)
#define DPTX_VG_CONFIG1_N(n)		(0x3804)
#define DPTX_VG_CONFIG2_N(n)		(0x3808)
#define DPTX_VG_CONFIG3_N(n)		(0x380C)
#define DPTX_VG_CONFIG4_N(n)		(0x3810)
#define DPTX_VG_CONFIG5_N(n)		(0x3814)
#define DPTX_VG_SWRST_N(n)		(0x3800)
#endif
#define DPTX_VIDEO_HBLANK_INTERVAL	0x330
#define DPTX_VIDEO_HBLANK_INTERVAL_SHIFT 16
#define DPTX_VIDEO_HBLANK_INTERVAL_ENABLE 1
/* Audio Registers */
#define DPTX_AUD_CONFIG1		0x400
#define DPTX_AG_CONFIG1			0x3904
#define DPTX_AG_CONFIG2			0x3908
#define DPTX_AG_CONFIG3			0x390C
#define DPTX_AG_CONFIG4			0x3910
#define DPTX_AG_CONFIG5			0x3914
#define DPTX_AG_CONFIG6			0x3918

/* SecondaryDataPacket Registers */
#define DPTX_SDP_VERTICAL_CTRL		0x500
#define DPTX_SDP_HORIZONTAL_CTRL        0x504
#define DPTX_SDP_STATUS			0x508
#define DPTX_SDP_BANK			0x600

/* PHY Layer Control Registers */
#define DPTX_PHYIF_CTRL			0xA00
#define DPTX_PHY_TX_EQ			0xA04
#define DPTX_CUSTOMPAT0			0xA08
#define DPTX_CUSTOMPAT1			0xA0C
#define DPTX_CUSTOMPAT2			0xA10
#define DPTX_PHYREG_CMDADDR		0xC00
#define DPTX_PHYREG_DATA		0xC04
#define DPTX_TYPE_C_CTRL		0xC08

/* AUX Channel Interface Registers */
#define DPTX_AUX_CMD			0xB00
#define DPTX_AUX_STS			0xB04
#define DPTX_AUX_DATA0			0xB08
#define DPTX_AUX_DATA1			0xB0C
#define DPTX_AUX_DATA2			0xB10
#define DPTX_AUX_DATA3			0xB14

/* Interrupt Registers */
#define DPTX_ISTS			0xD00
#define DPTX_IEN			0xD04
#define DPTX_HPDSTS			0xD08
#define DPTX_HPD_IEN			0xD0C

/* HDCP Registers */
#define DPTX_HDCP_CONFIG		0xE00
#define DPTX_HDCP_API_INT_MSK		0xE10

/* I2C APB Registers */
#define DPTX_I2C_ENABLE			0xc006c
#define DPTX_I2C_CTRL			0xc0000
#define DPTX_I2C_TARGET			0xc0004
#define DPTX_I2C_DATA_CMD		0xc0010
#define DPTX_PLUG_ORIENTATION_MASK	BIT(4)

/* RAM Registers */
#ifdef CONFIG_HISI_FB_V510
#define DPTX_VG_RAM_ADDR_N(n)		(0x381C + 0x10000 * (n))
#define DPTX_VG_WRT_RAM_CTR_N(n)	(0x3820 + 0x10000 * (n))
#define DPTX_VG_WRT_RAM_DATA_N(n)	(0x3824 + 0x10000 * (n))
#else
#define DPTX_VG_RAM_ADDR_N(n)		(0x381C)
#define DPTX_VG_WRT_RAM_CTR_N(n)	(0x3820)
#define DPTX_VG_WRT_RAM_DATA_N(n)	(0x3824)
#endif

/* WRAP Registers */
#ifdef CONFIG_HISI_FB_V510
#define DPTX_WRAP_REG_OFFSET		0x42000
#define DPTX_WRAP_REG_DPC_INTS	0x4210c
#define DPTX_WRAP_REG_DPC_INT_MASK	0x42110

#define DPTX_DPC_AUX_CTRL_BLOCK		BIT(10)
#define DPTX_TYPEC_AUX_VOD_TUNE_SHIFT	4
#define DPTX_TYPEC_AUX_VOD_TUNE_MASK	GENMASK(5, 4)
#else
#define DPTX_WRAP_REG_OFFSET		0x12000

#define DPTX_WRAP_REG_DPC_INTS	0x1210c
#define DPTX_WRAP_REG_DPC_INT_MASK	0x12110

#ifdef CONFIG_HISI_FB_V501
#define DPTX_WRAP_REG_DPC_AUX_CTRL  0x122B8
#else
#define DPTX_WRAP_REG_DPC_AUX_CTRL  0x12298
#endif

#define DPTX_DPC_AUX_CTRL_BLOCK		BIT(0)
#define DPTX_TYPEC_AUX_VOD_TUNE_SHIFT	12
#define DPTX_TYPEC_AUX_VOD_TUNE_MASK	GENMASK(13, 12)
#endif

#define DPTX_TYPEC_INTERRUPT_STATUS		BIT(2)
#define DPTX_TYPEC_DISABLE_STATUS		BIT(1)
#define DPTX_TYPEC_DISABLE_ACK		BIT(0)

#define DPTX_VG_RAM_ADDR_START_SHIFT	12
#define DPTX_VG_RAM_ADDR_START_MASK	GENMASK(0, 12)
#define DPTX_VG_RAM_CTR_START_SHIFT	0
#define DPTX_VG_RAM_CTR_START_MASK	BIT(0)
#define DPTX_VG_WRT_RAM_DATA_SHIFT	0
#define DPTX_VG_WRT_RAM_DATA_MASK	GENMASK(0, 7)

/* Register Bitfields */
#define DPTX_ID_DEVICE_ID_SHIFT		16
#define DPTX_ID_DEVICE_ID_MASK		GENMASK(31, 16)
#define DPTX_ID_VENDOR_ID_SHIFT		0
#define DPTX_ID_VENDOR_ID_MASK		GENMASK(15, 0)

#define DPTX_CONFIG1_NUM_STREAMS_SHIFT	16
#define DPTX_CONFIG1_NUM_STREAMS_MASK	GENMASK(18, 16)
#define DPTX_CONFIG1_MP_MODE_SHIFT	19
#define DPTX_CONFIG1_MP_MODE_MASK	GENMASK(21, 19)
#define DPTX_CONFIG1_MP_MODE_SINGLE	1
#define DPTX_CONFIG1_MP_MODE_DUAL	2
#define DPTX_CONFIG1_MP_MODE_QUAD	4
#define DPTX_CONFIG1_DSC_EN		BIT(22)
#define DPTX_CONFIG1_NUM_DSC_ENC_SHIFT	25
#define DPTX_CONFIG1_NUM_DSC_ENC_MASK	GENMASK(28, 25)
#define DPTX_CONFIG1_GEN2_PHY		BIT(29)

#define DPTX_CCTL_ENH_FRAME_EN		BIT(1)
#define DPTX_CCTL_ENABLE_MST_MODE	BIT(25)
#define DPTX_CCTL_ENABLE_FEC			BIT(26)
#define DPTX_CCTL_INITIATE_MST_ACT	BIT(28)
#define DPTX_CCTL_ENH_FRAME_FEC_EN	BIT(29)

#define DPTX_CCTL_FORCE_HPD			BIT(4)

#define DPTX_SRST_CTRL_CONTROLLER	BIT(0)
#define DPTX_SRST_CTRL_PHY		BIT(1)
#define DPTX_SRST_CTRL_HDCP		BIT(2)
#define DPTX_SRST_CTRL_AUDIO_SAMPLER	BIT(3)
#define DPTX_SRST_CTRL_AUX		BIT(4)
#ifdef CONFIG_HISI_FB_V510
#define DPTX_SRST_VIDEO_RESET_N(n)	BIT(5 + n)
#define DPTX_SRST_CTRL_ALL (DPTX_SRST_CTRL_CONTROLLER |		\
				DPTX_SRST_CTRL_PHY |		\
				DPTX_SRST_CTRL_HDCP |		\
				DPTX_SRST_CTRL_AUDIO_SAMPLER |	\
				DPTX_SRST_CTRL_AUX)
#else
#define DPTX_SRST_VIDEO_RESET_N(n)	BIT(5)
#define DPTX_SRST_CTRL_ALL (DPTX_SRST_CTRL_CONTROLLER |		\
				DPTX_SRST_CTRL_HDCP |		\
				DPTX_SRST_CTRL_AUDIO_SAMPLER |	\
				DPTX_SRST_CTRL_AUX)
#endif

#define DPTX_PHYIF_CTRL_TPS_SEL_SHIFT	0
#define DPTX_PHYIF_CTRL_TPS_SEL_MASK	GENMASK(3, 0)
#define DPTX_PHYIF_CTRL_TPS_NONE	0
#define DPTX_PHYIF_CTRL_TPS_1		1
#define DPTX_PHYIF_CTRL_TPS_2		2
#define DPTX_PHYIF_CTRL_TPS_3		3
#define DPTX_PHYIF_CTRL_TPS_4		4
#define DPTX_PHYIF_CTRL_TPS_SYM_ERM	5
#define DPTX_PHYIF_CTRL_TPS_PRBS7	6
#define DPTX_PHYIF_CTRL_TPS_CUSTOM80	7
#define DPTX_PHYIF_CTRL_TPS_CP2520_1	8
#define DPTX_PHYIF_CTRL_TPS_CP2520_2	9
#define DPTX_PHYIF_CTRL_RATE_SHIFT	4
#define DPTX_PHYIF_CTRL_RATE_MASK	GENMASK(5, 4)
#define DPTX_PHYIF_CTRL_LANES_SHIFT	6
#define DPTX_PHYIF_CTRL_LANES_MASK	GENMASK(7, 6)
#define DPTX_PHYIF_CTRL_RATE_RBR	0x0
#define DPTX_PHYIF_CTRL_RATE_HBR	0x1
#define DPTX_PHYIF_CTRL_RATE_HBR2	0x2
#define DPTX_PHYIF_CTRL_RATE_HBR3	0x3
#define DPTX_PHYIF_CTRL_XMIT_EN_SHIFT	8
#define DPTX_PHYIF_CTRL_XMIT_EN_MASK	GENMASK(11, 8)
#define DPTX_PHYIF_CTRL_XMIT_EN(lane)	BIT(8 + lane)
#define DPTX_PHYIF_CTRL_BUSY(lane)	BIT(12 + lane)
#define DPTX_PHYIF_CTRL_SSC_DIS		BIT(16)
#define DPTX_PHYIF_CTRL_LANE_PWRDOWN_SHIFT 17
#define DPTX_PHYIF_CTRL_PWRDOWN_MASK GENMASK(20, 17)              /*GA*/

//#define DPTX_PHYIF_CTRL_LANE_PWRDOWN_SHIFT(lane) (17 + lane * 2)                         /*EA03*/
#define DPTX_PHYIF_CTRL_LANE_PWRDOWN_MASK(lane) GENMASK(17 + lane * 2 + 1, \
							17 + lane * 2)

#define DPTX_PHYIF_CTRL_WIDTH		BIT(25)

#define DPTX_PHY_TX_EQ_PREEMP_SHIFT(lane)	(6 * lane)
#define DPTX_PHY_TX_EQ_PREEMP_MASK(lane)	GENMASK(6 * lane + 1, 6 * lane)
#define DPTX_PHY_TX_EQ_VSWING_SHIFT(lane)	(6 * lane + 2)
#define DPTX_PHY_TX_EQ_VSWING_MASK(lane)	GENMASK(6 * lane + 3, \
							6 * lane + 2)

#define DPTX_AUX_CMD_REQ_LEN_SHIFT	0
#define DPTX_AUX_CMD_REQ_LEN_MASK	GENMASK(3, 0)
#define DPTX_AUX_CMD_I2C_ADDR_ONLY	BIT(4)
#define DPTX_AUX_CMD_ADDR_SHIFT		8
#define DPTX_AUX_CMD_ADDR_MASK		GENMASK(27, 8)
#define DPTX_AUX_CMD_TYPE_SHIFT		28
#define DPTX_AUX_CMD_TYPE_MASK		GENMASK(31, 28)
#define DPTX_AUX_CMD_TYPE_WRITE		0x0
#define DPTX_AUX_CMD_TYPE_READ		0x1
#define DPTX_AUX_CMD_TYPE_WSU		0x2
#define DPTX_AUX_CMD_TYPE_MOT		0x4
#define DPTX_AUX_CMD_TYPE_NATIVE	0x8

#define DPTX_AUX_STS_STATUS_SHIFT	4
#define DPTX_AUX_STS_STATUS_MASK	GENMASK(7, 4)
#define DPTX_AUX_STS_STATUS_ACK		0x0
#define DPTX_AUX_STS_STATUS_NACK	0x1
#define DPTX_AUX_STS_STATUS_DEFER	0x2
#define DPTX_AUX_STS_STATUS_I2C_NACK	0x4
#define DPTX_AUX_STS_STATUS_I2C_DEFER	0x8
#define DPTX_AUX_STS_AUXM_SHIFT		8
#define DPTX_AUX_STS_AUXM_MASK		GENMASK(15, 8)
#define DPTX_AUX_STS_REPLY_RECEIVED	BIT(16)
#define DPTX_AUX_STS_TIMEOUT		BIT(17)
#define DPTX_AUX_STS_REPLY_ERR		BIT(18)
#define DPTX_AUX_STS_BYTES_READ_SHIFT	19
#define DPTX_AUX_STS_BYTES_READ_MASK	GENMASK(23, 19)
#define DPTX_AUX_STS_SINK_DWA		BIT(24)

#define DPTX_ISTS_HPD			BIT(0)
#define DPTX_ISTS_AUX_REPLY		BIT(1)
#define DPTX_ISTS_HDCP			BIT(2)
#define DPTX_ISTS_AUX_CMD_INVALID	BIT(3)
#define DPTX_ISTS_SDP			BIT(4)
#define DPTX_ISTS_AUDIO_FIFO_OVERFLOW	BIT(5)
#define DPTX_ISTS_VIDEO_FIFO_OVERFLOW	BIT(6)
#define DPTX_ISTS_TYPE_C		BIT(7)
#define DPTX_ISTS_ALL_INTR	(DPTX_ISTS_HPD |			\
				 DPTX_ISTS_AUX_REPLY |			\
				 DPTX_ISTS_HDCP |			\
				 DPTX_ISTS_AUX_CMD_INVALID |		\
				 DPTX_ISTS_SDP |			\
				 DPTX_ISTS_AUDIO_FIFO_OVERFLOW |	\
				 DPTX_ISTS_VIDEO_FIFO_OVERFLOW |	\
				 DPTX_ISTS_TYPE_C)

#define DPTX_IEN_HPD			BIT(0)
#define DPTX_IEN_AUX_REPLY		BIT(1)
#define DPTX_IEN_HDCP			BIT(2)
#define DPTX_IEN_AUX_CMD_INVALID	BIT(3)
#define DPTX_IEN_SDP			BIT(4)
#define DPTX_IEN_AUDIO_FIFO_OVERFLOW	BIT(5)
#define DPTX_IEN_VIDEO_FIFO_OVERFLOW	BIT(6)
#define DPTX_IEN_TYPE_C			BIT(7)
#define DPTX_IEN_ALL_INTR	(DPTX_IEN_HPD |		\
				 DPTX_IEN_AUX_REPLY |		\
				 DPTX_IEN_HDCP |		\
				 DPTX_IEN_AUX_CMD_INVALID |	\
				 DPTX_IEN_SDP |			\
				 DPTX_IEN_TYPE_C)

#define DPTX_HPDSTS_IRQ			BIT(0)
#define DPTX_HPDSTS_HOT_PLUG		BIT(1)
#define DPTX_HPDSTS_HOT_UNPLUG		BIT(2)

#define DPTX_HPDSTS_STATUS_GA			BIT(8)     //GA
#define DPTX_HPDSTS_STATUS_EA03		BIT(3)            //EA03

#define DPTX_HPDSTS_STATE_SHIFT		4
#define DPTX_HPDSTS_STATE_MASK		GENMASK(6, 4)
#define DPTX_HPDSTS_TIMER_SHIFT		16
#define DPTX_HPDSTS_TIMER_MASK		GENMASK(31, 16)

#define DPTX_HPD_IEN_IRQ_EN		DPTX_HPDSTS_IRQ
#define DPTX_HPD_IEN_HOT_PLUG_EN	DPTX_HPDSTS_HOT_PLUG
#define DPTX_HPD_IEN_HOT_UNPLUG_EN	DPTX_HPDSTS_HOT_UNPLUG

#define DPTX_VSAMPLE_CTRL_STREAM_EN	BIT(5)

#define DPTX_AG_CONFIG1_WORD_WIDTH_SHIFT		6
#define DPTX_AG_CONFIG1_WORD_WIDTH_MASK			GENMASK(9, 6)
#define DPTX_AG_CONFIG1_USE_LUT_SHIFT			14
#define DPTX_AG_CONFIG1_USE_LUT_MASK			BIT(14)
#define DPTX_AG_CONFIG3_CH_NUMCL0_SHIFT			24
#define DPTX_AG_CONFIG3_CH_NUMCL0_MASK			GENMASK(27, 24)
#define DPTX_AG_CONFIG3_CH_NUMCR0_SHIFT			28
#define DPTX_AG_CONFIG3_CH_NUMCR0_MASK			GENMASK(31, 28)
#define DPTX_AG_CONFIG4_SAMP_FREQ_SHIFT			0
#define DPTX_AG_CONFIG4_SAMP_FREQ_MASK			GENMASK(3, 0)
#define DPTX_AG_CONFIG4_WORD_LENGTH_SHIFT		8
#define DPTX_AG_CONFIG4_WORD_LENGTH_MASK		GENMASK(11, 8)
#define DPTX_AG_CONFIG4_ORIG_SAMP_FREQ_SHIFT		12
#define DPTX_AG_CONFIG4_ORIG_SAMP_FREQ_MASK		GENMASK(15, 12)
#define DPTX_AUD_CONFIG1_INF_TYPE_SHIFT			0
#define DPTX_AUD_CONFIG1_INF_TYPE_MASK			BIT(0)
#define DPTX_AUD_CONFIG1_NCH_DEFAULT_VALUE			1
#define DPTX_AUD_CONFIG1_NCH_SHIFT			12
#define DPTX_AUD_CONFIG1_NCH_MASK			GENMASK(14, 12)
#define DPTX_AUD_CONFIG1_DATA_WIDTH_SHIFT		5
#define DPTX_AUD_CONFIG1_DATA_WIDTH_MASK		GENMASK(9, 5)
#define DPTX_AUD_CONFIG1_DATA_EN_IN_SHIFT		1
#define DPTX_AUD_CONFIG1_DATA_EN_IN_MASK		GENMASK(4, 1)
#define DPTX_AUD_CONFIG1_ATS_VER_SHFIT			24
#define DPTX_AUD_CONFIG1_ATS_VER_MASK			GENMASK(29, 24)

#define DPTX_VSAMPLE_CTRL_VMAP_BPC_SHIFT                16
#define DPTX_VSAMPLE_CTRL_VMAP_BPC_MASK                 GENMASK(20, 16)
#define DPTX_VSAMPLE_CTRL_MULTI_PIXEL_SHIFT		21
#define DPTX_VSAMPLE_CTRL_MULTI_PIXEL_MASK		GENMASK(22, 21)
#define DPTX_VSAMPLE_CTRL_ENABLE_DSC			BIT(23)
#define DPTX_VSAMPLE_CTRL_QUAD_PIXEL			DPTX_MP_QUAD_PIXEL
#define DPTX_VSAMPLE_CTRL_DUAL_PIXEL			DPTX_MP_DUAL_PIXEL
#define DPTX_VSAMPLE_CTRL_SINGLE_PIXEL			DPTX_MP_SINGLE_PIXEL
#define DPTX_VIDEO_VMSA2_BPC_SHIFT                      29
#define DPTX_VIDEO_VMSA2_BPC_MASK                       GENMASK(31, 29)
#define DPTX_VIDEO_VMSA2_COL_SHIFT                      25
#define DPTX_VIDEO_VMSA2_COL_MASK                       GENMASK(28, 25)
#define DPTX_VIDEO_VMSA3_PIX_ENC_SHIFT                  31
#define DPTX_VIDEO_VMSA3_PIX_ENC_YCBCR420_SHIFT           30 // ignore MSA
#define DPTX_VIDEO_VMSA3_PIX_ENC_MASK                   GENMASK(31, 30)
#define DPTX_POL_CTRL_V_SYNC_POL_EN			BIT(0)
#define DPTX_POL_CTRL_H_SYNC_POL_EN			BIT(1)
#define DPTX_POL_CTRL_DE_IN_POL_EN			BIT(2)
#define DPTX_VIDEO_CONFIG1_IN_OSC_EN			BIT(0)
#define DPTX_VIDEO_CONFIG1_O_IP_EN			BIT(1)
#define DPTX_VIDEO_H_BLANK_SHIFT			2
#define DPTX_VIDEO_H_ACTIVE_SHIFT			16
#define DPTX_VIDEO_V_BLANK_SHIFT			16
#define DPTX_VIDEO_V_ACTIVE_SHIFT			0
#define DPTX_VIDEO_H_FRONT_PORCH			0
#define DPTX_VIDEO_H_SYNC_WIDTH				16
#define DPTX_VIDEO_V_FRONT_PORCH			0
#define DPTX_VIDEO_V_SYNC_WIDTH				16
#define DPTX_VIDEO_MSA1_H_START_SHIFT			0
#define DPTX_VIDEO_MSA1_V_START_SHIFT			16
#define DPTX_VIDEO_CONFIG5_TU_SHIFT			0
#define DPTX_VIDEO_CONFIG5_TU_MASK			GENMASK(6, 0)
#define DPTX_VIDEO_CONFIG5_TU_FRAC_SHIFT_MST            14
#define DPTX_VIDEO_CONFIG5_TU_FRAC_MASK_MST             GENMASK(19, 14)
#define DPTX_VIDEO_CONFIG5_TU_FRAC_SHIFT_SST            16
#define DPTX_VIDEO_CONFIG5_TU_FRAC_MASK_SST             GENMASK(19, 16)
#define DPTX_VIDEO_CONFIG5_INIT_THRESHOLD_SHIFT		7
#define DPTX_VIDEO_CONFIG5_INIT_THRESHOLD_MASK		GENMASK(13, 7)

#define DPTX_VG_CONFIG1_BPC_SHIFT			12
#define DPTX_VG_CONFIG1_BPC_MASK			GENMASK(14, 12)
#define DPTX_VG_CONFIG1_PATTERN_SHIFT			17
#define DPTX_VG_CONFIG1_PATTERN_MASK			GENMASK(18, 17)
#define DPTX_VG_CONFIG1_MULTI_PIXEL_SHIFT		19
#define DPTX_VG_CONFIG1_MULTI_PIXEL_MASK		GENMASK(20, 19)
#define DPTX_VG_CONFIG1_QUAD_PIXEL			DPTX_MP_QUAD_PIXEL
#define DPTX_VG_CONFIG1_DUAL_PIXEL			DPTX_MP_DUAL_PIXEL
#define DPTX_VG_CONFIG1_SINGLE_PIXEL			DPTX_MP_SINGLE_PIXEL
#define DPTX_VG_CONFIG1_ODE_POL_EN			BIT(0)
#define DPTX_VG_CONFIG1_OH_SYNC_POL_EN			BIT(1)
#define DPTX_VG_CONFIG1_OV_SYNC_POL_EN			BIT(2)
#define DPTX_VG_CONFIG1_OIP_EN				BIT(3)
#define DPTX_VG_CONFIG1_BLANK_IN_OSC_EN			BIT(5)
#define DPTX_VG_CONFIG1_YCC_422_EN			BIT(6)
#define DPTX_VG_CONFIG1_YCC_PATTERN_GEN_EN		BIT(7)
#define DPTX_VG_CONFIG1_YCC_420_EN			BIT(15)
#define DPTX_VG_CONFIG1_PIXEL_REP_SHIFT			12
#define DPTX_VG_CONFIG2_H_ACTIVE_SHIFT			0
#define DPTX_VG_CONFIG2_H_BLANK_SHIFT			16

#define DPTX_EN_AUDIO_TIMESTAMP_SDP			BIT(0)
#define DPTX_EN_AUDIO_STREAM_SDP			BIT(1)
#define DPTX_EN_AUDIO_INFOFRAME_SDP			BIT(2)
#define DPTX_EN_AUDIO_CH_1				1
#define DPTX_EN_AUDIO_CH_2				1
#define DPTX_EN_AUDIO_CH_3                              3
#define DPTX_EN_AUDIO_CH_4				9
#define DPTX_EN_AUDIO_CH_5				7
#define DPTX_EN_AUDIO_CH_6				7
#define DPTX_EN_AUDIO_CH_7				0xF
#define DPTX_EN_AUDIO_CH_8				0xF
#define DPTX_AUDIO_MUTE					BIT(15)

#define DPTX_AUDIO_REFER_TO_STREAM_HEADER		0x0    /* Configured to 0, sink just check stream head */

#define DPTX_AUDIO_CHANNEL_CNT_2CH				0x1
#define DPTX_AUDIO_CHANNEL_CNT_3CH				0x2
#define DPTX_AUDIO_CHANNEL_CNT_4CH				0x3
#define DPTX_AUDIO_CHANNEL_CNT_5CH				0x4
#define DPTX_AUDIO_CHANNEL_CNT_6CH				0x5
#define DPTX_AUDIO_CHANNEL_CNT_7CH				0x6
#define DPTX_AUDIO_CHANNEL_CNT_8CH				0x7
#define DPTX_AUDIO_CHANNEL_CNT_SHIFT			0
#define DPTX_AUDIO_CHANNEL_CNT_MASK			GENMASK(2, 0)

#define DPTX_AUDIO_CODING_TYPE_LPCM			0x1
#define DPTX_AUDIO_CODING_TYPE_AC3				0x2
#define DPTX_AUDIO_CODING_TYPE_MPEG1			0x3
#define DPTX_AUDIO_CODING_TYPE_MP3				0x4
#define DPTX_AUDIO_CODING_TYPE_MPEG2			0x5
#define DPTX_AUDIO_CODING_TYPE_AAC				0x6
#define DPTX_AUDIO_CODING_TYPE_DTS				0x7
#define DPTX_AUDIO_CODING_TYPE_ATRAC			0x8
#define DPTX_AUDIO_CODING_TYPE_ONE_BIT_AUDIO	0x9
#define DPTX_AUDIO_CODING_TYPE_E_AC3			0xA
#define DPTX_AUDIO_CODING_TYPE_DTS_HD			0xB
#define DPTX_AUDIO_CODING_TYPE_MAT				0xC
#define DPTX_AUDIO_CODING_TYPE_DST				0xD
#define DPTX_AUDIO_CODING_TYPE_WMA_PRO		0xE
#define DPTX_AUDIO_CODING_TYPE_REFER_TO_CXT	0xF
#define DPTX_AUDIO_CODING_TYPE_SHIFT			4
#define DPTX_AUDIO_CODING_TYPE_MASK			GENMASK(7, 4)

#define DPTX_AUDIO_SAMPLE_SIZE_16BIT			0x1
#define DPTX_AUDIO_SAMPLE_SIZE_20BIT			0x2
#define DPTX_AUDIO_SAMPLE_SIZE_24BIT			0x3
#define DPTX_AUDIO_SAMPLE_SIZE_SHIFT			8
#define DPTX_AUDIO_SAMPLE_SIZE_MASK			GENMASK(9, 8)

#define DPTX_AUDIO_SAMPLE_FREQ_32K				0x1
#define DPTX_AUDIO_SAMPLE_FREQ_44_1K			0x2
#define DPTX_AUDIO_SAMPLE_FREQ_48K				0x3
#define DPTX_AUDIO_SAMPLE_FREQ_88_2K			0x4
#define DPTX_AUDIO_SAMPLE_FREQ_96K				0x5
#define DPTX_AUDIO_SAMPLE_FREQ_176_4K			0x6
#define DPTX_AUDIO_SAMPLE_FREQ_192K			0x7
#define DPTX_AUDIO_SAMPLE_FREQ_SHIFT			10
#define DPTX_AUDIO_SAMPLE_FREQ_MASK			GENMASK(12, 10)

/* Data Bytes 4 and 5 apply only to multi-channel (i.e., more than two channels) Uncompressed Audio */
/* Data Byte 4 contains information that describes how various speaker locations are allocated to
transmission channels. */
#define DPTX_AUDIO_SPEAKER_MAPPING_2CH			0x0		/* - - - - - FR FL */
#define DPTX_AUDIO_SPEAKER_MAPPING_3CH			0x2		/* - - - - FC - FR FL */
#define DPTX_AUDIO_SPEAKER_MAPPING_4CH			0x3		/* - - - - FC LFE FR FL */
#define DPTX_AUDIO_SPEAKER_MAPPING_5CH			0x7		/* - - - RC FC LFE FR FL */
#define DPTX_AUDIO_SPEAKER_MAPPING_6CH			0xB		/* - - RR RL FC LFE FR FL */
#define DPTX_AUDIO_SPEAKER_MAPPING_7CH			0xF		/* - RC RR RL FC LFE FR FL */
#define DPTX_AUDIO_SPEAKER_MAPPING_8CH			0x13 	/* RRC RLC RR RL FC LFE FR FL */
#define DPTX_AUDIO_SPEAKER_MAPPING_SHIFT		24
#define DPTX_AUDIO_SPEAKER_MAPPING_MASK		GENMASK(31, 24)

/* Data Byte 5 contains Level Shift Information, a Down-mix Inhibit Flag, and LFE playback level information. */
#define DPTX_AUDIO_LSV_0DB		0x0
#define DPTX_AUDIO_LSV_1DB		0x1
#define DPTX_AUDIO_LSV_2DB		0x2
#define DPTX_AUDIO_LSV_3DB		0x3
#define DPTX_AUDIO_LSV_4DB		0x4
#define DPTX_AUDIO_LSV_5DB		0x5
#define DPTX_AUDIO_LSV_6DB		0x6
#define DPTX_AUDIO_LSV_7DB		0x7
#define DPTX_AUDIO_LSV_8DB		0x8
#define DPTX_AUDIO_LSV_9DB		0x9
#define DPTX_AUDIO_LSV_10DB		0xA
#define DPTX_AUDIO_LSV_11DB		0xB
#define DPTX_AUDIO_LSV_12DB		0xC
#define DPTX_AUDIO_LSV_13DB		0xD
#define DPTX_AUDIO_LSV_14DB		0xE
#define DPTX_AUDIO_LSV_15DB		0xF
#define DPTX_AUDIO_LSV_SHIFT		3
#define DPTX_AUDIO_LSV_MASK		GENMASK(6, 3)

#define DPTX_AUDIO_DOWN_MIX_PERMITETED		0x0		/* Permitted or no information about any assertion of this */
#define DPTX_AUDIO_DOWN_MIX_PROHIBITED		0x1
#define DPTX_AUDIO_DOWN_MIX_SHIFT			7

#define DPTX_HDCP_REG_RMLCTL				0x3614
#define DPTX_HDCP_CFG                                   0xE00
#define DPTX_HDCP_REG_RMLSTS                            0x3618
#define DPTX_HDCP_REG_DPK_CRC				0x3630
#define DPTX_HDCP_REG_DPK0				0x3620
#define DPTX_HDCP_REG_DPK1				0x3624
#define DPTX_HDCP_REG_SEED				0x361C
#define DPTX_HDCP_INT_STS				0xE0C
#define DPTX_HDCP_INT_CLR				0xE08
#define DPTX_HDCP_OBS					0xE04

#define DPTX_HDCP_CFG_DPCD_PLUS_SHIFT			7
#define DPTX_HDCP_CFG_DPCD_PLUS_MASK			BIT(7)
#define DPTX_HDCP_KSV_ACCESS_INT			BIT(0)
#define DPTX_HDCP_AUX_RESP_TIMEOUT			BIT(3)
#define DPTX_HDCP_KSV_SHA1				BIT(5)
#define DPTX_HDCP_FAILED				BIT(6)
#define DPTX_HDCP_ENGAGED				BIT(7)
#define DPTX_HDCP22_GPIOINT				BIT(8)
#define DPTX_REVOC_LIST_MASK				GENMASK(31, 24)
#define DPTX_REVOC_SIZE_SHIFT				23
#define DPTX_REVOC_SIZE_MASK				GENMASK(23, 8)
#define DPTX_ODPK_DECRYPT_ENABLE_SHIFT			0
#define DPTX_ODPK_DECRYPT_ENABLE_MASK			BIT(0)
#define DPTX_IDPK_DATA_INDEX_SHIFT			0
#define DPTX_IDPK_DATA_INDEX_MASK			GENMASK(5, 0)
#define DPTX_IDPK_WR_OK_STS_SHIFT			6
#define DPTX_IDPK_WR_OK_STS_MASK			BIT(6)
#define DPTX_CFG_EN_HDCP13				BIT(2)
#define DPTX_CFG_CP_IRQ					BIT(6)
#define DPTX_CFG_EN_HDCP				BIT(1)

#define DPTX_HDCP22_BOOTED				BIT(23)
#define DPTX_HDCP22_STATE				(BIT(24)|BIT(25)|BIT(26))
#define DPTX_HDCP22_CAP_CHECK_COMPLETE	BIT(27)
#define DPTX_HDCP22_CAPABLE_SINK		BIT(28)
#define DPTX_HDCP22_AUTH_SUCCESS		BIT(29)
#define DPTX_HDCP22_AUTH_FAILED			BIT(30)
#define DPTX_HDCP22_RE_AUTH_REQ			BIT(31)

#define DPTX_DSC_HWCFG 0x0230
#define DPTX_DSC_NUM_ENC_MSK GENMASK(3, 0)
#define DPTX_DSC_CTL 0x0234
#define DPTX_DSC_STREAM0_ENC_CLK_DIV_MSK BIT(18)
#define DPTX_DSC_STREAM0_ENC_CLK_DIV_SHIFT 18

#define DPTX_DSC_ENC_STREAM_SEL(i) GENMASK((2 * i + 1), (2 * i))
#define DPTX_DSC_ENC_STREAM_SEL_SHIFT(i) ((i) * 2)
#define DPTX_DSC_STREAM0_NUM_SLICES_SHIFT 22

// Stream should be [1 .. 4],  SST = 1
#define DPTX_DSC_PPS(stream, i) ((0x3a00 + (stream -1) * 0x10000) + (i * 0x4))
#define DPTX_SST_MODE 1

// PPS SDPs
#define DPTX_DSC_VER_MIN_SHIFT 0
#define DPTX_DSC_VER_MAJ_SHIFT 4
#define DPTX_DSC_BUF_DEPTH_SHIFT 24
#define DPTX_DSC_BLOCK_PRED_SHIFT 5
#define DPTX_DSC_BPP_HIGH_MASK GENMASK(9, 8)
#define DPTX_DSC_BPP_LOW_MASK GENMASK(7, 0)
#define DPTX_DSC_BPP_LOW_MASK1 GENMASK(15, 8)
#define DPTX_DSC_BPC_SHIFT 28

#define DPTX_CONFIG_REG2 0x104
#define DSC_MAX_NUM_LINES_SHIFT 16
#define DSC_MAX_NUM_LINES_MASK GENMASK(31, 16)

#define DPTX_VIDEO_DSCCFG 0x334
#define DPTX_DSC_LSTEER_INT_SHIFT 0
#define DPTX_DSC_LSTEER_FRAC_SHIFT 5
#define DPTX_DSC_LSTEER_XMIT_DELAY_SHIFT 16
#define DPTX_DSC_LSTEER_XMIT_DELAY_MASK GENMASK(31, 16)
#define DPTX_DSC_LSTEER_FRAC_SHIFT_MASK GENMASK(9, 5)
#define DPTX_DSC_LSTEER_INT_SHIFT_MASK GENMASK(4, 0)

#define DPTX_BITS_PER_PIXEL 8 // For Interop testing only RGB 8bpp 8bpc
#define DPTX_BITS_PER_COMPONENT 8 // For Interop testing only RGB 8bpp 8bpc

#define DPTX_EN_HDR_INFOFRAME_SDP BIT(3)
#define DPTX_FIXED_PRIORITY_ARBITRATION BIT(31)
#define DPTX_DISABLE_EXT_SDP BIT(30)
#endif
