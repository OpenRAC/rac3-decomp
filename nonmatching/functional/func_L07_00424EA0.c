/* functional: high. Written from the PAL asm using the matched twin func_L01_004241F0 (Veldin) for the shared prologue and names; PAL-specific pieces re-read from the asm: mode 4 effects run for timer 0x63D..0x64B (0xF-wide) and 0x64B..0x64E, effect word 0x21, mode 1 and 2 pick moby slots 6 and 3. Bytes may differ in scheduling. */
#include "common.h"
#include "vu0.h"

typedef struct {
    u8 pad0[0x30];
    s32 mode;
    s32 timer;
    u8 pad38[0xC];
    s16 count;
    u8 pad46[0x1A0 - 0x46];
    u8 *mobys[7];
} G_424EA0;
typedef struct {
    u8 pad0[0x2C];
    s32 f2C;
    u8 pad30[0x10];
    f32 f40;
    u8 pad44[4];
    s32 f48;
} E_424EA0;
extern G_424EA0 D_L07_001E6200;
extern E_424EA0 D_L07_001E1EC0;
extern u8 *D_L07_00238870[];
extern s32 D_001D545C;
__asm__(".extern D_L07_001D6A90, 4");
extern f32 D_L07_001D6A90;
extern f32 D_L07_001D6A94;
extern f32 D_L07_001D6A98;
extern void func_L01_00423AB8(void);
extern void func_003A58C0(u8 *, s32);
extern void func_003A7AF8(void);
extern void func_L01_00404A10(void *, void *);
extern void func_L01_00451DB8(u8 *, f32 *, s32, s32, f32);
extern void func_L01_00424168(void);
extern void func_L01_00404808(void *, void *);
extern void func_L07_004249A0(s32, s32, s32);
extern void func_L03_00411F50(u8 *, s32);
extern f32 func_003824E0(f32, f32);
extern void func_003C4C18(void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern u8 *func_L01_003B1750(u8 *, void *, void *, s32, s32, s32, s32, f32, f32);
extern s32 func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                             s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);

void func_L07_00424EA0(void) {
    s32 i;
    u8 *m;
    u8 *o;
    s32 t;
    s32 j;
    vu0_v4 tmp;
    vu0_v4 v;

    func_L01_00423AB8();
    for (i = 0; i < D_L07_001E6200.count; i++) {
        m = D_L07_001E6200.mobys[i];
        if (m != 0 && *(s16 *)(m + 0xAA) == 0xE29) {
            *(u16 *)(m + 0x34) |= 0x800;
        }
        if (*(s16 *)(m + 0xAA) == 0xD54) {
            m[0x63] = 0;
            for (j = 0; D_L07_00238870[j] != 0; j++) {
                if (D_L07_00238870[j][0x63] != 0) {
                    D_L07_00238870[j][0x63] = 1;
                }
            }
            func_003A58C0(m, 0);
            func_L01_00404A10(func_003A7AF8, m);
        }
        if (m == 0) {
            continue;
        }
        t = *(s16 *)(m + 0xAA);
        if (t == 0xFA0) {
            if (*(u8 **)(m + 0x68) != 0) {
                func_L01_00451DB8(m, (f32 *)(*(u8 **)(m + 0x68) + 0xC), 0x80AAAAD2, 0x80396464, 0.07330383f);
            }
        } else if (t == 0x1DEE || t == 0x19BC) {
            func_L01_00451DB8(m, &D_L07_001D6A90, 0x80505080, 0x80404038, 0.038397245f);
        } else if (t == 0x1977) {
            func_L01_00451DB8(m, &D_L07_001D6A94, 0x8080AAAA, 0x80464646, 0.045378566f);
        } else if (t == 0x1766) {
            func_L01_00451DB8(m, &D_L07_001D6A98, 0x80AAAAFF, 0x80646496, 0.13264504f);
        } else if (t == 0x195B || t == 0x1B58 || t == 0x195C || t == 0x175A) {
            func_L01_00404808(func_L01_00424168, m);
        }
    }
    if (D_001D545C != 7) {
        return;
    }
    switch (D_L07_001E6200.mode) {
    case 1:
        func_L07_004249A0(0x3E8, 0, 3);
        if (D_L07_001E6200.timer >= 0) {
            o = D_L07_001E6200.mobys[6];
            if (o != 0) {
                func_L03_00411F50(o, 0);
                func_L03_00411F50(o, 1);
            }
        }
        break;
    case 2:
        if (D_L07_001E6200.timer >= 0) {
            o = D_L07_001E6200.mobys[3];
            if (o != 0) {
                func_L03_00411F50(o, 0);
                func_L03_00411F50(o, 1);
            }
        }
        break;
    case 4:
        if ((u32)(D_L07_001E6200.timer - 0x63D) < 0xF) {
            o = D_L07_001E6200.mobys[0];
            if (o != 0) {
                tmp = *(vu0_v4 *)(o + 0x10);
                tmp.x = tmp.x + func_003824E0(-3.5f, 3.5f);
                tmp.y = tmp.y + func_003824E0(-3.5f, 3.5f);
                tmp.z = tmp.z + 4.0f;
                func_003C4C18(&tmp, 0.1f);
                __asm__("lqc2 $vf1,%1\n\tlqc2 $vf2,%2\n\tvsub.xyz $vf2,$vf2,$vf1\n\tsqc2 $vf2,%0"
                    : "=m"(v) : "m"(tmp), "m"(*(vu0_v4 *)(o + 0x10)) : "vf1", "vf2");
                func_0038CF68(&v, &v, 1.0f);
                func_L01_003B1750(0, &tmp, &v, 0x60FF1010, 0x60DDDDDD, 0x7F1010, 0xFF1010, 0.0f, 0.65f);
            }
        }
        if ((u32)(D_L07_001E6200.timer - 0x64B) < 4) {
            tmp = *(vu0_v4 *)(D_L07_001E6200.mobys[0] + 0x10);
            tmp.z = tmp.z + 0.3f;
            func_003C4C18(&tmp, 0.1f);
            D_L07_001E1EC0.f40 = func_003824E0(0.1f, 0.2f);
            D_L07_001E1EC0.f48 = 0x21;
            D_L07_001E1EC0.f2C = 0;
            func_L01_003303B8(&tmp, 1, 0x19, 0x14, 0x14, 0x14, 0x2D, 2, 1.0f, 0.0f, 0.0f, 2.0f,
                              1, 1, 1, 0, 1, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF,
                              0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
        }
        break;
    }
}
