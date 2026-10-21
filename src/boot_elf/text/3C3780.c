#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* declarations of 3C3280.c's earlier functions (tools/port_from_us.py) */
typedef struct { f32 x, y, z, w; } V4_3BDAC8;
typedef struct { f32 m[12]; V4_3BDAC8 v; } M_3BDAC8;
typedef int Q_3BDAC8 __attribute__((mode(TI)));
extern void func_003CA858();
extern void func_0038D200(f32 *, void *, f32);
extern void func_0038D950();
extern void func_0038DA20();
extern int D_001DA050_003C3478;
extern int D_001DA490_003C3478;
extern s32 D_001D4BB0_003C3478;
extern void func_003CB408();
extern void func_003A99D0();
typedef struct { s16 a; s16 b; } T_BDC90;
typedef struct { u8 c[0xC]; s32 fC; } E_BDC90;
typedef struct { u8 p0[0x20]; E_BDC90 *f20; } O_BDC90;
extern s32 D_002DDFF0[];
extern O_BDC90 *D_002DA740[];
extern T_BDC90 D_002DD830[];
extern int D_001DA4E4_003C3640;
extern s32 D_001DA4E0;
extern s32 D_001D9D34_003C3640;
extern s32 D_001D5BA8_003C3640;
extern void func_003D1AC0();
extern void func_003D1768();

/* localdecomp:start func_003C3780 */
typedef struct { u8 pB_[0xB]; u8 bB; u8 pC[0x14]; s32 f20; } T_3BDEA8;
typedef struct { u8 p0[0x24]; T_3BDEA8 *f24; } O_3BDEA8;
extern u8 *D_001DA530;
extern u8 D_002FC1A0[];
extern u8 D_00380120[];
extern u8 D_001D7830[];
extern void func_0038D108();
void func_003C3780(void) {
    u32 *pkt;
    u8 *e;
    if (D_001DA530 == D_002FC1A0) return;
    pkt = (u32 *)D_001DA050_003C3478;
    D_001DA050_003C3478 = (int)(pkt + 4);
    for (e = D_002FC1A0; e < D_001DA530; e += 8) {
        u32 *a = *(u32 **)e;
        u32 b = *(u32 *)(e + 4);
        O_3BDEA8 *o;
        T_3BDEA8 *t;
        s32 lo, hi, idx;
        s32 base;
        s32 j;
        a[0] = 0x20000000;
        idx = b & 0xF;
        o = (O_3BDEA8 *)(b & ~0xF);
        a[1] = D_001DA050_003C3478;
        a[3] = 0x11000000;
        t = o->f24;
        hi = t->bB >> 4;
        lo = t->bB & 0xF;
        base = t->f20 - ((lo * hi) << 10) - 0x10;
        for (j = 0; j < hi; j++) {
            s16 h = ((s16 *)base)[j];
            func_0038D108(D_001DA050_003C3478, D_00380120, 0x70);
            ((s16 *)D_001DA050_003C3478)[0x12] = h;
            ((u32 *)D_001DA050_003C3478)[0x19] = base + (idx << 10) + 0x10 + ((j * lo) << 10);
            D_001DA050_003C3478 = D_001DA050_003C3478 + 0x70;
        }
        ((u32 *)D_001DA050_003C3478)[0] = 0x30000003;
        ((u32 *)D_001DA050_003C3478)[1] = (u32)D_001D7830;
        ((u32 *)D_001DA050_003C3478)[2] = 0;
        ((u32 *)D_001DA050_003C3478)[3] = 0x50000003;
        D_001DA050_003C3478 = D_001DA050_003C3478 + 0x10;
        ((u32 *)D_001DA050_003C3478)[0] = 0x20000000;
        ((u32 *)D_001DA050_003C3478)[1] = (u32)(a + 4);
        ((u32 *)D_001DA050_003C3478)[2] = 0;
        ((u32 *)D_001DA050_003C3478)[3] = 0;
        D_001DA050_003C3478 = D_001DA050_003C3478 + 0x10;
    }
    pkt[0] = 0x20000000;
    pkt[1] = D_001DA050_003C3478;
    pkt[2] = 0;
    pkt[3] = 0;
}
/* localdecomp:end func_003C3780 */

/* localdecomp:start func_003C39A8 */
extern u8 D_00380250[];
extern s32 D_001D9D30;
extern s32 D_001D9D38;
extern void func_11F0A0(s32);
extern void func_0038D108(u32 *, s32, s32);
extern void func_003CB6B8();
void func_003C39A8(void) {
    func_11F0A0(0);
    func_0038D108((u32 *)0x70003800, (s32)D_00380250, 0x800);
    func_003CB6B8(D_001D9D30, D_001D9D38);
}
/* localdecomp:end func_003C39A8 */
