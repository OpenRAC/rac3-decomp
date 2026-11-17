/* near miss (level 5, Daxx), opus pass 2026-11-13: 227 differences, needs @ps2as on its file (src/levels/05_daxx/L05_003CB758.c), which has no other function. Every instruction and branch is right; the count is a register renumbering. Retail keeps one more saved register (frame 0x60, $s0-$s5): the loaded D_001CCFD0.f24 (known -1) stays in $s0 and the three "v[8..10] = -1" stores use it, while id has its own $s3. Here cse stores id's -1 instead (or, with a t local, global-alloc ties t and id), so $s0 serves both and the frame is 0x50. The "st << D_001D545C" in the first bit test is retail's: cse put the case-1 value (1, in $s0) for the 1; the second test has a plain 1. The switch on o[0x20] gives retail's dispatch; base = D_L05_001DFB9C loaded once before the v[4] test. */
#include "common.h"
/* localdecomp:start func_L05_003CB758 */
__asm__(".extern D_L05_001DEE74, 4");
__asm__(".extern D_L05_001DEE78, 4");
__asm__(".extern D_L05_001DEE7C, 4");
__asm__(".extern D_L05_001DFB9C, 4");
__asm__(".extern D_L05_001D6694, 4");
__asm__(".extern D_001D545C, 16");
extern s32 D_L05_001DEE74;
extern s32 D_L05_001DEE78;
extern s32 D_L05_001DEE7C;
extern u8 *D_L05_001DFB9C;
extern s32 D_L05_001D6694;
extern s32 D_001D545C;
extern s32 D_001A8558[];
extern s32 D_001A8AEC[];
extern s16 D_001426A0[];
extern u8 D_001426E0[];
extern s32 D_001C5290[];
extern u8 D_001BBC40[][16];
extern u8 D_001A4C60[];
typedef struct {
    u8 pad0[0x24];
    s32 f24;
    u8 pad1[0x44];
    s32 f6C;
    u8 pad2[0x6];
    s16 h76;
    u8 pad3[0x1C];
    s32 f94;
    s16 h98;
    u8 pad4[0x4];
    s16 h9E;
} S_3CB758;
extern S_3CB758 D_001CCFD0;
extern s32 func_L01_004BA800(void);
extern void func_L01_0041A5B0(s32, s32);
extern void func_0039EF28(void);
extern s32 func_00382380(void *, s32, s32);
extern void func_003A2B68(s32, s32);
extern void func_003A1798(void);
extern s32 func_0038CAD0(void *);

void func_L05_003CB758(u8 *o) {
    s32 *v;
    s32 st;
    s32 lo;
    s32 id;
    s32 k;
    s32 arr[5];
    u8 *m;
    u8 *base;

    st = o[0x20];
    v = *(s32 **)(o + 0x68);
    switch (st) {
    case 0:
        o[0x30] = 0xFF;
        D_L05_001DEE78 = 0;
        o[0x20] = 1;
        break;
    case 1:
        if (D_L05_001D6694 != 6 && func_L01_004BA800() == 0 && (D_001A8558[0] & (st << D_001D545C)) == 0) {
            func_L01_0041A5B0(0xCF3, 0x9A);
        }
        lo = D_001BBC40[D_001D545C][v[0]] >> 7;
        if ((D_001BBC40[D_001D545C][v[1]] >> 7) != 0) {
            base = D_L05_001DFB9C;
            if (v[4] >= 0) {
                m = base + (v[4] << 8);
                *(u16 *)(m + 0x34) &= 0xFFBE;
                m = base + (v[4] << 8);
                *(u16 *)(m + 0x34) |= *(u16 *)(*(u8 **)(m + 0x24) + 0x44) & 0x1000;
                m = base + (v[4] << 8);
                *(s32 *)(m + 0x98) = *(s32 *)(*(u8 **)(m + 0x24) + 0x10);
                v[4] = -1;
            }
            if (D_001426E0[0x7B] == 0) {
                D_001426E0[0x7B] = 1;
                func_0039EF28();
                D_001426E0[0x13] = 1;
                func_0039EF28();
            }
        }
        if (D_001C5290[0x50 + v[0]] + D_001C5290[0x50 + v[6]] >= 3 && D_001426A0[0] < 2
            && (D_001A8AEC[0] & (1 << D_001D545C)) == 0) {
            func_L01_0041A5B0(0x140F, 0x111);
        }
        if (o[0x95] == 0) {
            if (D_001CCFD0.f6C == 0 && D_001CCFD0.f24 == -1 && D_001CCFD0.f94 == 0) {
                id = -1;
                if (lo == 0) {
                    if (func_00382380(D_001A4C60, v[8], 0) != 0) {
                        v[8] = -1;
                        id = v[11];
                    } else if (func_00382380(D_001A4C60, v[9], 0) != 0) {
                        v[9] = -1;
                        id = v[12];
                    } else if (func_00382380(D_001A4C60, v[10], 0) != 0) {
                        v[10] = -1;
                        id = v[13];
                    }
                }
                if (id == -1) {
                    if (D_L05_001DEE78 == 0 && func_00382380(D_001A4C60, v[5], 0) != 0) {
                        k = D_L05_001DEE7C;
                        arr[0] = v[17];
                        arr[1] = v[14];
                        arr[2] = v[16];
                        arr[3] = v[15];
                        arr[4] = v[18];
                        D_L05_001DEE7C = k + 1;
                        if (k + 1 >= 5) {
                            D_L05_001DEE7C = 0;
                        }
                        id = arr[k];
                        D_L05_001DEE78 = D_L05_001DEE74;
                    }
                    if (id == -1) {
                        goto end;
                    }
                }
                func_003A2B68((id & 0x3FFF) + 0x7D0, 0);
                o[0x95] = 1;
            }
        } else if (o[0x95] == 1) {
            if (D_001CCFD0.h76 == 0 && D_001CCFD0.h9E == 3 && D_001CCFD0.h98 < 0x1B58) {
                func_003A1798();
                o[0x95] = 0;
            }
        }
        break;
    }
end:
    func_0038CAD0(&D_L05_001DEE78);
}
/* localdecomp:end func_L05_003CB758 */
