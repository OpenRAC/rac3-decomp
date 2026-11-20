#include "common.h"

/* declared by functions of L39_00668620.c, which this file was cut from */
typedef struct { s32 id; u8 p4[0x2CC]; s32 w2D0; u8 p2D4[0x340 - 0x2D4]; } E_665D48;
extern s32 D_L39_002461F8;
extern E_665D48 D_L39_00337700[];

/* localdecomp:start func_L39_0066ADA0 */
/* LOG: first draft 67 diff; MATCH after (a) b382 read twice instead of a local c, (b) `(Dec ^ 0x14) == 0`,
 * (c) a per-function alias D_L39_0024BB90_0066ADA0 (.extern 16) for the non-delay-slot store (retail's lui $at form). */
typedef struct Ply_0066ADA0 {
    u8 pad0[0x2D0];
    s32 w2D0;
    u8 pad2D4[0x19E6 - 0x2D4];
    u8 b19E6;
    u8 pad19E7[0x1A14 - 0x19E7];
    u8 b1A14;
    u8 pad1A15[0x24C9 - 0x1A15];
    u8 b24C9;
} Ply_0066ADA0;

typedef struct Ref_0066ADA0 {
    u8 pad0[0x382];
    u8 b382;
} Ref_0066ADA0;

typedef struct Obj_0066ADA0 {
    u8 pad0[0x23];
    u8 b23;
    u8 pad24[0x34 - 0x24];
    u16 h34;
    u8 pad36[0x68 - 0x36];
    Ref_0066ADA0 *p68;
    u8 pad6C[0xAA - 0x6C];
    s16 hAA;
} Obj_0066ADA0;

typedef struct Ent_0066ADA0 {
    u8 pad0[0x2D0];
    Obj_0066ADA0 *o2D0;
    u8 pad2D4[4];
    Ply_0066ADA0 *p2D8;
    Ply_0066ADA0 *p2DC;
    u8 pad2E0[0x340 - 0x2E0];
} Ent_0066ADA0;

typedef union Buf_0066ADA0 {
    u8 b[8];
    u32 w[2];
} Buf_0066ADA0;

extern s32 D_L39_002461F8;
extern s32 D_L39_00241118;
extern s32 D_L39_0024BB90;
extern s32 D_L39_0024BB90_0066ADA0;
__asm__(".extern D_L39_0024BB90_0066ADA0, 16");
extern u8 D_L39_004997E0[];
extern Ply_0066ADA0 *func_L39_0061BF38(s32);

void func_L39_0066ADA0(void) {
    s32 i;
    Ent_0066ADA0 *e;
    Obj_0066ADA0 *o;
    Ply_0066ADA0 *r;
    Buf_0066ADA0 buf;
    u32 a;
    u32 b;
    s32 n;
    s32 k;
    s32 m;
    s32 j;
    s32 dec;
    u8 *d;
    u8 *q;
    long t;

    D_L39_0024BB90 = 0;
    for (i = 0; i < D_L39_002461F8; i++) {
        e = (Ent_0066ADA0 *)&D_L39_00337700[i];
        if (e != 0) {
            o = e->o2D0;
            if (o != 0 && o->hAA == 0x107E) {
                if (o->p68->b382 != 0) {
                    r = func_L39_0061BF38(o->p68->b382 - 1);
                    if (r != 0 && r->b24C9 == D_L39_00241118) {
                        q = &r->b19E6;
                        if (r->w2D0 == 0 || (({
                            dec = 0;
                            t = *q;
                            if (t != 0) {
                                n = *q;
                                k = ((u32)q - n) & 7;
                                m = n + 1;
                                d = buf.b;
                                for (j = 0; j < 40; j += 5) {
                                    *d++ = D_L39_004997E0[m + ((k + j) & 7) * 255];
                                }
                                a = buf.w[0] ^ (u32)q;
                                b = buf.w[1] ^ a;
                                buf.w[0] = a;
                                buf.w[1] = b;
                                dec = b;
                            }
                            dec;
                        }) ^ 0x14) == 0) {
                            D_L39_0024BB90_0066ADA0 = 2;
                        }
                    }
                }
                if (e->p2D8 != 0 && e->p2D8->b1A14 != 0 && e->p2D8->b24C9 == D_L39_00241118) {
                    D_L39_0024BB90 = 2;
                }
                if (e->p2DC != 0 && e->p2DC->b1A14 != 0 && e->p2DC->b24C9 == D_L39_00241118) {
                    D_L39_0024BB90 = 2;
                }
                if (e->p2DC != 0 && e->p2DC->b1A14 != 0 && e->p2DC->b24C9 == D_L39_00241118) {
                    e->o2D0->b23 = 0x20;
                    e->o2D0->h34 |= 0x800;
                } else {
                    e->o2D0->b23 = 0x80;
                    e->o2D0->h34 &= 0xF7FF;
                }
            }
        }
    }
}
/* localdecomp:end func_L39_0066ADA0 */
