#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void func_003BBB68(s32);
extern s32 func_12C908(s32);
extern void func_003A0B60(u8 *, u32);
extern void (*D_001D9A40[2])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern s32 func_13B620(void);
void func_003A0B60(u8 *, u32);
extern void func_003BB988();
extern void func_003BB948(s32);
extern void func_003A0B60();
/* --- end of declarations from other files --- */

/* declarations of 3BB3B8.c's earlier functions (tools/port_from_us.py) */
extern s32 D_0037FA44[];
typedef struct {
    char pad_0[0x74];
    s32 field_74;      
    s32 field_78;       
} TargetStruct_0037BA20;
extern TargetStruct_0037BA20 D_0037F9D0;
extern s32 D_0037FA44[];
extern s8 D_001D8BF0[1];
typedef struct { u8 pad[0xC]; u8 *buf[4]; } S_3B5CA0;
extern S_3B5CA0 D_0037F9D0_003BB538[];
extern u8 D_002D0040[];
extern void func_0038CF58();
typedef struct { u32 a; u32 b; } E_3B5D10;
extern E_3B5D10 D_001DA1B0_003BB5A8[1];
extern u8 D_001D5BDC;
extern u8 D_00280FC0[];
extern void *D_001DA1B0[];
extern u32 D_001DA1B4[];
extern s32 func_003BB8E8(s32);
extern void func_0038CF58();
typedef struct { s32 id; s32 fl; } E_3B5F88;
typedef struct { u8 pad[4]; s16 f4; } S_3B5F88;
extern E_3B5F88 D_001DA1B0_003BB820[1];
extern s32 D_001DA1B4_003BB820[2];
extern s32 D_001DA1B4_003B5F88b[2];
extern S_3B5F88 D_1CCFD0_003BB820[];
extern void func_003A2958();
extern s32 D_001DA1B0_003BB8E8[];
extern s32 D_001DA1B4_003BB8E8[];

/* localdecomp:start func_003BB948 */
extern f32 D_001D8C2C;
extern s32 func_0038DFB8(f32, s32, s32);
extern s32 func_003E8128(s32, s32);
void func_003BB948(s32 a) {
    func_003E8128(a, ((s32 (*)(s32, s32, f32))func_0038DFB8)(0x20000000, 0x402299DE, D_001D8C2C));
}
/* localdecomp:end func_003BB948 */

extern f32 D_001D8C30;
extern f32 D_001D8C2C;
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003BB988);

LINKER_REMNANT("asm/boot_elf/remnants", func_003BBA28);

/* localdecomp:start func_003BBA30 */
s32 func_003BBA30(void) {
    return 0;
}
/* localdecomp:end func_003BBA30 */

/* localdecomp:start func_003BBA38 */
typedef struct { s32 f0; s32 f4; } E_3B61A0;
extern E_3B61A0 D_0037FA58[];
extern s32 D_0037FA64[];
extern char D_001D8C40[];
extern char D_001D8C48[];
extern s32 func_003823D0();
extern void func_11B2E8();
char *func_003BBA38(char *buf, s32 n) {
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
        x = func_003823D0(0xE2);
        y = func_003823D0(n > 0 ? D_0037FA58[n % 60].f4 : D_0037FA64[0]);
        func_11B2E8(buf, fmt, x, y);
    } else {
        fmt2 = D_001D8C48;
        y = func_003823D0(n > 0 ? D_0037FA58[n % 60].f4 : D_0037FA64[0]);
        func_11B2E8(buf, fmt2, y);
    }
    return buf;
}
/* localdecomp:end func_003BBA38 */

/* localdecomp:start func_003BBB68 */
extern u8 D_001D8CB0;
void func_003BBB68(s32 a) {
    D_001D8CB0 = a;
}
/* localdecomp:end func_003BBB68 */

/* localdecomp:start func_003BBB70 */
extern s32 D_001D8CEC;
s32 func_003BBB70(void) {
    return D_001D8CEC;
}
/* localdecomp:end func_003BBB70 */

/* localdecomp:start func_003BBB78 */
extern s32 D_001D8CE8;
s32 func_003BBB78(void) {
    return D_001D8CE8;
}
/* localdecomp:end func_003BBB78 */

/* localdecomp:start func_003BBB80 */
extern void func_13BC30(s32, void *, unsigned long);
extern void func_003A58F0();
extern void func_11F0A0();
void func_003BBB80(s32 a, s32 *p) {
    s32 m;
    *p = -1;
    func_13BC30(a, func_003A58F0, (u32)p);
    m = -1;
    do {
        func_11F0A0(0);
        func_12C908(0);
        ((s32 (*)(void))func_13B620)();
    } while (*p == m);
}
/* localdecomp:end func_003BBB80 */

/* localdecomp:start func_003BBBF0 */
void func_003BBBF0(s32 a0, long a1) {
    *(s32 *)a1 = a0;
}
/* localdecomp:end func_003BBBF0 */

extern s32 D_001D8CE0_003BBC00;
extern s32 D_001DA1F0_003BBC00[1];
extern s32 D_001DA218_003BBC00[1];
extern s32 D_001DA240_003BBC00[1];
extern void func_13CA20();
extern void func_13CA28();
extern void func_13B620_003BBC00();
extern void func_13C0B8(s32, s32, s32, s32, s32, s32, void *, long);
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003BBC00);

/* localdecomp:start func_003BBCA8 */
extern int D_001D8CE0_003BBCA8;
extern int D_001DA218[];
extern int D_001DA240[];
extern void func_13C230(int, int, int);

void func_003BBCA8(float volume, int index) {
    int sound;
    register int offset __asm__("$3");
    register int *indices __asm__("$2");
    register int *sounds __asm__("$4");
    register int invalid __asm__("$5");

    if (index >= 0 && index < D_001D8CE0_003BBCA8) {
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
/* localdecomp:end func_003BBCA8 */

extern void func_0013CA20(void);
extern void func_0013BF00(s32);
extern void func_0013CA28(void);
extern s32 func_0013B620(void);
extern void func_0013BED0(void);
extern u32 D_001D8CE0;
extern s32 D_001DA1F4[];
extern s32 D_001D4B4C[];
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003BBD20);

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
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003BC7C0);

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
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003BCA50);

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
