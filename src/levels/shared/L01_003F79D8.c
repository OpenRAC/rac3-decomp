#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L01_003F79D8 */
extern void func_L01_00439880(u8 *, s32 *, s32 *);
extern s32 func_L01_00439A68(u8 *, s32);
extern u8 *func_003C24B0(s32, s32);
extern u8 *func_L01_00448FF0(u8 *);
extern void func_L01_00456160(u8 *, u8 *);
extern void func_L01_0044E820(u8 *, s32);
extern void func_0038D308(u8 *, u8 *);
extern void func_003C7DD8(u8 *);
extern f32 func_0038D0B0(f32);
extern void func_L01_00443B88(f32 *, f32, f32);
extern void func_003C29B0(u8 *);
extern void func_003C6FE0(u8 *);
extern u8 D_L01_002FFF00[];
extern void func_L01_003F7CE0(u8 *m, s32 mode, s32 index, vu0_q *a, vu0_q *b, f32 f, s32 byte, s32 half);

u8 *func_L01_003F79D8(u8 *parent, s32 kind, s32 id, s32 count, vu0_q *pos, vu0_q *rot, vu0_q *vel, u8 fl, f32 sa, f32 sb, s32 life, s32 z, s32 x80) {
    vu0_v4 q;
    s32 res[2];
    u8 *obj;
    u8 *a;
    s32 flagsw;

    if (id != 0xCDB && (u32)(kind - 1) < 2) {
        func_L01_00439880(parent, &res[0], &res[1]);
        if (((res[0] >> count) ^ 1) & 1) {
            return 0;
        }
        if (kind == 2 && func_L01_00439A68(parent, count) == 0) {
            return 0;
        }
    }
    obj = func_003C24B0(id, x80);
    flagsw = 0;
    a = func_L01_00448FF0(parent);
    if (a != 0) {
        {
            s32 hi = 0x80000000;
            s32 t = (a[5] << 8) | hi;
            flagsw = ((a[6] << 16) | t) | a[4];
        }
    }
    if (obj != 0) {
        func_L01_00456160(obj, parent);
        if (flagsw != 0) {
            func_L01_0044E820(obj, flagsw);
        }
        *(vu0_q *)(obj + 0x10) = *pos;
        *(vu0_q *)(obj + 0xF0) = *rot;
        func_0038D308(obj + 0xC0, obj + 0xF0);
        if (parent != 0) {
            *(f32 *)(obj + 0x2C) = *(f32 *)(*(u8 **)(obj + 0x24) + 0x24) * (*(f32 *)(parent + 0x2C) / *(f32 *)(*(u8 **)(parent + 0x24) + 0x24));
        }
        func_003C7DD8(obj);
        {
            u32 h = *(u16 *)(obj + 0x34) & 0xABDB;
            *(u16 *)(obj + 0x34) = h | 0x140;
            if (parent != 0) {
                if (*(u16 *)(parent + 0x34) & 0x800) {
                    *(u16 *)(obj + 0x34) = h | 0x940;
                }
                if (parent[0x7E] & 0x80) {
                    u8 b = (obj[0x7E] | 0x80) & 0x8F;
                    obj[0x7E] = b;
                    obj[0x7E] = b | (parent[0x7E] & 0x70);
                }
            }
        }
        *(s32 *)(obj + 0x98) = 0;
        *(u8 **)(*(u8 **)(obj + 0x68) + 0x54) = parent;
        sa = func_0038D0B0(sa * 0.017453292f * 0.020000001f * 0.5f);
        func_L01_00443B88(&q.x, sa, sa);
        sa = sa * sa;
        q.w = sqrt_asm(1.0f - sa);
        if (kind == 1) {
            if (parent != 0) {
                obj[0x42] = parent[0x43];
                obj[0x43] = parent[0x43];
            }
            func_003C29B0(obj);
            *(s32 *)(obj + 0x48) = 0;
            *(s32 *)(obj + 0x44) = 0;
            func_003C6FE0(obj);
        }
        func_L01_003F7CE0(obj, kind, count, vel, (vu0_q *)&q, sb, fl, life);
        if (*(u16 *)(obj + 0x7C) & 0x8000) {
            if (*(u16 *)(obj + 0x34) & 0x10) {
                *(u16 *)(obj + 0x34) &= 0xFFEF;
            }
        }
        *(u8 **)(obj + 0x64) = D_L01_002FFF00;
        *(u16 *)(obj + 0x34) &= 0xFFFD;
    }
    return obj;
}
/* localdecomp:end func_L01_003F79D8 */
