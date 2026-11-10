#include "common.h"

typedef struct S_006CD768 {
    u8 f0;
    u8 pad1[7];
    u8 f8;
    u8 pad9[3];
    s32 fC;
} S_006CD768;

INCLUDE_ASM("asm/levels", func_L39_006CCE90);

INCLUDE_ASM("asm/levels", func_L39_006CD038);

/* localdecomp:start func_L39_006CD1B8 */
typedef struct { u8 bytes[32]; } __attribute__((packed)) Block_6CD1B8;
typedef struct { u8 pad[0x2d]; u8 f2D; u8 pad2[6]; Block_6CD1B8 f34; } Target_6CD1B8;
typedef struct { u8 pad[0x1d]; u8 f1D; u8 pad2[0x12]; Target_6CD1B8 *f30; } Global_6CD1B8;
__asm__(".extern D_L39_0024D760, 16");
extern void *D_L39_0024D760;

/* from rac4-decomp's func_L00_00765F58 */
void func_L39_006CD1B8(Block_6CD1B8 *arg) {
    Global_6CD1B8 *g = ((Global_6CD1B8 *)D_L39_0024D760);
    Target_6CD1B8 *t = g->f30;
    if (g->f1D == 0) {
        t->f34 = *arg;
        t->f2D = 0;
    }
}
/* localdecomp:end func_L39_006CD1B8 */

/* localdecomp:start func_L39_006CD218 */
__asm__(".extern D_L39_0024D760, 16");
typedef struct { int words[7]; } Data_006CD218;
typedef struct { char pad[0x2E]; unsigned char flag; char pad2[0xE9]; Data_006CD218 data; } Target_006CD218;
typedef struct { char pad[0x1D]; unsigned char flag; char pad2[0x12]; Target_006CD218 *target; } Global_006CD218;

/* from rac4-decomp's func_L00_00765FB8 */
void func_L39_006CD218(Data_006CD218 *arg) {
    Global_006CD218 *g = ((Global_006CD218 *)D_L39_0024D760);
    Target_006CD218 *t = g->target;
    if (!g->flag) {
        t->data = *arg;
        t->flag = 0;
    }
}
/* localdecomp:end func_L39_006CD218 */

/* localdecomp:start func_L39_006CD270 */
__asm__(".extern D_L39_0024D760, 16");
typedef struct { int words[7]; } Data_6CD270;
typedef struct { char pad[0x2F]; unsigned char flag; char pad2[0xE8]; Data_6CD270 data; } Target_6CD270;
typedef struct { char pad[0x1D]; unsigned char flag; char pad2[0x12]; Target_6CD270 *target; } Global_6CD270;

/* from rac4-decomp's func_L00_00765FB8 */
void func_L39_006CD270(Data_6CD270 *arg) {
    Global_6CD270 *g = ((Global_6CD270 *)D_L39_0024D760);
    Target_6CD270 *t = g->target;
    if (!g->flag) {
        t->data = *arg;
        t->flag = 0;
    }
}
/* localdecomp:end func_L39_006CD270 */

INCLUDE_ASM("asm/levels", func_L39_006CD2C8);

INCLUDE_ASM("asm/levels", func_L39_006CD488);

/* localdecomp:start func_L39_006CD540 */
typedef struct { u8 a; u8 p[3]; s32 b; } E_006CD540;
typedef struct { E_006CD540 e[2]; s32 c; u8 d; u8 q[7]; u8 f; } S_006CD540;
S_006CD540 *func_L39_006CD540(S_006CD540 *s) {
    s->e[0].a = 0; s->e[0].b = -1;
    s->e[1].a = 0; s->e[1].b = -1;
    s->c = -1;
    s->d = 0;
    s->f = 0;
    return s;
}
/* localdecomp:end func_L39_006CD540 */

/* localdecomp:start func_L39_006CD568 */
typedef struct S_006CD568 {
    s32 pad0;
    s32 a4;
    u8 b8;
    u8 p9[3];
    s32 aC;
    s32 a10;
    u8 b14;
    u8 p15[7];
    u8 b1C;
} S_006CD568;
void func_L39_006CD568(S_006CD568 *arg0) {
    arg0->a4 = -1;
    arg0->b8 = 0;
    arg0->aC = -1;
    arg0->a10 = -1;
    arg0->b14 = 0;
    arg0->b1C = 0;
}
/* localdecomp:end func_L39_006CD568 */

/* localdecomp:start func_L39_006CD588 */
s32 func_L39_006E16A0(s32, s32, s32, s32);

s32 func_L39_006CD588(u32 arg0, s32 arg1) {
    u32 r = arg0;
    u32 m;
    u32 rem;
    u32 a;
    r += func_L39_006E16A0(r, arg1 * 2, 0xD0, 4);
    m = 4;
    rem = r % m;
    a = r;
    if (rem != 0) {
        a = r + (m - rem);
    }
    r = a;
    r += arg1 * 8;
    return r - arg0;
}
/* localdecomp:end func_L39_006CD588 */

INCLUDE_ASM("asm/levels", func_L39_006CD5F0);

/* localdecomp:start func_L39_006CD6E0 */
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
s32 func_L39_006CD768(u8 *);

s32 func_L39_006CD6E0(u8 *arg0) {
    s32 result = 1;

    if (arg0[0] != 0) {
        if (arg0[8] != 0) {
            if (((s32) func_00130760(func_0012DCB0(), 0x24000) - *(s32 *) (arg0 + 0xC)) >= 0x3A99) {
                arg0[8] = 0;
                result = 0;
                func_L39_006CD768(arg0);
            }
        }
    }
    return result;
}
/* localdecomp:end func_L39_006CD6E0 */

/* localdecomp:start func_L39_006CD768 */
extern u16 D_L39_00249BC0[];
extern u8 D_001976F0[];
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern s32 func_0017F7D8(u16 *, u8 *, s32);
extern void func_001961E8(s32);
extern s32 func_001961F8(void);

s32 func_L39_006CD768(u8 *arg0) {
    S_006CD768 *p = (S_006CD768 *)arg0;
    s32 r = 1;
    u16 x[16];

    if (p->f0 != 0) {
        x[0] = D_L39_00249BC0[0];
        p->f8 = 1;
        p->fC = (s32) func_00130760(func_0012DCB0(), 0x24000);
        func_001961E8(func_0017F7D8(x, D_001976F0, 0));
        if (func_001961F8() != 0) {
            p->f8 = 0;
            r = 0;
        }
    }
    return r;
}
/* localdecomp:end func_L39_006CD768 */

INCLUDE_ASM("asm/levels", func_L39_006CD808);

INCLUDE_ASM("asm/levels", func_L39_006CDC30);

