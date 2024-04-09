

#if (_PRE_PRODUCT_ID == _PRE_PRODUCT_ID_HI1151)

/* ͷ�ļ����� */
#include "oal_pci_if.h"

#include "oal_hardware.h"
#include "oal_bus_if.h"

#include "securec.h"

#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_OAL_PCI_C

/* ȫ�ֱ������� */
/* PCI����֧�ֵ��豸�б� */
#define OAL_PCI_WITP_DEVICE_ID 0x1151

OAL_CONST oal_pci_device_id_stru pci_id_table[] = {
    { 0x168c, 0x0007, PCI_ANY_ID, PCI_ANY_ID },
    { 0x168c, 0x0012, PCI_ANY_ID, PCI_ANY_ID },
    { 0xa727, 0x0013, PCI_ANY_ID, PCI_ANY_ID }, /* 3com */
    { 0x10b7, 0x0013, PCI_ANY_ID, PCI_ANY_ID }, /* 3com 3CRDAG675 */
    { 0x168c, 0x1014, PCI_ANY_ID, PCI_ANY_ID }, /* IBM minipci 5212 */
    { 0x168c, 0x101a, PCI_ANY_ID, PCI_ANY_ID }, /* some Griffin-Lite */
    { 0x168c, 0x0015, PCI_ANY_ID, PCI_ANY_ID },
    { 0x168c, 0x0016, PCI_ANY_ID, PCI_ANY_ID },
    { 0x168c, 0x0017, PCI_ANY_ID, PCI_ANY_ID },
    { 0x168c, 0x0018, PCI_ANY_ID, PCI_ANY_ID },
    { 0x168c, 0x0019, PCI_ANY_ID, PCI_ANY_ID },
    { 0x168c, 0x001a, PCI_ANY_ID, PCI_ANY_ID },
    { 0x168c, 0x001b, PCI_ANY_ID, PCI_ANY_ID }, /* Eagle */
    { 0x168c, 0x001d, PCI_ANY_ID, PCI_ANY_ID }, /* Nala */
    { 0x168c, 0xff1d, PCI_ANY_ID, PCI_ANY_ID }, /* owl emulation */
    { 0x168c, 0xff1c, PCI_ANY_ID, PCI_ANY_ID }, /* owl emulation */
    { 0x168c, 0x0023, PCI_ANY_ID, PCI_ANY_ID }, /* PCI (MB/CB)   */
    { 0x168c, 0x0024, PCI_ANY_ID, PCI_ANY_ID }, /* PCI-E (XB)    */
    { 0x168c, 0x0027, PCI_ANY_ID, PCI_ANY_ID }, /* Sowl PCI      */
    { 0x168c, 0x0029, PCI_ANY_ID, PCI_ANY_ID }, /* Merlin PCI    */
    { 0x168c, 0x002a, PCI_ANY_ID, PCI_ANY_ID }, /* Merlin PCIE   */
    { 0x168c, 0x002b, PCI_ANY_ID, PCI_ANY_ID }, /* Kite PCIE     */
    { 0x168c, 0x002d, PCI_ANY_ID, PCI_ANY_ID }, /* Kiwi PCI      */
    { 0x168c, 0x002e, PCI_ANY_ID, PCI_ANY_ID }, /* Kiwi PCIE     */
    { 0x168c, 0xabcd, PCI_ANY_ID, PCI_ANY_ID }, /* Osprey PCIE Emulation   */
    { 0x168c, 0x0030, PCI_ANY_ID, PCI_ANY_ID }, /* Osprey PCIE   */
    { 0x168c, 0x0033, PCI_ANY_ID, PCI_ANY_ID }, /* Peacock PCIE  */
    { 0x19e5, 0x1151, PCI_ANY_ID, PCI_ANY_ID }, /* 1151 PCIE  */
    {
        0,
    }
};

oal_pci_bar_idx_enum_uint8 en_bar_table[1] = {
    OAL_PCI_BAR_0, /* 256KB��ַ�ռ䣬����SoC MAC PHY��ַӳ�� */
};

#ifdef _PRE_WLAN_FEATURE_AP_PM
oal_uint8 is_cpu_sleep = OAL_FALSE;
/*lint -e19*/
oal_module_symbol(is_cpu_sleep);
/*lint +e19*/
#endif

/* ��̬�������� */
OAL_STATIC oal_int32 oal_pci_probe(oal_pci_dev_stru *pst_pci_dev, OAL_CONST oal_pci_device_id_stru *pst_id);
OAL_STATIC oal_void oal_pci_remove(oal_pci_dev_stru *pst_pci_dev);
#if (_PRE_CONFIG_TARGET_PRODUCT == _PRE_TARGET_PRODUCT_TYPE_E5)
OAL_STATIC oal_void oal_drv_pcie_pm_sys_resume(oal_void);
#endif

#if (_PRE_OS_VERSION_LINUX == _PRE_OS_VERSION)
OAL_STATIC oal_int32 oal_pci_suspend(oal_pci_dev_stru *pst_pci_dev, oal_pm_message_t state);
OAL_STATIC oal_int32 oal_pci_resume(oal_pci_dev_stru *pst_pci_dev);

OAL_STATIC oal_int32 oal_pci_prepare(oal_device_stru *pst_dev);

#if ((_PRE_TARGET_PRODUCT_TYPE_5610EVB == _PRE_CONFIG_TARGET_PRODUCT) ||  \
     (_PRE_TARGET_PRODUCT_TYPE_VSPM310DMB == _PRE_CONFIG_TARGET_PRODUCT))
#elif (_PRE_TARGET_PRODUCT_TYPE_WS835DMB == _PRE_CONFIG_TARGET_PRODUCT)
/* WS835�͹�����Ҫ��pcie��λ�������Ƿ������Ҫ�������� */
#elif (_PRE_TARGET_PRODUCT_TYPE_E5 == _PRE_CONFIG_TARGET_PRODUCT)
/* E5ƽ̨�ݲ�ʹ��  */
#elif (_PRE_TARGET_PRODUCT_TYPE_CPE == _PRE_CONFIG_TARGET_PRODUCT)
/* CPEƽ̨�ݲ�ʹ��  */
#elif (_PRE_TARGET_PRODUCT_TYPE_ONT == _PRE_CONFIG_TARGET_PRODUCT)
/* ONTƽ̨�ݲ�ʹ��  */
#elif (_PRE_TARGET_PRODUCT_TYPE_5630HERA == _PRE_CONFIG_TARGET_PRODUCT)
#else
#endif
#endif

#if (_PRE_OS_VERSION_LINUX == _PRE_OS_VERSION)
OAL_STATIC oal_dev_pm_ops_stru oal_dev_pm_ops = {
    .prepare = oal_pci_prepare,
};

OAL_STATIC oal_pci_driver_stru pci_drv = {
    .name = "witp_pci",
    .id_table = pci_id_table,
    .probe = oal_pci_probe,
    .remove = oal_pci_remove,
    .suspend = oal_pci_suspend,
    .resume = oal_pci_resume,
    .driver = {
        .pm = &oal_dev_pm_ops,
    },
};

#if (_PRE_CONFIG_TARGET_PRODUCT == _PRE_TARGET_PRODUCT_TYPE_E5)
/* syscore��Ӧ�ṹ�� */
OAL_STATIC oal_pm_syscore_ops drv_pcie_pm_syscore_ops = {
    .resume = oal_drv_pcie_pm_sys_resume,
};
#endif

#elif (_PRE_OS_VERSION_WIN32 == _PRE_OS_VERSION)
OAL_STATIC oal_pci_driver_stru pci_drv = {
    "witp_pci",
    pci_id_table,
    oal_pci_probe,
    oal_pci_remove
};

#if (_PRE_CONFIG_TARGET_PRODUCT == _PRE_TARGET_PRODUCT_TYPE_E5)
/* syscore��Ӧ�ṹ�� */
OAL_STATIC oal_pm_syscore_ops drv_pcie_pm_syscore_ops = {
    oal_drv_pcie_pm_sys_resume,
};
#endif

#endif

oal_void *pst_5115_cfg_base = OAL_PTR_NULL;
oal_void *pst_5115_sys_ctl = OAL_PTR_NULL;
oal_void *pst_5610_mode = OAL_PTR_NULL;
oal_void *pst_5610_gpio = OAL_PTR_NULL;
#if (_PRE_TARGET_PRODUCT_TYPE_5610DMB == _PRE_CONFIG_TARGET_PRODUCT)
oal_void *pst_5610_gpio1 = OAL_PTR_NULL; /* 0x10106000��ַ */
oal_void *pst_5610_gpio2 = OAL_PTR_NULL; /* 0x10108000��ַ */
#endif
#ifdef _PRE_WLAN_FEATURE_PCIE_ADAPT_5116
oal_void *pst_5115_sys_ctl1 = OAL_PTR_NULL; /* v200 5116 pcie1��sys ctrl */
#endif

#if (_PRE_OS_VERSION_LINUX == _PRE_OS_VERSION)
OAL_STATIC oal_int32 oal_pci_suspend(oal_pci_dev_stru *pst_pci_dev, oal_pm_message_t state)
{
#if (_PRE_CONFIG_TARGET_PRODUCT == _PRE_TARGET_PRODUCT_TYPE_E5)
    oal_pci_save_state(pst_pci_dev);
#endif

    OAL_IO_PRINT("enter oal_pcie_suspend\n");

    return OAL_SUCC;
}

