#include "common.h"

/* NTSC-U counterpart of func_L01_00469018 (src/levels/shared/L01_00465878.c): 0.012 -> 0.01; 0.976 -> 0.98 */
#include "vu0.h"
extern s32 func_003883C8(u8 *);
#include "vu0.h"
#include "vu0.h"
#include "vu0.h"
#include "vu0.h"
#include "vu0.h"
#include "vu0.h"
#include "vu0.h"
#include "vu0.h"
#include "vu0.h"
extern s32 func_003883C8(u8 *);
#include "structs/hero.h"
#include "vu0.h"
#include "vu0.h"

/* localdecomp:start func_L01_004659C0 */
#include "vu0.h"
void func_L01_004659C0(u8 *self) {
    extern s32 func_003883C8(u8 *);
    extern void func_003C7CE0(u8 *);
    extern void func_003886E8(void *, void *, f32);
    u8 *vars = self + 0x20;
    if (func_003883C8(self + 0xA)) goto destroy;
    *(f32 *)(self + 0xC) += *(f32 *)(vars + 0x10);
    self[8]++;
    *(f32 *)(vars + 0x14) -= 0.00999999978f;
    *(f32 *)(vars + 0x14) = *(f32 *)(vars + 0x14) < 0.0f ? 0.0f : *(f32 *)(vars + 0x14);
    *(u32 *)(self + 4) &= 0xFFFFFF;
    *(u32 *)(self + 4) |= (s32)(*(f32 *)(vars + 0x14) * 255.0f) << 24;
    if (*(f32 *)(vars + 0x14) <= 0.0f) {
destroy:
        func_003C7CE0(self);
    } else {
        vec_add_ab(self + 0x10, self + 0x10, self + 0x20);
        func_003886E8(vars, vars, 0.980000019f);
    }
}
/* localdecomp:end func_L01_004659C0 */
