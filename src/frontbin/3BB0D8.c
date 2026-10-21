#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void func_003BB7B0(s32);
extern s32 func_12C908(s32);
extern void func_003A0760(u8 *, u32);
extern void (*D_001D9A40[2])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern s32 func_13B620(void);
void func_003A0760(u8 *, u32);
extern s32 func_003BD4B8();
extern void func_003BB5D0();
extern void func_003BB590(s32);
extern void func_003A0760();
extern void func_003BB0D8(void);
extern void func_003BB0E8(s32);
extern void func_003BB1F0(s32);
extern s32 func_003BB3A8(s32);
extern void func_003BB180(void);
extern s32 func_003BB118(u32);
extern s32 func_003BB100(s32);
/* --- end of declarations from other files --- */

/* localdecomp:start func_003BB0D8 */
extern s32 D_0037FA44[];
 
void func_003BB0D8(void) {
    D_0037FA44[0] = 7;
}
/* localdecomp:end func_003BB0D8 */

/* localdecomp:start func_003BB0E8 */
typedef struct {
    char pad_0[0x74];
    s32 field_74;      
    s32 field_78;       
} TargetStruct_0037BA20;

extern TargetStruct_0037BA20 D_0037F9D0;

void func_003BB0E8(s32 arg_a0) {
    D_0037F9D0.field_74 = 1;
    D_0037F9D0.field_78 = arg_a0;
}
/* localdecomp:end func_003BB0E8 */

/* localdecomp:start func_003BB100 */
extern s32 D_0037FA44[];
s32 func_003BB100(s32 a0) {
    return D_0037FA44[0] == a0;
}
/* localdecomp:end func_003BB100 */

/* localdecomp:start func_003BB118 */
s32 func_003BB118(u32 i) {
    if (i < 4) {
        return ((struct { s32 pad[3]; s32 arr[4]; } *)&D_0037F9D0)->arr[i];
    }
    return 0;
}
/* localdecomp:end func_003BB118 */

LINKER_REMNANT("asm/remnants", func_003BB140);

/* localdecomp:start func_003BB148 */
extern s8 D_001D8BF0[1];
s32 func_003BB148(s32 i) {
    if (i >= 60) return -1;
    return D_001D8BF0[i];
}
/* localdecomp:end func_003BB148 */

LINKER_REMNANT("asm/remnants", func_003BB170);

/* localdecomp:start func_003BB180 */
typedef struct { u8 pad[0xC]; u8 *buf[4]; } S_3B5CA0;
extern S_3B5CA0 D_0037F9D0_003BB180[];
extern u8 D_002CFFC0[];
extern void func_0038CB78();
void func_003BB180(void) {
    s32 i;
    u8 *p = D_002CFFC0;
    for (i = 0; i < 4; i++) { u8 *q = p + i * 0x800; D_0037F9D0_003BB180[0].buf[i] = q; func_0038CB78(q, 0, 0x800); }
}
/* localdecomp:end func_003BB180 */

typedef struct { u32 a; u32 b; } E_3B5D10;
extern E_3B5D10 D_001DA1B0_003BB1F0[1];
extern u8 D_001D5BDC;
extern u8 D_00280FC0[];
INCLUDE_ASM("asm/nonmatchings/text", func_003BB1F0);

extern void *D_001DA1B0[];
extern u32 D_001DA1B4[];
extern s32 func_003BB530(s32);
extern void func_0038CB78();
INCLUDE_ASM("asm/nonmatchings/text", func_003BB3A8);

