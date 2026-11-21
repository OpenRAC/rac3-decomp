#include "common.h"

/* localdecomp:start func_L35_003A5780 */
typedef int u128_003A5780 __attribute__((mode(TI)));
extern u8 *func_003C24B0(s32, s32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 D_L35_001DEA74;
extern f32 D_L35_001DEA84;
extern f32 D_L35_001DEA98_003A5780;
extern const s32 D_L35_001DEA9C;
__asm__(".extern D_L35_001DEA74, 4");
__asm__(".extern D_L35_001DEA84, 4");
__asm__(".extern D_L35_001DEA98_003A5780, 4");
__asm__(".extern D_L35_001DEA9C, 4");

u8 *func_L35_003A5780(void *pos, f32 ang) {
    u8 *m = func_003C24B0(0x19FB, 0x80);
    u8 *v;

    if (m == 0) {
        return 0;
    }
    m[0x30] = 0xFF;
    *(s16 *)(m + 0x32) = 0x40;
    v = *(u8 **)(m + 0x68);
    *(f32 *)(m + 0x2C) = D_L35_001DEA84 * *(f32 *)(*(u8 **)(m + 0x24) + 0x24);
    *(u128_003A5780 *)(m + 0x10) = *(u128_003A5780 *)pos;
    *(f32 *)(v + 0x20) = ang;
    *(f32 *)(v + 0x10) = func_0038D098(ang) * D_L35_001DEA98_003A5780;
    *(f32 *)(v + 0x18) = func_0038D0B0(*(f32 *)(v + 0x20)) * D_L35_001DEA98_003A5780;
    *(s32 *)(v + 0x14) = 0;
    *(f32 *)(v + 0x00) = func_0038D098(*(f32 *)(v + 0x20)) * D_L35_001DEA74;
    *(f32 *)(v + 0x08) = func_0038D0B0(*(f32 *)(v + 0x20)) * D_L35_001DEA74;
    *(s32 *)(v + 0x28) = -1;
    *(s32 *)(v + 0x24) = D_L35_001DEA9C;
    *(s32 *)(v + 0x04) = 0;
    return m;
}
/* localdecomp:end func_L35_003A5780 */

/* localdecomp:start func_L35_003A5878 */
void func_L35_003A5878(void *arg0, f32 fparg0, f32 fparg1) {
    f32 temp_f0;
    s32 var_a1;
    void *temp_a0;
    void *var_v1;

    if (arg0 != 0) {
        temp_a0 = *(void **)((u8 *)arg0 + 0x68);
        var_v1 = temp_a0 + 0x60;
        if (temp_a0 != 0) {
            var_a1 = 0;
            if ((*(s32 *)((u8 *)temp_a0 + 0x20)) > 0) {
                do {
                    if ((*(s32 *)((u8 *)var_v1 + 0x14)) != -1) {
                        temp_f0 = (*(f32 *)((u8 *)var_v1 + 8)) + fparg0;
                        *(f32 *)((u8 *)var_v1 + 8) = temp_f0;
                        if (fparg1 < temp_f0) {
                            *(f32 *)((u8 *)var_v1 + 8) = fparg1;
                        }
                    }
                    var_a1 += 1;
                    var_v1 += 0x20;
                } while (var_a1 < (*(s32 *)((u8 *)temp_a0 + 0x20)));
            }
        }
    }
}
/* localdecomp:end func_L35_003A5878 */

/* localdecomp:start func_L35_003A58E8 */
void func_L35_003A5978(void *);
void func_L35_003A5E20(void *);
void func_L35_003A5F00(void *);
void func_L35_003A60F0(void *);
void func_L35_003A6240(void *);

void func_L35_003A58E8(void *arg0) {
    u8 temp_v1;

    temp_v1 = *(u8 *)((u8 *)arg0 + 0x20);
    switch (temp_v1) {                              /* irregular */
    case 0:
        func_L35_003A5F00(arg0);
        break;
    case 1:
        func_L35_003A6240(arg0);
        break;
    case 2:
        func_L35_003A60F0(arg0);
        break;
    }
    func_L35_003A5978(arg0);
    func_L35_003A5E20(arg0);
}
/* localdecomp:end func_L35_003A58E8 */
