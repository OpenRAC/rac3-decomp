/* functional: high. 238 diffs, allocation/scheduling; every call, argument, offset and constant re-read against retail asm block by block. */
#include "common.h"
typedef struct {
    f32 v[4];
} __attribute__((aligned(16))) Vec4_0039E0C8;
/* localdecomp:start func_L01_00397A28 */
#include "vu0.h"
extern s32 D_001DE0D0_sda;
__asm__(".extern D_001DE0D0_sda, 4");
extern u8 D_001425C0[];
extern Ent_003985C0 D_L01_002C5600[];
extern u8 D_001A4BE0[];
extern u8 D_001A52D0[];
extern s32 D_L01_001D673C[];
extern vu0_q D_L01_001EAA20[];
extern u8 D_L01_002A19F0[];
extern u8 D_L01_001E0140[];
u8 *func_L01_00397A28(u8 *owner, vu0_q *position, u8 *target, s32 unused, vu0_q *end)
{
    extern u8 *func_003C24B0(s32, s32);
    extern void func_0038CF68(Vec4_0039E0C8 *, Vec4_0039E0C8 *, f32);
    extern void func_0038CE20(f32 *, f32 *, f32);
    extern void func_0038CE90(void *, void *, void *);
    extern void func_L01_004CAC78(void *, void *, f32, f32, f32);
    extern f32 func_L01_00443A18(f32, f32);
    extern f32 func_00382538(void);
    extern void func_003C5180(void *, void *, s32);
    extern f32 func_0038CE68(void *, void *);
    extern u8 *func_00382348(void *);
    extern s32 func_003D3CB0(Vec4 *, s32 *, s32, s32, s32);
    extern void func_L01_00399D78(u8 *, u8 *);
    extern void func_003C7C38(void *);
    extern void func_L01_0044BE50(void *, void *, s32);
    extern s32 func_L01_004C85C8(void *, void *, f32, f32, f32);
    vu0_v4 destination, normal, projection;
    u8 *obj = func_003C24B0(0x1894, 0x80);
    u8 *s;
    u8 *hero;
    u8 *right;
    u8 *forward;
    u8 *velocity;
    f32 speed;
    if (obj != 0) {
        obj[0x30] = 255;
        obj[0x31] = 1;
        obj[0x20] = 0;
        *(s16 *)(obj + 0x32) = 255;
        *(u16 *)(obj + 0x34) |= 0x100;
        s = *(u8 **)(obj + 0x68);
        if ((u32)D_001DE0D0_sda >= 9) D_001DE0D0_sda = 0;
        *(s32 *)(s + 0x2C) = D_001DE0D0_sda;
        D_001DE0D0_sda = (D_001DE0D0_sda + 1) % 8;
        speed = *(f32 *)((u8 *)&D_L01_002C5600[D_001425C0[0x3F]] + 0x4C) * 0.020000001f;
        *(vu0_q *)(obj + 0x10) = *position;
        *(vu0_q *)&destination = *end;
        hero = D_001A4BE0;
        if (*(s16 *)(hero + 0x2874) && *(s32 *)(hero + 0x16B0) != 2) {
            func_0038CF68((Vec4_0039E0C8 *)(obj + 0xC0), (Vec4_0039E0C8 *)(owner + 0xD0), -1.0f);
            func_0038CE20((f32 *)(obj + 0xD0), (f32 *)(owner + 0xC0), -1.0f);
            *(vu0_q *)(obj + 0xE0) = *(vu0_q *)(owner + 0xE0);
        } else if (target) {
            vec_sub_ab(obj + 0xC0, &destination, obj + 0x10);
            forward = obj + 0xC0;
            func_0038CF68((Vec4_0039E0C8 *)forward, (Vec4_0039E0C8 *)forward, 1.0f);
            right = obj + 0xD0;
            func_0038CE90(right, forward, *(u8 **)(hero + 0x25C0) + 0xE0);
            func_0038CF68((Vec4_0039E0C8 *)right, (Vec4_0039E0C8 *)right, 1.0f);
            func_0038CE90(obj + 0xE0, right, forward);
        } else {
            u8 *camera = D_001A52D0;
            *(vu0_q *)(obj + 0xC0) = *(vu0_q *)camera;
            forward = obj + 0xC0;
            if (*(s32 *)(camera + 0xFC0))
                func_L01_004CAC78(forward, position, 1.0f, 75.0f, 1.3962634f);
            right = obj + 0xD0;
            func_0038CE90(right, forward, camera - 0x10);
            func_0038CF68((Vec4_0039E0C8 *)right, (Vec4_0039E0C8 *)right, 1.0f);
            func_0038CE90(obj + 0xE0, right, forward);
        }
        *(f32 *)(obj + 0xCC) = 0.0f;
        *(f32 *)(obj + 0xEC) = 0.0f;
        *(f32 *)(obj + 0xDC) = 0.0f;
        velocity = s + 0x30;
        *(u8 **)(s + 12) = owner;
        *(f32 *)(s + 32) = func_L01_00443A18(6.0f, 10.0f);
        *(f32 *)(s + 24) = speed;
        *(f32 *)(s + 40) = func_00382538();
        s[38] = 0;
        s[39] = 1;
        *(u8 **)(s + 16) = target;
        *(vu0_q *)velocity = *(vu0_q *)(obj + 0xC0);
        if (D_L01_001D673C[0]) {
            func_003C5180(obj + 0x10, &normal, 1);
            func_0038CE20((f32 *)&projection, (f32 *)&normal, func_0038CE68(&normal, velocity));
            vec_sub_ab(velocity, velocity, &projection);
        }
        if (target) {
            u8 *damage = func_00382348(target);
            if (damage) {
                *(u16 *)(damage + 30) |= 0x80;
                if (damage[11]) s[38] = 0;
            }
        }
        *(s16 *)(s + 36) = (s32)(75.0f / speed);
        *(vu0_q *)&normal = *(vu0_q *)(owner + 0x10);
        normal.z = ((f32 *)position)[2];
        if (func_003D3CB0((Vec4 *)&normal, (s32 *)position, 0, *(s32 *)(hero + 0x25C0), 0)) {
            obj[0xBC] = 1;
            *(vu0_q *)(obj + 0x10) = D_L01_001EAA20[0];
        }
        func_L01_00399D78(obj, D_L01_002A19F0 + (*(s32 *)(s + 0x2C) << 6));
        func_003C7C38(obj);
        func_L01_0044BE50(obj, D_L01_001E0140, 31);
        if (((u8 *)&D_L01_002C5600[D_001425C0[0x3F]])[1] >= 4)
            *(f32 *)(obj + 44) *= 4.0f;
        else
            *(f32 *)(obj + 44) *= 2.5f;
        *(s32 *)(s + 80) = func_L01_004C85C8(obj, 0, 1.0f, 1.0f, 1.0f);
    }
    return obj;
}
/* localdecomp:end func_L01_00397A28 */
