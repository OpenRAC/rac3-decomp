#include "common.h"

/* localdecomp:start func_L04_0041AE18 */
typedef struct {
    f32 v[9][4];
} S418580;
extern void func_0038D000(void *a0, void *a1, void *a2);
extern void func_0038D5F0(void *a0, void *a1, void *a2);
extern void func_003D2DA0(void *a0, s32 a1, s32 a2);
void func_L04_0041AE18(S418580 *p, s32 n, void *m, s32 cnt, s32 arg4) {
    f32 tmp[12];
    s32 i;
    s32 j;
    s32 k;
    s32 l;

    for (i = 0; i < n; i++) {
        func_0038D000(p[i].v[2], p[i].v[2], m);
        func_0038D000(p[i].v[3], p[i].v[3], m);
    }
    func_0038D5F0(tmp, m, m);
    for (j = 0; j < cnt; j++) {
        if (j & 1) k = 2; else k = 0;
        for (l = 0; l < n; l++) {
            func_0038D000(p[l].v[k], p[l].v[k], tmp);
            func_0038D000(p[l].v[k + 1], p[l].v[k + 1], tmp);
            func_003D2DA0(&p[l], arg4, 1);
        }
    }
}
/* localdecomp:end func_L04_0041AE18 */
