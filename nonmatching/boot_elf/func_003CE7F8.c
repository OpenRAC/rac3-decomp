/* US draft of func_003CE7F8 (rac3-uya-decomp func_003CE690, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` and without `-mno-split-addresses` (a single-function override). */


/* localdecomp:start func_003CE7F8 */
typedef struct { u8 pad[0x10]; u8 *base; s16 h14; s16 h16; s16 h18; s16 h1A; s16 h1C; s16 h1E; } E_3C8ED0;
typedef struct { s16 n; u16 flags; u8 pad[0xC]; E_3C8ED0 items[1]; } S_3C8ED0;
extern u32 *D_001DA050_003CE7F8;
extern s32 D_001D9348;
extern u8 D_001423C0[];
extern u8 D_00142350[];
extern void func_003CF0C0(E_3C8ED0 *, s32, u8 *);
extern void func_003CEB38(void);
extern s32 func_003CEBE0(u8 *, u8 *, s32);
extern s32 func_003CEDD8(s32, u8 *, u8 *, u8 *, s32);
void func_003CE7F8(Q_3C8E70 *arg) {
    S_3C8ED0 *q = (S_3C8ED0 *)arg;
    E_3C8ED0 *e;
    u8 *fl;
    s32 i;
    s32 alt;
    s32 drawn;
    s32 prev;
    if (q->n != 0) {
        func_003CF0C0(q->items, q->n, (u8 *)0x70003F00);
        func_003CEB38();
        fl = (u8 *)0x70003F00;
        alt = (q->flags >> 1) & 1;
        D_001DA050_003CE7F8[0] = 0x30000007;
        drawn = 0;
        D_001DA050_003CE7F8[2] = 0;
        D_001DA050_003CE7F8[3] = 0x50000007;
        if (alt) D_001DA050_003CE7F8[1] = (u32)D_001423C0;
        else D_001DA050_003CE7F8[1] = (u32)D_00142350;
        prev = -1;
        D_001DA050_003CE7F8 += 4;
        for (i = 0, e = q->items; i < q->n; i++, e++, fl++) {
            if (*fl == 0) {
                u8 *b = e->base;
                u8 *c = b + e->h1C;
                u8 *a0 = b + e->h18;
                u8 *d = b + e->h1A;
                if (func_003CEBE0(a0, (u8 *)0x70000000, e->h14) == 0) {
                    drawn = 1;
                    prev = func_003CEDD8(e->h16, c, d, (u8 *)0x70000000, prev);
                }
            }
        }
        if (alt && drawn) D_001D9348 |= 4;
    }
}
/* localdecomp:end func_003CE7F8 */
