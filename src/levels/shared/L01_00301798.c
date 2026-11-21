#include "common.h"
#include "vu0.h"

typedef int u128_t __attribute__((mode(TI)));
typedef union {
    u128_t q;
    f32 f[4];
} Vec4;
typedef int s128 __attribute__((mode(TI)));

/* declared by functions of L01_003002A8.c, which this file was cut from */
extern u8 *func_003C24B0(s32, s32);

/* localdecomp:start func_L01_00301798 */
extern u8 *func_003C24B0(s32, s32);
extern s32 D_00142668[];

u8 *func_L01_00301798(u8 *src, s32 a1, s32 a2, s32 a3, s32 a4) {
    u8 *m;
    u8 *pv;
    s32 v;

    if ((s8)src[32] < 0)
        return 0;
    m = func_003C24B0(806, 192);
    if (m != 0) {
        pv = *(u8 **)(m + 104);
        m[48] = 64;
        m[32] = 0;
        *(u8 **)(m + 184) = src;
        pv[87] = a1;
        *(s32 *)(pv + 128) = a2;
        *(s32 *)(pv + 132) = a3;
        *(s32 *)(pv + 136) = a4;
        if (a2 == 0 && a3 == 0 && a4 == 0) {
            v = D_00142668[0];
            *(s32 *)(pv + 140) = 0;
            *(s32 *)(pv + 132) = v / 4;
            *(s32 *)(pv + 128) = v / 3;
            *(s32 *)(pv + 136) = v / 5;
        } else {
            *(s32 *)(pv + 140) = 1;
        }
        *(u16 *)(m + 52) |= 65;
        *(s32 *)(m + 152) = 0;
        *(u128_t *)(m + 16) = *(u128_t *)(src + 16);
    }
    return m;
}
/* localdecomp:end func_L01_00301798 */

LINKER_REMNANT("asm/levels", func_L01_003018B0);

/* localdecomp:start func_L01_003018B8 */
typedef struct {
    u8 pad0[0x18];
    u8 *object;
    u8 pad1c[0xc];
    f32 height;
} Collision_003018B8;
extern Collision_003018B8 D_L01_001EAA00_003018B8;
extern f32 D_L01_001EAA28_003018B8[];
void func_L01_003018B8(u8 *object)
{
    extern s32 func_L01_0044C108(void *);
    extern void func_L01_004450F0(void *, s32, s32);
    extern void func_L01_0044C998(void *, void *, void *, void *, void *, void *);
    extern void func_003C5278(Vec4 *, Vec4 *, Vec4 *, f32);
    extern s32 func_003D3CB0(Vec4 *, s32 *, s32, s32, s32);
    extern s32 func_003C4B50(void *);
    extern s32 func_003C4D58(void *);
    extern void func_L01_0044CB18(void *, void *, void *, void *, void *, void *);
    Vec4 bottom, top, zero;
    u8 *state = *(u8 **)(object + 0x68);
    Vec4 *position = (Vec4 *)(object + 0x10);
    s32 collided = 0;
    f32 ground;
    if (!func_L01_0044C108(position)) {
        func_L01_004450F0(object, 5, -1);
        return;
    }
    if (*(void **)(state + 0xc)) {
        qzero(&zero);
        func_L01_0044C998(object, *(void **)(state + 0xc), state + 0x70, &zero, position, &zero);
    }
    bottom = *position;
    func_003C5278(position, &bottom, &bottom, -0.5f);
    top = bottom;
    func_003C5278(position, &top, &top, 1.5f);
    if (func_003D3CB0(&bottom, (s32 *)&top, 2, (s32)object, 0)) {
        collided = 1;
        ground = D_L01_001EAA28_003018B8[0];
    } else {
        ground = top.f[2];
    }
    if (collided && D_L01_001EAA00_003018B8.object) {
        if (func_003C4B50(D_L01_001EAA00_003018B8.object)) {
            *(f32 *)(state + 0x10) = *(f32 *)(D_L01_001EAA00_003018B8.object + 0x10);
            *(f32 *)(object + 0x10) = *(f32 *)(state + 0x10);
            *(f32 *)(state + 0x14) = *(f32 *)(D_L01_001EAA00_003018B8.object + 0x14);
            *(f32 *)(object + 0x14) = *(f32 *)(state + 0x14);
            *(f32 *)(object + 0x18) = D_L01_001EAA00_003018B8.height;
            *(Vec4 *)(state + 0x10) = *(Vec4 *)(object + 0x10);
            func_003C5278((Vec4 *)(object + 0x10), (Vec4 *)(state + 0x10), (Vec4 *)(state + 0x10), -0.5f);
        } else if (!*(void **)(state + 0xc) && func_003C4D58(D_L01_001EAA00_003018B8.object)) {
            void *hit = D_L01_001EAA00_003018B8.object;
            *(void **)(state + 0xc) = hit;
            func_L01_0044CB18(object, hit, object + 0x10, object + 0xf0, state + 0x70, &zero);
        }
    }
    if (*(f32 *)(object + 0x18) <= ground) {
        *(f32 *)(object + 0x18) = ground;
        object[0xbc] = 0;
        *(s32 *)(state + 0x50) = 0;
    } else {
        object[0xbc] = 1;
        if (*(void **)(state + 0xc)) *(f32 *)(state + 0x78) -= *(f32 *)(state + 0x50);
        else *(f32 *)(object + 0x18) -= *(f32 *)(state + 0x50);
        *(f32 *)(state + 0x50) += 0.00392f;
        *(f32 *)(state + 0x50) = *(f32 *)(state + 0x50) > 0.3f ? 0.3f : *(f32 *)(state + 0x50);
    }
}
/* localdecomp:end func_L01_003018B8 */
