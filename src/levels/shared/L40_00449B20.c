#include "common.h"

/* localdecomp:start func_L40_00449B20 */
typedef struct {
    u8 b0;
    u8 b1;
    s16 id;
    s32 w4;
    s32 w8;
    s32 wC;
    s32 w10;
} E_00449B20;

extern s32 D_001D6D14_sda;
extern s32 D_001D6D18_sda;
extern E_00449B20 D_L40_00257CC0[];
extern s32 func_L40_00449A38(void *, s32 *, s32 *, u16 *, u8 *);

s32 func_L40_00449B20(void *a0) {
    u16 c0;
    u8 c2;
    s32 s4;
    s32 s8;
    s32 i;
    s16 id;

    if (a0 != 0 && func_L40_00449A38(a0, &s4, &s8, &c0, &c2) != 0) {
        i = D_001D6D14_sda;
        id = (u16)D_001D6D14_sda | ((u16)D_001D6D18_sda << 6);
        D_L40_00257CC0[i].b1 = c2;
        D_L40_00257CC0[i].w8 = s4;
        D_L40_00257CC0[i].wC = s8;
        if (c2 == 0) {
            D_L40_00257CC0[i].w4 = s4;
        } else {
            D_L40_00257CC0[i].w4 = s8;
        }
        D_001D6D18_sda++;
        D_L40_00257CC0[D_001D6D14_sda].b0 = c0;
        D_L40_00257CC0[D_001D6D14_sda].id = id;
        D_L40_00257CC0[D_001D6D14_sda].w10 = -1;
        D_001D6D14_sda = (D_001D6D14_sda + 1) & 0xF;
        return id;
    }
    return 0;
}
/* localdecomp:end func_L40_00449B20 */

/* localdecomp:start func_L40_00449C10 */
typedef struct {
    u8 pad0[0xC];
    s32 xC[0xC0];
} S_00449C10;

extern S_00449C10 D_001A6A80;
extern s32 D_001D6D24_sda;
extern s32 func_L39_005B4398(s32);

s32 func_L40_00449C10(void) {
    s32 n = func_L39_005B4398(D_001D6D24_sda);
    s32 i;

    for (i = 0; i < 0xC0; i++) {
        if (D_001A6A80.xC[i] != 0) {
            if (--n == 0) {
                return D_001A6A80.xC[i];
            }
        }
    }
    return 0;
}
/* localdecomp:end func_L40_00449C10 */
