#include "common.h"

typedef struct { u32 f0; u32 f4; s32 f8; s32 fC; s32 f10; s32 f14; s32 f18; u32 f1C; u32 f20; u32 f24; u32 f28; u32 f2C; u32 f30; u32 f34; u32 f38; u32 f3C; s32 f40; s32 f44; } O_00609CE8;

extern s32 func_001262A0(s32 a0);
extern void func_00126280(s32 a0);
extern void func_L39_00609638(s32);
extern void func_L39_006095C8(s32);

/* localdecomp:start func_L39_006098A8 */

void func_L39_006098A8(s32 *a0, s32 *a1, s32 *a2, s32 *a3, s32 *a4) {
    s32 pos, left;
    func_001262A0(a0[16]);
    left = (s32)((long)a0[2] - (long)(a0[4]+2)) * 2048 - a0[5];
    pos = ((a0[3] + a0[4]) * 2048 + a0[5]) % a0[6];
    if (left <= a0[6]-pos) {
        *a1 = a0[0]+pos;
        *a2 = left;
        *a3 = 0;
        *a4 = 0;
    } else {
        *a1 = a0[0]+pos;
        *a2 = a0[6]-pos;
        *a3 = a0[0];
        *a4 = left - (a0[6]-pos);
    }
    func_00126280(a0[16]);
}
/* localdecomp:end func_L39_006098A8 */

/* localdecomp:start func_L39_00609998 */
extern s32 func_001262A0(s32);
extern s32 func_001262A0(s32 a0);

/* from rac2-decomp's func_00350B70, renamed */
void func_L39_00609998(u8 *a0, s32 a1) {
    func_001262A0(*(s32 *)(a0+0x40));
    *(s32 *)(a0+0x14) += (s32)a1;
    *(long *)(a0+0x48) = (long)a1 + *(long *)(a0+0x48);
    func_00126280(*(s32 *)(a0+0x40));
}
/* localdecomp:end func_L39_00609998 */

INCLUDE_ASM("asm/levels", func_L39_006099F0);

/* localdecomp:start func_L39_00609BD8 */

int func_L39_00609BD8(int *p)
{
    func_001262A0(p[16]);
    p[17] = 0;
    func_L39_00609638(5);
    p[7] = *(volatile int *)0x1000B410;
    p[8] = *(volatile int *)0x1000B430;
    p[9] = *(volatile int *)0x1000B420;
    p[10] = *(volatile int *)0x1000B400;
    if (*(volatile int *)0x10002010 & 0xF0)
        while (*(volatile int *)0x10002010 & 0xF0)
            ;
    func_L39_006095C8(0);
    p[11] = *(volatile int *)0x1000B010;
    p[12] = *(volatile int *)0x1000B020;
    p[13] = *(volatile int *)0x1000B000;
    p[14] = *(volatile int *)0x10002020;
    p[15] = *(volatile int *)0x10002010;
    func_00126280(p[16]);
    return 1;
}
/* localdecomp:end func_L39_00609BD8 */

/* localdecomp:start func_L39_00609CE8 */
extern s32 func_003B1530();
s32 func_L39_00609CE8(O_00609CE8 *p) {
    u32 v = p->f38;
    u32 bits = v & 0x7F;
    u32 t = ((v >> 16) & 3) + ((v >> 8) & 0xF);
    u32 madr = p->f1C - t * 16;
    u32 qwc = p->f24 + t;
    u32 chcr = p->f28 | 0x100;
    u32 tadr = p->f20;
    func_001262A0(p->f40);
    if (madr < p->f0) {
        s32 tag;
        s32 m;
        qwc = (p->f0 - madr) >> 4;
        tadr = p->f4 & 0xFFFFFFF;
        madr += p->f8 << 11;
        tag = 0;
        if (p->f1C != p->f0) {
            tag = p->f1C == p->f0 + (p->f8 << 11) ? 0 : 3;
        }
        chcr = (p->f28 & 0xFFFFFFF) | (tag << 28) | 0x100;
        m = (p->f8 - p->fC) % p->f8;
        if (m < 0 || m >= p->f10) {
            p->fC = p->f8 - 1;
            p->f10 = p->f10 + 1;
        }
    } else {
        s32 a = func_003B1530(p, p->f1C);
        s32 b = func_003B1530(p, madr);
        if (a != b) {
            s32 tag;
            s32 m;
            tadr = (p->f4 + a * 16) & 0xFFFFFFF;
            qwc = (p->f0 + (a << 11) - madr) >> 4;
            tag = p->f0 + (p->f1C - p->f0) % (u32)(p->f8 << 11) == p->f0 + (((p->fC + p->f10) % p->f8) << 11) ? 0 : 3;
            chcr = (p->f28 & 0xFFFFFFF) | (tag << 28) | 0x100;
            m = (b + p->f8 - p->fC) % p->f8;
            if (m < 0 || m >= p->f10) {
                p->fC = b;
                p->f10 = p->f10 + 1;
            }
        }
    }
    if (p->f2C != 0 && p->f30 != 0) {
        *(volatile u32 *)0x1000B010 = p->f2C;
        *(volatile u32 *)0x1000B020 = p->f30;
        func_L39_006095C8(p->f34 | 0x100);
    }
    if (p->f10 != 0) {
        if (*(volatile s32 *)0x10002010 < 0) { do {} while (*(volatile s32 *)0x10002010 < 0); }
        *(volatile u32 *)0x10002000 = bits;
        if (*(volatile s32 *)0x10002010 < 0) { do {} while (*(volatile s32 *)0x10002010 < 0); }
    }
    *(volatile u32 *)0x1000B410 = madr;
    *(volatile u32 *)0x1000B430 = tadr;
    *(volatile u32 *)0x1000B420 = qwc;
    if (p->f10 != 0) {
        func_L39_00609638(chcr);
    }
    *(volatile u32 *)0x10002010 = p->f3C;
    p->f44 = 1;
    func_00126280(p->f40);
    return 1;
}
/* localdecomp:end func_L39_00609CE8 */

/* localdecomp:start func_L39_00609FF8 */
extern void func_L39_00609638(s32);
extern void func_00126270(s32);
s32 func_L39_00609FF8(u8 *p) {
    func_L39_00609638(5);
    *(volatile u32 *)0x1000B420 = 0;
    *(volatile u32 *)0x1000B410 = 0;
    *(volatile u32 *)0x1000B430 = 0;
    func_00126270(*(s32 *)(p + 0x40));
    return 1;
}
/* localdecomp:end func_L39_00609FF8 */

/* localdecomp:start func_L39_0060A050 */
s32 func_L39_0060A050(void *arg0) {
    s32 temp_s1;

    func_001262A0((*(s32 *)((u8 *)arg0 + 0x40)));
    temp_s1 = ((*(s32 *)((u8 *)arg0 + 0x10)) << 0xB) + (*(s32 *)((u8 *)arg0 + 0x14));
    func_00126280((*(s32 *)((u8 *)arg0 + 0x40)));
    return temp_s1;
}
/* localdecomp:end func_L39_0060A050 */

/* localdecomp:start func_L39_0060A0A0 */
extern s32 func_001262A0(s32);
extern s32 func_001262A0(s32 a0);

/* from rac2-decomp's func_003512B8, renamed */
void func_L39_0060A0A0(u8 *a0) {
    func_001262A0(*(s32 *)(a0 + 0x40));
    *(s32 *)(a0 + 0x14) = (*(s32 *)(a0 + 0x14) + 0x7ff) / 0x800 * 0x800;
    func_00126280(*(s32 *)(a0 + 0x40));
}
/* localdecomp:end func_L39_0060A0A0 */