typedef struct { s32 id; s32 fl; } E_3B5F88;
typedef struct { u8 pad[4]; s16 f4; } S_3B5F88;
extern E_3B5F88 D_001DA1B0_003BB468[1];
extern s32 D_001DA1B4_003BB468[2];
extern s32 D_001DA1B4_003B5F88b[2];
extern S_3B5F88 D_1CCFD0_003BB468[];
extern void func_003A2558();
INCLUDE_ASM("asm/nonmatchings/text", func_003BB468);

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
   loaded word in the same register.  With the file's own flags (no
   @ps2as) that shape only comes out of a plain constant address: a
   sized extern is $gp-relative, and an unsized array alias splits into
   two pseudos (the load lands in a different register than the lui).
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
    v = *(s32 *)0x1DA058;
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

typedef struct { u8 p0[0x15C]; s32 f15C; s32 f160; s32 f164; } S_142430_3B7378;
extern S_142430_3B7378 D_142430_003BC858;
extern s32 D_001D99A4;
extern s32 D_001D4BC4;
extern s32 D_001D9BC8;
extern f32 D_001D8CF0;
extern void func_00389240(s32);
extern void func_003A9440(s32, unsigned long);
extern long func_00389598(s32);
extern void func_0038B4D0(s32, s32, s32, s32, s32, s32, s32, s32, long, long);
extern void func_00397638(f32, f32, f32, f32, f32, s32, s32, long);
extern void func_00389370(void);
extern void func_0038AE20(s32, s32, s32, s32);
INCLUDE_ASM("asm/nonmatchings/text", func_003BC858);

typedef struct { u8 pad[0x22]; u16 f22; } S_16C580c;
extern S_16C580c D_16C580_003BCA48;
extern s32 (*D_001D8CB8)();
extern s32 D_001D8CD4;
extern void (*D_001D8CBC)(s32);
extern s32 D_001D5B94;
extern s32 D_001D9D00;
extern void func_003CD058();
extern void func_003CD350();
INCLUDE_ASM("asm/nonmatchings/text", func_003BCA48);

extern s32 D_001D9348;
extern s32 D_001D9364;
extern s32 D_001D9C10;
extern s32 D_001D9C08;
extern s32 D_001D9C0C;
extern s32 D_001A1ED0_3B7618[];
extern u8 D_00100AE0[];
extern u8 D_002FDC00[];
extern void func_003A9440(s32, unsigned long);
extern void func_003873C0();
extern void func_003861F0();
extern void func_003CF0F0();
extern void func_003A9C70(s32);
extern void func_003A96D8();
extern void func_00389240(s32);
extern void func_00389E28();
extern void func_00389370();
extern void func_003A9678();
extern void func_003C3860();
extern void func_00389DB0();
extern void func_11F0A0(s32);
extern void func_003CD3D8();
extern void func_003A8F90();
extern void func_003A92F0(s32);
extern void func_003D0180();
extern void func_003CF050();
extern void func_003C31B0();
extern void func_00389F68();
extern void func_003864C0(s32);
extern void func_003D85C0_003BCAF8(s32);
extern void func_003D8640();
extern void func_003D9260_003BCAF8(s32);
INCLUDE_ASM("asm/nonmatchings/text", func_003BCAF8);

/* localdecomp:start func_003BCD50 */
extern void func_003CE250(void);
extern void func_003CE1B0(void);
extern void func_003CE2C0(void);
extern void func_003A9440(s32, unsigned long);
extern s32 D_001A1ED8[];
void func_003BCD50(void) {
    func_003CE250();
    func_003CE1B0();
    func_003CE2C0();
    func_003A9440(0x47, 0x5360B);
    func_003A9440(0x4E, (D_001A1ED8[0] >> 13) | 0x1000000);
}
/* localdecomp:end func_003BCD50 */

