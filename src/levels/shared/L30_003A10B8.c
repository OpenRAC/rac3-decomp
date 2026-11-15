#include "common.h"

typedef int u128_t __attribute__((mode(TI)));
typedef union { u128_t q; f32 f[4]; } Vec4;

/* localdecomp:start func_L30_003A10B8 */
typedef struct { u8 pad0[0x100]; f32 x100; u8 pad1[0x35C - 0x104]; u8 *x35C; s32 x360; } S_003A10B8;
extern S_003A10B8 D_001A4BE0;
extern f32 D_L30_001E2258 __attribute__((section(".data")));
extern f32 D_L30_001DE880;
extern f32 func_0038DBA0(f32, f32);
void func_L30_003A10B8(u8 *a0) {
    S_003A10B8 *h = &D_001A4BE0;
    if (h->x35C == a0 && h->x360 != 0) {
        if (func_0038DBA0(*(f32 *)(a0 + 0xF8), D_L30_001E2258) < 1.5707964f) {
            h->x100 = D_L30_001DE880 * 0.020000001f;
        } else {
            h->x100 = -(D_L30_001DE880 * 0.020000001f);
        }
    }
}
/* localdecomp:end func_L30_003A10B8 */

/* localdecomp:start func_L30_003A1150 */
#include "vu0.h"
typedef struct S_003A1150h {
    Vec4 dir;
    void *src;
    u32 flags;
    u8 b28;
    u8 b29;
    s16 h2A;
    f32 damage;
    u8 pad30[0x10];
} S_003A1150h;

typedef struct S_003A1150t {
    u8 pad0[0x12];
    s16 count;
    u8 pad14[0x20 - 0x14];
    s32 *list;
} S_003A1150t;


typedef struct S_003A1150o {
    u8 pad0[0x30];
    f32 x;
    f32 y;
    f32 z;
} S_003A1150o;

typedef struct S_003A1150p {
    u8 pad0[0x1DC];
    s16 h1DC;
    u8 pad1DE[0x25C0 - 0x1DE];
    u8 *body;
    s32 state;
} S_003A1150p;

extern s32 D_001D545C;
extern u8 *D_L30_001DF3CC;
extern u8 *D_L30_001DF800;
extern u8 *D_L30_001DF728;
__asm__(".extern D_L30_001DF728, 4");
extern void func_L01_004450F0(void *, s32, s32);
extern f32 func_L30_0034CE78(u8 *);
extern f32 func_0038CEA8(void *);
extern void func_L30_004CF4B0(s32, s32);
extern void func_L01_00446978(void *, void *);
extern s32 func_003A52A0(s32, s32, void *);

void func_L30_003A1150(u8 *a0) {
    u8 *v;
    u8 *m;
    u8 *next;
    Vec4 pos;
    S_003A1150h hit;
    S_003A1150t *t;
    S_003A1150o *e;
    s32 i;
    f32 r;
    f32 a;
    f32 b;
    f32 d;
    f32 dx;
    f32 dz;
    s32 s;

    v = *(u8 **)(a0 + 0x68);
    switch (a0[0x20]) {
    case 0:
        a0[0x30] = 0xFF;
        func_L01_004450F0(a0, 1, -1);
        break;
    case 1:
        hit.src = a0;
        hit.flags = 0x10001;
        if (*(s32 *)(v + 8) == 1) {
            hit.flags = 0x110001;
        }
        if (*(s32 *)(v + 8) == 2) {
            hit.flags |= 0x400000;
        }
        if (*(s32 *)(v + 4) == -1) {
            hit.damage = 1000.0f;
        } else {
            hit.damage = *(s32 *)(v + 4);
        }
        hit.b28 = 3;
        hit.b29 = 2;
        hit.h2A = *(u16 *)(a0 + 0xAA);
        qzero(&hit.dir);
        t = (S_003A1150t *)(D_L30_001DF3CC + (*(s32 *)v * 0x30 + 0x20));
        m = ((S_003A1150p *)&D_001A4BE0)->body;
        while (m != 0) {
            if ((*(u8 **)(m + 0x24) != 0 && *(*(u8 **)(m + 0x24) + 0x46) == 5) || m == ((S_003A1150p *)&D_001A4BE0)->body) {
                if (m[0x20] == 0x42 || m[0x20] == 0xFF) {
                    goto next;
                }
                r = func_L30_0034CE78(m);
                pos.q = *(u128_t *)(m + 0x10);
                pos.f[2] += r;
                for (i = 0; i < t->count; i++) {
                    e = (S_003A1150o *)(D_L30_001DF800 + t->list[i] * 128);
                    a = func_0038CEA8(e);
                    b = func_0038CEA8((u8 *)e + 0x20);
                    if (e->x < *(f32 *)(m + 0x10)) {
                        d = pos.f[0] - (e->x + a);
                        dx = 0.0f;
                    } else {
                        d = (e->x - a) - pos.f[0];
                        dx = 0.0f;
                    }
                    if (0.0f < d) {
                        dx = d;
                    }
                    if (r < dx) {
                        continue;
                    }
                    if (e->z < *(f32 *)(m + 0x18)) {
                        d = pos.f[2] - (e->z + b);
                        dz = 0.0f;
                    } else {
                        d = (e->z - b) - pos.f[2];
                        dz = 0.0f;
                    }
                    if (0.0f < d) {
                        dz = d;
                    }
                    if (dz * dz + dx * dx < r * r) {
                        if (*(s32 *)(v + 4) == -1) {
                            if (*(s16 *)(m + 0xAA) == *(s16 *)(((S_003A1150p *)&D_001A4BE0)->body + 0xAA)) {
                                func_L30_004CF4B0(0x9F, 1);
                            }
                            func_L01_00446978(m, &hit);
                        } else {
                            func_L01_00446978(m, &hit);
                        }
                        if (D_001D545C == 0x22 && m == ((S_003A1150p *)&D_001A4BE0)->body) {
                            s = ((S_003A1150p *)&D_001A4BE0)->state;
                            if (s != 0x9E && s != 0xAC && s != 0x9F) {
                                func_003A52A0(0x1E, 0, m);
                                if (((S_003A1150p *)&D_001A4BE0)->h1DC != 0) {
                                    func_L30_004CF4B0(0xAC, 1);
                                }
                            }
                        }
                    }
                }
            }
        next:
            if (m != ((S_003A1150p *)&D_001A4BE0)->body) {
                next = *(u8 **)(m + 0x28);
            } else {
                next = D_L30_001DF728;
            }
            m = next;
        }
        break;
    }
}
/* localdecomp:end func_L30_003A1150 */
