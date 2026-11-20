#include "common.h"

/* localdecomp:start func_L40_004142A8 */
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

extern u8 D_L40_003AA040[];
extern u8 D_L40_003AA041[];
extern u32 D_L40_00247EC8;
extern Ent_004142A8 D_L40_003C2ED0[];
__asm__(".extern D_L40_00241640, 16");
extern u8 *D_L40_00241640;
extern s32 *D_L40_00241120;

extern s32 func_L39_005BE900(void *, s32, f32);
extern s32 func_L40_00414268(u8 *);
extern void func_003C2880(void *);
extern void func_L01_0043A430(void *, s32, void *);
extern void func_L01_004450F0(void *, s32, s32);
extern u8 *func_L39_0061BF38(s32);
extern s32 func_L39_00648AE0(u8 *, s32);
extern void func_L39_005F33E0(s32, s32, void *);
extern s32 func_L01_004561B8(u8 *);
extern void func_L01_00404808(void *, void *);
extern void func_L40_004146C8(u8 *);
extern f32 func_003C4138(f32 *, f32, f32);
extern void func_0038D750(void *, s32, f32);
extern f32 func_0038DB00(f32, f32);

void func_L40_004142A8(Moby_004142A8 *m) {
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
    if (func_L39_005BE900(&sph, 0, (f32)m->b30) == -1) {
        v->i8 = 0;
        return;
    }
    r = func_L40_00414268((u8 *)m);
    switch (m->b20) {
    case 0:
        if (*(s8 *)(D_L40_00241640 + 0x190) == 0) {
            func_003C2880(m);
            return;
        }
        v->pC = 0;
        if (v->b11 == 0) {
            func_L01_0043A430(m, 0, &v->b10);
        }
        func_L01_004450F0(m, 1, -1);
    case 1:
        if (v->pC != 0) {
            if (*(Moby_004142A8 **)(v->pC + 0x2CC) != m) {
                v->pC = 0;
            }
        } else {
            for (i = 0; i < *D_L40_00241120; i++) {
                e = func_L39_0061BF38(i);
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

                            if (func_L39_00648AE0(e, j)) {
                                t = &D_L40_003C2ED0[D_L40_003C2ED0[j].b21];
                            } else {
                                t = &D_L40_003C2ED0[j];
                    }
                    q = (u8 *)(j + (u32)e);
                    q += 0x1A52;
                    hk = q;
                    h = t->h1E;
                    if (*q == 0) {
                        *q = ++D_L40_003AA040[0];
                    } else {
                        x = *q;
                        *q = D_L40_003AA041[0];
                        D_L40_003AA041[0] = x;
                    }
                    key = ((u32 *)D_L40_003AA040)[((u32)hk * D_L40_00247EC8) % 418];
                    k = ((u32)q - *q) & 7;
                    buf.h[2] = h;
                    buf.w[0] = (u32)q ^ key;
                    buf.w[1] = ((buf.w[1] & 0xFFFF) | (buf.w[1] << 16)) ^ key;
                    n = *q + 1;
                    d = buf.b;
                    for (ii = 0; ii < 24; ii += 3) {
                        s32 o = ((k + ii) & 7) * 209 + n;
                        D_L40_003AA040[o] = *d++;
                    }
                }
                func_L39_005F33E0(0, 0, m);
                func_L01_004450F0(m, 2, -1);
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
        if (func_L01_004561B8((u8 *)m)) {
            v->f0 = 0.0f;
        }
        if (v->f0 < 0.85f) {
            func_L01_00404808(func_L40_004146C8, m);
            func_003C4138(&v->f0, 0.85f, 0.040000003f);
        } else {
            func_L01_004450F0(m, 1, -1);
        }
        break;
    }
    v->f30 = r ? 1.0f : 0.0f;
    func_0038D750(v->a20, 2, v->f4);
    v->f4 = func_0038DB00(v->f4, 0.06981318f);
}
/* localdecomp:end func_L40_004142A8 */

/* localdecomp:start func_L40_004146C8 */
typedef struct {
    f32 x, y, z, w;
} V4_004146C8 __attribute__((aligned(16)));

typedef struct {
    f32 u, v;
} UV_004146C8;

typedef struct {
    V4_004146C8 pos[4];
    u32 col[4];
    UV_004146C8 uv[4];
    unsigned long a70;
    unsigned long a78;
    unsigned long a80;
    unsigned long a88;
} Q_004146C8;

typedef int U128_004146C8 __attribute__((mode(TI)));
extern void func_0038D570(void *, void *);
extern void func_0038D308(void *, void *);
extern s32 func_0038DBD8(s32, s32, f32);
extern unsigned long func_L39_00589890(s32);
extern void func_L04_0041AE18(void *, s32, void *, s32, void *);

__asm__(".extern D_L40_002474C0, 4");
__asm__(".extern D_L40_002474C4, 4");
__asm__(".extern D_L40_002474C8, 4");
__asm__(".extern D_L40_002474CC, 4");
__asm__(".extern D_L40_002474D0, 4");
__asm__(".extern D_L40_00247500, 4");
__asm__(".extern D_L40_00247508, 4");
extern s32 D_L40_002474C0;
extern s32 D_L40_002474C4;
extern s32 D_L40_002474C8;
extern s32 D_L40_002474CC;
extern s32 D_L40_002474D0;
__asm__(".extern D_L40_002474D8, 8");
__asm__(".extern D_L40_002474E0, 8");
extern u32 D_L40_002474D8[] __attribute__((section(".sdata")));
extern UV_004146C8 D_L40_002474E0[] __attribute__((section(".sdata")));
extern f32 D_L40_00247500;
extern f32 D_L40_00247508;
extern f32 D_L40_00247ED8;

static __inline__ f32 max_004146C8(f32 x, f32 lo) {
    if (x < lo) {
        x = lo;
    }
    return x;
}

/* from func_L40_00435388 (L40_00434DA8.c): the same code with this function's data */
void func_L40_004146C8(u8 *a0) {
    Q_004146C8 q[4];
    V4_004146C8 m[4];
    V4_004146C8 r[3];
    V4_004146C8 rot;
    f32 *t = *(f32 **)(a0 + 0x68);
    f32 a, b, c, d;
    s32 k;

    func_0038D570(m, a0 + 0xC0);
    m[3] = *(V4_004146C8 *)(a0 + 0x10);
    for (k = 0; k < 4; k++) {
        q[k].a78 = func_L39_00589890(D_L40_002474D0);
        q[k].a80 = 0xFF9000000260UL;
        q[k].a70 = 0;
        q[k].a88 = (long)D_L40_002474C0 | ((long)D_L40_002474C4 << 2) | ((long)D_L40_002474C8 << 4) |
                    ((long)D_L40_002474CC << 6) | 0x8000000000UL;
    }

    a = (0.85f - *t) * 2.0f;
    b = 0.15f;
    if (a > 1.0f) {
        a = 1.0f;
    } else if (a < 0.0f) {
        a = 0.0f;
    }
    if (*t < 1.15f) {
        c = max_004146C8(1.15f - *t, 0.0f);
        d = max_004146C8((0.2f - *t) / 0.2f, 0.0f);
        D_L40_00247ED8 = d;
        b = c + 0.15f;
    }

    {
        s32 i, j;
        f32 x;

        for (i = 0; i < 4; i++) {
            for (j = 0; j < 4; j++) {
                q[i].uv[j].u = D_L40_002474E0[j].u;
                q[i].uv[j].v = D_L40_002474E0[j].v;
                q[i].col[j] = D_L40_002474D8[i != 0];
                q[i].col[j] = func_0038DBD8(q[i].col[j] & 0xFFFFFF, q[i].col[j], a);
                __asm__("sqc2 $vf0, %0" : "=m"(*(U128_004146C8 *)&q[i].pos[j]));
                q[i].pos[j].x = x = *t + (i != 0 ? 0.01f : 0.0f);
                if (j & 1) {
                    switch (i) {
                    case 0:
                        q[i].pos[j].z += D_L40_00247500 + b;
                        break;
                    case 1:
                        q[i].pos[j].z += D_L40_00247500 + D_L40_00247508;
                        break;
                    case 2:
                        q[i].pos[j].z += D_L40_00247500 - b * 0.8f + D_L40_00247508;
                        break;
                    case 3:
                        q[i].pos[j].z += D_L40_00247500 + b * 0.8f + D_L40_00247508;
                        break;
                    }
                } else {
                    switch (i) {
                    case 0:
                        q[i].pos[j].z += D_L40_00247500 - b;
                        break;
                    case 1:
                        q[i].pos[j].z += D_L40_00247500 - D_L40_00247508;
                        break;
                    case 2:
                        q[i].pos[j].z += D_L40_00247500 - b * 0.8f - D_L40_00247508;
                        break;
                    case 3:
                        q[i].pos[j].z += D_L40_00247500 + b * 0.8f - D_L40_00247508;
                        break;
                    }
                }
            }
        }
    }

    *(U128_004146C8 *)&rot = 0;
    rot.z = 0.19634954f;
    func_0038D308(r, &rot);
    func_L04_0041AE18(q, 4, r, 0x20, m);
}
/* localdecomp:end func_L40_004146C8 */
