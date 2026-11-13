#include "common.h"

/* NTSC-U counterpart of func_L01_004788D0 (src/levels/shared/L01_004783E0.c): 8 -> 10 */
extern void *func_003E6C08();
extern u8 D_L01_001E1660[];

/* localdecomp:start func_L01_00475078 */
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
__asm__(".extern D_L01_001D8048_00475078, 1");
__asm__(".extern D_L01_001D8049_00475078, 1");
extern u8 D_L01_001D8048_00475078;
extern u8 D_L01_001D8049_00475078;
extern s32 D_L01_001D6694_00475078;       /* no size hint: Ps2EeAs reads it with `lui` */
extern u8 D_001425C0[];
extern s32 D_001427F0[];
extern s32 D_00142660[];
extern u8 D_L01_002C5640[];
extern u8 D_L01_001E1660[];
extern s32 func_003E82F8(void);   /* its (unused) result keeps $v0 busy: the next temporary is $v1 */
extern void *func_003E6C08();
extern s32 func_003E6A60(void *);
extern void *func_003E6518(s32);
extern void func_003E6F18(void *, s32);
extern s32 func_L01_00474D90(void);
extern void func_L01_00477F48(s32, s32);
extern void func_L01_00477FD0(s32, s32);
extern void func_L01_00478168(s32);
extern void func_L01_004789D0(s32);

typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; } List_004788D0;

/* hud_weapon_fill: each gameplay frame with a hand item other than the wrench: its icon,
   recent_guns[1] and [2] smaller, the ammo, the XP bar and V label; keeps the weapon HUD
   up for 20 more frames. The game block's address is written at each read (a pointer local
   would tie the recent gun to its register). */
void func_L01_00475078(void) {
    List_004788D0 *group;
    List_004788D0 *list;
    s32 item;

    if (D_L01_001D8049_00475078 != 0) {
        return;
    }
    func_003E82F8();
    list = (List_004788D0 *)D_L01_001E1660;
    if (list->x4) group = list;
    else group = func_003E6C08(list);
    func_003E6A60(group);
    if (D_L01_001D6694_00475078 != 5 && D_L01_001D8048_00475078 == 0) {
        item = func_L01_00474D90();
        if (item != 0) {
            func_L01_00477F48(((GunRow_004788D0 *)D_L01_002C5640)[D_001425C0[item]].icon, 0);
            if (((Game_004788D0 *)D_00142660)->recent_guns[0] != 0) {
                func_L01_00477F48(((GunRow_004788D0 *)D_L01_002C5640)[D_001425C0[((Game_004788D0 *)D_00142660)->recent_guns[0]]].icon, 1);
            } else {
                func_L01_00477F48(0, 1);
            }
            if (((Game_004788D0 *)D_00142660)->recent_guns[1] != 0) {
                func_L01_00477F48(((GunRow_004788D0 *)D_L01_002C5640)[D_001425C0[((Game_004788D0 *)D_00142660)->recent_guns[1]]].icon, 2);
            } else {
                func_L01_00477F48(0, 2);
            }
            func_L01_00477FD0(D_001427F0[item], ((GunRow_004788D0 *)D_L01_002C5640)[D_001425C0[item]].max_ammo);
            func_L01_00478168(item);
            func_L01_004789D0(10);
        }
    }
    D_L01_001D8048_00475078 = 0;
    func_003E6F18(func_003E6518(0), 20);
}
/* localdecomp:end func_L01_00475078 */
