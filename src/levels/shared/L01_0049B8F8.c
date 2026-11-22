#include "common.h"

typedef struct {
    u8 pad0[0x4954];
    s32 f4954;
    u8 pad1[0x5628 - 0x4958];
    u8 fX[1];
} S_func_00496AB0;
typedef struct O_49A988 O_49A988;
typedef struct { u8 p0[0xC]; void (*fn)(O_49A988 *); } VT_49A988;
struct O_49A988 { s32 w0; VT_49A988 *vt; };
typedef struct {
    s32 x0;
    s32 x4;
    s32 x8;
} E_496DC0;
typedef struct {
    s32 id;
    s32 pad[3];
} Ent_497BC8;
typedef struct { s32 a; s32 b; s32 c; s32 d; } Ent_00497C30;

/* declared by functions of L01_00499C80.c, which this file was cut from */
typedef struct { u8 pad0[0x1C4]; s32 w1C4; } S_00499F00;
extern S_00499F00 *D_001D52FC[] __attribute__((section(".sdata")));
extern u8 D_L01_001D672C[] __attribute__((section(".sdata")));
extern s32 func_L01_00498610(s32);
extern void func_L01_004990A8(s32 a, s32 b);
extern u8 func_L01_0047DAB0(void);
extern void func_L01_0047DAC8(void);
extern s32 func_L01_0047EBE0(void);
extern void func_L01_00517748(int);
extern void func_L01_00517918(s32);
extern void func_003A2750(s32);
extern void func_003A2750(s32 a0);
extern void func_L01_0049B7D0();

/* localdecomp:start func_L01_0049B8F8 */
typedef struct {
    s32 f0;
    s32 f4;
    s32 type;
    s32 fC;
    f32 f10;
    f32 f14;
    f32 f18;
    f32 f1C;
    s32 f20;
    s32 f24;
    f32 f28;
    s32 f2C;
} E_0049B8F8;
extern s32 func_L01_00518D40_0049B8F8(s32);
extern void func_L01_00518590(s32, s32, s32);
extern void func_L01_00516470(s32, f32, f32);
extern void func_L01_00517538(s32, f32, f32);
extern void func_003E8EF0(s32, s32, s32, f32, f32, f32, f32, f32);
extern void func_003E9138(s32, s32, f32, f32, f32, f32, s32);
extern void func_003E9270(s32, s32, f32, f32, f32, f32, f32, f32);
extern void func_003E90B8(s32, s32, s32, f32, f32, f32, f32, f32, f32);
extern void func_003E9358(s32, s32, s32, f32, f32, f32, f32, f32);
extern void func_L01_00516818(s32, f32);
extern void func_L01_00516728(s32, f32, f32);
extern s32 func_L01_00516AA0(s32, s32, s32);
extern void func_L01_00518670(s32, s32, s32);
extern void func_L01_00516B90(s32, s32, s32);
extern void func_003E8630(s32, s32);
extern s32 func_00381FF0(s32);

void func_L01_0049B8F8(E_0049B8F8 *tbl) {
    s32 a = 3;
    s32 b = 3;
    s32 i = 0;
    E_0049B8F8 *e;

    while (tbl[i].f0 != 0) {
        e = &tbl[i];
        switch (e->type) {
        case 0:
            func_L01_00518D40_0049B8F8(e->f0);
            if (e->f2C & 1) {
                func_L01_00518590(e->f0, 1, 1);
                func_L01_00516470(e->f0, e->f10, e->f14);
                func_L01_00517538(e->f0, e->f18, e->f1C);
            }
            break;
        case 1:
            func_003E8EF0(e->f0, e->f24, e->fC, e->f10, e->f14, e->f18, e->f1C, 0.0f);
            break;
        case 2:
            func_003E9138(e->f0, e->fC, e->f10, e->f14, e->f18, e->f1C, e->f24);
            break;
        case 3:
            func_003E9270(e->f0, e->fC, e->f10, e->f14, e->f18, e->f1C, e->f28, e->f28);
            break;
        case 4:
            func_003E90B8(e->f0, (e->f2C & 4) ? func_00381FF0(e->f24) : e->f24, e->fC, e->f10, e->f14, e->f18, e->f1C, 0.005f, 0.005f);
            break;
        case 5:
            func_003E9358(e->f0, (e->f2C & 4) ? func_00381FF0(e->f24) : e->f24, e->fC, e->f10, e->f14, e->f18, e->f1C, 1.0f);
            func_L01_00516818(e->f0, e->f28);
            func_L01_00516728(e->f0, e->f28 * 0.005f, e->f28 * 0.005f);
            func_L01_00516AA0(e->f0, 0x40, 1);
            if (e->f2C & 8) func_L01_00518670(e->f0, 1, 1);
            break;
        }
        if (e->f20 != 0) {
            if (e->f20 & 1) a = 1;
            else if (e->f20 & 2) a = 2;
            if (e->f20 & 8) b = 1;
            else if (e->f20 & 0x10) b = 2;
            func_L01_00516B90(e->f0, a, b);
        }
        if (e->f2C & 2) func_L01_00516AA0(e->f0, 1, 0);
        if (e->f4 != 0) func_003E8630(e->f4, e->f0);
        i++;
    }
}
/* localdecomp:end func_L01_0049B8F8 */
