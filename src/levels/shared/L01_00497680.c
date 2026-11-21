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

/* localdecomp:start func_L01_00497680 */
extern f32 D_L01_001D91A8;
extern f32 D_L01_001D91B0;
extern f32 D_L01_001D91B4;
extern s32 D_L01_001D9220;
extern f32 D_L01_001D9224;
extern f32 D_L01_001D9228;
extern f32 D_L01_001D922C;
extern s32 func_003E9270(s32, s32, f32, f32, f32, f32, f32, f32);
extern s32 func_003E9138(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_L01_00516AA0(s32, s32, s32);
extern s32 func_003E8FE8(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_L01_00518010(s32, s32);
extern s32 func_003E8898(s32, f32, f32);
extern void func_L01_00516B90(s32, s32, s32);
extern s32 func_00381FF0(s32);
extern void func_003E8A58(s32, s32, s32, s32, s32);

void func_L01_00497680(s32 a, s32 b) {
    f32 *v = (f32 *)b;
    f32 x;

    func_003E9270(0x47001D, 0x332299DE, v[0], v[1], v[2], v[3], D_L01_001D91B0 * 0.001953125f, D_L01_001D91B4 / 416.0f);
    x = v[0];
    x += (v[2] - v[3]) * 0.5f;
    func_003E9138(0x470020, 0x8066CCFF, 0xED26, x, v[1], v[3] - D_L01_001D9224, v[3] - D_L01_001D9224);
    func_L01_00516AA0(0x470020, 0x40, 1);
    x -= v[3] * 0.5f;
    x -= D_L01_001D91A8 * 0.001953125f;
    func_003E8FE8(0x47001E, 0, 0x8066CCFF, x + D_L01_001D9228, v[1], 1.0f, 1.0f);
    func_L01_00518010(0x47001E, 1);
    func_003E8898(0x47001E, D_L01_001D922C, 0.0f);
    func_L01_00516AA0(0x47001E, 0x40, 1);
    func_L01_00516B90(0x47001E, 2, 3);
    func_003E8FE8(0x47001F, func_00381FF0(0xCA7), 0x8066CCFF, v[0] - v[2] * 0.5f + (f32)D_L01_001D9220 * 0.001953125f, v[1], 1.0f, 1.0f);
    func_L01_00516AA0(0x47001F, 0x40, 1);
    func_L01_00516B90(0x47001F, 1, 3);
    func_003E8A58(a, 0x47001D, 0x470020, 0x47001E, 0x47001F);
}
/* localdecomp:end func_L01_00497680 */

/* localdecomp:start func_L01_004978A8 */
extern f32 D_L01_001D9230;
extern f32 D_L01_001D9234;
extern f32 D_L01_001D9238;
extern f32 D_L01_001D923C;
extern f32 D_L01_001D9240;
extern f32 D_L01_001D9244;
extern f32 D_L01_001D9248;
extern s32 func_003E9138(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E8FE8(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E8A08(s32, s32, s32);

void func_L01_004978A8(s32 a, s32 b) {
    f32 *v = (f32 *)b;
    f32 step;
    s32 i;

    func_003E9138(0x470023, 0x332299DE, 0, D_L01_001D9238, D_L01_001D923C, D_L01_001D9240, D_L01_001D9244);
    func_003E8630(a, 0x470023);
    func_003E9270(0x470022, 0x332299DE, v[0], v[1], v[2], v[3], D_L01_001D91B0 * 0.001953125f, D_L01_001D91B4 / 416.0f);
    func_003E8630(a, 0x470022);
    step = v[3] / 5.0f - D_L01_001D9248;
    for (i = 0; i < 5; i++) {
        func_003E8FE8(i + 0x470024, 0, 0x8066CCFF, v[0], v[1] + step * ((f32)i - 2.0f), 1.0f, 1.0f);
        func_L01_00516AA0(i + 0x470024, 0x40, 1);
        if (i > 0) {
            func_003E9138(i + 0x47002A, 0x202299DE, 0, v[0], v[1] + step * ((f32)i - 2.5f), v[2] - D_L01_001D9234 * 0.001953125f, D_L01_001D9230);
            func_003E8A08(a, i + 0x470024, i + 0x47002A);
        } else {
            func_003E8630(a, i + 0x470024);
        }
    }
}
/* localdecomp:end func_L01_004978A8 */

/* localdecomp:start func_L01_00497AC8 */
extern f32 D_L01_001D91A8;
extern f32 D_L01_001D91AC;
extern f32 func_L01_00497C08(s32 a0, f32 a, f32 b);
extern f32 func_L01_00497C38(s32 a0, f32 a, f32 b, f32 c);

static __inline__ void place_00497AC8(f32 *r, f32 *v, u8 x, u8 y, f32 sx, f32 sy) {
    r[2] = func_L01_00497C08(x, v[2], sx);
    r[3] = func_L01_00497C08(y, v[3], sy);
    r[0] = func_L01_00497C38(x, v[0], v[2], r[2]);
    r[1] = func_L01_00497C38(y, v[1], v[3], r[3]);
}

void func_L01_00497AC8(void *fn, s32 a, s32 b, s32 ax, s32 ay, s32 inset, f32 sx, f32 sy) {
    f32 r[4];
    u8 x = ax;
    u8 y = ay;
    u8 in = inset;

    place_00497AC8(r, (f32 *)b, x, y, sx, sy);
    if (in) {
        r[2] -= D_L01_001D91A8 * 0.001953125f;
        r[3] -= D_L01_001D91AC / 416.0f;
    }
    ((void (*)(s32, f32 *))fn)(a, r);
}
/* localdecomp:end func_L01_00497AC8 */

/* localdecomp:start func_L01_00497BE0 */
extern void func_L01_00517918(int);

void func_L01_00497BE0(void)
{
    func_L01_00517918(13);
    func_L01_00517918(14);
}
/* localdecomp:end func_L01_00497BE0 */

/* localdecomp:start func_L01_00497C08 */
f32 func_L01_00497C08(s32 a0, f32 a, f32 b) {
    if (a0 == 2) {
        return a * (1.0f - b);
    }
    return a * b;
}
/* localdecomp:end func_L01_00497C08 */

/* localdecomp:start func_L01_00497C38 */
f32 func_L01_00497C38(s32 a0, f32 a, f32 b, f32 c) {
    if (a0 == 0) {
        return a - b * 0.5f + c * 0.5f;
    }
    if (a0 == 2) {
        return a + b * 0.5f - c * 0.5f;
    }
    return a;
}
/* localdecomp:end func_L01_00497C38 */
