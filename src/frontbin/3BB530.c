#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations carried from the file this was cut from */
extern void func_003BB7B0(s32);
extern s32 func_12C908(s32);
extern void func_003A0760(u8 *, u32);
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern s32 func_13B620(void);
void func_003A0760(u8 *, u32);
extern void func_003BB5D0();
extern void func_003BB590(s32);
extern void func_003A0760();
extern s32 func_003BB530(s32);


extern s32 D_001DA1B0_003BB530[];
extern s32 D_001DA1B4_003BB530[];
INCLUDE_ASM("asm/nonmatchings/text", func_003BB530);

/* localdecomp:start func_003BB590 */
extern f32 D_001D8C2C;
extern s32 func_0038DBD8(f32, s32, s32);
extern s32 func_003E7D70(s32, s32);
void func_003BB590(s32 a) {
    func_003E7D70(a, ((s32 (*)(s32, s32, f32))func_0038DBD8)(0x20000000, 0x402299DE, D_001D8C2C));
}
/* localdecomp:end func_003BB590 */

extern f32 D_001D8C30;
extern f32 D_001D8C2C;
INCLUDE_ASM("asm/nonmatchings/text", func_003BB5D0);

LINKER_REMNANT("asm/remnants", func_003BB670);

/* localdecomp:start func_003BB678 */
s32 func_003BB678(void) {
    return 0;
}
/* localdecomp:end func_003BB678 */

/* localdecomp:start func_003BB680 */
typedef struct { s32 f0; s32 f4; } E_3B61A0;
extern E_3B61A0 D_0037FA58[];
extern s32 D_0037FA64[];
extern char D_001D8C40[];
extern char D_001D8C48[];
extern s32 func_00381FF0();
extern void func_11B2E8();
char *func_003BB680(char *buf, s32 n) {
    s32 r;
    s32 x;
    s32 y;
    char *fmt2;
    char *fmt;
    switch (n) {
    case 2:
    case 5:
    case 10:
    case 23:
    case 24:
    case 25:
    case 26:
        r = 0;
        break;
    default:
        r = 1;
        break;
    }
    if (r != 0) {
        fmt = D_001D8C40;
        x = func_00381FF0(0xE2);
        y = func_00381FF0(n > 0 ? D_0037FA58[n % 60].f4 : D_0037FA64[0]);
        func_11B2E8(buf, fmt, x, y);
    } else {
        fmt2 = D_001D8C48;
        y = func_00381FF0(n > 0 ? D_0037FA58[n % 60].f4 : D_0037FA64[0]);
        func_11B2E8(buf, fmt2, y);
    }
    return buf;
}
/* localdecomp:end func_003BB680 */

/* localdecomp:start func_003BB7B0 */
extern u8 D_001D8CB0;
void func_003BB7B0(s32 a) {
    D_001D8CB0 = a;
}
/* localdecomp:end func_003BB7B0 */

/* localdecomp:start func_003BB7B8 */
extern s32 D_001D8CEC;
s32 func_003BB7B8(void) {
    return D_001D8CEC;
}
/* localdecomp:end func_003BB7B8 */

/* localdecomp:start func_003BB7C0 */
extern s32 D_001D8CE8;
s32 func_003BB7C0(void) {
    return D_001D8CE8;
}
/* localdecomp:end func_003BB7C0 */

/* localdecomp:start func_003BB7C8 */
extern void func_13BC30(s32, void *, unsigned long);
extern void func_003A54F0();
extern void func_11F0A0();
void func_003BB7C8(s32 a, s32 *p) {
    s32 m;
    *p = -1;
    func_13BC30(a, func_003A54F0, (u32)p);
    m = -1;
    do {
        func_11F0A0(0);
        func_12C908(0);
        ((s32 (*)(void))func_13B620)();
    } while (*p == m);
}
/* localdecomp:end func_003BB7C8 */

/* localdecomp:start func_003BB838 */
void func_003BB838(s32 a0, long a1) {
    *(s32 *)a1 = a0;
}
/* localdecomp:end func_003BB838 */

extern s32 D_001D8CE0_003BB848;
extern s32 D_001DA1F0_003BB848[1];
extern s32 D_001DA218_003BB848[1];
extern s32 D_001DA240_003BB848[1];
extern void func_13CA20();
extern void func_13CA28();
extern void func_13B620_003BB848();
extern void func_13C0B8(s32, s32, s32, s32, s32, s32, void *, long);
INCLUDE_ASM("asm/nonmatchings/text", func_003BB848);

/* localdecomp:start func_003BB8F0 */
extern int D_001D8CE0_003BB8F0;
extern int D_001DA218[];
extern int D_001DA240[];
extern void func_13C230(int, int, int);

void func_003BB8F0(float volume, int index) {
    int sound;
    register int offset __asm__("$3");
    register int *indices __asm__("$2");
    register int *sounds __asm__("$4");
    register int invalid __asm__("$5");

    if (index >= 0 && index < D_001D8CE0_003BB8F0) {
        offset = index * 4;
        __asm__ volatile("" : "+r"(offset));
        indices = D_001DA218;
        offset += (int)indices;
        __asm__ volatile("" : "+r"(offset));
        sounds = D_001DA240;
        __asm__ volatile("" : "+r"(sounds));
        sound = sounds[*(int *)offset];
        invalid = -1;
        if (sound != invalid) {
            func_13C230(sound, (int)(volume * 1024.0f), 0);
        }
    }
}
/* localdecomp:end func_003BB8F0 */

extern void func_0013CA20(void);
extern void func_0013BF00(s32);
extern void func_0013CA28(void);
extern s32 func_0013B620(void);
extern void func_0013BED0(void);
extern u32 D_001D8CE0;
extern s32 D_001DA1F4[];
extern s32 D_001D4B4C[];
INCLUDE_ASM("asm/nonmatchings/text", func_003BB968);

