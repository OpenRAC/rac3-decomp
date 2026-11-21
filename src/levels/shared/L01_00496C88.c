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

/* localdecomp:start func_L01_00496C88 */
extern void func_L01_00496D58(s32 a0, s32 a1);
extern void func_L01_004978A8(s32 a, s32 b);
extern f32 D_L01_001D91D4;
extern void func_L01_00518D40_00496C88(s32);
extern void func_003E8630(s32, s32);
extern void func_L01_00497AC8(void *, s32, s32, s32, s32, s32, f32, f32);

void func_L01_00496C88(s32 a0, s32 a1) {
    func_L01_00518D40_00496C88(0x47000B);
    func_L01_00497AC8(((void (*)(void))func_L01_00496D58), 0x47000B, a1, 1, 0, 0, 1.0f, D_L01_001D91D4);
    func_003E8630(a0, 0x47000B);
    func_L01_00518D40_00496C88(0x470021);
    func_L01_00497AC8(((void (*)(void))func_L01_004978A8), 0x470021, a1, 1, 2, 1, 1.0f, D_L01_001D91D4);
    func_003E8630(a0, 0x470021);
}
/* localdecomp:end func_L01_00496C88 */

/* localdecomp:start func_L01_00496D58 */
extern void func_L01_004974F0(s32 a, s32 b);
extern void func_L01_00496E08(s32 a, s32 b);
extern f32 D_L01_001D91D8;
extern void func_L01_00518D40_00496D58(s32);
extern void func_003E8630(s32, s32);
extern void func_L01_00497AC8(void *, s32, s32, s32, s32, s32, f32, f32);

void func_L01_00496D58(s32 a0, s32 a1) {
    func_L01_00518D40_00496D58(0x47000C);
    func_L01_00497AC8(((void (*)(void))func_L01_00496E08), 0x47000C, a1, 0, 1, 0, D_L01_001D91D8, 1.0f);
    func_003E8630(a0, 0x47000C);
    func_L01_00497AC8(((void (*)(void))func_L01_004974F0), a0, a1, 2, 1, 0, D_L01_001D91D8, 1.0f);
}
/* localdecomp:end func_L01_00496D58 */

/* localdecomp:start func_L01_00496E08 */
extern void func_L01_00497180(s32 a, s32 b);
extern f32 D_L01_001D91DC;
extern void func_L01_00496E98(s32 a, s32 b);
extern void func_L01_00497AC8(void *, s32, s32, s32, s32, s32, f32, f32);

void func_L01_00496E08(s32 a, s32 b) {
    func_L01_00497AC8(func_L01_00496E98, a, b, 1, 0, 1, 1.0f, D_L01_001D91DC);
    func_L01_00497AC8(((void (*)(void))func_L01_00497180), a, b, 1, 2, 0, 1.0f, D_L01_001D91DC);
}
/* localdecomp:end func_L01_00496E08 */

/* localdecomp:start func_L01_00496E98 */
extern f32 D_L01_001D91B0;
extern f32 D_L01_001D91B4;
extern f32 D_L01_001D91E0;
extern s32 func_003E9270(s32, s32, f32, f32, f32, f32, f32, f32);
extern void func_003E8630(s32, s32);
extern void func_L01_00496F78(s32 a, s32 b);
extern void func_L01_00497090(s32 a, s32 b);
extern void func_L01_00497AC8(void *, s32, s32, s32, s32, s32, f32, f32);

void func_L01_00496E98(s32 a, s32 b) {
    f32 *v = (f32 *)b;

    func_003E9270(0x47000E, 0x332299DE, v[0], v[1], v[2], v[3], D_L01_001D91B0 * 0.001953125f, D_L01_001D91B4 / 416.0f);
    func_003E8630(a, 0x47000E);
    func_L01_00497AC8(((void (*)(void))func_L01_00496F78), a, b, 1, 0, 0, 1.0f, D_L01_001D91E0);
    func_L01_00497AC8(((void (*)(void))func_L01_00497090), a, b, 1, 2, 1, 1.0f, D_L01_001D91E0);
}
/* localdecomp:end func_L01_00496E98 */
