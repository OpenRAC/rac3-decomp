#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* declarations of 3B6828.c's earlier functions (tools/port_from_us.py) */
extern s32 D_001D8AA8;
extern s32 func_0039C428(void);
extern void func_0039C600(s32);
extern s32 D_001D8A40[];
extern s32 D_001D8A40_003B6930;
typedef struct { u8 b[8]; } B8_3B10A8;
typedef struct { s32 f0, f4, f8, fC; B8_3B10A8 f10; s32 f18; } E_3B10A8;
typedef struct { u8 p0[0x30]; E_3B10A8 e[11]; u8 p1[0x17C - 0x30 - 11 * 0x1C]; s32 f17C; } S_3B10A8;
typedef struct { s32 f0; u8 p[0x2E]; u8 f32; } T_3B10A8;
extern S_3B10A8 D_00142430_003B6940;
extern T_3B10A8 D_00142660_003B6940;
extern B8_3B10A8 D_001D4BE0_003B6940;
extern s32 D_001D545C_003B6940;
extern s32 D_001D5528;
extern s32 D_001D8A9C;
extern s32 D_001D8AB4;
extern u8 D_001D8AB8;
extern void func_0039C2D0(s32, s32);
extern s32 D_001D8A9C;
extern u8 D_001D8AB8;
extern void func_0039C2D0(s32, s32);
extern void func_0039C6E0(void);
extern s32 D_001D8A9C;
extern u8 D_001D8AB8;
extern void func_0039C2D0(s32, s32);
extern s32 D_001D8A9C;
extern s32 D_001D8AB4;
extern u8 D_001D8AB9;
extern s32 D_001D545C[];
extern u8 D_001D5571[];
extern void func_0039E9C0(s32);
extern void func_0039C2A0(s16);
extern s32 D_001425AC[];
extern s32 D_00143958[];
extern s32 D_001D545C_gp_003B1210;
extern s32 D_001D545C_003B6AA8;
extern u8 D_001D5571_003B6AA8;
extern s32 D_001D5B74;
extern s32 D_001D9D04;
extern u8 D_001D5638;
extern s32 D_0022CF90[];
extern s32 D_001D8A9C;
extern s32 D_001D8A40_003B6AA8;
extern s32 func_0039C428();
extern void func_0039C600();
extern void func_003A43E0(void);
extern s32 func_003A2B50(s32);
extern void func_0013BFE0(s32);
extern void func_003A9308(void);
extern s32 func_0039C428(void);
extern void func_0039C600(s32);
extern void func_003BB490(void);
extern void func_003BB4A0(s32);
extern void func_003A43E0(void);
extern void func_0013BFE0(s32);
extern s32 D_001D8A9C;
extern s32 D_001D8A40_003B6B60;
extern u8 D_001D8AB9;
extern s32 D_001D545C_003B6B60;
extern s32 D_001425AC[];
extern s32 D_00143958[];
extern s8 D_001D5638_003B6B60;
extern s32 D_0022CF90[];

/* localdecomp:start func_003B6C00 */
extern s32 D_001D8A9C;
extern s32 D_001D8AB4;
extern s32 D_001D8A40_g;
extern void func_003B35E0(void *); // Ensure this prototype matches exactly
extern void func_0039C0E8(void (*)(), s32, void (*)());
extern void func_003B69F0();
extern void func_003B68C8();

void func_003B6C00(void) {
    func_003B35E0((void *)(s32)D_001D8A9C);
    
    // Explicit sequence point
    *(volatile s32 *)&D_001D8A40_g = 1; 
    
    func_0039C0E8(func_003B69F0, D_001D8AB4, func_003B68C8);
}
/* localdecomp:end func_003B6C00 */

/* localdecomp:start func_003B6C40 */
extern void func_0039C250(void);
extern s32 D_001D8A40_g;
void func_003B6C40(void) {
    func_0039C250();
    D_001D8A40_g = 1;
}
/* localdecomp:end func_003B6C40 */

/* localdecomp:start func_003B6C68 */
extern s32 func_0039C050(s32, void *);
extern void func_003B6930();
extern s32 D_001D8A40_g;
s32 func_003B6C68(void) {
    s32 r = func_0039C050(0, func_003B6930);
    D_001D8A40_g = 1;
    return r;
}
/* localdecomp:end func_003B6C68 */

/* localdecomp:start func_003B6C98 */
extern s32 func_0039C050(s32, void *);
extern void func_003B6930();
extern s32 D_001D8A40_g;
s32 func_003B6C98(void) {
    s32 r = func_0039C050(0, func_003B6930);
    D_001D8A40_g = 1;
    return r;
}
/* localdecomp:end func_003B6C98 */

extern unsigned char D_001D5BDC;
extern int D_001D8AB4;
extern int D_001D8A40_g;
extern void func_0039C1A0(int, int, int);
extern void func_003B6A58(void);
extern void func_003B6AA8(void);
extern void func_003B6B60(void);
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003B6CC8);

/* localdecomp:start func_003B6D28 */
extern s32 D_001D8A9C;
extern s32 D_001D8AB4;
extern s32 D_001D8A40_g;
extern void func_003B35E0(void *);
extern void func_0039C0E8();
extern void func_003B6940();
void func_003B6D28(void) {
    func_003B35E0((void *)D_001D8A9C);
    func_0039C0E8(func_003B6940, D_001D8AB4, 0);
    D_001D8A40_g = 1;
}
/* localdecomp:end func_003B6D28 */

/* localdecomp:start func_003B6D68 */
extern s32 D_001D8A9C;
extern s32 D_001D8AB4;
extern s32 D_001D8A40_g;
extern void func_003B35E0(void *);
extern void func_003B8DF0(s32);
extern void func_0039C0E8();
extern void func_003B6A28();
extern void func_003B6900();
void func_003B6D68(void) {
    func_003B35E0((void *)D_001D8A9C);
    func_003B8DF0(D_001D8AB4);
    func_0039C0E8(func_003B6A28, D_001D8AB4, func_003B6900);
    D_001D8A40_g = 1;
}
/* localdecomp:end func_003B6D68 */
