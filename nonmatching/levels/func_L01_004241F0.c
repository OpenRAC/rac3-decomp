/* NTSC-U draft (2026-11-14, Claude worker): C of func_L01_004214C0, the NTSC-U twin of func_L01_004241F0, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (src/levels/01_veldin/L01_004241F0.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division").
 */
#include "common.h"
#include "vu0.h"

/* NTSC-U counterpart of func_L01_004241F0 (src/levels/01_veldin/L01_004241F0.c).
 * Byte-exact only with `-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as`: the PAL
 * file's flag line lacks -mvu0-use-vf0-vf2 (vec_add_ab) and @ps2as (float literals as lui/ori/mtc1). */

/* localdecomp:start func_L01_004214C0 */
typedef int u128_t_4214C0 __attribute__((mode(TI)));
typedef struct {
    u8 pad0[0x30];
    s32 mode;
    s32 timer;
    u8 pad38[0xC];
    s16 count;
    u8 pad46[0x1A0 - 0x46];
    u8 *mobys[3];
} G_4214C0;
typedef struct {
    u8 pad0[0x2C];
    s32 f2C;
    u8 pad30[0x10];
    f32 f40;
    u8 pad44[4];
    s32 f48;
} E_4214C0;
extern G_4214C0 D_L01_001E6E00;
extern E_4214C0 D_L01_001E2AC0;
extern u8 *D_L01_0023ACF0[];
extern s32 D_001D545C;
__asm__(".extern D_001D6AE0_sda, 4");
extern f32 D_001D6AE0_sda;
extern f32 D_L01_001D6AE4;
extern f32 D_L01_001D6AE8;
extern u8 D_L01_001D66B0[8];
extern void func_L01_00420D88(void);
extern void func_003A04A0(u8 *, s32);
extern void func_003A26D0(void);
extern void func_L01_004026A0(void *, void *);
extern void func_L01_0044EB38(u8 *, f32 *, s32, s32, f32);
extern void func_L01_00421438(void);
extern void func_L01_00402498(void *, void *);
extern void func_L01_004210F0(void);
extern s32 func_0037E208(s32, s32);
extern s32 func_0037E1D8(s32);
extern f32 func_0037E250(f32, f32);
extern void func_00388BF0(void *, void *);
extern void func_003886E8(void *, void *, f32);
extern u8 *func_L01_003AFF80(u8 *, void *, void *, s32, s32, s32, s32, f32, f32);
extern s32 func_L01_004A72A8(s32, s32, void *, s32);
extern s32 func_L01_0032FE90(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                             s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_0034F568(void *);
extern void func_L01_004212E0(void *, void *);
extern void func_L01_004210C0(void);
extern void func_L01_00420F18(void *, f32, f32, f32);

void func_L01_004214C0(void) {
    s32 i;
    u8 *m;
    s32 t;
    s32 j;

    func_L01_00420D88();
    for (i = 0; i < D_L01_001E6E00.count; i++) {
        m = D_L01_001E6E00.mobys[i];
        if (m != 0 && *(s16 *)(m + 0xAA) == 0xE29) {
            *(u16 *)(m + 0x34) |= 0x800;
        }
        if (*(s16 *)(m + 0xAA) == 0xD54) {
            m[0x63] = 0;
            for (j = 0; D_L01_0023ACF0[j] != 0; j++) {
                if (D_L01_0023ACF0[j][0x63] != 0) {
                    D_L01_0023ACF0[j][0x63] = 1;
                }
            }
            func_003A04A0(m, 0);
            func_L01_004026A0(func_003A26D0, m);
        }
        if (m == 0) {
            continue;
        }
        t = *(s16 *)(m + 0xAA);
        if (t == 0xFA0) {
            if (*(u8 **)(m + 0x68) != 0) {
                func_L01_0044EB38(m, (f32 *)(*(u8 **)(m + 0x68) + 0xC), 0x80AAAAD2, 0x80396464, 0.061086528f);
            }
        } else if (t == 0x1DEE || t == 0x19BC) {
            func_L01_0044EB38(m, &D_001D6AE0_sda, 0x80505080, 0x80404038, 0.031997703f);
        } else if (t == 0x1977) {
            func_L01_0044EB38(m, &D_L01_001D6AE4, 0x8080AAAA, 0x80464646, 0.0378154702f);
        } else if (t == 0x1766) {
            func_L01_0044EB38(m, &D_L01_001D6AE8, 0x80AAAAFF, 0x80646496, 0.110537529f);
        } else if (t == 0x195B || t == 0x1B58 || t == 0x195C || t == 0x175A) {
            func_L01_00402498(func_L01_00421438, m);
        }
    }
    if (D_001D545C == 1) {
        switch (D_L01_001E6E00.mode) {
        case 0: {
            vu0_v4 p = {402.0f, 177.0f, 90.0f};
            vu0_v4 r = {0.0f, 0.0f, 2.4434609f};
            s32 tbl[3] = {580, 610, 630};
            vu0_v4 q = {388.0f, 189.0f, 90.0f};
            vu0_v4 mat[4];
            vu0_v4 s;
            vu0_v4 u;

            /* the inner block keeps the loop below out of the declaring block: a loop in the same block as
             * the address-taken locals pins their stack slots, and retail shares them with case 5's arrays */
            {
                s32 k;
                u8 *ptr;

                if (func_0037E208(0, 20) == 0) {
                    s = p;
                    r.y += func_0037E250(-0.1f, 0.1f);
                    r.z += func_0037E250(-0.1f, 0.1f);
                    func_00388BF0(mat, &r);
                    s.z -= func_0037E250(0.0f, 5.0f);
                    u = mat[0];
                    ptr = func_L01_003AFF80(0, &s, &u, 0x60FF1010, 0x60DDDDDD, 0x7F1010, 0xFF1010, 0.0f, 0.65f);
                    if (ptr != 0) {
                        func_L01_004A72A8(0, 0, ptr, 0x1F7C);
                    }
                }
                for (k = 0; k < 3; k++) {
                    if (D_L01_001E6E00.timer == tbl[k]) {
                        D_L01_001E2AC0.f40 = func_0037E250(0.1f, 0.2f);
                        D_L01_001E2AC0.f48 = 20;
                        D_L01_001E2AC0.f2C = 0;
                        ptr = (u8 *)func_L01_0032FE90(&q, 1, 25, 20, 20, 20, 45, 2, 1.0f, 0.0f, 0.0f, 2.0f,
                                                      1, 1, 1, 0, 1, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF,
                                                      0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
                        if (ptr != 0) {
                            func_L01_004A72A8(0, 0, ptr, 0x1F7B);
                        }
                    }
                }
            }
            break;
        }
        case 1:
            func_L01_004210F0();
            break;
        case 5: {
            s32 arr1[12] = {1100, 1110, 1120, 1145, 1170, 1220, 1230, 1240, 1260, 1270, 1280, 1435};
            s32 arr2[10] = {1100, 1110, 1170, 1200, 1210, 1220, 1290, 1315, 1325, 1335};
            vu0_v4 d;
            s32 k;

            for (k = 0; k < 12; k++) {
                if (arr1[k] == D_L01_001E6E00.timer) {
                    func_L01_0034F568(D_L01_001E6E00.mobys[2]);
                }
            }
            for (k = 0; k < 10; k++) {
                if (arr2[k] == D_L01_001E6E00.timer) {
                    func_L01_0034F568(D_L01_001E6E00.mobys[1]);
                }
            }
            if (D_L01_001E6E00.timer == 0x5AA) {
                u8 *h = D_L01_001E6E00.mobys[1];

                vec_add_ab(&d, h + 0x10, h + 0x10);
                func_003886E8(&d, &d, 0.5f);
                d.z += 0.1f;
                D_L01_001E2AC0.f40 = func_0037E250(0.1f, 0.2f);
                D_L01_001E2AC0.f48 = 20;
                D_L01_001E2AC0.f2C = 0;
                func_L01_0032FE90(&d, 1, 25, 20, 20, 20, 45, 2, 1.0f, 0.0f, 0.0f, 2.0f,
                                  1, 1, 1, 0, 1, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF,
                                  0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            }
            if (D_L01_001E6E00.timer > arr1[0] && D_L01_001E6E00.timer < arr1[11]) {
                if (func_0037E1D8(3) == 0) {
                    if (func_0037E1D8(2) == 0) {
                        func_L01_004212E0(D_L01_001E6E00.mobys[2], D_L01_001D66B0);
                    } else {
                        func_L01_004212E0(D_L01_001E6E00.mobys[1], D_L01_001D66B0);
                    }
                }
            }
            func_L01_004210C0();
            if (func_0037E1D8(5) == 0) {
                *(u128_t_4214C0 *)&d = 0;
                d.y = -10.0f;
                func_L01_004212E0(D_L01_001E6E00.mobys[0], &d);
            }
            if (D_L01_001E6E00.timer % 100 == 0) {
                if (func_0037E1D8(2) == 0) {
                    *(u128_t_4214C0 *)&d = 0;
                    d.x = 14.0f;
                    d.z = -0.8f;
                    func_L01_00420F18(&d, 5.0f, 0.1f, 1.0f);
                }
            }
            break;
        }
        }
    }
}
/* localdecomp:end func_L01_004214C0 */