typedef struct { u8 p0[0x18]; s16 f18; u8 p1A[0x142]; s32 f15C; s32 f160; s32 f164; u8 p168[0x14]; s32 f17C; } S_142430_3B78C8;
typedef struct { u8 p0[7]; u8 f7; u8 p8[8]; } S_1CCFD0_3B78C8;
typedef struct { u8 p0[0x10]; u32 f10; } S_2276C0_3B78C8;
typedef struct { u8 p0[0x90]; s32 f90[6]; } S_1A30B0_3B78C8;
extern s32 D_001D5B94;
extern s32 D_001D9D2C;
extern s32 D_001D4CEC;
extern s32 D_001D545C;
extern s32 D_001D9D04;
extern u8 D_00227480[];
extern S_2276C0_3B78C8 D_00227640;
extern S_1A30B0_3B78C8 D_1A30B0;
extern S_142430_3B78C8 D_142430;
extern S_1CCFD0_3B78C8 D_1CCFD0;
extern void func_0038CB78();
extern void func_003C2D88();
extern void func_11F0A0();
extern void func_13CF80(s32, s32, s32, s32, s32);
extern void func_13CA28(void);
extern void func_003A5430(void);
extern void func_003A1C28(void);
extern void func_13BF00(s32);
extern void func_13BED0(void);
extern void func_0039C410(void);
extern void func_0039ADE0(void);
extern s32 func_13CF40(s32);
extern void func_003A2750(s32);
extern void func_0038A238(s32);
extern void func_0039A150(void);
extern void func_13CDF0(s32);
extern void func_003A9AD0(void);
INCLUDE_ASM("asm/nonmatchings/text", func_003BCDA8);

extern u8 D_001D5571;
s32 func_003A7618_003BCF80(s32);
extern s32 D_001D9D04;
typedef struct { u8 pad0[0x7]; s8 f7; } S_001CCFD0_003B7AA0_003B7AA0;
extern S_001CCFD0_003B7AA0_003B7AA0 D_001CCFD0[];
INCLUDE_ASM("asm/nonmatchings/text", func_003BCF80);

INCLUDE_ASM("asm/nonmatchings/text", func_003BD030);

typedef struct { u8 p0[0x15C]; s32 f15C; s32 f160; s32 f164; } S_142430_3B7EB0;
typedef struct { u8 p0[7]; u8 f7; } S_1CCFD0_3B7EB0;
extern u8 D_001D8CD1;
extern s32 D_001DA1F0;
extern void (*D_001D8CC4)(void);
extern S_142430_3B7EB0 D_142430_003BD390;
extern S_1CCFD0_3B7EB0 D_1CCFD0_003BD390;
extern void func_11F0A0();
extern void func_0039C410(void);
extern void func_0039ADE0(void);
extern s32 func_0039A1E0(void);
extern void func_13BF00(s32);
extern void func_13BED0(void);
extern void func_003A9AD0(void);
extern void func_00387EF0(void);
INCLUDE_ASM("asm/nonmatchings/text", func_003BD390);

extern u8 D_001D5BDC;
extern s32 D_001D9D04;
extern u8 D_001D8CD0;
extern u8 D_001D8CD1;
extern s32 D_001D9D54;
extern s32 D_001D9BC8;
extern s32 D_001D6E90;
extern s32 D_001D4B48;
extern u8 D_001D8CF4;
extern f32 D_001D8CF0;
extern void func_0039EC28(s32, s32);
extern void func_003BCDA8(void);
extern void func_003BD030(void);
extern void func_00387EF0(void);
extern void func_003A3B70(void);
extern s32 func_003BCA48(s32);
extern void func_00387218(void);
extern void func_0039C410(void);
extern void func_0039ADE0(void);
extern void func_003A92F0(s32);
extern s32 func_0039A1E0(void);
extern void func_003A91D0(void);
extern void func_003A9150(void);
extern void func_003923D0(void);
extern void func_003BE200(void);
extern void func_00392748(s32);
extern void func_003922B8(void);
extern void func_00392350(s32);
extern void func_0038A238(s32);
extern void func_003BD390(void);
INCLUDE_ASM("asm/nonmatchings/text", func_003BD4B8);

