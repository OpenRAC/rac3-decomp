#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* localdecomp:start func_003C33C8 */
typedef struct { u8 pB_[0xB]; u8 bB; u8 pC[0x14]; s32 f20; } T_3BDEA8;
typedef struct { u8 p0[0x24]; T_3BDEA8 *f24; } O_3BDEA8;
extern u8 *D_001DA530;
extern u8 D_002FC1A0[];
extern u8 D_00380120[];
extern u8 D_001D7830[];
extern void func_0038CD28();
extern void (*D_001D9A40[2])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern int D_001DA050;
typedef struct { u8 pB_[0xB]; u8 bB; u8 pC[0x14]; s32 f20; } T_3BDEA8_3C33C8;
typedef struct { u8 p0[0x24]; T_3BDEA8_3C33C8 *f24; } O_3BDEA8_3C33C8;
extern u8 *D_001DA530;
extern u8 D_002FC1A0[];
extern u8 D_00380120[];
extern u8 D_001D7830[];
extern void func_0038CD28();
extern void func_0038CD28(u32 *, s32, s32);

void func_003C33C8(void) {
    u32 *pkt;
    u8 *e;
    if (D_001DA530 == D_002FC1A0) return;
    pkt = (u32 *)D_001DA050;
    D_001DA050 = (int)(pkt + 4);
    for (e = D_002FC1A0; e < D_001DA530; e += 8) {
        u32 *a = *(u32 **)e;
        u32 b = *(u32 *)(e + 4);
        O_3BDEA8_3C33C8 *o;
        T_3BDEA8_3C33C8 *t;
        s32 lo, hi, idx;
        s32 base;
        s32 j;
        a[0] = 0x20000000;
        idx = b & 0xF;
        o = (O_3BDEA8_3C33C8 *)(b & ~0xF);
        a[1] = D_001DA050;
        a[3] = 0x11000000;
        t = o->f24;
        hi = t->bB >> 4;
        lo = t->bB & 0xF;
        base = t->f20 - ((lo * hi) << 10) - 0x10;
        for (j = 0; j < hi; j++) {
            s16 h = ((s16 *)base)[j];
            func_0038CD28(D_001DA050, D_00380120, 0x70);
            ((s16 *)D_001DA050)[0x12] = h;
            ((u32 *)D_001DA050)[0x19] = base + (idx << 10) + 0x10 + ((j * lo) << 10);
            D_001DA050 = D_001DA050 + 0x70;
        }
        ((u32 *)D_001DA050)[0] = 0x30000003;
        ((u32 *)D_001DA050)[1] = (u32)D_001D7830;
        ((u32 *)D_001DA050)[2] = 0;
        ((u32 *)D_001DA050)[3] = 0x50000003;
        D_001DA050 = D_001DA050 + 0x10;
        ((u32 *)D_001DA050)[0] = 0x20000000;
        ((u32 *)D_001DA050)[1] = (u32)(a + 4);
        ((u32 *)D_001DA050)[2] = 0;
        ((u32 *)D_001DA050)[3] = 0;
        D_001DA050 = D_001DA050 + 0x10;
    }
    pkt[0] = 0x20000000;
    pkt[1] = D_001DA050;
    pkt[2] = 0;
    pkt[3] = 0;
}
/* localdecomp:end func_003C33C8 */

/* func_003C35F0: from the US C of func_003BE0D0 (rac3-uya-decomp, commit 13cf5c5), matched here with
   this file's flags. */

/* Retail reaches the word at 0x001D9D30 through lui/lw in the destination register, not $gp: the
   assembler's expansion, through an alias declared sized with an `.extern X, 16` hint (docs/wiki/Matching-Patterns.md: gcc leaves the access to the assembler as one macro, which the hint makes it expand with lui, as SN's single-pass Ps2EeAs did). */


/* localdecomp:start func_003C35F0 */
extern s32 D_001D9D30_003C35F0;
__asm__(".extern D_001D9D30_003C35F0, 16");
extern u8 D_00380250[];
extern s32 D_001D9D38;
extern void func_11F0A0(s32);
extern void func_0038CD28(u32 *, s32, s32);
extern void func_003CB300();
void func_003C35F0(void) {
    func_11F0A0(0);
    func_0038CD28((u32 *)0x70003800, (s32)D_00380250, 0x800);
    func_003CB300(D_001D9D30_003C35F0, D_001D9D38);
}
/* localdecomp:end func_003C35F0 */
