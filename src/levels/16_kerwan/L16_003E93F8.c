#include "common.h"

/* localdecomp:start func_L16_003E93F8 */
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V_003E93F8;

typedef struct {
    V_003E93F8 v[4];
    f32 f40[4];
    f32 t[4];
    f32 f60;
    f32 f64;
    u8 p68[6];
    u8 b6E;
    u8 p6F;
    V_003E93F8 v70;
    V_003E93F8 v80;
} S_003E93F8;

extern void func_L16_003E8D20(V_003E93F8 *, V_003E93F8 *, f32, f32);
extern f32 func_0038CF38(void *, void *);
extern f32 func_003824E0(f32, f32);
extern void func_L16_003E92B8(void *, u8 *, f32 *);
__asm__(".extern D_L16_001DF63C, 4");
extern f32 D_L16_001DF63C;
__asm__(".extern D_L16_001DF640, 4");
extern f32 D_L16_001DF640;

void func_L16_003E93F8(u8 *a0) {
    S_003E93F8 *m = *(S_003E93F8 **)(a0 + 0x68);
    s32 i;

    for (i = 0; i < 4; i++) {
        if (i < (s32)(m->b6E * 0.5f)) {
            func_L16_003E91B0(a0, (u8 *)&m->v[i], &m->t[i]);
        } else {
            if (D_L16_001DF63C + D_L16_001DF640 < m->v[i].w) {
                f32 d;
                func_L16_003E8D20(&m->v[i], &m->v70, 0.25f, 0.75f);
                d = func_0038CF38(&m->v[i], &m->v80);
                if (m->f60 * 0.4f < d) {
                    func_L16_003E8D20(&m->v[i], &m->v80, 1.0f, 3.0f);
                }
                m->v70 = m->v[i];
                m->v[i].w = D_L16_001DF63C + func_003824E0(0.0f, 0.3f);
                m->t[i] = m->f64 * func_003824E0(0.75f, 0.95f);
            }
            func_L16_003E92B8(a0, (u8 *)&m->v[i], &m->t[i]);
        }
    }
}
/* localdecomp:end func_L16_003E93F8 */

/* localdecomp:start func_L16_003E95A8 */
extern void func_L01_004048D0(void *, u8 *);
extern f32 func_0038CF38(void *, void *);
extern void func_L01_004450F0(s32, s32, s32);
extern void func_003C2880(void *);
extern void func_L16_003E93F8();
extern u8 D_1A4C60[];

void func_L16_003E95A8(u8 *o) {
    s32 k = o[0x20];
    f32 d;

    switch (k) {
    case 0:
        func_L01_004450F0((s32)o, 1, -1);
        break;
    case 1:
        func_L01_004048D0(func_L16_003E93F8, o);
        d = func_0038CF38(D_1A4C60, o + 0x10);
        if (40.0f < d) {
            func_L01_004450F0((s32)o, 2, -1);
        }
        break;
    case 2:
        func_003C2880(o);
        break;
    }
}
/* localdecomp:end func_L16_003E95A8 */

/* localdecomp:start func_L16_003E9660 */
#include "vu0.h"
/* log:
   v1: first draft (struct layout from the offsets): 436 diff; M padding fixed, gp floats hinted: 395.
   6694/6690 as one || chain, scalar externs in the lui form, mobys loaded before the head test: 336.
   qzero for the zeroed vector, f98 before b30: 38. const on the .lit floats (loads move over stores): 25.
   loop 2 with its own pointer and q++ after the call: 23; hero stores reordered: 21;
   D_00142660[2] store after b.z: 5; func_0039EF28 returns s32 (as in src/frontbin/39E5E0.c): MATCH.
*/
typedef struct {
    u8 p0[0x40];
    f32 f40;
    s16 h44;
    u8 p46[0x1E8 - 0x46];
    s32 f1E8;
} A_003E9660;

typedef struct {
    u8 p0[0x10];
    s32 f10;
    u8 p14[0x30];
    u16 h44;
} C_003E9660;

