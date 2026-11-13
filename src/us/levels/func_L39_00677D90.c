#include "common.h"

/* localdecomp:start func_L39_00677D90 */
typedef struct {
    u8 pad0[0x10];
    s32 **f10;
} Obj_L39_00677D90;

extern u8 D_001A5FF2[];
extern s32 func_L01_0041D288(s32);
extern Obj_L39_00677D90 *func_L01_00410190(void *);
extern s32 func_L01_004101E0(s32);
extern void func_001206F4(void *, s32);
extern void func_L01_00410078(s32);
extern void func_001260A0(void);

void func_L39_00677D90(void) {
    Obj_L39_00677D90 *o;

    func_L01_0041D288(0);
    o = func_L01_00410190(D_001A5FF2);
    if (o != 0) {
        func_001206F4(D_001A5FF2 - 0x20, func_L01_004101E0(**o->f10));
    }
    o = func_L01_00410190(D_001A5FF2 + 0x60);
    if (o != 0) {
        func_001206F4(D_001A5FF2 + 0x40, func_L01_004101E0(**o->f10));
    }
    func_L01_00410078(0);
    func_001260A0();
}
/* localdecomp:end func_L39_00677D90 */
