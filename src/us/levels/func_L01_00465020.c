#include "common.h"

/* NTSC-U counterpart of func_L01_00468678 (src/levels/shared/L01_00462978.c) */
#include "vu0.h"
extern u8 *func_L01_0045E438(s32);
#include "vu0.h"
extern u8 *func_L01_0045E438(s32);
#include "vu0.h"
#include "vu0.h"
extern u8 *func_L01_0045E438(s32);
#include "vu0.h"
extern u8 *func_L01_0045E438(s32);
extern u8 *func_L01_0045E438(s32);
extern f32 func_0037E250(f32 low, f32 high);
#include "vu0.h"

/* localdecomp:start func_L01_00465020 */
#include "vu0.h"
typedef struct {
    u8 pad0[0x88]; f32 z; u8 pad8C[0x350 - 0x8C]; f32 floor;
    u8 pad354[0x25C4 - 0x354]; s32 state;
} Hero_00468678;
extern Hero_00468678 D_001A4BE0;
extern u8 *D_L01_002211A0_00465020[];
u8 *func_L01_00465020(vu0_q *pos, f32 *velocity, s32 color, f32 size, f32 ground) {
    extern u8 *func_L01_0045E438(s32);
    extern f32 func_0037E250(f32, f32);
    extern s32 func_0037E208(s32, s32);
    extern f32 func_0037E2A8(void);
    u8 *p = func_L01_0045E438(0x22);
    f32 *s;
    if (p) {
        *(s32 *)(p + 4) = color;
        p[1] = 0;
        s = (f32 *)(p + 0x20);
        p[9] = 0x44;
        p[3] = 0x44;
        s[3] = func_0037E250(0.75f, 1.25f) * size;
        *(f32 *)(p + 0xC) = 5250.0f;
        p[8] = func_0037E208(-10, 10) + 128;
        p[2] = *D_L01_002211A0_00465020[0];
        *(s16 *)(p + 0xA) = func_0037E208(70, 140);
        if (ground == -1.0f) {
            if (D_001A4BE0.state == 0x30) s[4] = D_001A4BE0.z + 0.4f;
            else s[4] = D_001A4BE0.floor;
        } else s[4] = ground;
        s[5] = func_0037E2A8();
        s[6] = func_0037E250(0.02908882312476635f, 0.1163552924990654f);
        s[7] = func_0037E250(0.008333333767950535f, 0.023333333432674408f);
        s[0] = velocity[0];
        s[1] = velocity[1];
        s[2] = velocity[2];
        *(vu0_q *)(p + 0x10) = *pos;
    }
    return p;
}
/* localdecomp:end func_L01_00465020 */
