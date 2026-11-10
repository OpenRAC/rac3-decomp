#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_006BA5C0);

LINKER_REMNANT("asm/levels", func_L39_006BAAF8);

INCLUDE_ASM("asm/levels", func_L39_006BAB00);

/* localdecomp:start func_L39_006BB148 */
void func_L39_00688400(void *, s32);
void func_L39_006CC158(void *, s32);
extern u8 D_L39_0047E880[];

void func_L39_006BB148(void *arg0, s32 arg1) {
    *(void **)((u8 *)arg0 + 0x60) = D_L39_0047E880;
    func_L39_006CC158(arg0 + 0x8590, 2);
    func_L39_00688400(arg0, arg1);
}
/* localdecomp:end func_L39_006BB148 */

INCLUDE_ASM("asm/levels", func_L39_006BB1A0);

/* localdecomp:start func_L39_006BBB38 */
__asm__(".extern D_L39_0024D760, 16");
__asm__(".extern D_L39_0024D764, 16");
extern u8 D_L39_0024D764;
extern u8 *D_L39_0024D760;
void func_L39_006CC120(void *);
void func_L39_006CC930(void *);
void func_L39_0068A2D0(void *, s32, s32, s32, f32, f32);
void func_L39_0068B2F8(void *, s32, s32);
void func_L39_0067F168(void);
void func_L39_0068ADC8(void *);
void func_L39_006CC158(void *, s32);

void func_L39_006BBB38(u8 *arg0) {
    u8 buf[0x1E0];

    D_L39_0024D764 = 0;
    *(s32 *)(arg0 + 0x318) = 0;
    func_L39_006CC120(buf);
    func_L39_006CC930(buf);
    *(u8 *)(*(u8 **)(D_L39_0024D760 + 0x4C) + 0x168) = 0;
    *(u8 *)(*(u8 **)(D_L39_0024D760 + 0x70) + 0x10) = 0;
    func_L39_0068A2D0(arg0, 0, 3, 3, 0.0f, 0.0f);
    func_L39_0068B2F8(arg0, 4, 0);
    func_L39_0067F168();
    func_L39_0068ADC8(arg0);
    func_L39_006CC158(buf, 2);
}
/* localdecomp:end func_L39_006BBB38 */

/* localdecomp:start func_L39_006BBBE0 */
long func_L39_006BBBE0(void *arg0) {
    long r = 0;

    if (*(s32 *)((u8 *)arg0 + 0x2A8) != -1) {
        s32 t = *(s32 *)((u8 *)arg0 + 0x2F0) != 0;
        r = t;
    }
    return r;
}
/* localdecomp:end func_L39_006BBBE0 */

INCLUDE_ASM("asm/levels", func_L39_006BBC08);

INCLUDE_ASM("asm/levels", func_L39_006BBD80);

INCLUDE_ASM("asm/levels", func_L39_006BD290);

INCLUDE_ASM("asm/levels", func_L39_006BD408);

INCLUDE_ASM("asm/levels", func_L39_006BD788);

INCLUDE_ASM("asm/levels", func_L39_006BD988);

INCLUDE_ASM("asm/levels", func_L39_006BDAB8);

/* localdecomp:start func_L39_006BDCC8 */
__asm__(".extern D_L39_00247914, 16");
extern s32 *D_L39_00247914;
extern void func_L39_006BD408(s32);

/* from rac4-decomp's func_01EEFA5C */
s32 func_L39_006BDCC8(void) {
    func_L39_006BD408(D_L39_00247914[0xE0 / 4]);
    return 1;
}
/* localdecomp:end func_L39_006BDCC8 */

INCLUDE_ASM("asm/levels", func_L39_006BDCF0);

INCLUDE_ASM("asm/levels", func_L39_006BDE00);
