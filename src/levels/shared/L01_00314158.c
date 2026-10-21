#include "common.h"

typedef struct {
    u8 *obj;
    s32 col;
    s32 pad8;
    f32 t;
    u8 pad10[16];
} Ent_003153D8;
typedef struct {
    f32 v[4][4];
    u8 pad40[0x10];
    f32 w[4][2];
    unsigned long d70;
    u8 pad78[8];
    unsigned long d80;
} Obj317488;
typedef struct {
    u8 pad0[56];
    s32 w56;
    s32 w60;
} S_00142660;
typedef struct {
    u8 pad[8];
    s32 x8;
} S_142660;
typedef struct { u8 pad[20]; s32 id; u8 pad2[8]; } E_31ABE0;
typedef int u128_t __attribute__((mode(TI)));

INCLUDE_ASM("asm/levels", func_L01_00314158);

INCLUDE_ASM("asm/levels", func_L01_00314620);

INCLUDE_ASM("asm/levels", func_L01_00314C90);

INCLUDE_ASM("asm/levels", func_L01_00315350);

INCLUDE_ASM("asm/levels", func_L01_003155A8);

/* localdecomp:start func_L01_00315800 */

extern Ent_003153D8 D_L01_00271B40[];
extern u8 **func_L01_00448FB8(u8 *);
extern s32 func_0038DBD8(s32, s32, f32);
extern void func_L01_0043B9E8(u8 *, s32, s32, s32);

void func_L01_00315800(s32 i, s32 a1) {
    s32 a;
    u8 **v;
    s32 c;
    s32 g;
    s32 b;

    a = (s32)(D_L01_00271B40[i].t * 96.0f);
    D_L01_00271B40[i].obj[35] = a;
    v = func_L01_00448FB8(D_L01_00271B40[i].obj);
    if (v != 0 && *v != 0) {
        (*v)[35] = a;
    }
    c = func_0038DBD8(a1, D_L01_00271B40[i].col, D_L01_00271B40[i].t);
    b = (c >> 16) & 0xFF;
    g = (c >> 8) & 0xFF;
    func_L01_0043B9E8(D_L01_00271B40[i].obj, c & 0xFF, g, b);
}
/* localdecomp:end func_L01_00315800 */

/* localdecomp:start func_L01_003158D0 */
extern Ent_003153D8 D_L01_00271B40[];
extern s32 D_L01_001E1740;
extern void func_0038CBA0(void *, s32);

void func_L01_003158D0(void) {
    func_0038CBA0(((u8 *)&D_L01_00271B40), 2048);
    D_L01_001E1740 = 0;
}
/* localdecomp:end func_L01_003158D0 */

INCLUDE_ASM("asm/levels", func_L01_00315900);

INCLUDE_ASM("asm/levels", func_L01_00315A60);

INCLUDE_ASM("asm/levels", func_L01_003163D0);

INCLUDE_ASM("asm/levels", func_L01_00316DA0);

INCLUDE_ASM("asm/levels", func_L01_00316E38);

/* localdecomp:start func_L01_00316F50 */
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);

void func_L01_00316F50(s32 a0, f32 *e, s32 n)
{
    s32 i;
    f32 *p;

    for (i = 0; i < n; i++) {
        p = &e[i * 32];
        p[0] = func_0038DAB8(p[0], p[3]);
        p[1] = func_0038DAB8(p[1], p[4]);
        p[2] = func_0038DAB8(p[2], p[5]);
        p[9] = func_0038DAB8(p[9], p[12]);
        p[10] = func_0038DAB8(p[10], p[13]);
        p[11] = func_0038DAB8(p[11], p[14]);
        p[20] = func_0038D098(p[0]) * p[6];
        p[21] = func_0038D0B0(p[1]) * p[7];
        p[22] = -func_0038D0B0(p[2]) * p[8];
        p[24] = func_0038D098(p[9]) * p[15];
        p[25] = func_0038D0B0(p[10]) * p[16];
        p[26] = -func_0038D0B0(p[11]) * p[17];
    }
}
/* localdecomp:end func_L01_00316F50 */

INCLUDE_ASM("asm/levels", func_L01_00317070);

LINKER_REMNANT("asm/levels", func_L01_00317230);

INCLUDE_ASM("asm/levels", func_L01_00317238);

INCLUDE_ASM("asm/levels", func_L01_00317370);

/* localdecomp:start func_L01_003173B0 */
extern s32 func_00382498(s32, s32);
extern f32 func_003824E0(f32, f32);
extern f32 func_00382538(void);
extern void func_003D9508(s32, s32, s32, s32, f32, f32, f32);

void func_L01_003173B0(s32 unused, s32 target, u32 color, s32 n, f32 scale) {
    f32 size;
    color |= func_00382498(n >> 1, n) << 24;
    size = func_003824E0(scale * 0.75f, scale);
    size = size + size;
    func_003D9508(target, 44, color, 1, size, 0.08f, func_00382538());
}
/* localdecomp:end func_L01_003173B0 */