typedef struct {
    u8 p0[0x10];
    V_003E93F8 v10;
    u8 p20[4];
    C_003E9660 *f24;
    u8 p28[8];
    u8 b30;
    u8 p31;
    u16 h32;
    u16 h34;
    u8 p36[0x68 - 0x36];
    void *f68;
    u8 p6C[0x98 - 0x6C];
    s32 f98;
    u8 p9C[0xF8 - 0x9C];
    f32 fF8;
    u8 pFC[4];
} M_003E9660;

typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    s32 f14;
    u8 p18[4];
    s32 f1C;
    s32 f20;
    f32 f24;
    f32 f28;
    s32 f2C;
    f32 *f30;
    u8 p34[4];
    u8 f38[4];
    s32 f3C;
    s32 f40;
} P_003E9660;

typedef struct {
    u8 p0[0x88];
    f32 f88;
    u8 p8C[0x214 - 0x8C];
    s16 h214;
    u8 p216[0x25C4 - 0x216];
    s32 f25C4;
    u8 p25C8[0x25F3 - 0x25C8];
    u8 b25F3;
    u8 p25F4[0x2850 - 0x25F4];
    s32 f2850;
    u8 p2854[0x2884 - 0x2854];
    s16 h2884;
} H_003E9660;

extern s32 func_L01_0044C108(void *);
extern s32 func_L01_004561B8(void *);
extern void func_L16_003E9ED8(u8 *, s32, s32);
extern s32 func_00382380(void *, s32, s32);
extern s32 func_0038CAD0(void *);
extern s32 func_L01_00456250(void *);
extern void func_L01_0043B510(s32);
extern void func_0039EC28(s32, s32);
extern void func_L01_005003D0(s32, s32);
extern f32 func_003C4138(f32 *, f32, f32);
extern void func_L02_003A0200(u8 *);
extern f32 func_0038D160(f32, f32);
extern void func_L01_004F50C8(void *, void *, s32, s32);
extern s32 func_L01_003F2A50(s32, s32);
extern void func_L16_004DCA98(s32);
extern void func_003C41A0(f32 *, void *, f32, f32, f32, f32);
extern void func_L16_00402D30(s32, void *);
extern void func_L01_003F2AF8(s32, void *);
extern s32 func_00392B20(void *, s32);
extern s32 func_00392C78(void *);
extern void func_L01_004BA7B8(void);
extern void func_L01_004AA7E8(void *, s32);
extern s32 func_0039EF28(void);

extern s32 D_L16_001D6694;
__asm__(".extern D_L16_001D6694, 4");
extern s32 D_L16_001D6690;
extern s32 D_001D545C;
extern s32 D_001D545C_sda;
__asm__(".extern D_001D545C_sda, 4");
extern u8 D_001BBC40[][16];
extern u8 D_1A4C60[];
extern H_003E9660 D_001A4BE0;
extern s32 D_00142660[];
extern u8 D_001426E0[];
extern u32 D_00142C50[];
extern f32 D_L16_001DFA50;
extern s16 *D_L16_0021D460[];
extern u8 *D_L16_001E015C;
extern u8 *D_001E015C_sda;
__asm__(".extern D_001E015C_sda, 4");
extern s32 D_L16_001E0198;
extern s32 D_001E0198_sda;
__asm__(".extern D_001E0198_sda, 4");
extern const f32 D_L16_001DF654;
__asm__(".extern D_L16_001DF654, 4");
extern const f32 D_L16_001DF658;
__asm__(".extern D_L16_001DF658, 4");
extern const f32 D_L16_001DF65C;
__asm__(".extern D_L16_001DF65C, 4");
extern const f32 D_L16_001DF660;
__asm__(".extern D_L16_001DF660, 4");
extern u8 D_L16_001E9680[];
extern u8 *D_L16_001E0240;

