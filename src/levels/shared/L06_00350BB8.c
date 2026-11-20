#include "vu0.h"
#include "common.h"

/* declared by functions of L06_003506E0.c, which this file was cut from */
extern void func_L06_00350BB8(void *arg0, u8 *arg1);

/* localdecomp:start func_L06_00350BB8 */
typedef struct {
    f32 v[4];
} __attribute__((aligned(16))) Vec4;

typedef struct {
    Vec4 m[4];
} Mtx4;

extern void func_003C2EC0(void *, s32, Mtx4 *);
extern void func_0038D590(void *, Mtx4 *);
extern void func_003C48A8(void *, void *);
extern f32 func_0038DAB8(f32, f32);
extern void func_0038D308(void *, void *);

void func_L06_00350BB8(void *arg0, u8 *arg1) {
    Mtx4 m;

    func_003C2EC0(arg0, 0, &m);
    *(Vec4 *)(*(u8 **)(arg1 + 608) + 16) = m.m[3];
    func_0038D590(*(u8 **)(arg1 + 608) + 192, &m);
    func_003C48A8(*(u8 **)(arg1 + 608) + 192, *(u8 **)(arg1 + 608) + 240);
    if (*(f32 *)(arg1 + 880) != 0.0f) {
        *(f32 *)(*(u8 **)(arg1 + 608) + 248) = func_0038DAB8(*(f32 *)(*(u8 **)(arg1 + 608) + 248), *(f32 *)(arg1 + 880));
        func_0038D308(*(u8 **)(arg1 + 608) + 192, *(u8 **)(arg1 + 608) + 240);
    }
}
/* localdecomp:end func_L06_00350BB8 */
