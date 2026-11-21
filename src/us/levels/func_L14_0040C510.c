#include "common.h"

/* NTSC-U counterpart of func_L14_0040F408 (src/levels/14_koros/L14_0040F408.c) */
/* localdecomp:start func_L14_0040C510 */
#include "vu0.h"

typedef struct {
    u8 p0[0x30];
    s32 w30;
    s32 w34;
    u8 p38[0xC];
    s16 count;
    u8 p46[0x15A];
    u8 *mobys[5];
} S_0040F408;

extern S_0040F408 D_L14_001E6480_0040C510;
extern u8 *D_L14_00239530_0040C510[];
extern f32 D_L14_001D6A90_0040C510;
__asm__(".extern D_L14_001D6A90_0040C510, 4");
extern f32 D_L14_001D6A94_0040C510;
extern f32 D_L14_001D6A98_0040C510;
extern s32 D_L14_001D6B88_0040C510[] __attribute__((section(".sdata")));
extern f32 D_L14_001D6B98_0040C510[] __attribute__((section(".sdata")));
extern f32 D_L14_001D6BA8_0040C510[] __attribute__((section(".sdata")));
__asm__(".extern D_L14_001D6B88_0040C510, 8");
__asm__(".extern D_L14_001D6B98_0040C510, 8");
__asm__(".extern D_L14_001D6BA8_0040C510, 8");
extern f32 D_L14_001DF058_0040C510;
extern s32 D_001D545C;

extern void func_L01_00420D88(void);
extern void func_003A04A0(void *, s32);
extern void func_L01_004026A0(void *, void *);
extern void func_L01_0044EB38(void *, void *, s32, s32, f32);
extern void func_L01_00402498(void *, void *);
extern u8 *func_L14_0040B760(s32);
extern void func_L14_0040BB50(void);
extern void func_L14_0040C0A8(u8 *, s32, s32, s32, f32, f32);
extern void func_L14_0040C2C0(u8 *, s32);
extern void func_003A26D0(void *);
extern void func_L01_00421438(void *);
extern void func_L14_0040BA60(void *);
extern void func_L14_0040BBC0(void *);

/* from the NTSC-U draft of func_L14_0040C510 */
void func_L14_0040C510(void) {
    s32 i;
    u8 *m;
    s32 j;
    s16 t;
    u8 *obj;
    u8 *e;
    s32 k;
    vu0_v4 v;

    func_L01_00420D88();
    for (i = 0; i < D_L14_001E6480_0040C510.count; i++) {
        m = D_L14_001E6480_0040C510.mobys[i];
        if (m != 0 && *(s16 *)(m + 0xAA) == 0xE29) *(u16 *)(m + 0x34) |= 0x800;
        if (*(s16 *)(m + 0xAA) == 0xD54) {
            m[0x63] = 0;
            for (j = 0; D_L14_00239530_0040C510[j] != 0; j++) {
                if (D_L14_00239530_0040C510[j][0x63] != 0) D_L14_00239530_0040C510[j][0x63] = 1;
            }
            func_003A04A0(m, 0);
            func_L01_004026A0(func_003A26D0, m);
        }
        if (m == 0) continue;
        t = *(s16 *)(m + 0xAA);
        if (t == 0xFA0) {
            if (*(u8 **)(m + 0x68) != 0) {
                func_L01_0044EB38(m, *(u8 **)(m + 0x68) + 0xC, 0x80AAAAD2, 0x80396464, 0.061086528f);
            }
        } else if (t == 0x1DEE || t == 0x19BC) {
            func_L01_0044EB38(m, &D_L14_001D6A90_0040C510, 0x80505080, 0x80404038, 0.031997703f);
        } else if (t == 0x1977) {
            func_L01_0044EB38(m, &D_L14_001D6A94_0040C510, 0x8080AAAA, 0x80464646, 0.03781547f);
        } else if (t == 0x1766) {
            func_L01_0044EB38(m, &D_L14_001D6A98_0040C510, 0x80AAAAFF, 0x80646496, 0.11053753f);
        } else if (t == 0x195B || t == 0x1B58 || t == 0x195C || t == 0x175A) {
            func_L01_00402498(func_L01_00421438, m);
        }
    }
    if (D_001D545C == 0xE) {
        if (D_L14_001E6480_0040C510.w30 == 0 && D_L14_001E6480_0040C510.w34 < 0x72) {
            e = func_L14_0040B760(0x1C93);
            func_L01_00402498(func_L14_0040BA60, e);
        }
        if (D_L14_001E6480_0040C510.w30 == 1) {
            *(vu0_q *)&v = 0;
            v.y = 0.20902063f;
            v.z = 2.05327511f;
            v.w = 1.0f;
            func_L14_0040BB50();
            obj = D_L14_001E6480_0040C510.mobys[4];
            if (obj != 0 && D_L14_001E6480_0040C510.w34 >= 0x505) {
                *(vu0_v4 *)(obj + 0xF0) = v;
                func_L01_00402498(func_L14_0040BBC0, 0);
                if (D_L14_001E6480_0040C510.w34 < 0x565) {
                    for (j = 0; j < 4; j++) {
                        if (!(D_L14_001E6480_0040C510.w34 < D_L14_001D6B88_0040C510[j])) {
                            func_L14_0040C0A8(obj, D_L14_001D6B88_0040C510[j], D_L14_001E6480_0040C510.w34 & 1, j, D_L14_001D6B98_0040C510[j], D_L14_001D6BA8_0040C510[j]);
                        }
                    }
                }
                func_L14_0040C2C0(obj, (s32)((f32)(D_L14_001E6480_0040C510.w34 - 0x505) / 65.0f * 14.0f));
                k = D_L14_001E6480_0040C510.w34 - 0x550;
                if ((u32)k < 0x15) {
                    if (D_L14_001DF058_0040C510 < 1365.0f) {
                        D_L14_001DF058_0040C510 = (f32)k / 5.0f;
                    } else {
                        D_L14_001DF058_0040C510 = 1.0f;
                    }
                } else {
                    D_L14_001DF058_0040C510 = 0;
                }
            }
        }
    }
}
/* localdecomp:end func_L14_0040C510 */
