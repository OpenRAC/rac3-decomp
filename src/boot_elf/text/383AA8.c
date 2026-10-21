#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations of 382780.c's earlier functions (tools/port_from_us.py) */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_37E0F0;
typedef int Q_37E0F0 __attribute__((mode(TI)));
extern u8 *D_001D9A20;
extern void func_0038D3E0_00382760(void *, void *, void *);
extern s32 func_0013D3E0(void);
extern s32 func_0013D3E0(void);
extern s32 func_13D3E0(void);
extern s32 func_0013D3E0(void);
extern f32 func_00382918(void);
extern f32 func_003828C0(f32, f32);
extern void func_00382B40(void *, f32, f32, f32);
extern f32 func_0038D478(f32);
extern f32 func_0038D490(f32);
typedef struct { u8 pad[0x424]; f32 f424; f32 f428; f32 f42C; f32 f430; f32 f434; u8 b438; u8 b439; u16 h43A; f32 f43C; f32 f440; u8 pad2[0x1C]; } E_0037E568;
extern E_0037E568 D_00222480_00382BF0[];
typedef struct { u8 pad[0x424]; f32 f424; f32 f428; f32 f42C; f32 f430; f32 f434; u8 b438; u8 b439; s16 h43A; f32 f43C; f32 f440; u8 pad2[0x1C]; } E_0037E630;
extern E_0037E630 D_00222480_00382CB8[];
extern f32 D_002259B0[];
extern void func_00383038(f32 *, f32, f32, f32, f32, f32);
extern s32 func_0038CEE0(void *);
extern f32 func_0038D478(f32);
extern f32 func_0038D490(f32);
extern f32 func_003C3FA0(f32, f32, f32);
extern void func_003877A0();
void func_0038D108(void *, void *, s32);
typedef struct { u8 pad0[0x50]; void *f50; u8 pad54[0x460 - 0x54]; } S_00222500_0037E7D8;
extern S_00222500_0037E7D8 D_00222480[];
extern u8 D_00224B10[];
extern u8 D_00225450[];
extern s32 D_001D9A80[2];
extern void (*D_001D9A40[2])(s32);
extern void func_0038DE98(f32, f32);
extern f32 func_0038DEE0(f32, f32);
s32 func_00381C88(void *, s32, s32, s32);
extern void func_003C2C38(s32 p);
extern u8 D_002224E0[];
typedef struct { s32 a, b, c, d, e; } S_37D000;
extern S_37D000 D_00380F80[];
typedef int u128_37EB68 __attribute__((mode(TI)));
typedef struct { u8 p0[0x2B8]; f32 f2B8; u8 p2BC[0xC]; f32 f2C8; u8 p2CC[0x58]; s32 f324; u8 p328[0x138]; } E_37EB68;
extern E_37EB68 D_00222480_003831F0[];
extern u8 *D_001D9A84;
extern u8 D_002251D0[];
extern void func_00382E60(s32);
extern void func_003831A8(u8 *);
typedef struct { u8 p0[0xC]; s32 fC; u8 p10[0x24 - 0x10]; s32 f24; } T_37EE80;
typedef struct { u8 p0[0x1C]; T_37EE80 *f1C; } R_37EE80;
typedef struct { u8 p0[0x5D0]; s32 f5D0; u8 p5D4[0x5E0 - 0x5D4]; s32 f5E0; u8 p5E4[0x690 - 0x5E4]; s32 f690; u8 p694[0x6A0 - 0x694]; s32 f6A0; u8 p6A4[0x25CC - 0x6A4]; s32 f25CC; } A_37EE80;
typedef struct { u8 p0[0x24C]; s32 f24C; u8 p250[0x460 - 0x250]; } E_37EE80;
extern u8 *D_001D9A84_00383508;
typedef struct { u8 p0[0x10]; s32 f10; u8 p14[0xC]; } G2_37EE80;
extern G2_37EE80 *D_001D9E50;
extern A_37EE80 D_001A4BE0_00383508;
extern E_37EE80 D_00222480_00383508[];
extern u8 D_002225D0[];
extern s32 func_00382760(void *, s32, s32);
extern S_37D000 D_00380F80[];
extern u8 D_00222A10_00383760[];
extern u8 D_001D9B10_00383760[8];
extern void func_00383718(u8 *);
extern s32 func_00383508(s32, u8 *, u8 *);
extern void func_003831F0(u8 *, s32);
extern void func_00383128(s32, void *);
extern void func_00382F00(s32);
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_37F228;
typedef int Q_37F228 __attribute__((mode(TI)));
extern f32 func_0038D248(void *, void *);
extern f32 func_0038D288(void *);
extern f32 func_0038D4A8(f32);
extern void func_0038DC70(void *, void *, void *, f32);
extern void func_0038D348(s32 a, s32 b, f32 x);

