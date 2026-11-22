#include "common.h"

typedef struct O_49A988 O_49A988;
typedef struct { u8 p0[0xC]; void (*fn)(O_49A988 *); } VT_49A988;
struct O_49A988 { s32 w0; VT_49A988 *vt; };
typedef struct {
    s32 w0;
    u8 b4;
    u8 pad5[3];
    void (*fn)(void);
    s32 wC;
} S_48F880e;
typedef struct {
    u8 pad0[0x1C4];
    s32 w1C4;
} S_48F880;
typedef struct O_490778 O_490778;
typedef struct {
    u8 pad0[12];
    void (*fn)(O_490778 *);
} V_490778;
struct O_490778 {
    u8 pad0[4];
    V_490778 *vt;
};

/* localdecomp:start func_L01_00492FE0 */
typedef struct {
    u8 pad0[0x4954];
    s32 f4954;
    u8 pad1[0x6F08 - 0x4958];
    u8 f6F08[1];
} S_L01_160C40;

extern s32 func_L01_0047EF58(s32 a);
extern s32 func_L01_00494160(s32 a);
extern void func_L01_00494390(s32 a, s32 b, s32 c, s32 d, s32 e);
extern S_L01_160C40 D_00160C40_00492FE0[];
extern s32 D_L01_001D8E70;
extern s32 D_L01_001D8E74;

void func_L01_00492FE0(void) {
    s32 r;

    D_L01_001D8E70 = func_L01_0047EF58(0);
    D_L01_001D8E74 = func_L01_0047EF58(0);
    r = func_L01_00494160(0);
    func_L01_00494390(r, D_L01_001D8E70, D_L01_001D8E74, D_00160C40_00492FE0->f4954, (s32)&D_00160C40_00492FE0->f6F08);
}
/* localdecomp:end func_L01_00492FE0 */

/* localdecomp:start func_L01_00493038 */
extern void *D_L01_001D8E70_00493038;
extern void *D_L01_001D8E74_00493038;
extern void *func_L01_00494160_00493038(s32);
extern void func_L01_0047F018(s32);
void func_L01_00493038(void) {
    O_49A988 *o = ((O_49A988 * (*)(s32))func_L01_00494160_00493038)(0);
    o->vt->fn(o);
    func_L01_0047F018((*(s32 *)&D_L01_001D8E70_00493038));
    func_L01_0047F018((*(s32 *)&D_L01_001D8E74_00493038));
}
/* localdecomp:end func_L01_00493038 */

/* localdecomp:start func_L01_00493078 */


extern s32 D_L01_001D8E68;
extern S_48F880e D_L01_002EB498[];
extern S_48F880 *D_001D52FC;
extern void func_003A5348(s32 a0, s32 a1, s32 a2);
extern s32 func_L01_0047FE28(void);
extern s32 func_L01_004A1128(void);
extern void func_L01_00517748(s32 a0);
extern void func_L01_00516090_00493078(s32 a0);

void func_L01_00493078(s32 a0, s32 flags) {
    S_48F880e *e;

    if (flags & 0x40) {
        e = &D_L01_002EB498[D_L01_001D8E68];
        if (e->b4 != 0 && D_L01_002EB498[D_L01_001D8E68].fn != 0) {
            e->fn();
        } else {
            func_003A5348(5, 0, 0);
        }
    }
    if (flags & 0x910) {
        func_L01_00517748(func_L01_0047FE28());
        func_L01_00516090_00493078(a0);
    } else if (D_001D52FC->w1C4 & 1) {
        func_L01_00517748(func_L01_004A1128());
        func_L01_00516090_00493078(a0);
    }
}
/* localdecomp:end func_L01_00493078 */

/* localdecomp:start func_L01_00493150 */
extern s32 D_L01_001D8E6C;
extern s32 D_L01_001D8E7C;
extern s32 func_003B9BD0(s32);
extern s32 func_003B9C58(s32);
extern s32 func_L01_00517190(s32, s32);
extern s32 func_L01_00516D60(s32, s32);

void func_L01_00493150(void) {
    s32 r;

    r = func_003B9C58(func_003B9BD0(0));
    D_L01_001D8E68 = r;
    if (r >= 0) {
        if (D_L01_001D8E6C != r) {
            D_L01_001D8E7C = 30;
        }
        if (D_L01_001D8E7C != 0) {
            if (--D_L01_001D8E7C == 0) {
                func_L01_00516D60(0x1C0003, 1);
                func_L01_00517190(0x1C0003, D_L01_002EB498[D_L01_001D8E68].wC);
            }
        }
        D_L01_001D8E6C = D_L01_001D8E68;
    }
}
/* localdecomp:end func_L01_00493150 */
