/*
 * (C) Copyright 2016 Rockchip Electronics Co., Ltd
 *
 * SPDX-License-Identifier:     GPL-2.0+
//	"load mmc 0:5 ${kernel_addr_r} /boot/zImage; load mmc 0:5 ${fdt_addr_r} /boot/rk3288-ntablet-870a-5648.dtb; bootz ${kernel_addr_r} - ${fdt_addr_r};"
 */

#ifndef __CONFIG_H
#define __CONFIG_H

#define ROCKCHIP_DEVICE_SETTINGS \
		"stdin=serial,cros-ec-keyb\0" \
		"stdout=serial,vidconsole\0" \
		"stderr=serial,vidconsole\0"

#include <configs/rk3288_common.h>

#undef BOOT_TARGET_DEVICES
#undef BOOTENV
#define BOOT_TARGET_DEVICES(func)
#define BOOTENV

#ifndef CONFIG_SPL_BUILD
#undef CONFIG_BOOTCOMMAND
#undef CONFIG_EXTRA_ENV_SETTINGS
#define CONFIG_EXTRA_ENV_SETTINGS LINUX_BOOTMENU
#endif

#undef ENV_MEM_LAYOUT_SETTINGS
#define ENV_MEM_LAYOUT_SETTINGS \
	"scriptaddr=0x00000000\0" \
	"fdt_addr_r=0x08300000\0" \
	"kernel_addr_r=0x02008000\0"

#define LINUX_BOOTMENU \
	ENV_MEM_LAYOUT_SETTINGS \
	"importbootenv=env import -t -r ${scriptaddr} $filesize\0" \
	"loadbootenv=load ${devtype} ${devnum}:5 ${scriptaddr} /boot/uEnv.txt\0" \
	"preboot=run loadbootenv;run importbootenv\0" \
	BOOTENV	

#define CONFIG_SYS_MMC_ENV_DEV 0
#define CONFIG_MENU_SHOW

#endif
