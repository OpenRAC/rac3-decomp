#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations of 3CE2C0.c's earlier functions */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
typedef struct { u16 pad; u16 flags; } Q_3C8E70;
extern void func_003CE5E8(Q_3C8E70 *);
extern void func_003CE440(Q_3C8E70 *);

typedef struct { u8 pad[0x10]; u8 *base; s16 h14; s16 h16; s16 h18; s16 h1A; s16 h1C; s16 h1E; } E_3C8ED0;
typedef struct { s16 n; u16 flags; u8 pad[0xC]; E_3C8ED0 items[1]; } S_3C8ED0;
extern u32 *D_001DA050_003CE440;
extern s32 D_001D9348;
extern u8 D_001423C0[];
extern u8 D_00142350[];
extern void func_003CED08(E_3C8ED0 *, s32, u8 *);
extern void func_003CE780(void);
extern s32 func_003CE828(u8 *, u8 *, s32);
extern s32 func_003CEA20(s32, u8 *, u8 *, u8 *, s32);
/* localdecomp:start func_003CE440 */
void func_003CE440(Q_3C8E70 *arg) {
    S_3C8ED0 *q = (S_3C8ED0 *)arg;
    E_3C8ED0 *e;
    u8 *fl;
    s32 i;
    s32 alt;
    s32 drawn;
    s32 prev;
    if (q->n != 0) {
        func_003CED08(q->items, q->n, (u8 *)0x70003F00);
        func_003CE780();
        fl = (u8 *)0x70003F00;
        alt = (q->flags >> 1) & 1;
        D_001DA050_003CE440[0] = 0x30000007;
        drawn = 0;
        D_001DA050_003CE440[2] = 0;
        D_001DA050_003CE440[3] = 0x50000007;
        if (alt) D_001DA050_003CE440[1] = (u32)D_001423C0;
        else D_001DA050_003CE440[1] = (u32)D_00142350;
        prev = -1;
        D_001DA050_003CE440 += 4;
        for (i = 0, e = q->items; i < q->n; i++, e++, fl++) {
            if (*fl == 0) {
                u8 *b = e->base;
                u8 *c = b + e->h1C;
                u8 *a0 = b + e->h18;
                u8 *d = b + e->h1A;
                if (func_003CE828(a0, (u8 *)0x70000000, e->h14) == 0) {
                    drawn = 1;
                    prev = func_003CEA20(e->h16, c, d, (u8 *)0x70000000, prev);
                }
            }
        }
        if (alt && drawn) D_001D9348 |= 4;
    }
}
/* localdecomp:end func_003CE440 */

typedef E_3C8ED0 E_3C9078;
typedef struct { s16 n; u16 flags; u8 pad[0xC]; E_3C9078 items[1]; } S_3C9078;
extern u32 *D_001DA050_003CE5E8;
extern u8 D_1422E0[];
extern s32 D_1A1ED0[];
extern void func_003CED08(E_3C9078 *, s32, u8 *);
extern void func_003CE780(void);
extern s32 func_003CE828(u8 *, u8 *, s32);
extern void func_003CE920(s32, u8 *, u8 *, u8 *);
extern void func_003A9440(s32, unsigned long);
/* localdecomp:start func_003CE5E8 */
/* from rac1-decomp's SkyDrawShellGouraud */
void func_003CE5E8(Q_3C8E70 *arg) {
    S_3C9078 *q = (S_3C9078 *)arg;
    E_3C9078 *e;
    u8 *fl;
    s32 i;
    if (q->n != 0) {
        func_003CED08(q->items, q->n, (u8 *)0x70003F00);
        func_003CE780();
        fl = (u8 *)0x70003F00;
        e = q->items;
        D_001DA050_003CE5E8[0] = 0x30000007;
        D_001DA050_003CE5E8[1] = (u32)D_1422E0;
        D_001DA050_003CE5E8[2] = 0;
        D_001DA050_003CE5E8[3] = 0x50000007;
        D_001DA050_003CE5E8 += 4;
        for (i = 0; i < q->n; i++, e++, fl++) {
            if (*fl == 0) {
                u8 *b = e->base;
                u8 *c = b + e->h1C;
                u8 *a0 = b + e->h18;
                u8 *d = b + e->h1A;
                if (func_003CE828(a0, (u8 *)0x70000000, e->h14) == 0) {
                    func_003CE920(q->items[i].h16, c, d, (u8 *)0x70000000);
                }
            }
        }
        func_003A9440(0x47, 0x3180B);
        {
            s32 *d1 = D_1A1ED0;
            func_003A9440(0x4E, ((d1[2] >> 13) | 0x1000000) | 0x100000000L);
        }
    }
}
/* localdecomp:end func_003CE5E8 */

LINKER_REMNANT("asm/remnants", func_003CE778);
