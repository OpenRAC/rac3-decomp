#include "common.h"

/* localdecomp:start func_L39_005A5C90 */
extern s32 D_001D4CE8_sda;
extern s32 D_001D4CEC_sda;
extern s32 D_001A43E8[];

void func_L39_005A5C90(void)
{
    s32 x;
    s32 v;

    v = D_001A43E8[0];
    if (2 != v) {
        D_001D4CE8_sda = 4;
        return;
    }
    x = D_001D4CEC_sda;
    if (x & 0x2020) {
        s32 y = x & ~0x20;
        *(s32 *)0x002403F8 = 14;
        *(s32 *)0x002403FC = y & ~0x2000;
    }
}
/* localdecomp:end func_L39_005A5C90 */

/* localdecomp:start func_L39_005A5CE8 */
extern s32 D_L39_002403FC;
extern s32 D_L39_002403F8;
__asm__(".extern D_L39_002403FC, 16");
__asm__(".extern D_L39_002403F8, 16");
extern s32 D_001A43E8[];
extern void func_0039C028(void);
void func_L39_005A5CE8(void) {
    s32 r;
    if (D_001A43E8[0] != 2) {
        r = 4;
    } else {
        s32 x = D_L39_002403FC;
        if (x & 0x20) {
            func_0039C028();
            r = 0x12;
        } else if (x & 0x2000) {
            r = 0x1D;
        } else {
            return;
        }
    }
    D_L39_002403F8 = r;
}
/* localdecomp:end func_L39_005A5CE8 */

/* localdecomp:start func_L39_005A5D48 */
typedef struct S_005A5D48 { s32 pad0[4]; s32 x10; s32 pad14[0x4D]; s32 x148; } S_005A5D48;
extern S_005A5D48 D_001A43E0;
extern s32 D_L39_002430A4;
extern s32 D_L39_002430A8;
extern s32 D_L39_002430AC;
extern s32 D_L39_002430B0;
extern s32 D_L39_002430B4;
extern s32 D_L39_002403FC_005A5D48;
extern u8 D_L39_0024BE70;
extern u8 D_L39_0024BE78;
extern s32 D_L39_002403FC;
__asm__(".extern D_L39_0024BE78, 16");
__asm__(".extern D_L39_002403FC, 16");
extern s32 func_0039BE48();
extern void func_0039C028(void);

s32 func_L39_005A5D48(s32 a, s32 b)
{
    s32 r = func_0039BE48(a);
    if (r != 0) {
        s32 f = D_L39_002403FC_005A5D48;
        f |= 0x10;
        f &= ~4;
        f &= ~2;
        D_L39_002430B4 = b;
        D_001A43E0.x148 = 0;
        D_L39_002403FC = f & ~0x40;
        D_001A43E0.x10 = 0;
        D_L39_002430A4 = 0;
        D_L39_002430A8 = 0;
        D_L39_002430AC = 0;
        D_L39_002430B0 = 0;
        D_L39_0024BE78 = 0;
        D_L39_0024BE70 = 0;
        func_0039C028();
    }
    return r;
}
/* localdecomp:end func_L39_005A5D48 */

/* localdecomp:start func_L39_005A5DE0 */
extern s32 D_L39_002430A4;
extern s32 D_L39_002430A8;
extern s32 D_L39_002430AC;
extern s32 D_L39_002430B0;
extern s32 D_L39_002430B4;
extern s32 D_L39_002430B8;
extern u8 D_L39_0024BE70;
extern u8 D_L39_0024BE78;
extern s32 D_L39_002403FC;
__asm__(".extern D_L39_0024BE78, 16");
__asm__(".extern D_L39_002403FC, 16");
extern void func_0039C028(void);

void func_L39_005A5DE0(s32 a, s32 b, s32 c)
{
    D_L39_002430A4 = a;
    D_L39_002430A8 = c;
    D_L39_002430B8 = b;
    D_001A43E0.x148 = 0;
    D_L39_002430AC = 0;
    D_L39_002430B0 = 0;
    D_L39_002430B4 = 0;
    D_L39_0024BE78 = 0;
    D_L39_0024BE70 = 0;
    func_0039C028();
    D_001A43E0.x10 = 0;
    {
        s32 f = D_L39_002403FC;
        f &= ~4;
        f |= 2;
        f &= ~0x40;
        f &= ~0x10;
        f &= ~0x4000;
        D_L39_002403FC = f;
    }
}
/* localdecomp:end func_L39_005A5DE0 */
