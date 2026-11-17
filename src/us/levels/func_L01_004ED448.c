#include "common.h"

/* NTSC-U counterpart of func_L01_004F1220 (src/levels/shared/L01_004EF3A8.c) */
#include "vu0.h"
#include "vu0.h"
#include "vu0.h"
extern void func_00388830(void *, void *, f32);
typedef int Q_004F05F0 __attribute__((mode(TI)));
extern f32 func_00388730(void *, void *);

/* localdecomp:start func_L01_004ED448 */
#include "vu0.h"
typedef struct {
    u8 p0[0xF0]; vu0_v4 velocity;
    u8 p100[0x140-0x100]; vu0_q copied;
    u8 p150[0x174-0x150]; f32 speed_a; f32 speed_b;
    u8 p17c[0x190-0x17c]; vu0_q target;
    f32 angle; u8 p1a4[0x1b0-0x1a4]; f32 target_speed; f32 speed;
    u8 p1b8[0x2a7-0x1b8]; u8 b2a7;
    u8 p2a8[0x36a-0x2a8]; s16 h36a;
    u8 p36c[0x4f4-0x36c]; s16 h4f4;
    u8 p4f6[0x9e0-0x4f6]; vu0_q q9e0;
    u8 p9f0[0x1434-0x9f0]; s16 lock;
    u8 p1436[0x16b0-0x1436]; s32 camera;
    u8 p16b4[0x25c4-0x16b4]; s32 state;
    u8 p25c8[4]; s32 state_type;
    u8 p25d0[0x25f4-0x25d0]; u8 mode;
} Hero_004F1220;
extern Hero_004F1220 D_001A4BE0_004ED448;
extern vu0_v4 D_001A4CD0_004ED448;
extern vu0_q D_001A4D70_004ED448;
void func_L01_004ED448(f32 delta) {
    extern f32 func_00388960(f32);
    extern f32 func_00388978(f32);
    extern f32 func_003887A0(void *);
    extern void func_00388880(void *, void *, f32);
    extern f32 func_L01_004EC818(Q_004F05F0 *);
    extern void func_L01_0050D530(void *, void *, f32);
    extern void func_00388830(void *, void *, f32);
    extern f32 func_00388730(void *, void *);
    extern f32 func_L01_0050D430(void *);
    extern void func_L01_0050D5B0(void *, void *, f32);
    extern s32 func_L01_0045D358(s32, s32, s32, s32);
    vu0_v4 v;
    vu0_v4 saved;
    vu0_v4 projected;
    vu0_v4 *velocity;
    vu0_q *target;
    Hero_004F1220 *tail;
    f32 angle, speed, dot, a, b;
    s32 locked;
    switch (D_001A4BE0_004ED448.mode) {
    case 0:
        angle = D_001A4BE0_004ED448.angle;
        speed = D_001A4BE0_004ED448.target_speed;
        if (D_001A4BE0_004ED448.state_type == 4 && D_001A4BE0_004ED448.h4f4 != 0 && D_001A4BE0_004ED448.b2a7 != 0) speed = 0.083333336f;
        if (D_001A4BE0_004ED448.h36a != 0 && D_001A4BE0_004ED448.state == 14 && speed > 0.0166666675f) speed = 0.0166666675f;
        v.x = func_00388960(angle) * speed;
        v.y = func_00388978(angle) * speed;
        v.z = D_001A4BE0_004ED448.velocity.z;
        dot = -(D_001A4BE0_004ED448.velocity.x * v.x + D_001A4BE0_004ED448.velocity.y * v.y);
        a = func_003887A0(&v);
        b = func_003887A0(&D_001A4BE0_004ED448.velocity);
        if (a == 0.0f || b == 0.0f) dot = 0.0f;
        else { dot /= a; dot /= b; }
        if (D_001A4BE0_004ED448.state == 176) dot += 0.5f;
        else { dot += 1.0f; dot *= 1.5f; }
        if (dot > 3.0f) dot = 3.0f;
        if (dot < 1.0f) dot = 1.0f;
        velocity = &D_001A4CD0_004ED448;
        vec_sub_ab(&v, &v, &D_001A4CD0_004ED448);
        delta *= dot;
        if (delta < func_003887A0(&v)) func_00388880(&v, &v, delta);
        vec_add_ab(velocity, velocity, &v);
        *(vu0_q *)((u8 *)velocity + 0x50) = *(vu0_q *)velocity;
        *(vu0_q *)&saved = *(vu0_q *)((u8 *)velocity + 0x8F0);
        tail = (Hero_004F1220 *)((u8 *)velocity - 0xF0);
        b = func_L01_004EC818((Q_004F05F0 *)&saved);
        locked = tail->lock;
        tail->speed = tail->speed_b - b;
        break;
    case 1:
    case 2:
        target = &D_001A4D70_004ED448;
        *(vu0_q *)&saved = *target;
        speed = *(f32 *)((u8 *)target + 0x20);
        func_L01_0050D530(&v, &saved, 0.0f);
        target = (vu0_q *)((u8 *)target - 0xA0);
        func_00388830(&v, &v, speed);
        func_L01_0050D530(&projected, target, 0.0f);
        dot = -func_00388730(&projected, &v);
        a = func_L01_0050D430(&v);
        b = func_L01_0050D430(target);
        if (a == 0.0f || b == 0.0f) dot = 0.0f;
        else { dot /= a; dot /= b; }
        dot += 1.0f;
        dot *= 1.5f;
        if (dot > 3.0f) dot = 3.0f;
        if (dot < 1.0f) dot = 1.0f;
        vec_sub_ab(&v, &v, &D_001A4CD0_004ED448);
        func_L01_0050D530(&v, &v, 0.0f);
        delta *= dot;
        if (delta < func_L01_0050D430(&v)) func_L01_0050D5B0(&v, &v, delta);
        vec_add_ab(&D_001A4CD0_004ED448, &D_001A4CD0_004ED448, &v);
        tail = (Hero_004F1220 *)((u8 *)&D_001A4CD0_004ED448 - 0xF0);
        locked = tail->lock;
        tail->speed = tail->speed_b;
        break;
    default:
        return;
    }
    if (locked != 0 || (tail->camera == 1 && func_L01_0045D358(40, 2, 0, 0) != 0)) tail->speed = tail->speed_a;
}
/* localdecomp:end func_L01_004ED448 */