/* localdecomp:start func_L39_006CDD90 */
typedef struct {
    u8 pad0[0x14];
    s8 f14;
    s32 f18;
} S_6CDD90_B;
typedef struct {
    u8 pad0[0x34];
    S_6CDD90_B *f34;
} S_6CDD90_A;
__asm__(".extern D_L39_0024D760, 16");

/* from rac4-decomp's func_L00_00766C00 */
void func_L39_006CDD90(S_6CDD90_B *arg0) {
    S_6CDD90_B *p = ((S_6CDD90_A *)D_L39_0024D760)->f34;
    p->f14 = 0;
    p->f18 = arg0->f18;
}
/* localdecomp:end func_L39_006CDD90 */

INCLUDE_ASM("asm/levels", func_L39_006CDDB0);

/* localdecomp:start func_L39_006CDF18 */
__asm__(".extern D_L39_0024D760, 16");
typedef struct { u8 pad0[0x1C]; s8 f1C; u8 pad1[3]; s32 f20; } Sub_6CDF18;
typedef struct { u8 pad0[0x34]; Sub_6CDF18 *f34; } Obj_6CDF18;

/* from rac4-decomp's func_L00_00766DB0 */
void func_L39_006CDF18(s32 *arg0) {
    Sub_6CDF18 *s = ((Obj_6CDF18 *)D_L39_0024D760)->f34;
    s->f1C = 0;
    s->f20 = arg0[6];
}
/* localdecomp:end func_L39_006CDF18 */

/* localdecomp:start func_L39_006CDF38 */
void func_L39_006CDF38(void *arg0) {
    *(s8 *)((u8 *)arg0 + 0x34) = 0;
    *(s8 *)((u8 *)arg0 + 0x5C) = 0;
    *(s8 *)((u8 *)arg0 + 0x64) = 0;
    *(s8 *)((u8 *)arg0 + 0x6C) = 0;
    *(s8 *)((u8 *)arg0 + 0x7C) = 0;
    *(s8 *)((u8 *)arg0 + 0x84) = 0;
    *(s8 *)((u8 *)arg0 + 0x8C) = 0;
    *(s8 *)((u8 *)arg0 + 0x94) = 0;
    *(s8 *)((u8 *)arg0 + 0x9C) = 0;
    *(s8 *)((u8 *)arg0 + 0xA4) = 0;
    *(s8 *)((u8 *)arg0 + 0xAC) = 0;
    *(s8 *)((u8 *)arg0 + 0xB4) = 0;
    *(s8 *)((u8 *)arg0 + 0xBC) = 0;
    *(s8 *)((u8 *)arg0 + 0xC4) = 0;
    *(s8 *)((u8 *)arg0 + 0xCC) = 0;
    *(s8 *)((u8 *)arg0 + 0xD4) = 0;
    *(s8 *)((u8 *)arg0 + 0x220) = 0;
    *(s8 *)((u8 *)arg0 + 0x38C) = 0;
    *(s32 *)((u8 *)arg0 + 0x3B8) = -1;
    *(s8 *)((u8 *)arg0 + 0x3BC) = 0;
    *(s32 *)((u8 *)arg0 + 0x3C0) = -1;
    *(s32 *)((u8 *)arg0 + 0x3C4) = -1;
    *(s32 *)((u8 *)arg0 + 0x3F0) = -1;
    *(s8 *)((u8 *)arg0 + 0x3F4) = 0;
    *(s32 *)((u8 *)arg0 + 0x3F8) = -1;
    *(s32 *)((u8 *)arg0 + 0x3FC) = -1;
    *(s32 *)((u8 *)arg0 + 0x428) = -1;
    *(s8 *)((u8 *)arg0 + 0x42C) = 0;
    *(s32 *)((u8 *)arg0 + 0x430) = -1;
    *(s32 *)((u8 *)arg0 + 0x434) = -1;
    *(s32 *)((u8 *)arg0 + 0x460) = -1;
    *(s8 *)((u8 *)arg0 + 0x464) = 0;
    *(s32 *)((u8 *)arg0 + 0x468) = -1;
    *(s32 *)((u8 *)arg0 + 0x46C) = -1;
    *(s32 *)((u8 *)arg0 + 0x4A0) = -1;
    *(s8 *)((u8 *)arg0 + 0x4A4) = 0;
    *(s32 *)((u8 *)arg0 + 0x4A8) = -1;
    *(s32 *)((u8 *)arg0 + 0x4AC) = -1;
    *(s32 *)((u8 *)arg0 + 0x4E0) = -1;
    *(s8 *)((u8 *)arg0 + 0x4E4) = 0;
    *(s32 *)((u8 *)arg0 + 0x4E8) = -1;
    *(s32 *)((u8 *)arg0 + 0x4EC) = -1;
    *(s32 *)((u8 *)arg0 + 0x518) = -1;
    *(s8 *)((u8 *)arg0 + 0x51C) = 0;
    *(s32 *)((u8 *)arg0 + 0x520) = -1;
    *(s32 *)((u8 *)arg0 + 0x524) = -1;
    *(s32 *)((u8 *)arg0 + 0x0) = -1;
}
/* localdecomp:end func_L39_006CDF38 */

/* localdecomp:start func_L39_006CE000 */
s32 func_L39_006E16A0(s32, s32, s32, s32);

s32 func_L39_006CE000(u32 arg0, s32 arg1) {
    u32 r = arg0;
    u32 m;
    u32 rem;
    u32 a;
    r += func_L39_006E16A0(r, arg1 * 2, 0x1DC, 4);
    m = 4;
    rem = r % m;
    a = r;
    if (rem != 0) {
        a = r + (m - rem);
    }
    r = a;
    r += arg1 * 8;
    return r - arg0;
}
/* localdecomp:end func_L39_006CE000 */

INCLUDE_ASM("asm/levels", func_L39_006CE068);

/* localdecomp:start func_L39_006CE150 */
s32 func_L39_006E16A0(s32, s32, s32, s32);

s32 func_L39_006CE150(u32 arg0, s32 arg1) {
    u32 r = arg0;
    u32 m;
    u32 rem;
    u32 a;
    r += func_L39_006E16A0(r, arg1 * 2, 0xD4, 4);
    m = 4;
    rem = r % m;
    a = r;
    if (rem != 0) {
        a = r + (m - rem);
    }
    r = a;
    r += arg1 * 8;
    return r - arg0;
}
/* localdecomp:end func_L39_006CE150 */

INCLUDE_ASM("asm/levels", func_L39_006CE1B8);

/* localdecomp:start func_L39_006CE2A0 */
s32 func_L39_006E16A0(s32, s32, s32, s32);

