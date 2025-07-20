/*
 * SPDX-FileCopyrightText: 2010-2022 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: CC0-1.0
 */

#include <stdio.h>
#include <inttypes.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_chip_info.h"
#include "esp_flash.h"
#include "esp_system.h"
// void app_main(void)
// {
//     // 打印欢迎信息
//     printf("Hello world!\n");

//     /* 打印芯片信息 */
//     esp_chip_info_t chip_info;
//     uint32_t flash_size;
//     // 获取芯片信息
//     esp_chip_info(&chip_info);
//     // 打印芯片类型、CPU核心数及支持的功能
//     printf("This is %s chip with %d CPU core(s), %s%s%s%s, ",
//            CONFIG_IDF_TARGET,
//            chip_info.cores,
//            (chip_info.features & CHIP_FEATURE_WIFI_BGN) ? "WiFi/" : "",
//            (chip_info.features & CHIP_FEATURE_BT) ? "BT" : "",
//            (chip_info.features & CHIP_FEATURE_BLE) ? "BLE" : "",
//            (chip_info.features & CHIP_FEATURE_IEEE802154) ? ", 802.15.4 (Zigbee/Thread)" : "");

//     // 计算并打印芯片版本号
//     unsigned major_rev = chip_info.revision / 100;
//     unsigned minor_rev = chip_info.revision % 100;
//     printf("silicon revision v%d.%d, ", major_rev, minor_rev);

//     // 获取并打印闪存大小，失败则提示错误并返回
//     if (esp_flash_get_size(NULL, &flash_size) != ESP_OK)
//     {
//         printf("Get flash size failed");
//         return;
//     }

//     // 打印闪存类型及大小
//     printf("%" PRIu32 "MB %s flash\n", flash_size / (uint32_t)(1024 * 1024),
//            (chip_info.features & CHIP_FEATURE_EMB_FLASH) ? "embedded" : "external");

//     // 打印最小空闲堆内存
//     printf("Minimum free heap size: %" PRIu32 " bytes\n", esp_get_minimum_free_heap_size());

//     // 倒计时10秒后重启
//     for (int i = 10; i >= 0; i--)
//     {
//         printf("Restarting in %d seconds...\n", i);
//         vTaskDelay(1000 / portTICK_PERIOD_MS);
//     }
//     // 打印重启信息并执行重启
//     printf("Restarting now.\n");
//     fflush(stdout);
//     esp_restart();
// }

void print_Task(void *pvParameters)
{
    while (1)
    {
        printf("Hello from Task!,running on core %d\n", xPortGetCoreID());
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

void task2(void *pvParameters)
{
    while (1)
    {
        printf("Hello from Task2!,running on core %d\n", xPortGetCoreID());
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}
void app_main(void){
    xTaskCreate(print_Task, "print_Task", 1024*2, NULL, 5, NULL);
    xTaskCreate(task2, "task2", 1024*2, NULL, 5, NULL);
}