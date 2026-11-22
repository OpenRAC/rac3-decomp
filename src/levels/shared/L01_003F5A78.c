#include "common.h"
#include "vu0.h"

typedef struct {
    s32 f0;
    u8 pad[16];
} S_003F38D0;

/* localdecomp:start func_L01_003F5A78 */
extern S_003F38D0 D_L01_002F7680[];
s32 func_L01_003F5A78(s32 id) {
    s32 i;
    for (i = 0; D_L01_002F7680[i].f0 != -1 && D_L01_002F7680[i].f0 != id; i++) {
    }
    return i;
}
/* localdecomp:end func_L01_003F5A78 */

/* localdecomp:start func_L01_003F5AC0 */
typedef int u128_003F5AC0 __attribute__((mode(TI)));
extern u8 D_L01_001E2A40[];
extern u8 D_L01_001E5510[];
extern void func_L01_004E1F00(s32);
extern u8 *func_L01_003F34E0(s32, s32);
extern void func_L01_003F4E70(s32, s32);
extern void func_L01_003F37A0(u8 *);
extern void func_L01_003F3398(s32);
extern void func_L01_003F3068(s32);

/* camera_reset_follow: makes the follow camera current with no blend and re-initialises it. */
void func_L01_003F5AC0(s32 player, s32 reset_timer) {
    u8 *camera = D_L01_001E2A40 + player * 0x460; /* GameCamera, 0x460 per player */
    u8 *update;
    f32 *update_pos;
    f32 *hero_pos;
    f32 *follow_pos;

    func_L01_004E1F00(0); /* camera_hero_copy */
    /* end the current camera: active (+0x8E), asked_for (+0x7D), ending (+0x7E) */
    if (*(u8 **)(camera + 0x50) != 0) {
        *(s16 *)(*(u8 **)(camera + 0x50) + 0x8E) = 0;
        *(u8 *)(*(u8 **)(camera + 0x50) + 0x7D) = 0;
        *(s16 *)(*(u8 **)(camera + 0x50) + 0x7E) = 0;
    }
    /* the follow camera (class 0) becomes current, with player's follow block (0x780 each) */
    *(u8 **)(camera + 0x50) = func_L01_003F34E0(player, 0);
    *(s16 *)(*(u8 **)(camera + 0x50) + 0x8E) = 1;
    *(u8 **)(*(u8 **)(camera + 0x50) + 0x70) = D_L01_001E5510 + player * 0x780;
    *(u8 *)(*(u8 **)(camera + 0x50) + 0x7D) = 0;
    *(s16 *)(camera + 0x2A0) = 0; /* blend_state: no blend */
    func_L01_003F4E70(player, 1);
    if (reset_timer) {
        *(s32 *)(camera + 0x454) = 0;
    }
    func_L01_003F37A0(*(u8 **)(camera + 0x50));
    func_L01_003F3398(player);
    /* the camera takes the follow camera's position */
    update = *(u8 **)(camera + 0x50);
    *(u128_003F5AC0 *)camera = *(u128_003F5AC0 *)(update + 0x30);
    update_pos = (f32 *)(update + 0x64);
    update_pos[0] = ((f32 *)camera)[0];
    update_pos[1] = ((f32 *)camera)[1];
    update_pos[2] = ((f32 *)camera)[2];
    hero_pos = (f32 *)(camera + 0x190);
    follow_pos = (f32 *)(camera + 0x60);
    follow_pos[0] = hero_pos[0];
    follow_pos[1] = hero_pos[1];
    follow_pos[2] = hero_pos[2];
    func_L01_003F3068(player);
}
/* localdecomp:end func_L01_003F5AC0 */

