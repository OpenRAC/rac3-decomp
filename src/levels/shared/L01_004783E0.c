#include "common.h"

/* localdecomp:start func_L01_004783E0 */
extern void func_L01_00517538(f32);
void func_L01_004783E0(s32 a0, s32 a1, s32 a2, f32 f) {
    f32 r;
    if (a2 == 0) {
        a2 = 1;
    }
    if (a2 > 0) {
        r = (f32)a1 / (f32)a2;
    } else {
        r = 0.0f;
    }
    if (r > 1.0f) {
        r = 1.0f;
    }
    func_L01_00517538(f * r);
}
/* localdecomp:end func_L01_004783E0 */

/* localdecomp:start func_L01_00478450 */
extern void func_L01_005169C8(f32);
void func_L01_00478450(s32 a0, s32 a1, s32 a2, f32 f) {
    f32 r;
    if (a2 == 0) {
        a2 = 1;
    }
    if (a2 > 0) {
        r = (f32)a1 / (f32)a2;
    } else {
        r = 0.0f;
    }
    if (r > 1.0f) {
        r = 1.0f;
    }
    func_L01_005169C8(f * r);
}
/* localdecomp:end func_L01_00478450 */

INCLUDE_ASM("asm/levels", func_L01_004784C0);

/* localdecomp:start func_L01_004785E8 */
typedef struct { u8 pad[4648]; s32 w; u8 pad2[9700 - 4652]; u8 b; } S474;
extern S474 D_001A4BE0;
s32 func_L01_004785E8(void) {
    S474 *p = &D_001A4BE0;
    s32 v = p->w;
    if (v == 9) v = 0;
    if (p->b) v = 0;
    return v;
}
/* localdecomp:end func_L01_004785E8 */

INCLUDE_ASM("asm/levels", func_L01_00478608);

/* localdecomp:start func_L01_00478898 */
extern void func_L01_00478898(void);
extern void *func_003E6C08();

extern void func_003E69F8(void *);
extern u8 D_L01_001E15E0[];
 
void func_L01_00478898(void) {
    void *x = D_L01_001E15E0;
    if (*(s32 *)((u8 *)x + 0x4) == 0) {
        x = func_003E6C08();
    }
    func_003E69F8(x);
}
/* localdecomp:end func_L01_00478898 */

/* localdecomp:start func_L01_004788D0 */
typedef struct {
    u8 pad0[0x38];
    u16 icon;       /* 0x38 */
    u8 pad3A[0x8A - 0x3A];
    u16 max_ammo;   /* 0x8A */
    u8 pad8C[0xF0 - 0x8C];
} GunRow_004788D0;
typedef struct {
    u8 pad0[0x14];
    s32 recent_guns[2]; /* 0x14: recent_guns[1] and [2] */
} Game_004788D0;
/* Ps2EeAs only uses $gp for these if it knows they are small before the use. */
__asm__(".extern D_L01_001D8048, 1");
__asm__(".extern D_L01_001D8049, 1");
extern u8 D_L01_001D8048;
extern u8 D_L01_001D8049;
extern s32 D_L01_001D6694;       /* no size hint: Ps2EeAs reads it with `lui` */
extern u8 D_001425C0[];
extern s32 D_001427F0[];
extern s32 D_00142660[];
extern u8 D_L01_002C5600[];
extern u8 D_L01_001E15E0[];
extern s32 func_003E82F8(void);   /* its (unused) result keeps $v0 busy: the next temporary is $v1 */
extern void *func_003E6C08();
extern s32 func_003E6A60(void *);
extern void *func_003E6518(s32);
extern void func_003E6F18(void *, s32);
extern s32 func_L01_004785E8(void);
extern void func_L01_0047B798(s32, s32);
extern void func_L01_0047B820(s32, s32);
extern void func_L01_0047B9B8(s32);
extern void func_L01_0047C220(s32);

typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; } List_004788D0;

/* hud_weapon_fill: each gameplay frame with a hand item other than the wrench: its icon,
   recent_guns[1] and [2] smaller, the ammo, the XP bar and V label; keeps the weapon HUD
   up for 20 more frames. The game block's address is written at each read (a pointer local
   would tie the recent gun to its register). */
void func_L01_004788D0(void) {
    List_004788D0 *group;
    List_004788D0 *list;
    s32 item;

    if (D_L01_001D8049 != 0) {
        return;
    }
    func_003E82F8();
    list = (List_004788D0 *)D_L01_001E15E0;
    if (list->x4) group = list;
    else group = func_003E6C08(list);
    func_003E6A60(group);
    if (D_L01_001D6694 != 5 && D_L01_001D8048 == 0) {
        item = func_L01_004785E8();
        if (item != 0) {
            func_L01_0047B798(((GunRow_004788D0 *)D_L01_002C5600)[D_001425C0[item]].icon, 0);
            if (((Game_004788D0 *)D_00142660)->recent_guns[0] != 0) {
                func_L01_0047B798(((GunRow_004788D0 *)D_L01_002C5600)[D_001425C0[((Game_004788D0 *)D_00142660)->recent_guns[0]]].icon, 1);
            } else {
                func_L01_0047B798(0, 1);
            }
            if (((Game_004788D0 *)D_00142660)->recent_guns[1] != 0) {
                func_L01_0047B798(((GunRow_004788D0 *)D_L01_002C5600)[D_001425C0[((Game_004788D0 *)D_00142660)->recent_guns[1]]].icon, 2);
            } else {
                func_L01_0047B798(0, 2);
            }
            func_L01_0047B820(D_001427F0[item], ((GunRow_004788D0 *)D_L01_002C5600)[D_001425C0[item]].max_ammo);
            func_L01_0047B9B8(item);
            func_L01_0047C220(8);
        }
    }
    D_L01_001D8048 = 0;
    func_003E6F18(func_003E6518(0), 20);
}
/* localdecomp:end func_L01_004788D0 */

/* localdecomp:start func_L01_00478AA0 */
extern void func_L01_00478AA0(void);
extern void *func_003E6C08();

extern void func_003E6A98(void *);
extern u8 D_L01_001E15E0[];
 
void func_L01_00478AA0(void) {
    void *x = D_L01_001E15E0;
    if (*(s32 *)((u8 *)x + 0x4) == 0) {
        x = func_003E6C08();
    }
    func_003E6A98(x);
}
/* localdecomp:end func_L01_00478AA0 */

/* localdecomp:start func_L01_00478AD8 */
extern void func_L01_00478AD8(void);
extern void *func_003E6C08();

extern void func_003E6B28(void *);
extern u8 D_L01_001E15E0[];
 
void func_L01_00478AD8(void) {
    void *x = D_L01_001E15E0;
    if (*(s32 *)((u8 *)x + 0x4) == 0) {
        x = func_003E6C08();
    }
    func_003E6B28(x);
}
/* localdecomp:end func_L01_00478AD8 */
