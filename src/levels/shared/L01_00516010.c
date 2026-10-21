#include "common.h"

/* localdecomp:start func_L01_00516010 */
extern s32 func_L01_00516000_00516010(s32);
extern void func_003E6FF0(s32, s32);
s32 func_L01_00516010(s32 a0) {
    if (func_L01_00516000_00516010(a0) != 1) return 0;
    func_003E6FF0(a0, 2);
    return 1;
}
/* localdecomp:end func_L01_00516010 */

/* localdecomp:start func_L01_00516050 */
extern s32 func_L01_00516000_00516050(s32);
extern void func_003E6FF0(s32, s32);
s32 func_L01_00516050(s32 a0) {
    if (func_L01_00516000_00516050(a0) != 2) return 0;
    func_003E6FF0(a0, 1);
    return 1;
}
/* localdecomp:end func_L01_00516050 */

/* localdecomp:start func_L01_00516090 */
extern void func_003E6FF0_00516090(s32, s32);
extern void func_L01_00516090(void *p);
extern void func_L01_00516090(void *);

 
void func_L01_00516090(void *p) {
    ((void (*)(void *, s32))func_003E6FF0_00516090)(p, 0);
}
/* localdecomp:end func_L01_00516090 */
