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
extern void func_L01_00517918(s32);
extern void func_L01_00497BE0(void);
extern void func_L01_004978A8(s32 a, s32 b);
extern void func_003E8630(s32, s32);
extern void func_L01_00497AC8(void *, s32, s32, s32, s32, s32, f32, f32);
extern void func_L01_004974F0(s32 a, s32 b);
extern f32 D_L01_001D91B0;
extern f32 D_L01_001D91B4;
extern s32 func_003E9270(s32, s32, f32, f32, f32, f32, f32, f32);
extern s32 func_L01_00516AA0(s32, s32, s32);

/* localdecomp:start func_L01_004974F0 */
extern f32 D_L01_001D920C;
extern void func_L01_00497580(s32 a, s32 b);
extern void func_L01_00497680(s32 a, s32 b);
extern void func_L01_00497AC8(void *, s32, s32, s32, s32, s32, f32, f32);

void func_L01_004974F0(s32 a, s32 b) {
    func_L01_00497AC8(func_L01_00497580, a, b, 1, 0, 1, 1.0f, D_L01_001D920C);
    func_L01_00497AC8(func_L01_00497680, a, b, 1, 2, 1, 1.0f, D_L01_001D920C);
}
/* localdecomp:end func_L01_004974F0 */