OAL_STATIC oal_int32 oal_pci_resume(oal_pci_dev_stru *pst_pci_dev)
{
    OAL_IO_PRINT("enter oal_pcie_resume\n");

#ifdef _PRE_WLAN_FEATURE_AP_PM
    is_cpu_sleep = OAL_FALSE;
#endif

    return OAL_SUCC;
}

/* cpu����ʱ����stop_ap����suspend */
OAL_STATIC oal_int32 oal_pci_prepare(oal_device_stru *pst_dev)
{
    OAL_IO_PRINT("enter oal_pci_prepare\n");

#ifdef _PRE_WLAN_FEATURE_AP_PM
    is_cpu_sleep = OAL_TRUE;
#endif

    return OAL_SUCC;
}

#endif
/* ����ʵ�� */
#ifdef _PRE_WLAN_PRODUCT_1151V200
/*
 * �� �� ��  : oal_pcie_set_inbound_iatu
 * ��������  : ����EP��iATU��,����2��ӳ�����
 *             256KB��BAR0�ռ�:
 *             iATU0: 240K,Ϊsoc+phy+mac�ļĴ�����ַ
 *             iATU1: pcie internal�Ĵ�����ַ
 */
oal_void oal_pcie_set_inbound_iatu(oal_pci_dev_stru *pst_pci_dev)
{
    /* iATU0:BAR0:SoC MAC PHY: 240KB */
    OAL_IO_PRINT("pci_resource_start[0x%lx],pci_resource_en[0x%lx]\n",
                 oal_pci_resource_start(pst_pci_dev, OAL_PCI_BAR_0),
                 oal_pci_resource_end(pst_pci_dev, OAL_PCI_BAR_0));
    oal_pci_write_config_dword(pst_pci_dev, 0x700 + 0x200, 0x80000000); /* view index */
    oal_pci_write_config_dword(pst_pci_dev, 0x700 + 0x204, 0x0); /* ctrl 1 */
    oal_pci_write_config_dword(pst_pci_dev, 0x700 + 0x208, 0x80000000); /* ctrl 2 */
    oal_pci_write_config_dword(pst_pci_dev, 0x700 + 0x20c,
                               oal_pci_resource_start(pst_pci_dev, OAL_PCI_BAR_0)); /* base lower */
    oal_pci_write_config_dword(pst_pci_dev, 0x700 + 0x210, 0); /* base upper */
    oal_pci_write_config_dword(pst_pci_dev, 0x700 + 0x214,
                               oal_pci_resource_start(pst_pci_dev, OAL_PCI_BAR_0) + 0x15FFF); /* limit */
    oal_pci_write_config_dword(pst_pci_dev, 0x700 + 0x218, 0x20000000); /* target lower */
    oal_pci_write_config_dword(pst_pci_dev, 0x700 + 0x21c, 0);

    /* iATU1:BAR0:PCIE Internal: 16KB,��0x3C000��ʼ��ӳ��Ϊ0��ַ */
    oal_pci_write_config_dword(pst_pci_dev, 0x700 + 0x200, 0x80000001); /* view index */
    oal_pci_write_config_dword(pst_pci_dev, 0x700 + 0x204, 0x0); /* ctrl 1 */
    oal_pci_write_config_dword(pst_pci_dev, 0x700 + 0x208, 0x80000000); /* ctrl 2 */
    oal_pci_write_config_dword(pst_pci_dev, 0x700 + 0x20c,
                               oal_pci_resource_start(pst_pci_dev, OAL_PCI_BAR_0) + 0x16000); /* base lower */
    oal_pci_write_config_dword(pst_pci_dev, 0x700 + 0x210, 0); /* base upper */
    oal_pci_write_config_dword(pst_pci_dev, 0x700 + 0x214,
                               oal_pci_resource_start(pst_pci_dev, OAL_PCI_BAR_0) + 0x16FFF); /* limit */
    oal_pci_write_config_dword(pst_pci_dev, 0x700 + 0x218, 0x40000000); /* target lower */
    oal_pci_write_config_dword(pst_pci_dev, 0x700 + 0x21c, 0);

    /* iATU2:BAR0:PCIE Internal: 16KB,��0x3C000��ʼ��ӳ��Ϊ0��ַ */
    oal_pci_write_config_dword(pst_pci_dev, 0x700 + 0x200, 0x80000002); /* view index */
    oal_pci_write_config_dword(pst_pci_dev, 0x700 + 0x204, 0x0); /* ctrl 1 */
    oal_pci_write_config_dword(pst_pci_dev, 0x700 + 0x208, 0x80000000); /* ctrl 2 */
    oal_pci_write_config_dword(pst_pci_dev, 0x700 + 0x20c,
                               oal_pci_resource_start(pst_pci_dev, OAL_PCI_BAR_0) + 0x17000); /* base lower */
    oal_pci_write_config_dword(pst_pci_dev, 0x700 + 0x210, 0); /* base upper */
    oal_pci_write_config_dword(pst_pci_dev, 0x700 + 0x214,
                               oal_pci_resource_end(pst_pci_dev, OAL_PCI_BAR_0)); /* limit */
    oal_pci_write_config_dword(pst_pci_dev, 0x700 + 0x218, 0x20017000); /* target lower */
    oal_pci_write_config_dword(pst_pci_dev, 0x700 + 0x21c, 0);

    /* ��������Ĵ���                                                                         */
    /* BIT0 = 1(I/O Space Enable), BIT1 = 1(Memory Space Enable), BIT2 = 1(Bus Master Enable) */
    oal_pci_write_config_word(pst_pci_dev, 0x04, 0x7);
}

/*
 * �� �� ��  : oal_pcie_set_inbound_iatu_slip_window_fpga
 * ��������  : ���û������EP��iATU��:FPGA��0x30000000�ĵ�ַ�ռ䣬��Ҫ���л�������
 */
oal_void oal_pcie_set_inbound_iatu_slip_window_fpga(oal_pci_dev_stru *pst_pci_dev)
{
    /* iATU0:BAR0:SoC MAC PHY: 240KB */
    OAL_IO_PRINT("pci_resource_start[0x%lx],pci_resource_en[0x%lx]\n",
                 oal_pci_resource_start(pst_pci_dev, OAL_PCI_BAR_0),
                 oal_pci_resource_end(pst_pci_dev, OAL_PCI_BAR_0));
    oal_pci_write_config_dword(pst_pci_dev, 0x700 + 0x200, 0x80000000); /* view index */
    oal_pci_write_config_dword(pst_pci_dev, 0x700 + 0x204, 0x0);        /* ctrl 1 */
    oal_pci_write_config_dword(pst_pci_dev, 0x700 + 0x208, 0x80000000); /* ctrl 2 */
    oal_pci_write_config_dword(pst_pci_dev, 0x700 + 0x20c,
                               oal_pci_resource_start(pst_pci_dev, OAL_PCI_BAR_0)); /* base lower */
    oal_pci_write_config_dword(pst_pci_dev, 0x700 + 0x210, 0); /* base upper */
    oal_pci_write_config_dword(pst_pci_dev, 0x700 + 0x214,
                               oal_pci_resource_start(pst_pci_dev, OAL_PCI_BAR_0) + 0x15FFF); /* limit */
    oal_pci_write_config_dword(pst_pci_dev, 0x700 + 0x218, 0x20000000); /* target lower */
    oal_pci_write_config_dword(pst_pci_dev, 0x700 + 0x21c, 0);

    /* iATU1:BAR0:PCIE Internal: 16KB,��0x3C000��ʼ��ӳ��Ϊ0��ַ */
    oal_pci_write_config_dword(pst_pci_dev, 0x700 + 0x200, 0x80000001); /* view index */
    oal_pci_write_config_dword(pst_pci_dev, 0x700 + 0x204, 0x0);        /* ctrl 1 */
    oal_pci_write_config_dword(pst_pci_dev, 0x700 + 0x208, 0x80000000); /* ctrl 2 */
    oal_pci_write_config_dword(pst_pci_dev, 0x700 + 0x20c,
                               oal_pci_resource_start(pst_pci_dev, OAL_PCI_BAR_0) + 0x16000); /* base lower */
    oal_pci_write_config_dword(pst_pci_dev, 0x700 + 0x210, 0);  /* base upper */
    oal_pci_write_config_dword(pst_pci_dev, 0x700 + 0x214,
                               oal_pci_resource_start(pst_pci_dev, OAL_PCI_BAR_0) + 0x16FFF); /* limit */
    oal_pci_write_config_dword(pst_pci_dev, 0x700 + 0x218, 0x40000000); /* target lower */
    oal_pci_write_config_dword(pst_pci_dev, 0x700 + 0x21c, 0);

    /* iATU2:BAR0:PCIE Internal: 16KB,��0x3C000��ʼ��ӳ��Ϊ0��ַ */
    oal_pci_write_config_dword(pst_pci_dev, 0x700 + 0x200, 0x80000002); /* view index */
    oal_pci_write_config_dword(pst_pci_dev, 0x700 + 0x204, 0x0);        /* ctrl 1 */
    oal_pci_write_config_dword(pst_pci_dev, 0x700 + 0x208, 0x80000000); /* ctrl 2 */
    oal_pci_write_config_dword(pst_pci_dev, 0x700 + 0x20c,
                               oal_pci_resource_start(pst_pci_dev, OAL_PCI_BAR_0) + 0x17000); /* base lower */
    oal_pci_write_config_dword(pst_pci_dev, 0x700 + 0x210, 0); /* base upper */
    oal_pci_write_config_dword(pst_pci_dev, 0x700 + 0x214,
                               oal_pci_resource_end(pst_pci_dev, OAL_PCI_BAR_0)); /* limit */
    oal_pci_write_config_dword(pst_pci_dev, 0x700 + 0x218, 0x20017000); /* target lower */
    oal_pci_write_config_dword(pst_pci_dev, 0x700 + 0x21c, 0);

    /* ��������Ĵ��� */
    /* BIT0 = 1(I/O Space Enable), BIT1 = 1(Memory Space Enable), BIT2 = 1(Bus Master Enable) */
    oal_pci_write_config_word(pst_pci_dev, 0x04, 0x7);
}