INCLUDE_ASM("asm/nonmatchings/text", func_003BBA08);

typedef struct { u8 pad0[8]; s32 f8; u8 pad1[0x90]; s32 tbl[1]; } B_3B6F28;
extern B_3B6F28 *D_00227598_003BC408[];
typedef struct { s32 a[1]; } A_3B6F28;
extern s32 D_001DA218_003BC408[2];
extern s32 D_001DA240_003BC408[2];
extern s32 D_001DA1F0_003BC408[2];
typedef struct { u8 pad[0xA4]; u32 fA4; } S_1A30B0_3B6F28;
extern S_1A30B0_3B6F28 D_001A30B0;
extern void func_11F0A0();
extern void func_13BED0();
INCLUDE_ASM("asm/nonmatchings/text", func_003BC408);

/* localdecomp:start func_003BC588 */
typedef struct { u8 p0[0xC]; s32 fC; } P_3B70A8;
extern P_3B70A8 *D_00227598[];
extern s32 D_0037FFE8[];
extern void func_11F0A0();
void func_003BC588(s32 a, s32 *out, s32 c) {
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
    *out = ((s32 (*)(u8 *, u32))func_003A0760)(base + tbl[D_0037FFE8[a]], c);
    func_11F0A0(0);
}
/* localdecomp:end func_003BC588 */

/* localdecomp:start func_003BC670 */
extern unsigned long func_0039ACA8(s32);
void func_003BC670(s32 a, unsigned long *out) {
    *out = func_0039ACA8(a);
}
/* localdecomp:end func_003BC670 */

/* PAL candidate for func_003BC698 (frontbin).

   Retail reaches D_001DA058 (0x1DA058) with `lui $a2, %hi(D)` +
   `lw $a2, %lo(D)($a2)`, not through $gp, and with the address and the
   loaded word in the same register: the assembler's expansion of a load
   from a global, not gcc's split (an unsized array alias splits into two
   pseudos and the load lands in a different register than the lui).
   The global is declared sized (so gcc leaves the access to the assembler as
   one `lui $at` / `%lo` macro, as for any small global), with an `.extern X, 16` hint before its first use (docs/wiki/Matching-Patterns.md). The hint tells the assembler the global is not small data, so it expands the macro with `lui`,
   as SN's single-pass Ps2EeAs did for a global whose size it had not seen yet.
   The value is read into a local so it is loaded once, like retail.
   See docs/wiki/Matching-Patterns.md, "Globals: gp vs lui". */

/* localdecomp:start func_003BC698 */
typedef struct { s32 off; s32 sz; } E_3B71B8;
typedef struct { u8 pad0[0x68]; s32 f68; s32 f6C; u8 pad70[0x20]; s32 f90[0x44]; } S_225780_3B71B8;
typedef struct { u8 pad0[8]; s32 f8; u8 pad1[0x60]; s32 tbl[1]; } H_3B71B8;
typedef struct { u8 pad0[0xC]; s32 fC; s32 f10; u8 *f14; H_3B71B8 *f18; } S_227600_3B71B8;
extern S_225780_3B71B8 D_00225700_003BC698;
extern S_227600_3B71B8 D_00227580;
extern s32 D_001DA058;
__asm__(".extern D_001DA058, 16");
extern void func_0038CB78();
void func_003BC698(s32 a) {
    H_3B71B8 *h;
    u8 *e;
    E_3B71B8 *p;
    s32 i;
    s32 b;
    s32 v;
    S_227600_3B71B8 *s;
    func_0038CB78(&D_00225700_003BC698, 0, 0x1E0);
    v = D_001DA058;
    s = &D_00227580;
    D_00225700_003BC698.f68 = s->fC + v;
    D_00225700_003BC698.f6C = s->f10 + v;
    h = s->f18;
    e = (u8 *)h + h->f8 + h->tbl[a];
    b = (s32)e + 0x800;
    p = (E_3B71B8 *)e;
    for (i = 0; i < 0x44 && p->sz != 0; i++, p++) {
        D_00225700_003BC698.f90[i] = b + p->off;
    }
}
/* localdecomp:end func_003BC698 */

/* localdecomp:start func_003BC768 */
extern void func_003C2880(s32 p);
typedef struct { u8 p0[0x44]; s16 n; u8 p1[0x15A]; void *slot[1]; } S_B7288;
typedef struct { u8 p0[0xC]; u8 c; u8 p1[0x3B]; s32 q[1]; } I_B7288;
typedef struct { u8 p0[0x24]; I_B7288 *in; } O_B7288;
extern S_B7288 D_00225700;
void func_003BC768(void) {
    s32 i;
    for (i = 0; i < D_00225700.n; i++) {
        O_B7288 *o = D_00225700.slot[i];
        if (o != 0) {
            o->in->c--;
            *(s32 *)((u8 *)o->in + (o->in->c << 2) + 0x48) = 0;
            func_003C2880((s32)o);
            D_00225700.slot[i] = 0;
        }
    }
}
/* localdecomp:end func_003BC768 */

/* localdecomp:start func_003BC800 */
extern void func_003861F0(void);
extern void func_003C2DC0(void);
extern void func_00387F68(void);
extern void func_003BC858(void);
extern void func_003926E8(void);
extern s32 D_001D9D1C;
extern void (*D_001D8CC0)(void);
void func_003BC800(void) {
    void (*fn)(void);
    func_003861F0();
    func_003C2DC0();
    func_00387F68();
    fn = D_001D8CC0;
    D_001D9D1C = -1;
    if (fn != 0) fn();
    func_003BC858();
    func_003926E8();
}
/* localdecomp:end func_003BC800 */