void func_L16_003E9660(u8 *o) {
    P_003E9660 *p;
    M_003E9660 *m;
    s16 *q;
    u8 *mobys;

    if (func_L01_0044C108(o + 0x10) == 0) return;
    if (D_L16_001D6694 == 1 || D_L16_001D6694 == 2 || D_L16_001D6690 == 1 || D_L16_001D6690 == 2) return;
    p = *(P_003E9660 **)(o + 0x68);
    switch (o[0x20]) {
    case 0:
        p->f30 = 0;
        p->f2C = 0;
        if (D_001BBC40[D_001D545C][o[0xB0]] & 0x80) {
            func_L01_004450F0((s32)o, 4, -1);
        } else {
            func_L01_004450F0((s32)o, 1, -1);
        }
        break;
    case 1:
        if (func_L01_004561B8(o)) {
            func_L16_003E9ED8(o, 0, 1);
        }
        if ((D_001BBC40[D_001D545C][p->f14] & 0x80) && func_00382380(D_1A4C60, p->f20, 0)) {
            if (++p->f2C > 50) {
                func_L01_004450F0((s32)o, 2, -1);
            }
        } else {
            func_0038CAD0(&p->f2C);
        }
        if (!(D_001BBC40[D_001D545C][p->f14] & 0x80) && func_L01_00456250(o)) {
            func_L01_0043B510(p->f14);
            func_L01_004450F0((s32)o, 3, -1);
            func_0039EC28(0, -1);
        }
        break;
    case 2:
        if (func_L01_004561B8(o)) {
            func_L01_005003D0(0x74, 1);
        }
        func_003C4138(&D_L16_001DFA50, 1.0f, 0.05882353f);
        if (1.0f <= D_L16_001DFA50) {
            func_L01_004450F0((s32)o, 3, -1);
        }
        break;
    case 3:
        if (func_L01_004561B8(o)) {
            V_003E93F8 a, b, r;
            func_L16_003E9ED8(o, 1, 1);
            q = D_L16_0021D460[p->f10];
            while ((mobys = D_001E015C_sda, (p->f10 & 0xFF) != 0xFF) && p->f10 <= D_L16_001E0198 && q != 0 &&
                   (q[-1] >= 0 || q == D_L16_0021D460[p->f10])) {
                C_003E9660 *c;
                m = (M_003E9660 *)(D_L16_001E015C + ((*(u16 *)q & 0x7FFF) << 8));
                mobys = D_L16_001E015C;
                if (m == 0) break;
                m->h34 &= 0xFFBE;
                c = m->f24;
                m->h34 |= c->h44 & 0x1000;
                m->f98 = c->f10;
                m->b30 = 0xFF;
                m->h32 = 0xFF;
                q++;
                func_L02_003A0200((u8 *)m);
            }
            a = ((M_003E9660 *)mobys)[p->f4].v10;
            a.z += D_L16_001DF654;
            b = ((M_003E9660 *)mobys)[p->f8].v10;
            b.z += D_L16_001DF654;
            D_001A4BE0.f2850 = D_00142660[2];
            ((M_003E9660 *)mobys)[p->f0].v10 = a;
            ((M_003E9660 *)D_L16_001E015C)[p->f0].fF8 = func_0038D160(b.x - a.x, b.y - a.y);
            qzero(&r);
            r.z = func_0038D160(a.x - b.x, a.y - b.y);
            func_L01_004F50C8(&b, &r, 0, 1);
            D_001A4BE0.h2884 = 1;
            func_L01_004450F0((s32)(D_L16_001E015C + (p->f0 << 8)), 2, 1);
            if (p->f30 == 0) {
                p->f30 = (f32 *)func_L01_003F2A50(0, 5);
            }
        }
        func_L16_004DCA98(2);
        if (p->f3C == 0) {
            A_003E9660 *s = (A_003E9660 *)((M_003E9660 *)D_L16_001E015C)[p->f0].f68;
            if (s->f40 / (f32)s->h44 < p->f28) {
                f32 *t = (f32 *)((u8 *)((M_003E9660 *)(D_L16_001E015C + (p->fC << 8)))->f68 + 0x7C);
                func_003C41A0(t, p->f38, 0.0f, 0.016f, 0.004f, 0.40000004f);
                if (*t < 0.05f) {
                    *t = 0.0f;
                    p->f3C = 1;
                    s->f1E8 = 1;
                }
            }
        }
        if (p->f30 != 0) {
            p->f30[2] = D_L16_001DF658;
            p->f30[1] = D_L16_001DF660;
            p->f30[0] = D_L16_001DF65C;
            func_L16_00402D30(0, p->f30);
        }
        D_001A4BE0.b25F3 = 1;
        D_001A4BE0.h214 = 2;
        if (D_001A4BE0.f88 < p->f24) {
            if (D_001A4BE0.f25C4 != 0x79) {
                func_L01_005003D0(0x79, 1);
            }
            break;
        }
        if (func_L01_00456250(D_L16_001E015C + (p->f0 << 8)) == 0) break;
        if (D_001A4BE0.f2850 <= 0) break;
        func_L01_004450F0((s32)o, 4, -1);
        break;
    case 4:
        if (D_001A4BE0.f2850 <= 0) break;
        if (D_001A4BE0.f25C4 == 0x79) break;
        if (func_L01_004561B8(o)) {
            func_L16_003E9ED8(o, 0, 1);
            if (p->f30 != 0) {
                func_L01_003F2AF8(0, p->f30);
                p->f30 = 0;
            }
            if (o[0x94] == 3 && !(D_00142C50[0] & 0x10000) && func_00392B20(D_L16_001E9680, 0xB0)) {
                func_00392C78(D_L16_001E9680);
                func_L01_004BA7B8();
            }
            ((M_003E9660 *)D_L16_001E015C)[p->f0].h34 |= 0x41;
            ((M_003E9660 *)D_L16_001E015C)[p->f0].h34 &= 0xEFFF;
            ((M_003E9660 *)D_L16_001E015C)[p->f0].f98 = 0;
            func_L01_004AA7E8(D_L16_001E015C + (p->f0 << 8), 1);
            break;
        }
        ((M_003E9660 *)D_L16_001E015C)[p->f0].h34 |= 0x41;
        ((M_003E9660 *)D_L16_001E015C)[p->f0].h34 &= 0xEFFF;
        ((M_003E9660 *)D_L16_001E015C)[p->f0].f98 = 0;
        func_L01_004AA7E8(D_L16_001E015C + (p->f0 << 8), 1);
        q = D_L16_0021D460[p->f40];
        while ((p->f40 & 0xFF) != 0xFF && p->f40 <= D_001E0198_sda && q != 0 &&
               (q[-1] >= 0 || q == D_L16_0021D460[p->f40])) {
            M_003E9660 *n = (M_003E9660 *)(D_L16_001E015C + ((*(u16 *)q & 0x7FFF) << 8));
            if (n == 0) break;
            n->h34 = (n->h34 | 0x41) & 0xEFFF;
            n->f98 = 0;
            func_L01_004AA7E8(n, 1);
            q++;
        }
        func_L01_0043B510(o[0xB0]);
        func_L01_004F50C8(D_L16_001E0240 + (p->f1C << 7) + 0x30, D_L16_001E0240 + (p->f1C << 7) + 0x70, 0, 1);
        D_001426E0[0x28] = 1;
        D_001A4BE0.h2884 = 0;
        D_001A4BE0.b25F3 = 0;
        func_0039EF28();
        *(u16 *)(o + 0x34) |= 2;
        break;
    }
}
/* localdecomp:end func_L16_003E9660 */