oal_void oal_pcie_set_outbound_iatu(oal_pci_dev_stru *pst_pci_dev)
{
    /* iATU1:512M */
    oal_pci_write_config_dword(pst_pci_dev, 0x700 + 0x200, 0x1);                  /* view index */
    oal_pci_write_config_dword(pst_pci_dev, 0x700 + 0x204, 0x0);                  /* ctrl 1 */
    oal_pci_write_config_dword(pst_pci_dev, 0x700 + 0x208, 0x80000000);           /* ctrl 2 */
    oal_pci_write_config_dword(pst_pci_dev, 0x700 + 0x20c, 0x40000000);           /* base lower */
    oal_pci_write_config_dword(pst_pci_dev, 0x700 + 0x210, 0);                    /* base upper */
    oal_pci_write_config_dword(pst_pci_dev, 0x700 + 0x214, 0x5FFFFFFF);           /* limit */
    oal_pci_write_config_dword(pst_pci_dev, 0x700 + 0x218, OAL_PCIE_TARGET_ADDR); /* target lower */
    oal_pci_write_config_dword(pst_pci_dev, 0x700 + 0x21c, 0);                    /* target upper */

    /* ��������Ĵ��� */
    /* BIT0 = 1(I/O Space Enable), BIT1 = 1(Memory Space Enable), BIT2 = 1(Bus Master Enable) */
    oal_pci_write_config_word(pst_pci_dev, 0x04, 0x7);
}
#else
/*
 * �� �� ��  : oal_pcie_set_inbound_iatu
 * ��������  : ����EP��iATU��,����2��ӳ�����
 *             256KB��BAR0�ռ�:
 *             iATU0: 240K,Ϊsoc+phy+mac�ļĴ�����ַ
 *             iATU1: pcie internal�Ĵ�����ַ
 */
oal_void oal_pcie_set_inbound_iatu(oal_pci_dev_stru *pst_pci_dev)
{
    /* iATU0:BAR0:SoC MAC PHY: 240KB */
    OAL_IO_PRINT("pci_resource_start[0x%lx],pci_resource_en[0x%lx]\n",
                 oal_pci_resource_start(pst_pci_dev, OAL_PCI_BAR_0),
                 oal_pci_resource_end(pst_pci_dev, OAL_PCI_BAR_0));
    oal_pci_write_config_dword(pst_pci_dev, 0x700 + 0x200, 0x80000000); /* view index */
    oal_pci_write_config_dword(pst_pci_dev, 0x700 + 0x204, 0x0);        /* ctrl 1 */
    oal_pci_write_config_dword(pst_pci_dev, 0x700 + 0x208, 0x80000000); /* ctrl 2 */
    oal_pci_write_config_dword(pst_pci_dev, 0x700 + 0x20c,
                               oal_pci_resource_start(pst_pci_dev, OAL_PCI_BAR_0)); /* base lower */
    oal_pci_write_config_dword(pst_pci_dev, 0x700 + 0x210, 0); /* base upper */
    oal_pci_write_config_dword(pst_pci_dev, 0x700 + 0x214,
        oal_pci_resource_start(pst_pci_dev, OAL_PCI_BAR_0) + OAL_HI1151_SOC_ADDR_LIMIT - 1); /* limit */
    oal_pci_write_config_dword(pst_pci_dev, 0x700 + 0x218, 0x20000000); /* target lower */
    oal_pci_write_config_dword(pst_pci_dev, 0x700 + 0x21c, 0);

    /* iATU1:BAR0:PCIE Internal: 16KB,��0x3C000��ʼ��ӳ��Ϊ0��ַ */
    oal_pci_write_config_dword(pst_pci_dev, 0x700 + 0x200, 0x80000001); /* view index */
    oal_pci_write_config_dword(pst_pci_dev, 0x700 + 0x204, 0x0);        /* ctrl 1 */
    oal_pci_write_config_dword(pst_pci_dev, 0x700 + 0x208, 0x80000000); /* ctrl 2 */
    oal_pci_write_config_dword(pst_pci_dev, 0x700 + 0x20c,
        oal_pci_resource_start(pst_pci_dev, OAL_PCI_BAR_0) + OAL_HI1151_SOC_ADDR_LIMIT); /* base lower */
    oal_pci_write_config_dword(pst_pci_dev, 0x700 + 0x210, 0); /* base upper */
    oal_pci_write_config_dword(pst_pci_dev, 0x700 + 0x214,
                               oal_pci_resource_end(pst_pci_dev, OAL_PCI_BAR_0)); /* limit */
    oal_pci_write_config_dword(pst_pci_dev, 0x700 + 0x218, 0x0); /* target lower */
    oal_pci_write_config_dword(pst_pci_dev, 0x700 + 0x21c, 0);

    /* ��������Ĵ��� */
    /* BIT0 = 1(I/O Space Enable), BIT1 = 1(Memory Space Enable), BIT2 = 1(Bus Master Enable) */
    oal_pci_write_config_word(pst_pci_dev, 0x04, 0x7);
}

oal_void oal_pcie_set_outbound_iatu(oal_pci_dev_stru *pst_pci_dev)
{
    /* iATU1:512M */
    oal_pci_write_config_dword(pst_pci_dev, 0x700 + 0x200, 0x1);                  /* view index */
    oal_pci_write_config_dword(pst_pci_dev, 0x700 + 0x204, 0x0);                  /* ctrl 1 */
    oal_pci_write_config_dword(pst_pci_dev, 0x700 + 0x208, 0x80000000);           /* ctrl 2 */
    oal_pci_write_config_dword(pst_pci_dev, 0x700 + 0x20c, 0x0);                  /* base lower */
    oal_pci_write_config_dword(pst_pci_dev, 0x700 + 0x210, 0);                    /* base upper */
    oal_pci_write_config_dword(pst_pci_dev, 0x700 + 0x214, 0x1FFFFFFF);           /* limit */
    oal_pci_write_config_dword(pst_pci_dev, 0x700 + 0x218, OAL_PCIE_TARGET_ADDR); /* target lower */
    oal_pci_write_config_dword(pst_pci_dev, 0x700 + 0x21c, 0);                    /* target upper */

    /* ��������Ĵ���                                                                         */
    /* BIT0 = 1(I/O Space Enable), BIT1 = 1(Memory Space Enable), BIT2 = 1(Bus Master Enable) */
    oal_pci_write_config_word(pst_pci_dev, 0x04, 0x7);
}
#endif

/*
 * �� �� ��  : oal_pcie_set_inbound_iatu_slip_window
 * ��������  : ���û������EP��iATU��
 */
oal_void oal_pcie_set_inbound_iatu_slip_window(oal_pci_dev_stru *pst_pci_dev)
{
    /* iATU0:BAR0:SoC MAC PHY: 256KB */
    oal_pci_write_config_dword(pst_pci_dev, 0x700 + 0x200, 0x80000000); /* view index */
    oal_pci_write_config_dword(pst_pci_dev, 0x700 + 0x204, 0x0);        /* ctrl 1 */
    oal_pci_write_config_dword(pst_pci_dev, 0x700 + 0x208, 0x80000000); /* ctrl 2 */
    oal_pci_write_config_dword(pst_pci_dev, 0x700 + 0x20c,
                               oal_pci_resource_start(pst_pci_dev, OAL_PCI_BAR_0)); /* base lower */
    oal_pci_write_config_dword(pst_pci_dev, 0x700 + 0x210, 0); /* base upper */
    oal_pci_write_config_dword(pst_pci_dev, 0x700 + 0x214,
                               oal_pci_resource_end(pst_pci_dev, OAL_PCI_BAR_0)); /* limit */
    oal_pci_write_config_dword(pst_pci_dev, 0x700 + 0x218, 0x20040000); /* target lower */
    oal_pci_write_config_dword(pst_pci_dev, 0x700 + 0x21c, 0);

    /* ��������Ĵ���                                                                         */
    /* BIT0 = 1(I/O Space Enable), BIT1 = 1(Memory Space Enable), BIT2 = 1(Bus Master Enable) */
    oal_pci_write_config_word(pst_pci_dev, 0x04, 0x7);
}

#ifdef _PRE_DEBUG_MODE
/*
 * �� �� ��  : oal_pci_debug_info
 * ��������  : ��ӡPCIe������Ϣ
 */
