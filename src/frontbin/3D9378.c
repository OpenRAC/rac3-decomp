#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
typedef struct { u8 pad0[0x24]; f32 f24; f32 f28; u8 pad2C[4]; s32 f30; u8 pad34[4]; s32 f38; s32 f3C; u8 pad40[8]; s32 f48; s32 f4C; } E_3A3028_003A8450;
extern void func_003D9508(E_3A3028_003A8450 *, s32, s32, s32, f32, f32, f32);
/* --- end of declarations from other files --- */

/* declarations carried from the file this was cut from */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void func_003D9CF0(void);
extern void func_003D9C30(void);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_003D9DA8();
extern void func_003D9450();
extern void func_003D9740(void *, s32, s32, s32, s32, f32);


LINKER_REMNANT("asm/remnants", func_003D9378);

/* localdecomp:start func_003D93B0 */
extern long func_00389598(s32);
extern u8 D_00380E60[];

void func_003D93B0(void *arg0, s32 arg1, s32 arg2, long arg3) {
    void *temp_s0;

    (*(long *)((u8 *)(arg0) + 0x78)) = func_00389598(arg1);
    (*(long *)((u8 *)(arg0) + 0x80)) = (long) (0xFF9000000000 | 0x260);
    (*(long *)((u8 *)(arg0) + 0x70)) = 0;
    temp_s0 = (arg2 * 0x14) + D_00380E60;
    (*(long *)((u8 *)(arg0) + 0x88)) = (long) ((*(s32 *)((u8 *)(temp_s0) + 0)) | ((long) (*(s32 *)((u8 *)(temp_s0) + 4)) * 4) | ((long) (*(s32 *)((u8 *)(temp_s0) + 8)) * 0x10) | ((long) (*(s32 *)((u8 *)(temp_s0) + 0xC)) << 6) | (arg3 << 0x20));
}
/* localdecomp:end func_003D93B0 */

/* localdecomp:start func_003D9450 */
typedef int u128_3D3EE0 __attribute__((mode(TI)));
extern void func_003D93B0(void *, s32, s32, long);
void func_003D9450(u8 *p, s32 a1, s32 a2, f32 *src, u128_3D3EE0 *q, s32 a5) {
    s32 i;
    f32 *fp;
    s32 *ip;
    func_003D93B0(p, a1, a5, 0x80);
    ip = (s32 *)(p + 0x40);
    fp = (f32 *)(p + 0x54);
    for (i = 0; i < 4; i++) {
        fp[i * 2 - 1] = src[i * 2];
        fp[i * 2] = src[i * 2 + 1];
        ip[i] = a2;
        ((u128_3D3EE0 *)p)[i] = q[i];
    }
}
/* localdecomp:end func_003D9450 */

INCLUDE_ASM("asm/nonmatchings/text", func_003D94E8);

INCLUDE_ASM("asm/nonmatchings/text", func_003D9508);

