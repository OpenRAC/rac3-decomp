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

/* localdecomp:start func_003B6AA8 */
__asm__(".extern D_001D545C_gp_003B1210, 4");
__asm__(".extern D_001D8A9C, 4");
__asm__(".extern D_001D8A40_003B6AA8, 4");
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
void func_003B6AA8(void) {
    s32 v;
    if (func_0039C428()) {
        func_0039C600(D_001D8A9C);
        D_001D8A40_003B6AA8 = 5;
        return;
    }
    D_001425AC[0] = 1;
    func_003A43E0();
    func_003A2B50(1);
    func_0013BFE0(D_00143958[0] == 0);
    v = D_001D545C_gp_003B1210;
    if (D_001D545C_003B6AA8 < 2 && D_001D5571_003B6AA8 == 0) {
        func_003A9308();
    } else {
        *(volatile s32 *)&D_001D5B74 = 1;
        *(volatile s32 *)&D_001D9D04 = v;
    }
    D_001D5638 = 1;
    D_0022CF90[0] = 0;
}
/* localdecomp:end func_003B6AA8 */

/* localdecomp:start func_003B6B60 */
__asm__(".extern D_001D8A9C, 4");
__asm__(".extern D_001D8A40_003B6B60, 4");
__asm__(".extern D_001D8AB9, 1");
__asm__(".extern D_001D545C_003B6B60, 4");
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
void func_003B6B60(void) {
    if (func_0039C428() != 0) {
        func_0039C600(D_001D8A9C);
        D_001D8A40_003B6B60 = 5;
        return;
    }
    D_001425AC[0] = 1;
    func_003A43E0();
    ((s32 (*)(s32))func_003A2B50)(1);
    func_0013BFE0(D_00143958[0] == 0);
    if (D_001D8AB9 != 0) {
        func_003BB490();
    } else {
        func_003BB4A0(D_001D545C_003B6B60);
    }
    D_001D8A40_003B6B60 = 6;
    D_001D5638_003B6B60 = 1;
    D_0022CF90[0] = 0;
}
/* localdecomp:end func_003B6B60 */
