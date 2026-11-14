#include "common.h"

/* NTSC-U counterpart of func_L40_004142A8 (src/levels/shared/L40_004142A8.c): 0.04 -> 0.0333333; 0.0698132 -> 0.0581776 */
/* localdecomp:start func_L40_00413A70 */
#include "vu0.h"

typedef union Buf_004142A8 {
    u8 b[8];
    u32 w[2];
    u16 h[4];
} Buf_004142A8;

typedef struct Ent_004142A8 {
    u8 pad0[0x1E];
    s16 h1E;
    u8 pad20;
    s8 b21;
    u8 pad22[0x80 - 0x22];
} Ent_004142A8;

typedef struct Vars_004142A8 {
    f32 f0;
    f32 f4;
    s32 i8;
    u8 *pC;
    u8 b10;
    u8 b11;
    u8 pad12[0x20 - 0x12];
    u8 a20[0x10];
    f32 f30;
} Vars_004142A8;

typedef struct Moby_004142A8 {
    u8 pad0[0x10];
    vu0_v4 pos;
    u8 b20;
    u8 pad21[0x30 - 0x21];
    u8 b30;
    u8 pad31[0x68 - 0x31];
    Vars_004142A8 *vars;
    u8 pad6C[0x96 - 0x6C];
    u16 h96;
} Moby_004142A8;

extern u8 D_L40_003AA180[];
extern u8 D_L40_003AA181[];
extern u32 D_L40_00248048;
extern Ent_004142A8 D_L40_003C3010[];
__asm__(".extern D_L40_002417C0, 16");
extern u8 *D_L40_002417C0;
extern s32 *D_L40_002412A0;

extern s32 func_L39_005BC958(void *, s32, f32);
extern s32 func_L40_00413A30(u8 *);
extern void func_003BD360(void *);
extern void func_L01_00437350(void *, s32, void *);
extern void func_L01_00441FB8(void *, s32, s32);
extern u8 *func_L39_006197C0(s32);
extern s32 func_L39_00646268(u8 *, s32);
extern void func_L39_005F0CE0(s32, s32, void *);
extern s32 func_L01_00452EC8(u8 *);
extern void func_L01_00402498(void *, void *);
extern void func_L40_00413E90(u8 *);
extern f32 func_003BEBF8(f32 *, f32, f32);
extern void func_00389018(void *, s32, f32);
extern f32 func_003893C8(f32, f32);

void func_L40_00413A70(Moby_004142A8 *m) {
    Vars_004142A8 *v = m->vars;
    vu0_v4 sph;
    s32 r;
    s32 i;
    s32 j;
    u8 *e;

    if (m->h96 < 0x7FFD) {
        m->h96++;
    }
    sph = m->pos;
    sph.w = 2.0f;
    if (func_L39_005BC958(&sph, 0, (f32)m->b30) == -1) {
        v->i8 = 0;
        return;
    }
    r = func_L40_00413A30((u8 *)m);
    switch (m->b20) {
    case 0:
        if (*(s8 *)(D_L40_002417C0 + 0x190) == 0) {
            func_003BD360(m);
            return;
        }
        v->pC = 0;
        if (v->b11 == 0) {
            func_L01_00437350(m, 0, &v->b10);
        }
        func_L01_00441FB8(m, 1, -1);
    case 1:
        if (v->pC != 0) {
            if (*(Moby_004142A8 **)(v->pC + 0x2CC) != m) {
                v->pC = 0;
            }
        } else {
            for (i = 0; i < *D_L40_002412A0; i++) {
                e = func_L39_006197C0(i);
                if (e != 0 && *(Moby_004142A8 **)(e + 0x2CC) == m && *(s16 *)(e + 0x2DE) == 0 && r != 0) {
                    if (v->i8 == 0) {
                        v->i8 = 1;
                        for (j = 1; j < 16; j++) {
                            Ent_004142A8 *t;
                            u8 *q;
                            u8 *hk;
                            s16 h;
                            Buf_004142A8 buf;
                            u32 key;
                            s32 k;
                            s32 n;
                            s32 x;
                            s32 ii;
                            u8 *d;

                            if (func_L39_00646268(e, j)) {
                                t = &D_L40_003C3010[D_L40_003C3010[j].b21];
                            } else {
                                t = &D_L40_003C3010[j];
                    }
                    q = (u8 *)(j + (u32)e);
                    q += 0x1A52;
                    hk = q;
                    h = t->h1E;
                    if (*q == 0) {
                        *q = ++D_L40_003AA180[0];
                    } else {
                        x = *q;
                        *q = D_L40_003AA181[0];
                        D_L40_003AA181[0] = x;
                    }
                    key = ((u32 *)D_L40_003AA180)[((u32)hk * D_L40_00248048) % 418];
                    k = ((u32)q - *q) & 7;
                    buf.h[2] = h;
                    buf.w[0] = (u32)q ^ key;
                    buf.w[1] = ((buf.w[1] & 0xFFFF) | (buf.w[1] << 16)) ^ key;
                    n = *q + 1;
                    d = buf.b;
                    for (ii = 0; ii < 24; ii += 3) {
                        s32 o = ((k + ii) & 7) * 209 + n;
                        D_L40_003AA180[o] = *d++;
                    }
                }
                func_L39_005F0CE0(0, 0, m);
                func_L01_00441FB8(m, 2, -1);
                v->pC = e;
                break;
                    }
                } else {
                    v->i8 = 0;
                }
            }
        }
        break;
    case 2:
        if (func_L01_00452EC8((u8 *)m)) {
            v->f0 = 0.0f;
        }
        if (v->f0 < 0.85f) {
            func_L01_00402498(func_L40_00413E90, m);
            func_003BEBF8(&v->f0, 0.85f, 0.0333333351f);
        } else {
            func_L01_00441FB8(m, 1, -1);
        }
        break;
    }
    v->f30 = r ? 1.0f : 0.0f;
    func_00389018(v->a20, 2, v->f4);
    v->f4 = func_003893C8(v->f4, 0.0581776462f);
}
/* localdecomp:end func_L40_00413A70 */