/* localdecomp:start func_003BD648 */
typedef int u128_3B8168 __attribute__((mode(TI)));
typedef struct { u8 p0[0x38]; s32 idx; u8 p1[0x28]; u8 *tab; } S_3B8168;
extern S_3B8168 D_00225700_003BD648;
extern f32 D_002259B0[];
typedef struct { u8 p0[0x140]; u128_3B8168 q; u8 p1[0x10]; f32 m[3][4]; } D_3BD648;
extern u8 D_002222C0[];
extern void func_003873C0();
extern void func_12FF40(f32 *);
extern void func_130088(f32 *, f32 *, f32);
extern void func_130130(f32 *, f32 *, f32);
extern void func_12FFE0(f32 *, f32 *, f32);
s32 func_003BD648(void) {
    f32 m[16];
    D_3BD648 *d;
    S_3B8168 *s = &D_00225700_003BD648;
    u8 *p = s->tab + s->idx * 32;
    f32 *q = (f32 *)(p + 0x10);
    s32 flag = p[0xC] != 0;
    D_002259B0[0] = q[3];
    func_003873C0();
    *(u128_3B8168 *)(D_002222C0 + 0x140) = *(u128_3B8168 *)p;
    func_12FF40(m);
    func_130088(m, m, *(f32 *)(p + 0x10));
    func_130130(m, m, q[1]);
    func_12FFE0(m, m, q[2]);
    d = (D_3BD648 *)D_002222C0;
    d->m[0][0] = -m[8];
    d->m[1][0] = -m[0];
    d->m[2][0] = m[4];
    d->m[0][1] = -m[9];
    d->m[1][1] = -m[1];
    d->m[2][1] = m[5];
    d->m[0][2] = -m[10];
    d->m[1][2] = -m[2];
    d->m[2][2] = m[6];
    return flag;
}
/* localdecomp:end func_003BD648 */

extern u8 D_001DA2A0[];
extern s32 D_001DA2B0[];
extern f32 D_001DA2B4[];
extern f32 D_001DA2B8[];
INCLUDE_ASM("asm/nonmatchings/text", func_003BD760);

INCLUDE_ASM("asm/nonmatchings/text", func_003BD7A0);

extern f32 func_0038D0B0(f32);
typedef int u128_3B8440 __attribute__((mode(TI)));
extern s32 D_001DA2A0_003BD938[2];
extern f32 D_001DA2BC;
extern s32 D_001DA2B0_003BD938;
extern f32 D_001DA2B4_003BD938;
extern f32 D_001DA2B8_003BD938;
extern void func_003C2F58_003BD938(void *, s32, void *);
extern void func_0038DAB8(f32, f32);
extern f32 func_0038D0B0(f32);
extern void func_00389D60(void (*)(), s32);
extern void func_003BD760(void);
INCLUDE_ASM("asm/nonmatchings/text", func_003BD938);

