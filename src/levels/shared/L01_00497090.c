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

/* declared by functions of L01_00494F98.c, which this file was cut from */
extern void func_003E8630(s32, s32);
extern void func_L01_00497AC8(void *, s32, s32, s32, s32, s32, f32, f32);
extern void func_L01_00497180(s32 a, s32 b);
extern void func_L01_00497090(s32 a, s32 b);

/* localdecomp:start func_L01_00497090 */
extern f32 D_L01_001D91F0;
extern f32 D_L01_001D91F4;
extern s32 func_003E9358(s32, s32, s32, f32, f32, f32, f32, f32);
extern s32 func_L01_00516AA0(s32, s32, s32);
extern s32 func_L01_00518728(s32 arg0, s32 arg1, s32 arg2);
extern s32 func_003E7F20(s32, s32);
extern void func_003E8630(s32, s32);

void func_L01_00497090(s32 a, s32 b) {
    f32 *v = (f32 *)b;
    f32 h = D_L01_001D91F4 / 416.0f;
    f32 w = D_L01_001D91F0 * 0.001953125f;

    v[2] -= w;
    v[3] -= h;
    func_003E9358(0x470012, 0, 0x8066CCFF, v[0], v[1], v[2], v[3], 1.0f);
    func_L01_00516AA0(0x470012, 0x40, 1);
    func_L01_00518728(0x470012, 4, 0);
    func_L01_00518728(0x470012, 8, 0);
    func_003E7F20(0x470012, 1);
    func_003E8630(a, 0x470012);
}
/* localdecomp:end func_L01_00497090 */

/* localdecomp:start func_L01_00497180 */
extern f32 D_L01_001D91F8;
extern void func_L01_00497210(void);
extern void func_L01_004973B0(s32 a, s32 b);
extern void func_L01_00497AC8(void *, s32, s32, s32, s32, s32, f32, f32);

void func_L01_00497180(s32 a, s32 b) {
    func_L01_00497AC8(func_L01_00497210, a, b, 0, 1, 1, D_L01_001D91F8, 1.0f);
    func_L01_00497AC8(func_L01_004973B0, a, b, 2, 1, 1, D_L01_001D91F8, 1.0f);
}
/* localdecomp:end func_L01_00497180 */

INCLUDE_ASM("asm/levels", func_L01_00497210);
