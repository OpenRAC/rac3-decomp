#include "common.h"

/* localdecomp:start func_L39_006B2CE0 */
__asm__(".extern D_L39_0024D760_006B2CE0, 16");
extern u8 *D_L39_0024D760_006B2CE0;
extern s32 func_L39_006DE180(s32);
extern s32 func_L01_003A4720(s32);

void func_L39_006B2CE0(void) {
    func_L39_006DE180(*(s32 *)(D_L39_0024D760_006B2CE0 + 0x54));
    func_L01_003A4720(*(s32 *)(D_L39_0024D760_006B2CE0 + 0x30));
}
/* localdecomp:end func_L39_006B2CE0 */

/* localdecomp:start func_L39_006B2D18 */
typedef struct {
    char pad0[0x50];
    s32 f50;
} S_6B2D18;

__asm__(".extern D_L39_0024D760, 16");
extern S_6B2D18 *D_L39_0024D760;
extern void func_L39_006DCAD0(s32, s32);

/* from rac4-decomp's func_L00_00708980 */
void func_L39_006B2D18(void) {
    func_L39_006DCAD0(D_L39_0024D760->f50, 0);
}
/* localdecomp:end func_L39_006B2D18 */

LINKER_REMNANT("asm/levels", func_L39_006B2D40);

INCLUDE_ASM("asm/levels", func_L39_006B2D50);

LINKER_REMNANT("asm/levels", func_L39_006B2FC0);

/* localdecomp:start func_L39_006B2FC8 */
extern u8 D_L39_0047E310[];
extern void func_L39_00688400(u8 *, s32);

/* from rac4-decomp's func_004EE7B0, renamed, constants adapted */
void func_L39_006B2FC8(void *object, s32 flags)
{
    *(void **)((u8 *)object + 96) = D_L39_0047E310;
    func_L39_00688400(object, flags);
}
/* localdecomp:end func_L39_006B2FC8 */
