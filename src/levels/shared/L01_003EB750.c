#include "common.h"

typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    u8 pad[1120];
} Ent1120;
typedef int q128 __attribute__((mode(TI)));
typedef struct { u8 pad[0x120]; f32 x120[3]; } V_3E3730;
typedef struct { u8 pad[0x70]; V_3E3730 *x70; } O_3E3730;
typedef struct {
    u8 pad[80];
    u8 *p50;
    u8 pad2[1036];
} Entry_3E6C58;
typedef struct {
    u8 pad[80];
    u8 *p50;
    u8 pad2[1036];
} Entry_3E6CA8;
typedef struct {
    u8 pad[28];
    u8 *p1C;
} M_3E6CA8;
typedef struct {
    u8 pad[80];
    u8 *p;
    u8 pad2[1120 - 84];
} S_003E7430;
typedef struct {
    u8 pad[588];
    s32 v;
    u8 pad2[1120 - 592];
} Unk003E8810;
typedef int s128_003E8C50 __attribute__((mode(TI)));
typedef struct {
    u8 pad[512];
    u8 data[48];
    s128_003E8C50 q;
    u8 pad2[1120 - 576];
} Slot_003E8C50;
typedef struct {
    u8 pad[56];
    u8 a38[4];
    u8 a3C[4];
} Base_003E8C50;
typedef struct {
    u8 pad[28];
    Base_003E8C50 *p;
} Ent_003E8C50;
typedef struct {
    u8 pad[48];
    s128_003E8C50 q30;
    u8 pad2[112 - 64];
    s32 *f70;
    u8 pad3[10];
    s16 h7E;
    u8 pad4[4];
    s16 h84;
    u8 pad5[14];
    s32 f94;
} Obj_003E8C50;
typedef int u128_3E8D18 __attribute__((mode(TI)));
typedef struct { u8 pad[0x200]; u8 x200[0x30]; u128_3E8D18 x230; u8 pad240[0x2A0 - 0x240]; s16 x2A0; u8 pad2A2[0x2C0 - 0x2A2]; f32 x2C0; u8 pad2C4[1120 - 0x2C4]; } E_3E8D18;
typedef struct { u8 pad[0x25E5]; u8 x25E5; } G_3E8D18;
typedef struct { u8 pad[0x30]; u128_3E8D18 x30; u8 pad40[0x94 - 0x40]; s32 x94; } O_3E8D18;
typedef struct {
    u8 pad0[292];
    s32 w124;
    u8 pad128[672 - 296];
    s16 h2A0;
    u8 b2A2;
    u8 b2A3;
    u8 pad2A4[696 - 676];
    f32 f2B8;
    u8 pad2BC[712 - 700];
    f32 f2C8;
    u8 pad2CC[1120 - 716];
} Entry_3E92A8;
typedef int u128_003E94A0 __attribute__((mode(TI)));
typedef struct { u8 pad[80]; u8 *o; u8 pad2[1036]; } Slot_003E94A0;
typedef int u128_003E9510 __attribute__((mode(TI)));
typedef struct { u8 pad[80]; u8 *o; u8 pad2[1036]; } Slot_003E9510;

typedef struct {
    u8 pad[0x70];
    u8 *x70;
    u8 pad2[0x86 - 0x74];
    s16 h86;
} Q_003E8F20;

typedef struct {
    u8 pad00[0x10];
    u32 flags;
    f32 f14;
    u8 pad18[4];
    f32 f1C;
    u8 pad20[4];
    f32 f24;
} Input_003E92F8;
typedef struct {
    u8 pad00[0x134];
    f32 *p134;
} Ent_003E92F8;
typedef struct {
    u8 pad00[0x60];
    u16 count;
    u8 pad62[2];
    u32 best;
    u32 flags;
} Counter_003E92F8;
typedef struct {
    s32 v;
    u8 pad[0x1C];
} Pad_003E92F8;

typedef struct {
    u8 pad0[0x24C];
    s32 x24C;
    u8 pad1[0x2A0 - 0x250];
    s16 h2A0;
    u8 pad2[0x2A3 - 0x2A2];
    u8 b2A3;
    u8 pad3[0x2B8 - 0x2A4];
    f32 f2B8;
    f32 f2BC;
    f32 f2C0;
    f32 f2C4;
    f32 f2C8;
    f32 f2CC;
    u8 pad4[1120 - 0x2D0];
} Ent_003EB200;

/* localdecomp:start func_L01_003EB750 */
typedef struct { u8 pad[0x150]; s16 width, height; } Screen_003EB750;
extern Screen_003EB750 D_L01_001CFEC0;
extern s32 D_L01_001D5520;
__asm__(".extern D_L01_001DF718, 4");
__asm__(".extern D_L01_001DF710, 4");
__asm__(".extern D_L01_001DF714, 4");
extern s32 D_L01_001DF718;
extern s32 D_L01_001DF710;
extern s32 D_L01_001DF714;
void func_L01_003EB750(void) {
    extern void func_L01_004C5E28(void);
    extern void func_003A9440(s32, unsigned long);
    extern unsigned long func_00389598(s32);
    extern void func_0038B4D0(s32, s32, s32, s32, s32, s32, s32, s32, unsigned long, unsigned long);
    unsigned long texture, last_texture;
    func_L01_004C5E28();
    if (D_L01_001D5520) {
        D_L01_001DF718 = -1;
        D_L01_001DF710 = 236;
        D_L01_001DF714 = 240;
    }
    func_003A9440(0x47, 0x513F1);
    func_003A9440(0x42, 0x800000006AUL);
    texture = func_00389598(0x42);
    func_0038B4D0(0, 0, (s32)(D_L01_001CFEC0.width * 0.5f), (s32)(D_L01_001CFEC0.height * 0.5f), 0, 0, 255, 255, 0x647F7F7F, texture);
    func_0038B4D0(D_L01_001CFEC0.width, 0, -(s32)(D_L01_001CFEC0.width * 0.5f), (s32)(D_L01_001CFEC0.height * 0.5f), 0, 0, 255, 255, 0x647F7F7F, texture);
    func_0038B4D0(0, D_L01_001CFEC0.height, (s32)(D_L01_001CFEC0.width * 0.5f), -(s32)(D_L01_001CFEC0.height * 0.5f), 0, 0, 255, 255, 0x647F7F7F, texture);
    func_0038B4D0(D_L01_001CFEC0.width, D_L01_001CFEC0.height, -(s32)(D_L01_001CFEC0.width * 0.5f), -(s32)(D_L01_001CFEC0.height * 0.5f), 0, 0, 255, 255, 0x647F7F7F, texture);
    func_003A9440(0x42, 0x800000006AUL);
    func_003A9440(0x42, 0x8000000054UL);
    last_texture = func_00389598(D_L01_001DF718);
    func_0038B4D0(0, 0, D_L01_001CFEC0.width, D_L01_001CFEC0.height, 10, 8, D_L01_001DF710, D_L01_001DF714, 0x7F6F6F6F, last_texture);
}
/* localdecomp:end func_L01_003EB750 */
