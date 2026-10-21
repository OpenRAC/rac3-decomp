/* US draft of func_003CE9A0 (rac3-uya-decomp func_003CE838, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` and without `-mno-split-addresses` (a single-function override). */


/* localdecomp:start func_003CE9A0 */
typedef E_3C8ED0 E_3C9078;
typedef struct { s16 n; u16 flags; u8 pad[0xC]; E_3C9078 items[1]; } S_3C9078;
extern u32 *D_001DA050_003CE9A0;
extern u8 D_1422E0[];
extern s32 D_1A1ED0[];
extern void func_003CF0C0(E_3C9078 *, s32, u8 *);
extern void func_003CEB38(void);
extern s32 func_003CEBE0(u8 *, u8 *, s32);
extern void func_003CECD8(s32, u8 *, u8 *, u8 *);
extern void func_003A97F8(s32, unsigned long);
void func_003CE9A0(Q_3C8E70 *arg) {
    S_3C9078 *q = (S_3C9078 *)arg;
    E_3C9078 *e;
    u8 *fl;
    s32 i;
    if (q->n != 0) {
        func_003CF0C0(q->items, q->n, (u8 *)0x70003F00);
        func_003CEB38();
        fl = (u8 *)0x70003F00;
        e = q->items;
        D_001DA050_003CE9A0[0] = 0x30000007;
        D_001DA050_003CE9A0[1] = (u32)D_1422E0;
        D_001DA050_003CE9A0[2] = 0;
        D_001DA050_003CE9A0[3] = 0x50000007;
        D_001DA050_003CE9A0 += 4;
        for (i = 0; i < q->n; i++, e++, fl++) {
            if (*fl == 0) {
                u8 *b = e->base;
                u8 *c = b + e->h1C;
                u8 *a0 = b + e->h18;
                u8 *d = b + e->h1A;
                if (func_003CEBE0(a0, (u8 *)0x70000000, e->h14) == 0) {
                    func_003CECD8(q->items[i].h16, c, d, (u8 *)0x70000000);
                }
            }
        }
        func_003A97F8(0x47, 0x3180B);
        func_003A97F8(0x4E, ((D_1A1ED0[2] >> 13) | 0x1000000) | 0x100000000L);
    }
}
/* localdecomp:end func_003CE9A0 */
