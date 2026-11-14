#include "common.h"

/* localdecomp:start func_L39_00516008 */
typedef struct R_00516008 { char pad[8]; s32 f8; s32 fC; s32 f10; } R_00516008;
typedef struct D_00516008 { s32 f0; s32 pad; s32 f8; s32 fC; s32 f10; } D_00516008;
typedef struct O_00516008 { char pad[0xD8]; D_00516008 *fD8; } O_00516008;
extern s32 func_L39_004E4AE8(s32, s32, s32, s32, R_00516008 **, s32);
extern void func_L39_005177C0(void *, s32, s32, u8 *, s32, s32, s32);
extern s32 func_L39_004E48A8(s32, s32, s32, s32, s32, s32, s32);
s32 func_L39_00516008(O_00516008 *o, s32 x, s64 *out, s64 code, s64 a, s64 b) {
    R_00516008 *r;

    if (code < 0x20) {
        if (func_L39_004E4AE8(x, a, b, 0, &r, 0)) return 1;
        func_L39_005177C0(o->fD8, 0, code, (u8 *)r->fC, r->f10, 0, 0);
    } else if (code == 0x41) {
        if (func_L39_004E4AE8(x, a, b, 0, &r, 0)) return 1;
        func_L39_005177C0(o->fD8, 0, r->f8, (u8 *)r->fC, r->f10, 0, 0);
    } else if (code == 0x44) {
        if (func_L39_004E4AE8(x, a, b, 0, &r, 0)) return 1;
        *out = r->f10;
    } else if (code == 0x42) {
        func_L39_004E48A8(x, a, b, o->fD8->f10, o->fD8->f8, o->fD8->f0, 0x10);
    } else if (code == 0x43) {
        func_L39_004E48A8(x, a, b, 2, 0, *out, 0x10);
    } else if (code == 0x40) {
        func_L39_004E4AE8(x, a, b, 0, &r, 0);
        *out = r != 0;
        return 0;
    } else {
        return 2;
    }
    return 0;
}
/* localdecomp:end func_L39_00516008 */

/* localdecomp:start func_L39_005161F8 */
extern void *func_L39_00516620(void);
extern void func_L39_00516498(s32 *, s32);

void func_L39_005161F8(void *arg0)
{
    func_L39_00516498(arg0, (s32)func_L39_00516620());
}
/* localdecomp:end func_L39_005161F8 */