/* localdecomp:start func_L01_003F5BE0 */
extern u8 *D_L01_001DF8C0[1];
extern u8 D_L01_001DF890[] __attribute__((section(".sdata")));
extern u8 D_L01_001E2FD0[];
extern s32 D_L01_001DF808;
extern u8 *D_L01_001DF804;
extern s32 D_L01_001DF800[] __attribute__((section(".sdata")));
__asm__(".extern D_001D5FE8_sda, 8");
extern f32 D_001D5FE8_sda[2];
void func_L01_003F5BE0(void) {
    extern void func_L01_003F3068(s32);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_L01_003F2A00(s32);
    s32 i, player;
    {
        s32 k = 15;
        u8 **slot = D_L01_001DF8C0 + 15;
        for (; k >= 0; k--) { *slot-- = 0; }
    }
    player = 0;
    do {
        u8 *camera = D_L01_001E2A40 + player * 0x460;
        u8 *follow = camera + 0x60;

        *(s32 *)(camera + 0x450) = 0;
        *(s32 *)(camera + 0x454) = 0;
        func_L01_003F3068(player);
        qzero(camera + 0x410);
        *(s32 *)(camera + 0x54) = 0;
        *(s16 *)(camera + 0x2A0) = 0;
        func_0038CF68(camera + 0x80, *(u8 **)(camera + 0x240) + 0xE0, 1.0f);
        { u128_003F5AC0 pos = *(u128_003F5AC0 *)(camera + 0x190);
        qzero(camera + 0xB0);
        *(u128_003F5AC0 *)(camera + 0xC0) = pos; }
        {
            u8 *active = (u8 *)(player * 0x30 + (s32)D_L01_001DF890);
            u8 *entry = (u8 *)(player * 0x2100 + (s32)D_L01_001E2FD0);
            *(u128_003F5AC0 *)(camera + 0xA0) = *(u128_003F5AC0 *)(camera + 0x90) = *(u128_003F5AC0 *)(camera + 0x80);
            *(s32 *)(follow + 0xC4) = 0;
            *(s32 *)(follow + 0xE4) = 0;
            *(s32 *)(follow + 0xC0) = 0;
            *(s32 *)(follow + 0xCC) = 0;
            *(s32 *)(follow + 0xE8) = 0;
            D_001D5FE8_sda[player] = 0.85f;
            *(f32 *)(follow + 0xAC) = *(f32 *)(follow + 0xB0) = *(f32 *)(follow + 0xB4) = *(f32 *)(follow + 0xB8) = *(f32 *)(follow + 0xBC) = *(f32 *)(camera + 0x1A8);
            for (i = 47; i >= 0; i--) {
                *(s16 *)(entry + 0x8E) = 0;
                *(s32 *)(entry + 0x94) = player;
                *active++ = 0;
                entry += 0xB0;
            }
        }
        func_L01_003F2A00(player);
        i = 0;
        if (D_L01_001DF808 > 0) {
            u8 *active = (u8 *)(player * 0x30 + (s32)D_L01_001DF890);
            u8 *entry = (u8 *)(player * 0x2100 + (s32)D_L01_001E2FD0);
            do {
                u8 *row = (u8 *)(i * 0x20 + (s32)D_L01_001DF804);
                u8 *object = *(u8 **)(row + 0x1C);
                *(s16 *)(entry + 0x84) = i;
                *(u8 **)(object + 4) = entry;
                *(s16 *)(entry + 0x8E) = 0;
                entry[0x89] = 0;
                *(s16 *)(entry + 0x8A) = 0;
                *(s16 *)(entry + 0x82) = -1;
                *(s16 *)(entry + 0x80) = -1;
                entry[0x7D] = 0;
                *(s16 *)(entry + 0x7E) = 0;
                *(f32 *)(entry + 0x78) = -1.0f;
                entry[0x7C] = object[0x1C];
                *(s32 *)(entry + 0x74) = object[0x1F];
                {
                    u16 id = *(u16 *)(row + 0xC);
                    *active++ = 1;
                    *(s16 *)(entry + 0x86) = id;
                    *(s16 *)(entry + 0x8C) = func_L01_003F5A78((s16)id);
                }
                entry += 0xB0;
                i++;
            } while (i < D_L01_001DF808);
        }
        func_L01_003F5AC0(player, 1);
        *(s16 *)(camera + 0x2A0) = 0;
        {
            u8 *tail = camera + 0x3F0;
            *(s32 *)(tail + 0xC) = 0;
            *(s32 *)(tail + 4) = 0;
            *(s32 *)(camera + 0x3F0) = 0;
            *(s32 *)(tail + 0x10) = 0;
        }
        D_L01_001DF800[player] = 0;
        player++;
    } while (player <= 0);
}
/* localdecomp:end func_L01_003F5BE0 */

