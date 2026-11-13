#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L36_00348BB8 */
extern void func_0038D328(void *, void *);
extern void func_0038D028(void *, void *, void *);
extern void func_0038D640(void *, void *, void *);
extern void func_003C48A8(void *, void *);
extern void func_0038D308(void *, void *);
void func_L36_00348BB8(u8 *a0, f32 *a1, f32 x, f32 y, f32 z) {
    vu0_v4 m0[4];
    vu0_v4 m1[4];
    vu0_v4 m2[4];
    vu0_v4 v0, v1, v2, v3;
    func_0038D328(m0, a0 + 0xF0);
    vec_sub_ba(&v0, a1, a0 + 0x10);
    v1.x = x;
    v1.y = y;
    v1.z = z;
    func_0038D328(m1, &v1);
    func_0038D028(&v2, &v0, m1);
    vec_sub_ba(&v3, &v2, &v0);
    vec_add_ba(a0 + 0x10, a0 + 0x10, &v3);
    func_0038D640(m2, m0, m1);
    func_003C48A8(m2, a0 + 0xF0);
    func_0038D308(a0 + 0xC0, a0 + 0xF0);
}
/* localdecomp:end func_L36_00348BB8 */

LINKER_REMNANT("asm/levels", func_L36_00348CB8);
