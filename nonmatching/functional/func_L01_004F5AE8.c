/* functional: medium. 127 diff words (boolean lowering slt vs movn, allocation); asm .extern removed, D_L01_001DBCFC plain extern */
#include "vu0.h"
typedef struct {
    u8 pad0[0x184]; f32 speed;
    u8 pad188[0x1B8-0x188]; s32 timer;
    u8 pad1BC[0x298-0x1BC]; f32 wall_height; f32 pad29C; f32 wall_normal; u8 blocked;
    u8 pad2A5[0xBE4-0x2A5]; f32 yaw, pitch;
    u8 padBEC[0x1200-0xBEC]; u8 *moby;
    u8 pad1204[0x121A-0x1204]; u8 active;
    u8 pad121B[0x1228-0x121B]; s32 trigger;
    u8 pad122C[0x16B0-0x122C]; s32 camera;
    u8 pad16B4[0x1CE0-0x16B4]; u8 effect_state[0x30];
    u8 pad1D10[0x25C0-0x1D10]; u8 *hero_moby; s32 state;
} Hero_004F5AE8;
extern St_004ECCD8 D_001A4BE0;
extern Camera_004F5730 D_L01_001E2A40;
extern s32 D_L01_001DBCFC;
void func_L01_004F5AE8(void) {
    extern void func_L01_005118D0(s32, s32);
    extern s32 func_L01_004F5730(void);
    extern f32 func_0038DAB8(f32, f32);
    extern u8 *func_003C24B0(s32, s32);
    extern void func_L01_00456160(u8 *, u8 *);
    extern void func_L01_004AA7E8(u8 *, s32);
    extern void func_L01_00511178(void *, void *, f32);
    extern void func_00382760(void *, f32, f32, f32);
    extern void func_0038D308(void *, void *);
    extern void func_0038D5F0(void *, void *, void *);
    extern void func_003C48A8(void *, void *);
    extern void func_L01_0044E318(void *, void *);
    extern void func_L01_0044E340(void *, s32, s32, f32);
    vu0_v4 rotation;
    vu0_q matrix[3], camera_matrix[3];
    s32 aiming;
    u8 *vars, *effect, *moby, *effect_vars;
    if ((*(Hero_004F5AE8 *)&D_001A4BE0).active == 0) {
    func_L01_005118D0(-1, 1);
    D_L01_001DBCFC = 0;
    aiming = 1;
    if ((*(Hero_004F5AE8 *)&D_001A4BE0).camera != 2) aiming--;
    if ((*(Hero_004F5AE8 *)&D_001A4BE0).state == 1 || (*(Hero_004F5AE8 *)&D_001A4BE0).state == 29) {
        aiming = 1;
        if ((*(Hero_004F5AE8 *)&D_001A4BE0).timer < 18) aiming--;
    }
    if (aiming && !func_L01_004F5730()) {
        (*(Hero_004F5AE8 *)&D_001A4BE0).yaw = D_L01_001E2A40.yaw;
        (*(Hero_004F5AE8 *)&D_001A4BE0).pitch = func_0038DAB8(-D_L01_001E2A40.pitch, 0.12217304855585098f);
    }
    if ((*(Hero_004F5AE8 *)&D_001A4BE0).trigger == 127) {
    moby = (*(Hero_004F5AE8 *)&D_001A4BE0).moby;
    vars = *(u8 **)(moby + 0x68);
    *(u8 **)(vars + 0x20) = func_003C24B0(71, 0x80);
    func_L01_00456160(*(u8 **)(vars + 0x20), moby);
    effect = *(u8 **)(vars + 0x20);
    *(s32 *)(effect + 0x98) = 0;
    *(u16 *)(effect + 0x34) = (*(u16 *)(effect + 0x34) | 0x41) & 0xEFFF;
    func_L01_004AA7E8(effect, 1);
    (*(Hero_004F5AE8 *)&D_001A4BE0).active = 1;
    effect[0x20] = 10;
    effect_vars = *(u8 **)(effect + 0x68);
    if ((*(Hero_004F5AE8 *)&D_001A4BE0).wall_height < 1.2f && (*(Hero_004F5AE8 *)&D_001A4BE0).wall_normal > 0.6632251143455505f && !(*(Hero_004F5AE8 *)&D_001A4BE0).blocked) *(s16 *)(effect_vars + 0x76) = 1;
    qzero(effect_vars + 0x40);
    if (!aiming) func_L01_00511178(effect_vars + 0x40, effect_vars + 0x40, 1.0f);
    else func_00382760(effect_vars + 0x40, 1.0f, (*(Hero_004F5AE8 *)&D_001A4BE0).yaw, (*(Hero_004F5AE8 *)&D_001A4BE0).pitch);
    qzero(&rotation);
    func_0038D308(matrix, &rotation);
    if (aiming) {
        rotation.x = D_L01_001E2A40.pad10;
        rotation.y = D_L01_001E2A40.pitch;
        rotation.z = D_L01_001E2A40.yaw;
        func_0038D308(camera_matrix, &rotation);
        func_0038D5F0(matrix, camera_matrix, matrix);
    } else func_0038D5F0(matrix, (*(Hero_004F5AE8 *)&D_001A4BE0).hero_moby + 0xC0, matrix);
    func_003C48A8(matrix, effect + 0xF0);
    *(s32 *)(effect_vars + 0x64) = 0;
    *(f32 *)(effect_vars + 0x60) = 0.46000003814697266f;
    if ((*(Hero_004F5AE8 *)&D_001A4BE0).speed < 0.40000003576278687f) {
        func_L01_0044E318(effect, (*(Hero_004F5AE8 *)&D_001A4BE0).effect_state);
        func_L01_0044E340((*(Hero_004F5AE8 *)&D_001A4BE0).effect_state, 48, 3, 0.0f);
        func_L01_0044E340((*(Hero_004F5AE8 *)&D_001A4BE0).effect_state, 23, 5, 0.0f);
    }
    }
    }
}