s32 func_L39_006CE2A0(u32 arg0, s32 arg1) {
    u32 r = arg0;
    u32 m;
    u32 rem;
    u32 a;
    r += func_L39_006E16A0(r, arg1 * 2, 0x114, 4);
    m = 4;
    rem = r % m;
    a = r;
    if (rem != 0) {
        a = r + (m - rem);
    }
    r = a;
    r += arg1 * 8;
    return r - arg0;
}
/* localdecomp:end func_L39_006CE2A0 */

INCLUDE_ASM("asm/levels", func_L39_006CE308);

/* localdecomp:start func_L39_006CE3F0 */
s32 func_L39_006E16A0(s32, s32, s32, s32);

s32 func_L39_006CE3F0(u32 arg0, s32 arg1) {
    u32 r = arg0;
    u32 m;
    u32 rem;
    u32 a;
    r += func_L39_006E16A0(r, arg1 * 2, 0x118, 4);
    m = 4;
    rem = r % m;
    a = r;
    if (rem != 0) {
        a = r + (m - rem);
    }
    r = a;
    r += arg1 * 8;
    return r - arg0;
}
/* localdecomp:end func_L39_006CE3F0 */

/* localdecomp:start func_L39_006CE458 */
typedef struct S_006CE458_Q { s32 f0; s32 f4; s32 f8; } S_006CE458_Q;
typedef struct S_006CE458 {
    u8 pad0[0x45C];
    u8 f45C;
    u8 pad45D[7];
    u8 f464;
    u8 pad465[0xB];
    s32 f470;
    S_006CE458_Q f474;
    S_006CE458_Q f480;
    s32 f48C;
    u32 f490;
} S_006CE458;
extern s32 func_L39_006E16A0(s32, s32, s32, s32);
extern s32 func_L39_006E1648(s32, s32, s32, s32);
extern void func_L39_006CE458(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    S_006CE458 *p = (S_006CE458 *)arg0;
    S_006CE458_Q *q;
    S_006CE458_Q *q2;
    u32 r;
    u32 m;
    u32 rem;
    u32 a;
    s32 size;

    if (p->f45C == 0) {
        r = arg1;
        p->f464 = 0;
        p->f470 = arg3;
        p->f45C = 1;
        size = func_L39_006E16A0(r, arg3 * 2, 0x118, 4);
        p->f48C = func_L39_006E1648(r, size, 0x118, 4);
        r += size;
        m = 4;
        rem = r % m;
        a = r;
        if (rem != 0) {
            a = r + (m - rem);
        }
        r = a;
        p->f490 = r;
        func_0011D534(r, 0, p->f470 * 8);
        q = &p->f474;
        q->f0 = 0;
        q->f8 = p->f490;
        q->f4 = 0;
        q2 = &p->f480;
        q2->f0 = 0;
        q2->f8 = p->f470 * 4 + p->f490;
        q2->f4 = 0;
    }
}
/* localdecomp:end func_L39_006CE458 */

/* localdecomp:start func_L39_006CE540 */
s32 func_L39_006E16A0(s32, s32, s32, s32);

s32 func_L39_006CE540(u32 arg0, s32 arg1) {
    u32 r = arg0;
    u32 m;
    u32 rem;
    u32 a;
    r += func_L39_006E16A0(r, arg1 * 2, 0x48, 4);
    m = 4;
    rem = r % m;
    a = r;
    if (rem != 0) {
        a = r + (m - rem);
    }
    r = a;
    r += arg1 * 8;
    return r - arg0;
}
/* localdecomp:end func_L39_006CE540 */

INCLUDE_ASM("asm/levels", func_L39_006CE5A8);

/* localdecomp:start func_L39_006CE690 */
s32 func_L39_006E16A0(s32, s32, s32, s32);

s32 func_L39_006CE690(u32 arg0, s32 arg1) {
    u32 r = arg0;
    u32 m;
    u32 rem;
    u32 a;
    r += func_L39_006E16A0(r, arg1 * 2, 0x1C4, 4);
    m = 4;
    rem = r % m;
    a = r;
    if (rem != 0) {
        a = r + (m - rem);
    }
    r = a;
    r += arg1 * 8;
    return r - arg0;
}
/* localdecomp:end func_L39_006CE690 */

INCLUDE_ASM("asm/levels", func_L39_006CE6F8);

/* localdecomp:start func_L39_006CE7E0 */
s32 func_L39_006E16A0(s32, s32, s32, s32);

s32 func_L39_006CE7E0(u32 arg0, s32 arg1) {
    u32 r = arg0;
    u32 m;
    u32 rem;
    u32 a;
    r += func_L39_006E16A0(r, arg1 * 2, 0x28, 4);
    m = 4;
    rem = r % m;
    a = r;
    if (rem != 0) {
        a = r + (m - rem);
    }
    r = a;
    r += arg1 * 8;
    return r - arg0;
}
/* localdecomp:end func_L39_006CE7E0 */

INCLUDE_ASM("asm/levels", func_L39_006CE848);

/* localdecomp:start func_L39_006CE930 */
/* from rac4-decomp's func_L00_00767968 */
void *func_L39_006CE930(void *arg0) {
    u8 *p = (u8 *)arg0;
    *(s8 *)(p + 0x34) = 0;
    *(s32 *)(p + 0x0) = -1;
    *(s8 *)(p + 0x5C) = 0;
    *(s8 *)(p + 0x64) = 0;
    *(s8 *)(p + 0x6C) = 0;
    *(s8 *)(p + 0x7C) = 0;
    *(s8 *)(p + 0x84) = 0;
    *(s8 *)(p + 0x8C) = 0;
    *(s8 *)(p + 0x94) = 0;
    *(s8 *)(p + 0x9C) = 0;
    *(s8 *)(p + 0xA4) = 0;
    *(s8 *)(p + 0xAC) = 0;
    *(s8 *)(p + 0xB4) = 0;
    *(s8 *)(p + 0xBC) = 0;
    *(s8 *)(p + 0xC4) = 0;
    *(s8 *)(p + 0xCC) = 0;
    *(s8 *)(p + 0xD4) = 0;
    *(s8 *)(p + 0x220) = 0;
    *(s8 *)(p + 0x38C) = 0;
    *(s8 *)(p + 0x3B4) = 0;
    *(s32 *)(p + 0x3B8) = -1;
    *(s8 *)(p + 0x3BC) = 0;
    *(s32 *)(p + 0x3C0) = -1;
    *(s32 *)(p + 0x3C4) = -1;
    *(s8 *)(p + 0x3EC) = 0;
    *(s32 *)(p + 0x3F0) = -1;
    *(s8 *)(p + 0x3F4) = 0;
    *(s32 *)(p + 0x3F8) = -1;
    *(s32 *)(p + 0x3FC) = -1;
    *(s8 *)(p + 0x424) = 0;
    *(s32 *)(p + 0x428) = -1;
    *(s8 *)(p + 0x42C) = 0;
    *(s32 *)(p + 0x430) = -1;
    *(s32 *)(p + 0x434) = -1;
    *(s8 *)(p + 0x45C) = 0;
    *(s32 *)(p + 0x460) = -1;
    *(s8 *)(p + 0x464) = 0;
    *(s32 *)(p + 0x468) = -1;
    *(s32 *)(p + 0x46C) = -1;
    *(s8 *)(p + 0x49C) = 0;
    *(s32 *)(p + 0x4A0) = -1;
    *(s8 *)(p + 0x4A4) = 0;
    *(s32 *)(p + 0x4A8) = -1;
    *(s32 *)(p + 0x4AC) = -1;
    *(s8 *)(p + 0x4DC) = 0;
    *(s32 *)(p + 0x4E0) = -1;
    *(s8 *)(p + 0x4E4) = 0;
    *(s32 *)(p + 0x4E8) = -1;
    *(s32 *)(p + 0x4EC) = -1;
    *(s8 *)(p + 0x515) = 0;
    *(s32 *)(p + 0x518) = -1;
    *(s8 *)(p + 0x51C) = 0;
    *(s32 *)(p + 0x520) = -1;
    *(s32 *)(p + 0x524) = -1;
    return arg0;
}
/* localdecomp:end func_L39_006CE930 */

