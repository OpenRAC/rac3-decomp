#include "common.h"

/* localdecomp:start func_L39_00672470 */
typedef struct {
    s16 a[26];
    f32 b[25];
    f32 c[25];
    f32 d[25];
    f32 e[25];
    f32 f[5];
} S_00672470;
extern S_00672470 D_1A6D90;
extern char D_00246430[];
extern char D_00246438[];
extern char D_00246440[];
extern char D_00246448[];
extern char D_00246450[];
extern char D_00246458[];
extern char D_00246460[];
extern char D_00246468[];
extern char D_00246470[];
extern char D_00246478[];
extern char D_00246480[];
extern char *func_120EE8(char *, char *);
extern s32 func_118F88(char *);
extern s32 func_120B70(char *, char *, s32);
extern s32 func_118F70(char *);
extern f32 func_131ED8(s32);
extern s32 func_1205B0(char *, char *);

s32 func_L39_00672470(char *key, char *val) {
    s32 ret = 0;
    char *p;
    u32 i;
    f32 v;

    p = func_120EE8(key, D_00246430);
    if (p != 0) {
        i = func_118F88(p + 1);
        if (i < 26) {
            if (func_120B70(key, D_00246438, 2) == 0) {
                ret = 1;
                D_1A6D90.a[i] = func_118F88(val);
            } else if (func_120B70(key, D_00246440, 3) == 0) {
                ret = 1;
                D_1A6D90.b[i] = func_131ED8(func_118F70(val));
            } else if (func_120B70(key, D_00246448, 3) == 0) {
                ret = 1;
                D_1A6D90.c[i] = func_131ED8(func_118F70(val));
            } else if (func_120B70(key, D_00246450, 3) == 0) {
                ret = 1;
                D_1A6D90.d[i] = func_131ED8(func_118F70(val));
            } else if (func_120B70(key, D_00246458, 3) == 0) {
                ret = 1;
                D_1A6D90.e[i] = func_131ED8(func_118F70(val));
            }
        }
    } else {
        v = func_131ED8(func_118F70(val));
        if (func_1205B0(key, D_00246460) == 0) {
            ret = 1;
            D_1A6D90.f[0] = v;
        } else if (func_1205B0(key, D_00246468) == 0) {
            ret = 1;
            D_1A6D90.f[1] = v;
        } else if (func_1205B0(key, D_00246470) == 0) {
            ret = 1;
            D_1A6D90.f[2] = v;
        } else if (func_1205B0(key, D_00246478) == 0) {
            ret = 1;
            D_1A6D90.f[3] = v;
        } else if (func_1205B0(key, D_00246480) == 0) {
            ret = 1;
            D_1A6D90.f[4] = v;
        }
    }
    return ret;
}
/* localdecomp:end func_L39_00672470 */
