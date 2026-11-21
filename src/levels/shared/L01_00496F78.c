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
extern void func_L01_00496F78(s32 a, s32 b);

/* localdecomp:start func_L01_00496F78 */
extern f32 D_L01_001D91E4;
extern f32 D_L01_001D91E8;
extern f32 D_L01_001D91EC;
__asm__(".extern D_L01_001D91E4, 4");
__asm__(".extern D_L01_001D91E8, 4");
__asm__(".extern D_L01_001D91EC, 4");
extern s32 func_003E8FE8(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_L01_00516AA0(s32, s32, s32);
extern s32 func_003E7F20(s32, s32);
extern s32 func_L01_00518010(s32, s32);
extern s32 func_003E8898(s32, f32, f32);
extern s32 func_003E9138(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E8A08(s32, s32, s32);

void func_L01_00496F78(s32 a, s32 b) {
    f32 *v = (f32 *)b;

    func_003E8FE8(0x47000F, 0, 0x8066CCFF, v[0], v[1], 1.0f, 1.0f);
    func_L01_00516AA0(0x47000F, 0x40, 1);
    func_003E7F20(0x47000F, 1);
    func_L01_00518010(0x47000F, 1);
    func_003E8898(0x47000F, v[2] * 0.9f, 0.0f);
    func_003E9138(0x470010, 0x202299DE, 0, v[0], v[1] + v[3] + D_L01_001D91E4, v[2] - D_L01_001D91EC * 0.001953125f, D_L01_001D91E8);
    func_003E8A08(a, 0x47000F, 0x470010);
}
/* localdecomp:end func_L01_00496F78 */
