#include "common.h"

/* localdecomp:start func_L39_004C24C8 */
extern void *func_L39_004BEED8(s32);
extern void func_0011D534(void *, s32, s32);
extern s32 func_L39_004DE940(void);
extern void func_L39_004BC6C8(s32, s32, s32, s32, s32);

typedef struct S_004C24C8 S_004C24C8;
typedef struct {
    s32 f0;
    s32 f4;
    void (*f8)(S_004C24C8 *);
} V_004C24C8;
struct S_004C24C8 {
    u8 pad0[8];
    V_004C24C8 *vt;
    u8 padC[0x48];
    u8 *f54;
};

s32 func_L39_004C24C8(S_004C24C8 *arg0) {
    u8 *p = func_L39_004BEED8(0x198);

    if (p == 0 || (func_0011D534(p, 0, 0x198), (*(s32 *)(p + 0xF8) = func_L39_004DE940()) == 0)) {
        func_L39_004BC6C8(0x14, 0x93, 0x21, 0, 0);
        return 0;
    }
    do {
        if ((*(s32 *)(p + 0xFC) = func_L39_004DE940()) != 0) {
            arg0->f54 = p;
            arg0->vt->f8(arg0);
            return 1;
        }
        func_L39_004BC6C8(0x14, 0x93, 0x21, 0, 0);
        return 0;
    } while (0);
}
/* localdecomp:end func_L39_004C24C8 */
