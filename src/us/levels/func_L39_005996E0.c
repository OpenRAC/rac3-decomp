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

/* localdecomp:start func_L39_005996E0 */
extern State_0059AA38 D_L39_00498AA0;


extern Cfg_0059AA38 D_001A5990;
extern s32 *D_L39_002412A0;
extern s32 D_L39_002415CC;
extern s32 D_L39_00240484;
extern Entry_0059AA38 *D_L39_0024BDC0;
__asm__(".extern D_001D7360_sda, 4");
__asm__(".extern D_001D7364_sda, 4");
__asm__(".extern D_001D7368_sda, 4");
__asm__(".extern D_001D736C_sda, 4");
__asm__(".extern D_001D7370_sda, 4");
__asm__(".extern D_001D7374_sda, 4");
__asm__(".extern D_001D7378_sda, 4");
__asm__(".extern D_001D737C_sda, 4");
__asm__(".extern D_001D7380_sda, 4");
__asm__(".extern D_001D7384_sda, 4");
__asm__(".extern D_001D7388_sda, 4");
__asm__(".extern D_001D738C_sda, 4");
__asm__(".extern D_001D7390_sda, 4");
__asm__(".extern D_001D7394_sda, 4");
__asm__(".extern D_001D7398_sda, 4");
__asm__(".extern D_001D739C_sda, 4");
extern s32 D_001D7360_sda;
extern s32 D_001D7364_sda;
extern s32 D_001D7368_sda;
extern s32 D_001D736C_sda;
extern s32 D_001D7370_sda;
extern s32 D_001D7374_sda;
extern s32 D_001D7378_sda;
extern s32 D_001D737C_sda;
extern s32 D_001D7380_sda;
extern s32 D_001D7384_sda;
extern s32 D_001D7388_sda;
extern s32 D_001D738C_sda;
extern s32 D_001D7390_sda;
extern s32 D_001D7394_sda;
extern s32 D_001D7398_sda;
extern s32 D_001D739C_sda;
__asm__(".extern D_001D73A0_sda, 8");
extern s32 D_001D73A0_sda[2];

extern void func_L39_005F0E48(s32, s32, s32);
extern s32 func_L39_00588720(s32);
extern s32 func_120884(s32);
extern void func_0038C888(u16 *p, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h);
extern void func_0038C9B8(u16 *p, long a, s32 b, s32 c, s32 d, s32 e, f32 f, unsigned long g);
extern void func_00389920(s32);

/* Opens a menu entry's widget: marks it active with a zero timer, picks its layout rectangle values
 * by the player mode (fixed defaults, or the stored sets for modes 2 and 4) and fills a metrics
 * array. */
void func_L39_005996E0(void) {
    u16 metrics[16];
    s32 id;
    s32 mode;
    s32 x, y, w, h, e, f, g;
    s32 screenH;

    D_L39_00498AA0.active = 1;
    D_L39_00498AA0.timer = 0;
    if (D_001A5990.flag != 0) {
        func_L39_005F0E48(0, 1, 0);
    }
    id = D_L39_0024BDC0[D_L39_00498AA0.entryIndex].unk00;
    mode = *D_L39_002412A0;
    x = 0xF0;
    y = 0x1E0;
    w = 0x2C;
    h = D_001D7364_sda + 0x1D4;
    e = D_001D7360_sda + 0x100;
    f = 0x168;
    g = 0x10;
    if (mode == 2) {
        x = D_001D7368_sda;
        y = D_001D736C_sda;
        w = D_001D7370_sda;
        h = D_001D7374_sda;
        e = D_001D7378_sda;
        f = D_001D737C_sda;
        g = D_001D7380_sda;
    } else if (mode == 4) {
        x = D_001D7384_sda;
        y = D_001D7388_sda;
        w = D_001D738C_sda;
        h = D_001D7390_sda;
        e = D_001D7394_sda;
        f = D_001D7398_sda;
        g = D_001D739C_sda;
    }
    func_0038C888(metrics, x, y, w, h, e, f, g, 7);
    metrics[9] |= 0x20;
    metrics[12] = 2;
    metrics[13] = 2;
    func_00389920(1);
    func_0038C9B8(metrics, 0x8066CCFFL, id, -1, func_L39_00588720(1), D_L39_002415CC, 1.0f, 0x80000000UL);
    D_L39_00498AA0.unk08 = ((s16)metrics[6] >> 1) + 10;
    D_L39_00498AA0.unk0C = ((s16)metrics[7] >> 1) + 5;
    D_L39_00498AA0.unk10 = e;
    D_L39_00498AA0.unk14 = D_001D73A0_sda[D_001A5990.index];
    D_L39_00498AA0.unk18 = 8;
    D_L39_00498AA0.unk1C = 8;
    D_L39_00498AA0.unk48 = 0;
    if (id != 0) {
        D_L39_00498AA0.unk48 = func_120884(id) * 7;
    }
    screenH = D_L39_00240484;
    D_L39_00498AA0.unk14 = screenH - 0x3C;
    if (screenH - 0xC < D_L39_00498AA0.unk14 + D_L39_00498AA0.unk0C) {
        s32 bottom = D_L39_00498AA0.unk0C + 0xC;
        D_L39_00498AA0.unk14 = screenH - bottom;
    }
}
/* localdecomp:end func_L39_005996E0 */
