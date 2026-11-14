#include "common.h"

typedef s32 (*FnVcall_006826C0)(void *, s32, s32);

typedef struct {
    u8 pad0[0x60];
    void *f60;
    s32 f64;
    s32 f68;
    s32 f6C;
    s32 f70;
    s32 f74;
} S_00683550;
typedef struct {
    u8 pad0[0x48];
    s32 f48;
} T_00683550;

typedef struct Vt_00685D48 {
    u8 pad_00[0x30];
    s32 (*f30)(void *, void *, void *);
    s32 (*f34)(void *, void *, void *);
} Vt_00685D48;

typedef void (*Fn_00686768)(void *);
typedef struct S_00686768 {
    u8 pad[0x110];
    u8 *arr[1];
} S_00686768;

/* declared by functions of L39_00681758.c, which this file was cut from */
extern void func_L39_0067EEC8(u8 *, s32);
extern s32 func_L01_00517538(s32, f32, f32);
extern s32 func_003E7F20(s32, s32);
extern s32 func_L01_00516AA0(s32, s32, s32);
extern S_00683550 *func_L39_0067EE40(void *, void *);
s32 func_L01_00516C78(s32, s32, s32);
s32 func_L01_00516AA0(s32, s32, s32);

/* localdecomp:start func_L39_00683718 */
typedef struct {
    char _p0[0x64];
    s32 f64;
    s32 f68;
    s32 f6C;
    s32 f70;
} S_683718;

/* from rac4-decomp's func_L00_004F7328 */
void func_L39_00683718(S_683718 *arg0) {
    arg0->f64 = -1;
    arg0->f68 = -1;
    arg0->f6C = -1;
    arg0->f70 = -1;
}
/* localdecomp:end func_L39_00683718 */

/* localdecomp:start func_L39_00683730 */
extern s32 func_003E7F20(s32, s32);

s32 func_L39_00683730(void *arg0, s32 arg1) {
    s32 v = *(s32 *)((u8 *)arg0 + 0x64);

    if (v != -1) {
        return func_003E7F20(v, arg1);
    }
    return 0;
}
/* localdecomp:end func_L39_00683730 */

/* localdecomp:start func_L39_00683760 */
extern s32 func_L01_00518010(s32, s32);
extern s32 func_003E8898(s32, f32, f32);

s32 func_L39_00683760(S_00683550 *o, s32 arg1, f32 a, f32 b) {
    if (o->f64 != -1) {
        if (func_L01_00518010(o->f64, arg1) != 0) {
            if (arg1 != 0) {
                return func_003E8898(o->f64, a, b);
            }
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L39_00683760 */

/* localdecomp:start func_L39_006837E8 */
s32 func_L39_006837E8(void *arg0, s32 arg1, s32 arg2) {
    s32 v;
    *(s32 *)((u8 *)arg0 + 0x74) = arg1;
    v = *(s32 *)((u8 *)arg0 + 0x64);
    if (v != -1) {
        return func_L01_00516C78(v, arg1, arg2);
    }
    return 0;
}
/* localdecomp:end func_L39_006837E8 */

/* localdecomp:start func_L39_00683818 */
extern s32 func_L01_00516AA0(s32, s32, s32);

s32 func_L39_00683818(void *arg0, s32 arg1, s32 arg2) {
    s32 v = *(s32 *)((u8 *)arg0 + 0x64);

    if (v != -1) {
        return func_L01_00516AA0(v, arg1, arg2);
    }
    return 0;
}
/* localdecomp:end func_L39_00683818 */
