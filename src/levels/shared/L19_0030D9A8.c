#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L19_0030D9A8 */
extern void func_L19_0030D928(u8 *, void *, void *);
extern s32 func_L19_00356008(u32, void *, void *);
extern s32 func_L19_00356088(u32, void *);
extern f32 func_0038CF38(void *, void *);
extern f32 func_003C3D30(void *, s32, s32, f32);
extern char D_001A4C60[];

void func_L19_0030D9A8(u8 *object, void *unused, f32 *output) {
    u128_t first;
    u128_t second;
    u8 *vars = *(u8 **)(object + 0x68);
    s32 region;
    f32 distance;
    func_L19_0030D928(object, &first, &second);
    if (func_L19_00356008(*(u32 *)(vars + 0x74), &first, D_001A4C60) != 0) {
        *(u128_t *)output = first;
    } else if (func_L19_00356008(*(u32 *)(vars + 0x74), &second, D_001A4C60) != 0) {
        *(u128_t *)output = second;
    } else {
        region = func_L19_00356088(*(u32 *)(vars + 0x74), &first);
        if (region != -1) {
            *(u128_t *)output = first;
        } else if (func_L19_00356088(*(u32 *)(vars + 0x74), &second) != region) {
            *(u128_t *)output = second;
        } else {
            distance = func_0038CF38(D_001A4C60, &first);
            if (distance < func_0038CF38(D_001A4C60, &second))
                *(u128_t *)output = first;
            else
                *(u128_t *)output = second;
        }
    }
    output[2] += 0.5f;
    output[2] = func_003C3D30(output, 0, 0, 0.5f);
}
/* localdecomp:end func_L19_0030D9A8 */
