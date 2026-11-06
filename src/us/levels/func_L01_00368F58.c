#include "common.h"

/* localdecomp:start func_L01_00368F58 */
typedef struct {
    u8 reserved0[0x1C];
    s32 value1C;
} Inner_L01_00368F58;

typedef struct {
    u8 reserved0[0x68];
    Inner_L01_00368F58 *inner;
    u8 reserved6C[0x4C];
    s32 valueB8;
} Owner_L01_00368F58;

extern s32 func_0037E208(s32, s32);
extern void func_003886E8(void *, void *, f32);
extern void *func_L01_003DE3A8(void *, void *, s32);

void func_L01_00368F58(Owner_L01_00368F58 *owner, void *first, void *second) {
    Inner_L01_00368F58 *inner = owner->inner;
    Owner_L01_00368F58 *result;
    s32 value = func_0037E208(15, 45);
    inner->value1C = value;
    func_003886E8(second, second, 0.2f);
    result = func_L01_003DE3A8(first, second, 0);
    if (result != 0) {
        result->valueB8 = owner->valueB8;
    }
}
/* localdecomp:end func_L01_00368F58 */
