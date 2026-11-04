#include "common.h"

typedef struct {
    s32 unk00;
    s32 pad04;
    s32 pad08;
    s32 pad0C;
} Entry_0059AA38;
typedef struct {
    s32 active;
    s32 timer;
    s32 unk08;
    s32 unk0C;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 entryIndex;
    s32 pad24[9];
    s32 unk48;
} State_0059AA38;
typedef struct {
    s32 index;
    u8 pad04;
    u8 flag;
    u8 pad06[10];
} Cfg_0059AA38;

LINKER_REMNANT("asm/levels", func_L39_0059AA30);

/* localdecomp:start func_L39_0059AA38 */
extern State_0059AA38 D_L39_004989E0;


extern Cfg_0059AA38 D_001A5810;
extern Entry_0059AA38 *D_L39_0024BCC0;
__asm__(".extern D_001D7360, 4");
__asm__(".extern D_001D7364, 4");
__asm__(".extern D_001D7368, 4");
__asm__(".extern D_001D736C, 4");
__asm__(".extern D_001D7370, 4");
__asm__(".extern D_001D7374, 4");
__asm__(".extern D_001D7378, 4");
__asm__(".extern D_001D737C, 4");
__asm__(".extern D_001D7380, 4");
__asm__(".extern D_001D7384, 4");
__asm__(".extern D_001D7388, 4");
__asm__(".extern D_001D738C, 4");
__asm__(".extern D_001D7390, 4");
__asm__(".extern D_001D7394, 4");
__asm__(".extern D_001D7398, 4");
__asm__(".extern D_001D739C, 4");
extern s32 D_001D7360;
extern s32 D_001D7364;
extern s32 D_001D7368;
extern s32 D_001D736C;
extern s32 D_001D7370;
extern s32 D_001D7374;
extern s32 D_001D7378;
extern s32 D_001D737C;
extern s32 D_001D7380;
extern s32 D_001D7384;
extern s32 D_001D7388;
extern s32 D_001D738C;
extern s32 D_001D7390;
extern s32 D_001D7394;
extern s32 D_001D7398;
extern s32 D_001D739C;
__asm__(".extern D_001D73A0, 8");
extern s32 D_001D73A0[2];

extern void func_L39_005F3548(s32, s32, s32);
extern s32 func_L39_00589890(s32);
extern s32 func_120884(s32);
extern void func_003910C0(u16 *p, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h);
extern void func_003911F0(u16 *p, long a, s32 b, s32 c, s32 d, s32 e, f32 f, unsigned long g);
extern void func_0038E150(s32);

void func_L39_0059AA38(void) {
    u16 metrics[16];
    s32 id;
    s32 mode;
    s32 x, y, w, h, e, f, g;
    s32 screenH;

    D_L39_004989E0.active = 1;
    D_L39_004989E0.timer = 0;
    if (D_001A5810.flag != 0) {
        func_L39_005F3548(0, 1, 0);
    }
    id = D_L39_0024BCC0[D_L39_004989E0.entryIndex].unk00;
    mode = **(s32 **)0x241120;
    x = 0xF0;
    y = 0x1E0;
    w = 0x2C;
    h = D_001D7364 + 0x1D4;
    e = D_001D7360 + 0x100;
    f = 0x168;
    g = 0x10;
    if (mode == 2) {
        x = D_001D7368;
        y = D_001D736C;
        w = D_001D7370;
        h = D_001D7374;
        e = D_001D7378;
        f = D_001D737C;
        g = D_001D7380;
    } else if (mode == 4) {
        x = D_001D7384;
        y = D_001D7388;
        w = D_001D738C;
        h = D_001D7390;
        e = D_001D7394;
        f = D_001D7398;
        g = D_001D739C;
    }
    func_003910C0(metrics, x, y, w, h, e, f, g, 7);
    metrics[9] |= 0x20;
    metrics[12] = 2;
    metrics[13] = 2;
    func_0038E150(1);
    func_003911F0(metrics, 0x8066CCFFL, id, -1, func_L39_00589890(1), *(s32 *)0x24144C, 1.0f, 0x80000000UL);
    D_L39_004989E0.unk08 = ((s16)metrics[6] >> 1) + 10;
    D_L39_004989E0.unk0C = ((s16)metrics[7] >> 1) + 5;
    D_L39_004989E0.unk10 = e;
    D_L39_004989E0.unk14 = D_001D73A0[D_001A5810.index];
    D_L39_004989E0.unk18 = 8;
    D_L39_004989E0.unk1C = 8;
    D_L39_004989E0.unk48 = 0;
    if (id != 0) {
        D_L39_004989E0.unk48 = func_120884(id) * 7;
    }
    screenH = *(s32 *)0x240304;
    D_L39_004989E0.unk14 = screenH - 0x3C;
    if (screenH - 0xC < D_L39_004989E0.unk14 + D_L39_004989E0.unk0C) {
        s32 bottom = D_L39_004989E0.unk0C + 0xC;
        D_L39_004989E0.unk14 = screenH - bottom;
    }
}
/* localdecomp:end func_L39_0059AA38 */

INCLUDE_ASM("asm/levels", func_L39_0059AC60);