OAL_STATIC oal_void oal_pci_debug_info(oal_pci_dev_stru *pst_pci_dev)
{
    oal_pci_bar_idx_enum_uint8 en_index;
    oal_uint32 aul_bar[OAL_PCI_BAR_BUTT];
    oal_uint32 aul_len[OAL_PCI_BAR_BUTT];

    for (en_index = 0; en_index < OAL_PCI_BAR_BUTT; en_index++) {
        aul_bar[en_index] = oal_pci_resource_start(pst_pci_dev, en_index);
        aul_len[en_index] = oal_pci_resource_len(pst_pci_dev, en_index);

        OAL_IO_PRINT("bar%d: 0x%x, len = 0x%x\n", en_index, aul_bar[en_index], aul_len[en_index]);
    }
}
#endif

/*
 * �� �� ��  : oal_pci_witp_init
 * ��������  : WITP 1151 PCI̽���ʼ������
 * �������  : pst_pci_dev: ָ��PCI�豸
 *             ul_dev_id     : PCI�豸��
 * �� �� ֵ  : Linux������
 */
OAL_STATIC oal_int32 oal_pci_witp_init(oal_pci_dev_stru *pst_pci_dev, oal_uint32 ul_dev_id)
{
    oal_uint8 uc_index;
    oal_uint8 uc_subidx;
    oal_pci_bar_idx_enum_uint8 en_bar_idx;
    oal_uint32 aul_bar[OAL_WITP_MAX_BARS];
    oal_uint32 aul_len[OAL_WITP_MAX_BARS];
    oal_uint32 aul_mem[OAL_WITP_MAX_BARS];
    oal_uint8 uc_chip_idx; /* ��ǰ��̽�⵽��оƬ��� */
    oal_bus_chip_stru *pst_bus_chip = OAL_PTR_NULL;
    oal_bus_dev_stru *pst_bus_dev;
    oal_uint32 ul_ret;

    /* ��ȡ��ǰ������chip������ */
    uc_chip_idx = oal_bus_get_chip_num();

    oal_bus_get_chip_instance(&pst_bus_chip, uc_chip_idx);
    if (OAL_UNLIKELY(pst_bus_chip == OAL_PTR_NULL)) {
        OAL_IO_PRINT("oal_pci_witp_init: OAL_PTR_NULL == pst_bus_chip!\n");
        return -OAL_EIO;
    }

    if (uc_chip_idx == 0) {
        pst_bus_chip->p_pci_dbi_base = oal_ioremap_nocache(OAL_DBI_BASE_ADDR_0, 0x1000);
    } else if (uc_chip_idx == 1) {
        pst_bus_chip->p_pci_dbi_base = oal_ioremap_nocache(OAL_DBI_BASE_ADDR_1, 0x1000);
    }
    if (OAL_UNLIKELY(pst_bus_chip->p_pci_dbi_base == OAL_PTR_NULL)) {
        OAL_IO_PRINT("oal_pci_witp_init::Cannot map dbi base for pcie%d!\n", uc_chip_idx);

        return -OAL_EIO;
    }

    pst_bus_chip->uc_chip_id = uc_chip_idx;
    pst_bus_chip->pst_pci_device = pst_pci_dev;

    /* 1151оƬ��DBSC������device����һ��Ϊ1 */
    pst_bus_chip->uc_device_num = 1;

    /* ��ȡBUS DEV�ṹ�� */
    pst_bus_dev = &pst_bus_chip->st_bus_dev[0];

    for (uc_index = 0; uc_index < OAL_WITP_MAX_BARS; uc_index++) {
        en_bar_idx = en_bar_table[uc_index];
        aul_bar[uc_index] = oal_pci_resource_start(pst_pci_dev, en_bar_idx);
        aul_len[uc_index] = oal_pci_resource_len(pst_pci_dev, en_bar_idx);

        OAL_IO_PRINT("BAR %d: set to [mem 0x%x, len = 0x%x]\n",
                     en_bar_idx, aul_bar[uc_index], aul_len[uc_index]);

        /* ����IO�ڴ���Դ���˴�witp�ַ�����IO�ڴ���Դ������ */
        if (!oal_request_mem_region(aul_bar[uc_index], aul_len[uc_index], "witp")) {
            OAL_IO_PRINT("BAR %d, pci: cannot reserve PCI memory region\n", en_bar_idx);

            for (uc_subidx = 0; uc_subidx < uc_index; uc_subidx++) {
                oal_release_mem_region(aul_bar[uc_subidx], aul_len[uc_subidx]);
            }

            oal_pci_disable_device(pst_pci_dev);

            return -OAL_ENODEV;
        }

        aul_mem[uc_index] = (oal_uint)oal_ioremap(aul_bar[uc_index], aul_len[uc_index]);

        OAL_IO_PRINT("BAR %d: ioremap addr = 0x%x\n", en_bar_idx, aul_mem[uc_index]);

        /*lint -e774*/ /* WIN32��װ��ul_mem�ǳ�����if�ж�����false */
        if (!aul_mem[uc_index]) {
            OAL_IO_PRINT("BAR %d, pci: cannot remap PCI memory region\n", en_bar_idx);

            for (uc_subidx = 0; uc_subidx < uc_index; uc_subidx++) {
                oal_iounmap ((OAL_VOLATILE oal_void *)(aul_mem[uc_subidx]));
            }

            for (uc_subidx = 0; uc_subidx <= uc_index; uc_subidx++) {
                oal_release_mem_region(aul_bar[uc_subidx], aul_len[uc_subidx]);
            }

            oal_pci_disable_device(pst_pci_dev);

            return -OAL_ENODEV;
        }
        /* lint +e774 */
    }

    /* �������ַ��1151оƬ�Ļ���ַ����device�Ļ���ַ */
    if (memcpy_s(pst_bus_dev->aul_mem_start, sizeof(pst_bus_dev->aul_mem_start),
                 aul_mem, OAL_WITP_MAX_BARS * OAL_SIZEOF(oal_uint32)) != EOK) {
        OAL_IO_PRINT("memcpy_s error, destlen=%u, srclen=%u\n ",
                     sizeof(pst_bus_dev->aul_mem_start, OAL_WITP_MAX_BARS * OAL_SIZEOF(oal_uint32)));
        oal_pci_disable_device(pst_pci_dev);
        return -OAL_EFAIL;
    }

    if (memcpy_s(pst_bus_chip->aul_mem_start, sizeof(pst_bus_chip->aul_mem_start),
                 aul_mem, OAL_WITP_MAX_BARS * OAL_SIZEOF(oal_uint32)) != EOK) {
        OAL_IO_PRINT("memcpy_s error, destlen=%u, srclen=%u\n ",
                     sizeof(pst_bus_chip->aul_mem_start), OAL_WITP_MAX_BARS * OAL_SIZEOF(oal_uint32));
        oal_pci_disable_device(pst_pci_dev);
        return -OAL_EFAIL;
    }

    /* �����ϵ�chip��������1 */
    ul_ret = oal_bus_inc_chip_num();
    if (ul_ret != OAL_SUCC) {
        OAL_IO_PRINT("oal_pci_probe: oal_bus_inc_chip_num failed!\n");
        return -OAL_EIO;
    }

    /* ����������Ϣ */
    pst_bus_dev->uc_chip_id = pst_bus_chip->uc_chip_id;
    pst_bus_dev->p_dev = pst_pci_dev;
    pst_bus_dev->ul_irq_num = pst_pci_dev->irq;
    pst_bus_dev->ul_device_id = ul_dev_id;
    pst_bus_dev->uc_bar_num = OAL_WITP_MAX_BARS;

    /* ����inbound iATU�� */
    oal_pcie_set_inbound_iatu(pst_pci_dev);

    /* ����outbound iATU�� */
    oal_pcie_set_outbound_iatu(pst_pci_dev);

    OAL_IO_PRINT("WITP: pci_dev->irq      : %d.\n", pst_bus_dev->ul_irq_num);

    return OAL_SUCC;
}

/*
 * �� �� ��  : oal_pci_probe
 * ��������  : PCI̽�⺯��
 * �������  : pst_pci_dev: ָ��PCI�豸
 *             pst_id     : PCI�豸��
 * �� �� ֵ  : Linux������
 */
OAL_STATIC oal_int32 oal_pci_probe(oal_pci_dev_stru *pst_pci_dev, OAL_CONST oal_pci_device_id_stru *pst_id)
{
    oal_uint32 ul_dev_id;
    oal_int32 l_ret;

    OAL_IO_PRINT("pci probe begin!\n");

    if ((pst_pci_dev == OAL_PTR_NULL) || (pst_id == OAL_PTR_NULL)) {
        OAL_IO_PRINT("pci: pci_enable_device I/O error!\n");
        return -OAL_EIO;
    }

    if (oal_pci_enable_device(pst_pci_dev)) {
        OAL_IO_PRINT("pci: pci_enable_device I/O error!\n");

        return -OAL_EIO;
    }

#ifdef _PRE_DEBUG_MODE
    oal_pci_debug_info(pst_pci_dev);
#endif

    /* ��ȡchip�е�device id */
    ul_dev_id = OAL_PCI_GET_DEV_ID(pst_id);

    /* 1151 chip�ĳ�ʼ�� */
    if (ul_dev_id == OAL_PCI_WITP_DEVICE_ID) {
        l_ret = oal_pci_witp_init(pst_pci_dev, ul_dev_id);
        if (l_ret != OAL_SUCC) {
            OAL_IO_PRINT("oal_pci_probe: OAL_SUCC != l_ret!\n");
            return -OAL_EIO;
        }

#ifdef _PRE_WLAN_FEATURE_DFR
        oal_pci_save_state(pst_pci_dev);
#endif

    } else {
        /* �ݲ�֧������оƬ */
        OAL_IO_PRINT("oal_pci_probe: unknown device id (%d)!\n", ul_dev_id);
        return -OAL_EIO;
    }

    OAL_IO_PRINT("PCI driver: probe succ!\n");

    return OAL_SUCC;
}

