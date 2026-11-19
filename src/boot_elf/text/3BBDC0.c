#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void func_003A0B60(u8 *, u32);
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
void func_003A0B60(u8 *, u32);
extern void func_003A0B60();
/* --- end of declarations from other files --- */

/* declarations of 3BB948.c's earlier functions */
extern void func_0038CF58();
extern void func_11F0A0();
extern void func_003BBB80(s32 a, s32 *p);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003BBDC0);

typedef struct { u8 pad0[8]; s32 f8; u8 pad1[0x90]; s32 tbl[1]; } B_3B6F28;
extern B_3B6F28 *D_00227598_003BC7C0[];
typedef struct { s32 a[1]; } A_3B6F28;
extern s32 D_001DA218_003BC7C0[2];
extern s32 D_001DA240_003BC7C0[2];
extern s32 D_001DA1F0_003BC7C0[2];
typedef struct { u8 pad[0xA4]; u32 fA4; } S_1A30B0_3B6F28;
extern S_1A30B0_3B6F28 D_001A30B0;
extern void func_11F0A0();
extern void func_13BED0();
/* localdecomp:start func_003BC7C0 */
__asm__(".extern D_001DA218_003BC7C0, 16");
__asm__(".extern D_001DA240_003BC7C0, 16");
__asm__(".extern D_001DA1F0_003BC7C0, 16");
void func_003BC7C0(s32 count, s32 *selection) {
    extern void func_003BBB80(s32, s32 *);
    extern void func_11F0A0();
    extern void func_13BED0();
    s32 local[10];
    s32 invalid = -1;
    B_3B6F28 *base = D_00227598_003BC7C0[0];
    u8 *data = (u8 *)base + base->f8;
    s32 *sounds = D_001DA240_003BC7C0;
    s32 *map = D_001DA218_003BC7C0;
    s32 *indices = map;
    s32 *result;
    s32 i;
    s32 *p;
    for (i = 9; i >= 0; i--) {
        *indices++ = invalid;
        *sounds++ = invalid;
    }
    if (selection == 0) {
        for (i = 0; i < count; i++) local[i] = i;
        selection = local;
    }
    D_001A30B0.fA4 = 0xFFFFFFFFU;
    if (count > 0) {
    u8 *entryBase = data + 0x18;
    s32 *offsets = base->tbl;
    s32 flag = 0xC000;
    p = selection;
    i = count;
    do {
        u8 *entry = entryBase + *(s32 *)((u8 *)offsets + (*p++ << 2));
        *(s32 *)(entry + 0x2C) = flag;
        *(s32 *)(entry + 0x28) = flag;
    } while (--i != 0);
    }
    func_11F0A0(0);
    i = 0;
    if (count > 0) {
    s32 *table = base->tbl;
    result = D_001DA1F0_003BC7C0;
    do {
        s32 index = *selection;
        s32 *output = result++;
        selection++;
        map[index] = i;
        func_003BBB80((s32)(data + *(s32 *)((u8 *)table + (index << 2))), output);
        i++;
    } while(i < count);
    }
    func_13BED0();
}
/* localdecomp:end func_003BC7C0 */

/* localdecomp:start func_003BC940 */
typedef struct { u8 p0[0xC]; s32 fC; } P_3B70A8;
extern P_3B70A8 *D_00227598[];
extern s32 D_0037FFE8[];
extern void func_11F0A0();
void func_003BC940(s32 a, s32 *out, s32 c) {
    u8 *base;
    s32 n;
    s32 *tbl;
    s32 idx;
    base = (u8 *)D_00227598[0] + D_00227598[0]->fC;
    n = *(s32 *)base;
    tbl = (s32 *)(base + 0x10);
    if (a < 0x1E && (idx = D_0037FFE8[a]) != -1 && idx < n && tbl[idx] != 0) {
    } else {
        a = 0;
    }
    func_11F0A0(0);
    *out = ((s32 (*)(u8 *, u32))func_003A0B60)(base + tbl[D_0037FFE8[a]], c);
    func_11F0A0(0);
}
/* localdecomp:end func_003BC940 */

/* localdecomp:start func_003BCA28 */
extern unsigned long func_0039B088(s32);
void func_003BCA28(s32 a, unsigned long *out) {
    *out = func_0039B088(a);
}
/* localdecomp:end func_003BCA28 */