/* localdecomp:start func_00383AA8 */
typedef int u128_37F420 __attribute__((mode(TI)));
extern void func_0038D348(s32 a, s32 b, f32 x);
extern void func_003838B0();
extern u8 D_00222480_00383AA8[];
void func_00383AA8(s32 idx) {
    u128_37F420 v[3];
    u8 *p = D_00222480_00383AA8 + idx * 0x460;
    u8 *q = p + 0x150;
    func_0038D348((s32)&v[0], *(s32 *)(q + 0xF0) + 0xC0, 1.0f);
    func_0038D348((s32)&v[1], *(s32 *)(q + 0xF0) + 0xD0, 1.0f);
    func_0038D348((s32)&v[2], *(s32 *)(q + 0xF0) + 0xE0, 1.0f);
    *(u128_37F420 *)(p + 0x330) = v[0];
    *(u128_37F420 *)(p + 0x340) = v[2];
    func_003838B0(p + 0x310, p + 0x360, p + 0x190, &v[0], &v[1], &v[2]);
    *(u128_37F420 *)(p + 0x350) = *(u128_37F420 *)(p + 0x370);
}
/* localdecomp:end func_00383AA8 */

/* localdecomp:start func_00383B80 */
typedef int u128_37F4F8 __attribute__((mode(TI)));
typedef struct { u8 p0[2]; u8 b2; u8 b3; u8 p4[0x50 - 4]; u128_37F4F8 q50; u128_37F4F8 q60; u8 p70[0xC0 - 0x70]; u128_37F4F8 qC0; u128_37F4F8 qD0; u8 pE0[0x460 - 0xE0]; } E_37F4F8;
extern E_37F4F8 D_00222720_00383B80[];
void func_00383B80(s32 idx) {
    s32 off = idx * 0x460;
    E_37F4F8 *e = (E_37F4F8 *)((u8 *)D_00222720_00383B80 + off);
    u8 *b;
    if (e->b2 == 0) {
        e->qC0 = e->q50;
        if (e->b3 == 2) {
            b = (u8 *)D_00222720_00383B80 - 0xE0;
            __asm__ __volatile__("lqc2 $vf2, 0xC0(%0)" : : "r"(e));
            __asm__ __volatile__("lqc2 $vf1, 0(%0)\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0xC0(%1)" : : "r"((u8 *)(off + (s32)b)), "r"(e) : "memory");
        }
        e->qD0 = e->q60;
    }
}
/* localdecomp:end func_00383B80 */

/* localdecomp:start func_00383BD8 */
typedef int u128_t __attribute__((mode(TI)));
extern u8 D_00222720[];
void func_00383BD8(s32 arg0) {
    u8 *p = D_00222720 + arg0 * 0x460;
    if (p[2] != 0) {
        *(u128_t *)(p + 0x50) = *(u128_t *)(p + 0xC0);
        *(u128_t *)(p + 0x60) = *(u128_t *)(p + 0xD0);
    }
}
/* localdecomp:end func_00383BD8 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_00383C10);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_00383E48);

typedef struct { f32 f0, f4, f8, fC, f10, f14, f18, f1C; } A_37F588;
typedef struct { s32 p0[3]; s32 fC; f32 f10; s32 f14; } R_37F588;
typedef struct {
    s16 f0; u8 b2; u8 b3; u8 p4[0xC]; A_37F588 a; u128_t q30; u128_t q40; u128_t q50; u128_t q60; R_37F588 r;
} E_37F588;
extern u8 D_00222480_00383C18[];
extern void func_003C4BA0();
typedef int Q_37F7A8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_37F7A8;
typedef struct { f32 f0, f4; u8 p8[8]; f32 f10, f14; u8 p18[8]; V_37F7A8 v20; V_37F7A8 v30; u128_t q40; u8 m50[0x40]; } B_37F7A8;
typedef struct { u8 p0[0x30]; f32 f30, f34, f38; u8 p3C[0x94 - 0x3C]; s32 f94; } O_37F7A8;
typedef struct { u128_t q0; u8 p10[0x1C0 - 0x10]; V_37F7A8 v1C0; u8 p1D0[0x380 - 0x1D0]; u8 m380[0x40]; u8 p3C0[0x460 - 0x3C0]; } E_37F7A8;
extern E_37F7A8 D_00222480_00383E38[];
extern void func_003C4BA0(void *, void *);
extern void func_0038D970(void *, void *);
extern void func_0038DAA8_00383E38(void *, void *, void *, f32);
extern void func_0038DC10_00383E38(void *, void *);
extern f32 func_003C3FA0(f32, f32, f32);
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_00384028);

extern u8 D_00222720[];
extern u8 D_00222480_00384598[];
extern s32 func_00384028();
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_00384598);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_00384640);
