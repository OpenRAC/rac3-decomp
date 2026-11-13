#include "common.h"

/* localdecomp:start func_L39_0057B4C0 */
/* from this repository's func_L01_003F5AC0 (the same camera reset) */
typedef int u128_0057B4C0 __attribute__((mode(TI)));
extern u8 D_L39_0024DE80[];
extern u8 D_L39_00257C90[];
extern s32 D_L39_00241164;
extern s32 D_L39_0024BF5C;
extern u8 *func_L39_0061BF38(s32);
extern void func_L39_0063B0A8(u8 *);
extern u8 *func_L01_003F34E0(s32, s32);
extern void func_00384498(s32, s32);
extern void func_L01_003F37A0(u8 *);
extern void func_00382A80(s32);
extern void func_L01_003F3068(s32);

void func_L39_0057B4C0(s32 player, s32 reset_timer) {
    u8 *camera = D_L39_0024DE80 + player * 0x460;
    u8 *update;
    u8 *q;
    f32 *update_pos;
    f32 *hero_pos;
    f32 *follow_pos;

    q = func_L39_0061BF38(player);
    if (*(s32 *)(q + 0x2530) != 0) {
        func_L39_0063B0A8(q);
    } else {
        *(s32 *)(camera + 0x240) = D_L39_0024BF5C;
        *(s32 *)(camera + 0x284) = D_L39_00241164;
    }
    if (*(u8 **)(camera + 0x50) != 0) {
        *(s16 *)(*(u8 **)(camera + 0x50) + 0x8E) = 0;
        *(u8 *)(*(u8 **)(camera + 0x50) + 0x7D) = 0;
        *(s16 *)(*(u8 **)(camera + 0x50) + 0x7E) = 0;
    }
    *(u8 **)(camera + 0x50) = func_L01_003F34E0(player, 0);
    *(s16 *)(*(u8 **)(camera + 0x50) + 0x8E) = 1;
    *(u8 **)(*(u8 **)(camera + 0x50) + 0x70) = D_L39_00257C90 + player * 0x780;
    *(u8 *)(*(u8 **)(camera + 0x50) + 0x7D) = 0;
    *(s16 *)(camera + 0x2A0) = 0;
    func_00384498(player, 1);
    if (reset_timer) {
        *(s32 *)(camera + 0x454) = 0;
    }
    func_L01_003F37A0(*(u8 **)(camera + 0x50));
    func_00382A80(player);
    update = *(u8 **)(camera + 0x50);
    *(u128_0057B4C0 *)camera = *(u128_0057B4C0 *)(update + 0x30);
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
/* localdecomp:end func_L39_0057B4C0 */

/* localdecomp:start func_L39_0057B610 */
/* LOG func_L39_0057B610 (MATCH with --as ps2as; float constants are built inline by Ps2EeAs, the file's flags lack @ps2as)
 * v1 plain structs: 168 diff. Fixes that mattered: qzero() for `sq $0` (vu0.h); .sdata/_sda float slot as
 * `extern f32 X[1]` + `.extern X, 4` ($gp); D_B850/B854 scalar + `.extern X, 16` (lui macro, no hoist);
 * separate temps for the first (clear) loop; sub-struct view at cam+0x60; f32 temp for the 5 stores;
 * (j*32 + (s32)D_B850) for the row (addu operand order); lhu id + (s16) cast for the call;
 * D_B940 and D_B840 as 1-element arrays with `.extern X, 64` (la macro, adjacent lui/addiu);
 * store order for the 0xB0..0xC0 quadwords (N,A,C) and the tail. vperm found nothing better than the hand fix. */
#include "vu0.h"
typedef int u128_0057B610 __attribute__((mode(TI)));
typedef struct Obj_fwd_0057B610 {
    u8 pad0[0x74];
    s32 w74;
    f32 f78;
    u8 b7C;
    u8 b7D;
    s16 h7E;
    s16 h80;
    s16 h82;
    s16 h84;
    s16 h86;
    u8 pad88;
    u8 b89;
    s16 h8A;
    s16 h8C;
    s16 h8E;
    u8 pad90[4];
    s32 w94;
    u8 pad98[0xB0 - 0x98];
} Obj_0057B610;
struct Obj_fwd_0057B610;
typedef struct {
    u8 pad0[4];
    struct Obj_fwd_0057B610 *obj;
    u8 pad8[0x1C - 8];
    u8 b1C;
    u8 pad1D[2];
    u8 b1F;
} Info_0057B610;
typedef struct {
    u8 pad0[0xC];
    u16 hC;
    u8 pad0E[0x1C - 0xE];
    Info_0057B610 *info;
} Row_0057B610;
typedef struct {
    u8 pad0[0x20];
    s32 w20;
    s32 w24;
    f32 f28;
    f32 f2C;
    u8 pad30[0xAC - 0x30];
    f32 fAC;
    f32 fB0;
    f32 fB4;
    f32 fB8;
    f32 fBC;
    s32 wC0;
    s32 wC4;
    u8 padC8[4];
    s32 wCC;
    u8 padD0[0xE4 - 0xD0];
    s32 wE4;
    s32 wE8;
} Sub_0057B610;
typedef struct {
    u8 pad0[0x54];
    s32 w54;
    u8 pad58[0x80 - 0x58];
    s32 w80;
    s32 w84;
    f32 f88;
    f32 f8C;
    u128_0057B610 q90;
    u128_0057B610 qA0;
    u128_0057B610 qB0;
    u128_0057B610 qC0;
    u8 padD0[0x10C - 0xD0];
    f32 f10C;
    f32 f110;
    f32 f114;
    f32 f118;
    f32 f11C;
    s32 w120;
    s32 w124;
    u8 pad128[4];
    s32 w12C;
    u8 pad130[0x144 - 0x130];
    s32 w144;
    s32 w148;
    u8 pad14C[0x190 - 0x14C];
    u128_0057B610 q190;
    u8 pad1A0[0x1A8 - 0x1A0];
    f32 f1A8;
    u8 pad1AC[0x2A0 - 0x1AC];
    s16 h2A0;
    u8 pad2A2[0x3F0 - 0x2A2];
    s32 w3F0;
    s32 w3F4;
    u8 pad3F8[4];
    s32 w3FC;
    s32 w400;
    u8 pad404[0x410 - 0x404];
    u128_0057B610 q410;
    u8 pad420[0x450 - 0x420];
    s32 w450;
    s32 w454;
    u8 pad458[0x460 - 0x458];
} Cam_0057B610;

extern s32 D_L39_0024B940[1];
__asm__(".extern D_L39_0024B940, 64");
extern Obj_0057B610 D_L39_0024F110[];
extern u8 D_L39_00259A90[];

extern s32 D_L39_0024B854;
__asm__(".extern D_L39_0024B854, 16");
extern Row_0057B610 *D_L39_0024B850;
__asm__(".extern D_L39_0024B850, 16");
extern s32 D_L39_0024B840[1];
__asm__(".extern D_L39_0024B840, 64");
extern f32 D_001D6C78_sda[1];
__asm__(".extern D_001D6C78_sda, 4");

extern void func_L01_003F3068(s32);
extern void func_L01_003F2A00(s32);
extern s32 func_L01_003F5A78(s32);
extern void func_L39_0057B4C0(s32, s32);

void func_L39_0057B610(void) {
    s32 i;
    s32 p;
    s32 j;
    u16 id;
    f32 fl;
    Cam_0057B610 *cam;
    Obj_0057B610 *obj;
    Obj_0057B610 *o1;
    u8 *act;
    u8 *a1;
    Row_0057B610 *row;
    Info_0057B610 *info;
    s32 *q;
    Sub_0057B610 *sub;

    for (i = 15; i >= 0; i--) {
        D_L39_0024B940[i] = 0;
    }
    for (p = 0; p < 4; p++) {
        cam = (Cam_0057B610 *)D_L39_0024DE80 + p;
        cam->w450 = 0;
        cam->w454 = 0;
        func_L01_003F3068(p);
        cam->w54 = 0;
        qzero(&cam->q410);
        cam->h2A0 = 0;
        sub = (Sub_0057B610 *)((u8 *)cam + 0x60);
        sub->w20 = 0;
        sub->w24 = 0;
        sub->f28 = 1.0f;
        sub->f2C = 1.0f;
        qzero(&cam->qB0);
        cam->q90 = *(u128_0057B610 *)&cam->w80;
        cam->qA0 = *(u128_0057B610 *)&cam->w80;
        cam->qC0 = cam->q190;
        D_001D6C78_sda[p] = 0.85f;
        sub->wC4 = 0;
        sub->wE4 = 0;
        sub->wC0 = 0;
        sub->wCC = 0;
        sub->wE8 = 0;
        fl = cam->f1A8;
        sub->fBC = fl;
        sub->fB8 = fl;
        sub->fB4 = fl;
        sub->fB0 = fl;
        sub->fAC = fl;
        a1 = &D_L39_00259A90[p * 48];
        o1 = &D_L39_0024F110[p * 48];
        for (j = 47; j >= 0; j--) {
            o1->h8E = 0;
            o1->w94 = p;
            *a1 = 0;
            o1++;
            a1++;
        }
        func_L01_003F2A00(p);
        j = 0;
        q = &cam->w3F0;
        if (D_L39_0024B854 > 0) {
            act = &D_L39_00259A90[p * 48];
            obj = &D_L39_0024F110[p * 48];
            do {
                row = (Row_0057B610 *)(j * 32 + (s32)D_L39_0024B850);
                info = row->info;
                obj->h84 = j;
                info->obj = obj;
                j++;
                obj->h8E = 0;
                obj->b89 = 0;
                obj->h8A = 0;
                obj->h82 = -1;
                obj->h80 = -1;
                obj->b7D = 0;
                obj->h7E = 0;
                obj->f78 = -1.0f;
                obj->b7C = info->b1C;
                obj->w74 = info->b1F;
                id = row->hC;
                *act = 1;
                obj->h86 = id;
                obj->h8C = func_L01_003F5A78((s16)id);
                act++;
                obj++;
            } while (j < D_L39_0024B854);
        }
        func_L39_0057B4C0(p, 1);
        cam->h2A0 = 0;
        q[3] = 0;
        q[1] = 0;
        cam->w3F0 = 0;
        q[4] = 0;
        D_L39_0024B840[p] = 0;
    }
}
/* localdecomp:end func_L39_0057B610 */
