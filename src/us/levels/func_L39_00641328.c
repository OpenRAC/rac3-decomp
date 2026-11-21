#include "common.h"

/* NTSC-U counterpart of func_L39_00643B98 (src/levels/shared/L39_006439E0.c) */
/* localdecomp:start func_L39_00641328 */
typedef int u128_t __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_00643B98;
typedef union { u8 b[8]; u32 w[2]; } Buf_00643B98;
typedef struct {
    u8 pad0[0x34];
    u8 f34;
    u8 pad35[0x78 - 0x35];
    s32 f78;
} Obj_00643B98;
typedef struct {
    u8 pad0[0x450];
    Obj_00643B98 *obj;
    u8 pad454[0x470 - 0x454];
    s32 f470;
    u8 pad474[4];
    s32 f478;
    f32 f47C;
    u8 pad480[0x19E4 - 0x480];
    u8 b19E4;
    u8 pad19E5[0x1A07 - 0x19E5];
    u8 b1A07;
} G_00643B98;

extern u8 D_L39_004998A0[];
extern f32 func_00389380(f32, f32);
extern f32 func_00388978(f32);
extern s32 func_003894A0(s32, s32, f32);
extern void func_L01_0046CA58(void *, s32, s32, s32, s32, s32, f32, f32, s32, s32, f32, s32, s32);

static __inline__ s32 Dec_00643B98(u8 *q) {
    Buf_00643B98 buf;
    
    u8 *d;
    long t;
    s32 x = 0;
    s32 n;
    s32 m;
    s32 k;
    s32 i;

    t = *q;
    if (t != 0) {
        n = *q;
        m = n + 1;
        k = ((s32)q - n) & 7;
        d = buf.b;
        for (i = 0; i < 40; i += 5) {
            *d++ = D_L39_004998A0[m + ((k + i) & 7) * 255];
        }
        buf.w[0] ^= (u32)q;
        buf.w[1] ^= buf.w[0];
        x = buf.w[1];
    }
    return x;
}

static __inline__ s32 DecEq_00643B98(u8 *q, s32 v) {
    return Dec_00643B98(q) == v;
}

void func_L39_00641328(u8 *a0) {
    G_00643B98 *a = (G_00643B98 *)a0;
    Obj_00643B98 *obj;
    s32 color;

    if (a->obj != 0 && !DecEq_00643B98(&a->b19E4, 0x63)) {
        obj = a->obj;
        if ((obj->f34 ^ 1) & 1) {
            if (a->f470 >= 0x17) {
                V4_00643B98 vec;
                V4_00643B98 unused;
                color = a->f470 - 15;
                if (color > 0x40) color = 0x40;
                if (color < 0) color = 0;
                color = (color << 24) | 0xFFFFFF;
                switch (a->f478) {
                case 5:
                    a->f47C = func_00389380(a->f47C, 0.05235988274f);
                    obj->f78 = func_003894A0(0xFF00FFFF, 0xFF104080, func_00388978(a->f47C) * 0.5f + 0.5f);
                    *(u128_t *)&vec = 0;
                    vec.x = 0.333f;
                    vec.y = -0.05f;
                    func_L01_0046CA58(&vec, (s32)obj, obj->f78 & 0x35FFFFFF, -1, 1, 2, 73500.0f, 0.15f, 0, -1, 1.0f, 0, 0);
                    break;
                case 1:
                    *(u128_t *)&vec = 0;
                    vec.x = 0.195f;
                    vec.y = -0.317f;
                    if (a->b1A07 != 0) {
                        s32 r, m;
                        a->f47C = func_00389380(a->f47C, 0.11635529f);
                        r = func_003894A0(obj->f78, func_003894A0(0xFF0040FF, 0xFF10BEBE, func_00388978(a->f47C) * 0.5f + 0.5f), 0.22f);
                        obj->f78 = r;
                        m = 0x32FFFFFF;
                        if (color < m) m = color;
                        func_L01_0046CA58(&vec, (s32)obj, r & m, -1, 1, 2, 50400.0f, 0.15f, 0, -1, 1.0f, 0, 0);
                    } else {
                        s32 r, m;
                        a->f47C = func_00389380(a->f47C, 0.040724352f);
                        r = func_003894A0(obj->f78, func_003894A0(0xFF0028C8, 0xFF10B4B4, func_00388978(a->f47C) * 0.5f + 0.5f), 0.15f);
                        obj->f78 = r;
                        m = 0x38FFFFFF;
                        if (color < m) m = color;
                        func_L01_0046CA58(&vec, (s32)obj, r & m, -1, 1, 2, 50400.0f, 0.15f, 0, -1, 1.0f, 0, 0);
                    }
                    break;
                case 2:
                    a->f47C = func_00389380(a->f47C, 0.0581776462f);
                    obj->f78 = func_003894A0(0xFFDFDFDF, 0xFF20205F, func_00388978(a->f47C) * 0.5f + 0.5f);
                    break;
                case 4:
                    break;
                }
            }
        }
    }
}
/* localdecomp:end func_L39_00641328 */