/*
 * �� �� ��  : oal_pci_witp_remove
 * ��������  : WITP PCI̽�⺯��
 * �������  : pst_pci_dev: ָ��PCI�豸
 *             pst_id     : PCI�豸��
 * �� �� ֵ  : Linux������
 */
OAL_STATIC oal_void oal_pci_witp_remove(oal_pci_dev_stru *pst_pci_dev)
{
    oal_uint8 uc_index;
    oal_bus_chip_stru *pst_bus_chip;
    oal_bus_dev_stru *pst_bus_dev;

    oal_bus_find_dev_instance(&pst_bus_dev, (oal_void *)pst_pci_dev);
    if (pst_bus_dev == OAL_PTR_NULL) {
        OAL_IO_PRINT("oal_pci_witp_remove: remove driver failed: OAL_PTR_NULL == pst_bus_dev\n");
        return;
    }

    oal_bus_get_chip_instance(&pst_bus_chip, pst_bus_dev->uc_chip_id);
    if (OAL_UNLIKELY(pst_bus_chip == OAL_PTR_NULL)) {
        OAL_IO_PRINT("oal_pci_witp_remove: remove driver failed: OAL_PTR_NULL == pst_bus_chip\n");
        return;
    }

    oal_iounmap ((OAL_VOLATILE oal_void *)(pst_bus_chip->p_pci_dbi_base));

    for (uc_index = 0; uc_index < OAL_WITP_MAX_BARS; uc_index++) {
        oal_iounmap ((OAL_VOLATILE oal_void *)(pst_bus_dev->aul_mem_start[uc_index]));

        oal_release_mem_region(oal_pci_resource_start(pst_pci_dev, en_bar_table[uc_index]),
                               oal_pci_resource_len(pst_pci_dev, en_bar_table[uc_index]));
    }

    return;
}

/*
 * �� �� ��  : oal_pci_remove
 * ��������  : pci�豸�Ƴ�����
 * �������  : pst_pci_dev: pci�豸
 */
OAL_STATIC oal_void oal_pci_remove(oal_pci_dev_stru *pst_pci_dev)
{
    oal_uint32 ul_dev_id;

    ul_dev_id = OAL_PCI_GET_DEV_ID(pst_pci_dev);

    if (ul_dev_id == OAL_PCI_WITP_DEVICE_ID) {
        oal_pci_witp_remove(pst_pci_dev);
    } else {
        OAL_IO_PRINT("oal_pci_remove: unknown device id (%d)!\n", ul_dev_id);
    }

    oal_pci_disable_device(pst_pci_dev);

    OAL_IO_PRINT("PCI driver: remove driver.\n");
}

/*
 * �� �� ��  : oal_pci_init
 * ��������  : pci��ʼ��
 */
oal_uint32 oal_pci_init(oal_void)
{
#if (_PRE_OS_VERSION_WIN32 == _PRE_OS_VERSION) && (_PRE_TEST_MODE == _PRE_TEST_MODE_UT)
    oal_uint8 uc_chip_id;
#endif

    OAL_IO_PRINT("PCI driver: driver init start.\n");

    if (oal_pci_register_driver(&pci_drv) < 0) {
        OAL_IO_PRINT("PCI driver: No devices found, driver not installed.\n");

        return OAL_FAIL;
    }

    /* WINDOWS��UT���� */
#if (_PRE_OS_VERSION_WIN32 == _PRE_OS_VERSION) && (_PRE_TEST_MODE == _PRE_TEST_MODE_UT)
    for (uc_chip_id = 0; uc_chip_id < WLAN_CHIP_MAX_NUM_PER_BOARD; uc_chip_id++) {
        oal_bus_inc_chip_num();
    }
#endif

    return OAL_SUCC;
}

/*
 * �� �� ��  : oal_pci_exit
 * ��������  : pci�����˳�
 */
oal_void oal_pci_exit(oal_void)
{
    oal_pci_unregister_driver(&pci_drv);

    OAL_IO_PRINT("PCI driver: driver unloaded.\n");
}

/*
 * �� �� ��  : oal_5115_pci_init
 * ��������  : 5115 system control & PCIE0 ����ַӳ��
 * �� �� ֵ  : OAL_SUCC������������
 */
oal_uint32 oal_5115_pci_init(oal_void)
{
    pst_5115_sys_ctl = oal_ioremap_nocache(OAL_PCIE_SYS_BASE_PHYS, 0x1000);
    if (pst_5115_sys_ctl == OAL_PTR_NULL) {
        OAL_IO_PRINT("oal_5115_pci_init, Cannot map system controller register base!\n");

        return OAL_ERR_CODE_PTR_NULL;
    }
#ifdef _PRE_WLAN_FEATURE_PCIE_ADAPT_5116
    pst_5115_sys_ctl1 = oal_ioremap_nocache(OAL_PCIE_SYS_BASE_PHYS + OAL_PCIE_PORT_OFFSET, 0x1000);
    if (pst_5115_sys_ctl1 == OAL_PTR_NULL) {
        OAL_IO_PRINT("oal_5115_pci_init, Cannot map system controller register base for pcie1!\n");

        return OAL_ERR_CODE_PTR_NULL;
    }
#endif
    OAL_IO_PRINT("oal_5115_pci_init,OAL_PCIE_SYS_BASE_PHYS=0x%x,map pst_5115_sys_ctl = 0x%x\n",
                 OAL_PCIE_SYS_BASE_PHYS, (oal_uint32)pst_5115_sys_ctl);

#if (_PRE_TARGET_PRODUCT_TYPE_E5 != _PRE_CONFIG_TARGET_PRODUCT) && \
    (_PRE_TARGET_PRODUCT_TYPE_CPE != _PRE_CONFIG_TARGET_PRODUCT)
    pst_5115_cfg_base = oal_ioremap_nocache(OAL_PCIE_CRG_BASE, 0x300);
    if (pst_5115_cfg_base == OAL_PTR_NULL) {
        OAL_IO_PRINT("oal_5115_pci_init, cannot map cfg base register!\n");
        return OAL_ERR_CODE_PTR_NULL;
    }
#endif

    pst_5610_mode = oal_ioremap_nocache(0x14900000, 0x200);
    if (pst_5610_mode == OAL_PTR_NULL) {
        OAL_IO_PRINT("oal_5115_pci_init, Cannot map 5610_mode register base!\n");

        return OAL_ERR_CODE_PTR_NULL;
    }

    pst_5610_gpio = oal_ioremap_nocache(0x10107000, 0x100);
    if (pst_5610_gpio == OAL_PTR_NULL) {
        OAL_IO_PRINT("oal_5115_pci_init, Cannot map 5610_mode register base!\n");

        return OAL_ERR_CODE_PTR_NULL;
    }

#if (_PRE_TARGET_PRODUCT_TYPE_5610DMB == _PRE_CONFIG_TARGET_PRODUCT)
    pst_5610_gpio1 = oal_ioremap_nocache(0x10106000, 0x100);
    if (pst_5610_gpio1 == OAL_PTR_NULL) {
        OAL_IO_PRINT("oal_5115_pci_init, Cannot map pst_5610_gpio1 register base!\n");

        return OAL_ERR_CODE_PTR_NULL;
    }

    pst_5610_gpio2 = oal_ioremap_nocache(0x10108000, 0x100);
    if (pst_5610_gpio2 == OAL_PTR_NULL) {
        OAL_IO_PRINT("oal_5115_pci_init, Cannot map pst_5610_gpio2 register base!\n");

        return OAL_ERR_CODE_PTR_NULL;
    }
#endif

    return OAL_SUCC;
}

oal_void oal_5115_pci_exit(oal_void)
{
    if (pst_5115_sys_ctl != NULL) {
        oal_iounmap(pst_5115_sys_ctl);
    }

#ifdef _PRE_WLAN_FEATURE_PCIE_ADAPT_5116
    if (pst_5115_sys_ctl1) {
        oal_iounmap(pst_5115_sys_ctl1);
    }
#endif

    if (pst_5610_mode != NULL) {
        oal_iounmap(pst_5610_mode);
    }

    if (pst_5610_gpio != NULL) {
        oal_iounmap(pst_5610_gpio);
    }

#if (_PRE_TARGET_PRODUCT_TYPE_5610DMB == _PRE_CONFIG_TARGET_PRODUCT)
    if (pst_5610_gpio1 != NULL) {
        oal_iounmap(pst_5610_gpio1);
    }

    if (pst_5610_gpio2 != NULL) {
        oal_iounmap(pst_5610_gpio2);
    }
#endif
}

