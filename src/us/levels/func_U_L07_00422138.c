#include "common.h"

/* NTSC-U counterpart of func_L07_00424EA0. */
/* localdecomp:start func_U_L07_00422138 */
#include "vu0.h"
typedef struct {
    u8 pad_000[0x30];
    s32 mode;
    s32 w34;
    u8 pad_038[0xC];
    s16 count;
    u8 pad_046[0x15A];
    u8 *objs[1];
} Level7_424EA0;

extern Level7_424EA0 D_U_001E6200;
extern u8 *D_U_00238870[];
extern s32 D_001D545C;
__asm__(".extern D_001D545C, 16");
extern f32 D_U_001D6A90[2];
__asm__(".extern D_U_001D6A90, 8");
extern f32 D_U_001D6A94;
__asm__(".extern D_U_001D6A94, 16");
extern f32 D_U_001D6A98;
__asm__(".extern D_U_001D6A98, 16");
typedef struct {
    u8 pad_00[0x2C];
    s32 w2C;
    u8 pad_30[0x10];
    f32 f40;
    u8 pad_44[4];
    s32 w48;
} Fx_001E1EC0;

extern Fx_001E1EC0 D_U_001E1EC0;

extern void func_U_00421AC0();
extern void func_U_004A6D88(u8 *, s32);
extern void func_U_004AB8D0();
extern void func_U_004220B0();
extern void func_U_00403C00(void *, void *);
extern void func_U_004039F8(void *, void *);
extern void func_U_0044F0A8(u8 *, void *, s32, s32, f32);
extern void func_U_00421C50(s32, s32, s32);
extern void func_U_00421ED0(u8 *, s32);
extern f32 func_U_00440E30(f32, f32);
extern void func_U_00449618(void *, f32);
extern void func_U_0040CA00(void *, void *, f32);
extern u8 *func_U_003AC0A0(u8 *, void *, void *, s32, s32, s32, s32, f32, f32);
extern void func_U_0032CC58(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                              s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);

void func_U_L07_00422138(void) {
    s32 i;
    u8 *obj;
    u8 *o;
    s32 j;
    vu0_v4 tmp;
    vu0_v4 v;
    vu0_v4 *q1;
    vu0_v4 *q2;

    func_U_00421AC0();
    for (i = 0; i < D_U_001E6200.count; i++) {
        obj = D_U_001E6200.objs[i];
        if (obj != 0 && *(s16 *)(obj + 0xAA) == 0xE29) {
            *(u16 *)(obj + 0x34) |= 0x800;
        }
        if (*(s16 *)(obj + 0xAA) == 0xD54) {
            obj[0x63] = 0;
            for (j = 0; D_U_00238870[j] != 0; j++) {
                if (D_U_00238870[j][0x63] != 0) {
                    D_U_00238870[j][0x63] = 1;
                }
            }
            func_U_004A6D88(obj, 0);
            func_U_00403C00(func_U_004AB8D0, obj);
        }
        if (obj != 0) {
            if (*(s16 *)(obj + 0xAA) == 0xFA0) {
                if (*(u8 **)(obj + 0x68) != 0) {
                    func_U_0044F0A8(obj, *(u8 **)(obj + 0x68) + 0xC, 0x80AAAAD2, 0x80396464,
                                      0.061086528f);
                }
            } else if (*(s16 *)(obj + 0xAA) == 0x1DEE || *(s16 *)(obj + 0xAA) == 0x19BC) {
                func_U_0044F0A8(obj, D_U_001D6A90, 0x80505080, 0x80404038,
                                  0.031997703f);
            } else if (*(s16 *)(obj + 0xAA) == 0x1977) {
                func_U_0044F0A8(obj, &D_U_001D6A94, 0x8080AAAA, 0x80464646,
                                  0.03781547f);
            } else if (*(s16 *)(obj + 0xAA) == 0x1766) {
                func_U_0044F0A8(obj, &D_U_001D6A98, 0x80AAAAFF, 0x80646496,
                                  0.110537529f);
            } else if (*(s16 *)(obj + 0xAA) == 0x195B || *(s16 *)(obj + 0xAA) == 0x1B58 ||
                       *(s16 *)(obj + 0xAA) == 0x195C || *(s16 *)(obj + 0xAA) == 0x175A) {
                func_U_004039F8(func_U_004220B0, obj);
            }
        }
    }
    if (D_001D545C != 7) {
        return;
    }
    switch (D_U_001E6200.mode) {
    case 1:
        func_U_00421C50(0x3E8, 0, 3);
        if (D_U_001E6200.w34 >= 0) {
            o = D_U_001E6200.objs[6];
            if (o != 0) {
                func_U_00421ED0(o, 0);
                func_U_00421ED0(o, 1);
            }
        }
        break;
    case 2:
        if (D_U_001E6200.w34 >= 0) {
            o = D_U_001E6200.objs[3];
            if (o != 0) {
                func_U_00421ED0(o, 0);
                func_U_00421ED0(o, 1);
            }
        }
        break;
    case 4:
        if ((u32)(D_U_001E6200.w34 - 2300) < 21) {
            o = D_U_001E6200.objs[0];
            if (o != 0) {
                q1 = &tmp;
                tmp = *(vu0_v4 *)(o + 0x10);
                tmp.x = tmp.x + func_U_00440E30(-3.5f, 3.5f);
                tmp.y = tmp.y + func_U_00440E30(-3.5f, 3.5f);
                tmp.z = tmp.z + 4.0f;
                func_U_00449618(q1, 0.1f);
                vec_sub_ba(&v, o + 0x10, &tmp);
                func_U_0040CA00(&v, &v, 1.0f);
                func_U_003AC0A0(0, q1, &v, 0x60FF1010, 0x60DDDDDD, 0x7F1010, 0xFF1010, 0.0f, 0.65f);
            }
        }
        if ((u32)(D_U_001E6200.w34 - 2320) < 6) {
            q2 = &tmp;
            tmp = *(vu0_v4 *)(D_U_001E6200.objs[0] + 0x10);
            tmp.z = tmp.z + 0.3f;
            func_U_00449618(q2, 0.1f);
            D_U_001E1EC0.f40 = func_U_00440E30(0.1f, 0.2f);
            D_U_001E1EC0.w48 = 40;
            D_U_001E1EC0.w2C = 0;
            func_U_0032CC58(q2, 1, 0x19, 0x14, 0x14, 0x14, 0x2D, 2, 1.0f, 0.0f, 0.0f, 2.0f,
                              1, 1, 1, 0, 1, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF,
                              0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
        }
        break;
    }
}
/* localdecomp:end func_U_L07_00422138 */
