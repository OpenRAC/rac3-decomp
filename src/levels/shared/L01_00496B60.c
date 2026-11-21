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
typedef struct { s32 a, b, c, d; } Q_496B00;
extern void func_L01_00496B60(s32, Q_496B00 *);

/* localdecomp:start func_L01_00496B60 */
extern void func_L01_004980C0(s32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 func_00381FF0(s32);
extern s32 func_003E8FE8(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_L01_00516AA0(s32, s32, s32);
extern void func_003E8630(s32, s32);
extern void func_L01_00496C88(s32 a0, s32 a1);
extern void func_L01_00497AC8(void *, s32, s32, s32, s32, s32, f32, f32);
extern f32 D_L01_001D91D0;
__asm__(".extern D_L01_001D91D0, 4");
extern f32 D_L01_001D91C8;
__asm__(".extern D_L01_001D91C8, 4");
extern f32 D_L01_001D91CC;
__asm__(".extern D_L01_001D91CC, 4");

void func_L01_00496B60(s32 a0, Q_496B00 *a1) {
    func_L01_004980C0(0xD, D_L01_001D91D0, 0x470001, 0x470002, 0x470003, 0x470004, 0x470005, 0x470006,
                      0x470007, 0xD0008, 0, 0x470008, 0x470009);
    func_003E8FE8(0x47000A, func_00381FF0(0xC96), 0x8066CCFF, 0.5f, 0.93f, 1.0f, 1.0f);
    func_L01_00516AA0(0x47000A, 0x40, 1);
    func_003E8630(0x470001, 0x47000A);
    func_L01_00497AC8(func_L01_00496C88, a0, (s32)a1, 1, 1, 1, D_L01_001D91C8, D_L01_001D91CC);
}
/* localdecomp:end func_L01_00496B60 */