/* localdecomp:start func_L16_003E9ED8 */
typedef struct { u8 p0[0x34]; u16 h34; u8 p36[0x32]; void *f68; u8 p6C[0x2C]; s32 f98; u8 p9C[0x64]; } M_003E9ED8;
typedef struct { u8 p0[0x70]; M_003E9ED8 *f70; s32 f74; } V_003E9ED8;
typedef struct { u8 p0[0x1F0]; s32 a1F0[6]; } W_003E9ED8;
typedef struct { s32 f0; s32 f4; u8 p8[8]; s32 f10; } P_003E9ED8;
extern s16 *D_L16_0021D460[];
extern u8 *D_L16_001E015C;
__asm__(".extern D_L16_001E015C, 16");
extern u8 *D_001E015C_sda;
__asm__(".extern D_001E015C_sda, 4");
extern s32 D_001E0198_sda;
__asm__(".extern D_001E0198_sda, 4");
extern void func_L01_004AA7E8(void *, s32);
extern void func_L16_00346100(u8 *, s32);

void func_L16_003E9ED8(u8 *a0, s32 a1, s32 a2) {
    P_003E9ED8 *p = *(P_003E9ED8 **)(a0 + 0x68);
    W_003E9ED8 *w;
    s16 *q;
    M_003E9ED8 *m;

    if (p->f0 == -1) return;
    w = (W_003E9ED8 *)((M_003E9ED8 *)D_L16_001E015C)[p->f0].f68;
    if (w->a1F0[2] == -1) return;
    func_L16_00346100(D_L16_001E015C + (w->a1F0[2] << 8), a1);
    func_L16_00346100(D_L16_001E015C + (w->a1F0[5] << 8), a1);
    if (a2 != 0) {
        u8 *mobys = D_001E015C_sda;
        if (a1 != 0) {
            ((M_003E9ED8 *)mobys)[((V_003E9ED8 *)((M_003E9ED8 *)mobys)[w->a1F0[0]].f68)->f74].h34 &= ~2;
            ((M_003E9ED8 *)mobys)[((V_003E9ED8 *)((M_003E9ED8 *)mobys)[w->a1F0[3]].f68)->f74].h34 &= ~2;
            ((M_003E9ED8 *)mobys)[w->a1F0[0]].h34 &= ~2;
            ((M_003E9ED8 *)mobys)[w->a1F0[1]].h34 &= ~2;
            ((M_003E9ED8 *)mobys)[w->a1F0[2]].h34 &= ~2;
            ((M_003E9ED8 *)mobys)[w->a1F0[3]].h34 &= ~2;
            ((M_003E9ED8 *)mobys)[w->a1F0[4]].h34 &= ~2;
            ((M_003E9ED8 *)mobys)[w->a1F0[5]].h34 &= ~2;
        } else {
            ((M_003E9ED8 *)mobys)[((V_003E9ED8 *)((M_003E9ED8 *)mobys)[w->a1F0[0]].f68)->f74].h34 |= 2;
            ((M_003E9ED8 *)mobys)[((V_003E9ED8 *)((M_003E9ED8 *)mobys)[w->a1F0[3]].f68)->f74].h34 |= 2;
            ((M_003E9ED8 *)mobys)[w->a1F0[0]].h34 |= 2;
            ((M_003E9ED8 *)mobys)[w->a1F0[1]].h34 |= 2;
            ((M_003E9ED8 *)mobys)[w->a1F0[2]].h34 |= 2;
            ((M_003E9ED8 *)mobys)[w->a1F0[3]].h34 |= 2;
            ((M_003E9ED8 *)mobys)[w->a1F0[4]].h34 |= 2;
            ((M_003E9ED8 *)mobys)[w->a1F0[5]].h34 |= 2;
        }
        return;
    }
    {
        m = (M_003E9ED8 *)(D_L16_001E015C + (((V_003E9ED8 *)((M_003E9ED8 *)D_L16_001E015C)[w->a1F0[0]].f68)->f74 << 8));
        m->h34 = (m->h34 | 0x41) & 0xEFFF;
        m->f98 = 0;
        func_L01_004AA7E8(m, 1);
        ((V_003E9ED8 *)m->f68)->f70->h34 |= 0x41;
        ((V_003E9ED8 *)m->f68)->f70->h34 &= 0xEFFF;
        ((V_003E9ED8 *)m->f68)->f70->f98 = 0;
        func_L01_004AA7E8(((V_003E9ED8 *)m->f68)->f70, 1);
    }
    {
        m = (M_003E9ED8 *)(D_L16_001E015C + (((V_003E9ED8 *)((M_003E9ED8 *)D_L16_001E015C)[w->a1F0[3]].f68)->f74 << 8));
        m->h34 = (m->h34 | 0x41) & 0xEFFF;
        m->f98 = 0;
        func_L01_004AA7E8(m, 1);
        ((V_003E9ED8 *)m->f68)->f70->h34 |= 0x41;
        ((V_003E9ED8 *)m->f68)->f70->h34 &= 0xEFFF;
        ((V_003E9ED8 *)m->f68)->f70->f98 = 0;
        func_L01_004AA7E8(((V_003E9ED8 *)m->f68)->f70, 1);
    }
    ((M_003E9ED8 *)D_L16_001E015C)[w->a1F0[0]].h34 |= 0x41;
    ((M_003E9ED8 *)D_L16_001E015C)[w->a1F0[0]].h34 &= 0xEFFF;
    ((M_003E9ED8 *)D_L16_001E015C)[w->a1F0[0]].f98 = 0;
    func_L01_004AA7E8(((M_003E9ED8 *)(D_L16_001E015C + (w->a1F0[0] << 8))), 1);
    ((M_003E9ED8 *)D_L16_001E015C)[w->a1F0[1]].h34 |= 0x41;
    ((M_003E9ED8 *)D_L16_001E015C)[w->a1F0[1]].h34 &= 0xEFFF;
    ((M_003E9ED8 *)D_L16_001E015C)[w->a1F0[1]].f98 = 0;
    func_L01_004AA7E8(((M_003E9ED8 *)(D_L16_001E015C + (w->a1F0[1] << 8))), 1);
    ((M_003E9ED8 *)D_L16_001E015C)[w->a1F0[2]].h34 |= 0x41;
    ((M_003E9ED8 *)D_L16_001E015C)[w->a1F0[2]].h34 &= 0xEFFF;
    ((M_003E9ED8 *)D_L16_001E015C)[w->a1F0[2]].f98 = 0;
    func_L01_004AA7E8(((M_003E9ED8 *)(D_L16_001E015C + (w->a1F0[2] << 8))), 1);
    ((M_003E9ED8 *)D_L16_001E015C)[w->a1F0[3]].h34 |= 0x41;
    ((M_003E9ED8 *)D_L16_001E015C)[w->a1F0[3]].h34 &= 0xEFFF;
    ((M_003E9ED8 *)D_L16_001E015C)[w->a1F0[3]].f98 = 0;
    func_L01_004AA7E8(((M_003E9ED8 *)(D_L16_001E015C + (w->a1F0[3] << 8))), 1);
    ((M_003E9ED8 *)D_L16_001E015C)[w->a1F0[4]].h34 |= 0x41;
    ((M_003E9ED8 *)D_L16_001E015C)[w->a1F0[4]].h34 &= 0xEFFF;
    ((M_003E9ED8 *)D_L16_001E015C)[w->a1F0[4]].f98 = 0;
    func_L01_004AA7E8(((M_003E9ED8 *)(D_L16_001E015C + (w->a1F0[4] << 8))), 1);
    ((M_003E9ED8 *)D_L16_001E015C)[w->a1F0[5]].h34 |= 0x41;
    ((M_003E9ED8 *)D_L16_001E015C)[w->a1F0[5]].h34 &= 0xEFFF;
    ((M_003E9ED8 *)D_L16_001E015C)[w->a1F0[5]].f98 = 0;
    func_L01_004AA7E8(((M_003E9ED8 *)(D_L16_001E015C + (w->a1F0[5] << 8))), 1);
    q = (s16 *)D_L16_0021D460[p->f10];
    while ((p->f10 & 0xFF) != 0xFF && p->f10 <= D_001E0198_sda && q != 0 && (q[-1] >= 0 || q == D_L16_0021D460[p->f10])) {
        P_003E9ED8 *v;
        m = (M_003E9ED8 *)(D_L16_001E015C + ((*(u16 *)q & 0x7FFF) << 8));
        if (m == 0) return;
        m->h34 = (m->h34 | 0x41) & 0xEFFF;
        m->f98 = 0;
        func_L01_004AA7E8(m, 1);
        v = (P_003E9ED8 *)m->f68;
        if (v->f0 >= 0) {
            u8 *mobys = D_001E015C_sda;
            ((M_003E9ED8 *)mobys)[v->f0].h34 |= 0x41;
            ((M_003E9ED8 *)mobys)[v->f0].h34 &= 0xEFFF;
            ((M_003E9ED8 *)mobys)[v->f0].f98 = 0;
            func_L01_004AA7E8(mobys + (v->f0 << 8), 1);
        }
        if (v->f4 >= 0) {
            u8 *mobys = D_001E015C_sda;
            ((M_003E9ED8 *)mobys)[v->f4].h34 |= 0x41;
            ((M_003E9ED8 *)mobys)[v->f4].h34 &= 0xEFFF;
            ((M_003E9ED8 *)mobys)[v->f4].f98 = 0;
            func_L01_004AA7E8(mobys + (v->f4 << 8), 1);
        }
        q++;
    }
}
/* localdecomp:end func_L16_003E9ED8 */
