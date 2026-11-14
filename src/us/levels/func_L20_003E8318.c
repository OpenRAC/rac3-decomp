#include "common.h"

/* NTSC-U counterpart of func_L20_003EA258 (src/levels/20_final_boss/L20_003E6150.c) */
#include "vu0.h"

/* localdecomp:start func_L20_003E8318 */
extern f32 D_001DF27C_sda;
__asm__(".extern D_001DF27C_sda, 4");
extern f32 D_001DF280_sda;
__asm__(".extern D_001DF280_sda, 4");
extern s32 D_L20_001D66B0;
__asm__(".extern D_L20_001D66B0, 16");
extern void func_L20_003E8548(void *);
extern void func_L01_004A6DF8(void *, s32);
extern void func_003BD360(void *);
extern void func_L01_00402498(void (*)(void *), void *);
extern u8 *func_0037E0B8(s32);
extern void func_L01_00443628(void *, void *, s32, void *, f32);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern f32 func_00389380(f32, f32);
extern s32 func_003CE740(void *, void *, s32, void *, void *);

void func_L20_003E8318(u8 *obj) {
    u8 buf[0x30];
    vu0_v4 q;
    vu0_v4 r;
    u8 *vars;
    u8 *e;
    f32 ang;
    f32 k;
    f32 sc;
    s32 i;

    vars = *(u8 **)(obj + 0x68);
    switch (obj[0x20]) {
    case 0:
        *(vu0_q *)vars = *(vu0_q *)(obj + 0x10);
        obj[0x20] = 3;
        *(s32 *)(vars + 0x18) = 0x14;
        break;
    case 3:
        *(s32 *)(obj + 0x98) = 0;
        *(u16 *)(obj + 0x34) = (*(u16 *)(obj + 0x34) | 0x41) & 0xEFFF;
        func_L01_004A6DF8(obj, 1);
        if (*(f32 *)(vars + 0x1C) > D_001DF27C_sda) {
            func_003BD360(obj);
            return;
        }
        func_L01_00402498(func_L20_003E8548, obj);
        k = D_001DF280_sda * 0.016666668f;
        *(f32 *)(vars + 0x1C) = *(f32 *)(vars + 0x1C) + k;
        *(f32 *)(vars + 0x20) = *(f32 *)(vars + 0x20) + k;
        sc = 2.0f;
        if (*(s32 *)(obj + 0xB8) != 0) {
            e = func_0037E0B8(*(s32 *)(obj + 0xB8));
            if (e != 0) {
                sc = (f32)e[0x16];
            }
        }
        func_L01_00443628(buf, obj, 0x08000001, &D_L20_001D66B0, sc);
        ang = 0.0f;
        q.x = func_00388960(ang) * *(f32 *)(vars + 0x1C);
        q.y = func_00388978(ang) * *(f32 *)(vars + 0x1C);
        q.z = 0.0f;
        ang = 0.5235988f;
        vec_add_ba(&q, &q, obj + 0x10);
        for (i = 11; i >= 0; i--) {
            r.x = func_00388960(ang) * *(f32 *)(vars + 0x1C);
            r.y = func_00388978(ang) * *(f32 *)(vars + 0x1C);
            r.z = 0.0f;
            vec_add_ba(&r, &r, obj + 0x10);
            func_003CE740(&q, &r, 9, obj, buf);
            ang = func_00389380(ang, 0.5235988f);
            q = r;
        }
        break;
    }
}
/* localdecomp:end func_L20_003E8318 */
