#include "common.h"

/* NTSC-U counterpart of func_L39_00672470 (src/levels/39_multiplayer_menu/L39_00672470.c) */
/* localdecomp:start func_L39_0066FB20 */
typedef struct {
    s16 a[26];
    f32 b[25];
    f32 c[25];
    f32 d[25];
    f32 e[25];
    f32 f[5];
} S_00672470;
extern S_00672470 D_001A6F10;
extern char D_L39_002465B0[];
extern char D_L39_002465B8[];
extern char D_L39_002465C0[];
extern char D_L39_002465C8[];
extern char D_L39_002465D0[];
extern char D_L39_002465D8[];
extern char D_L39_002465E0[];
extern char D_L39_002465E8[];
extern char D_L39_002465F0[];
extern char D_L39_002465F8[];
extern char D_L39_00246600_0066FB20[];
extern char *func_00120EE8(char *, char *);
extern s32 func_00118F88(char *);
extern s32 func_00120B70(char *, char *, s32);
extern s32 func_00118F70(char *);
extern f32 func_00131ED8(s32);
extern s32 func_001205B0(char *, char *);

s32 func_L39_0066FB20(char *key, char *val) {
    s32 ret = 0;
    char *p;
    u32 i;
    f32 v;

    p = func_00120EE8(key, D_L39_002465B0);
    if (p != 0) {
        i = func_00118F88(p + 1);
        if (i < 26) {
            if (func_00120B70(key, D_L39_002465B8, 2) == 0) {
                ret = 1;
                D_001A6F10.a[i] = func_00118F88(val);
            } else if (func_00120B70(key, D_L39_002465C0, 3) == 0) {
                ret = 1;
                D_001A6F10.b[i] = func_00131ED8(func_00118F70(val));
            } else if (func_00120B70(key, D_L39_002465C8, 3) == 0) {
                ret = 1;
                D_001A6F10.c[i] = func_00131ED8(func_00118F70(val));
            } else if (func_00120B70(key, D_L39_002465D0, 3) == 0) {
                ret = 1;
                D_001A6F10.d[i] = func_00131ED8(func_00118F70(val));
            } else if (func_00120B70(key, D_L39_002465D8, 3) == 0) {
                ret = 1;
                D_001A6F10.e[i] = func_00131ED8(func_00118F70(val));
            }
        }
    } else {
        v = func_00131ED8(func_00118F70(val));
        if (func_001205B0(key, D_L39_002465E0) == 0) {
            ret = 1;
            D_001A6F10.f[0] = v;
        } else if (func_001205B0(key, D_L39_002465E8) == 0) {
            ret = 1;
            D_001A6F10.f[1] = v;
        } else if (func_001205B0(key, D_L39_002465F0) == 0) {
            ret = 1;
            D_001A6F10.f[2] = v;
        } else if (func_001205B0(key, D_L39_002465F8) == 0) {
            ret = 1;
            D_001A6F10.f[3] = v;
        } else if (func_001205B0(key, D_L39_00246600_0066FB20) == 0) {
            ret = 1;
            D_001A6F10.f[4] = v;
        }
    }
    return ret;
}
/* localdecomp:end func_L39_0066FB20 */
