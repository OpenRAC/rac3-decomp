/* functional: high. Callee func_L39_00564800 argument layout (stack slots 0/8/0x10, t0..t3) inferred from the retail call; 203 byte diffs are codegen only. */
#include "common.h"
extern f32 D_001DFE08_sda;
__asm__(".extern D_001DFE08_sda, 4");
extern s32 D_001DFE0C_sda;
__asm__(".extern D_001DFE0C_sda, 4");
extern s32 D_001DFE10_sda;
__asm__(".extern D_001DFE10_sda, 4");
extern s32 D_001DFE14_sda;
__asm__(".extern D_001DFE14_sda, 4");
extern f32 D_001DFE18_sda;
__asm__(".extern D_001DFE18_sda, 4");
extern f32 D_001DFE1C_sda;
__asm__(".extern D_001DFE1C_sda, 4");
extern s32 D_0024D680[];
extern f32 D_0024D640[];
extern f32 D_003CCF80[];
extern u8 D_00296818[];
void func_003C4840(void *, void *, f32);
void func_0038D850(void *, void *, void *);
void func_003C4C18(void *, f32);
f32 func_0038CEA8(void *);
void func_0038CE20(void *, void *, f32);
u8 *func_L01_0046CA28(void *, s32, s32, s32);
void func_L39_00564800(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32);

void func_L39_00564498(u8 *obj) {
    u8 *st = *(u8 **)(obj + 0x68);
    f32 local[20][4];
    f32 base[4];
    f32 rot[4];
    f32 *H;
    f32 *pos;
    f32 len, lim;
    s32 i, k, m, cnt;
    u8 *p;
    base[0] = *(f32 *)(st + 0x30);
    base[1] = *(f32 *)(st + 0x34);
    base[2] = *(f32 *)(st + 0x38);
    base[3] = *(f32 *)(st + 0x3C);
    for (i = 0; i < 4; i++) {
        D_0024D680[i] = D_0024D680[i] + 1;
        if (D_0024D680[i] >= 0x14) D_0024D680[i] = 0x14;
        k = D_0024D680[i] - 1;
        H = D_003CCF80 + i * 0x50;
        if (k > 0) {
            for (m = k; m > 0; m--) {
                f32 *d = H + m * 4;
                f32 *s = H + (m - 1) * 4;
                f32 *o = local[k - m];
                d[0] = s[0]; d[1] = s[1]; d[2] = s[2]; d[3] = s[3];
                o[0] = base[0] + d[0];
                o[1] = base[1] + d[1];
                o[2] = base[2] + d[2];
                o[3] = 0.05f;
            }
        }
        func_003C4840(rot, D_0024D640 + i * 4, 0.10471976f);
        func_0038D850(H, H, rot);
        func_003C4C18(H, 0.025f);
        len = func_0038CEA8(H);
        lim = D_001DFE08_sda * 1.1f;
        if (lim < len) {
            func_0038CE20(H, H, lim / len);
        } else {
            lim = D_001DFE08_sda * 0.9f;
            if (len < lim) func_0038CE20(H, H, lim / len);
        }
        pos = local[k];
        pos[0] = base[0] + H[0];
        pos[1] = base[1] + H[1];
        pos[2] = base[2] + H[2];
        pos[3] = 0.05f;
        p = func_L01_0046CA28(pos, 2, 0, 1);
        if (p != 0) {
            *(s32 *)(p + 0x4) = D_001DFE0C_sda | *(s32 *)(st + 0x8);
            *(f32 *)(p + 0xC) = D_001DFE18_sda * 210000.0f;
            p[2] = (*(u8 **)(D_00296818 + 0xF8))[1];
        }
        p = func_L01_0046CA28(pos, 2, 0, 1);
        if (p != 0) {
            *(s32 *)(p + 0x4) = 0x407F7F7F;
            *(f32 *)(p + 0xC) = D_001DFE18_sda * 0.15f * 210000.0f;
        }
        cnt = D_0024D680[i];
        func_L39_00564800(local, 0x14, 0xE, 0xE, D_001DFE10_sda, D_001DFE10_sda & 0xFFFFFF,
                          D_001DFE14_sda | *(s32 *)(st + 0x8), D_001DFE14_sda, 0, cnt - 1, cnt,
                          0.02f, 0.07f, D_001DFE1C_sda);
    }
}