INCLUDE_ASM("asm/levels", func_L39_006CEA18);

/* localdecomp:start func_L39_006CECA0 */
extern s32 func_00120048(u8 *, u8 *, ...);
extern u8 D_L39_00249BC8[];

void func_L39_006CECA0(u8 *arg0, s32 *arg1) {
    u32 i = 0;
    u8 *p = arg0;
    s32 *q = arg1;

    do {
        func_00120048(p, D_L39_00249BC8, *q);
        i++;
        q++;
        p += 8;
    } while (i < 3);
    *(u8 *)((u8 *)arg0 + i * 8) = 0;
}
/* localdecomp:end func_L39_006CECA0 */

/* localdecomp:start func_L39_006CED20 */
extern u8 D_L39_00249BC8[];
extern void func_001200E0(void *, void *, void *);

void func_L39_006CED20(u8 *arg0, s32 *arg1)
{
    u32 i = 0;
    s32 *q = arg1;
    u8 *p = arg0;

    do {
        func_001200E0(p, D_L39_00249BC8, q);
        i++;
        q++;
        p += 8;
    } while (i < 3);
}
/* localdecomp:end func_L39_006CED20 */

INCLUDE_ASM("asm/levels", func_L39_006CED88);

INCLUDE_ASM("asm/levels", func_L39_006CEEE0);

/* localdecomp:start func_L39_006CF080 */
__asm__(".extern D_L39_0024D760, 16");
typedef struct { char pad[0x64]; char flag; char pad2[3]; int val; } T_006CF080;
typedef struct { char pad[0x38]; T_006CF080 *p; } S_006CF080;

/* from rac4-decomp's func_L00_00766C00 */
void func_L39_006CF080(char *arg0) {
    T_006CF080 *t = ((S_006CF080 *)D_L39_0024D760)->p;
    t->flag = 0;
    t->val = *(int *)(arg0 + 0x18);
}
/* localdecomp:end func_L39_006CF080 */

INCLUDE_ASM("asm/levels", func_L39_006CF0A0);

/* localdecomp:start func_L39_006CF218 */
typedef struct {
    u8 pad0[0x6C];
    s8 f6C;
    u8 pad1[3];
    s32 f70;
} S_6CF218_B;
typedef struct {
    u8 pad0[0x18];
    s32 f18;
} S_6CF218_C;
typedef struct {
    u8 pad0[0x38];
    S_6CF218_B *f38;
} S_6CF218_A;
__asm__(".extern D_L39_0024D760, 16");

/* from rac4-decomp's func_L00_00766C00 */
void func_L39_006CF218(S_6CF218_C *arg0) {
    S_6CF218_B *p = ((S_6CF218_A *)D_L39_0024D760)->f38;
    p->f6C = 0;
    p->f70 = arg0->f18;
}
/* localdecomp:end func_L39_006CF218 */

INCLUDE_ASM("asm/levels", func_L39_006CF238);

/* localdecomp:start func_L39_006CF3C8 */
__asm__(".extern D_L39_0024D760, 16");

/* from rac4-decomp's func_L00_00766C00 */
void func_L39_006CF3C8(void *arg0) {
    void *temp_v1;
    temp_v1 = (*(void **)((u8 *)D_L39_0024D760 + 0x38));
    (*(s8 *)((u8 *)(temp_v1) + 0x74)) = 0;
    (*(s32 *)((u8 *)(temp_v1) + 0x78)) = (s32) (*(s32 *)((u8 *)(arg0) + 0x18));
}
/* localdecomp:end func_L39_006CF3C8 */

INCLUDE_ASM("asm/levels", func_L39_006CF3E8);

/* localdecomp:start func_L39_006CF588 */
typedef struct {
    u8 pad0[0x7c];
    s8 f7C;
    u8 pad1[0x80 - 0x7c - 1];
    s32 f80;
} S_006CF588_B;
typedef struct {
    u8 pad0[0x18];
    s32 f18;
} S_006CF588_C;
typedef struct {
    u8 pad0[0x38];
    S_006CF588_B *f38;
} S_006CF588_A;
__asm__(".extern D_L39_0024D760, 16");

/* from rac4-decomp's func_L00_00766C00 */
void func_L39_006CF588(S_006CF588_C *arg0) {
    S_006CF588_B *p = ((S_006CF588_A *)D_L39_0024D760)->f38;
    p->f7C = 0;
    p->f80 = arg0->f18;
}
/* localdecomp:end func_L39_006CF588 */

INCLUDE_ASM("asm/levels", func_L39_006CF5A8);

/* localdecomp:start func_L39_006CF750 */
__asm__(".extern D_L39_0024D760, 16");
typedef struct { char pad[0x84]; char flag; char pad2[3]; int val; } T_006CF750;
typedef struct { char pad[0x38]; T_006CF750 *p; } S_006CF750;

/* from rac4-decomp's func_L00_00766C00 */
void func_L39_006CF750(char *arg0) {
    T_006CF750 *t = ((S_006CF750 *)D_L39_0024D760)->p;
    t->flag = 0;
    t->val = *(int *)(arg0 + 0x18);
}
/* localdecomp:end func_L39_006CF750 */

INCLUDE_ASM("asm/levels", func_L39_006CF770);

/* localdecomp:start func_L39_006CF900 */
__asm__(".extern D_L39_0024D760, 16");

