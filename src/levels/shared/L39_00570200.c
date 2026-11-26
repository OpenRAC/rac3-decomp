#include "common.h"

typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    u8 pad[80];
    u8 *p50;
    u8 pad2[1036];
} Entry_3E6C58;
typedef struct {
    u8 pad[28];
    u8 *p1C;
} M_3E6CA8;

/* localdecomp:start func_L39_00570200 */
extern Entry_3E6C58 D_L39_0024DE80[];
extern M_3E6CA8 *D_L39_0024B850;
#include "structs/camera.h"
static __inline__ void copy_003EB438(void *d, void *s) { *(u128_t *)d = *(u128_t *)s; }
static __inline__ u128_t *hero_pos_003EB438(struct GameCamera *c) { return (u128_t *)&c->hero_pos; }
/* camera_scripted_set: switches player's camera to the scripted camera (mode 5) at a position
   and facing; kind 3 starts from the old pose aimed at the hero; no_look_timer = 2 */
void func_L39_00570200(s32 player, u128_t *position, u128_t *facing, s32 mode, s32 value, s32 owner) {
    extern u8 *func_L01_003F34E0(s32, s32);
    extern void func_00382E10(u8 *, s32);
    extern s32 func_L01_003F5FC0(u8 *, u128_t *, u128_t *);
    f32 pos[4] __attribute__((aligned(16)));
    f32 rot[4] __attribute__((aligned(16)));
    f32 oldpos[4] __attribute__((aligned(16)));
    f32 oldrot[4] __attribute__((aligned(16)));
    u8 *obj = func_L01_003F34E0(player, 5);
    u8 *base = D_L39_0024B850[*(s16 *)(obj+0x84)].p1C;
    u8 *data;
    u8 *sub;
    copy_003EB438(pos, position);
    copy_003EB438(rot, facing);
    copy_003EB438(oldpos, &((struct GameCamera *)D_L39_0024DE80)[player].position);
    copy_003EB438(oldrot, &((struct GameCamera *)D_L39_0024DE80)[player].angles);
    func_00382E10(obj, mode == 4);
    obj[0x7D] = 1;
    data = *(u8 **)(obj+0x70);
    sub = data+0xE0;
    *(u128_t *)(obj+0x30) = *(u128_t *)pos;
    copy_003EB438(&((struct GameCamera *)D_L39_0024DE80)[player].position, pos);
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
        copy_003EB438(data + 0x110, &((struct GameCamera *)D_L39_0024DE80)[player].hero_pos);
        func_L01_003F5FC0(data+0xFC, (u128_t *)oldpos, hero_pos_003EB438(&((struct GameCamera *)D_L39_0024DE80)[player]));
set_value:
        *(s32 *)(sub+4) = value;
        *(s32 *)(data+0xE0) = value;
    }
}
/* localdecomp:end func_L39_00570200 */
