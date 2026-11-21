#include "common.h"

typedef struct {
    u8 pad0[0x34];
    u16 f34;
    u8 pad36[0xB2 - 0x36];
    s16 fB2;
    u8 padB4[0x100 - 0xB4];
} Type_004A3A90;

typedef struct {
    u8 pad0[0x4954];
    s32 f4954;
    u8 pad1[0x4B90 - 0x4958];
    u8 f4B90[1];
    u8 pad2[0x6D28 - 0x4B91];
    u8 fX[1];
} S_func_0049A930;
typedef struct O_49A988 O_49A988;
typedef struct { u8 p0[0xC]; void (*fn)(O_49A988 *); } VT_49A988;
struct O_49A988 { s32 w0; VT_49A988 *vt; };
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 pad[3];
} Ent_0049AB20;
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    u8 f14;
    u8 pad[3];
} S_2EC7A8;
typedef struct { u8 b[16]; } V16_48DCD8;
typedef struct {
    s32 v[12][3];
} S_236B80;
typedef struct {
    s32 x0;
    s32 x4;
    s32 x8;
    s32 xC;
    s32 x10;
    u8 x14;
    u8 pad[3];
} E_49E5B8;
typedef struct {
    s32 offset;
    s32 data;
    u16 size;
    s16 kind;
    s16 arg1;
    s16 arg0;
} Entry_4A0270;
typedef struct {
    s32 count;
    Entry_4A0270 entries[1];
} Table_4A0270;

typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    u8 fC;
    u8 pad[11];
} S_2EC760_0049E648;

/* declared by functions of L01_0049E000.c, which this file was cut from */
extern s32 D_L01_001D94CC;

/* localdecomp:start func_L01_0049E408 */
extern s32 D_L01_001D94CC;
extern s32 D_L01_001D94D4;
extern f32 D_L01_001D94E4;
__asm__(".extern D_L01_001D94CC, 4");
__asm__(".extern D_L01_001D94D4, 4");
__asm__(".extern D_L01_001D94E4, 4");
extern void func_L01_00516558(s32, f32 *, f32 *);
extern s32 func_L01_00516470(s32, f32, f32);

s32 func_L01_0049E408(void) {
    f32 y1, x1, y0, x0;
    f32 z = 0.0f;
    f32 d;
    s32 ok;

    x0 = z;
    y0 = z;
    x1 = z;
    y1 = z;
    ok = 1;
    func_L01_00516558(D_L01_001D94CC, &x0, &y0);
    func_L01_00516558(D_L01_001D94D4, &x1, &y1);
    d = D_L01_001D94E4;
    x1 -= d;
    x0 -= d;
    if (x1 < 0.5f) {
        x1 = 0.5f;
        ok = 0;
    }
    func_L01_00516470(D_L01_001D94CC, x0, y0);
    func_L01_00516470(D_L01_001D94D4, x1, y1);
    return ok;
}
/* localdecomp:end func_L01_0049E408 */

INCLUDE_ASM("asm/levels", func_L01_0049E4B0);

/* localdecomp:start func_L01_0049E558 */
extern s32 D_L01_001D94CC;
extern s32 D_L01_001D94D0;
extern s32 D_L01_001D94D4;
__asm__(".extern D_L01_001D94CC, 4");
__asm__(".extern D_L01_001D94D0, 4");
__asm__(".extern D_L01_001D94D4, 4");
extern s32 func_L01_00516470(s32, f32, f32);

void func_L01_0049E558(void) {
    f32 y = 0.47836399f;

    func_L01_00516470(D_L01_001D94CC, 0.5f, y);
    func_L01_00516470(D_L01_001D94D0, -0.5f, y);
    func_L01_00516470(D_L01_001D94D4, 1.5f, y);
}
/* localdecomp:end func_L01_0049E558 */
