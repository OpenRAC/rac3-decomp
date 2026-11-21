#include "common.h"

typedef struct Obj_004CE458 Obj_004CE458;
typedef struct {
    u8 pad[8];
    void (*fn8)(Obj_004CE458 *);
} Vt_004CE458;
struct Obj_004CE458 {
    u8 pad[36];
    Vt_004CE458 *vt;
    u8 pad2[20];
};

/* localdecomp:start func_L01_004D25D0 */
s32 func_L01_004D25D0(s32 a, s32 b, s32 c) {
    return a + b * 1560;
}
/* localdecomp:end func_L01_004D25D0 */
