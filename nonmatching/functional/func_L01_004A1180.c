/* functional: high. Near miss: 187 words differ only because the two div.s after the 0.588/ratio branch need the config divs_nops padding (row func_L01_004A1180 0 2 1); otherwise same code. Draft in nonmatching/levels re-verified line by line against PAL asm. */
typedef struct {
    s32 id;
    s32 a;
    s32 b;
    s32 c;
    s32 d;
    u8 enabled;
    u8 pad[3];
} Entry_004A1180;
extern Entry_004A1180 D_L01_002ED850[];
extern char D_L01_002ED898[];
extern f32 D_L01_001DC0E8;
extern s32 D_001D9660_sda;
extern s32 D_001D965C_sda;
extern s32 D_001D9658_sda;
__asm__(".extern D_001D9660_sda, 4\n.extern D_001D965C_sda, 4\n.extern D_001D9658_sda, 4");
extern void func_L01_004A1CA8(void);
extern void func_L01_004A1910(void);
extern void func_L01_004A1F78(void);
extern void func_L01_004A1E18(void);
extern void func_L01_004A1630(void *);
extern void func_L01_00518010(s32, s32);
extern void func_L01_00516D60(s32, s32);
extern void func_L01_00517190(s32, s32);
extern void func_L01_00517538(s32, f32, f32);
extern s32 func_00381FF0(s32);
extern s32 func_0038E548(char *, s32, f32);
extern f32 func_003C4088(f32, f32, f32);
extern void func_003B9298(s32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_003E8FE8(s32, s32, s32, f32, f32, f32, f32);
extern void func_003E7F20(s32, s32);
extern void func_003E8A08(s32, s32, s32);
extern void func_003E8898(s32, f32, f32);
extern void func_003E8348(s32, s32);
extern void func_003E8710(s32, void *);
extern void func_003E87B8(s32, s32, s32);
void func_L01_004A1180(void) {
    s32 i = 0;
    s32 scaled = 0;
    s32 selected;
    f32 ratio;
    f32 scale;
    f32 resize = 0.0f;
    f32 min = 0.0f;
    f32 max = 0.49f;
    f32 low = 6.0f;
    f32 high = 11.0f;
    Entry_004A1180 *p;
    Entry_004A1180 *q;
    func_L01_004A1CA8();
    ratio = (f32)func_0038E548((char *)func_00381FF0(0x106), -1, 1.2f) / D_L01_001DC0E8;
    if (max < ratio) {
        resize = 0.588000059f / ratio;
        scaled = 1;
        ratio = max;
    }
    ratio = (ratio - min) / (max - min);
    scale = func_003C4088(low, high, ratio);
    if (high < scale) {
        scale = high;
    } else if (scale < low) {
        scale = low;
    }
    func_003B9298(0x10, scale, 0xD000B, 0xD0000, 0xD0001, 0xD0002, 0xD0003, 0xD0004, 0xD0005, 0xD0008,
                  func_00381FF0(0x106), 0xD0006, 0x124, 0xD0007, 0xCD5);
    func_003E8FE8(0xD0009, func_00381FF0(0x1B80), 0x8066CCFF, 0.035f, 0.5f, 1.0f, 1.0f);
    func_003E7F20(0xD0009, 1);
    func_003E8FE8(0xD000A, func_00381FF0(0x1B81), 0x8066CCFF, 0.97f, 0.5f, 1.0f, 1.0f);
    func_003E7F20(0xD000A, 1);
    func_003E8A08(0xD000B, 0xD0009, 0xD000A);
    if (scaled) {
        func_L01_00517538(0xD0005, resize, resize);
    }
    func_L01_004A1630(D_L01_002ED898);
    func_L01_00518010(0x570005, 1);
    func_003E8898(0x570005, 0.49f, 0.0f);
    func_003E8348(0x11, 0x570000);
    func_003E7F20(0x570006, 1);
    func_003E8710(0x570009, func_003B42F8(0));
    func_L01_004A1910();
    func_L01_004A1F78();
    D_001D9660_sda = -1;
    p = &D_L01_002ED850[i];
    if (p->id) {
        selected = -1;
        q = p;
        do {
            if (q->enabled) {
                selected = i;
            }
            q++;
            i++;
        } while (q->id && selected < 0);
        D_001D9660_sda = selected;
    }
    if (D_001D9660_sda < 0 && D_001D965C_sda) {
        D_001D9660_sda = 0;
    }
    func_L01_00516D60(0x570009, 0);
    func_L01_00517190(0x570009, 0);
    func_003E87B8(0x570009, 1, 8);
    D_001D9658_sda = -1;
    func_L01_004A1E18();
}