INCLUDE_ASM("asm/levels", func_L01_00317440);

/* localdecomp:start func_L01_003178B8 */

void func_L01_003178B8(Obj317488 *o) {
    o->d80 = 0xFF9000000260;
    o->d70 = 0;
    o->w[0][0] = 0;
    o->w[1][0] = 0;
    o->w[2][0] = 1.0f;
    o->w[3][0] = 1.0f;
    o->w[0][1] = 0;
    o->w[1][1] = 1.0f;
    o->w[2][1] = 0;
    o->w[3][1] = 1.0f;
    o->v[0][2] = -2.0f;
    o->v[1][2] = 2.0f;
    o->v[2][2] = -2.0f;
    o->v[3][2] = 2.0f;
    o->v[0][1] = -2.0f;
    o->v[1][1] = -2.0f;
    o->v[2][1] = 2.0f;
    o->v[3][1] = 2.0f;
    o->v[0][0] = 0;
    o->v[1][0] = 0;
    o->v[2][0] = 0;
    o->v[3][0] = 0;
    o->v[0][3] = 1.0f;
    o->v[1][3] = 1.0f;
    o->v[2][3] = 1.0f;
    o->v[3][3] = 1.0f;
}
/* localdecomp:end func_L01_003178B8 */

INCLUDE_ASM("asm/levels", func_L01_00317948);

INCLUDE_ASM("asm/levels", func_L01_003179F0);

/* localdecomp:start func_L01_00317C48 */

extern u8 D_001A4C60[];
extern s32 D_001D545C;
extern u8 D_001BBC40[];
extern s32 D_L01_001EFC80[][3];
extern s32 D_L01_001EFD40[][3];
extern S_00142660 D_00142660;
extern s32 func_00382380(void *, s32, s32);
extern s32 func_L01_00400430(s32);

void func_L01_00317C48(u8 *a0) {
    s32 *p = *(s32 **)(a0 + 104);
    u8 *q;
    s32 r;
    s32 sh;
    u8 v;

    if (a0[32] == 0) {
        a0[48] = 255;
        a0[32]++;
    }
    if (func_00382380(D_001A4C60, p[1], 0) == 0) {
        return;
    }
    D_001A4C60[9591] = a0[176];
    if (p[2] != 0) {
        return;
    }
    if ((D_001BBC40[a0[176] + D_001D545C * 16] >> (a0[177] * 2)) & 3) {
        return;
    }
    p[2] = 1;
    r = func_L01_00400430(a0[176]);
    q = &D_001BBC40[(a0[176] & 15) + D_001D545C * 16];
    sh = (a0[177] & 3) * 2;
    v = *q;
    if ((v >> sh) & 3) {
        return;
    }
    *q = (v & ~(3 << sh)) | (r << sh);
    D_00142660.w56 += D_L01_001EFC80[a0[176] & 15][a0[177] & 3];
    D_00142660.w60 += D_L01_001EFD40[a0[176] & 15][a0[177] & 3];
}
/* localdecomp:end func_L01_00317C48 */

INCLUDE_ASM("asm/levels", func_L01_00317DF0);

INCLUDE_ASM("asm/levels", func_L01_00318408);

/* localdecomp:start func_L01_003185E8 */
extern s32 D_L01_001DC7DC;

void func_L01_003185E8(void) { D_L01_001DC7DC = 0; }
/* localdecomp:end func_L01_003185E8 */

INCLUDE_ASM("asm/levels", func_L01_003185F0);

INCLUDE_ASM("asm/levels", func_L01_003186A8);

/* localdecomp:start func_L01_00318818 */
extern S_00142660 D_00142660;

extern s32 D_L01_002AC240[];

s32 func_L01_00318818(void) {
    S_142660 *g = &(*(S_142660 *)&D_00142660);
    s32 *t;
    s32 r = 0;
    s32 i = 0;

    for (t = D_L01_002AC240; i < 19; i++, t++) {
        if (g->x8 < *t) break;
        if (g->x8 == *t) {
            r = 1;
            break;
        }
    }
    return r;
}
/* localdecomp:end func_L01_00318818 */

INCLUDE_ASM("asm/levels", func_L01_00318878);

INCLUDE_ASM("asm/levels", func_L01_003189B0);

INCLUDE_ASM("asm/levels", func_L01_00318AF8);

INCLUDE_ASM("asm/levels", func_L01_00318C30);

INCLUDE_ASM("asm/levels", func_L01_00318D80);

INCLUDE_ASM("asm/levels", func_L01_00318E68);

/* localdecomp:start func_L01_00318FB8 */
void func_L01_00318FB8(u8 *p)
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
/* localdecomp:end func_L01_00318FB8 */