typedef struct { s32 off; s32 sz; } E_3B71B8;
typedef struct { u8 pad0[0x68]; s32 f68; s32 f6C; u8 pad70[0x20]; s32 f90[0x44]; } S_225780_3B71B8;
typedef struct { u8 pad0[8]; s32 f8; u8 pad1[0x60]; s32 tbl[1]; } H_3B71B8;
typedef struct { u8 pad0[0xC]; s32 fC; s32 f10; u8 *f14; H_3B71B8 *f18; } S_227600_3B71B8;
extern S_225780_3B71B8 D_00225700_003BCA50;
extern S_227600_3B71B8 D_00227580;
extern s32 D_001DA058;
extern void func_0038CF58();
/* localdecomp:start func_003BCA50 */
/* PAL candidate for func_003BCA50 (frontbin).

   Retail reaches D_001DA058_003BCA50 (0x1DA058) with `lui $a2, %hi(D)` +
   `lw $a2, %lo(D)($a2)`, not through $gp, and with the address and the
   loaded word in the same register: the assembler's expansion of a load
   from a global, not gcc's split (an unsized array alias splits into two
   pseudos and the load lands in a different register than the lui).
   The global is declared sized (so gcc leaves the access to the assembler as
   one `lui $at` / `%lo` macro, as for any small global), with an `.extern X, 16` hint before its first use (docs/wiki/Matching-Patterns.md). The hint tells the assembler the global is not small data, so it expands the macro with `lui`,
   as SN's single-pass Ps2EeAs did for a global whose size it had not seen yet.
   The value is read into a local so it is loaded once, like retail.
   See docs/wiki/Matching-Patterns.md, "Globals: gp vs lui". */

typedef struct { s32 off; s32 sz; } E_3B71B8_003BCA50;
typedef struct { u8 pad0[0x68]; s32 f68; s32 f6C; u8 pad70[0x20]; s32 f90[0x44]; } S_225780_3B71B8_003BCA50;
typedef struct { u8 pad0[8]; s32 f8; u8 pad1[0x60]; s32 tbl[1]; } H_3B71B8_003BCA50;
typedef struct { u8 pad0[0xC]; s32 fC; s32 f10; u8 *f14; H_3B71B8_003BCA50 *f18; } S_227600_3B71B8_003BCA50;
extern S_225780_3B71B8_003BCA50 D_00225700_003BCA50_003BCA50;
extern S_227600_3B71B8_003BCA50 D_00227580_003BCA50;
extern s32 D_001DA058_003BCA50;
__asm__(".extern D_001DA058_003BCA50, 16");
extern void func_0038CF58_003BCA50();
void func_003BCA50(s32 a) {
    H_3B71B8_003BCA50 *h;
    u8 *e;
    E_3B71B8_003BCA50 *p;
    s32 i;
    s32 b;
    s32 v;
    S_227600_3B71B8_003BCA50 *s;
    func_0038CF58_003BCA50(&D_00225700_003BCA50_003BCA50, 0, 0x1E0);
    v = D_001DA058_003BCA50;
    s = &D_00227580_003BCA50;
    D_00225700_003BCA50_003BCA50.f68 = s->fC + v;
    D_00225700_003BCA50_003BCA50.f6C = s->f10 + v;
    h = s->f18;
    e = (u8 *)h + h->f8 + h->tbl[a];
    b = (s32)e + 0x800;
    p = (E_3B71B8_003BCA50 *)e;
    for (i = 0; i < 0x44 && p->sz != 0; i++, p++) {
        D_00225700_003BCA50_003BCA50.f90[i] = b + p->off;
    }
}
/* localdecomp:end func_003BCA50 */

/* localdecomp:start func_003BCB20 */
extern void func_003C2C38(s32 p);
typedef struct { u8 p0[0x44]; s16 n; u8 p1[0x15A]; void *slot[1]; } S_B7288;
typedef struct { u8 p0[0xC]; u8 c; u8 p1[0x3B]; s32 q[1]; } I_B7288;
typedef struct { u8 p0[0x24]; I_B7288 *in; } O_B7288;
extern S_B7288 D_00225700;
void func_003BCB20(void) {
    s32 i;
    for (i = 0; i < D_00225700.n; i++) {
        O_B7288 *o = D_00225700.slot[i];
        if (o != 0) {
            o->in->c--;
            *(s32 *)((u8 *)o->in + (o->in->c << 2) + 0x48) = 0;
            func_003C2C38((s32)o);
            D_00225700.slot[i] = 0;
        }
    }
}
/* localdecomp:end func_003BCB20 */

/* localdecomp:start func_003BCBB8 */
extern void func_003865D0(void);
extern void func_003C3178(void);
extern void func_00388348(void);
extern void func_003BCC10(void);
extern void func_00392AC8(void);
extern s32 D_001D9D1C;
extern void (*D_001D8CC0)(void);
void func_003BCBB8(void) {
    void (*fn)(void);
    func_003865D0();
    func_003C3178();
    func_00388348();
    fn = D_001D8CC0;
    D_001D9D1C = -1;
    if (fn != 0) fn();
    func_003BCC10();
    func_00392AC8();
}
/* localdecomp:end func_003BCBB8 */