/* localdecomp:start func_003BDA58 */
/* PROVISIONAL, VU0 j-constraint form. */
typedef int Q_3B8560 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3B8560;
typedef struct { u8 p0[0xC]; u8 c; } I_3B8560;
typedef struct {
    u8 p0[0x10];
    V4_3B8560 v10;
    u8 p20[0x4];
    I_3B8560 *f24;
    u8 p28[0xA];
    s16 f32;
    u8 p34[0xC];
    u8 f40, f41, f42, f43;
    f32 f44;
    u8 p48[0x19];
    u8 f61, f62;
    u8 p63[0x5];
    u8 *f68;
    u8 p6C[0x3E];
    s16 fAA;
} O_3B8560;
typedef struct { u8 p0[0x38]; s32 f38; u8 p3C[0x8]; s16 n; u8 p46[0x15A]; O_3B8560 *slot[1]; } S_3B8560;
extern S_3B8560 D_00225700_003BDA58;
extern void func_0038CE20(f32 *, void *, f32);
extern void func_003C29B0();
extern void func_003C7C38();
extern void func_003BD938(u8 *);
void func_003BDA58(void) {
    s32 i;
    for (i = 0; i < D_00225700_003BDA58.n; i++) {
        V4_3B8560 a, b;
        Q_3B8560 x, y, r;
        O_3B8560 *o = D_00225700_003BDA58.slot[i];
        s32 bits = D_00225700_003BDA58.f38;
        s32 hi = bits >> 1;
        u8 *t = o->f68;
        s32 k;
        o->f44 = (f32)(bits & 1) * 0.5f;
        func_0038CE20(&a.x, t + hi * 16, 1.0f - o->f44);
        func_0038CE20(&b.x, t + (hi + 1) * 16, o->f44);
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*(Q_3B8560 *)&a));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*(Q_3B8560 *)&b));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(o->v10) : "j"(r));
        o->f42 = o->f24->c - 1;
        o->f43 = o->f24->c - 1;
        o->f40 = hi;
        o->f41 = hi + 1;
        func_003C29B0(o);
        o->f62 = 0xFF;
        o->f61 = 0xFF;
        o->f32 = 0x1FF;
        func_003C7C38(o);
        o->f42 = o->f24->c - 1;
        o->f43 = o->f24->c - 1;
        k = o->fAA;
        if (k == 10 || k == 0x19C9 || k == 0x1159 || k == 0x57 || k == 0x259 || k == 0x1F6B) {
            func_003BD938((u8 *)o);
        }
    }
}
/* localdecomp:end func_003BDA58 */

/* US draft of func_003BDBF8 (rac3-uya-decomp func_003B8700, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: differs: did not build, or built to other bytes, in PAL. */


/* localdecomp:start func_003BDBF8 */
extern void func_0039A690(s32);
extern void func_003BB848(s32);
extern s32 func_003BD648(void);
extern void func_003BDA58(void);
extern s32 D_001D8CDC;
extern s32 D_0016C5E4[];
typedef struct { u8 pad0[0x34]; s32 f34; s32 f38; s32 f3C; s16 f40; } S_003B8700;
extern S_003B8700 D_00225700_003BDBF8[];
s32 func_003BDBF8(void) {
    S_003B8700 *p = D_00225700_003BDBF8;
    s32 temp_3;
    s32 temp_4;
    s32 var_17;

    var_17 = 0;
        p->f38 = p->f38 + 1;
        temp_3 = p->f34 + 1;
        p->f34 = temp_3;
    if (temp_3 == 1) {
        func_003BB848(D_0016C5E4[0]);
    }
    if (p->f40 >= p->f34) {
        if (p->f38 >= 0x50) {
            temp_4 = p->f3C + 1;
            p->f3C = temp_4;
            func_0039A690(temp_4);
        }
        func_003BD648();
        func_003BDA58();
    } else {
        var_17 = 1;
        D_001D8CDC = D_001D8CDC + 1;
    }
    return var_17;
}
/* localdecomp:end func_003BDBF8 */

extern s32 D_001D8CFC;
extern s32 D_001D8CF8;
extern s32 D_001DA268[];
extern s8 D_001DA290[];
INCLUDE_ASM("asm/nonmatchings/text", func_003BDCB0);

extern s8 D_001DA299[];
/* localdecomp:start func_003BDD08 */
void func_003BDD08(void) {
    s32 var_v1;
    s8 *var_v0;

    var_v1 = 9;
    do { var_v0 = D_001DA299; } while (0);
    do {
        *var_v0 = 0;
        var_v1 -= 1;
        var_v0 -= 1;
    } while (var_v1 >= 0);
}
/* localdecomp:end func_003BDD08 */

typedef struct { u8 pad[0x64]; s32 f64; } S_16C580_3B8840;
extern S_16C580_3B8840 D_16C580_003BDD38;
extern u8 D_001DA290_003BDD38[1];
extern s32 D_001DA268_003BDD38[2];
extern s32 func_00382468(s32);
extern void func_003BDD08(void);
INCLUDE_ASM("asm/nonmatchings/text", func_003BDD38);

