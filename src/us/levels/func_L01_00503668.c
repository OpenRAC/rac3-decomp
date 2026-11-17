#include "common.h"

/* NTSC-U counterpart of func_L01_005075D8 (src/levels/shared/L01_005063E8.c) */
typedef struct {
    u8 pad0[0x1A0];
    u32 held;                       
    s32 pressed;                    
    u8 pad1A8[0x1B8 - 0x1A8];
    s32 released;                   
} Pad_5075D8;
extern u8 D_001A4BE0[];
extern u8 D_001A4BE0[];
extern u8 D_001A4BE0[];
extern Pad_5075D8 *D_001D52FC;
extern u8 D_001A4BE0[];

/* localdecomp:start func_L01_00503668 */
typedef struct {
    u8 pad0[0x25C4];
    s32 state;
    u8 pad25C8[0x25ED - 0x25C8];
    u8 no_firing;
    u8 pad25EE[0x2880 - 0x25EE];
    s16 quick_switch_tap[2];
    u8 pad2884[0x28C0 - 0x2884];
    u8 quick_switch_request; /* taken by hero_quick_switch */
} Hero_5075D8;
extern u8 D_001A4BE0[];
extern Pad_5075D8 *D_001D52FC;
extern s32 D_L01_002D1630[];
extern s32 D_L01_002E5F70[];
extern void func_003883C8(void *a0);
extern void func_L01_0041FD00(void);

/* hero_quick_switch_button: Triangle pressed opens a 20-frame window; released inside it, asks for a quick switch */
void func_L01_00503668(void) {
    s16 *tap = ((Hero_5075D8 *)D_001A4BE0)->quick_switch_tap;
    Hero_5075D8 *hero = (Hero_5075D8 *)D_001A4BE0;
    s32 state;

    func_003883C8(&tap[0]);
    func_003883C8(&tap[1]);
    state = hero->state;
    if (state == 0x37 || state == 0x13 || state == 0x15 || state == 0x88 || state == 0x14) {
        return;
    }
    if (hero->no_firing != 0) {
        return;
    }
    if (D_L01_002D1630[0] != 0) {
        return;
    }
    if (D_L01_002E5F70[0] != 0 || D_L01_002E5F70[9] != -1) {
        return;
    }
    if (D_001D52FC->pressed & 0x10) {
        hero->quick_switch_tap[0] = 20; /* frames */
    }
    if (hero->quick_switch_tap[0] != 0 && (D_001D52FC->released & 0x10)) {
        hero->quick_switch_request = 1;
        func_L01_0041FD00();
        if (hero->quick_switch_tap[1] == 0) {
            hero->quick_switch_tap[1] = 20;
        }
    }
}
/* localdecomp:end func_L01_00503668 */
