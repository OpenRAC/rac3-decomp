#include "common.h"
extern s32 D_001D545C_sda;
extern f32 D_001DAA3C_sda;
extern u8 D_0014275B[];
extern f32 D_L01_002F17E0[];
__asm__(".extern D_001D545C_sda, 4");
__asm__(".extern D_001DAA3C_sda, 4");
s32 func_L01_003291D0(u8 *m) {
    extern s32 func_L01_0041A4F0(u8 *);
    u8 *vars = *(u8 **)(m + 0x68);
    s32 value = *(s32 *)(vars + 0x54);
    s32 divisor = 1;
    s32 scaled;
    if (func_L01_0041A4F0(m)) {
        f32 amount = (f32)value;
        f32 scale;
        if (D_001D545C_sda == 7 && D_0014275B[0]) scale = D_001DAA3C_sda;
        else scale = D_L01_002F17E0[D_001D545C_sda];
        scaled = (s32)(amount * scale);
        if (D_001D545C_sda == 4) scaled *= 15;
        value = scaled;
    }
    if (vars[0x53] == 255 || D_L01_002AEA10[vars[0x53]].w12 == 0) {
        s32 key = *(s32 *)(vars + 8);
        if (key != -1) {
            if (D_001BBC40[key + D_001D545C_sda * 16] & 128) divisor = 10;
        }
    } else {
        E_00329038 *entry = &D_L01_002AEA10[vars[0x53]];
        u32 flag = D_001426E0[entry->w12];
        if (flag >= 2) divisor = 10;
        else if (flag == 1) divisor = 3;
    }
    if (divisor >= 2) {
        s32 result = value / divisor;
        result -= result % 100;
        if (result == 0) result = 100;
        return result;
    }
    return value;
}
