#pragma once

#include <stdint.h>
#include <string.h>


struct tp_mAudioMgrInfo{
    uint32_t* ptr00;
};


/* Pointers */
#define tp_mAudioMgrPtr_addr 0x80451368
#define tp_mAudioMgrPtr (*(tp_mAudioMgrInfo *)tp_mAudioMgrPtr_addr)

/* Functions */
#define bgmStart_addr 0x802AF010
typedef void (*bgmStart_t)(uint32_t* param0, uint32_t param1, signed long param2);
#define bgmStart ((bgmStart_t)bgmStart_addr)

#define bgmStop_addr 0x802AF408
typedef void (*bgmStop_t)(uint32_t* param0, signed long param1);
#define bgmStop ((bgmStop_t)bgmStop_addr)

/* SC2 */

#define playSound_addr 0x8007d40c
typedef void (*playSound_t)(float param0, uint32_t sfx_id);
#define playSound ((playSound_t)playSound_addr)

#define playBgm_addr 0x8007ebb0
typedef void (*playBgm_t)(uint32_t bgm_id);
#define playBgm ((playBgm_t)playBgm_addr)