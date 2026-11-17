/* PAL near miss (Codex wave 10): near miss: 149 words differ with the file's flags.
 * Worker's note: 149 aligned instruction diffs, 704 vs 716 bytes, 00385228-03.log (metadata probe divs 2,2): fixed assembler emits literal-pool loads for 0.020000001 and 1.3962634 where retail has inline li.s; no alternate flags tried. VU scheduling and register differences ...
 */
#include "common.h"
/* localdecomp:start func_L01_00385228 */
#include "structs/weapon.h"
typedef int Q_00385228 __attribute__((mode(TI)));
typedef struct {
    u8 pad0[0x6F0];
    Q_00385228 aim;
    u8 pad700[0x16B0 - 0x700];
    s32 aiming;
    u8 pad16B4[0x2874 - 0x16B4];
    s16 mode;
} Hero_00385228;
extern Hero_00385228 D_001A4BE0;
extern u8 D_001425C0[];
extern struct WeaponRow D_L01_002C5600[];
extern Q_00385228 D_001A4C60;
extern f32 D_L01_001DDD98;
extern s32 D_L01_001DDD90, D_L01_001DDD94;
u8 *func_L01_00385228(Q_00385228 *position, u8 *owner, u8 *target)
{
    extern u8 *func_003C24B0(s32, s32);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_L01_004CB128(void *, void *, s32);
    extern void func_L01_004CAC78(void *, void *, f32, f32, f32);
    extern f32 *func_00382348(s32);
    extern s32 func_L01_00457458(s32, s32);
    extern void func_003C2880(void *);
    extern s32 func_L01_004C85C8(void *, s32, f32, f32, f32);
    extern void func_L01_00385EE0(u8 *);
    extern void func_L01_00404A10(void (*)(u8 *), void *);
    extern void func_003C7C38(void *);
    Q_00385228 temp;
    u8 *moby = func_003C24B0(0x1881, 0x80);
    u8 *vars;
    f32 speed;
    s32 ticks;
    if (moby) {
        vars = *(u8 **)(moby + 0x68);
        moby[0x30] = 255;
        *(u16 *)(moby + 0x34) = 0x100;
        moby[0x31] = 1;
        *(u16 *)(moby + 0x32) = 255;
        *(u8 **)(moby + 0xB8) = owner;
        moby[0x20] = 0;
        *(s32 *)(vars + 0x3C) = 0;
        speed = D_L01_002C5600[D_001425C0[0x2F]].shot_speed * 0.020000001f;
        if (D_001A4BE0.mode == 1) {
            func_0038CF68(vars + 0x20, owner + 0xD0, -speed);
        } else if (target) {
            func_L01_004CB128(&temp, target, 0);
            __asm__("lqc2 vf1, %1\nlqc2 vf2, %2\nvsub.xyz vf1, vf1, vf2\nsqc2 vf1, %0"
                : "=m" (*(Q_00385228 *)(vars + 0x20)) : "m" (temp), "m" (*position) : "vf1", "vf2");
            func_0038CF68(vars + 0x20, vars + 0x20, speed);
        } else if (D_001A4BE0.aiming) {
            func_L01_004CAC78(vars + 0x20, position, speed, 35.0f, 1.3962634f);
        } else {
            func_0038CF68(vars + 0x20, &D_001A4BE0.aim, speed);
        }
        *(Q_00385228 *)(moby + 0x10) = *position;
        ticks = (s32)(30.0f / speed) + 30;
        *(f32 *)(vars + 0x2C) = speed;
        *(s32 *)(vars + 0x34) = ticks;
        *(f32 *)(vars + 0x38) = 1.0f / ticks;
        *(f32 *)(moby + 0x2C) = *(f32 *)(*(u8 **)(moby + 0x24) + 0x24) * D_L01_001DDD98;
        moby[0x20] = 0;
        *(u8 **)(vars + 0x1C) = target;
        if (target) {
            f32 *hit = func_00382348((s32)target);
            if (hit) *(u16 *)((u8 *)hit + 0x1E) |= 0x80;
        }
        *(f32 *)(vars + 0x40) = 1.0f;
        *(s32 *)(vars + 0x14) = *(s16 *)(*(u8 **)(owner + 0x68) + 0x5A);
        *(s32 *)(vars + 0x18) = *(s16 *)(owner + 0xAA);
        if (!func_L01_00457458(*(s32 *)(vars + 0x18), *(s32 *)(vars + 0x14))) {
            func_003C2880(moby);
            return 0;
        }
        *(s32 *)(vars + 0x10) = 0;
        if ((u32)D_L01_001DDD90 >= 16) D_L01_001DDD90 = 0;
        D_L01_001DDD94 = 0;
        *(s32 *)vars = D_L01_001DDD90++;
        if (D_L01_001DDD90 >= 16) D_L01_001DDD90 = 0;
        temp = *(Q_00385228 *)(moby + 0x10);
        *(Q_00385228 *)(moby + 0x10) = D_001A4C60;
        *(s32 *)(vars + 0x30) = func_L01_004C85C8(moby, 0, 1.0f, 1.0f, 1.0f);
        *(Q_00385228 *)(moby + 0x10) = temp;
        func_L01_00404A10(func_L01_00385EE0, moby);
        func_003C7C38(moby);
    }
    return moby;
}
/* localdecomp:end func_L01_00385228 */
