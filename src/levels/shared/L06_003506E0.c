#include "vu0.h"
#include "common.h"

/* localdecomp:start func_L06_003506E0 */
extern void func_L06_00350BB8(void *arg0, u8 *arg1);
typedef struct {
    u8 pad0[32];
    u8 state;
    u8 pad1[52 - 33];
    u16 flags;
    u8 pad2[104 - 54];
    void *vars;
} Moby_0034F9E8;
extern u8 D_L06_001DD340[];
extern void func_L06_00350788(Moby_0034F9E8 *, void *);
extern s32 func_L06_00351C48(Moby_0034F9E8 *, void *);
extern s32 func_L04_004C1158(Moby_0034F9E8 *, void *);
extern void func_L06_003528B8(Moby_0034F9E8 *, void *);
extern void func_L06_00352AA0(Moby_0034F9E8 *, void *);
extern void func_L06_00354D48(Moby_0034F9E8 *, void *);
void func_L06_003506E0(Moby_0034F9E8 *m) {
    void *v;
    if (m->flags & 2) return;
    v = m->vars;
    if (m->state == 0) func_L06_00350788(m, v);
    if (func_L06_00351C48(m, v) == 0) return;
    if (func_L04_004C1158(m, D_L06_001DD340)) {
        ((void (*)(Moby_0034F9E8 *, void *))func_L06_00350BB8)(m, v);
        func_L06_003528B8(m, v);
        func_L06_00352AA0(m, v);
        func_L06_00354D48(m, v);
    }
}
/* localdecomp:end func_L06_003506E0 */