/*
 * �� �� ��  : oal_pcie_dbi_enable
 * ��������  : ʹ��RC���DBI��д����
 */
oal_void oal_pcie_dbi_enable(oal_uint32 id)
{
#if (_PRE_OS_VERSION_LINUX == _PRE_OS_VERSION)
    oal_uint32 ul_val;

#ifdef _PRE_WLAN_FEATURE_PCIE_ADAPT_5116
    if (id == 0) {
        ul_val = oal_readl(pst_5115_sys_ctl + OAL_PERI_R_PCIE0);
        ul_val |= BIT13;
        oal_writel(ul_val, pst_5115_sys_ctl + OAL_PERI_R_PCIE0);
    } else {
        ul_val = oal_readl(pst_5115_sys_ctl1 + OAL_PERI_R_PCIE1);
        ul_val |= BIT13;
        oal_writel(ul_val, pst_5115_sys_ctl1 + OAL_PERI_R_PCIE1);
    }
#else
    if (id == 0) {
        ul_val = oal_readl(pst_5115_sys_ctl + OAL_PERI_R_PCIE0);
        ul_val |= BIT21;
        oal_writel(ul_val, pst_5115_sys_ctl + OAL_PERI_R_PCIE0);

        ul_val = oal_readl(pst_5115_sys_ctl + OAL_PERI_W_PCIE0);
        ul_val |= BIT21;
        oal_writel(ul_val, pst_5115_sys_ctl + OAL_PERI_W_PCIE0);
    } else {
        ul_val = oal_readl(pst_5115_sys_ctl + OAL_PERI_R_PCIE1);
        ul_val |= BIT21;
        oal_writel(ul_val, pst_5115_sys_ctl + OAL_PERI_R_PCIE1);

        ul_val = oal_readl(pst_5115_sys_ctl + OAL_PERI_W_PCIE1);
        ul_val |= BIT21;
        oal_writel(ul_val, pst_5115_sys_ctl + OAL_PERI_W_PCIE1);
    }
#endif

#endif
}
/*
 * �� �� ��  : oal_pcie_dbi_disable
 * ��������  : ȥʹ��RC���DBI��д���ܣ��ָ�EP���DBI��д
 */
oal_void oal_pcie_dbi_disable(oal_uint32 id)
{
#if (_PRE_OS_VERSION_LINUX == _PRE_OS_VERSION)
    /* ���ù���ģʽ���ָ���дwifi�� */
    oal_uint32 ul_val;

#ifdef _PRE_WLAN_FEATURE_PCIE_ADAPT_5116
    if (id == 0) {
        ul_val = oal_readl(pst_5115_sys_ctl + OAL_PERI_R_PCIE0);
        ul_val &= (~BIT13);
        oal_writel(ul_val, pst_5115_sys_ctl + OAL_PERI_R_PCIE0);
    } else {
        ul_val = oal_readl(pst_5115_sys_ctl1 + OAL_PERI_R_PCIE1);
        ul_val &= (~BIT13);
        oal_writel(ul_val, pst_5115_sys_ctl1 + OAL_PERI_R_PCIE1);
    }
#else
    if (id == 0) {
        ul_val = oal_readl(pst_5115_sys_ctl + OAL_PERI_R_PCIE0);
        ul_val &= (~BIT21);
        oal_writel(ul_val, pst_5115_sys_ctl + OAL_PERI_R_PCIE0);

        ul_val = oal_readl(pst_5115_sys_ctl + OAL_PERI_W_PCIE0);
        ul_val &= (~BIT21);
        oal_writel(ul_val, pst_5115_sys_ctl + OAL_PERI_W_PCIE0);
    } else {
        ul_val = oal_readl(pst_5115_sys_ctl + OAL_PERI_R_PCIE1);
        ul_val &= (~BIT21);
        oal_writel(ul_val, pst_5115_sys_ctl + OAL_PERI_R_PCIE1);

        ul_val = oal_readl(pst_5115_sys_ctl + OAL_PERI_W_PCIE1);
        ul_val &= (~BIT21);
        oal_writel(ul_val, pst_5115_sys_ctl + OAL_PERI_W_PCIE1);
    }
#endif

#endif
}
/*
 * �� �� ��  : oal_pcie_internal_get
 * ��������  : 1151 PCIE�ڲ��Ĵ���MEM���ӿڣ����ýӿ�ǰ����ȷ���ѵ���hi1151_pcie_dbi_enable�ӿ�ʹ��1151��DBI�ӿڡ�
 */
oal_uint32 oal_pcie_internal_get(oal_uint32 ul_inter_addr, oal_uint32 bit_offset, oal_uint32 bit_width)
{
    oal_uint32 ul_value = 0;

#if (_PRE_OS_VERSION_LINUX == _PRE_OS_VERSION)
    oal_void *pst_virt_addr;
    oal_bus_chip_stru *pst_bus_chip = OAL_PTR_NULL;

    oal_bus_get_chip_instance(&pst_bus_chip, 0);
    if (OAL_UNLIKELY(pst_bus_chip == OAL_PTR_NULL)) {
        OAL_IO_PRINT("oal_pcie_internal_get: OAL_PTR_NULL == pst_bus_chip!\n");
        return ul_value;
    }

    pst_virt_addr = (oal_void *)(pst_bus_chip->aul_mem_start[0] + OAL_HI1151_SOC_ADDR_LIMIT + ul_inter_addr);

    ul_value = oal_readl(pst_virt_addr);
    ul_value >>= bit_offset;
    ul_value &= OAL_MASK(bit_width, 0);
#endif

    return ul_value;
}
/*
 * �� �� ��  : oal_pcie_internal_set
 * ��������  : 1151 PCIE�ڲ��Ĵ���MEMд�ӿڣ����ýӿ�ǰ����ȷ���ѵ���hi1151_pcie_dbi_enable�ӿ�ʹ��1151��DBI�ӿڡ�
 */
oal_void oal_pcie_internal_set(oal_uint32 ul_inter_addr, oal_uint32 bit_offset,
                               oal_uint32 bit_width, oal_uint32 bit_value)
{
#if (_PRE_OS_VERSION_LINUX == _PRE_OS_VERSION)
    oal_uint32 ul_value;
    oal_void *pst_virt_addr;
    oal_bus_chip_stru *pst_bus_chip = OAL_PTR_NULL;

    oal_bus_get_chip_instance(&pst_bus_chip, 0);
    if (OAL_UNLIKELY(pst_bus_chip == OAL_PTR_NULL)) {
        OAL_IO_PRINT("oal_pcie_internal_get: OAL_PTR_NULL == pst_bus_chip!\n");
        return;
    }

    pst_virt_addr = (oal_void *)(pst_bus_chip->aul_mem_start[0] + OAL_HI1151_SOC_ADDR_LIMIT + ul_inter_addr);

    ul_value = oal_readl(pst_virt_addr);
    ul_value &= OAL_MASK_INVERSE(bit_width, bit_offset);
    ul_value |= (bit_value << bit_offset);
    oal_writel(ul_value, pst_virt_addr);
#endif
}
/*
 * �� �� ��  : oal_pci_linkup_check
 * ��������  : ���PCIE��link״̬
 */
oal_uint32 oal_pci_linkup_check(oal_pci_dev_stru *pst_pci_dev)
{
#if (_PRE_OS_VERSION_LINUX == _PRE_OS_VERSION)
    oal_uint32 ul_value;

    ul_value = oal_readl(pst_5115_sys_ctl + OAL_PCIE_LINK_STATUS_OFFSET);
    if ((ul_value & 0x20) && (ul_value & 0x8000)) {
        OAL_IO_PRINT("PCIE0 Device Link Up val = 0x%08x.\n", ul_value);
        return OAL_TRUE;
    } else {
        OAL_IO_PRINT("PCIE0 Device Link Down val = 0x%08x.\n", ul_value);
        return OAL_FALSE;
    }
#endif

    return OAL_FALSE;  //lint !e527
}

/*
 * �� �� ��  : oal_pcie_show_link_status
 * ��������  : �����ǰPCIE��ģʽ�����ʣ�����
 */
oal_void oal_pcie_show_link_status(oal_uint32 id)
{
#if (_PRE_OS_VERSION_LINUX == _PRE_OS_VERSION)
    oal_uint32 value = 0;
    oal_uint32 link_speed = 0;
    oal_uint32 link_width = 0;
    char *pcie_info_gen_str[] = { "Gen1.1", "Gen2", "Gen3" };
    char *pcie_info_phy_rate_str[] = { "2.5-Gbps", "5-Gbps", "8-Gbps" };
    oal_bus_chip_stru *pst_bus_chip = OAL_PTR_NULL;
    oal_uint ul_flag = 0;

    /* ��ȡ��ǰ������chip������ */
    if (id == 0) {
        oal_bus_get_chip_instance(&pst_bus_chip, 0);
        if (OAL_UNLIKELY(pst_bus_chip == OAL_PTR_NULL)) {
            OAL_IO_PRINT("oal_pcie_show_link_status: OAL_PTR_NULL == pst_bus_chip!\n");
            return;
        }

        oal_irq_save(&ul_flag, OAL_5115IRQ_WH5RR);
        oal_pcie_dbi_enable(id);
        value = oal_readl(pst_bus_chip->p_pci_dbi_base + 0x80);
        oal_pcie_dbi_disable(id);
        oal_irq_restore(&ul_flag, OAL_5115IRQ_WH5RR);

        link_width = ((value >> 20) & 0x3F);
        link_speed = ((value >> 16) & 0x0F) / 2;

        OAL_IO_PRINT("[PCIe]: PCIe %u Info: %s %s, Lane: x%u\n", id,
                     pcie_info_phy_rate_str[link_speed],
                     pcie_info_gen_str[link_speed],
                     link_width);
    }
#endif
}