/* localdecomp:start func_003BDE20 */
typedef struct { u8 pad[0x64]; s32 f64; s32 f68; } S_16C580b;
extern S_16C580b D_16C580;
extern void func_003BC698_003BDE20(s32);
extern void func_0039A690(s32);
void func_003BDE20(s32 a) {
    func_003BC698_003BDE20(a);
    D_16C580.f64 = a;
    D_16C580.f68 = 0;
    func_0039A690(0);
}
/* localdecomp:end func_003BDE20 */

/* localdecomp:start func_003BDE60 */
extern void func_003BC698_003BDE60(s32);
extern void func_0039A690(s32);
extern void func_003BDA58(void);
extern void func_003C29B0();
void func_003BDE60(s32 a) {
    s32 i;
    func_003BC698_003BDE60(a);
    D_16C580.f64 = a;
    func_0039A690(0);
    func_003BDA58();
    for (i = 0; i < D_00225700.n; i++) {
        if (D_00225700.slot[i] != 0) {
            func_003C29B0(D_00225700.slot[i]);
        }
    }
}
/* localdecomp:end func_003BDE60 */

/* localdecomp:start func_003BDEF0 */
extern s32 D_0016C5E4[];
 
s32 func_003BDEF0(void) {
    return D_0016C5E4[0];
}
/* localdecomp:end func_003BDEF0 */

/* localdecomp:start func_003BDF00 */
extern s32 D_00225734[];
s32 func_003BDF00(void) {
    return D_00225734[0];
}
/* localdecomp:end func_003BDF00 */

/* localdecomp:start func_003BDF10 */
extern s32 D_001D8CDC;
s32 func_003BDF10(void) { return D_001D8CDC; }
/* localdecomp:end func_003BDF10 */

/* func_003BDF18: from the US C of func_003B8A20 (rac3-uya-decomp, commit 13cf5c5), matched here with
   this file's flags. */


/* localdecomp:start func_003BDF18 */
extern s32 D_001D4B4C[];
extern s32 D_001D4B48;
s32 func_003BDF18(void)
{
  s32 new_var;
  if (new_var)
  {
    new_var = D_001D4B4C[0];
  }
  else
  {
    new_var = D_001D4B4C[0];
  }
  if ((new_var != 0) && (D_001D4B48 >= 2))
  {
    return 1;
  }
  return 0;
}
/* localdecomp:end func_003BDF18 */

/* localdecomp:start func_003BDF40 */
extern s32 D_001DA5C4[];
extern s32 D_001DA5C8[];
/* func_003BDF40: init the three globals of the "frontbin" state.
 *
 * The retail code addresses the first two through a lui/lo pair that the
 * assembler built from a plain symbol reference (no-split-addresses shape:
 * `lui $at` + `sw ..., %lo(sym)($at)`).  With this file's flags (split
 * addresses) gcc always splits a symbol address itself and keeps the high
 * half in a register it allocates ($v0/$a0), so the globals are written
 * through their literal addresses instead: gcc then folds the low half into
 * the store offset and lets the assembler use $at, which is what retail has.
 * 0x1DA5C4 and 0x1DA5C8 are the addresses of D_001DA5C4 and D_001DA5C8;
 * D_001DA5CC is small data and is reached through $gp, as in retail. */

extern s32 D_001DA5CC;

void func_003BDF40(void) {
    s32 v = -1;
    *(s32 *)0x1DA5C4 = 0;
    *(s32 *)0x1DA5C8 = v;
    D_001DA5CC = 0;
}
/* localdecomp:end func_003BDF40 */

