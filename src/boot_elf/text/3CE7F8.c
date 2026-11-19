#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* declarations of 3CE790.c's earlier functions */
typedef struct { u16 pad; u16 flags; } Q_3C8E70;
extern void func_003CE9A0(Q_3C8E70 *);
extern void func_003CE7F8(Q_3C8E70 *);

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
/* localdecomp:start func_003CE7F8 */
/* from rac3-uya-decomp's func_003CE690 */
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
/* localdecomp:start func_003CE9A0 */
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

LINKER_REMNANT("asm/boot_elf/remnants", func_003CEB30);
