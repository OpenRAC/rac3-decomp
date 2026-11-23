/* PAL near miss (sol-3): 263 words differ with the file's flags. Float literals use the assembler pool, shifting the output. The VU0 sequence and some branches also schedule differently. */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L07_00424EA0 */
typedef struct {
    u8 pad_000[0x30];
    s32 mode;
    s32 w34;
    u8 pad_038[0xC];
    s16 count;
    u8 pad_046[0x15A];
    u8 *objs[1];
} Level7_424EA0;

extern Level7_424EA0 D_L07_001E6200;
extern u8 *D_L07_00238870[];
extern s32 D_001D545C;
__asm__(".extern D_001D545C, 16");
extern f32 D_001D6A90_sda[2];
__asm__(".extern D_001D6A90_sda, 8");
extern f32 D_001D6A94;
__asm__(".extern D_001D6A94, 16");
extern f32 D_001D6A98;
__asm__(".extern D_001D6A98, 16");
typedef struct {
    u8 pad_00[0x2C];
    s32 w2C;
    u8 pad_30[0x10];
    f32 f40;
    u8 pad_44[4];
    s32 w48;
} Fx_001E1EC0;

extern Fx_001E1EC0 D_L07_001E1EC0;

extern void func_L01_00423AB8();
extern void func_003A58C0(u8 *, s32);
extern void func_003A7AF8();
extern void func_L01_00424168();
extern void func_L01_00404A10(void *, void *);
extern void func_L01_00404808(void *, void *);
extern void func_L01_00451DB8(u8 *, void *, s32, s32, f32);
extern void func_L07_004249A0(s32, s32, s32);
extern void func_L03_00411F50(u8 *, s32);
extern f32 func_003824E0(f32, f32);
extern void func_003C4C18(void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern u8 *func_L01_003B1750(u8 *, void *, void *, s32, s32, s32, s32, f32, f32);
extern void func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                              s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);

void func_L07_00424EA0(void) {
    s32 i;
    u8 *obj;
    u8 *o;
    s32 j;
    vu0_v4 tmp;
    vu0_v4 v;
    vu0_v4 *q1;
    vu0_v4 *q2;

    func_L01_00423AB8();
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
            func_003A58C0(obj, 0);
            func_L01_00404A10(func_003A7AF8, obj);
        }
        if (obj != 0) {
            if (*(s16 *)(obj + 0xAA) == 0xFA0) {
                if (*(u8 **)(obj + 0x68) != 0) {
                    func_L01_00451DB8(obj, *(u8 **)(obj + 0x68) + 0xC, 0x80AAAAD2, 0x80396464,
                                      0.073303834f);
                }
            } else if (*(s16 *)(obj + 0xAA) == 0x1DEE || *(s16 *)(obj + 0xAA) == 0x19BC) {
                func_L01_00451DB8(obj, D_001D6A90_sda, 0x80505080, 0x80404038,
                                  0.038397245f);
            } else if (*(s16 *)(obj + 0xAA) == 0x1977) {
                func_L01_00451DB8(obj, &D_001D6A94, 0x8080AAAA, 0x80464646,
                                  0.045378566f);
            } else if (*(s16 *)(obj + 0xAA) == 0x1766) {
                func_L01_00451DB8(obj, &D_001D6A98, 0x80AAAAFF, 0x80646496,
                                  0.13264504f);
            } else if (*(s16 *)(obj + 0xAA) == 0x195B || *(s16 *)(obj + 0xAA) == 0x1B58 ||
                       *(s16 *)(obj + 0xAA) == 0x195C || *(s16 *)(obj + 0xAA) == 0x175A) {
                func_L01_00404808(func_L01_00424168, obj);
            }
        }
    }
    if (D_001D545C != 7) {
        return;
    }
    switch (D_L07_001E6200.mode) {
    case 1:
        func_L07_004249A0(0x3E8, 0, 3);
        if (D_L07_001E6200.w34 >= 0) {
            o = D_L07_001E6200.objs[6];
            if (o != 0) {
                func_L03_00411F50(o, 0);
                func_L03_00411F50(o, 1);
            }
        }
        break;
    case 2:
        if (D_L07_001E6200.w34 >= 0) {
            o = D_L07_001E6200.objs[3];
            if (o != 0) {
                func_L03_00411F50(o, 0);
                func_L03_00411F50(o, 1);
            }
        }
        break;
    case 4:
        if ((u32)(D_L07_001E6200.w34 - 0x63D) < 0xF) {
            o = D_L07_001E6200.objs[0];
            if (o != 0) {
                q1 = &tmp;
                tmp = *(vu0_v4 *)(o + 0x10);
                tmp.x = tmp.x + func_003824E0(-3.5f, 3.5f);
                tmp.y = tmp.y + func_003824E0(-3.5f, 3.5f);
                tmp.z = tmp.z + 4.0f;
                func_003C4C18(q1, 0.1f);
                __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvsub.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0"
                        : "=m"(v) : "m"(*(vu0_v4 *)(o + 0x10)), "m"(tmp) : "vf1", "vf2");
                func_0038CF68(&v, &v, 1.0f);
                func_L01_003B1750(0, q1, &v, 0x60FF1010, 0x60DDDDDD, 0x7F1010, 0xFF1010, 0.0f, 0.65f);
            }
        }
        if ((u32)(D_L07_001E6200.w34 - 0x64B) < 4) {
            q2 = &tmp;
            tmp = *(vu0_v4 *)(D_L07_001E6200.objs[0] + 0x10);
            tmp.z = tmp.z + 0.3f;
            func_003C4C18(q2, 0.1f);
            D_L07_001E1EC0.f40 = func_003824E0(0.1f, 0.2f);
            D_L07_001E1EC0.w48 = 0x21;
            D_L07_001E1EC0.w2C = 0;
            func_L01_003303B8(q2, 1, 0x19, 0x14, 0x14, 0x14, 0x2D, 2, 1.0f, 0.0f, 0.0f, 2.0f,
                              1, 1, 1, 0, 1, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF,
                              0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
        }
        break;
    }
}
/* localdecomp:end func_L07_00424EA0 */
