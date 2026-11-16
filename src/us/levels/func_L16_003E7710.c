#include "common.h"

/* NTSC-U counterpart of func_L16_003E9660 (src/levels/16_kerwan/L16_003E93F8.c) */
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V_003E93F8;
extern void func_L01_00441FB8(s32, s32, s32);
extern u8 D_001A4C60[];

/* localdecomp:start func_L16_003E7710 */
#include "vu0.h"
/* log:
   v1: first draft (struct layout from the offsets): 436 diff; M padding fixed, gp floats hinted: 395.
   6694/6690 as one || chain, scalar externs in the lui form, mobys loaded before the head test: 336.
   qzero for the zeroed vector, f98 before b30: 38. const on the .lit floats (loads move over stores): 25.
   loop 2 with its own pointer and q++ after the call: 23; hero stores reordered: 21;
   D_00142660[2] store after b.z: 5; func_00399F90 returns s32 (as in src/frontbin/39E5E0.c): MATCH.
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

extern s32 func_L01_00448E90(void *);
extern s32 func_L01_00452EC8(void *);
extern void func_L16_003E7F88(u8 *, s32, s32);
extern s32 func_0037E0F0(void *, s32, s32);
extern s32 func_00388398(void *);
extern s32 func_L01_00452F60(void *);
extern void func_L01_00438430(s32);
extern void func_00399C90(s32, s32);
extern void func_L01_004FC518(s32, s32);
extern f32 func_003BEBF8(f32 *, f32, f32);
extern void func_L02_0039E460(u8 *);
extern f32 func_00388A28(f32, f32);
extern void func_L01_004F12C0(void *, void *, s32, s32);
extern s32 func_L01_003F08D8(s32, s32);
extern void func_L16_004D8BB0(s32);
extern void func_003BEC60(f32 *, void *, f32, f32, f32, f32);
extern void func_L16_00400938(s32, void *);
extern void func_L01_003F0980(s32, void *);
extern s32 func_0038E2E8(void *, s32);
extern s32 func_0038E440(void *);
extern void func_L01_004B6C20(void);
extern void func_L01_004A6DF8(void *, s32);
extern s32 func_00399F90(void);

extern s32 D_L16_001D6694_003E7710;
__asm__(".extern D_L16_001D6694_003E7710, 4");
extern s32 D_L16_001D6690_003E7710;
extern s32 D_001D545C;
extern u8 D_001BBC40[][16];
extern u8 D_001A4C60[];
extern H_003E9660 D_001A4BE0;
extern s32 D_00142660[];
extern u8 D_001426E0[];
extern u32 D_00142C50[];
extern f32 D_L16_001DFA50_003E7710;
extern s16 *D_L16_0021D460_003E7710[];
extern u8 *D_L16_001E015C_003E7710;
extern u8 *D_001E015C_sda_003E7710;
__asm__(".extern D_001E015C_sda_003E7710, 4");
extern s32 D_L16_001E0198_003E7710;
extern s32 D_001E0198_sda_003E7710;
__asm__(".extern D_001E0198_sda_003E7710, 4");
extern const f32 D_L16_001DF694;
__asm__(".extern D_L16_001DF694, 4");
extern const f32 D_L16_001DF698;
__asm__(".extern D_L16_001DF698, 4");
extern const f32 D_L16_001DF69C;
__asm__(".extern D_L16_001DF69C, 4");
extern const f32 D_L16_001DF6A0;
__asm__(".extern D_L16_001DF6A0, 4");
extern u8 D_L16_001E9680_003E7710[];
extern u8 *D_L16_001E0240_003E7710;

void func_L16_003E7710(u8 *o) {
    P_003E9660 *p;
    M_003E9660 *m;
    s16 *q;
    u8 *mobys;

    if (func_L01_00448E90(o + 0x10) == 0) return;
    if (D_L16_001D6694_003E7710 == 1 || D_L16_001D6694_003E7710 == 2 || D_L16_001D6690_003E7710 == 1 || D_L16_001D6690_003E7710 == 2) return;
    p = *(P_003E9660 **)(o + 0x68);
    switch (o[0x20]) {
    case 0:
        p->f30 = 0;
        p->f2C = 0;
        if (D_001BBC40[D_001D545C][o[0xB0]] & 0x80) {
            func_L01_00441FB8((s32)o, 4, -1);
        } else {
            func_L01_00441FB8((s32)o, 1, -1);
        }
        break;
    case 1:
        if (func_L01_00452EC8(o)) {
            func_L16_003E7F88(o, 0, 1);
        }
        if ((D_001BBC40[D_001D545C][p->f14] & 0x80) && func_0037E0F0(D_001A4C60, p->f20, 0)) {
            if (++p->f2C > 60) {
                func_L01_00441FB8((s32)o, 2, -1);
            }
        } else {
            func_00388398(&p->f2C);
        }
        if (!(D_001BBC40[D_001D545C][p->f14] & 0x80) && func_L01_00452F60(o)) {
            func_L01_00438430(p->f14);
            func_L01_00441FB8((s32)o, 3, -1);
            func_00399C90(0, -1);
        }
        break;
    case 2:
        if (func_L01_00452EC8(o)) {
            func_L01_004FC518(0x74, 1);
        }
        func_003BEBF8(&D_L16_001DFA50_003E7710, 1.0f, 0.05f);
        if (1.0f <= D_L16_001DFA50_003E7710) {
            func_L01_00441FB8((s32)o, 3, -1);
        }
        break;
    case 3:
        if (func_L01_00452EC8(o)) {
            V_003E93F8 a, b, r;
            func_L16_003E7F88(o, 1, 1);
            q = D_L16_0021D460_003E7710[p->f10];
            while ((mobys = D_001E015C_sda_003E7710, (p->f10 & 0xFF) != 0xFF) && p->f10 <= D_L16_001E0198_003E7710 && q != 0 &&
                   (q[-1] >= 0 || q == D_L16_0021D460_003E7710[p->f10])) {
                C_003E9660 *c;
                m = (M_003E9660 *)(D_L16_001E015C_003E7710 + ((*(u16 *)q & 0x7FFF) << 8));
                mobys = D_L16_001E015C_003E7710;
                if (m == 0) break;
                m->h34 &= 0xFFBE;
                c = m->f24;
                m->h34 |= c->h44 & 0x1000;
                m->f98 = c->f10;
                m->b30 = 0xFF;
                m->h32 = 0xFF;
                q++;
                func_L02_0039E460((u8 *)m);
            }
            a = ((M_003E9660 *)mobys)[p->f4].v10;
            a.z += D_L16_001DF694;
            b = ((M_003E9660 *)mobys)[p->f8].v10;
            b.z += D_L16_001DF694;
            D_001A4BE0.f2850 = D_00142660[2];
            ((M_003E9660 *)mobys)[p->f0].v10 = a;
            ((M_003E9660 *)D_L16_001E015C_003E7710)[p->f0].fF8 = func_00388A28(b.x - a.x, b.y - a.y);
            qzero(&r);
            r.z = func_00388A28(a.x - b.x, a.y - b.y);
            func_L01_004F12C0(&b, &r, 0, 1);
            D_001A4BE0.h2884 = 1;
            func_L01_00441FB8((s32)(D_L16_001E015C_003E7710 + (p->f0 << 8)), 2, 1);
            if (p->f30 == 0) {
                p->f30 = (f32 *)func_L01_003F08D8(0, 5);
            }
        }
        func_L16_004D8BB0(2);
        if (p->f3C == 0) {
            A_003E9660 *s = (A_003E9660 *)((M_003E9660 *)D_L16_001E015C_003E7710)[p->f0].f68;
            if (s->f40 / (f32)s->h44 < p->f28) {
                f32 *t = (f32 *)((u8 *)((M_003E9660 *)(D_L16_001E015C_003E7710 + (p->fC << 8)))->f68 + 0x7C);
                func_003BEC60(t, p->f38, 0.0f, 0.011111111380159855f, 0.0027777778450399637f, 0.3333333432674408f);
                if (*t < 0.05f) {
                    *t = 0.0f;
                    p->f3C = 1;
                    s->f1E8 = 1;
                }
            }
        }
        if (p->f30 != 0) {
            p->f30[2] = D_L16_001DF698;
            p->f30[1] = D_L16_001DF6A0;
            p->f30[0] = D_L16_001DF69C;
            func_L16_00400938(0, p->f30);
        }
        D_001A4BE0.b25F3 = 1;
        D_001A4BE0.h214 = 2;
        if (D_001A4BE0.f88 < p->f24) {
            if (D_001A4BE0.f25C4 != 0x79) {
                func_L01_004FC518(0x79, 1);
            }
            break;
        }
        if (func_L01_00452F60(D_L16_001E015C_003E7710 + (p->f0 << 8)) == 0) break;
        if (D_001A4BE0.f2850 <= 0) break;
        func_L01_00441FB8((s32)o, 4, -1);
        break;
    case 4:
        if (D_001A4BE0.f2850 <= 0) break;
        if (D_001A4BE0.f25C4 == 0x79) break;
        if (func_L01_00452EC8(o)) {
            func_L16_003E7F88(o, 0, 1);
            if (p->f30 != 0) {
                func_L01_003F0980(0, p->f30);
                p->f30 = 0;
            }
            if (o[0x94] == 3 && !(D_00142C50[0] & 0x10000) && func_0038E2E8(D_L16_001E9680_003E7710, 0xB0)) {
                func_0038E440(D_L16_001E9680_003E7710);
                func_L01_004B6C20();
            }
            ((M_003E9660 *)D_L16_001E015C_003E7710)[p->f0].h34 |= 0x41;
            ((M_003E9660 *)D_L16_001E015C_003E7710)[p->f0].h34 &= 0xEFFF;
            ((M_003E9660 *)D_L16_001E015C_003E7710)[p->f0].f98 = 0;
            func_L01_004A6DF8(D_L16_001E015C_003E7710 + (p->f0 << 8), 1);
            break;
        }
        ((M_003E9660 *)D_L16_001E015C_003E7710)[p->f0].h34 |= 0x41;
        ((M_003E9660 *)D_L16_001E015C_003E7710)[p->f0].h34 &= 0xEFFF;
        ((M_003E9660 *)D_L16_001E015C_003E7710)[p->f0].f98 = 0;
        func_L01_004A6DF8(D_L16_001E015C_003E7710 + (p->f0 << 8), 1);
        q = D_L16_0021D460_003E7710[p->f40];
        while ((p->f40 & 0xFF) != 0xFF && p->f40 <= D_001E0198_sda_003E7710 && q != 0 &&
               (q[-1] >= 0 || q == D_L16_0021D460_003E7710[p->f40])) {
            M_003E9660 *n = (M_003E9660 *)(D_L16_001E015C_003E7710 + ((*(u16 *)q & 0x7FFF) << 8));
            if (n == 0) break;
            n->h34 = (n->h34 | 0x41) & 0xEFFF;
            n->f98 = 0;
            func_L01_004A6DF8(n, 1);
            q++;
        }
        func_L01_00438430(o[0xB0]);
        func_L01_004F12C0(D_L16_001E0240_003E7710 + (p->f1C << 7) + 0x30, D_L16_001E0240_003E7710 + (p->f1C << 7) + 0x70, 0, 1);
        D_001426E0[0x28] = 1;
        D_001A4BE0.h2884 = 0;
        D_001A4BE0.b25F3 = 0;
        func_00399F90();
        *(u16 *)(o + 0x34) |= 2;
        break;
    }
}
/* localdecomp:end func_L16_003E7710 */