/* localdecomp:start func_003BDF60 */
extern f32 D_001D8CF0;
void func_003BDF60(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
  arg1 = arg1 - 1;
  if (arg0 <= 0 || arg0 >= arg1) {
    D_001D8CF0 = 0.0f;
  } else if (arg2 >= arg0) {
    D_001D8CF0 = (f32)arg0 / (f32)arg2;
  } else if (arg1 - arg3 < arg0) {
    D_001D8CF0 = (f32)(arg1 - arg0) / (f32)arg3;
  } else {
    D_001D8CF0 = 1.0f;
  }
  D_001D8CF0 = 1.0f - D_001D8CF0;
}
/* localdecomp:end func_003BDF60 */

/* localdecomp:start func_003BE008 */
extern f32 D_001D8CF0;
void func_003BE008(f32 a) {
    D_001D8CF0 = a;
}
/* localdecomp:end func_003BE008 */

extern u32 D_00142BA0[];
extern s32 D_001D6E90;
INCLUDE_ASM("asm/nonmatchings/text", func_003BE010);

/* func_003BE0C0 (frontbin, PAL).

   The retail bytes read the flag byte with the destination register reused as
   the address base:

       lui   $v0, 0x1d
       lbu   $v0, 0x558c($v0)

   That is the shape gcc gives for a *constant* address (it folds the low half
   of the address into the load's offset).  With the symbol, split addresses
   (this file's flags) give the other shape, with a second register for the
   loaded byte:

       lui   $v0, 0x1d
       lbu   $v1, 0x558c($v0)

   so the flag is read through its literal address, as done elsewhere in this
   project (e.g. func_003B66A0 reads *(u8 *)0x001D5571). */

/* localdecomp:start func_003BE0C0 */
extern s32 func_003BE010(s32, s32, s32);
extern u8 D_001D558C[];
void func_003BE0C0(void) {
    if (func_003BE010(0x1C, 8, 0)) return;
    if (func_003BE010(8, 8, 0)) return;
    if (func_003BE010(8, 0x1B, 0)) return;
    if (func_003BE010(8, 0x1C, 0)) return;
    if (func_003BE010(-1, 8, 0x11)) return;
    if (*(u8 *)0x001D558C != 0) func_003BE010(8, -1, 0x12);
}
/* localdecomp:end func_003BE0C0 */

void func_003A7480(s32);
void func_003A7618(s32);
extern s32 D_001D5B94;
extern s32 D_001D6E90;
typedef struct { u8 pad0[0x7]; s8 f7; } S_001CCFD0_003B8C70_003B8C70;
extern S_001CCFD0_003B8C70_003B8C70 D_001CCFD0_003BE168[];
INCLUDE_ASM("asm/nonmatchings/text", func_003BE168);

/* localdecomp:start func_003BE1F8 */
extern u8 D_001D8CF4;
void func_003BE1F8(s32 a) {
    D_001D8CF4 = a;
}
/* localdecomp:end func_003BE1F8 */

/* PAL candidate for func_003BE200 (US draft of rac3-uya-decomp func_003B8D08).
   Retail reaches the queue pointer at 0x1DA050 through lui/%lo for every access
   but the last one, which sits in the delay slot of the return and goes through
   $gp.  With the default assembler that mix comes from telling the assembler,
   before the function, that the per-function alias is not small data (the
   .extern size hint); the delay-slot store keeps the sized symbol, which the
   assembler reaches through $gp.
   See docs/wiki/Matching-Patterns.md ("Mixed access in one function").
   The per-function alias D_001DA050_003BE200 needs a line in
   config/frontbin/symbol_addrs.txt (0x001DA050) when this lands. */

/* localdecomp:start func_003BE200 */
extern u32 *D_001DA050;
extern u32 *D_001DA050_003BE200;
extern u8 D_001D02D0[];
extern u8 D_001D7300[];
extern s32 D_001D8D00;
__asm__(".extern D_001DA050, 4");
__asm__(".extern D_001DA050_003BE200, 16");