/* from rac4-decomp's func_L00_00766C00 */
void func_L39_006CF900(void *arg0) {
    void *temp_v1;
    temp_v1 = (*(void **)((u8 *)D_L39_0024D760 + 0x38));
    (*(s8 *)((u8 *)(temp_v1) + 0x8c)) = 0;
    (*(s32 *)((u8 *)(temp_v1) + 0x90)) = (s32) (*(s32 *)((u8 *)(arg0) + 0x18));
}
/* localdecomp:end func_L39_006CF900 */

INCLUDE_ASM("asm/levels", func_L39_006CF920);

/* localdecomp:start func_L39_006CFAD0 */
typedef struct {
    u8 pad0[0x94];
    s8 f94;
    u8 pad1[3];
    s32 f98;
} S_6CFAD0_B;
typedef struct {
    u8 pad0[0x18];
    s32 f18;
} S_6CFAD0_C;
typedef struct {
    u8 pad0[0x38];
    S_6CFAD0_B *f38;
} S_6CFAD0_A;
__asm__(".extern D_L39_0024D760, 16");

/* from rac4-decomp's func_L00_00766C00 */
void func_L39_006CFAD0(S_6CFAD0_C *arg0) {
    S_6CFAD0_B *p = ((S_6CFAD0_A *)D_L39_0024D760)->f38;
    p->f94 = 0;
    p->f98 = arg0->f18;
}
/* localdecomp:end func_L39_006CFAD0 */

INCLUDE_ASM("asm/levels", func_L39_006CFAF0);

/* localdecomp:start func_L39_006CFCB0 */
__asm__(".extern D_L39_0024D760, 16");
typedef struct { char pad[0x9c]; char flag; char pad2[3]; int val; } T_006CFCB0;
typedef struct { char pad[0x38]; T_006CFCB0 *p; } S_006CFCB0;

/* from rac4-decomp's func_L00_00766C00 */
void func_L39_006CFCB0(char *arg0) {
    T_006CFCB0 *t = ((S_006CFCB0 *)D_L39_0024D760)->p;
    t->flag = 0;
    t->val = *(int *)(arg0 + 0x18);
}
/* localdecomp:end func_L39_006CFCB0 */

INCLUDE_ASM("asm/levels", func_L39_006CFCD0);

/* localdecomp:start func_L39_006CFE68 */
typedef struct {
    u8 pad0[0xa4];
    s8 fA4;
    u8 pad1[0xa8 - 0xa4 - 1];
    s32 fA8;
} S_006CFE68_B;
typedef struct {
    u8 pad0[0x18];
    s32 f18;
} S_006CFE68_C;
typedef struct {
    u8 pad0[0x38];
    S_006CFE68_B *f38;
} S_006CFE68_A;
__asm__(".extern D_L39_0024D760, 16");

/* from rac4-decomp's func_L00_00766C00 */
void func_L39_006CFE68(S_006CFE68_C *arg0) {
    S_006CFE68_B *p = ((S_006CFE68_A *)D_L39_0024D760)->f38;
    p->fA4 = 0;
    p->fA8 = arg0->f18;
}
/* localdecomp:end func_L39_006CFE68 */

/* localdecomp:start func_L39_006CFE88 */
__asm__(".extern D_L39_0024D760, 16");

/* from rac4-decomp's func_L00_00766C00 */
void func_L39_006CFE88(void *arg0) {
    void *temp_v1;
    temp_v1 = (*(void **)((u8 *)D_L39_0024D760 + 0x38));
    (*(s8 *)((u8 *)(temp_v1) + 0xac)) = 0;
    (*(s32 *)((u8 *)(temp_v1) + 0xb0)) = (s32) (*(s32 *)((u8 *)(arg0) + 0x18));
}
/* localdecomp:end func_L39_006CFE88 */

INCLUDE_ASM("asm/levels", func_L39_006CFEA8);

/* localdecomp:start func_L39_006D0058 */
typedef struct {
    u8 pad0[0xB4];
    s8 fB4;
    u8 pad1[3];
    s32 fB8;
} S_6D0058_B;
typedef struct {
    u8 pad0[0x18];
    s32 f18;
} S_6D0058_C;
typedef struct {
    u8 pad0[0x38];
    S_6D0058_B *f38;
} S_6D0058_A;
__asm__(".extern D_L39_0024D760, 16");

/* from rac4-decomp's func_L00_00766C00 */
void func_L39_006D0058(S_6D0058_C *arg0) {
    S_6D0058_B *p = ((S_6D0058_A *)D_L39_0024D760)->f38;
    p->fB4 = 0;
    p->fB8 = arg0->f18;
}
/* localdecomp:end func_L39_006D0058 */

INCLUDE_ASM("asm/levels", func_L39_006D0078);

/* localdecomp:start func_L39_006D0208 */
__asm__(".extern D_L39_0024D760, 16");
typedef struct { char pad[0xc4]; char flag; char pad2[3]; int val; } T_006D0208;
typedef struct { char pad[0x38]; T_006D0208 *p; } S_006D0208;

/* from rac4-decomp's func_L00_00766C00 */
void func_L39_006D0208(char *arg0) {
    T_006D0208 *t = ((S_006D0208 *)D_L39_0024D760)->p;
    t->flag = 0;
    t->val = *(int *)(arg0 + 0x18);
}
/* localdecomp:end func_L39_006D0208 */

INCLUDE_ASM("asm/levels", func_L39_006D0228);

/* localdecomp:start func_L39_006D0398 */
typedef struct {
    u8 pad0[0xcc];
    s8 fCC;
    u8 pad1[0xd0 - 0xcc - 1];
    s32 fD0;
} S_006D0398_B;
typedef struct {
    u8 pad0[0x18];
    s32 f18;
} S_006D0398_C;
typedef struct {
    u8 pad0[0x38];
    S_006D0398_B *f38;
} S_006D0398_A;
__asm__(".extern D_L39_0024D760, 16");

/* from rac4-decomp's func_L00_00766C00 */
void func_L39_006D0398(S_006D0398_C *arg0) {
    S_006D0398_B *p = ((S_006D0398_A *)D_L39_0024D760)->f38;
    p->fCC = 0;
    p->fD0 = arg0->f18;
}
/* localdecomp:end func_L39_006D0398 */

INCLUDE_ASM("asm/levels", func_L39_006D03B8);

/* localdecomp:start func_L39_006D0550 */
__asm__(".extern D_L39_0024D760, 16");

/* from rac4-decomp's func_L00_00766C00 */
void func_L39_006D0550(void *arg0) {
    void *temp_v1;
    temp_v1 = (*(void **)((u8 *)D_L39_0024D760 + 0x38));
    (*(s8 *)((u8 *)(temp_v1) + 0xbc)) = 0;
    (*(s32 *)((u8 *)(temp_v1) + 0xc0)) = (s32) (*(s32 *)((u8 *)(arg0) + 0x18));
}
/* localdecomp:end func_L39_006D0550 */

