#include "common.h"

typedef union { int q __attribute__((mode(TI))); float f[4]; } Vector;
typedef struct { int count; int pad[3]; Vector v[1]; } VList;

LINKER_REMNANT("asm/levels", func_L06_004591D0);

/* localdecomp:start func_L06_004591F8 */
extern float func_0038CF00(Vector *, Vector *);
extern float func_0038CF38(Vector *, Vector *);

int func_L06_004591F8(Vector *pos, VList *list, unsigned char flag)
{
    Vector p;
    Vector *pp = &p;
    float best = 9999999.0f;
    int found = -1;
    int i;
    float d;

    p.q = pos->q;
    if (list == 0)
        return -1;
    for (i = 0; i < list->count; i++) {
        if (flag)
            d = func_0038CF00(pp, &list->v[i]);
        else
            d = func_0038CF38(pp, &list->v[i]);
        if (d < best) {
            best = d;
            found = i;
        }
    }
    return found;
}
/* localdecomp:end func_L06_004591F8 */
