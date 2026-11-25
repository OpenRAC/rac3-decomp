/* Unlinked NTSC-U draft. 32 to 25 differences at the canonical level 09 placement after correcting the second VU subtraction. Saved-register assignments and argument and float scheduling remain. */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_U_L09_003C4A30 */
typedef int Q_4A30 __attribute__((mode(TI)));
typedef union { Q_4A30 q; f32 f[4]; } V_4A30;
typedef struct { V_4A30 pos; u8 pad[0x24D4]; s32 state; } G_4A30;
extern G_4A30 D_001A4CC0;
extern s32 D_001DFC40_sda, D_001D545C_sda;
extern f32 D_001DAA30_sda;
extern u8 D_0014275B[];
extern f32 D_L09_002F1DD0[];
extern void func_003BDA38(void *, s32, void *);
extern u8 *func_L01_004E5BB8(void *, f32, f32, f32, f32, s32, s32);
extern f32 func_L01_0040C040(void *, void *);
extern void func_003883C8(s16 *);
extern u8 *func_0037E0B8(void *);
extern f32 func_00388A28(f32, f32);
extern f32 func_00388770(void *);
extern void func_00388830(void *, void *, f32);
extern s32 func_L01_00417EA0(void);
extern void func_0039FE80(s32, s32, void *);
extern void func_L09_003DDD48(void *, void *, void *, f32, s32);
extern f32 func_0037E250(f32, f32);
extern f32 func_00389380(f32, f32);
extern s32 func_0037E208(s32, s32);
extern f32 func_00388960(f32);
extern void func_L01_004455F0(void *, f32, void *, f32, f32, f32, s32);
extern f32 func_003893C8(f32, f32);
extern void func_00389018(void *, s32, f32);

static __inline__ void sub_4A30(V_4A30 *d, V_4A30 *a, V_4A30 *b) {
    __asm__("lqc2 vf1, %1\n\tlqc2 vf2, %2\n\tvsub.xyz vf1, vf1, vf2\n\tsqc2 vf1, %0"
        : "=m"(*d) : "m"(*a), "m"(*b) : "vf1", "vf2");
}

void func_U_L09_003C4A30(u8 *m) {
    V_4A30 temp, direction, origin, target;
    u8 *p = *(u8 **)(m + 0x68);
    u8 *a, *b, *extra, *extra2;
    V_4A30 *op;
    f32 yaw, accel, speed, limit, shot;
    if (*(s32 *)(p + 0x758) == -1) return;
    if (D_001DFC40_sda % 45 == 0) {
        temp.q = D_001A4CC0.pos.q;
        func_003BDA38(m, *(s16 *)(p + 0x762) ? 18 : 17, &origin);
        op = &origin;
        D_001A4CC0.pos.q = origin.q;
        if (D_001A4CC0.state == 49) {
            a = func_L01_004E5BB8(&target, 18.0f, *(f32 *)(m+0xF8), 2.3561945f, 0.5f, 5, 1);
            b = func_L01_004E5BB8(&target, 30.0f, *(f32 *)(p+0x724), 2.3561945f, 0.5f, 5, 1);
            if (!a) *(u8 **)(p+0x75C) = b;
            else if (!b || func_L01_0040C040(op, b+0x10) > func_L01_0040C040(op, a+0x10))
                *(u8 **)(p+0x75C) = a;
            else *(u8 **)(p+0x75C) = b;
        } else {
            *(u8 **)(p+0x75C) = func_L01_004E5BB8(&target, 30.0f, *(f32 *)(p+0x724), 2.3561945f, 0.5f, 5, 1);
        }
        D_001A4CC0.pos.q = temp.q;
    }
    func_003883C8((s16 *)(p+0x716));
    if (*(u8 **)(p+0x75C)) {
        sub_4A30(&temp, (V_4A30 *)(*(u8 **)(p+0x75C)+0x10), (V_4A30 *)(m+0x10));
        extra = func_0037E0B8(*(u8 **)(p+0x75C));
        if (extra) temp.f[2] += *(f32 *)(extra+0x10);
        yaw = func_00388A28(temp.f[0], temp.f[1]);
        if (func_00388770(&temp) > 30.0f) *(u8 **)(p+0x75C) = 0;
        accel=2000.0f; speed=3000.0f; limit=300.0f;
        *(f32 *)(p+0x764) = yaw;
        if (*(s16 *)(p+0x716) <= 0 && *(u8 **)(p+0x75C)) {
            op = (V_4A30 *)origin.f;
            func_003BDA38(m, *(s16 *)(p+0x762) ? 18 : 17, op);
            extra2 = func_0037E0B8(*(u8 **)(p+0x75C));
            target.q = ((V_4A30 *)(*(u8 **)(p+0x75C)+0x10))->q;
            if (extra2) target.f[2] += *(f32 *)(extra2+0x10);
            vec_sub_ab(&direction, &target, &origin);
            func_00388830(&direction, &direction, 0.5f);
            shot=10.0f;
            if (func_L01_00417EA0()) {
                if (D_001D545C_sda == 7 && D_0014275B[0]) shot = D_001DAA30_sda * shot;
                else shot = D_L09_002F1DD0[D_001D545C_sda] * shot;
            }
            func_0039FE80(3, 0, m);
            func_L09_003DDD48(m, op, &direction, shot, 0x10000);
            *(s16 *)(p+0x716)=10;
            *(u8 *)(p+0x7AE)=1;
            *(u16 *)(p+0x762)^=1;
        }
    } else {
        f32 oscillation;
        accel=200.0f; speed=5000.0f; limit=60.0f;
        if (--*(s16 *)(p+0x760) <= 0) {
            f32 turn=func_0037E250(-1.5707964f, 1.5707964f);
            if (turn > -0.5f && turn <= 0.0f) turn=-0.5f;
            else if (turn < 0.5f && turn > 0.0f) turn=0.5f;
            *(f32 *)(p+0x764)=func_00389380(*(f32 *)(p+0x764), turn);
            *(s16 *)(p+0x760)=func_0037E208(30, 300);
        }
        *(f32 *)(p+0x770)=func_00389380(*(f32 *)(p+0x770), 0.058177646f);
        oscillation = func_00388960(*(f32 *)(p+0x770))*0.019000f;
        *(f32 *)(p+0x764)+=oscillation;
    }
    func_L01_004455F0(p+0x724, *(f32 *)(p+0x764), p+0x76C,
        (accel*0.017453292f)*0.00027777778f, (speed*0.017453292f)*0.00027777778f,
        (limit*0.017453292f)*0.016666668f, 0);
    yaw=func_003893C8(*(f32 *)(p+0x724), *(f32 *)(m+0xF8));
    func_00389018(p+0x570, 2, yaw);
}
/* localdecomp:end func_U_L09_003C4A30 */