INCLUDE_ASM("asm/levels", func_L39_006D05A0);

/* localdecomp:start func_L39_006D08E8 */
typedef struct S_006D08E8 {
    u16 f0;
    u8 pad2[0x16];
    s32 f18;
    s32 f1C;
    s32 f20;
    u8 pad24[0xC];
    u8 f30[16];
} S_006D08E8;
extern u16 D_L39_00249C18[];
extern u8 D_001978D0[];
void func_0014B008(void *);
s32 func_0017D990(void *, void *, s32);
void func_001961E8(s32);
s32 func_001961F8(void);

s32 func_L39_006D08E8(u8 *arg0) {
    S_006D08E8 buf;
    s32 r = 1;

    if (arg0[0x3B4] != 0) {
        buf.f0 = D_L39_00249C18[0];
        buf.f18 = *(s32 *)arg0;
        arg0[0x3BC] = 1;
        buf.f1C = 0;
        buf.f20 = 0;
        *(s32 *)(arg0 + 0x3C0) = (s32) func_00130760(func_0012DCB0(), 0x24000);
        func_0014B008(buf.f30);
        func_001961E8(func_0017D990(&buf, D_001978D0, 0));
        if (func_001961F8() != 0) {
            r = 0;
        }
    }
    return r;
}
/* localdecomp:end func_L39_006D08E8 */

INCLUDE_ASM("asm/levels", func_L39_006D0990);

INCLUDE_ASM("asm/levels", func_L39_006D0DD0);

INCLUDE_ASM("asm/levels", func_L39_006D0F08);

INCLUDE_ASM("asm/levels", func_L39_006D12C8);

/* localdecomp:start func_L39_006D1658 */
__asm__(".extern D_L39_0024D760, 16");
typedef struct {
    u16 f0;
    u8 pad2[0x13];
    u8 f15[0x13];
    s32 f28;
    s32 f2C;
    u8 f30[0x10];
} S_006D1658;
typedef struct {
    u8 pad0[0x424];
    u8 f424;
    u8 pad425[7];
    u8 f42C;
    u8 pad42D[3];
    s32 f430;
    u8 pad434[4];
    s32 f438;
} T_006D1658;
extern u16 D_L39_00249C18[];
extern u8 D_00197920[];
extern void *func_001206F4(void *, void *);
extern void func_0014B008(void *);
extern s32 func_0017D178(void *, u8 *, s32);

s32 func_L39_006D1658(u8 *arg0) {
    T_006D1658 *p = (T_006D1658 *)arg0;
    s32 r = 1;
    S_006D1658 x;

    if (p->f424 != 0) {
        void *n = *(void **)((u8 *)D_L39_0024D760 + 0x50);
        x.f0 = D_L39_00249C18[0];
        func_001206F4(x.f15, n);
        p->f42C = 1;
        x.f28 = 1;
        x.f2C = p->f438;
        p->f430 = (s32) func_00130760(func_0012DCB0(), 0x24000);
        func_0014B008(x.f30);
        func_001961E8(func_0017D178(&x, D_00197920, 0));
        if (func_001961F8() != 0) {
            r = 0;
        }
    }
    return r;
}
/* localdecomp:end func_L39_006D1658 */

INCLUDE_ASM("asm/levels", func_L39_006D1710);

/* localdecomp:start func_L39_006D1B40 */
__asm__(".extern D_L39_0024D760, 16");
typedef struct {
    u16 f0;
    u8 pad2[0x13];
    u8 f15[0x13];
    s32 f28;
    s32 f2C;
    u8 f30[0x10];
} S_006D1B40;
typedef struct {
    u8 pad0[0x45C];
    u8 f45C;
    u8 pad45D[7];
    u8 f464;
    u8 pad465[3];
    s32 f468;
    u8 pad46C[4];
    s32 f470;
} T_006D1B40;
extern u16 D_L39_00249C18[];
extern u8 D_001978A8[];
extern void *func_001206F4(void *, void *);
extern void func_0014B008(void *);
extern s32 func_0017D0F8(void *, u8 *, s32);

s32 func_L39_006D1B40(u8 *arg0) {
    T_006D1B40 *p = (T_006D1B40 *)arg0;
    s32 r = 1;
    S_006D1B40 x;

    if (p->f45C != 0) {
        void *n = *(void **)((u8 *)D_L39_0024D760 + 0x50);
        x.f0 = D_L39_00249C18[0];
        func_001206F4(x.f15, n);
        p->f464 = 1;
        x.f28 = 1;
        x.f2C = p->f470;
        p->f468 = (s32) func_00130760(func_0012DCB0(), 0x24000);
        func_0014B008(x.f30);
        func_001961E8(func_0017D0F8(&x, D_001978A8, 0));
        if (func_001961F8() != 0) {
            r = 0;
        }
    }
    return r;
}
/* localdecomp:end func_L39_006D1B40 */

INCLUDE_ASM("asm/levels", func_L39_006D1BF8);

/* localdecomp:start func_L39_006D2030 */
typedef struct {
    u16 f00;
    u8 pad02[0x16];
    s32 f18;
    s32 f1C;
    s32 f20;
    s32 f24;
} Loc_006D2030;
typedef struct {
    u8 pad0[0x494];
    s32 f494;
    s32 f498;
    u8 f49C;
    u8 pad49D[7];
    u8 f4A4;
    u8 pad4A5[3];
    s32 f4A8;
    u8 pad4AC[4];
    s32 f4B0;
} S_006D2030;
extern u16 D_L39_00249C18[];
extern u8 D_00197948[];
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern void func_0014B008(void *);
extern s32 func_0017D908(void *, u8 *, s32);
extern void func_001961E8(s32);
extern s32 func_001961F8(void);

s32 func_L39_006D2030(S_006D2030 *p, s32 a, s32 b, s32 c) {
    s32 r = 1;
    Loc_006D2030 loc;
    u8 buf[0x10];

    if (p->f49C != 0) {
        p->f498 = b;
        p->f494 = a;
        loc.f00 = D_L39_00249C18[0];
        loc.f18 = a;
        loc.f1C = b;
        loc.f20 = c;
        loc.f24 = p->f4B0;
        p->f4A4 = 1;
        p->f4A8 = (s32) func_00130760(func_0012DCB0(), 0x24000);
        func_0014B008(buf);
        func_001961E8(func_0017D908(&loc, D_00197948, 0));
        if (func_001961F8() != 0) {
            r = 0;
        }
    }
    return r;
}
/* localdecomp:end func_L39_006D2030 */

INCLUDE_ASM("asm/levels", func_L39_006D20E8);

INCLUDE_ASM("asm/levels", func_L39_006D2500);

INCLUDE_ASM("asm/levels", func_L39_006D25E0);