void func_003BE200(void) {
    D_001DA050_003BE200[0] = 0x30000002;
    D_001DA050_003BE200[1] = (u32)&D_001D8D00;
    D_001DA050_003BE200[2] = 0;
    D_001DA050_003BE200[3] = 0x50000002;
    D_001DA050_003BE200 += 4;
    D_001DA050_003BE200[0] = 0x30000029;
    D_001DA050_003BE200[1] = (u32)D_001D02D0;
    D_001DA050_003BE200[2] = 0;
    D_001DA050_003BE200[3] = 0x50000029;
    D_001DA050_003BE200 += 4;
    D_001DA050_003BE200[0] = 0x30000003;
    D_001DA050_003BE200[1] = (u32)D_001D7300;
    D_001DA050_003BE200[2] = 0;
    D_001DA050_003BE200[3] = 0x50000003;
    D_001DA050 = D_001DA050_003BE200 + 4;
}
/* localdecomp:end func_003BE200 */

/* localdecomp:start func_003BE300 */
extern u8 D_001D8CD1;
u8 func_003BE300(void) {
    return D_001D8CD1;
}
/* localdecomp:end func_003BE300 */

/* PAL candidate for func_003BE308 (frontbin).
 *
 * Retail reaches D_001DA49C and D_001DA4A0 through lui/lw, not through $gp:
 *     lui $2, %hi(D_001DA4A0) ; lw $2, %lo(D_001DA4A0)($2)
 *     lui $16, %hi(D_001DA49C) ; lw $16, %lo(D_001DA49C)($16)
 * With the file's assembler a sized scalar extern is small data, so the
 * default assembler reaches it through $gp. The project's way to get retail's
 * lui/lw form with the default assembler is the size hint .extern SYM, 16,
 * which keeps the symbol out of the small data area. Both globals are used by
 * this function only, so the hint changes nothing else in the file.
 */

/* localdecomp:start func_003BE308 */
extern u32 D_001DA49C;
extern u32 D_001DA4A0;
__asm__(".extern D_001DA49C, 16");
__asm__(".extern D_001DA4A0, 16");
void func_003BE308(void (*cb)(u32)) {
    u32 p;
    s32 i;
    for (p = D_001DA49C; p != D_001DA4A0; p += 0x100) {
        cb(p);
    }
    for (i = 0; i < D_00225700.n; i++) {
        if (D_00225700.slot[i] != 0) {
            ((void (*)(void *))cb)(D_00225700.slot[i]);
        }
    }
}
/* localdecomp:end func_003BE308 */

/* func_003BE3B8 (frontbin, PAL).
   Based on the US draft (rac3-uya-decomp func_003B8EC0, commit 13cf5c5), names moved to PAL
   addresses where known. PAL differs in the two constants: 5 instead of 6, 250 instead of 300.

   Retail reaches the global in the "no-split" shape (`lui $at, %hi(sym)` +
   `sw $v1, %lo(sym)($at)`), the one the US matched with `-mno-split-addresses`. With this
   file's own flags (split addresses) a named global always gets a general register as the
   base (`lui $v1, %hi(sym)` + `sw $v0, %lo(sym)($v1)`), but a literal address keeps the
   hi/lo pair in $at, so the store is written with the address D_001DA2C0 lives at. */


/* localdecomp:start func_003BE3B8 */
extern void func_003BBA08(s32, s32);
extern void func_0038A238(s32);
extern s32 D_001DA2C0[];
s32 func_003BE3B8(void) {
    func_003BBA08(0, 0);
    func_0038A238(5);
    *(s32 *)0x1DA2C0 = 250;
    return 1;
}
/* localdecomp:end func_003BE3B8 */

extern s16 D_0016C5A2[];
extern s32 func_0038CAD0(s32 *);
extern u8 D_001DA2C0_003BE3F0;
INCLUDE_ASM("asm/nonmatchings/text", func_003BE3F0);

/* localdecomp:start func_003BE440 */
s32 func_003BE440(void) {
}
/* localdecomp:end func_003BE440 */