/*
 * �� �� ��  : oal_pcie_set_gen
 * ��������  : PCIE����genģʽ:1.0/2.0/3.0
 * �������  : pst_pci_dev: pci�豸
 */
oal_void oal_pcie_set_gen(oal_uint32 id, oal_pci_gen_enum_uint8 uc_gen)
{
#if (_PRE_OS_VERSION_LINUX == _PRE_OS_VERSION)
    oal_bus_chip_stru *pst_bus_chip = OAL_PTR_NULL;
    oal_uint32 ul_val;
    oal_uint ul_flag;

    if (id == 0) {
        /* ��ȡ��ǰ������chip������ */
        oal_bus_get_chip_instance(&pst_bus_chip, 0);
        if (OAL_UNLIKELY(pst_bus_chip == OAL_PTR_NULL)) {
            OAL_IO_PRINT("oal_pcie_show_link_status: OAL_PTR_NULL == pst_bus_chip!\n");
            return;
        }
        oal_irq_save(&ul_flag, OAL_5115IRQ_WH5RR);

        oal_pcie_dbi_enable(id);
        if (uc_gen == OAL_PCI_GEN_1_0) {
            ul_val = oal_readl(pst_bus_chip->p_pci_dbi_base + 0xa0);
            OAL_WRITE_BITS(ul_val, 0x1, 4, 0);
            oal_writel(ul_val, pst_bus_chip->p_pci_dbi_base + 0xa0);
        } else if (uc_gen == OAL_PCI_GEN_2_0) {
            ul_val = oal_readl(pst_bus_chip->p_pci_dbi_base + 0xa0);
            OAL_WRITE_BITS(ul_val, 0x2, 4, 0);
            oal_writel(ul_val, pst_bus_chip->p_pci_dbi_base + 0xa0);
        }

        /* Retrain Link */
        ul_val = oal_readl(pst_bus_chip->p_pci_dbi_base + 0x80);
        ul_val |= BIT5;
        oal_writel(ul_val, pst_bus_chip->p_pci_dbi_base + 0x80);

        oal_pcie_dbi_disable(id);

        oal_irq_restore(&ul_flag, OAL_5115IRQ_WH5RR);

        oal_udelay(100);

        oal_pcie_show_link_status(id);
    }
#endif
}

/*
 * �� �� ��  : oal_pci_ep_reconfig
 * ��������  : pci�豸���½�����EP��(1151)�ָ����üĴ�����IATU��
 * �������  : pst_pci_dev: pci�豸
 */
oal_uint32 oal_pci_ep_reconfig(oal_pci_dev_stru *pst_pci_dev)
{
#if (_PRE_OS_VERSION_LINUX == _PRE_OS_VERSION)
    oal_uint32 ul_loop_count = 0;
    const oal_uint32 ul_loop_times = 1000;

    OAL_IO_PRINT("reconfig IATU tbl!...\n");
    while (ul_loop_count < ul_loop_times) {
        ul_loop_count++;

        if (oal_pci_linkup_check(pst_pci_dev) == OAL_TRUE) {
            oal_pci_restore_state(pst_pci_dev);

            oal_pcie_set_inbound_iatu(pst_pci_dev);
            oal_pcie_set_outbound_iatu(pst_pci_dev);

            return OAL_SUCC;
        } else {
            oal_udelay(100);
        }
    }
#endif
    return OAL_FAIL;
}

/*
 * �� �� ��  : oal_pci_rc_reconfig
 * ��������  : pci�豸���½�����ָ�RC��(5115)���üĴ�����IATU��
 * �������  : pst_pci_dev: pci�豸
 */
oal_uint32 oal_pci_rc_reconfig(oal_uint8 uc_chip_id)
{
#if (_PRE_OS_VERSION_LINUX == _PRE_OS_VERSION)

#if (_PRE_TARGET_PRODUCT_TYPE_E5 == _PRE_CONFIG_TARGET_PRODUCT)
    /* to be done: 722 ƽ̨���� */
    balong_pcie_pm_sys_resume();
#elif (_PRE_TARGET_PRODUCT_TYPE_CPE == _PRE_CONFIG_TARGET_PRODUCT)
    /* CPE�ݲ���Ҫ */
#elif ((_PRE_TARGET_PRODUCT_TYPE_5610EVB == _PRE_CONFIG_TARGET_PRODUCT) ||  \
       (_PRE_TARGET_PRODUCT_TYPE_VSPM310DMB == _PRE_CONFIG_TARGET_PRODUCT))
    oal_uint8 uc_pcie_slot = uc_chip_id + 1; /* pcie��λ�Ŵ�1��ʼ,chip id��0��ʼ */
    pcie_sys_reinit(uc_pcie_slot);
#elif (_PRE_TARGET_PRODUCT_TYPE_WS835DMB == _PRE_CONFIG_TARGET_PRODUCT)
    /* WS835�͹�����Ҫ��pcie��λ�������Ƿ������Ҫ�������� */
#elif (_PRE_TARGET_PRODUCT_TYPE_ONT == _PRE_CONFIG_TARGET_PRODUCT)
    /* ONT�͹�����Ҫ��pcie��λ�������Ƿ������Ҫ�������� */
#elif (_PRE_TARGET_PRODUCT_TYPE_5630HERA == _PRE_CONFIG_TARGET_PRODUCT)
    /* HERA�͹�����Ҫ��pcie��λ�������Ƿ������Ҫ�������� */
#else
    hi_pcie_reinit(uc_chip_id); /* 5610sdk���´����pcie�ǰ���chip��ʼ����Ϊ0,1,2��2��ʾ��Ч */
#endif

#endif
    return OAL_TRUE;
}

#ifdef _PRE_WLAN_FEATURE_DFR

#define PCIE_NONFATAL_ERR_STATUS 0x0104

/*
 * �� �� ��  : oal_pci_check_clear_error_nonfatal
 * ��������  : ��⵱ǰpcie�Ƿ��м�⵽pcie error_nonfatal����,�����⵽������üĴ�����������1�����򷵻�0;
 */
oal_uint32 oal_pci_check_clear_error_nonfatal(oal_uint8 uc_chip_id)
{
#if (_PRE_OS_VERSION_LINUX == _PRE_OS_VERSION) && (_PRE_TARGET_PRODUCT_TYPE_E5 == _PRE_CONFIG_TARGET_PRODUCT)
    oal_bus_chip_stru *pst_bus_chip = OAL_PTR_NULL;
    oal_uint32 ul_val = 0;
    oal_uint ul_flag = 0;
    oal_uint32 ul_nonfatal = 0;

    oal_bus_get_chip_instance(&pst_bus_chip, uc_chip_id);
    if (OAL_UNLIKELY(pst_bus_chip == OAL_PTR_NULL)) {
        return 0;
    }

    oal_irq_save(&ul_flag, OAL_5115IRQ_OPCCEN);

    if (uc_chip_id == 0) {
        /* ���ù���ģʽ����CPU�� */
        ul_val = oal_readl(pst_5115_sys_ctl + OAL_PERI_R_PCIE0);
        ul_val |= BIT21;
        oal_writel(ul_val, pst_5115_sys_ctl + OAL_PERI_R_PCIE0);

        /* ���ù���ģʽ��дCPU�� */
        ul_val = oal_readl(pst_5115_sys_ctl + OAL_PERI_W_PCIE0);
        ul_val |= BIT21;
        oal_writel(ul_val, pst_5115_sys_ctl + OAL_PERI_W_PCIE0);
    } else {
        /* ���ù���ģʽ����CPU�� */
        ul_val = oal_readl(pst_5115_sys_ctl + OAL_PERI_R_PCIE1);
        ul_val |= BIT21;
        oal_writel(ul_val, pst_5115_sys_ctl + OAL_PERI_R_PCIE1);

        /* ���ù���ģʽ��дCPU�� */
        ul_val = oal_readl(pst_5115_sys_ctl + OAL_PERI_W_PCIE1);
        ul_val |= BIT21;
        oal_writel(ul_val, pst_5115_sys_ctl + OAL_PERI_W_PCIE1);
    }

    /* ul_val �����ʾ����PCIE nonfatal���� */
    ul_val = oal_readl(pst_bus_chip->p_pci_dbi_base + PCIE_NONFATAL_ERR_STATUS);
    if (ul_val) {
        /* ��ȡ�Ĵ���ֵ���ɲ鿴�������� */
        OAL_IO_PRINT("before clear: chip_id = %d, dbi_base = %p, reg 0x0104 value = 0x%x",
                     uc_chip_id, pst_bus_chip->p_pci_dbi_base, ul_val);

        /* дȫF���� */
        oal_writel(0xFFFFFFFF, pst_bus_chip->p_pci_dbi_base + PCIE_NONFATAL_ERR_STATUS);

        /* �ض�ȷ���Ƿ����� */
        ul_val = oal_readl(pst_bus_chip->p_pci_dbi_base + PCIE_NONFATAL_ERR_STATUS);
        OAL_IO_PRINT("after clear: chip_id = %d, dbi_base = %p, reg 0x0104 value = 0x%x",
                     uc_chip_id, pst_bus_chip->p_pci_dbi_base, ul_val);

        ul_nonfatal = 1;
    }

    if (uc_chip_id == 0) {
        /* ���ù���ģʽ���ָ���wifi�� */
        ul_val = oal_readl(pst_5115_sys_ctl + OAL_PERI_R_PCIE0);
        ul_val &= (~BIT21);
        oal_writel(ul_val, pst_5115_sys_ctl + OAL_PERI_R_PCIE0);

        /* ���ù���ģʽ���ָ�дwifi�� */
        ul_val = oal_readl(pst_5115_sys_ctl + OAL_PERI_W_PCIE0);
        ul_val &= (~BIT21);
        oal_writel(ul_val, pst_5115_sys_ctl + OAL_PERI_W_PCIE0);
    } else {
        /* ���ù���ģʽ���ָ���wifi�� */
        ul_val = oal_readl(pst_5115_sys_ctl + OAL_PERI_R_PCIE1);
        ul_val &= (~BIT21);
        oal_writel(ul_val, pst_5115_sys_ctl + OAL_PERI_R_PCIE1);

        /* ���ù���ģʽ���ָ�дwifi�� */
        ul_val = oal_readl(pst_5115_sys_ctl + OAL_PERI_W_PCIE1);
        ul_val &= (~BIT21);
        oal_writel(ul_val, pst_5115_sys_ctl + OAL_PERI_W_PCIE1);
    }

    oal_irq_restore(&ul_flag, OAL_5115IRQ_OPCCEN);

    return ul_nonfatal;

#endif
    return 0;
}