/* localdecomp:start func_L39_006D29F0 */
typedef struct S_6D29F0 {
    s32 f0;
    u8 pad4[0x510];
    u8 f514;
    u8 f515;
    u8 pad516[6];
    u8 f51C;
    u8 pad51D[3];
    s32 f520;
    u8 pad524[4];
    s32 f528;
} S_6D29F0;
typedef struct S_6D29F0_G {
    u8 pad0[0x50];
    void *f50;
} S_6D29F0_G;
extern u16 D_L39_00249C18[];
extern u8 D_00197880[];
__asm__(".extern D_L39_0024D760, 16");
extern void *D_L39_0024D760;
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern void *func_001206F4(void *, void *);
extern void func_0014B008(void *);
extern s32 func_0017D800(void *, u8 *, s32);
extern void func_001961E8(s32);
extern s32 func_001961F8(void);

s32 func_L39_006D29F0(S_6D29F0 *arg0, s32 arg1) {
    s32 r = 1;
    struct { u16 x[1]; u8 pad2[0x13]; u8 buf[0x13]; s32 a; s32 b; s32 c; s32 d; u8 pad3[8]; u8 e[0x10]; } l;

    if (arg0->f515 != 0) {
        void *name = ((S_6D29F0_G *)D_L39_0024D760)->f50;
        arg0->f514 = arg1;
        l.x[0] = D_L39_00249C18[0];
        func_001206F4(l.buf, name);
        arg0->f51C = 1;
        l.a = arg0->f0;
        l.b = arg0->f514;
        l.c = 1;
        l.d = arg0->f528;
        arg0->f520 = (s32) func_00130760(func_0012DCB0(), 0x24000);
        func_0014B008(l.e);
        func_001961E8(func_0017D800(&l, D_00197880, 0));
        if (func_001961F8() != 0) {
            r = 0;
        }
    }
    return r;
}
/* localdecomp:end func_L39_006D29F0 */

INCLUDE_ASM("asm/levels", func_L39_006D2AC0);

/* localdecomp:start func_L39_006D2E80 */
extern void func_00196F18(s32, u8 *);

void func_L39_006D2E80(s32 arg0, s32 arg1) {
    u8 buf[0x100];

    func_L39_006CECA0(buf, (s32 *)arg1);
    func_00196F18(*(s32 *)arg0, buf);
}
/* localdecomp:end func_L39_006D2E80 */

/* localdecomp:start func_L39_006D2EB8 */
void func_00120D28(s32, s32, s32);
void func_L39_006D2E80(s32, s32);

void func_L39_006D2EB8(s32 arg0, s32 arg1) {
    func_00120D28(arg0 + 0x30, arg1, 4);
    func_L39_006D2E80(arg0, arg0 + 0x28);
}
/* localdecomp:end func_L39_006D2EB8 */

/* localdecomp:start func_L39_006D2EF0 */
void func_L39_006D2E80(s32, s32);
void func_L39_006D2EF0(void *arg0, s32 arg1, s32 arg2) {
    *(s32 *)((u8 *)arg0 + 0x28) = arg1;
    *(s32 *)((u8 *)arg0 + 0x2C) = arg2;
    func_L39_006D2E80((s32) arg0, (s32) (arg0 + 0x28));
}
/* localdecomp:end func_L39_006D2EF0 */

INCLUDE_ASM("asm/levels", func_L39_006D2F18);

INCLUDE_ASM("asm/levels", func_L39_006D2FA0);

/* localdecomp:start func_L39_006D30F8 */
__asm__(".extern D_L39_0024D760, 16");
typedef struct { u8 bytes[0x148]; } __attribute__((packed)) Block_006D30F8;
typedef struct { u8 pad[0xD4]; u8 fD4; u8 pad2[3]; Block_006D30F8 fD8; } Target_006D30F8;
typedef struct { u8 pad[0x38]; Target_006D30F8 *p; } Global_006D30F8;

void func_L39_006D30F8(Block_006D30F8 *arg0) {
    Target_006D30F8 *t = ((Global_006D30F8 *)D_L39_0024D760)->p;
    t->fD4 = 0;
    t->fD8 = *arg0;
}
/* localdecomp:end func_L39_006D30F8 */

INCLUDE_ASM("asm/levels", func_L39_006D31B8);

/* localdecomp:start func_L39_006D3318 */
typedef struct { u8 bytes[0x168]; } __attribute__((packed)) Block_6D3318;
typedef struct { u8 pad[0x220]; u8 f220; u8 pad221[3]; Block_6D3318 f224; } Target_6D3318;
typedef struct { u8 pad[0x38]; Target_6D3318 *f38; } Global_6D3318;
__asm__(".extern D_L39_0024D760, 16");
extern void *D_L39_0024D760;

void func_L39_006D3318(Block_6D3318 *arg) {
    Target_6D3318 *t = ((Global_6D3318 *)D_L39_0024D760)->f38;
    t->f220 = 0;
    t->f224 = *arg;
}
/* localdecomp:end func_L39_006D3318 */

INCLUDE_ASM("asm/levels", func_L39_006D33D8);

/* localdecomp:start func_L39_006D3440 */
void *func_L39_006D3440(void *arg0) {
    (*(s8 *)arg0) = 0;
    *(s8 *)((u8 *)arg0 + 1) = 0;
    *(s8 *)((u8 *)arg0 + 2) = 0;
    *(s8 *)((u8 *)arg0 + 3) = 0;
    *(s8 *)((u8 *)arg0 + 4) = 0;
    *(s32 *)((u8 *)arg0 + 8) = 0;
    *(s32 *)((u8 *)arg0 + 0xC) = 0;
    *(s8 *)((u8 *)arg0 + 0x10) = 0;
    *(s8 *)((u8 *)arg0 + 0x11) = 0;
    *(s8 *)((u8 *)arg0 + 0x12) = 0;
    *(s8 *)((u8 *)arg0 + 0x13) = 0;
    *(s32 *)((u8 *)arg0 + 0x14) = 0;
    *(s32 *)((u8 *)arg0 + 0x18) = 0;
    *(s8 *)((u8 *)arg0 + 0x20) = 0;
    *(s32 *)((u8 *)arg0 + 0x3FC) = 0;
    *(s32 *)((u8 *)arg0 + 0xD20) = 0;
    *(s32 *)((u8 *)arg0 + 0x1644) = 0;
    return arg0;
}
/* localdecomp:end func_L39_006D3440 */

/* localdecomp:start func_L39_006D3490 */
typedef struct S_006D3490 {
    u8 f0, f1, f2, f3, f4;
    s32 f8, fC;
    u8 f10, f11, f12, f13;
    s32 f14, f18;
    u8 f1C[4];
    u8 f20;
    u8 pad21[0x3DB];
    s32 f3FC;
    u8 pad400[0x920];
    s32 fD20;
    u8 padD24[0x920];
    s32 f1644;
} S_006D3490;

