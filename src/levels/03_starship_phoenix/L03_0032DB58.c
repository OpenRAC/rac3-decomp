#include "common.h"

/* localdecomp:start func_L03_0032DB58 */
typedef struct S_0032DB58 {
    char pad0[0x1A];
    short h;
    unsigned char b1C;
    unsigned char b1D;
} S_0032DB58;
void *func_L03_0032F6A8();
extern int D_001DCF28_sda[2];
__asm__(".extern D_001DCF28_sda, 8");

int func_L03_0032DB58(void) {
    S_0032DB58 *s = func_L03_0032F6A8();
    int v = D_001DCF28_sda[s->b1D];
    if (v == -1) return 1;
    if ((unsigned)(s->b1C - 2) < 2) return 1;
    if (s->h != -1) return s->h < v;
    return 0;
}
/* localdecomp:end func_L03_0032DB58 */

/* localdecomp:start func_L03_0032DBC0 */
s32 func_L03_0032DBC0(void) {
    return 0x10001;
}
/* localdecomp:end func_L03_0032DBC0 */

/* localdecomp:start func_L03_0032DBD0 */
void *func_L03_0032F6A8();

s32 func_L03_0032DBD0(s32 arg0, s32 arg1) {
    return (((*(u8 *)((u8 *)(func_L03_0032F6A8()) + 0x1C)) ^ 3) == 0) ? arg1 : 0xA;
}
/* localdecomp:end func_L03_0032DBD0 */

