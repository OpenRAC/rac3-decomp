#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L01_0043A800 */
extern void func_003CA4A0(void *, s32, void *, void *);
extern void func_0038CE20(void *, void *, f32);

void func_L01_0043A800(u8 *a0, s32 a1, void *a2) {
    f32 m[16];
    s32 id;
    f32 s = *(f32 *)(a0 + 44) * 0.0009765625f;
    id = a1;
    func_003CA4A0(a0, 1, &id, m);
    func_0038CE20(a2, &m[12], s);
}
/* localdecomp:end func_L01_0043A800 */

/* localdecomp:start func_L01_0043A860 */
extern void func_L01_0043FDD0(u8 *);
extern void func_0038D000(void *, void *, void *);

void func_L01_0043A860(u8 *a0, s32 n, s32 a2, u8 *p) {
    f32 s = *(f32 *)(a0 + 44) * 0.0009765625f;
    func_L01_0043FDD0(a0);
    if (n > 0) {
        do {
            n--;
            func_0038CE20(p, p, s);
            func_0038D000(p, p, a0 + 192);
            vec_add_ab(p, p, a0 + 16);
            p += 16;
        } while (n != 0);
    }
}
/* localdecomp:end func_L01_0043A860 */
