/* NTSC-U draft (Claude wave C4): C of func_L14_0040C510, the NTSC-U twin of func_L14_0040F408, with NTSC-U names and addresses (the two versions' code differs).
 * flags: byte-exact on NTSC-U only with "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (its file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division") (NTSC-U twin "func_L14_0040C510", whose code is not the PAL one).
 * Worker's note: flags: byte-exact (MATCH) only with the extra @ps2as; its PAL counterpart file src/levels/14_koros/L14_0040F408.c has no @ps2as (200 diff with its flags: retail has inline lui/ori/mtc1 constants and a gp-form delay-slot macro for D_L14_001DF058 next to its ...
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L14_0040C510 */
typedef struct {
    u8 p0[0x30];
    s32 w30;
    s32 w34;
    u8 p38[0xC];
    s16 count;
    u8 p46[0x15A];
    u8 *mobys[5];
} S_40C510;

extern S_40C510 D_L14_001E6480_0040C510;
extern u8 *D_L14_00239530[];
extern f32 D_001D6A90_sda;
__asm__(".extern D_001D6A90_sda, 4");
extern f32 D_L14_001D6A94;
extern f32 D_L14_001D6A98;
extern f32 D_001D6B88_sda[2];
__asm__(".extern D_001D6B88_sda, 8");
extern f32 D_001D6B98_sda[2];
__asm__(".extern D_001D6B98_sda, 8");
extern f32 D_001D6BA8_sda[2];
__asm__(".extern D_001D6BA8_sda, 8");
extern f32 D_001DF058_sda;
__asm__(".extern D_001DF058_sda, 4");
extern f32 D_L14_001DF058;
extern s32 D_001D545C;

extern void func_L01_00420D88(void);
extern void func_003A04A0(u8 *, s32);
extern void func_L01_004026A0(void *, void *);
extern void func_L01_0044EB38(u8 *, f32 *, s32, s32, f32);
extern void func_L01_00402498(void *, void *);
extern u8 *func_L14_0040B760(s32);
extern void func_L14_0040BB50(void);
extern void func_L14_0040C0A8(u8 *, s32, s32, s32, f32, f32);
extern void func_L14_0040C2C0(u8 *, s32);
extern void func_L14_00497270();
extern void func_L14_0040C488();
extern void func_L14_0040BA60();
extern void func_L14_0040BBC0();

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
            for (j = 0; D_L14_00239530[j] != 0; j++) {
                if (D_L14_00239530[j][0x63] != 0) D_L14_00239530[j][0x63] = 1;
            }
            func_003A04A0(m, 0);
            func_L01_004026A0(func_L14_00497270, m);
        }
        if (m == 0) continue;
        t = *(s16 *)(m + 0xAA);
        if (t == 0xFA0) {
            if (*(u8 **)(m + 0x68) != 0) {
                func_L01_0044EB38(m, (f32 *)(*(u8 **)(m + 0x68) + 0xC), 0x80AAAAD2, 0x80396464, 0.061086528f);
            }
        } else if (t == 0x1DEE || t == 0x19BC) {
            func_L01_0044EB38(m, &D_001D6A90_sda, 0x80505080, 0x80404038, 0.031997703f);
        } else if (t == 0x1977) {
            func_L01_0044EB38(m, &D_L14_001D6A94, 0x8080AAAA, 0x80464646, 0.03781547f);
        } else if (t == 0x1766) {
            func_L01_0044EB38(m, &D_L14_001D6A98, 0x80AAAAFF, 0x80646496, 0.11053753f);
        } else if (t == 0x195B || t == 0x1B58 || t == 0x195C || t == 0x175A) {
            func_L01_00402498(func_L14_0040C488, m);
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
            v.z = 2.0532751f;
            v.w = 1.0f;
            func_L14_0040BB50();
            obj = D_L14_001E6480_0040C510.mobys[4];
            if (obj != 0 && D_L14_001E6480_0040C510.w34 >= 0x505) {
                *(vu0_v4 *)(obj + 0xF0) = v;
                func_L01_00402498(func_L14_0040BBC0, 0);
                if (D_L14_001E6480_0040C510.w34 < 0x565) {
                    for (j = 0; j < 4; j++) {
                        if (!(D_L14_001E6480_0040C510.w34 < ((s32 *)D_001D6B88_sda)[j])) {
                            func_L14_0040C0A8(obj, ((s32 *)D_001D6B88_sda)[j], D_L14_001E6480_0040C510.w34 & 1, j, D_001D6B98_sda[j], D_001D6BA8_sda[j]);
                        }
                    }
                }
                func_L14_0040C2C0(obj, (s32)((f32)(D_L14_001E6480_0040C510.w34 - 0x505) / 65.0f * 14.0f));
                k = D_L14_001E6480_0040C510.w34 - 0x550;
                if ((u32)k < 0x15) {
                    if (D_001DF058_sda < 1365.0f) {
                        D_001DF058_sda = (f32)k / 5.0f;
                    } else {
                        D_001DF058_sda = 1.0f;
                    }
                } else {
                    D_L14_001DF058 = 0;
                }
            }
        }
    }
}
/* localdecomp:end func_L14_0040C510 */
