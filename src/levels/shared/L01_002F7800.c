#include "common.h"

/* localdecomp:start func_L01_002F7800 */
void func_L01_002F7800(void) {
}
/* localdecomp:end func_L01_002F7800 */

/* localdecomp:start func_L01_002F7808 */
typedef struct {
    float a[4];
    float b[4];
} Pair_002F7888;
typedef struct {
    u8 pad[16];
    float f;
    u8 pad2[8];
} Src_002F7888;
extern s32 D_L01_001DC2C0;
extern Pair_002F7888 D_L01_0026E050[];
extern Src_002F7888 D_L01_002BE708[];
extern void func_0038D750(float *, s32, float);
void func_L01_002F7808(void) {
    s32 i;
    if (D_L01_001DC2C0 == 0) {
        for (i = 0; i < 10; i++) {
            func_0038D750(D_L01_0026E050[i].a, 0, D_L01_002BE708[i].f);
            func_0038D750(D_L01_0026E050[i - 1].b, 0, -D_L01_002BE708[i].f);
        }
        D_L01_001DC2C0 = 1;
    }
}
/* localdecomp:end func_L01_002F7808 */

INCLUDE_ASM("asm/levels", func_L01_002F78B0);

INCLUDE_ASM("asm/levels", func_L01_002F88E0);

INCLUDE_ASM("asm/levels", func_L01_002F8AA8);

INCLUDE_ASM("asm/levels", func_L01_002F8D40);

/* localdecomp:start func_L01_002F8F10 */
void func_L01_002F8F10(void) {

}
/* localdecomp:end func_L01_002F8F10 */

LINKER_REMNANT("asm/levels", func_L01_002F8F18);

INCLUDE_ASM("asm/levels", func_L01_002F8F20);

INCLUDE_ASM("asm/levels", func_L01_002F9310);

INCLUDE_ASM("asm/levels", func_L01_002F94F8);

INCLUDE_ASM("asm/levels", func_L01_002F9578);

INCLUDE_ASM("asm/levels", func_L01_002F9738);

INCLUDE_ASM("asm/levels", func_L01_002F9830);

INCLUDE_ASM("asm/levels", func_L01_002F98F8);

INCLUDE_ASM("asm/levels", func_L01_002F9A18);

INCLUDE_ASM("asm/levels", func_L01_002F9B08);

INCLUDE_ASM("asm/levels", func_L01_002F9F20);

INCLUDE_ASM("asm/levels", func_L01_002FA1F8);

INCLUDE_ASM("asm/levels", func_L01_002FAAA0);

INCLUDE_ASM("asm/levels", func_L01_002FB208);

INCLUDE_ASM("asm/levels", func_L01_002FB2F0);

INCLUDE_ASM("asm/levels", func_L01_002FB5A8);

INCLUDE_ASM("asm/levels", func_L01_002FB660);

INCLUDE_ASM("asm/levels", func_L01_002FB7D8);

INCLUDE_ASM("asm/levels", func_L01_002FBB10);

INCLUDE_ASM("asm/levels", func_L01_002FBCD0);

INCLUDE_ASM("asm/levels", func_L01_002FC3E8);

/* localdecomp:start func_L01_002FC8A8 */
typedef struct {
    s32 w0;
    s32 w4;
    s32 w8;
    s32 wC;
} S_2FC880b;

typedef struct {
    u8 pad0[0x20];
    u8 b20;
    u8 pad21[0x30 - 0x21];
    u8 b30;
    u8 b31;
    s16 h32;
    u8 pad34[0x68 - 0x34];
    S_2FC880b *p68;
} S_2FC880;

extern S_2FC880 *func_003C24B0(s32 a0, s32 a1);

S_2FC880 *func_L01_002FC8A8(s32 a0) {
    S_2FC880 *p = func_003C24B0(167, 128);
    if (p != 0) {
        S_2FC880b *q = p->p68;
        q->w4 = a0;
        q->w0 = 0;
        q->w8 = 0;
        q->wC = 0;
        p->b30 = 255;
        p->h32 = 126;
        p->b31 = 0;
        p->b20 = 0;
    }
    return p;
}
/* localdecomp:end func_L01_002FC8A8 */

INCLUDE_ASM("asm/levels", func_L01_002FC910);

INCLUDE_ASM("asm/levels", func_L01_002FCDC0);

/* localdecomp:start func_L01_002FD090 */
extern void func_L01_004C70A8(u8 *, u8 *, s32, s32, float);
void func_L01_002FD090(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 104);
    if (*(s32 *)(p + 36) != 0) {
        func_L01_004C70A8(p, p + 16, 0, 1, 1.0f);
    }
}
/* localdecomp:end func_L01_002FD090 */

INCLUDE_ASM("asm/levels", func_L01_002FD0C8);

INCLUDE_ASM("asm/levels", func_L01_002FD288);

INCLUDE_ASM("asm/levels", func_L01_002FD530);

INCLUDE_ASM("asm/levels", func_L01_002FD818);

INCLUDE_ASM("asm/levels", func_L01_002FD988);

INCLUDE_ASM("asm/levels", func_L01_002FDA10);

INCLUDE_ASM("asm/levels", func_L01_002FDBD8);

INCLUDE_ASM("asm/levels", func_L01_002FDC18);

INCLUDE_ASM("asm/levels", func_L01_002FE0A0);

INCLUDE_ASM("asm/levels", func_L01_002FE280);
