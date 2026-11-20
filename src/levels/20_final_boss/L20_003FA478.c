#include "common.h"

/* localdecomp:start func_L20_003FA478 */
#include "vu0.h"
typedef struct {
    u8 p0[0x30];
    f32 f30;
    u8 p34[0x1EC];
    vu0_v4 v220;
    u8 p230[4];
    s16 h234;
    u8 p236[10];
    s32 w240;
    u8 p244[0x9C];
    s32 w2E0;
    u8 p2E4[2];
    s16 h2E6;
    s32 w2E8;
    u8 *p2EC;
    s32 w2F0;
    s32 w2F4;
    s32 w2F8;
    u8 p2FC[4];
    vu0_v4 v300;
    u8 p310[4];
    s32 w314;
} S_3FA478;
extern s32 func_L20_003FACD8(u8 *);
extern void func_003C2880(void *);
extern s32 func_L01_004561E0(void *);
extern s32 func_L01_004561B8(void *);
extern s32 func_00382498(s32, s32);
extern s32 func_0038CB00(void *);
extern void func_L20_003FB2A8(void *, s32, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_00409598(void *, void *, void *, s32, s32, s32, s32, s32, s32, s32);
extern s32 func_L01_00454370(void *, void *);
extern void func_L20_003FB120(void *);
/* The four floats follow the first argument in the prototype: arguments are evaluated and
   moved in parameter order, and this puts retail's f12 move and constant registers where they are. */
extern s32 func_L01_003303B8(u8 *, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L03_0043FC00(s32, s32, u8 *, s32, s32, f32, f32, f32, f32, s32, f32, f32, s32, s32, f32);
extern u8 *func_003C24B0(s32, s32);
extern void func_L01_00456160(u8 *, u8 *);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_003C4098(void *, void *, void *, f32);
extern void func_003C2EC0(void *, s32, void *);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038CED8(void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern f32 func_0038CF38(void *, void *);
extern void func_L06_00358938(void *, void *, void *, s32, f32, f32);
extern u8 *func_L01_0046B458(f32 *, f32, s32, f32, f32, s32, s32, s32, f32 *, s32);
extern void func_L01_0045A748(void *, void *);
extern s32 func_L01_00456500(void *, s32);
extern void func_L20_003FB180(void *);
/* the sdata attribute makes gcc emit the address as one `la` (lui and addiu adjacent) */
extern u8 D_L20_001D66B0[] __attribute__((section(".sdata")));
extern s32 D_L20_001DFD40;
__asm__(".extern D_L20_001DEBEC, 4");
__asm__(".extern D_L20_001DEBF0, 4");
extern s32 D_L20_001DEBEC;
extern s32 D_L20_001DEBF0;

void func_L20_003FA478(u8 *obj) {
    S_3FA478 *s;
    vu0_v4 d;
    vu0_v4 w;
    u8 v[0x30];
    vu0_v4 e;
    s32 hit;
    s32 r;
    f32 f;
    f32 one;
    u8 *vp;
    vu0_v4 *ep;

    s = *(S_3FA478 **)(obj + 0x68);
    r = func_L20_003FACD8(obj);
    if (r != 0) {
        goto L225;
    }
    if (D_L20_001DEBEC == 0) {
        return;
    }
    if (D_L20_001DEBF0 != 0) {
        func_003C2880(s->p2EC);
        s->w240 = 0;
        goto L225;
    }
    hit = 1;
    switch (obj[0x95]) {
    case 0:
        if (func_L01_004561E0(obj) != 0) {
            s->h2E6 = (func_00382498(0, 0x1E) * 5 + 2) / 6;
        }
        if (s->h234 == 1) {
            if (func_0038CB00(&s->h2E6) != 0) {
                func_L20_003FB2A8(obj, 1, 0, 8);
                func_L01_004450F0(obj, 3, 2);
                if (s->w2F8 == 0) {
                    goto Lpost;
                }
                func_L01_00409598(obj, obj + 0x10, obj + 0xF0, 0, 2, 3, 0x25, 0x25, 0xFF8040, 0x8F1010);
                func_L01_00409598(s->p2EC, s->p2EC + 0x10, s->p2EC + 0xF0, 0, 2, 3, 0x25, 0x25, 0xFF8040, 0x8F1010);
                goto Lpost;
            }
        }
        if (s->w2E8 == 0) {
            goto Lpost;
        }
        if (func_0038CB00(&s->h2E6) == 0) {
            goto Lpost;
        }
        func_L01_004450F0(obj, 2, 1);
        s->w2E8 = 0;
        if (!(s->w2E0 < 0xFA)) {
            goto Lpost;
        }
        s->w2E0 = (func_00382498(0x1E0, 0x258) * 5 + 2) / 6;
        goto Lpost;
    case 1:
        if (s->h234 == 1) {
            goto L244;
        }
        if (s->w2E0 != 0) {
            goto Lpost;
        }
        func_L01_004450F0(obj, 1, 0);
        goto Lpost;
    case 2:
        if (s->h234 == 1) {
            goto Lpost;
        }
        if (func_L01_004561E0(obj) != 0) {
            goto Lpost;
        }
        goto L249;
    case 3:
        r = func_L01_00454370(obj, (u8 *)s + 0x160);
        if ((r & 1) == 0) {
            if (!(s->f30 <= 0.0f)) {
                goto L229;
            }
        }
        one = 1.0f;
        func_L20_003FB120(obj);
        func_L01_003303B8(obj + 0x10, one, 0.0f, 0.0f, 2.0f, 1, 0x19, 0x14, 0x14, 0x14, 0x2D, 2, 1, 1, 1, 0, 1, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
        func_L03_0043FC00((s32)obj, 0x7FFF, D_L20_001D66B0, 2, 3, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, one);
        if ((u16)(*(u16 *)(obj + 0xB2) - 0x3F) >= 2) {
            func_L01_00456160(func_003C24B0(0x1E09, 0x80), obj);
        }
L225:
        func_003C2880(obj);
        return;
L229:
        if ((r & 2) == 0) {
            goto Lpost;
        }
        if (s->h234 != 1) {
            goto L249;
        }
        func_L20_003FB2A8(obj, 0x14, 0, 8);
        func_003C3A10(s->p2EC, 0xB, 0, 8);
L244:
        func_L01_004450F0(obj, 4, 2);
        goto Lpost;
L249:
        func_L01_004450F0(obj, 2, 1);
        s->w2E0 = (func_00382498(0x244, 0x258) * 5 + 2) / 6;
        goto Lpost;
    default:
        break;
    }
Lpost:
    if (s->p2EC[0x42] == 0xB) {
        if ((D_L20_001DFD40 & 3) == (((s32)obj >> 8) & 3)) {
            *(vu0_q *)&d = *(vu0_q *)&s->v300;
            *(vu0_q *)&w = *(vu0_q *)&s->v220;
            func_003C4098(&s->v300, &d, &w, 0.075f);
            vp = v;
            func_003C2EC0(s->p2EC, s->w2F4, vp);
            vec_sub_ab(&d, &s->v300, &e);
            func_0038CF68(&d, &d, 0.70000005f);
            ep = &e;
            f = func_0038CED8(vp);
            func_L06_00358938(obj, ep, &d, 3, -func_0038D160(f, *(f32 *)(v + 8)), 10.0f);
            func_L01_0046B458((f32 *)ep, 4.0f, 8, 5.0f, 0.0f, 0x5F005F00, 0, 2, (f32 *)D_L20_001D66B0, 0);
            s->w2F4 = s->w2F4 + 1;
            if (s->w2F4 >= 6) {
                s->w2F4 = 0;
            }
        }
        s->w2F0 = s->w2F0 + 1;
        if (s->w2F0 >= 0xC9) {
            func_003C3A10(s->p2EC, 0x11, 0, 8);
        }
    }
    if (s->p2EC[0x42] == 0x11) {
        s->w2F0 = 0;
        if (s->p2EC[0x60] & 2) {
            *(vu0_q *)&s->v300 = *(vu0_q *)&s->v220;
            vec_sub_ab(&d, &s->v300, obj + 0x10);
            d.z = 0.0f;
            func_0038CF68(&d, &d, -8.0f);
            vec_add_ab(&s->v300, &s->v300, &d);
            func_003C3A10(s->p2EC, 0xB, 0, 0xC);
        }
    }
    switch (obj[0x20]) {
    case 1:
    case 2:
        break;
    case 3:
        if ((obj[0x60] & 2) == 0) {
            goto Lend;
        }
        func_L20_003FB2A8(obj, 0x14, 0, 8);
        func_003C3A10(s->p2EC, 0xB, 0, 8);
        func_L01_004450F0(obj, 4, -1);
        break;
    case 4:
        if (func_L01_004561B8(obj) != 0) {
            *(vu0_q *)&s->v300 = *(vu0_q *)&s->v220;
            vec_sub_ab(&d, &s->v300, obj + 0x10);
            d.z = 0.0f;
            func_0038CF68(&d, &d, -8.0f);
            vec_add_ab(&s->v300, &s->v300, &d);
        }
        if (obj[0x42] == 5) {
            func_L01_0045A748(obj, (u8 *)s + 0x220);
        }
        hit = 1;
        if (s->w314 != -1) {
            if (func_L01_00456500((u8 *)s + 0x220, s->w314) != 0) {
                hit = 0;
            }
        }
        if (hit == 0) {
            goto L474;
        }
        if ((u16)(*(u16 *)(obj + 0xB2) - 0x3F) < 2) {
            goto L474;
        }
        if (!(func_0038CF38(obj + 0x10, (u8 *)s + 0x220) < 15.0f)) {
            goto L482;
        }
        if (!(func_0038DBA0(*(f32 *)(obj + 0xF8), func_0038D160(s->v220.x - *(f32 *)(obj + 0x10), s->v220.y - *(f32 *)(obj + 0x14))) < 0.08726646f)) {
            goto L482;
        }
L474:
        if (obj[0x43] == 2) {
            goto L482;
        }
        func_003C3A10(obj, 2, 0, 8);
L482:
        if (hit == 0) {
            goto L500;
        }
        if ((u16)(*(u16 *)(obj + 0xB2) - 0x3F) < 2) {
            goto L500;
        }
        if (20.0f < func_0038CF38(obj + 0x10, (u8 *)s + 0x220)) {
            goto L517;
        }
L500:
        if (!(0.7853982f < func_0038DBA0(*(f32 *)(obj + 0xF8), func_0038D160(s->v220.x - *(f32 *)(obj + 0x10), s->v220.y - *(f32 *)(obj + 0x14))))) {
            goto Lend;
        }
L517:
        if (obj[0x43] == 5) {
            goto Lend;
        }
        func_003C3A10(obj, 5, 0, 8);
        break;
    case 5:
        break;
    }
Lend:
    func_L20_003FB180(obj);
}
/* localdecomp:end func_L20_003FA478 */

/* localdecomp:start func_L20_003FACD8 */
extern s32 func_L20_003FAF10(void *);
extern void func_L20_003FB120(void *);
extern void func_L20_003FB1F0(void *);
extern s32 func_L01_00452FB0(void *, void *, s32, s32, s32);
extern s32 func_L01_00452860(void *, void *, s32);
extern void func_L01_0044FD88(void *, s32, s32, s32);
extern void func_L01_00456BD0(void *, s32);
extern void func_L01_00456C98(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32);

s32 func_L20_003FACD8(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);

    if (a0[0x20] == 0 && func_L20_003FAF10(a0) != 0) return 1;
    if (p[0x3E] == 2) goto done;
    if (func_L01_00452FB0(a0, p + 0x160, 0, 0, 0) != 0) func_L20_003FB1F0(a0);
    func_L01_00452860(a0, p + 0x30, 0);
    if (p[0x5E] != 0) {
done:
        func_L20_003FB120(a0);
        return 1;
    }
    func_L01_0044FD88(a0, *(s32 *)(p + 0x2EC), 0, 0);
    if (p[0x5F] != 0) {
        if ((*(unsigned long *)(a0 + 0x30) & 0x104100000000ul) != 0x4100000000ul || *(s32 *)(a0 + 0x98) != 0) {
            func_L01_00456BD0(a0, 5);
        }
        if (a0[0x95] == 0) func_L01_00456C98(a0, *(s32 *)(p + 0x2D0), 0, 0, 0, 0, 3, 0, 0, 0, *(f32 *)(p + 0x2D4), 10.0f, 1.0f);
        else func_L01_00456C98(a0, *(s32 *)(p + 0x2D8), 0, 0, 0, 0, 3, 0, 0, 0, *(f32 *)(p + 0x2DC), 10.0f, 1.0f);
    } else {
        if ((*(unsigned long *)(a0 + 0x30) & 0x104100000000ul) != 0x4100000000ul || *(s32 *)(a0 + 0x98) != 0) {
            func_L01_00456BD0(a0, 3);
        }
        if (a0[0x95] == 0) func_L01_00456C98(a0, *(s32 *)(p + 0x2D0), 0, 0, 0, 0, 1, 0, 0, 1, *(f32 *)(p + 0x2D4), 10.0f, 1.0f);
        else func_L01_00456C98(a0, *(s32 *)(p + 0x2D8), 0, 0, 0, 0, 1, 0, 0, 1, *(f32 *)(p + 0x2DC), 10.0f, 1.0f);
    }
    return 0;
}
/* localdecomp:end func_L20_003FACD8 */

/* localdecomp:start func_L20_003FAF10 */
typedef struct { u8 p0[0x24]; f32 f24; } C_003FAF10;
typedef struct {
    u8 p0[0x24]; C_003FAF10 *p24; u8 p28[4]; f32 f2C; u8 p30[2]; s16 h32; u16 h34;
    u8 p36[0x32]; u8 *p68; u8 p6C[0x2C]; s32 w98; u8 p9C[0x16]; s16 hB2;
} M_003FAF10;
typedef struct {
    u8 p0[0x30]; f32 f30; s16 h34; u8 p36[3]; u8 b39; u8 p3A[4]; u8 b3E; u8 p3F[1]; f32 f40;
    u8 p44[0x14]; u8 b58; u8 p59; u8 b5A; u8 p5B[0x15]; f32 f70; f32 f74; f32 f78; f32 f7C; f32 f80;
    u8 p84[0x18]; f32 f9C; f32 fA0; u8 pA4[8]; s32 wAC; u8 pB0[0xC0]; u8 b170; u8 p171[0x1F];
    f32 f190; f32 f194; u8 p198[4]; f32 f19C; u8 p1A0[8]; u8 b1A8; u8 p1A9[0x2E];
    u8 b1D7; u8 b1D8; u8 b1D9; u8 b1DA; u8 b1DB; u8 p1DC[0x64]; void *w240; u8 p244[0xA8];
    M_003FAF10 *w2EC; u8 p2F0[8]; s32 w2F8; u8 p2FC[0x14]; s32 w310;
} P_003FAF10;
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern u8 *func_003C24B0(s32, s32);
extern void func_L01_00456160(u8 *, u8 *);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L20_003FB2A8(void *, s32, s32, s32);
extern void func_L01_004AA7E8(void *, s32);

s32 func_L20_003FAF10(void *arg)
{
    M_003FAF10 *m = (M_003FAF10 *)arg;
    P_003FAF10 *p = (P_003FAF10 *)m->p68;
    u8 one;

    p->f190 = 0.5f;
    p->b170 = 6;
    p->b1A8 = 3;
    p->f19C = 0.15f;
    one = 1;
    p->b1DB = 0xFF;
    p->f194 = 0.5f;
    p->f70 = 0.7f;
    p->f74 = 0.5f;
    p->f78 = 0.75f;
    p->f7C = 1.0f;
    p->f80 = 1.4835298f;
    p->fA0 = 0.34906584f;
    p->f9C = 0.00392f;
    p->b1D7 = one;
    p->b1D8 = 0;
    p->b1D9 = 0;
    p->b1DA = 0;
    if (m->hB2 != 0x25) {
        p->wAC = p->w310;
    }
    func_L01_0045BD78(m, 0.0056000003f, 0.10000001f, 0.010053097f, 0.25132743f);
    p->b58 = 0x14;
    p->b5A = 0xE;
    if (p->h34 == 0) {
        p->h34 = 100;
        p->f30 = 100.0f;
    }
    p->b39 = one;
    p->b3E = one;
    p->f40 = 2.0f;
    p->w2EC = (M_003FAF10 *)func_003C24B0(0x1E00, 0x80);
    if (p->w2EC) {
        p->w240 = p->w2EC;
    }
    func_L01_00456160((u8 *)p->w2EC, (u8 *)m);
    m->h32 = 0xFF;
    m->f2C = m->p24->f24 + m->p24->f24;
    p->w2EC->f2C = p->w2EC->p24->f24 + p->w2EC->p24->f24;
    func_L01_004450F0(m, 1, 0);
    func_L20_003FB2A8(m, 0, 0, 0);
    if (p->w2F8) {
        m->w98 = 0;
        m->h34 = (m->h34 | 0x41) & 0xEFFF;
        func_L01_004AA7E8(m, 1);
    }
    return 0;
}
/* localdecomp:end func_L20_003FAF10 */
