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

#define BOOT_TARGET_DEVICES(func) \
	func(MMC, mmc, 1) \
	func(USB, usb, 0) \
	func(PXE, pxe, na) \
	func(DHCP, dchp, na)


#ifndef CONFIG_SPL_BUILD
#undef CONFIG_BOOTCOMMAND
#define CONFIG_BOOTCOMMAND LINUX_BOOTCOMMAND
#endif


#define LINUX_BOOTCOMMAND \
	"env set bootargs console=ttyS2,115200 rw rootfstype=ext4 root=/dev/mmcblk1p6 earlyprintk;" \
	"boot_android ${devtype} ${devnum};" \
	"bootrkp;"
	

#define CONFIG_SYS_MMC_ENV_DEV 1

#endif
