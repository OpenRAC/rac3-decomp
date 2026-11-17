#include "common.h"

/* localdecomp:start func_L39_0060A880 */
typedef struct {
    s32 f0;
    u8 *f4;
    s32 f8;
    s32 fC;
    s32 f10;
} G_0060A880;

typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
} A_0060A880;

extern G_0060A880 *D_L39_0024CBE0;
extern G_0060A880 *D_L39_0024CBE0_0060A880;
__asm__(".extern D_L39_0024CBE0_0060A880, 4");
extern u8 D_L39_002457C0[];
extern u8 D_L39_002457D8[];
extern s32 func_00143360(void *);
extern s32 func_003B2630(void *);
extern s32 func_003B2CF0(void *);
extern s32 func_00143290(void *, s32, s32);
extern void func_L39_00607DD8(void);
extern void func_L01_004BF5A8_0060A880(u8 *);
extern void func_L39_00608C08(void *, int, int, int, int);
extern void func_L39_0060ACD0(void *);
extern void func_001432E0(void *);
extern void func_0011E718(void *, s32);

s32 func_L39_0060A880(A_0060A880 *a0) {
    s32 result = 1;
    s32 r;
    s32 i;

    while (func_00143360(a0) == 0) {
        if (func_003B2630(a0) == 1) {
            result = -1;
            ((void (*)(void *))func_0011E718)(D_L39_002457C0);
            break;
        }
        while ((r = func_003B2CF0(D_L39_0024CBE0_0060A880)) == 0) {
            func_L39_00607DD8();
        }
        if (func_00143290(a0, r, 0x340) < 0) {
            func_L01_004BF5A8_0060A880(D_L39_002457D8);
        }
        if (a0->f8 == 0) {
            s32 x = a0->f0;
            s32 y = a0->f4;
            for (i = 0; i < D_L39_0024CBE0->f10; i++) {
                func_L39_00608C08(D_L39_0024CBE0->f4 + i * 0x27E40 + 0x40, D_L39_0024CBE0->f0 + i * 0xD0000, 0, x, y);
                func_L39_00608C08(D_L39_0024CBE0->f4 + i * 0x27E40 + 0x13F40, D_L39_0024CBE0->f0 + i * 0xD0000, 1, x, y);
            }
        }
        func_L39_0060ACD0(D_L39_0024CBE0);
        func_L39_00607DD8();
    }
    func_001432E0(a0);
    return result;
}
/* localdecomp:end func_L39_0060A880 */
