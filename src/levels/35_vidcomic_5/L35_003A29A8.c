#include "common.h"
#include "vu0.h"

typedef struct { u8 pad[0x1C]; s32 kind; } Entry_003A42F8;
typedef struct { u8 pad[0x100]; Entry_003A42F8 entries[4]; } State_003A42F8;

typedef struct { u8 pad[0x1C]; s32 mode; } Row;
typedef struct { u8 pad[0x100]; Row rows[4]; } State;

/* localdecomp:start func_L35_003A29A8 */
#include "vu0.h"

typedef struct V_003A29A8 {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V_003A29A8;

extern f32 D_L35_001DE9D0;
__asm__(".extern D_L35_001DE9D0, 4");
extern f32 D_L35_001DE9D4;
__asm__(".extern D_L35_001DE9D4, 4");
extern f32 D_L35_001DE9D8;
__asm__(".extern D_L35_001DE9D8, 4");
extern f32 D_L35_001DE9DC;
__asm__(".extern D_L35_001DE9DC, 4");
extern u8 *D_L35_0021F258[];
extern f32 func_003824E0(f32, f32);
extern void func_00382580(void *, f32, f32);
extern s32 func_00382498(s32, s32);
extern s32 func_00382468(s32);
extern u8 *func_L01_00475C60(void *, void *, s32, s32, s32, s32, f32, f32, f32, s32);

void func_L35_003A29A8(u8 *pos, u8 *vel, s32 count, s32 a3, f32 speed, f32 scale) {
    V_003A29A8 a;
    V_003A29A8 b;
    u8 *p;
    s32 i;
    s32 c;
    s32 idx;
    s32 r;
    f32 s;

    for (i = 0; i < count; i++) {
        s = scale;
        idx = 0x75;
        b = *(V_003A29A8 *)vel;
        b.x *= func_003824E0(speed * 0.3f, speed) * 0.016666668f;
        b.y = func_003824E0(-D_L35_001DE9D0, D_L35_001DE9D0) * 0.016666668f;
        b.z = func_003824E0(0.0f, D_L35_001DE9D4) * 0.016666668f;
        func_00382580(&a, 0.0f, D_L35_001DE9DC);
        vec_add_ab(&a, &a, pos);
        c = func_00382468(3) ? 0xFFF2B3 : 0xFFE361;
        if (func_00382468(2)) {
            r = func_00382498(2, 3);
            s *= func_003824E0(0.5f, 0.7f);
        } else {
            r = func_00382498(1, 3);
            idx = 0x7F;
            s *= func_003824E0(0.25f, 0.35f);
        }
        p = func_L01_00475C60(&a, &b, a3, func_00382498(-8, 8), c | 0x7F000000, c & 0xFFFFFF,
                              s * 210000.0f, 42000.0f, func_003824E0(D_L35_001DE9D8 * 0.5f, D_L35_001DE9D8), 0);
        if (p != 0) {
            p[2] = D_L35_0021F258[idx][r];
            p[3] = func_00382468(2) ? 0x44 : 0x48;
        }
    }
}
/* localdecomp:end func_L35_003A29A8 */
