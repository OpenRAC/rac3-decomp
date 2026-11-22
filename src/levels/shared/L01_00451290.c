#include "common.h"

/* localdecomp:start func_L01_00451290 */
extern void func_003C5180(void *);
 
void func_L01_00451290(void *p) {
    func_003C5180((u8 *)p + 0x10);
}
/* localdecomp:end func_L01_00451290 */

/* localdecomp:start func_L01_004512B0 */
#include "vu0.h"
extern s32 D_L01_001D673C_004512B0;
__asm__(".extern D_L01_001D673C_004512B0, 16");
extern void func_003C5180_004512B0(void *, void *, s32);

void func_L01_004512B0(void *a, void *b) {
    vu0_q q;

    if (D_L01_001D673C_004512B0 == 0) {
        __asm__("vmr32.xyzw %0, $vf0" : "=j"(q));
        __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)b) : "j"(q));
    } else {
        func_003C5180_004512B0(a, b, 1);
    }
}
/* localdecomp:end func_L01_004512B0 */

/* localdecomp:start func_L01_004512E8 */
extern void func_L01_004512B0_004512E8(void *);
 
void func_L01_004512E8(void *p) {
    func_L01_004512B0_004512E8((u8 *)p + 0x10);
}
/* localdecomp:end func_L01_004512E8 */
