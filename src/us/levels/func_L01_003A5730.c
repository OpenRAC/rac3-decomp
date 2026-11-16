#include "common.h"

/* NTSC-U counterpart of func_L01_003A6EB0 (src/levels/shared/L01_003A4970.c) */
typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    u8 pad[0x30];
    u8 b30;
    u8 pad2[3];
    u16 h34;
    u8 pad3[0x98 - 0x36];
    int x98;
} S_3A9AC0m;

/* localdecomp:start func_L01_003A5730 */
#include "vu0.h"
void func_L01_003A5730(S_3A9AC0m *obj) {
    extern void func_003BE4F0(void *, s32, s32, s32);
    extern void func_L01_00441FB8(S_3A9AC0m *, int, int);
    u8 *m = (u8 *)obj;
    u8 *v = *(u8 **)(m + 0x68);
    u8 *model;
    s32 value;
    v[0x5E] = 0;
    v[0x60] = 0;
    v[0x5F] = 0;
    qzero(m + 0xF0);
    model = *(u8 **)(m + 0x24);
    *(f32 *)(m + 0x2C) = *(f32 *)(model + 0x24);
    *(u128_t *)(m + 0x10) = *(u128_t *)(v + 0x320);
    *(f32 *)(m + 0xF8) = *(f32 *)(v + 0x3AC);
    *(u16 *)(m + 0x34) &= 0xFFBE;
    *(u16 *)(m + 0x34) |= *(u16 *)(model + 0x44) & 0x1000;
    value = *(s32 *)(model + 0x10);
    *(u16 *)(m + 0x34) &= 0xFFFD;
    *(s32 *)(m + 0x98) = value;
    if (m[0x43] != 2) func_003BE4F0(obj, 2, 0, 10);
    func_L01_00441FB8(obj, 6, 3);
    if (*(s32 *)(v + 0x2FC) != -1) func_L01_00441FB8(obj, 8, -1);
}
/* localdecomp:end func_L01_003A5730 */
