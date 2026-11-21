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

/* localdecomp:start func_L01_004D2110 */
void func_L01_004D2110(void) {

}
/* localdecomp:end func_L01_004D2110 */

/* localdecomp:start func_L01_004D2118 */

extern f32 *func_L01_004CC748_004D2118(Obj_004CE458 *);
extern void func_L01_004CCE00(Obj_004CE458 *, s32, s32);
extern void func_L01_004CCE40(Obj_004CE458 *, s32, s32);
extern void func_L01_004CD640(Obj_004CE458 *, s32);

void func_L01_004D2118(Obj_004CE458 (*base)[26], s32 i, s32 j, s32 x, s32 y, s32 z) {
    Obj_004CE458 *o = &base[i][j];

    func_L01_004CC748_004D2118(o)[0] = x;
    func_L01_004CC748_004D2118(o)[1] = y;
    func_L01_004CCE00(o, z, z);
    func_L01_004CCE40(o, z, z);
    func_L01_004CD640(o, z << 24);
    o->vt->fn8(o);
}
/* localdecomp:end func_L01_004D2118 */
