#include "common.h"

/* localdecomp:start func_L39_0067EAD0 */
typedef struct Obj_67EAD0 Obj_67EAD0;
typedef struct {
    u8 pad0[0x30];
    void (*fn)(Obj_67EAD0 *, f32 *, f32 *);
} VT_67EAD0;
struct Obj_67EAD0 {
    u8 pad0[4];
    s32 w4;
    u8 pad8[0x50];
    f32 f58;
    f32 f5C;
    VT_67EAD0 *vt;
    s32 h[2];
    u8 b6C;
    u8 pad6D[3];
    s32 w70;
    s32 w74;
    u8 b78;
    u8 pad79[7];
    s32 w80;
};

extern s32 *func_003AED40(s32);
extern void func_L01_005130C8(s32, s32);
extern void func_L01_00512AB0(s32, s32, s32);
extern void func_L01_00512480(s32, f32, f32);
extern void func_L01_00513548(s32, f32, f32);

void func_L39_0067EAD0(Obj_67EAD0 *obj) {
    f32 x;
    f32 y;
    if (obj->h[0] == -1) {
        return;
    }
    if (obj->b78 != 0 && obj->b6C != 0 && (func_003AED40(obj->w74)[0] ^ 2) == 0) {
        func_L01_005130C8(obj->h[obj->w74], obj->w80);
        func_L01_005130C8(obj->h[(obj->w74 + 1) % 2], 0);
        obj->b78 = 0;
    }
    if (obj->w4 == 0) {
        func_L01_00512AB0(obj->h[0], 1, 0);
        func_L01_00512AB0(obj->h[1], 1, 0);
        return;
    }
    func_L01_00512AB0(obj->h[0], 1, 1);
    func_L01_00512AB0(obj->h[1], 1, 1);
    obj->vt->fn(obj, &x, &y);
    func_L01_00512480(obj->h[0], x, y);
    func_L01_00512480(obj->h[1], x, y);
    func_L01_00513548(obj->h[0], obj->f58, obj->f5C);
    func_L01_00513548(obj->h[1], obj->f58, obj->f5C);
}
/* localdecomp:end func_L39_0067EAD0 */