typedef int Q_3D3FA0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_3D3FA0;
typedef struct { V_3D3FA0 v[4]; s32 c[4]; f32 uv[8]; long t70, t78, t80, t88; } B_3D3FA0;
extern V_3D3FA0 D_00222400_003D3FA0[];
extern V_3D3FA0 D_001D9180[];
typedef struct { u8 pad[0x80]; f32 f80[4]; u8 pad2[0x3D0]; } G_3D3FA0;
extern G_3D3FA0 D_002225D0_003D3FA0[];
extern u8 D_002225D0[];
extern s32 D_001D52F0;
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038D308(void *, void *);
extern void func_0038D5F0(void *, void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038D028(void *, void *, void *);
extern void func_003D2DA0(void *, s32, s32);

LINKER_REMNANT("asm/remnants", func_003D96F8);

typedef struct { f32 x, y, z; } P_3D41E0;
typedef struct { f32 a, b; } T_3D41E0;
extern f32 D_001D9390;
extern f32 D_001D93C0;
extern s32 D_001D9348;
extern P_3D41E0 D_002FF880[];
extern s32 D_002FF988[];
extern T_3D41E0 D_002FF9E0[];
extern void func_003A9440(s32, unsigned long);
extern long func_00389598(s32);
extern void func_0038C750(void);
extern void func_0038D028();
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern void func_003D3A24(s32, void *, void *, void *, s32);
INCLUDE_ASM("asm/nonmatchings/text", func_003D9740);

INCLUDE_ASM("asm/nonmatchings/text", func_003D9BE0);

/* func_003D9C00: PAL frontbin.
 *
 * Retail (PAL, 0x003D9C00):
 *   addiu $sp, $sp, -0x10
 *   lui   $4, 0x1d
 *   lw    $4, 0x4bb0($4)
 *   sd    $31, 0($sp)
 *   jal   func_003DCBF0
 *   jal   func_003A9618
 *   ld    $31, 0($sp)
 *   jr    $31
 *
 * The global read is the "no split" form: the high part of the address is
 * materialised in the destination register itself ($4), so the load reads
 * %lo(D)($4) instead of %lo(D)($2).  With a plain, size-less declaration
 * gcc materialises the address in the split-address register ($2), giving
 * "lui $2 / lw $4, lo($2)".  A sized declaration makes gcc emit a $gp
 * relative reference, and the assembler expands that back into the
 * lui/lw pair with the destination register as the base, which is exactly
 * what retail has.
 */

/* localdecomp:start func_003D9C00 */
extern s32 D_001D4BB0_003D9C00;
__asm__(".extern D_001D4BB0_003D9C00, 16");
extern void func_003DCBF0(s32);
extern void func_003A9618(void);
void func_003D9C00(void) {
    func_003DCBF0(D_001D4BB0_003D9C00);
    func_003A9618();
}
/* localdecomp:end func_003D9C00 */

/* localdecomp:start func_003D9C30 */
typedef struct { s16 a; s16 b; } T_D46E0;
typedef struct { u8 p0[0x33]; u8 f33; } E_D46E0;
typedef struct { u8 p0[0xF]; u8 cnt; u8 q[0xC]; E_D46E0 *ent; } O_D46E0;
extern s32 D_00304EC0[];
extern O_D46E0 *D_002FFAC0[];
extern T_D46E0 D_003048C0[];
void func_003D9C30(void) {
    s32 *p;
    s32 i;
    O_D46E0 *o;
    u8 *e;
    for (p = D_00304EC0; *p >= 0; p++) {
        o = D_002FFAC0[*p];
        e = (u8 *)o->ent;
        for (i = 0; i < o->cnt; i++) {
            T_D46E0 *t = &D_003048C0[e[0x33]];
            if (t->a != 0) { *(u32 *)e = (*(u32 *)e & 0xFFFFC000) | t->a; }
            if (t->b != 0) { *(u32 *)(e + 0x20) = (*(u32 *)(e + 0x20) & 0xFFFFC000) | t->b; }
            e += 0x50;
        }
    }
}
/* localdecomp:end func_003D9C30 */

extern s32 D_001D4BB4;
void func_0038CD28(s32, s32 *, s32);
void func_003A8F90(s32 *);
extern void func_003A9440(s32, unsigned long);
void func_003DAD90();
void func_003DC160();
void func_003DCEA0();
void func_11F0A0(s32);
extern s32 D_001D4BB0_003D9CF0;
extern u8 D_001D7960[];
extern s32 D_001DA050_003D9CF0;
extern u8 D_100AE0[];
extern u8 D_1159B0[];
/* localdecomp:start func_003D9CF0 */
/* Candidate for func_003D9CF0 (PAL retail, file flags -mvu0-use-vf0-vf2 -O2 -G8
   -fopt-stack -mno-check-zero-division).  Starts from the US near miss in draft.c. */

extern s32 D_001D4BB4_003D9CF0_k;
__asm__(".extern D_001D4BB4_003D9CF0_k, 16");
extern s32 D_001DA050_003D9CF0_h;
__asm__(".extern D_001DA050_003D9CF0_h, 16");
extern s32 D_001DA050_003D9CF0_i;
__asm__(".extern D_001DA050_003D9CF0_i, 16");
extern s32 D_001DA050_003D9CF0_j;
__asm__(".extern D_001DA050_003D9CF0_j, 16");
void func_003D9C00();
void func_003D9E28();

void func_003D9CF0(void) {
    func_003A9440(0x47, 0x5340B);
    D_001D4BB0_003D9CF0 = D_001D4BB4_003D9CF0_k;
    func_11F0A0(0);
    func_003D9E28();
    func_003D9C00();
    func_11F0A0(0);
    func_003DCEA0();
    func_003A8F90(D_1159B0);
    func_003DAD90();
    func_003DC160();
    func_003A8F90(D_100AE0);
    func_0038CD28(D_001DA050_003D9CF0_h, D_001D7960, 0x20);
    D_001DA050_003D9CF0_j = D_001DA050_003D9CF0_i + 0x20;
}
/* localdecomp:end func_003D9CF0 */

LINKER_REMNANT("asm/remnants", func_003D9DA0);

typedef struct {
    u8 pad[0x7614];
    s32 value;
} SourceBlock_003D4858;
extern u8 *D_001DA704;
extern u8 *D_001DA708;
extern s32 D_001DA710;
extern s32 D_001DA728;
extern s32 D_001DA72C;
extern s32 D_001DA730;
extern u8 *D_001DA734;
/* localdecomp:start func_003D9DA8 */
/* Retail reaches these through lui/%lo, not $gp: the size hints tell the assembler they are not small data. */
__asm__(".extern D_001DA704, 16");
__asm__(".extern D_001DA708, 16");
__asm__(".extern D_001DA710, 16");
__asm__(".extern D_001DA728, 16");
__asm__(".extern D_001DA72C, 16");
__asm__(".extern D_001DA734, 16");
extern s32 D_00227594[];
extern u8 D_002FFCC0[];

typedef struct { u8 p0[0x14]; u16 h14; s16 h16; u8 p18[7]; u8 b1F; } Entry_003D9DA8;

void func_003D9DA8(void) {
    s32 source;
    u8 *buffer;
    Entry_003D9DA8 *entry;

    source = D_00227594[0];
    buffer = D_002FFCC0;
    entry = (Entry_003D9DA8 *)D_001DA704;
    D_001DA710 = source;
    D_001DA734 = buffer;
    D_001DA728 = 0;
    D_001DA72C = 0;
    D_001DA730 = 0;
    if (entry != (Entry_003D9DA8 *)D_001DA708) {
        u16 empty = 0xFFFF;
        for (; entry != (Entry_003D9DA8 *)D_001DA708; entry++) {
            entry->b1F = 0xFF;
            entry->h16 = 0;
            entry->h14 = empty;
        }
    }
}
/* localdecomp:end func_003D9DA8 */
