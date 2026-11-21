#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L19_003556B0 */
s32 func_L19_003556B0(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 104);
    if (a0[32] == 2) {
        return *(s32 *)(p + 16);
    }
    return 0;
}
/* localdecomp:end func_L19_003556B0 */

/* localdecomp:start func_L19_003556D0 */
extern void func_0038CF68(void *, void *, f32);

void func_L19_003556D0(u8 *self, u8 *out) {
    func_0038CF68(out, self + 0xC0, 1.0f);
    vec_add_ba(out, out, self + 0x10);
}
/* localdecomp:end func_L19_003556D0 */

/* localdecomp:start func_L19_00355720 */
typedef struct {
    char pad0[0x10];
    int count;
    char pad14[0x1C - 0x14];
    int arg;
} Vars;

typedef struct {
    char pad0[0x68];
    Vars *vars;
} Obj;

extern void func_003A52A0(int, int, Obj *);
extern void func_L01_004450F0(Obj *, int, int);

void func_L19_00355720(Obj *obj, int arg) {
    Vars *v = obj->vars;
    int n;

    v->arg = arg;
    n = v->count - 1;
    v->count = n;
    if (n == 2) {
        func_003A52A0(0, 0, obj);
    } else if (n == 1) {
        func_003A52A0(1, 0, obj);
    } else if (n == 0) {
        func_003A52A0(2, 0, obj);
        func_L01_004450F0(obj, 3, -1);
    }
}
/* localdecomp:end func_L19_00355720 */
