/*
 * (C) Copyright 2019 YeaCreate Co., Ltd
 *
 * SPDX-License-Identifier:     GPL-2.0+
 */

#ifndef __CONFIG_H
#define __CONFIG_H

#include <configs/rk3288_common.h>

#define CONFIG_SYS_MMC_ENV_DEV 0

#define ROCKCHIP_DEVICE_SETTINGS \
		"stdout=serial,vidconsole\0" \
		"stderr=serial,vidconsole\0"

#endif

#undef BOOT_TARGET_DEVICES
#undef BOOTENV
#define BOOT_TARGET_DEVICES(func)
#define BOOTENV

#ifndef CONFIG_SPL_BUILD
#undef CONFIG_BOOTCOMMAND
#undef CONFIG_EXTRA_ENV_SETTINGS
#define CONFIG_EXTRA_ENV_SETTINGS \
	ENV_MEM_LAYOUT_SETTINGS \
	ROCKCHIP_DEVICE_SETTINGS \
	LINUX_BOOTMENU \
	BOOTENV
#endif


#undef ENV_MEM_LAYOUT_SETTINGS
#define ENV_MEM_LAYOUT_SETTINGS \
	"scriptaddr=0x00000000\0" \
	"fdt_addr_r=0x08300000\0" \
	"kernel_addr_r=0x02008000\0"

#define LINUX_BOOTMENU \
	"usbboot=rockusb 0 mmc 0\0" \
	"load_wifi_clk=pmic dev pmic@1c;pmic write 0x20 0x01\0" \
	"importbootenv=env import -t -r ${scriptaddr} $filesize\0" \
	"loadbootenv=load ${devtype} ${devnum}:6 ${scriptaddr} /boot/uEnv.txt\0" \
	"preboot=run load_wifi_clk;run loadbootenv;run importbootenv\0"

#define CONFIG_MENU_SHOW