#define PCIE_DEV_CLK_ENABLE_BIT(_chip_id) (_chip_id == 0 ? 0x40 : 0x80)
#define PCIE_CTRL_REG12(_chip_id)         (_chip_id == 0 ? 0x134 : 0x140)
#define PCIE_RESET_CTRL_BIT(_chip_id)     (_chip_id == 0 ? 0xFF7FFFFF : 0xFEFFFFFF)
#define PCIE_RESET_CLTR_BIT_NOT(_chip_id) (_chip_id == 0 ? 0x800000 : 0x1000000)

/*
 * �� �� ��  : oal_pci_hand_reset
 * ��������  : �ֶ�������λpci
 */
oal_uint32 oal_pci_hand_reset(oal_uint8 uc_chip_id)
{
#if (_PRE_OS_VERSION_LINUX == _PRE_OS_VERSION) && (_PRE_TARGET_PRODUCT_TYPE_E5 != _PRE_CONFIG_TARGET_PRODUCT) && \
    (_PRE_TARGET_PRODUCT_TYPE_CPE != _PRE_CONFIG_TARGET_PRODUCT)
    oal_uint32 ul_val;

    if (uc_chip_id > 1) {
        return OAL_FAIL;
    }

    /* ����ʱ��ʹ�ܼĴ�����bit6����pcie0ʱ�� */
    ul_val = oal_readl(pst_5115_cfg_base + 0x20);
    ul_val = ul_val | PCIE_DEV_CLK_ENABLE_BIT(uc_chip_id);
    oal_writel(ul_val, pst_5115_cfg_base + 0x20);

    /* pcie0���Ƽ���12����ʼֵΪ420c0802 */
    ul_val = 0x420539F3;
    oal_writel(ul_val, pst_5115_cfg_base + PCIE_CTRL_REG12(uc_chip_id));

    /* 0x30�⸴λ��������bit23���� PCIE0 ��λ(1������λ��0��������λ) */
    ul_val = oal_readl(pst_5115_cfg_base + 0x30);
    ul_val = ul_val & PCIE_RESET_CTRL_BIT(uc_chip_id);
    oal_writel(ul_val, pst_5115_cfg_base + 0x30);
    oal_udelay(1000);

    /* 0x30�⸴λ��������bit23���� PCIE0 ��λ(1������λ��0��������λ) */
    ul_val = oal_readl(pst_5115_cfg_base + 0x30);
    ul_val = ul_val | PCIE_RESET_CLTR_BIT_NOT(uc_chip_id);
    oal_writel(ul_val, pst_5115_cfg_base + 0x30);
    oal_udelay(1000);
#endif
    return OAL_SUCC;
}

/*
 * �� �� ��  : oal_machine_restart
 * ��������  : ����ϵͳ��λ
 */
oal_void oal_machine_restart(oal_void)
{
#if (_PRE_OS_VERSION_LINUX == _PRE_OS_VERSION)
    arm_pm_restart('h', OAL_PTR_NULL);
#endif
}

#endif

#if (_PRE_CONFIG_TARGET_PRODUCT == _PRE_TARGET_PRODUCT_TYPE_E5)
/*
 * �� �� ��  : oal_drv_pcie_pm_sys_resume
 * ��������  : syscore resume�Ļص�����,�ָ�ep��Ĵ���
 */
OAL_STATIC oal_void oal_drv_pcie_pm_sys_resume(oal_void)
{
    oal_uint8 uc_chip_idx;
    oal_bus_chip_stru *pst_bus_chip = OAL_PTR_NULL;
    oal_uint32 ul_ret;

    OAL_IO_PRINT("{oal_drv_pcie_pm_sys_resume:: enter!}\n");

    /* ����chip,��ȡ��Ӧ��pci device */
    for (uc_chip_idx = 0; uc_chip_idx < oal_bus_get_chip_num(); uc_chip_idx++) {
        oal_bus_get_chip_instance(&pst_bus_chip, uc_chip_idx);
        if (OAL_UNLIKELY(pst_bus_chip == OAL_PTR_NULL)) {
            OAL_IO_PRINT("oal_drv_pcie_pm_sys_resume:pst_bus_chip NULL! uc_chip_idx[%d]\n", uc_chip_idx);
            return;
        }

        if (pst_bus_chip->pst_pci_device == OAL_PTR_NULL) {
            OAL_IO_PRINT("oal_drv_pcie_pm_sys_resume:pst_pci_device NULL!\n");
            return;
        }

        ul_ret = oal_pci_ep_reconfig(pst_bus_chip->pst_pci_device);
        if (ul_ret == OAL_FAIL) {
            OAL_IO_PRINT("{oal_drv_pcie_pm_sys_resume::oal_pci_ep_reconfig fail!}\n");
            return;
        }
    }
}

/*
 * �� �� ��  : oal_register_syscore_ops
 * ��������  : ע��syscore�ص�����
 */
oal_void oal_register_syscore_ops(oal_void)
{
#if (_PRE_OS_VERSION_LINUX == _PRE_OS_VERSION)
    register_syscore_ops(&drv_pcie_pm_syscore_ops);
#endif
}

/*
 * �� �� ��  : oal_register_syscore_ops
 * ��������  : ȥע��syscore�ص�����
 */
oal_void oal_unregister_syscore_ops(oal_void)
{
#if (_PRE_OS_VERSION_LINUX == _PRE_OS_VERSION)
    unregister_syscore_ops(&drv_pcie_pm_syscore_ops);
#endif
}
#endif

/* ��pci_id_table�������û��ռ䣬ʹ�Ȳ�κ�ģ��װ��ϵͳ֪��ʲôģ�����ʲôӲ���豸 */
/*lint -e19*/
/*lint -e578*/ /*lint -e19*/
OAL_MODULE_DEVICE_TABLE(pci, pci_id_table);
oal_module_symbol(pst_5115_sys_ctl);
#ifdef _PRE_WLAN_FEATURE_PCIE_ADAPT_5116
oal_module_symbol(pst_5115_sys_ctl1);
#endif
oal_module_symbol(pst_5610_mode);
oal_module_symbol(pst_5610_gpio);
#if (_PRE_TARGET_PRODUCT_TYPE_5610DMB == _PRE_CONFIG_TARGET_PRODUCT)
oal_module_symbol(pst_5610_gpio1);
oal_module_symbol(pst_5610_gpio2);
#endif
#ifdef _PRE_WLAN_PRODUCT_1151V200
oal_module_symbol(oal_pcie_set_inbound_iatu_slip_window_fpga);
#endif
oal_module_symbol(oal_pcie_set_inbound_iatu_slip_window);
oal_module_symbol(oal_pcie_set_inbound_iatu);
oal_module_symbol(oal_pcie_set_outbound_iatu);
oal_module_symbol(oal_pci_ep_reconfig);
oal_module_symbol(oal_pci_rc_reconfig);

#ifdef _PRE_WLAN_FEATURE_DFR
oal_module_symbol(oal_pci_check_clear_error_nonfatal);
oal_module_symbol(oal_pci_hand_reset);
oal_module_symbol(oal_machine_restart);
#endif
oal_module_symbol(oal_pcie_show_link_status);
oal_module_symbol(oal_pcie_set_gen);
oal_module_symbol(oal_pcie_dbi_enable);
oal_module_symbol(oal_pcie_dbi_disable);
oal_module_symbol(oal_pcie_internal_get);
oal_module_symbol(oal_pcie_internal_set);
#endif