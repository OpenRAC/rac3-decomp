#include "common.h"

/* NTSC-U counterpart of func_003E38F8 (frontbin). */
#include "vu0.h"
extern void func_U_003DE3A8(f32 *);

/* localdecomp:start func_U_003DE3A8 */
/* US draft of func_U_003DE3A8 (rac3-uya-decomp func_003E3B68, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: differs: did not build, or built to other bytes, in PAL. */


extern void func_U_003DE3A8(f32 *);
__asm__(".extern D_U_001D950C_003DE3A8, 4");
extern f32 D_U_001D950C_003DE3A8;
extern f32 D_U_002224A0_003DE3A8[];
extern void func_U_003BF778_003DE3A8();
extern void func_U_003890D8_003DE3A8();
extern void func_U_00388EB8_003DE3A8();
void func_U_003DE3A8(f32 *arg0) {
    f32 a[4];
    f32 b[12];
    ((void (*)(f32 *, f32 *, f32))func_U_003BF778_003DE3A8)(a, D_U_002224A0_003DE3A8, *arg0 * (D_U_001D950C_003DE3A8 * 0.017453292f * 0.01666666753590107f));
    func_U_003890D8_003DE3A8(a, b);
    func_U_00388EB8_003DE3A8(D_U_002224A0_003DE3A8, b, D_U_002224A0_003DE3A8);
}
/* localdecomp:end func_U_003DE3A8 */
