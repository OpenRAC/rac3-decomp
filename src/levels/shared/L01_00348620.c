#include "common.h"

typedef struct {
    char pad0[0x10];
    char pos[0x2];
    s16 active;
    char pad14[0x18 - 0x14];
    f32 unk18;
    f32 unk1C;
    char pad20[0x40 - 0x20];
} Entry;
typedef struct {
    char pad0[0x1A];
    s16 unk1A;
} Vars;
typedef struct {
    char pad0[0x68];
    Vars *vars;
} Moby;
typedef struct {
    s32 unk0;
    s32 offset;
} Info;
typedef struct {
    u8 pad0[24];
    s32 x18;
    u8 pad1[20];
} S_27F600;
typedef struct {
    f32 f0;
    f32 f4;
    f32 f8;
    f32 fC;
    u8 f10[16];
} Src_0034C508;
typedef struct {
    u8 pad0[24];
    Src_0034C508 *src;
    u8 pad1C[20];
} Ent_0034C508;
typedef struct {
    u8 pad0[124];
    s32 f124;
    u8 pad128[8];
    s32 f136;
    u8 pad140[20];
} Sub_0034CC80;
typedef struct {
    u8 pad0[48];
    Sub_0034CC80 sub;
} Entry_0034CC80;
typedef int s128 __attribute__((mode(TI)));

INCLUDE_ASM("asm/levels", func_L01_00348620);

INCLUDE_ASM("asm/levels", func_L01_00348A98);

INCLUDE_ASM("asm/levels", func_L01_00348C88);

INCLUDE_ASM("asm/levels", func_L01_00348E30);

INCLUDE_ASM("asm/levels", func_L01_003493C8);

/* localdecomp:start func_L01_00349538 */




extern char *func_L01_00457480(s32, s32);
extern Info *func_L01_004574B0(s32, s32);
extern s32 func_0038CB00(void *);
extern f32 func_0038DAB8(f32, f32);

s32 func_L01_00349538(Moby *m) {
    Vars *v = m->vars;
    Entry *e;
    s32 i;
    s32 count = 0;

    e = (Entry *)(func_L01_00457480(3076, v->unk1A) + func_L01_004574B0(3076, v->unk1A)->offset);
    for (i = 0; i < 120; i++) {
        if (e[i].active != 0) {
            if (func_0038CB00(e[i].pos) != 0) {
                e[i].active = 0;
            } else {
                count++;
                e[i].unk18 = func_0038DAB8(e[i].unk18, e[i].unk1C);
            }
        }
    }
    return count;
}
/* localdecomp:end func_L01_00349538 */

INCLUDE_ASM("asm/levels", func_L01_003495F0);

INCLUDE_ASM("asm/levels", func_L01_00349998);

INCLUDE_ASM("asm/levels", func_L01_00349C58);

INCLUDE_ASM("asm/levels", func_L01_0034A3C8);

INCLUDE_ASM("asm/levels", func_L01_0034ACD8);

INCLUDE_ASM("asm/levels", func_L01_0034C300);

INCLUDE_ASM("asm/levels", func_L01_0034C378);

INCLUDE_ASM("asm/levels", func_L01_0034C4E0);

INCLUDE_ASM("asm/levels", func_L01_0034C4E8);

/* localdecomp:start func_L01_0034C910 */
extern void func_L01_0043B9E8(void *, s32, s32, s32);

void func_L01_0034C910(u8 *s) {
    u8 *m;

    func_L01_0043B9E8(*(u8 **)(s + 0x18), s[4], s[5], s[6]);
    m = *(u8 **)(s + 0x18);
    if (*(u16 *)(m + 0x34) & 0x20) {
        u8 *p = *(u8 **)(*(u8 **)(m + 0x68) + 0x10);
        if (p != 0 && *(s16 *)p != 0) {
            p[4] = s[4];
            p[5] = *(s32 *)(s + 4) >> 8;
            p[6] = *(s32 *)(s + 4) >> 16;
        }
    }
}
/* localdecomp:end func_L01_0034C910 */

/* localdecomp:start func_L01_0034C990 */

extern S_27F600 D_L01_0027F580[];

s32 func_L01_0034C990(s32 id) {
    s32 r = -1;
    s32 i;

    for (i = 0; i < 30; i++) {
        if (D_L01_0027F580[i].x18 == id) {
            r = i;
            break;
        }
    }
    return r;
}
/* localdecomp:end func_L01_0034C990 */

INCLUDE_ASM("asm/levels", func_L01_0034C9F0);

INCLUDE_ASM("asm/levels", func_L01_0034CE70);

INCLUDE_ASM("asm/levels", func_L01_0034CEB8);

/* localdecomp:start func_L01_0034CF88 */
extern S_27F600 D_L01_0027F580[];
extern void func_003C5180(void *, f32 *, s32);
extern void func_0038CE20(f32 *, f32 *, f32);
extern void func_L01_0034D700(s32);
void func_L01_0034CF88(s32 a) {
    f32 v[4];
    Ent_0034C508 *p;
    s32 i;
    f32 k1;
    f32 k2;
    p = ((Ent_0034C508 *)&D_L01_0027F580);
    k1 = 0.000976499985f;
    k2 = 0.850000024f;
    for (i = 0; i < 30; i++, p++) {
        if (p->src != 0) {
            func_003C5180(p->src->f10, v, 1);
            func_0038CE20(v, v, p->src->fC * k1 * k2);
            v[0] += p->src->f0 * k1;
            v[1] += p->src->f4 * k1;
            v[2] += p->src->f8 * k1;
        }
    }
    func_L01_0034D700(a);
}
/* localdecomp:end func_L01_0034CF88 */