/* localdecomp:start func_L01_003F5E88 */
extern u8 *D_L01_001DF8C0[1];
void func_L01_003F5E88(u8 *arg0) {
    s32 i;
    for (i = 0; i < 16; i++) {
        if (D_L01_001DF8C0[i] == 0) {
            D_L01_001DF8C0[i] = arg0;
            break;
        }
    }
}
/* localdecomp:end func_L01_003F5E88 */

/* localdecomp:start func_L01_003F5EE0 */
__asm__(".extern D_L01_001DF8C0, 64");
extern u8 *D_L01_001DF8C0[1];

void func_L01_003F5EE0(u8 *a0) {
    u8 **p = D_L01_001DF8C0;
    s32 i;

    for (i = 15; i >= 0; i--) {
        if (*p == a0) {
            *p = 0;
        }
        p++;
    }
}
/* localdecomp:end func_L01_003F5EE0 */

/* localdecomp:start func_L01_003F5F10 */
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);

void func_L01_003F5F10(f32 *out, f32 *in, void *center) {
    f32 s = func_0038D098(in[1]);
    out[0] = in[2] * s * func_0038D098(in[0]);
    s = func_0038D098(in[1]);
    out[1] = in[2] * s * func_0038D0B0(in[0]);
    out[2] = in[2] * func_0038D0B0(in[1]);
    out[3] = 0.0f;
    vec_add_ba(out, out, center);
}
/* localdecomp:end func_L01_003F5F10 */

/* localdecomp:start func_L01_003F5FC0 */
extern f32 func_0038CED8(void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DB00(f32, f32);
extern f32 func_0038CEA8(void *);

s32 func_L01_003F5FC0(f32 *a0, void *a1, void *a2) {
    vu0_v4 d;
    f32 t;

    vec_sub_ab(&d, a1, a2);
    a0[1] = func_0038D160(func_0038CED8(&d), d.z);
    t = func_0038D160(d.x, d.y);
    func_0038DB00(t, a0[0]);
    a0[0] = t;
    a0[2] = func_0038CEA8(&d);
    return 0;
}
/* localdecomp:end func_L01_003F5FC0 */

/* localdecomp:start func_L01_003F6048 */
extern u8 D_L01_001E2A40[];
extern s32 D_L01_001DF818[] __attribute__((section(".sdata")));
extern vu0_v4 D_L01_001EAA30;
void func_L01_003F6048(s32 player,vu0_v4 *position,f32 radius) {
    extern f32 func_0038CEA8(void *);
    extern void func_L01_0040E408(void *,void *,f32);
    extern s32 func_L01_003FB640(void *,s32,void *,f32);
    vu0_v4 step,origin;
    u8 *camera=D_L01_001E2A40+player*0x460;
    u8 *update=*(u8 **)(camera+0x50);
    f32 *p=(f32 *)(update+0x64);
    s32 count,i,j,next;
    origin.x=p[0];origin.y=p[1];origin.z=p[2];origin.w=0;
    if(*(s16 *)(update+0x8a)) {
        *(u128_003F5AC0 *)camera=*(u128_003F5AC0 *)position;
        *(s16 *)(update+0x8a)=0;
    } else {
        vec_sub_ba(&step,position,&origin);
        count=(s32)(func_0038CEA8(&step)/(radius*0.9f))+1;
        func_L01_0040E408(&step,&step,(f32)count);
        *(u128_003F5AC0 *)position=*(u128_003F5AC0 *)&origin;
        for(i=0;i<count;i++) {
            j=0;
            vec_add_ab(position,position,&step);
            while(j<6) {
                if(!func_L01_003FB640(position,D_L01_001DF818[player],*(void **)(camera+0x240),radius)) break;
                *(u128_003F5AC0 *)position=*(u128_003F5AC0 *)&D_L01_001EAA30;
                update=*(u8 **)(camera+0x50);
                if(!update[0x89]) update[0x89]=1;
                j++;
            }
        }
        *(u128_003F5AC0 *)camera=*(u128_003F5AC0 *)position;
    }
}
/* localdecomp:end func_L01_003F6048 */

LINKER_REMNANT("asm/levels", func_L01_003F6208);
