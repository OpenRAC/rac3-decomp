#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_006C99F0);

INCLUDE_ASM("asm/levels", func_L39_006C9BF0);

INCLUDE_ASM("asm/levels", func_L39_006C9C48);

INCLUDE_ASM("asm/levels", func_L39_006C9E50);

INCLUDE_ASM("asm/levels", func_L39_006CA060);

/* localdecomp:start func_L39_006CA268 */
/* pattern from L39_0068DDC8.c: scalar pointer with .extern size hint */
__asm__(".extern D_L39_0024D760, 16");
extern s32 *D_L39_0024D760;
extern void func_L39_006D0078(void *);

s32 func_L39_006CA268(u8 *arg0)
{
    func_L39_006D0078((void *)D_L39_0024D760[0x38 / 4]);
    arg0[0x2A8] = 1;
    return 1;
}
/* localdecomp:end func_L39_006CA268 */

LINKER_REMNANT("asm/levels", func_L39_006CA2A8);

INCLUDE_ASM("asm/levels", func_L39_006CA2C0);

LINKER_REMNANT("asm/levels", func_L39_006CA6C0);

/* localdecomp:start func_L39_006CA6C8 */
extern u8 D_L39_0047EDC0[];
extern void func_L39_00688400(u8 *, s32);

/* from rac4-decomp's func_004EE7B0, renamed, constants adapted */
void func_L39_006CA6C8(void *object, s32 flags)
{
    *(void **)((u8 *)object + 96) = D_L39_0047EDC0;
    func_L39_00688400(object, flags);
}
/* localdecomp:end func_L39_006CA6C8 */

/* localdecomp:start func_L39_006CA6F0 */
/* Same shape as func_L39_0069E768 (task 4); constants from the $gp slots 0x196C..0x197C. */
extern f32 D_001DE21C_sda;
extern f32 D_001DE220_sda;
extern f32 D_001DE224_sda;
extern f32 D_001DE228_sda;
extern f32 D_001DE22C_sda;
extern void func_L39_00688460(void *a0, f32 f1, f32 f2, f32 f3, f32 f4, f32 f5, void *p1, void *p2, void *p3, void *p4, void *p5);

void func_L39_006CA6F0(void *a0)
{
    s32 v[4];
    func_L39_00688460(a0, D_001DE21C_sda, D_001DE220_sda, D_001DE224_sda, D_001DE228_sda, D_001DE22C_sda, v, v, v, v, v);
}
/* localdecomp:end func_L39_006CA6F0 */

INCLUDE_ASM("asm/levels", func_L39_006CA730);

/* localdecomp:start func_L39_006CA8C8 */
extern void func_L39_0068ADC8(void *);
extern void func_L39_006CA8C8(void *);

extern void func_L39_0067F168();
void func_L39_006CA8C8(void *p) {
    func_L39_0067F168(p);
    func_L39_0068ADC8(p);
}
/* localdecomp:end func_L39_006CA8C8 */

INCLUDE_ASM("asm/levels", func_L39_006CA8F8);
