#include "common.h"
#include "vu0.h"

typedef int Quad_3543C8 __attribute__((mode(TI)));
typedef struct Obj_3543C8 {
    u8 pad0[0x10];
    Quad_3543C8 pos;
    u8 pad20[4];
    u8 *def;
    u8 pad28[0xC];
    u16 flags;
    u8 pad36[0x32];
    u8 *vars;
    u8 pad6C[0x2A];
    u16 timer;
    s32 w98;
    u8 pad9C[0xC];
    u8 alpha;
    u8 padA9[0x13];
    u8 state;
    u8 padBD[0x33];
    Quad_3543C8 pos2;
} Obj_3543C8;
typedef struct Vars_3543C8 {
    u8 pad0[0x30];
    f32 hp;
    s16 maxhp;
    s16 hurt;
    u8 pad38[0x48];
    s32 w80;
    u8 pad84[0x2FE];
    u8 b382;
    u8 pad383[0x7D];
    Quad_3543C8 q400;
    Quad_3543C8 q410;
} Vars_3543C8;

/* declared by functions of L18_00350FB0.c, which this file was cut from */
extern void func_L18_0041EFF8(void *, void *, f32);

/* localdecomp:start func_L18_00352BE0 */
typedef struct {
    f32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
} S_003537E8;

extern S_003537E8 D_L18_001E2B40[];
extern void func_L18_00402F60(s32, s32);
extern s32 func_L18_004B9918(s32, s32, void *);

void func_L18_00352BE0(void *obj) {
    ((s32 (*)(s32, s32))func_L18_00402F60)(18, 0);
    D_L18_001E2B40[2].f8 = 30;
    D_L18_001E2B40[3].f8 = 30;
    D_L18_001E2B40[2].f0 = 0.5f;
    D_L18_001E2B40[3].f0 = 0.2f;
    D_L18_001E2B40[4].f0 = 0.02f;
    D_L18_001E2B40[4].f8 = 30;
    D_L18_001E2B40[2].fC = 0;
    func_L18_004B9918(6, 0, obj);
}
/* localdecomp:end func_L18_00352BE0 */