INCLUDE_ASM("asm/levels", func_L01_0034D078);

INCLUDE_ASM("asm/levels", func_L01_0034D2F0);

/* localdecomp:start func_L01_0034D700 */


extern Entry_0034CC80 D_L01_0027FB20[];
extern void func_L01_0034D9E0(s32, Entry_0034CC80 *);
extern s32 func_00382498(s32, s32);
extern f32 func_00382538(void);
extern void func_003D9508(void *, s32, s32, s32, f32, f32, f32);

void func_L01_0034D700(s32 arg0) {
    s32 i;
    Entry_0034CC80 *e;
    Sub_0034CC80 *s;

    for (i = 47; i >= 0; i--) {
        e = &D_L01_0027FB20[47 - i];
        s = &e->sub;
        if (s->f124 == arg0) {
            func_L01_0034D9E0(arg0, e);
            if (s->f136 == 0) {
                func_003D9508(s, 49, (func_00382498(80, 96) << 24) | 0x103080, 1, 0.5f, 0.1f, func_00382538());
                func_003D9508(s, 49, (func_00382498(80, 96) << 24) | 0xFFFFFF, 1, 0.5f, 0.1f, func_00382538());
            }
        }
    }
}
/* localdecomp:end func_L01_0034D700 */

/* localdecomp:start func_L01_0034D840 */
void func_L01_0034D840(u8 *p)
{
    *(unsigned long *)(p + 128) = 0xFF9000000260;
    *(unsigned long *)(p + 112) = 0;
    *(f32 *)(p + 80) = 0.0f;
    *(f32 *)(p + 84) = 0.0f;
    *(f32 *)(p + 88) = 1.0f;
    *(f32 *)(p + 92) = 0.0f;
    *(f32 *)(p + 96) = 0.0f;
    *(f32 *)(p + 100) = 1.0f;
    *(f32 *)(p + 104) = 1.0f;
    *(f32 *)(p + 108) = 1.0f;
    *(f32 *)(p + 8) = -1.0f;
    *(f32 *)(p + 24) = 1.0f;
    *(f32 *)(p + 40) = -1.0f;
    *(f32 *)(p + 56) = 1.0f;
    *(f32 *)(p + 4) = -1.0f;
    *(f32 *)(p + 36) = 1.0f;
    *(f32 *)(p + 52) = 1.0f;
    *(f32 *)(p + 0) = 0.0f;
    *(f32 *)(p + 16) = 0.0f;
    *(f32 *)(p + 32) = 0.0f;
    *(f32 *)(p + 48) = 0.0f;
    *(f32 *)(p + 12) = 1.0f;
    *(f32 *)(p + 28) = 1.0f;
    *(f32 *)(p + 20) = -1.0f;
    *(f32 *)(p + 44) = 1.0f;
    *(f32 *)(p + 60) = 1.0f;
}
/* localdecomp:end func_L01_0034D840 */

INCLUDE_ASM("asm/levels", func_L01_0034D8C8);

INCLUDE_ASM("asm/levels", func_L01_0034D9E0);

INCLUDE_ASM("asm/levels", func_L01_0034DBA8);

INCLUDE_ASM("asm/levels", func_L01_0034DBE8);

INCLUDE_ASM("asm/levels", func_L01_0034E080);

INCLUDE_ASM("asm/levels", func_L01_0034E558);

INCLUDE_ASM("asm/levels", func_L01_0034E808);

INCLUDE_ASM("asm/levels", func_L01_0034E9E0);

INCLUDE_ASM("asm/levels", func_L01_0034EAA0);

INCLUDE_ASM("asm/levels", func_L01_0034F0B0);

INCLUDE_ASM("asm/levels", func_L01_0034F168);

INCLUDE_ASM("asm/levels", func_L01_0034F7E8);

/* localdecomp:start func_L01_0034F7F0 */
extern s32 D_L01_001E2EC4[];
extern f32 D_L01_001E2EC8[];
extern s32 D_L01_001E1A0C;
extern s32 D_001D545C;
extern s128 D_L01_002B2AB0[];
extern void func_L01_0034FA00(u8 *);
extern f32 func_L01_0034F908(u8 *);
extern void func_L01_0034FC28(void);
extern void func_L01_00404808(void (*)(void), u8 *);
void func_L01_0034F7F0(u8 *m) {
    s128 *v = *(s128 **)(m + 104);
    s32 t;
    s32 i;
    switch (m[32]) {
    case 0:
        m[48] = 255;
        m[32] = 1;
        D_L01_001E2EC4[0] = 0;
        t = D_001D545C;
        i = 0;
        if (t == 1) {
            D_L01_001E1A0C = 100;
        } else if (t == 2) {
            D_L01_001E1A0C = 101;
            i = 1;
        } else if (t == 5) {
            D_L01_001E1A0C = 105;
            i = 2;
        } else if (t == 16) {
            D_L01_001E1A0C = 100;
            i = 3;
        } else if (t == 26) {
            D_L01_001E1A0C = 100;
            i = 5;
        }
        *v = D_L01_002B2AB0[i];
        func_L01_0034FA00(m);
        break;
    case 1:
        D_L01_001E2EC8[0] = func_L01_0034F908(m);
        func_L01_00404808(func_L01_0034FC28, m);
        break;
    }
}
/* localdecomp:end func_L01_0034F7F0 */

INCLUDE_ASM("asm/levels", func_L01_0034F908);

INCLUDE_ASM("asm/levels", func_L01_0034FA00);

INCLUDE_ASM("asm/levels", func_L01_0034FC28);

INCLUDE_ASM("asm/levels", func_L01_0034FFE8);
