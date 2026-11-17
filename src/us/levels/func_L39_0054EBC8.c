#include "common.h"

/* NTSC-U counterpart of func_L39_0054F4E0 (src/levels/shared/L39_0054D5F8.c) */
#include "vu0.h"
extern void func_00388830(void *, void *, f32);
#include "vu0.h"
extern u8 D_L39_00242AB0[] __attribute__((section(".sdata")));
#include "vu0.h"
extern void func_00388830(void *, void *, f32);
#include "vu0.h"

/* localdecomp:start func_L39_0054EBC8 */
#include "vu0.h"

typedef struct {
    u8 pad0[0x21];
    s8 b21;
    u8 pad1[0x24 - 0x22];
    f32 f24;
    u8 pad2[0x30 - 0x28];
    f32 f30;
    u8 pad3[0x80 - 0x34];
} Ent_0054F4E0;

extern Ent_0054F4E0 D_L39_0049C950[];
extern u8 D_L39_004998A0[];
extern u8 D_L39_0025F860[];
__asm__(".extern D_L39_00242AB0, 16");
extern u8 D_L39_00242AB0[] __attribute__((section(".sdata")));
extern s32 func_L39_0059CE28(void *, s32, f32, f32);
extern s32 func_L39_00646268(u8 *, s32);
extern void func_L01_00443648(void *, void *, s32, f32, f32, f32, s32, s32, s32);
extern void func_00388830(void *, void *, f32);
extern s32 func_003CE740(void *, void *, s32, void *, s32);
extern f32 func_00388770(void *);
extern u8 *func_L39_0054FDD8(void *, void *, void *, s32, s32, s32, s32);
extern void func_003BDA38(void *, s32, void *);
extern void func_0037E2F0(void *, f32, f32);
extern s32 func_L39_005B24C8(s32, s32);
extern void func_L01_004708F8(void *, void *, s32, f32, f32, f32, f32, s32, s32, s32, s32);
extern u8 *func_L01_00467DA8(void *, s32, f32, f32, s32, s32, s32, void *, f32, s32);
extern u8 *func_L01_0046D570(u8 *position, s32 life, f32 size, f32 start_size, s32 colour, s32 a3, s32 spin,
                             void *velocity, s32 t2, s32 t3, s16 arg8, s32 arg9);

