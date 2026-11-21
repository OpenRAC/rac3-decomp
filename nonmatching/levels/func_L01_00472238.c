/* Near miss: 5 diffs, all at the start of the live block: retail issues lq $v0,0($s3) first, then sb 3, sb 1 (and keeps $a2 arg in $s0, pos in $s3); ours loads pos after sb 3/addiu s0 and swaps nothing else. 120 orders of the first five statements and 5040 of seven did not reach 0. */
#include "common.h"
#include "vu0.h"
extern u8 *func_L01_004618E0_00472238(s32);
extern u8 *D_L01_00221240_00472238[];
extern s32 func_00443948(s32);
extern s32 func_00443978(s32, s32);
extern f32 func_004439C0(f32, f32);

u8 *func_L01_00472238(s128 *pos, f32 *vec, s32 a2, s32 n, f32 f12) {
    u8 *p = func_L01_004618E0_00472238(0x6A);
    u8 *s;
    if (p != 0) {
        p[3] = a2;
        s = p + 0x20;
        *(s128 *)(p + 0x10) = *pos;
        p[9] = 0x44;
        p[1] = 0;
        p[8] = func_00443948(0xFF);
        p[2] = D_L01_00221240_00472238[0][0];
        *(s16 *)(p + 0xA) = n;
        *(f32 *)(p + 0x20) = vec[0];
        *(f32 *)(s + 4) = vec[1];
        *(f32 *)(s + 8) = vec[2];
        {
            s32 r = func_00443978(0xF, 0x1F);
            *(s32 *)(s + 0xC) = (r << 16) + (r << 8) + r;
        }
        s[0x10] = func_00443978(1, 4);
        s[0x11] = n;
        s[0x13] = 0;
        s[0x12] = func_00443978(0x5F, 0x7F);
        *(f32 *)(s + 0x14) = func_004439C0(0.0625f, 0.125f) * 210000.0f;
        *(f32 *)(s + 0x18) = func_004439C0(0.5f, 0.6f) * 210000.0f;
        *(f32 *)(s + 0x1C) = f12;
        *(s32 *)(p + 4) = (s[0x12] << 24) | 0x103080;
    }
    return p;
}
