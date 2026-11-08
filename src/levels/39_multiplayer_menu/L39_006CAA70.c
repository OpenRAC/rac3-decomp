#include "common.h"

/* localdecomp:start func_L39_006CAA70 */
typedef struct T3_006CAA70 T3_006CAA70;
typedef struct {
    char _p0[0x24];
    void (*f24)(T3_006CAA70 *arg0);
} T2_006CAA70;
struct T3_006CAA70 {
    char _p0[0x60];
    T2_006CAA70 *f60;
};
typedef struct {
    char _p0[0x110];
    T3_006CAA70 *f110;
} T1_006CAA70;

/* from rac4-decomp's func_L00_0071AB38 */
void func_L39_006CAA70(T1_006CAA70 *arg0) {
    T3_006CAA70 *o = arg0->f110;
    o->f60->f24(o);
}
/* localdecomp:end func_L39_006CAA70 */

/* localdecomp:start func_L39_006CAA98 */
typedef struct {
    char _p0[0x2a8];
    u32 f2a8[256];
    s32 f6a8;
    s32 f6ac;
    s32 f6b0;
} S_006CAA98;

/* from rac4-decomp's func_L00_00749408 */
void func_L39_006CAA98(S_006CAA98 *owner, const u32 *input, s32 count)
{
    s32 index;
    if (count > 256)
        count = 256;
    owner->f6b0 = 0;
    owner->f6a8 = count;
    owner->f6ac = 0;
    for (index = 0; index < owner->f6a8; index++) {
        owner->f2a8[index] = *input++;
    }
}
/* localdecomp:end func_L39_006CAA98 */

INCLUDE_ASM("asm/levels", func_L39_006CAAE8);

INCLUDE_ASM("asm/levels", func_L39_006CAC48);

INCLUDE_ASM("asm/levels", func_L39_006CAD88);

LINKER_REMNANT("asm/levels", func_L39_006CAEC0);

INCLUDE_ASM("asm/levels", func_L39_006CAEC8);

LINKER_REMNANT("asm/levels", func_L39_006CB078);

/* localdecomp:start func_L39_006CB080 */
extern u8 D_L39_0047EEC0[];
extern void func_L39_00688400(u8 *, s32);

/* from rac4-decomp's func_004EE7B0, renamed, constants adapted */
void func_L39_006CB080(void *object, s32 flags)
{
    *(void **)((u8 *)object + 96) = D_L39_0047EEC0;
    func_L39_00688400(object, flags);
}
/* localdecomp:end func_L39_006CB080 */

INCLUDE_ASM("asm/levels", func_L39_006CB0A8);

/* localdecomp:start func_L39_006CB230 */
extern void func_L39_0068ADC8(void *);
extern void func_L39_006CB230(void *);

extern void func_L39_0067F168();
void func_L39_006CB230(void *p) {
    func_L39_0067F168(p);
    func_L39_0068ADC8(p);
}
/* localdecomp:end func_L39_006CB230 */

INCLUDE_ASM("asm/levels", func_L39_006CB260);
