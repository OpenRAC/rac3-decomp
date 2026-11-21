#include "common.h"

/* NTSC-U counterpart of func_L01_004E2C48 (src/levels/shared/L01_004DF428.c): flash below 30 frames for 25, gun table at 0x2C5640 */
/* localdecomp:start func_L01_004DEE80 */
typedef struct {
    u8 pad0[4688];
    s32 f1250;
    u8 pad1254[36];
    s32 f1278;
    u8 pad127C[4932];
    s32 f25C0;
} G_004DEE80;
typedef struct {
    u8 pad0[0x1B8]; s32 timer;
    u8 pad1BC[0x1200 - 0x1BC]; u8 *attachment;
    u8 pad1204[0x1228 - 0x1204]; s32 weapon;
    u8 pad122C[0x25C0 - 0x122C]; u8 *moby; s32 state;
    u8 pad25C8[0x2818 - 0x25C8]; unsigned long saved_color; s32 flashing;
} Hero_004DEE80;
typedef struct {
    u8 b0; u8 active;
    u8 pad2[0xF0 - 2];
} Gun_004DEE80;
extern G_004DEE80 D_001A4BE0;
extern u8 D_001425C0[];
extern u8 D_L01_002C5640[];
extern void func_003C1A60(u8 *, s32 *, s32 *, s32 *);
extern void func_L01_00438908(u8 *, s32, s32, s32);
extern void func_L01_004DE980(void);
extern void func_L01_004DEA00_004DEE80(u8 *, u8 *);

void func_L01_004DEE80(void) {
    s32 r, g, b;
    s32 flash = 0;

    if ((*(Hero_004DEE80 *)&D_001A4BE0).state == 0x82 ||
        (*(Hero_004DEE80 *)&D_001A4BE0).state == 0xB1 ||
        (*(Hero_004DEE80 *)&D_001A4BE0).state == 0x84) {
        flash = (*(Hero_004DEE80 *)&D_001A4BE0).timer < 30;
    }
    if (flash) {
        if (!(*(Hero_004DEE80 *)&D_001A4BE0).flashing) {
            (*(Hero_004DEE80 *)&D_001A4BE0).saved_color =
                *(unsigned long *)((*(Hero_004DEE80 *)&D_001A4BE0).moby + 0x38);
            (*(Hero_004DEE80 *)&D_001A4BE0).flashing = 1;
        }
        func_003C1A60((*(Hero_004DEE80 *)&D_001A4BE0).moby, &r, &g, &b);
        if ((*(Hero_004DEE80 *)&D_001A4BE0).timer % 4 < 3) {
            r = 0;
            g = 0;
            b = 0;
        } else {
            r = 0x90;
            g = 0x90;
            b = 0xF0;
        }
        func_L01_00438908((*(Hero_004DEE80 *)&D_001A4BE0).moby, r, g, b);
        func_L01_004DE980();
    } else if ((*(Hero_004DEE80 *)&D_001A4BE0).flashing) {
        *(unsigned long *)((*(Hero_004DEE80 *)&D_001A4BE0).moby + 0x38) =
            (*(Hero_004DEE80 *)&D_001A4BE0).saved_color;
        (*(Hero_004DEE80 *)&D_001A4BE0).flashing = 0;
    }
    if ((*(Hero_004DEE80 *)&D_001A4BE0).weapon >= 0 &&
        ((Gun_004DEE80 *)D_L01_002C5640)[D_001425C0[(*(Hero_004DEE80 *)&D_001A4BE0).weapon]].active &&
        (*(Hero_004DEE80 *)&D_001A4BE0).attachment) {
        func_L01_004DEA00_004DEE80((*(Hero_004DEE80 *)&D_001A4BE0).attachment,
                          (*(Hero_004DEE80 *)&D_001A4BE0).moby);
    }
}
/* localdecomp:end func_L01_004DEE80 */
