#include "common.h"
#include "vu0.h"

typedef struct {
    u8 pad0[32];
    u8 state;
    u8 pad21[16];
    u8 unk31;
    u8 pad32[2];
    u16 unk34;
} M3C7568;
typedef struct Moby Moby;
typedef struct {
    char pad0[0x550];
    Moby *child;
} Vars;
struct Moby {
    char pad0[0x42];
    unsigned char anim;
    char pad43[0x48 - 0x43];
    float animSpeed;
    char pad4C[0x68 - 0x4C];
    Vars *vars;
};

/* localdecomp:start func_L04_003DE410 */
#include "vu0.h"
#define U8(p, o) (*(u8 *)((u8 *)(p) + (o)))
#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define S16(p, o) (*(s16 *)((u8 *)(p) + (o)))
#define S32(p, o) (*(s32 *)((u8 *)(p) + (o)))
#define F32(p, o) (*(f32 *)((u8 *)(p) + (o)))
#define PTR(p, o) (*(u8 **)((u8 *)(p) + (o)))
#define Q128(p, o) (*(vu0_q *)((u8 *)(p) + (o)))
extern s32 D_L01_001D6694;
extern s32 D_001D545C;
extern u8 D_L01_001D66B0[8];
extern s32 D_L01_001DFB40;
extern void func_L01_003CAA80(u8 *);
extern void func_L01_004AA7E8(u8 *, s32);
extern void func_L01_004AA760(s32, u8 *);
extern s32 func_L01_004BA800(void);
extern void func_L01_004450F0(M3C7568 *, s32, s32);
extern s32 func_L01_004561B8(u8 *);
extern void func_L01_00335F38(u8 *, s32);
extern void func_L01_003362B0(u8 *, s32);
extern void func_L01_003CABE8(Moby *, int, int, int, float);
extern void func_L01_003CAC78(u8 *);
extern void func_L01_003CBB40(u8 *, u8 *);
extern void func_L01_003CBEF0(u8 *);
extern void func_L04_003E1D80(u8 *, u8 *);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382498(s32, s32);
extern void func_L01_0045BD78(u8 *a0, f32 a, f32 b, f32 c, f32 d);
extern void func_L01_0045A9F0(u8 *);
extern f32 func_L01_00448890(void *, f32, void *, f32, f32, f32, s32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DB00(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern s32 func_L01_0044E1B8(void *, f32);
extern f32 func_L01_00443A18(f32, f32);
extern void func_003C3A10(Moby *, int, int, int);
extern void func_0038CE20(f32 *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_L01_0045C2A0(void *, f32, f32, f32);
extern f32 func_L01_004395E0(void *);
extern void func_L01_00404A10(void *, void *);
extern void func_003C2F58(u8 *, s32, f32 *);
extern void func_003C2EC0(void *, s32, void *);
extern f32 func_L01_00447878(void *, void *, s32, f32, f32);
extern void func_L01_00362610(void *, void *, s32, s32, s32);
extern s32 func_0013D3E0(void);
extern s32 func_L01_003303B8(void *, f32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_00451FE0(void *, s32, void *, f32, f32, f32, f32, s32, f32, f32, s32, s32, s32, s32, f32, f32, s32, s32);
extern void func_003A52A0(s32, s32, u8 *);
extern s32 func_L01_00454370(void *, void *);

void func_L04_003DE410(u8 *arg0) {
    vu0_v4 sp90;
    vu0_v4 spA0;
    vu0_v4 spB0;
    vu0_v4 mtx[4];
    u8 *v;
    u8 *c11;
    u8 *c14;
    u8 *c24;
    u8 *cls;
    f32 *p;
    f32 sc;
    f32 up;
    s32 turn;
    s32 hit;
    s32 started;
    f32 f9;
    f32 f10;
    f32 f11;
    f32 f14;
    f32 f15;
    f32 f16;
    f32 f24;
    f32 f25;
    f32 yaw;

    func_L01_003CAA80(arg0);
    v = PTR(arg0, 0x68);
    if (D_L01_001D6694 == 2 && U8(arg0, 0x20) != 3) {
        S32(arg0, 0x98) = 0;
        U16(arg0, 0x34) = (U16(arg0, 0x34) | 0x41) & 0xEFFF;
        func_L01_004AA7E8(arg0, 1);
        if (PTR(v, 0x550) != 0) {
            U16(PTR(v, 0x550), 0x34) |= 0x41;
            U16(PTR(v, 0x550), 0x34) &= 0xEFFF;
            S32(PTR(v, 0x550), 0x98) = 0;
            func_L01_004AA7E8(PTR(v, 0x550), 1);
            func_L01_004AA760(1, PTR(v, 0x550));
        }
        return;
    }
    if (func_L01_004BA800() == 0 && U8(arg0, 0x20) != 3) {
        cls = PTR(arg0, 0x24);
        U16(arg0, 0x34) &= ~0x41;
        U16(arg0, 0x34) |= U16(cls, 0x44) & 0x1000;
        S32(arg0, 0x98) = S32(cls, 0x10);
        if (PTR(v, 0x550) != 0) {
            U16(PTR(v, 0x550), 0x34) &= ~0x41;
            U16(PTR(v, 0x550), 0x34) |= U16(PTR(PTR(v, 0x550), 0x24), 0x44) & 0x1000;
            S32(PTR(v, 0x550), 0x98) = S32(PTR(PTR(v, 0x550), 0x24), 0x10);
        }
    }
    switch (U8(arg0, 0x20)) {
    case 0:
        S32(arg0, 0x98) = 0;
        U16(arg0, 0x34) = (U16(arg0, 0x34) | 0x43) & 0xEFFF;
        func_L01_004AA7E8(arg0, 1);
        func_L01_004450F0((M3C7568 *)arg0, 1, -1);
        break;
    case 2:
        if (func_L01_004561B8(arg0) != 0) {
            func_L01_00335F38(PTR(arg0, 0xB8), 0);
            func_L01_003CABE8((Moby *)arg0, 0, 0, 0, 1.0f);
        }
        break;
    case 3:
        S32(arg0, 0x98) = 0;
        break;
    case 4:
        if (func_L01_004561B8(arg0) != 0) {
            func_L01_00335F38(PTR(arg0, 0xB8), 0);
            func_L01_003CABE8((Moby *)arg0, 0, 0, S32(v, 0x47C), func_003824E0(0.75f, 1.0f));
        }
        if (U8(v, 0x490) != 0 && (U8(arg0, 0x60) & 2)) {
            func_L01_00335F38(PTR(arg0, 0xB8), 1);
        }
        break;
    case 5:
        if (func_L01_004561B8(arg0) != 0) {
            func_L01_00335F38(PTR(arg0, 0xB8), 0);
            if (U8(v, 0x559) != 0) {
                func_L01_003CABE8((Moby *)arg0, 0, 0, S32(v, 0x47C), func_003824E0(0.75f, 1.0f));
            } else {
                func_L01_003CABE8((Moby *)arg0, 1, 0, S32(v, 0x47C), func_003824E0(0.75f, 1.0f));
            }
        }
        if (U8(v, 0x490) != 0 && (U8(arg0, 0x60) & 2)) {
            func_L01_00335F38(PTR(arg0, 0xB8), 1);
        }
        break;
    case 6:
        if (func_L01_004561B8(arg0) != 0) {
            func_L01_00335F38(PTR(arg0, 0xB8), 0);
            func_L01_003CABE8((Moby *)arg0, 5, 0, S32(v, 0x47C), 1.0f);
        }
        if (U8(v, 0x490) != 0 && (U8(arg0, 0x60) & 2)) {
            func_L01_00335F38(PTR(arg0, 0xB8), 1);
        }
        break;
    case 7:
        if (func_L01_004561B8(arg0) != 0) {
            func_L01_00335F38(PTR(arg0, 0xB8), 0);
            func_L01_003CABE8((Moby *)arg0, 0xA, 0, S32(v, 0x47C), 1.0f);
        }
        if (U8(v, 0x490) != 0 && (U8(arg0, 0x60) & 2)) {
            func_L01_00335F38(PTR(arg0, 0xB8), 1);
        }
        break;
    case 8:
        if (func_L01_004561B8(arg0) != 0) {
            func_L01_00335F38(PTR(arg0, 0xB8), 0);
            func_L01_003CABE8((Moby *)arg0, 4, 0, S32(v, 0x47C), 1.0f);
        }
        if (U8(v, 0x490) != 0 && (U8(arg0, 0x60) & 2)) {
            func_L01_00335F38(PTR(arg0, 0xB8), 1);
        }
        break;
    case 9:
        if (func_L01_004561B8(arg0) != 0) {
            func_L01_00335F38(PTR(arg0, 0xB8), 0);
            func_L01_0045BD78(arg0, 0.0028000001f, 0.050000004f, 0.020106195f, 2.0106194f);
            func_L01_003CABE8((Moby *)arg0, 6, 0, S32(v, 0x47C), 1.0f);
        }
        f9 = F32(v, 0x240) / F32(v, 0x1B8);
        if (f9 < 0.7f) {
            f9 = 0.7f;
        }
        F32(arg0, 0x48) = F32(PTR(v, 0x550), 0x48) = f9 * 1.1f;
        if (U8(v, 0x490) != 0 && (U8(arg0, 0x60) & 2)) {
            func_L01_00335F38(PTR(arg0, 0xB8), 1);
        }
        break;
    case 10:
        if (func_L01_004561B8(arg0) != 0) {
            func_L01_00335F38(PTR(arg0, 0xB8), 0);
            func_L01_0045BD78(arg0, 0.0096f, 0.15f, 0.020106195f, 2.0106194f);
            func_L01_003CABE8((Moby *)arg0, 7, 0, S32(v, 0x47C), 1.0f);
        }
        f10 = F32(v, 0x240) / F32(v, 0x1B8);
        if (f10 < 0.7f) {
            f10 = 0.7f;
        }
        F32(arg0, 0x48) = F32(PTR(v, 0x550), 0x48) = f10 * 0.9f;
        if (U8(v, 0x490) != 0 && (U8(arg0, 0x60) & 2)) {
            func_L01_00335F38(PTR(arg0, 0xB8), 1);
        }
        break;
    case 11:
        if (func_L01_004561B8(arg0) != 0) {
            func_L01_00335F38(PTR(arg0, 0xB8), 0);
            func_L01_0045BD78(arg0, 0.0096f, 0.15f, 0.0050265486f, 0.50265485f);
            func_L01_003CABE8((Moby *)arg0, 6, 0, S32(v, 0x47C), 1.0f);
        }
        c11 = PTR(PTR(arg0, 0xB8), 0x68);
        if (U8(v, 0x558) == 0) {
            func_L01_0045A9F0(arg0);
        }
        func_L01_00448890(arg0 + 0xF8, func_0038D160(F32(v, 0x4A0) - F32(arg0, 0x10), F32(v, 0x4A4) - F32(arg0, 0x14)), c11 + 0x74, F32(v, 0x1A4), F32(v, 0x1A8), F32(v, 0x1AC), 0);
        f11 = (F32(c11, 0x74) / F32(v, 0x1AC)) * 6.0f;
        F32(PTR(v, 0x550), 0x48) = f11;
        F32(arg0, 0x48) = f11;
        if (U8(v, 0x490) != 0 && (U8(arg0, 0x60) & 2)) {
            func_L01_00335F38(PTR(arg0, 0xB8), 1);
        }
        break;
    case 12:
        if (func_L01_004561B8(arg0) != 0) {
            func_L01_00335F38(PTR(arg0, 0xB8), 0);
            func_L01_003CABE8((Moby *)arg0, 2, 1, S32(v, 0x47C), 1.0f);
        }
        if (U8(v, 0x558) == 0) {
            func_L01_0045A9F0(arg0);
        }
        if (func_L01_0044E1B8(PTR(v, 0x550), 0.0f) != 0) {
            func_L01_003CAC78(arg0);
        }
        if (U8(arg0, 0x60) & 2) {
            F32(arg0, 0x48) = func_L01_00443A18(0.0f, 0.25f) + 1.0f;
        }
        if (U8(v, 0x490) != 0 && (U8(arg0, 0x60) & 2)) {
            func_L01_00335F38(PTR(arg0, 0xB8), 1);
        }
        break;
    case 14:
        if (func_L01_004561B8(arg0) != 0) {
            func_L01_0045BD78(arg0, 0.0096f, 0.15f, 0.0050265486f, 0.50265485f);
            F32(v, 0x474) = F32(arg0, 0xF8);
            F32(v, 0x478) = 0.0f;
        }
        turn = 0;
        started = 0;
        func_L01_00335F38(PTR(arg0, 0xB8), 0);
        c14 = PTR(PTR(arg0, 0xB8), 0x68);
        if (U8(v, 0x558) == 0) {
            func_L01_0045A9F0(arg0);
        }
        F32(v, 0x478) = func_0038DB00(func_0038D160(F32(v, 0x4A0) - F32(arg0, 0x10), F32(v, 0x4A4) - F32(arg0, 0x14)), F32(v, 0x474));
        if (func_0038DBA0(func_0038D160(F32(v, 0x4A0) - F32(arg0, 0x10), F32(v, 0x4A4) - F32(arg0, 0x14)), F32(v, 0x474)) > 1.0471976f) {
            turn = 1;
        }
        if (turn != 0) {
            F32(v, 0x538) = func_0038DB00(func_0038D160(F32(v, 0x4A0) - F32(arg0, 0x10), F32(v, 0x4A4) - F32(arg0, 0x14)), F32(arg0, 0xF8));
            if ((U8(PTR(v, 0x550), 0x60) & 2) && U8(PTR(v, 0x550), 0x43) != 0) {
                func_003C3A10((Moby *)PTR(v, 0x550), 0, 0, S32(v, 0x47C));
            }
            F32(PTR(v, 0x550), 0x48) = 1.0f;
        } else {
            F32(v, 0x538) = F32(v, 0x478);
            if (U8(PTR(v, 0x550), 0x43) != 2 || func_L01_0044E1B8(PTR(v, 0x550), 6.0f) != 0) {
                func_003C3A10((Moby *)PTR(v, 0x550), 2, 0, S32(v, 0x47C));
                started = 1;
            }
            F32(PTR(v, 0x550), 0x48) = 0.5f;
        }
        if (turn != 0) {
            if (U8(arg0, 0x43) != 6) {
                func_003C3A10((Moby *)arg0, 6, 0, S32(v, 0x47C));
            }
            if (func_0038DBA0(F32(arg0, 0xF8), func_0038D160(F32(v, 0x4A0) - F32(arg0, 0x10), F32(v, 0x4A4) - F32(arg0, 0x14))) > 0.08726646f) {
                func_L01_00448890(arg0 + 0xF8, func_0038D160(F32(v, 0x4A0) - F32(arg0, 0x10), F32(v, 0x4A4) - F32(arg0, 0x14)), c14 + 0x74, F32(v, 0x1A4), F32(v, 0x1A8), F32(v, 0x1AC), 0);
            } else {
                F32(v, 0x474) = F32(arg0, 0xF8);
            }
            f14 = (F32(c14, 0x74) / F32(v, 0x1AC)) * 6.0f;
        } else {
            if (U8(arg0, 0x43) != 2 || func_L01_0044E1B8(arg0, 6.0f) != 0) {
                func_003C3A10((Moby *)arg0, 2, U8(PTR(v, 0x550), 0x41), S32(v, 0x47C));
                started = 1;
            }
            f14 = F32(PTR(v, 0x550), 0x48);
        }
        F32(arg0, 0x48) = f14;
        if (turn == 0 && func_L01_0044E1B8(PTR(v, 0x550), 0.0f) != 0) {
            func_L01_003CAC78(arg0);
        }
        if (U8(arg0, 0x43) != 2 && (U8(arg0, 0x60) & 2)) {
            F32(arg0, 0x48) = func_L01_00443A18(0.0f, 0.25f) + 1.0f;
        }
        if (U8(v, 0x490) != 0 && (U8(arg0, 0x43) != 2 || started != 0)) {
            func_L01_00335F38(PTR(arg0, 0xB8), 1);
        }
        break;
    case 15:
        if (func_L01_004561B8(arg0) != 0) {
            func_L01_00335F38(PTR(arg0, 0xB8), 0);
            func_L01_0045BD78(arg0, 0.0096f, 0.15f, 0.0050265486f, 0.50265485f);
            func_L01_003CABE8((Moby *)arg0, 9, 0, S32(v, 0x47C), 1.0f);
            func_0038CE20((f32 *)(v + 0x230), arg0 + 0xC0, (D_001D545C == 1 && S16(PTR(arg0, 0xB8), 0xB2) == 0x1A) ? 0.24000001f : 0.16000001f);
            F32(v, 0x238) = (D_001D545C == 1 && S16(PTR(arg0, 0xB8), 0xB2) == 0x1A) ? 0.66f : 0.6f;
            S32(v, 0x268) = -1;
            qzero(v + 0x1E0);
            S32(v, 0x220) = 0;
            S32(v, 0x218) = 0;
            S32(v, 0x21C) = 0;
        }
        f15 = F32(v, 0x238) - 0.012f;
        F32(v, 0x238) = f15;
        F32(v, 0x230) *= 0.99f;
        F32(v, 0x234) *= 0.99f;
        if (f15 < -0.8000001f) {
            F32(v, 0x238) = -0.8000001f;
        }
        if (F32(arg0, 0x18) < F32(PTR(PTR(PTR(arg0, 0xB8), 0xB8), 0x68), 0x88)) {
            func_L01_004450F0((M3C7568 *)arg0, 0x1C, -1);
        }
        if (func_L01_0045C2A0(arg0, 10.0f, 17.0f, 22.0f) != 0) {
            F32(arg0, 0x48) = 1.0f;
            if (U8(v, 0x558) == 0) {
                func_L01_0045A9F0(arg0);
            }
            if (U8(v, 0x490) != 0) {
                func_L01_00335F38(PTR(arg0, 0xB8), 1);
            }
        }
        break;
    case 16:
        if (func_L01_004561B8(arg0) != 0) {
            func_L01_00335F38(PTR(arg0, 0xB8), 0);
            F32(v, 0x484) += func_003824E0(-0.08726646f, 0.08726646f);
            F32(v, 0x230) = func_0038D098(F32(v, 0x484)) * 0.20000002f;
            f16 = func_0038D0B0(F32(v, 0x484)) * 0.20000002f;
            S32(v, 0x220) = 0;
            S32(v, 0x218) = 0;
            qzero(v + 0x1E0);
            S32(v, 0x21C) = 0;
            F32(v, 0x234) = f16;
            F32(v, 0x238) = 0.16000001f;
            S32(v, 0x268) = -1;
            func_L01_003CABE8((Moby *)arg0, 0xE, 2, S32(v, 0x47C), 1.0f);
        }
        func_L01_003CBB40(arg0, v);
        if (U8(v, 0x490) != 0 && func_L01_0044E1B8(arg0, 10.0f) != 0) {
            func_L01_00335F38(PTR(arg0, 0xB8), 1);
        }
        break;
    case 17:
        if (func_L01_004561B8(arg0) != 0) {
            func_L01_00335F38(PTR(arg0, 0xB8), 0);
            func_L01_003CABE8((Moby *)arg0, 0xF, 0, S32(v, 0x47C), 1.0f);
        }
        func_L01_003CBB40(arg0, v);
        if (U8(v, 0x490) != 0 && (U8(arg0, 0x60) & 2)) {
            func_L01_00335F38(PTR(arg0, 0xB8), 1);
        }
        break;
    case 18:
        if (func_L01_004561B8(arg0) != 0) {
            func_L01_00335F38(PTR(arg0, 0xB8), 0);
            S32(v, 0x554) = 0;
            func_L01_003CABE8((Moby *)arg0, 0x10, 0, S32(v, 0x47C), func_003824E0(0.5f, 0.6f));
        }
        func_L01_003CBB40(arg0, v);
        if (func_L01_004395E0(arg0) > 8.0f) {
            func_L01_00404A10(func_L01_003CBEF0, arg0);
            S32(v, 0x554) += 1;
        }
        func_L04_003E1D80(arg0, v);
        if (U8(v, 0x490) != 0 && func_L01_0044E1B8(arg0, 16.0f) != 0) {
            func_L01_00335F38(PTR(arg0, 0xB8), 1);
        }
        break;
    case 19:
        if (func_L01_004561B8(arg0) != 0) {
            func_L01_00335F38(PTR(arg0, 0xB8), 0);
            func_L01_003CABE8((Moby *)arg0, 0x11, 0, S32(v, 0x47C), 1.0f);
        }
        func_L01_003CBB40(arg0, v);
        func_L01_00404A10(func_L01_003CBEF0, arg0);
        func_L04_003E1D80(arg0, v);
        break;
    case 20:
        if (func_L01_004561B8(arg0) != 0) {
            func_L01_00335F38(PTR(arg0, 0xB8), 0);
            S32(v, 0x554) = 0;
            S32(v, 0x1C8) &= ~1;
            func_L01_003CABE8((Moby *)arg0, 0x12, 0, S32(v, 0x47C), 1.0f);
        }
        if (U8(v, 0x558) == 0) {
            func_L01_0045A9F0(arg0);
        }
        func_L01_00404A10(func_L01_003CBEF0, arg0);
        S32(v, 0x554) += 1;
        func_L04_003E1D80(arg0, v);
        if (U8(v, 0x490) != 0 && func_L01_0044E1B8(arg0, 11.0f) != 0) {
            func_L01_00335F38(PTR(arg0, 0xB8), 1);
        }
        break;
    case 21:
        if (func_L01_004561B8(arg0) != 0) {
            func_L01_00335F38(PTR(arg0, 0xB8), 0);
            func_L01_003CABE8((Moby *)arg0, 0xB, 0, S32(v, 0x47C), 1.0f);
        }
        if (U8(v, 0x490) != 0 && func_L01_0044E1B8(arg0, 7.0f) != 0) {
            func_L01_00335F38(PTR(arg0, 0xB8), 1);
        }
        break;
    case 22:
        if (func_L01_004561B8(arg0) != 0) {
            func_L01_00335F38(PTR(arg0, 0xB8), 0);
            func_L01_003CABE8((Moby *)arg0, 0xC, 0, S32(v, 0x47C), 1.0f);
        }
        if (U8(v, 0x490) != 0 && (U8(arg0, 0x60) & 2)) {
            func_L01_00335F38(PTR(arg0, 0xB8), 1);
        }
        break;
    case 23:
        if (func_L01_004561B8(arg0) != 0) {
            func_L01_00335F38(PTR(arg0, 0xB8), 0);
            func_L01_003CABE8((Moby *)arg0, 0xD, 0, S32(v, 0x47C), 1.0f);
        }
        if (U8(v, 0x490) != 0 && func_L01_0044E1B8(arg0, 7.0f) != 0) {
            func_L01_00335F38(PTR(arg0, 0xB8), 1);
        }
        break;
    case 24:
        if (func_L01_004561B8(arg0) != 0) {
            func_L01_00335F38(PTR(arg0, 0xB8), 0);
            if (U8(arg0, 0xBC) == 0) {
                func_L01_0045BD78(arg0, 0.0096f, 0.15f, 0.0050265486f, 0.50265485f);
                func_L01_003CABE8((Moby *)arg0, 6, 0, S32(v, 0x47C), 1.0f);
            } else {
                func_L01_003CABE8((Moby *)arg0, 3, 0, S32(v, 0x47C), 1.0f);
            }
        }
        if (U8(arg0, 0xBC) == 0) {
            c24 = PTR(PTR(arg0, 0xB8), 0x68);
            if (U8(v, 0x558) == 0) {
                func_L01_0045A9F0(arg0);
            }
            func_L01_00448890(arg0 + 0xF8, func_0038D160(F32(v, 0x4A0) - F32(arg0, 0x10), F32(v, 0x4A4) - F32(arg0, 0x14)), c24 + 0x74, F32(v, 0x1A4), F32(v, 0x1A8), F32(v, 0x1AC), 0);
            f24 = (F32(c24, 0x74) / F32(v, 0x1AC)) * 6.0f;
            F32(PTR(v, 0x550), 0x48) = f24;
            F32(arg0, 0x48) = f24;
            if (func_0038DBA0(F32(arg0, 0xF8), func_0038D160(F32(v, 0x4A0) - F32(arg0, 0x10), F32(v, 0x4A4) - F32(arg0, 0x14))) <= 0.034906585f) {
                U8(arg0, 0xBC) = 1;
                func_L01_004450F0((M3C7568 *)arg0, 0x18, -1);
            }
        } else {
            if (func_L01_0044E1B8(arg0, 15.0f) != 0) {
                func_003C2F58(PTR(v, 0x550), 1, &spA0.x);
                vec_sub_ba(&spB0, v + 0x4A0, arg0 + 0x10);
                func_0038CF68(&sp90, &spB0, 0.36f);
                sp90.z = func_L01_00447878(&spA0, v + 0x4A0, 0, 0.36f, -0.0044f);
                func_L01_00362610(&spA0, &sp90, 0, 0, 1);
            }
            if (U8(arg0, 0x60) & 2) {
                func_L01_00335F38(PTR(arg0, 0xB8), 1);
            }
        }
        break;
    case 25:
        if (func_L01_004561B8(arg0) != 0) {
            func_L01_00335F38(PTR(arg0, 0xB8), 0);
            func_L01_003CABE8((Moby *)arg0, 0x13, 0, S32(v, 0x47C), 1.0f);
            S32(v, 0x55C) = D_L01_001DFB40 + func_00382498(0xC, 0x19);
        } else {
            func_L01_00335F38(PTR(arg0, 0xB8), 1);
        }
        if (S32(v, 0x55C) < D_L01_001DFB40) {
            func_003C2EC0(PTR(v, 0x550), 0, mtx);
            func_0038CE20(&sp90.x, &mtx[1], 0.2f);
            vec_add_ab(&sp90, &sp90, &mtx[3]);
            f25 = func_003824E0(0.15f, 0.3f);
            func_L01_003303B8(&sp90, f25, 0, func_00382498(0, 1), 2, 0, (func_0013D3E0() & 2) >> 1, 2, 0, 0.0f, 0.0f, 0.0f, 0, 0, 0, 0, 0, 0, 0, 0, 0xF78E38, 0xF76300, 0xFF7F40, 0xFF2000, 0xFF8F00, 0xFF6430, 0x7FFFA060, 0x280000FF, 0x3064FF, 0);
            S32(v, 0x55C) = D_L01_001DFB40 + func_00382498(5, 0x15);
        }
        break;
    case 26:
        if (func_L01_004561B8(arg0) != 0) {
            func_L01_00335F38(PTR(arg0, 0xB8), 0);
            func_L01_003CABE8((Moby *)arg0, 0x14, 0, S32(v, 0x47C), 1.0f);
        } else {
            func_L01_00335F38(PTR(arg0, 0xB8), 1);
        }
        Q128(arg0, 0x10) = Q128(PTR(arg0, 0xB8), 0x10);
        Q128(arg0, 0xF0) = Q128(PTR(arg0, 0xB8), 0xF0);
        break;
    case 27:
        if (func_L01_004561B8(arg0) != 0) {
            func_L01_00335F38(PTR(arg0, 0xB8), 0);
            if (PTR(v, 0x550) != 0) {
                func_003C3A10((Moby *)PTR(v, 0x550), U8(arg0, 0x43), U8(arg0, 0x41), S32(v, 0x47C));
            }
        }
        hit = func_L01_00454370(arg0, v + 0xD0);
        if ((hit & 1) || F32(v, 0x30) <= 0.0f) {
            func_L01_004450F0((M3C7568 *)arg0, 0x1C, -1);
        } else if (hit & 2) {
            func_L01_00335F38(PTR(arg0, 0xB8), 1);
        }
        break;
    case 28:
        func_L01_00451FE0(arg0, 0xF, D_L01_001D66B0, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
        func_L01_00451FE0(PTR(v, 0x550), 0xF, D_L01_001D66B0, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
        func_003A52A0(5, 0, PTR(v, 0x550));
        func_L01_003303B8(arg0 + 0x10, 1.0f, 0, 0x19, 0x14, 0x14, 0x14, 0x2D, 0, 0.0f, 0.0f, 0.0f, 0, 0, 0, 0, 0, 0, 0x10000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
        func_L01_003362B0(PTR(arg0, 0xB8), 1);
        break;
    }
}
#undef U8
#undef U16
#undef S16
#undef S32
#undef F32
#undef PTR
#undef Q128
/* localdecomp:end func_L04_003DE410 */