void func_L39_0054EBC8(u8 *self, u8 *pos, s32 a2, s32 a3, s32 a4) {
    vu0_v4 dir;
    vu0_v4 tmp;
    u8 *obj;
    u8 *o;
    u8 *p;
    u8 *r;
    s32 x;
    s32 i;
    s32 j;

    obj = *(u8 **)(self + 0x68);
    o = *(u8 **)(obj + 0x3C);
    *(s32 *)(obj + 0x10) = func_L39_0059CE28(pos, 0xFF0000FF, 10.0f, 0.0f);
    *(s32 *)(obj + 0x14) = 0x1E;
    {
        s32 id = 3;
        Ent_0054F4E0 *e;

        if (func_L39_00646268(o, id)) {
            e = &D_L39_0049C950[D_L39_0049C950[id].b21];
        } else {
            e = &D_L39_0049C950[id];
        }
        func_L01_00443648(self, pos, 0x110001, 0.3f, e->f30, 1.0f, 0, 1, 0);
    }
    {
        s32 id = 3;
        Ent_0054F4E0 *e;

        if (func_L39_00646268(o, id)) {
            e = &D_L39_0049C950[D_L39_0049C950[id].b21];
        } else {
            e = &D_L39_0049C950[id];
        }
        func_00388830(&dir, obj + 0x40, e->f24 * 0.0166666675f);
    }
    p = o + 0x19E4;
    if (o[0x1A14] != 0 && (({
            u8 *b;
            s32 n;
            s32 m;
            s32 k;
            s32 v;

            if (o[0x19E4] == 0) {
                v = 0;
            } else {
                n = o[0x19E4];
                m = n + 1;
                k = ((s32)p - n) & 7;
                b = (u8 *)&tmp;
                for (i = 0; i < 40; i += 5) {
                    *b++ = D_L39_004998A0[m + ((k + i) & 7) * 255];
                }
                ((u32 *)&tmp)[0] ^= (u32)(o + 0x19E4);
                ((u32 *)&tmp)[1] ^= ((u32 *)&tmp)[0];
                v = ((u32 *)&tmp)[1];
            }
            v;
        }) ^ 0x1D) == 0) {
        r = func_L39_0054FDD8(pos, &dir, *(void **)(obj + 0x3C), a2, 1, a3, 0);
        if (r) {
            *(u8 **)(r + 0xB8) = self;
        }
    } else {
        if (func_003CE740(self + 0x10, pos, 0, *(void **)(*(u8 **)(obj + 0x3C) + 0x424), 0)) {
            a4 = 0;
            vec_sub_ba(&tmp, D_L39_0025F860, self + 0x10);
            func_00388830(&tmp, &tmp, func_00388770(&tmp) - 0.05f);
            vec_add_ba(pos, &tmp, self + 0x10);
        }
        r = func_L39_0054FDD8(pos, &dir, *(void **)(obj + 0x3C), a2, 0, a3, a4);
        if (r) {
            *(u8 **)(r + 0xB8) = self;
        }
    }
    {
        u8 *b;
        s32 n;
        s32 m;
        s32 k;

        if (o[0x19E4] == 0) {
            x = 0;
        } else {
            n = o[0x19E4];
            m = n + 1;
            k = ((s32)p - n) & 7;
            b = (u8 *)&tmp;
            for (i = 0; i < 40; i += 5) {
                *b++ = D_L39_004998A0[m + ((k + i) & 7) * 255];
            }
            ((u32 *)&tmp)[0] ^= (u32)p;
            ((u32 *)&tmp)[1] ^= ((u32 *)&tmp)[0];
            x = ((u32 *)&tmp)[1];
        }
    }
    if ((x ^ 0x1D) != 0 || o[0x1A14] == 0) {
        vu0_v4 vel;

        func_003BDA38(self, 0, &tmp);
        for (j = 0; j < 10; j++) {
            func_0037E2F0(&vel, 0.0833333358f, 0.166666672f);
            func_L01_004708F8(&tmp, &vel, func_L39_005B24C8(10, 25), 0.075f, 0.25f, 0.5f, 0.5f,
                              0x80408020, 0xFF00, 0, 0);
        }
        func_L01_00467DA8(&tmp, 0xE, 3.5f, 0.1f, 0xBF408020, 2, 1, D_L39_00242AB0, 0.0f, 1);
        func_L01_00467DA8(&tmp, 0xE, 2.5f, 0.1f, 0xBF406020, 2, -1, D_L39_00242AB0, 0.0f, 1);
        func_L01_00467DA8(&tmp, 0xE, 1.75f, 0.1f, 0xC0FFFFFF, 2, 1, D_L39_00242AB0, 0.0f, 1);
        func_L01_00467DA8(&tmp, 0xE, 1.25f, 0.1f, 0xB0FFFFFF, 2, -1, D_L39_00242AB0, 0.0f, 1);
        func_L01_0046D570((u8 *)&tmp, 0x14, 0.71999997f, 0.56f, 0x46787878, 2, 2, D_L39_00242AB0, 0, 2, 6, 1);
        func_L01_0046D570((u8 *)&tmp, 0x14, 1.36f, 0.56f, 0x46787878, 2, -1, D_L39_00242AB0, 1, 2, 6, 1);
        func_L01_0046D570((u8 *)&tmp, 0x14, 1.6f, 1.2f, 0x2D787878, 2, 1, D_L39_00242AB0, 1, 2, 6, 1);
    }
}
/* localdecomp:end func_L39_0054EBC8 */