/* localdecomp:start func_L01_00319040 */
extern void func_0038CE20(f32 *, f32 *, f32);
void func_L01_00319040(f32 *m, f32 s) {
    func_0038CE20(m, m, s);
    func_0038CE20(m + 4, m + 4, s);
    func_0038CE20(m + 8, m + 8, s);
    func_0038CE20(m + 12, m + 12, s);
}
/* localdecomp:end func_L01_00319040 */

INCLUDE_ASM("asm/levels", func_L01_003190A8);

INCLUDE_ASM("asm/levels", func_L01_00319258);

INCLUDE_ASM("asm/levels", func_L01_00319480);

INCLUDE_ASM("asm/levels", func_L01_00319718);

INCLUDE_ASM("asm/levels", func_L01_00319880);

INCLUDE_ASM("asm/levels", func_L01_00319A48);

INCLUDE_ASM("asm/levels", func_L01_00319A88);

INCLUDE_ASM("asm/levels", func_L01_00319F00);

INCLUDE_ASM("asm/levels", func_L01_0031A518);

INCLUDE_ASM("asm/levels", func_L01_0031A560);

/* localdecomp:start func_L01_0031A7D8 */
extern u8 func_L01_0031A820[];
extern void func_L01_00404A10_0031A7D8(void *a0, u8 *a1);
void func_L01_0031A7D8(u8 *a0) {
    if (a0[32] == 0) {
        a0[32] = 1;
        *(f32 *)(a0 + 192) = 1.0f;
        *(f32 *)(a0 + 212) = 1.0f;
        *(f32 *)(a0 + 232) = 1.0f;
    }
    func_L01_00404A10_0031A7D8(func_L01_0031A820, a0);
}
/* localdecomp:end func_L01_0031A7D8 */

INCLUDE_ASM("asm/levels", func_L01_0031A820);

/* localdecomp:start func_L01_0031AAA8 */
extern u8 func_L01_0031AAF0[];
extern void func_L01_00404A10_0031AAA8(void *a0, u8 *a1);
void func_L01_0031AAA8(u8 *a0) {
    if (a0[32] == 0) {
        a0[32] = 1;
        *(f32 *)(a0 + 192) = 1.0f;
        *(f32 *)(a0 + 212) = 1.0f;
        *(f32 *)(a0 + 232) = 1.0f;
    }
    func_L01_00404A10_0031AAA8(func_L01_0031AAF0, a0);
}
/* localdecomp:end func_L01_0031AAA8 */

INCLUDE_ASM("asm/levels", func_L01_0031AAF0);

INCLUDE_ASM("asm/levels", func_L01_0031AD78);

/* localdecomp:start func_L01_0031AFB8 */
extern void func_L01_0043B9E8(u8 *, s32, s32, s32);

void func_L01_0031AFB8(u8 *s) {
    u8 *m;
    u8 *q;

    func_L01_0043B9E8(*(u8 **)(s + 20), s[4], s[5], s[6]);
    m = *(u8 **)(s + 20);
    if (*(u16 *)(m + 52) & 0x20) {
        q = *(u8 **)(*(u8 **)(m + 104) + 16);
        if (q != 0 && *(s16 *)q != 0) {
            q[4] = s[4];
            q[5] = *(s32 *)(s + 4) >> 8;
            q[6] = *(s32 *)(s + 4) >> 16;
        }
    }
}
/* localdecomp:end func_L01_0031AFB8 */

/* localdecomp:start func_L01_0031B038 */
extern E_31ABE0 D_L01_00274580[];
s32 func_L01_0031B038(s32 a0) {
    s32 r = -1;
    s32 i;
    for (i = 0; i < 30; i++) {
        if (D_L01_00274580[i].id == a0) {
            r = i;
            break;
        }
    }
    return r;
}
/* localdecomp:end func_L01_0031B038 */

INCLUDE_ASM("asm/levels", func_L01_0031B090);

INCLUDE_ASM("asm/levels", func_L01_0031B358);

INCLUDE_ASM("asm/levels", func_L01_0031B3A0);

INCLUDE_ASM("asm/levels", func_L01_0031B4F8);

INCLUDE_ASM("asm/levels", func_L01_0031B810);

LINKER_REMNANT("asm/levels", func_L01_0031BC68);

/* localdecomp:start func_L01_0031BC78 */

extern void func_L01_0031BCA0(u8 *, u128_t *);

void func_L01_0031BC78(u8 *obj) {
    u128_t v;
    v = **(u128_t **)(obj + 104);
    func_L01_0031BCA0(obj, &v);
}
/* localdecomp:end func_L01_0031BC78 */

INCLUDE_ASM("asm/levels", func_L01_0031BCA0);

INCLUDE_ASM("asm/levels", func_L01_0031C100);
