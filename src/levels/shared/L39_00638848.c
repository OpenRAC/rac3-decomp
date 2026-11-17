#include "common.h"

/* localdecomp:start func_L39_00638848 */
typedef union Buf_00638848 {
    u8 b[8];
    u32 w[2];
} Buf_00638848;

extern u8 D_L39_004997E0[];
extern u8 D_L39_004997E1[];
extern u32 D_L39_0024B9C8;

typedef struct VT_00638848 {
    u8 pad0[0x34];
    s32 (*f34)(void *, s32, s32, s32, s32);
} VT_00638848;

typedef struct Ply_00638848 {
    u8 pad0[0x1A0];
    s32 w1A0;
} Ply_00638848;

extern void func_L39_00632D78(void *, s32, f32);
extern s32 func_L39_005C42E8(s32, s32);
extern s32 func_L39_005C2F50(void *);
extern void func_L39_0062B4A8(void *, s32, s32, s32, f32);
extern void func_L39_0062B6D8(void *, s32, s32);
extern s32 func_L39_006223B0(void *, s32);
extern void func_003C4BB0(void *, f32);
extern s32 D_L39_0024601C;

void func_L39_00638848(u8 *g) {
    *(s32 *)(g + 0x2450) = 0;
    func_L39_00632D78(g, 0, 1.0f);
    if (((*(Ply_00638848 **)(g + 0x2534))->w1A0 & func_L39_005C42E8(8, *(s32 *)(g + 0x2544))) &&
        !(func_L39_005C2F50(*(Ply_00638848 **)(g + 0x2534)) & 0x10)) {
        (*(VT_00638848 **)(g + 0x14))->f34(g, 4, 0, 0, 1);
        func_L39_0062B4A8(g, 0xD, 2, 0, -2.0f);
        func_L39_0062B6D8(g, 3, 0x12);
        return;
    }
    if (*(f32 *)(g + 0x2468) > 0.3f && *(s16 *)(g + 0x320) == 0) {
        if (g[0x372] != 0 || g[0x1A09] != 0) {
            (*(VT_00638848 **)(g + 0x14))->f34(g, 2, 1, 0, 1);
            return;
        }
        if ((*(VT_00638848 **)(g + 0x14))->f34(g, 2, 0, 0, 1) != 0) {
            u8 *q = g + 0x19E5;
            u8 *hk = q;
            s32 n;
            Buf_00638848 buf;
            u32 key;
            s32 k;
            s32 m;
            s32 i;
            u8 *d;

            if (*q == 0) {
                *q = ++D_L39_004997E0[0];
            } else {
                s32 t = *q;
                *q = D_L39_004997E1[0];
                D_L39_004997E1[0] = t;
            }
            key = ((u32 *)D_L39_004997E0)[((u32)hk * D_L39_0024B9C8) % 510];
            k = ((u32)q - *q) & 7;
            buf.w[0] = (u32)q ^ key;
            buf.w[1] = 1 ^ key;
            m = *q + 1;
            d = buf.b;
            for (i = 0; i < 40; i += 5) {
                D_L39_004997E0[m + ((k + i) & 7) * 255] = *d++;
            }
            n = g[0x14AC] >= 5 ? 0xC : 7;
            func_L39_0062B4A8(g, 4, D_L39_0024601C, 0, n);
            g[0x142E] = 1;
        }
        return;
    }
    if ((*(f32 *)(g + 0x1A8) > 0.060000002f && g[0x14AC] >= 3) || ({
            u8 *q = g + 0x19E4;
            u32 r;

            if (*q == 0) {
                r = 0;
            } else {
                Buf_00638848 buf;
                u32 a;
                s32 n = *q;
                s32 k = ((u32)q - n) & 7;
                s32 m = n + 1;
                s32 i;
                u8 *d = buf.b;

                for (i = 0; i < 40; i += 5) {
                    *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
                }
                a = buf.w[0] ^ (u32)q;
                r = buf.w[1] ^ a;
                buf.w[0] = a;
                buf.w[1] = r;
            }
            r == 0x10;
        })) {
        if ((*(VT_00638848 **)(g + 0x14))->f34(g, 3, 0, 0, 1) != 0) {
            func_L39_0062B4A8(g, 5, 0, 0, -1.0f);
            func_003C4BB0(g + 0x190, 0.10000001f);
        }
        return;
    }
    if ((g[0x14AC] >= 0xB || (*(s32 *)(g + 0x618) & 2)) && (*(VT_00638848 **)(g + 0x14))->f34(g, 0, 0, 0, 1) != 0 &&
        (*(s32 *)(g + 0x618) & 2)) {
        func_L39_0062B4A8(g, func_L39_006223B0(g, 0), 0, 0, -2.0f);
    }
}
/* localdecomp:end func_L39_00638848 */
