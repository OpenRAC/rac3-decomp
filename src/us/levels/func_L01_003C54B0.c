#include "common.h"

/* NTSC-U counterpart of func_L01_003C6D30 (src/levels/shared/L01_003C64E0.c): 0.02 -> 0.0166667 */
#include "vu0.h"
extern f32 func_00389380(f32, f32);
#include "vu0.h"

/* localdecomp:start func_L01_003C54B0 */
extern f32 D_L01_001DEC94;
__asm__(".extern D_L01_001DEC94, 4");
extern f32 D_L01_001DEC98;
__asm__(".extern D_L01_001DEC98, 4");
extern f32 D_L01_001DEC9C;
__asm__(".extern D_L01_001DEC9C, 4");
extern f32 D_L01_001DECA0;
__asm__(".extern D_L01_001DECA0, 4");
extern f32 D_L01_001DECA4;
__asm__(".extern D_L01_001DECA4, 4");
extern f32 D_L01_001DECA8;
__asm__(".extern D_L01_001DECA8, 4");
extern f32 D_L01_001DECAC;
__asm__(".extern D_L01_001DECAC, 4");
extern f32 func_00388978(f32);
extern f32 func_00388960(f32);

typedef struct {
    u8 pad0[0xB4];
    f32 xB4;
    f32 xB8;
    f32 xBC;
} S_003C6D30;

void func_L01_003C54B0(void *m, S_003C6D30 *obj, f32 *p1, f32 *p2, f32 *p3) {
    obj->xB4 = func_00389380(obj->xB4, D_L01_001DEC98 * 0.017453292f * 0.0166666675f);
    *p1 = func_00388978(obj->xB4) * D_L01_001DEC94;
    *p2 = D_L01_001DECA4 * func_00388978(obj->xB8) * func_00388978(obj->xBC) * 1.5f;
    *p3 = D_L01_001DECA4 * func_00388978(obj->xB8) * func_00388960(obj->xBC);
    obj->xB8 = func_00389380(obj->xB8, D_L01_001DECA8 * 0.017453292f * 0.0166666675f);
    obj->xBC = func_00389380(obj->xBC, D_L01_001DECAC * 0.017453292f * 0.0166666675f);
    *p3 += func_00388978(obj->xB4 + D_L01_001DEC9C) * D_L01_001DECA0;
}
/* localdecomp:end func_L01_003C54B0 */