void func_L39_006D3490(S_006D3490 *o) {
    o->f0 = 0;
    o->f1 = 0;
    o->f2 = 0;
    o->f3 = 0;
    o->f4 = 0;
    o->f8 = 0;
    o->fC = 0;
    o->f10 = 0;
    o->f11 = 0;
    o->f12 = 0;
    o->f13 = 0;
    o->f14 = 0;
    o->f18 = 0;
    o->f20 = 0;
    o->f3FC = 0;
    o->fD20 = 0;
    o->f1644 = 0;
}
/* localdecomp:end func_L39_006D3490 */

INCLUDE_ASM("asm/levels", func_L39_006D34D8);

/* localdecomp:start func_L39_006D3950 */
typedef struct { s32 w[0x2F]; } Block_6D3950;
typedef struct { u8 flag; u8 pad[0x27]; Block_6D3950 block; } Target_6D3950;
typedef struct { u8 pad[0x3C]; Target_6D3950 *target; } Context_6D3950;
__asm__(".extern D_L39_0024D760, 16");

void func_L39_006D3950(Block_6D3950 *source) {
    Target_6D3950 *target = ((Context_6D3950 *)D_L39_0024D760)->target;
    target->block = *source;
    target->flag = 0;
}
/* localdecomp:end func_L39_006D3950 */

INCLUDE_ASM("asm/levels", func_L39_006D3A30);

/* localdecomp:start func_L39_006D4018 */
__asm__(".extern D_L39_0024D760, 16");
typedef struct {
    char _p0[0x3C];
    s8 *f3C;
} S_6D4018;

/* from rac4-decomp's func_L00_0076F1E0 */
void func_L39_006D4018(void) {
    ((S_6D4018 *)D_L39_0024D760)->f3C[1] = 0;
}
/* localdecomp:end func_L39_006D4018 */

INCLUDE_ASM("asm/levels", func_L39_006D4030);

/* localdecomp:start func_L39_006D40B0 */
typedef struct S_6D40B0_G {
    u8 pad0[0x10];
    s32 f10;
    s32 f14;
    u8 pad18[0x38];
    void *f50;
} S_6D40B0_G;
__asm__(".extern D_L39_0024D760, 16");
extern void *D_L39_0024D760;
extern void *func_001206F4(void *, void *);
extern void func_00196038(void);
extern void func_0019B798(s32);
extern void func_0019B5B8(s32);
extern s32 func_0017E310(void *);
extern void func_001961E8(s32);
extern s32 func_001961F8(void);

s32 func_L39_006D40B0(void) {
    S_6D40B0_G *g = (S_6D40B0_G *)D_L39_0024D760;
    void *name = g->f50;
    s32 r = 1;
    struct { u8 pad[0x14]; s32 mode; } l;

    func_00196038();
    func_0019B798(0);
    func_0019B5B8(-1);
    func_001206F4(&l, name);
    l.mode = 2;
    func_001961E8(func_0017E310(&l));
    if (func_001961F8() != 0) {
        g->f10 = 4;
        if (g->f14 == 0) {
            g->f14 = 4;
        }
        r = 0;
    }
    l.mode = 1;
    func_001961E8(func_0017E310(&l));
    if (func_001961F8() != 0) {
        g->f10 = 4;
        if (g->f14 == 0) {
            g->f14 = 4;
        }
        r = 0;
    }
    return r;
}
/* localdecomp:end func_L39_006D40B0 */

/* localdecomp:start func_L39_006D4188 */
__asm__(".extern D_L39_0024D760, 16");
typedef struct {
    u16 f0;
    u8 pad2[0x13];
    u8 f15[0x13];
    s32 f28;
    u8 pad2C[4];
} S_006D4188;
typedef struct {
    u8 pad0;
    u8 f1;
    u8 pad2[6];
    s32 f8;
    u8 padC[4];
    s32 f10;
    s32 f14;
    u8 pad18[0x38];
    void *f50;
} G_006D4188;
extern u16 D_L39_00249C78[];
extern u8 D_00197BF0[];
extern void *func_001206F4(void *, void *);
s32 func_0019B5C8(void);
extern s32 func_0017EAB8(void *, u8 *, s32);

s32 func_L39_006D4188(u8 *arg0) {
    G_006D4188 *g;
    s32 r = 1;
    S_006D4188 x;

    x.f0 = D_L39_00249C78[0];
    g = (G_006D4188 *)D_L39_0024D760;
    func_001206F4(x.f15, g->f50);
    x.f28 = func_0019B5C8();
    arg0[3] = 1;
    *(s32 *)(arg0 + 0xC) = (s32) func_00130760(func_0012DCB0(), 0x24000);
    g->f1 = 1;
    g->f8 = (s32) func_00130760(func_0012DCB0(), 0x24000);
    func_001961E8(func_0017EAB8(&x, D_00197BF0, 0));
    if (func_001961F8() != 0) {
        g->f10 = 0x2E;
        if (g->f14 == 0) {
            g->f14 = 0x2E;
        }
        r = 0;
    }
    g->f1 = 0;
    return r;
}
/* localdecomp:end func_L39_006D4188 */

INCLUDE_ASM("asm/levels", func_L39_006D4278);

INCLUDE_ASM("asm/levels", func_L39_006D4380);

/* localdecomp:start func_L39_006D44F0 */
typedef struct { u8 bytes[0x188]; } __attribute__((packed)) Part_6D44F0;
typedef struct { Part_6D44F0 a; s32 b; } Block_6D44F0;
typedef struct { u8 pad[2]; u8 f2; u8 pad3[0xD]; u8 f10; u8 pad11[0x25F]; Block_6D44F0 f270; } Target_6D44F0;
typedef struct { u8 pad[0x3C]; Target_6D44F0 *f3C; } Global_6D44F0;
__asm__(".extern D_L39_0024D760, 16");
extern void *D_L39_0024D760;

void func_L39_006D44F0(Block_6D44F0 *arg) {
    Target_6D44F0 *t = ((Global_6D44F0 *)D_L39_0024D760)->f3C;
    t->f270 = *arg;
    t->f2 = 1;
    t->f10 = 0;
}
/* localdecomp:end func_L39_006D44F0 */

INCLUDE_ASM("asm/levels", func_L39_006D45B8);

INCLUDE_ASM("asm/levels", func_L39_006D4688);

INCLUDE_ASM("asm/levels", func_L39_006D48C8);

INCLUDE_ASM("asm/levels", func_L39_006D4A68);

INCLUDE_ASM("asm/levels", func_L39_006D4B98);

INCLUDE_ASM("asm/levels", func_L39_006D4D48);
