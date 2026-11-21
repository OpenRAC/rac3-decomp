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
extern f32 D_L01_001D91B0;
extern f32 D_L01_001D91B4;
extern s32 func_003E9270(s32, s32, f32, f32, f32, f32, f32, f32);
extern s32 func_L01_00516AA0(s32, s32, s32);
extern void func_L01_004973B0(s32 a, s32 b);

/* localdecomp:start func_L01_004973B0 */
extern s32 func_003E8FE8(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_L01_00516AA0(s32, s32, s32);
extern s32 func_003E9270(s32, s32, f32, f32, f32, f32, f32, f32);
extern s32 func_L01_00518110(s32, s32, s32, s32);
extern f32 D_L01_001D91B0;
__asm__(".extern D_L01_001D91B0, 4");
extern f32 D_L01_001D91B4;
__asm__(".extern D_L01_001D91B4, 4");

void func_L01_004973B0(s32 a, s32 b) {
    f32 *v = (f32 *)b;
    f32 d = v[3] * 0.25f;

    func_003E8FE8(0x470019, 0, 0x8066CCFF, v[0], v[1] - d, 0.85f, 0.85f);
    func_L01_00516AA0(0x470019, 0x40, 1);
    func_003E8FE8(0x47001A, 0, 0x8066CCFF, v[0], v[1] + d, 0.85f, 0.85f);
    func_L01_00516AA0(0x47001A, 0x40, 1);
    func_003E9270(0x470018, 0x332299DE, v[0], v[1], v[2], v[3], D_L01_001D91B0 * 0.001953125f, D_L01_001D91B4 / 416.0f);
    func_L01_00518110(a, 0x470018, 0x470019, 0x47001A);
}
/* localdecomp:end func_L01_004973B0 */
