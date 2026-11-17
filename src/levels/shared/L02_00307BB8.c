#include "common.h"

/* localdecomp:start func_L02_00307BB8 */
#include "vu0.h"
extern float func_00382538(void);
extern float func_003824E0(float, float);
extern float func_0038D098(float);
extern float func_0038D0B0(float);
extern int func_00382498(int, int);
extern int func_00382468(int);
extern void *func_L01_00468A68(void *, void *, int, int);
extern void func_L01_00443B88(float *, float, float);
extern char *func_L01_0046ABC0(void *, void *, void *, float, float);
extern float D_L02_001DFA28;
extern char D_L02_001D66B0;

void func_L02_00307BB8(void *unused, void *position)
{
    float vector[4] __attribute__((aligned(16)));
    float angle, radius;
    int life, kind;
    char *effect;
    int i;
    float *data = &D_L02_001DFA28;
    for (i = 15; i >= 0; --i) {
        angle = func_00382538();
        radius = func_003824E0(0.0f, 0.060000002384185791016f);
        vector[0] = func_0038D098(angle) * radius;
        vector[1] = func_0038D0B0(angle) * radius;
        vector[2] = func_003824E0(0.060000002384185791016f, 0.13000001013278961182f);
        life = func_00382498(90, 120);
        kind = func_00382468(2);
        func_L01_00468A68(position, vector, kind, life);
    }
    for (i = 0; i < 16; ++i) {
        func_L01_00443B88(vector, 1.0f, 1.0f);
        vec_add_ab(vector, vector, position);
        vector[2] = D_L02_001DFA28 + 0.05f;
        effect = func_L01_0046ABC0(vector, &D_L02_001D66B0, data, func_003824E0(0.7f, 1.0f), i == 0 ? 2.0f : -2.0f);
        if (effect != 0)
            *(short *)(effect + 10) = (func_003824E0(30.0f, 60.0f) * 5.0f + 2.0f) / 6.0f;
    }
}
/* localdecomp:end func_L02_00307BB8 */
