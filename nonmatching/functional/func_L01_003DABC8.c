/* functional: high. Codex near miss, 2 words differ: li and lui swapped (scheduling only). */
#include "common.h"
/* localdecomp:start func_L01_003DABC8 */
#include "vu0.h"
typedef struct { u8 p0[0x140]; f32 x, y; } Camera_003DABC8;
typedef struct { u8 p0[0x8F]; u8 weapon; } State_003DABC8;
typedef struct { u8 p0[0x6C]; f32 power; u8 p70[0xF0 - 0x70]; } Weapon_003DABC8;
typedef struct {
    vu0_v4 direction;
    u8 p10[8]; u8 kind, mode; u16 cls;
    s32 w1C, flags; u8 p24[12];
} Damage_003DABC8;
extern Camera_003DABC8 D_L01_001E2880;
extern State_003DABC8 D_001425C0;
extern Weapon_003DABC8 D_L01_002C5600[];
extern u8 *D_L01_001EEA80[];
extern s32 D_001DAFEC_sda;
extern s32 D_L01_001DDBB0;
extern s32 D_001E2430_sda;
void func_L01_003DABC8(u8 *self) {
    extern f32 func_003824E0(f32, f32);
    extern f32 func_00382538(void);
    extern void func_00382760(void *, f32, f32, f32);
    extern s32 func_00382498(s32, s32);
    extern void func_L01_004668A0(void *, void *, u32, u32, s32, f32);
    extern f32 func_0038D160(f32, f32);
    extern f32 func_L01_00443A18(f32, f32);
    extern f32 func_0038DAB8(f32, f32);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern void func_L01_00471BF0(void *, void *, s32);
    extern void func_L01_003D6158(void *, s32, s32, s32, s32, f32, f32);
    extern void func_L01_003002A8(void *, void *, void *);
    extern void func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32,
        s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32,
        s32, s32, s32, s32, f32, f32, f32, f32);
    extern s32 func_003A52A0(s32, s32, void *);
    extern s32 func_003D4D00(void *, s32, void *, s32, f32);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_L01_00446760(void *, void *, s32, void *, f32);
    extern void func_L01_00446978(void *, void *);
    extern void func_L01_00424D88(s32);
    extern void func_003C2880(void *);
    vu0_v4 velocity, position;
    Damage_003DABC8 damage;
    u8 *vars = *(u8 **)(self + 0x68);
    s32 i, count;

    u8 **list;
    for (i = 29; i >= 0; --i) {
        f32 speed, yaw, pitch;
        speed = func_003824E0(0.0f, 0.37f);
        yaw = func_00382538();
        func_00382760(&position, speed, yaw, func_00382538());
        position.z += func_003824E0(0.35f, 0.6f);
        vec_add_ba(&position, &position, self + 0x10);
        speed = func_003824E0(0.0030000002589076757f, 0.024000002071261406f);
        yaw = func_00382538();
        func_00382760(&velocity, speed, yaw, func_00382538());
        func_L01_004668A0(&position, &velocity, 0x4F7F7F7F, 0x202020, func_00382498(25, 47), 150000.0f);
    }
    {
    u8 *place = self + 0x10;
    for (i = 49; i >= 0; --i) {
        f32 yaw, speed, pitch, angle;
        yaw = func_0038D160(D_L01_001E2880.x - *(f32 *)(self + 0x10), D_L01_001E2880.y - *(f32 *)(self + 0x14));
        func_L01_00443A18(1.0f, 2.0f);
        velocity.x = *(f32 *)(self + 0x10) + func_L01_00443A18(0.0f, 0.15f);
        velocity.y = *(f32 *)(self + 0x14) + func_L01_00443A18(0.0f, 0.15f);
        velocity.z = *(f32 *)(self + 0x18) + func_L01_00443A18(0.0f, 0.15f);
        speed = func_003824E0(3.0f, 7.0f);
        pitch = func_L01_00443A18(0.0f, 2.6179938316345215f);
        speed *= 0.020000001415610313f;
        angle = func_0038DAB8(yaw, pitch);
        position.x = func_0038D098(angle) * speed;
        position.y = func_0038D0B0(angle) * speed;
        position.z = 0.0f;
        position.z = func_003824E0(5.0f, 10.0f) * 0.020000001415610313f;
        func_L01_00471BF0(&velocity, &position, 0x8E);
    }
    func_L01_003D6158(self, 0x4E, 0x4F, 10, 1, 1.5f, 1.2f);
    for (i = 9; i >= 0; --i) {
        f32 speed, yaw, pitch;
        speed = func_003824E0(0.0f, 0.35f);
        yaw = func_00382538();
        func_00382760(&position, speed, yaw, func_00382538());
        position.z += 0.25f;
        vec_add_ba(&position, &position, self + 0x10);
        { f32 next_speed = func_003824E0(0.06000000238418579f, 0.12000000476837158f);
        f32 next_yaw = func_00382538();
        func_00382760(&velocity, next_speed, next_yaw, 1.2217304706573486f); }
        velocity.z = func_003824E0(3.0f, 5.0f) * 0.020000001415610313f;
        func_L01_003002A8(self, &position, &velocity);
    }
    { s32 one = 1;
    func_L01_003303B8(place, one, 25, 20, 20, 20, 45, 2,
        0, one, one, 0, 0, 0, 0x10000, D_001DAFEC_sda, 0x388EF7, 0x63F7,
        0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0,
        0.8f, 0.0f, 0.0f, 0.0f); }
    func_003A52A0(3, 0, self);
    count = func_003D4D00(place, 0, self, 0, 3.0f);
    if (count > 0) {
        s32 remaining;
        list = D_L01_001EEA80;
        remaining = count;
        do {
            u8 *moby = *list;
            if ((*(u8 **)(moby + 0x24))[0x46] == 5 || (*(u16 *)(moby + 0x34) & 0x4000)) {
                vec_sub_ba(&velocity, moby + 0x10, self + 0x10);
                func_0038CF68(&velocity, &velocity, 1.0f);
                func_0038CF68(&damage, &damage, 1.0f);
                func_L01_00446760(&damage, self, 0x1010000, &velocity, ((Weapon_003DABC8 *)((u32)D_L01_002C5600 + D_001425C0.weapon * sizeof(Weapon_003DABC8)))->power * 0.2f);
                damage.flags = 1;
                *(vu0_q *)&damage.direction = *(vu0_q *)&velocity;
                damage.direction.w = 5627.9248046875f;
                damage.kind = 5;
                damage.mode = 3;
                damage.cls = *(u16 *)(moby + 0xAA);
                func_L01_00446978(moby, &damage);
            }
            --remaining;
            ++list;
        } while (remaining);
    }
    if (*(s32 *)(vars + 0x30) != -1) {
        func_L01_00424D88(*(s32 *)(vars + 0x30));
        *(s32 *)(vars + 0x30) = -1;
    }
    D_L01_001DDBB0 = 1;
    D_001E2430_sda = 50;
    func_003C2880(self);
    }
}
/* localdecomp:end func_L01_003DABC8 */
