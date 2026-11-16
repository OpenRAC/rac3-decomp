#include "common.h"

/* NTSC-U counterpart of func_L02_00307BB8 (src/levels/shared/L02_00307BB8.c) */
/* localdecomp:start func_L02_00307918 */
#include "vu0.h"
extern float func_0037E2A8(void);
extern float func_0037E250(float, float);
extern float func_00388960(float);
extern float func_00388978(float);
extern int func_0037E208(int, int);
extern int func_0037E1D8(int);
extern void *func_L01_00465410(void *, void *, int, int);
extern void func_L01_00440A88(float *, float, float);
extern char *func_L01_00467510(void *, void *, void *, float, float);
extern float D_L02_001DFAA8;
extern char D_L02_001D66B0_00307918;

void func_L02_00307918(void *unused, void *position)
{
    float vector[4] __attribute__((aligned(16)));
    float angle, radius;
    int life, kind;
    char *effect;
    int i;
    float *data = &D_L02_001DFAA8;
    for (i = 15; i >= 0; --i) {
        angle = func_0037E2A8();
        radius = func_0037E250(0.0f, 0.050000004470348358154f);
        vector[0] = func_00388960(angle) * radius;
        vector[1] = func_00388978(angle) * radius;
        vector[2] = func_0037E250(0.050000004470348358154f, 0.10833334177732467651f);
        life = func_0037E208(90, 120);
        kind = func_0037E1D8(2);
        func_L01_00465410(position, vector, kind, life);
    }
    for (i = 0; i < 16; ++i) {
        func_L01_00440A88(vector, 1.0f, 1.0f);
        vec_add_ab(vector, vector, position);
        vector[2] = D_L02_001DFAA8 + 0.05f;
        effect = func_L01_00467510(vector, &D_L02_001D66B0_00307918, data, func_0037E250(0.7f, 1.0f), i == 0 ? 2.0f : -2.0f);
        if (effect != 0)
            *(short *)(effect + 10) = func_0037E250(30.0f, 60.0f);
    }
}
/* localdecomp:end func_L02_00307918 */
