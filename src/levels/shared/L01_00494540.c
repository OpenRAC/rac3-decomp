#include "common.h"

typedef struct Obj_4917A0 Obj_4917A0;
typedef struct {
    s32 pad[3];
    void (*fn)(Obj_4917A0 *);
} Vt_4917A0;
struct Obj_4917A0 {
    s32 pad;
    Vt_4917A0 *vt;
};
typedef struct S_492AF0 S_492AF0;
typedef struct { u8 pad[0xC]; void (*fC)(S_492AF0 *); } V_492AF0;
struct S_492AF0 { s32 f0; V_492AF0 *vt; };
typedef struct Obj_492EE8 Obj_492EE8;
typedef struct {
    s32 pad[3];
    void (*fn)(Obj_492EE8 *);
} Vt_492EE8;
struct Obj_492EE8 {
    s32 pad;
    Vt_492EE8 *vt;
};

/* localdecomp:start func_L01_00494540 */
typedef struct {
    char _p0[0xC];
    s32 fC;
    s32 f10;
} S_494540;

/* from rac4-decomp's func_L00_0062A688 */
s32 func_L01_00494540(S_494540 *arg0) {
    s32 value = arg0->f10;
    if (value != 0) {
        return value;
    }
    return arg0->fC;
}
/* localdecomp:end func_L01_00494540 */

/* localdecomp:start func_L01_00494560 */
s32 func_L01_00494560(void) {
    return 1;
}
/* localdecomp:end func_L01_00494560 */

/* localdecomp:start func_L01_00494568 */
s32 func_L01_00494568(void) {
    return 2;
}
/* localdecomp:end func_L01_00494568 */

/* localdecomp:start func_L01_00494570 */
s32 func_L01_00494570(void) {
    return 0;
}
/* localdecomp:end func_L01_00494570 */

/* localdecomp:start func_L01_00494578 */
s32 func_L01_00494578(void) {
    return 1;
}
/* localdecomp:end func_L01_00494578 */

INCLUDE_ASM("asm/levels", func_L01_00494580);

/* localdecomp:start func_L01_00494590 */
s32 func_L01_00494590(void) {
    return 1;
}
/* localdecomp:end func_L01_00494590 */

/* localdecomp:start func_L01_00494598 */
s32 func_L01_00494598(void) {
    return 0;
}
/* localdecomp:end func_L01_00494598 */

/* localdecomp:start func_L01_004945A0 */
s32 func_L01_004945A0(void) {
    return 0;
}
/* localdecomp:end func_L01_004945A0 */

/* localdecomp:start func_L01_004945A8 */
s32 func_L01_004945A8(void) {
    return 0;
}
/* localdecomp:end func_L01_004945A8 */

/* localdecomp:start func_L01_004945B0 */
s32 func_L01_004945B0(void) {
    return 1;
}
/* localdecomp:end func_L01_004945B0 */

INCLUDE_ASM("asm/levels", func_L01_004945B8);

INCLUDE_ASM("asm/levels", func_L01_00494748);

INCLUDE_ASM("asm/levels", func_L01_004948E8);
