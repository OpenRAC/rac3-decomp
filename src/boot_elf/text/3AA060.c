#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* localdecomp:start func_003AA060 */
extern u8 D_001D8064;
void func_003AA060(u8 a) { D_001D8064 = a; }
/* localdecomp:end func_003AA060 */

/* localdecomp:start func_003AA068 */
extern u8 D_001D8064;
u8 func_003AA068(void) {
    return D_001D8064;
}
/* localdecomp:end func_003AA068 */

/* localdecomp:start func_003AA070 */
u8 *func_003AA070(u8 *p) {
    register u8 *r __asm__("$8");
    __asm__ __volatile__(
        ".set noreorder\n"
        "daddu $8, $4, $0\n"
        "lw $2, 0x10($8)\n"
        "lw $4, 0x14($8)\n"
        "lw $5, 0x18($8)\n"
        "addu $2, $2, $8\n"
        "lw $3, 0x1C($8)\n"
        "addu $4, $4, $8\n"
        "addu $5, $5, $8\n"
        "lw $6, 0x20($8)\n"
        "addu $3, $3, $8\n"
        "sw $2, 0x10($8)\n"
        "sw $4, 0x14($8)\n"
        "sw $5, 0x18($8)\n"
        "beqz $6, .L003A47AC_003A4768\n"
        "sw $3, 0x1C($8)\n"
        "addu $2, $6, $8\n"
        "sw $2, 0x20($8)\n"
        ".L003A47AC_003A4768:\n"
        "lwc1 $f0, 0xC($8)\n"
        "daddu $10, $0, $0\n"
        "lui $at, 0x3b52\n"
        "ori $at, $at, 0x79bc\n"
        "mtc1 $at, $f1\n"
        "lh $2, 0x6($8)\n"
        "mul.s $f0, $f0, $f1\n"
        "lw $9, 0x18($8)\n"
        "blez $2, .L003A4854_003A4768\n"
        "swc1 $f0, 0xC($8)\n"
        "addiu $11, $0, 0x1E\n"
        ".L003A47D8_003A4768:\n"
        "lw $3, 0x0($9)\n"
        "sll $5, $10, 4\n"
        "lw $2, 0x18($8)\n"
        "addiu $10, $10, 0x1\n"
        "lw $7, 0x4($9)\n"
        "sra $3, $3, 4\n"
        "lw $4, 0x8($9)\n"
        "addu $2, $5, $2\n"
        "lw $6, 0xC($9)\n"
        "sra $7, $7, 4\n"
        "sh $3, 0xA($2)\n"
        "plzcw $4, $4\n"
        "subu $4, $11, $4\n"
        "plzcw $6, $6\n"
        "lw $3, 0x18($8)\n"
        "subu $6, $11, $6\n"
        "addu $3, $5, $3\n"
        "sh $7, 0x8($3)\n"
        "lw $2, 0x18($8)\n"
        "addu $2, $5, $2\n"
        "sh $4, 0xC($2)\n"
        "lw $3, 0x18($8)\n"
        "addu $3, $5, $3\n"
        "sh $6, 0xE($3)\n"
        "lw $2, 0x18($8)\n"
        "addu $5, $5, $2\n"
        "sd $0, 0x0($5)\n"
        "lh $2, 0x6($8)\n"
        "slt $2, $10, $2\n"
        "bnez $2, .L003A47D8_003A4768\n"
        "addiu $9, $9, 0x10\n"
        ".L003A4854_003A4768:\n"
        ".set reorder\n"
        : "=r"(r) : : "memory"
    );
    return r;
}
/* localdecomp:end func_003AA070 */

typedef struct { u8 p0[0x16]; s16 h16; } F_3A4860;
typedef struct { u8 p0[4]; s16 n; u8 p6[2]; s16 nframes; s16 stride; u8 pC[0x14]; u8 *data; } A_3A4860;
typedef struct { f32 m[16]; } M_3A4860;
extern void func_0038DDF0();
extern void func_0038DE48(void *, void *, void *, f32);
extern void func_0038DD58();
extern void func_0038DA20();
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003AA168);

extern int D_001DA050[];

/* localdecomp:start func_003AA328 */
extern int D_001DA050[];
extern u32 *D_001DA050_g;
extern u8 D_001D8030;
void func_003AA328(void) {
    ((u32 *)D_001DA050[0])[0] = 0x30000003;
    ((u32 *)D_001DA050[0])[1] = (u32)&D_001D8030;
    ((u32 *)D_001DA050[0])[2] = 0;
    ((u32 *)D_001DA050[0])[3] = 0x50000003;
    D_001DA050_g = (u32 *)D_001DA050[0] + 4;
}
/* localdecomp:end func_003AA328 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003AA380);

/* US draft of func_003AA6D8 (rac3-uya-decomp func_003AA588, commit 13cf5c5), names moved to PAL addresses
   where known. The called helper is func_003AA780 in PAL (func_003AA630 in the US build). */


/* localdecomp:start func_003AA6D8 */
typedef struct { u8 p0[0xC]; f32 fC; } O_A4DC8;
extern void func_0038D680();
extern void func_003AA780(O_A4DC8 *, f32, f32, s32, f32, f32 *);
void func_003AA6D8(O_A4DC8 *o, s32 flag, f32 a, f32 b, f32 c, f32 d, f32 e) {
    f32 m[16];
    if ((flag >> 24) != 0) {
        func_0038D680(m);
        m[0] = c * o->fC;
        m[10] = d * o->fC;
        func_003AA780(o, a, b, flag, e, m);
    }
}
/* localdecomp:end func_003AA6D8 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003AA780);
