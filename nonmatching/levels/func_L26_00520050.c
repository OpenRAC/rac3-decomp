/* near miss (level 26, Kerwan: 1 diff, the jr delay slot) */
#include "common.h"

/* localdecomp:start func_L26_00520050 */
typedef struct S_00520050 S_00520050;
typedef struct {
    char _p0[0xC];
    s32 (*fC)(S_00520050 *);
    s32 (*f10)(S_00520050 *, s32);
} V_00520050;
struct S_00520050 {
    char _p0[8];
    V_00520050 *f8;
};

extern s32 D_L26_001E13E0[];
extern s32 D_L26_001DBF78;
extern char D_L26_0026D970[];
extern void *func_003E6C08(void);
extern void *func_003E6DE8(void *);
extern S_00520050 *func_003E6378(void *, S_00520050 *);
extern s32 (*func_L01_00519B90(char *, s32))(S_00520050 *, s32);

s32 func_L26_00520050(S_00520050 *p, s32 a1) {
    void *v;
    s32 name;
    s32 r;
    s32 (*fn)(S_00520050 *, s32);

    r = 0;
    if (D_L26_001E13E0[1] != 0) {
        v = D_L26_001E13E0;
    } else {
        v = func_003E6C08();
    }
    p = func_003E6378(func_003E6DE8(v), p);
    if (p == 0 || p->f8->f10(p, D_L26_001DBF78) == 0) {
        p = 0;
    }
    if (p != 0) {
        name = p->f8->fC(p);
        fn = func_L01_00519B90(D_L26_0026D970, name);
        if (fn != 0) {
            r = fn(p, a1);
        }
    }
    return r;
}
/* localdecomp:end func_L26_00520050 */