/* localdecomp:start func_L03_0032DC08 */
#include "vu0.h"
extern f32 func_0038CE68(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038CF38(void *, void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DB00(f32, f32);
extern f32 func_0038DAB8(f32, f32);

f32 func_L03_0032DC08(void *arg0, void *arg1, f32 ang, f32 *c) {
    u8 *a = arg0;
    u8 *b = arg1;
    vu0_v4 d;
    vu0_v4 t;
    f32 k;
    f32 a1;
    f32 dist;
    vec_sub_ab(&d, c, b + 0x10);
    if (func_0038CE68(&d, &d) < 0.1f) return ang;
    func_0038CF68(&d, &d, 2.0f);
    vec_add_ba(&t, b + 0x10, &d);
    dist = func_0038CF38(a + 0x10, &t);
    if (dist > 20.0f) {
        k = (20.0f - dist) * 0.5f;
        if (k > 0.0f) {
            k = 0.0f;
        } else if (k < 1.0f) {
            k = 1.0f;
        }
        a1 = func_0038D160(*(f32 *)(b + 0x10) - *(f32 *)(a + 0x10), *(f32 *)(b + 0x14) - *(f32 *)(a + 0x14));
        if (func_0038DB00(func_0038D160(c[0] - *(f32 *)(a + 0x10), c[1] - *(f32 *)(a + 0x14)), a1) > 0.0f) {
            return func_0038DAB8(ang, k * 1.5707964f);
        }
        return func_0038DB00(ang, k * 1.5707964f);
    }
    return ang;
}
/* localdecomp:end func_L03_0032DC08 */

/* localdecomp:start func_L03_0032DDC8 */
typedef int u128_t __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_0032DDC8;
extern f32 D_001DD128_sda;
__asm__(".extern D_001DD128_sda, 4");
extern u8 D_L03_001D66B0;
__asm__(".extern D_L03_001D66B0, 16");
extern s32 func_L01_003303B8(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
    s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 func_L03_0043FC00(s32, s32, u8 *, s32, s32, f32, f32, f32, f32, s32, f32, f32, s32, s32, f32);

void func_L03_0032DDC8(u8 *a, s32 b, s32 c) {
    V4_0032DDC8 v;
    u8 *state = *(u8 **)(a + 0x68);
    v = *(V4_0032DDC8 *)(a + 0x10);
    v.z += *(f32 *)(state + 0x40);
    func_L01_003303B8((u8 *)&v, 0, 15, 0, 15, 12, 0, 0, D_001DD128_sda, 0.0f, 0.0f, 0.0f,
        0, 1, 0, 0, 0, 0, 0, 0, 0x804020, 0x804020, 0x804020, 0x804020, 0x804020, 0x804020, 0x804020, 0x806020, 0x807020, 0);
    func_L03_0043FC00((s32)a, b, &D_L03_001D66B0, 3, c, 3.0f, 6.0f, 3.0f, 6.0f, 255, -1.0f, -1.0f, 180, 0, 0.4f);
}
/* localdecomp:end func_L03_0032DDC8 */

/* localdecomp:start func_L03_0032DF10 */
void *func_L03_0032F6A8();
void func_L01_004443E8(void *, s32, s32);
void func_L03_0032F6F8(s32, void *);

void func_L03_0032DF10(void *arg0) {
    void *p;

    p = func_L03_0032F6A8(arg0);
    if (p != 0) {
        func_L01_004443E8(arg0, 0, 3);
        func_L03_0032F6F8(*(s32 *)((u8 *)p + 0x8), arg0);
    }
}
/* localdecomp:end func_L03_0032DF10 */

/* localdecomp:start func_L03_0032DF60 */
/* near miss (level 3, Starship Phoenix): 11 differences: the shape and every other register match (the for loop over three entries with the func_L03_0032EB30 style walk); retail reads the loop-entry copy of the D_001DF9D8 limit with lui/lw and the back-edge copy through $gp (0x3128), the C uses $gp in both, shifting four instructions around the entry test; splitting the entry guard gives 71-92 diffs */

extern u16 *D_L03_0021C620[];
extern u8 *D_L03_001DF99C;
__asm__(".extern D_L03_001DF99C, 16");
extern s32 D_L03_001DF9D8;
extern int func_L01_0044C078(void *, int);
void func_L03_0032DF10(void *arg0);

typedef struct S_0032DF60 {
    char pad0[0xA8];
    int idx[3];
    char padB4[0x10];
    int arg;
} S_0032DF60;

void func_L03_0032DF60(void *a) {
    int i;
    S_0032DF60 *p = *(S_0032DF60 **)((char *)a + 0x68);
    for (i = 0; i < 3; i++) {
        short *cur = (short *)D_L03_0021C620[p->idx[i]];
        while ((p->idx[i] & 0xFF) != 0xFF && D_L03_001DF9D8 >= p->idx[i] && cur != 0 &&
               (cur[-1] >= 0 || cur == (short *)D_L03_0021C620[p->idx[i]])) {
            u8 *buf = D_L03_001DF99C + ((*(unsigned short *)cur & 0x7FFF) << 8);
            if (buf == 0) break;
            cur += 1;
            if (*(u8 *)(buf + 0x20) != 1) {
                if (func_L01_0044C078(buf + 0x10, p->arg) == 0)
                    func_L03_0032DF10(buf);
            }
        }
    }
}
/* localdecomp:end func_L03_0032DF60 */

INCLUDE_ASM("asm/levels", func_L03_0032E0D8);

/* localdecomp:start func_L03_0032E640 */
typedef struct N_0032E640 {
    u8 pad00[0x10];
    f32 f10;
    u8 pad14[0xC];
    u8 b20;
    u8 pad21[7];
    struct N_0032E640 *f28;
    u8 pad2C[0x7E];
    s16 hAA;
} N_0032E640;
extern N_0032E640 *D_L03_001DF9A8;
s32 func_L03_0032E640(s32 *list) {
    N_0032E640 *n;
    for (n = D_L03_001DF9A8; n != 0; n = n->f28) {
        if (n->f10 > 450.0f && n != 0 && n->b20 != 0xFE && n->b20 != 0xFD) {
            s32 t = n->hAA;
            s32 i = 0;
            if (list[0] != -1) {
                do {
                    if (list[i] == t) return 1;
                    i++;
                } while (i < 3 && list[i] != -1);
            }
        }
    }
    return 0;
}
/* localdecomp:end func_L03_0032E640 */

/* localdecomp:start func_L03_0032E6F0 */
extern u8 D_L03_002AE4D0[];
extern s32 D_00142660[];
extern s32 func_L03_0032E7A0(void *a0, s32 a1);
extern s32 func_L03_0032F948(s32 a0);
extern void func_L03_0032FA18(s32 a0);
extern void func_0039EC28(s32 a0, s32 a1);

s32 func_L03_0032E6F0(void *arg0, s32 arg1) {
    s32 r;
    s32 r2;
    u8 *p;

    p = *(u8 **)((u8 *)arg0 + 0x68);
    r = func_L03_0032E7A0(arg0, D_L03_002AE4D0[arg1 * 0x28 + 0x10]);
    if (r != 0) {
        *(s32 *)(p + 0x108) = -1;
    } else {
        r2 = func_L03_0032F948(arg1);
        if (r2 != 0) {
            *(s32 *)(p + 0x108) = r2;
        } else {
            *(s32 *)(p + 0x108) = -2;
        }
        D_00142660[0] += r2;
    }
    func_L03_0032FA18(arg1);
    func_0039EC28(1, -1);
    return r;
}
/* localdecomp:end func_L03_0032E6F0 */

/* localdecomp:start func_L03_0032E7A0 */
typedef struct { u8 pad[0xDC]; s32 fDC; } S_0032E7A0;
typedef struct { u8 pad[0x34]; u16 h34; } E_0032E7A0;
extern u8 D_001BBB30[];
extern u8 *D_L03_001DF99C;
s32 func_L03_0032E7A0(void *a0, s32 a1) {
    S_0032E7A0 *s = *(S_0032E7A0 **)((u8 *)a0 + 0x68);
    s32 r = 0;
    if (a1 == 0 && D_001BBB30[0] == 0) {
        E_0032E7A0 *e;
        r = 1;
        e = (E_0032E7A0 *)(D_L03_001DF99C + (s->fDC << 8));
        e->h34 &= 0xFFFC;
    }
    return r;
}
/* localdecomp:end func_L03_0032E7A0 */

/* localdecomp:start func_L03_0032E7E8 */
extern int func_0011A264(void *, int, int);
extern int func_00382498(int, int);
extern int func_L03_0032F790(void *, int, int);
extern void func_L03_00399C68(void *, int, int, int);
void func_L03_0032E7E8(void *a, int n, int *p19, int *p17, unsigned char *p18) {
    int c[3];
    int i;
    func_0011A264(c, 0, 12);
    if (*p19 > 0) {
        n++;
        *p19 = *p19 - 1;
    }
    if (n > 0) {
        do {
            if (*p17 > 0) {
                i = func_L03_0032F790(p18, func_00382498(0, *p17 - 1), 3);
                p18[i]--;
                c[i]++;
                *p17 = *p17 - 1;
            }
        } while (--n != 0);
    }
    func_L03_00399C68(a, c[0], c[1], c[2]);
}
/* localdecomp:end func_L03_0032E7E8 */

/* localdecomp:start func_L03_0032E8D8 */
void func_L03_0032E8D8(void *arg0, s32 arg1) {
    u8 temp_a1;
    u8 temp_v0;
    void *temp_v1;

    temp_v1 = *(void **)((u8 *)arg0 + 0x68);
    temp_a1 = arg1 & 0xFF;
    temp_v0 = *(u8 *)((u8 *)temp_v1 + 0xF6);
    *(u8 *)((u8 *)temp_v1 + 0xF6) = temp_a1;
    *(s8 *)((u8 *)temp_v1 + 0xF7) = (s8) (temp_a1 & ~temp_v0 & 0x1F);
}
/* localdecomp:end func_L03_0032E8D8 */

INCLUDE_ASM("asm/levels", func_L03_0032E900);

/* localdecomp:start func_L03_0032EB30 */
extern u16 *D_L03_0021C620[];
extern u8 *D_L03_001DF99C;
__asm__(".extern D_L03_001DF99C, 16");
extern s32 D_L03_001DF9D8;
extern void func_L02_003A02D8(u8 *a0, s32 a1);

void func_L03_0032EB30(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);
    u16 *p;
    u8 *e;
    p = D_L03_0021C620[*(s32 *)(s + 0xC0)];
    while ((*(s32 *)(s + 0xC0) & 0xFF) != 0xFF && *(s32 *)(s + 0xC0) <= D_L03_001DF9D8 && p != 0 &&
           ((s16)p[-1] >= 0 || p == D_L03_0021C620[*(s32 *)(s + 0xC0)])) {
        e = D_L03_001DF99C + ((*p & 0x7FFF) << 8);
        if (e == 0) break;
        func_L02_003A02D8(e, 0);
        p++;
    }
}
/* localdecomp:end func_L03_0032EB30 */

/* localdecomp:start func_L03_0032EBF0 */
__asm__(".extern D_001D7C20, 4");
extern int D_001D7C20;
extern void func_L03_0032EC38(int);
extern void func_L03_0032ED88(int);
extern void func_L03_0032EDE0(int);
extern void func_L03_0032EF78(int);

void func_L03_0032EBF0(int a0) {
    D_001D7C20 = -1;
    func_L03_0032EC38(a0);
    func_L03_0032ED88(a0);
    func_L03_0032EDE0(a0);
    func_L03_0032EF78(a0);
}
/* localdecomp:end func_L03_0032EBF0 */

/* localdecomp:start func_L03_0032EC38 */
#include "vu0.h"
extern u8 *D_L03_001DF99C;
__asm__(".extern D_L03_001DF99C, 16");
typedef int u128_0032EC38 __attribute__((mode(TI)));
typedef struct {
    s32 pair[4][2];
    s32 ids[4];
    u8 pad30[0x80 - 0x30];
    s32 a80[5];
    s32 a94[5];
    u8 padA8[0xF6 - 0xA8];
    u8 bF6;
} S_0032EC38;

void func_L03_0032EC38(int arg) {
    u8 *a = (u8 *)arg;
    S_0032EC38 *s = *(S_0032EC38 **)(a + 0x68);
    int i;
    s->bF6 = 0;
    for (i = 0; i < 5; i++) {
        s->a80[i] = 0;
        s->a94[i] = 0;
        if (i == 4) {
            int j;
            for (j = 0; j < 4; j++) {
                u8 *e = D_L03_001DF99C + (s->ids[j] << 8);
                *(u128_0032EC38 *)(e + 0x10) = *(u128_0032EC38 *)(a + 0x10);
            }
        } else {
            vu0_v4 off;
            vu0_v4 pos;
            f32 *pf;
            u8 *e0 = D_L03_001DF99C + (s->pair[i][0] << 8);
            u8 *e1 = D_L03_001DF99C + (s->pair[i][1] << 8);
            *(u128_0032EC38 *)&off = 0;
            pf = &(&off.x)[i % 2];
            {
                f32 f = *pf;
                if (i < 2) {
                    f += 16.65f;
                } else {
                    f += -16.65f;
                }
                *pf = f;
            }
            vec_add_ab(&pos, a + 0x10, &off);
            pos.z += -0.3f;
            *(u128_0032EC38 *)(e0 + 0x10) = *(u128_0032EC38 *)&pos;
            *(u128_0032EC38 *)(e1 + 0x10) = *(u128_0032EC38 *)&pos;
        }
    }
}
/* localdecomp:end func_L03_0032EC38 */
