/* NTSC-U draft (Claude wave C4): C of func_L07_00422138, the NTSC-U twin of func_L07_00424EA0, with NTSC-U names and addresses (the two versions' code differs).
 * flags: byte-exact on NTSC-U only with "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (its file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division") (NTSC-U twin "func_L07_00422138", whose code is not the PAL one).
 * Worker's note: flags: byte-exact (MATCH) only with the extra -mvu0-use-vf0-vf2 and @ps2as; its PAL counterpart file src/levels/07_annihilation_nation/L07_00424EA0.c has '-O2 -G8 -fopt-stack -mno-check-zero-division' only: COMPILE ERROR with its flags (vec_sub_ab's ...
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L07_00422138 */
typedef struct {
    u8 pad_000[0x30];
    s32 mode;
    s32 w34;
    u8 pad_038[0xC];
    s16 count;
    u8 pad_046[0x15A];
    u8 *objs[1];
} Level7_422138;

extern Level7_422138 D_L07_001E6200;
extern u8 *D_L07_00238870[];
extern s32 D_001D545C;
__asm__(".extern D_001D545C, 16");
extern f32 D_001D6A90_sda_00422138[2];
__asm__(".extern D_001D6A90_sda_00422138, 8");
extern f32 D_L07_001D6A94;
__asm__(".extern D_L07_001D6A94, 16");
extern f32 D_L07_001D6A98;
__asm__(".extern D_L07_001D6A98, 16");
typedef struct {
    u8 pad_00[0x2C];
    s32 w2C;
    u8 pad_30[0x10];
    f32 f40;
    u8 pad_44[4];
    s32 w48;
} Fx_001E1EC0;

extern Fx_001E1EC0 D_L07_001E1EC0_00422138;

extern void func_L01_00420D88();
extern void func_003A04A0(u8 *, s32);
extern void func_003A26D0();
extern void func_L01_00421438();
extern void func_L01_004026A0(void *, void *);
extern void func_L01_00402498(void *, void *);
extern void func_L01_0044EB38(u8 *, void *, s32, s32, f32);
extern void func_L07_00421C50(s32, s32, s32);
extern void func_L03_0040EE18(u8 *, s32);
extern f32 func_0037E250(f32, f32);
extern void func_003BF6A8(void *, f32);
extern void func_00388830(void *, void *, f32);
extern u8 *func_L01_003AFF80(u8 *, void *, void *, s32, s32, s32, s32, f32, f32);
extern void func_L01_0032FE90(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                              s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);

void func_L07_00422138(void) {
    s32 i;
    u8 *obj;
    u8 *o;
    s32 j;
    vu0_v4 tmp;
    vu0_v4 v;
    vu0_v4 *q1;
    vu0_v4 *q2;

    func_L01_00420D88();
    for (i = 0; i < D_L07_001E6200.count; i++) {
        obj = D_L07_001E6200.objs[i];
        if (obj != 0 && *(s16 *)(obj + 0xAA) == 0xE29) {
            *(u16 *)(obj + 0x34) |= 0x800;
        }
        if (*(s16 *)(obj + 0xAA) == 0xD54) {
            obj[0x63] = 0;
            for (j = 0; D_L07_00238870[j] != 0; j++) {
                if (D_L07_00238870[j][0x63] != 0) {
                    D_L07_00238870[j][0x63] = 1;
                }
            }
            func_003A04A0(obj, 0);
            func_L01_004026A0(func_003A26D0, obj);
        }
        if (obj != 0) {
            if (*(s16 *)(obj + 0xAA) == 0xFA0) {
                if (*(u8 **)(obj + 0x68) != 0) {
                    func_L01_0044EB38(obj, *(u8 **)(obj + 0x68) + 0xC, 0x80AAAAD2, 0x80396464,
                                      210.0f * 0.017453292f * 0.016666668f);
                }
            } else if (*(s16 *)(obj + 0xAA) == 0x1DEE || *(s16 *)(obj + 0xAA) == 0x19BC) {
                func_L01_0044EB38(obj, D_001D6A90_sda_00422138, 0x80505080, 0x80404038,
                                  110.0f * 0.017453292f * 0.016666668f);
            } else if (*(s16 *)(obj + 0xAA) == 0x1977) {
                func_L01_0044EB38(obj, &D_L07_001D6A94, 0x8080AAAA, 0x80464646,
                                  130.0f * 0.017453292f * 0.016666668f);
            } else if (*(s16 *)(obj + 0xAA) == 0x1766) {
                func_L01_0044EB38(obj, &D_L07_001D6A98, 0x80AAAAFF, 0x80646496,
                                  380.0f * 0.017453292f * 0.016666668f);
            } else if (*(s16 *)(obj + 0xAA) == 0x195B || *(s16 *)(obj + 0xAA) == 0x1B58 ||
                       *(s16 *)(obj + 0xAA) == 0x195C || *(s16 *)(obj + 0xAA) == 0x175A) {
                func_L01_00402498(func_L01_00421438, obj);
            }
        }
    }
    if (D_001D545C != 7) {
        return;
    }
    switch (D_L07_001E6200.mode) {
    case 1:
        func_L07_00421C50(0x3E8, 0, 3);
        if (D_L07_001E6200.w34 >= 0) {
            o = D_L07_001E6200.objs[6];
            if (o != 0) {
                func_L03_0040EE18(o, 0);
                func_L03_0040EE18(o, 1);
            }
        }
        break;
    case 2:
        if (D_L07_001E6200.w34 >= 0) {
            o = D_L07_001E6200.objs[3];
            if (o != 0) {
                func_L03_0040EE18(o, 0);
                func_L03_0040EE18(o, 1);
            }
        }
        break;
    case 4:
        if ((u32)(D_L07_001E6200.w34 - 0x8FC) < 0x15) {
            o = D_L07_001E6200.objs[0];
            if (o != 0) {
                q1 = &tmp;
                tmp = *(vu0_v4 *)(o + 0x10);
                tmp.x = tmp.x + func_0037E250(-3.5f, 3.5f);
                tmp.y = tmp.y + func_0037E250(-3.5f, 3.5f);
                tmp.z = tmp.z + 4.0f;
                func_003BF6A8(q1, 0.1f);
                vec_sub_ab(&v, o + 0x10, &tmp);
                func_00388830(&v, &v, 1.0f);
                func_L01_003AFF80(0, q1, &v, 0x60FF1010, 0x60DDDDDD, 0x7F1010, 0xFF1010, 0.0f, 0.65f);
            }
        }
        if ((u32)(D_L07_001E6200.w34 - 0x910) < 6) {
            q2 = &tmp;
            tmp = *(vu0_v4 *)(D_L07_001E6200.objs[0] + 0x10);
            tmp.z = tmp.z + 0.3f;
            func_003BF6A8(q2, 0.1f);
            D_L07_001E1EC0_00422138.f40 = func_0037E250(0.1f, 0.2f);
            D_L07_001E1EC0_00422138.w48 = 0x28;
            D_L07_001E1EC0_00422138.w2C = 0;
            func_L01_0032FE90(q2, 1, 0x19, 0x14, 0x14, 0x14, 0x2D, 2, 1.0f, 0.0f, 0.0f, 2.0f,
                              1, 1, 1, 0, 1, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF,
                              0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
        }
        break;
    }
}
/* localdecomp:end func_L07_00422138 */
