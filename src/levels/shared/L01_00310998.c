#include "common.h"

typedef int s128 __attribute__((mode(TI)));
typedef struct {
    u8 pad0[0x28];
    s32 w28;
} S_311A18m;
typedef struct {
    u8 pad0[0x10];
    s128 q10;
    u8 b20;
    u8 pad21[0x68 - 0x21];
    S_311A18m *p68;
    u8 pad6C[0xAA - 0x6C];
    s16 hAA;
} S_311A18;


/* localdecomp:start func_L01_00310998 */
void func_L01_00310998(u8 *p)
{
    *(unsigned long *)(p + 128) = 0xFF9000000260;
    *(unsigned long *)(p + 112) = 0;
    *(f32 *)(p + 80) = 0.0f;
    *(f32 *)(p + 84) = 0.0f;
    *(f32 *)(p + 88) = 1.0f;
    *(f32 *)(p + 92) = 0.0f;
    *(f32 *)(p + 96) = 0.0f;
    *(f32 *)(p + 100) = 1.0f;
    *(f32 *)(p + 104) = 1.0f;
    *(f32 *)(p + 108) = 1.0f;
    *(f32 *)(p + 8) = -1.0f;
    *(f32 *)(p + 24) = 1.0f;
    *(f32 *)(p + 40) = -1.0f;
    *(f32 *)(p + 56) = 1.0f;
    *(f32 *)(p + 4) = -1.0f;
    *(f32 *)(p + 36) = 1.0f;
    *(f32 *)(p + 52) = 1.0f;
    *(f32 *)(p + 0) = 0.0f;
    *(f32 *)(p + 16) = 0.0f;
    *(f32 *)(p + 32) = 0.0f;
    *(f32 *)(p + 48) = 0.0f;
    *(f32 *)(p + 12) = 1.0f;
    *(f32 *)(p + 28) = 1.0f;
    *(f32 *)(p + 20) = -1.0f;
    *(f32 *)(p + 44) = 1.0f;
    *(f32 *)(p + 60) = 1.0f;
}
/* localdecomp:end func_L01_00310998 */
