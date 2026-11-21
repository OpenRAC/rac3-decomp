/* functional: high. Same reads/writes/calls as retail (verified against asm); only register allocation/scheduling differ (39 words) */
extern Entry_3E6C58 D_L01_001E2A40[];
extern M_3E6CA8 *D_L01_001DF804;
extern s32 D_001A4E18[];
typedef struct { u128_t pos, rot; u8 pad20[0x440]; } Pose_003EB438;
static __inline__ void copy_003EB438(void *d, void *s) { *(u128_t *)d = *(u128_t *)s; }
void func_L01_003EB438(s32 player, u128_t *position, u128_t *facing, s32 mode, s32 value, s32 owner) {
    extern u8 *func_L01_003F34E0(s32, s32);
    extern void func_00382E10(u8 *, s32);
    extern s32 func_L01_003F5FC0(u8 *, u128_t *, u128_t *);
    f32 pos[4] __attribute__((aligned(16)));
    f32 rot[4] __attribute__((aligned(16)));
    f32 oldpos[4] __attribute__((aligned(16)));
    f32 oldrot[4] __attribute__((aligned(16)));
    u8 *obj = func_L01_003F34E0(player, 5);
    u8 *base = D_L01_001DF804[*(s16 *)(obj+0x84)].p1C;
    u8 *data;
    u8 *sub;
    u8 *entry;
    copy_003EB438(pos, position);
    copy_003EB438(rot, facing);
    entry = (u8 *)D_L01_001E2A40;
    copy_003EB438(oldpos, &((Pose_003EB438 *)D_L01_001E2A40)[player].pos);
    copy_003EB438(oldrot, &((Pose_003EB438 *)D_L01_001E2A40)[player].rot);
    func_00382E10(obj, mode == 4);
    obj[0x7D] = 1;
    data = *(u8 **)(obj+0x70);
    sub = data+0xE0;
    *(u128_t *)(obj+0x30) = *(u128_t *)pos;
    copy_003EB438(&D_L01_001E2A40[player], pos);
    *(u128_t *)(obj+0x40) = *(u128_t *)rot;
    *(u128_t *)(data+0x80) = *(u128_t *)pos;
    *(u128_t *)(data+0x90) = *(u128_t *)rot;
    *(s32 *)(sub+0x40) = owner;
    obj[0x88] = mode;
    base[0x20] = 0;
    if (mode == 2) goto set_value;
    if (mode == 3) {
        *(f32 *)(sub+0x44) = 1.0f;
        *(s32 *)(sub+0x48) = 0;
        *(u128_t *)(obj+0x30) = *(u128_t *)oldpos;
        *(u128_t *)(obj+0x40) = *(u128_t *)oldrot;
        *(u128_t *)(data+0x110) = *(u128_t *)(player*0x460 + (entry+0x190));
        func_L01_003F5FC0(data+0xFC, (u128_t *)oldpos, (u128_t *)((u8 *)&D_L01_001E2A40[player]+0x190));
set_value:
        *(s32 *)(sub+4) = value;
        *(s32 *)(data+0xE0) = value;
    }
    D_001A4E18[0] = 2;
}
