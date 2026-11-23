/* PAL near miss (haiku-w3): 146 words differ with the file's flags; saved-register choice (parent/m/kind in $s4/$s0/$s2 vs retail), the parent root-walk branch shape (retail bnel, we beqz) and the duplicated tail in the parent==0 arm */
#include "common.h"
typedef struct {
    u8 pad[16];
    float f;
    u8 pad2[8];
} Src_002F7888;
typedef struct {
    u8 pad[0xAA];
    u16 f_AA;
} S_002F94F8;
typedef struct {
    s32 w0;
    s32 w4;
    s32 w8;
    s32 wC;
} S_2FC880b;
typedef struct {
    u8 pad0[0x20];
    u8 b20;
    u8 pad21[0x30 - 0x21];
    u8 b30;
    u8 b31;
    s16 h32;
    u8 pad34[0x68 - 0x34];
    S_2FC880b *p68;
} S_2FC880;
extern Src_002F7888 D_L01_002BE708[];
extern vu0_v4 D_L01_001E29C0;
/* localdecomp:start func_L01_002F8F20 */
#include "vu0.h"

typedef struct {u8 pad[0x3C]; s32 bolts;} Stats_002F8F20;
extern Stats_002F8F20 D_00142660;
extern vu0_v4 D_L01_001E29C0;
extern Src_002F7888 D_L01_002BE708[];
extern u8 *D_001A71A0;
u8 *func_L01_002F8F20(u8 *parent, vu0_q *position, vu0_q *velocity, s32 flags, s32 amount, s32 kind) {
    extern f32 func_L01_0040E548(void *,void *);
    extern S_2FC880 *func_003C24B0(s32,s32);
    extern void func_L01_002F7808(void);
    extern void func_L01_004450F0(u8 *,s32,s32);
    extern s32 func_L01_002F94F8(S_002F94F8 *);
    extern void func_0038D308(void *,void *);
    extern void func_L01_0044E820(u8 *,u32);
    extern void func_003C6FB0(u8 *,s32 *,s32 *,s32 *);
    extern void func_003C6F90(u8 *,s32,s32,s32,s32);
    extern void func_L01_0043B9E8(u8 *,s32,s32,s32);
    extern s32 func_00382468(s32);
    extern f32 func_003824E0(f32,f32);
    extern void func_0038CE90(void *,void *,void *);
    extern void func_0038CF68(void *,void *,f32);
    extern void func_003C4840(void *,void *,f32);
    extern void func_L01_002F8D40(u8 *,void *,s32,f32,f32);
    extern void func_003C7C38(u8 *);
    vu0_v4 cross, delta;
    s32 r,g,b;
    s32 cls;
    u8 *m, *state, *root;
    f32 angle, tilt;
    if (func_L01_0040E548(position,&D_L01_001E29C0) >= 4096.0f) {
        D_00142660.bolts += amount;
        return 0;
    }
    if (amount >= 30000) cls = 0x1BA5;
    else if (amount >= 10000) cls = 0x1D5D;
    else if (amount >= 3000) cls = 0x1D5C;
    else if (amount >= 1000) cls = 0x13;
    else if (amount >= 500) cls = 0x12;
    else if (amount >= 100) cls = 0x11;
    else if (amount >= 50) cls = 0x10;
    else if (amount >= 20) cls = 0xF;
    else if (amount >= 50) cls = 0xE;
    else cls = 0xD;
    m = (u8 *)func_003C24B0(cls,0x80);
    if (m == 0) return 0;
    func_L01_002F7808();
    state = *(u8 **)(m + 0x68);
    state[0x6D] = 0;
    if (kind) state[0x6D] = 2;
    if (parent) {
        root = parent;
        while (*(u8 **)(root + 0xB8)) root = *(u8 **)(root + 0xB8);
    } else {
        root = 0;
    }
    *(u8 **)(m + 0xB8) = root;
    m[0x31] = 1;
    m[0x30] = 64;
    *(s16 *)(m + 0x32) = 64;
    m[0x63] = 10;
    func_L01_004450F0(m,1,-1);
    *(u16 *)(m + 0x34) |= 0x100;
    *(f32 *)(m + 0x2C) = *(f32 *)(*(u8 **)(m + 0x24) + 0x24) *
        *(f32 *)&D_L01_002BE708[func_L01_002F94F8((S_002F94F8 *)m)];
    func_0038D308(m + 0xC0,m + 0xF0);
    func_L01_0044E820(m,0x80181010);
    func_003C6FB0(m,&r,&g,&b);
    func_003C6F90(m,0,13,0,0);
    func_L01_0043B9E8(m,r,g,b);
    *(vu0_q *)(state + 0x30) = *velocity;
    *(vu0_q *)(m + 0x10) = *position;
    state[0x6D] |= func_00382468(2) ? 1 : 0;
    *(f32 *)(state + 0x78) = *(f32 *)(m + 0x18);
    vec_sub_ba(&delta,parent + 0x10,m + 0x10);
    angle = func_003824E0(0.0f,0.25132742524147034f);
    func_0038CE90(&cross,state + 0x30,&delta);
    func_0038CF68(state + 0x20,&cross,1.0f);
    func_003C4840(state + 0x20,state + 0x20,angle);
    if (flags & 2) {
        tilt = 0.0f;
        if (flags & 0x10) tilt = func_003824E0(-0.5235987901687622f,0.5235987901687622f);
        func_L01_002F8D40(m,D_001A71A0,0,tilt,0.0f);
    }
    func_003C7C38(m);
    return m;
}
/* localdecomp:end func_L01_002F8F20 */
