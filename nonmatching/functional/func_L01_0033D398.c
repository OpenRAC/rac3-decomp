/* functional: medium. 252 diff words at the file's flags (frame 0xA0 vs 0xB0, register allocation, jump-table form); control flow, 5-state jump table (read from the retail ELF: 0->0x33D490 falling into 1->0x33D498, 2->D5B8, 3->D6F4, 4->D728), packet layout and store order around func_0038CFB8 checked block by block. The out vector at sp+0x10 is read uninitialised when hero+0x25C4 != 1, as in retail. */
typedef struct { f32 x, y, z, w; } V4;
typedef int Q16 __attribute__((mode(TI)));
extern u8 D_001A4BE0[];
extern u8 D_L01_00278BC0[];
extern u8 D_L01_001E18A0;
extern u8 D_L01_001E18B0;
extern u8 D_L01_001E29C0;
extern u8 D_L01_002C5600[];
extern u8 D_001425D2[];
extern u8 *D_001D52FC[];
extern s32 D_001DCFDC_sda;
extern void func_003C2F58(u8 *, s32, void *);
extern void func_L01_005003D0(s32, s32, void *);
extern f32 func_0038CF00(void *, void *);
extern void func_L01_003F6F20(s32, u8 *, u32, void *, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32);
extern void func_L01_004EA7D8(s32);
extern s32 func_0038CAD0(void *);
extern void func_0038CFB8(void *, void *, f32);
extern void func_L01_00446978(u8 *, void *);
extern void func_L01_0033D940(u8 *, u8 *, s32);
extern void func_L01_0033DBE8(u8 *);
extern void func_L01_0033D780(void *);
extern void func_L01_00404A10(void (*)(void *), void *);

void func_L01_0033D398(u8 *m) {
    u8 *hero;
    u8 *p;
    s32 i;
    f32 d;
    /* sp+0x0 vector, sp+0x10 out vector, sp+0x20 position, sp+0x30 packet */
    struct {
        V4 v0;
        V4 v10;
        V4 v20;
        u8 pk[0x30];
    } s;
    *(Q16 *)&s.v0 = 0;
    if (m[0x20] == 0) {
        for (i = 2; i >= 0; i--) {
            *(s32 *)(D_L01_00278BC0 + i * 0xA0 + 0x8C) = 0;
        }
        m[0x20] = 1;
    }
    func_003C2F58(m, 1, &D_L01_001E18A0);
    func_003C2F58(m, 0, &D_L01_001E18B0);
    hero = D_001A4BE0;
    if (*(s32 *)(hero + 0x25C4) == 1) {
        func_L01_005003D0(0x1D, 1, &s.v10);
    }
    func_003C2F58(m, 0, &s.v10);
    switch (m[0x20]) {
    case 0:
        m[0x20] = 1;
        /* fall through */
    case 1:
        if (hero[0x25ED] != 0) {
            break;
        }
        p = *(u8 **)(hero + 0xAC0);
        if (p != 0) {
            d = func_0038CF00(&D_L01_001E29C0, p + 0x10);
            d = 0.9f - d / 50.0f * 0.65f;
            if (d < 0.0f) {
                d = -d;
            }
            *(Q16 *)&s.v20 = *(Q16 *)(p + 0x10);
            func_L01_003F6F20(0, m, 0xFF0FFF0F, &s.v20, 0x26, -1, 4, d, 0.0f, 90.0f, 0.5f, 0.5f, 40.0f, 40.0f);
            p = *(u8 **)(hero + 0xAC0);
            s.v0.x = ((V4 *)(p + 0x10))->x - s.v10.x;
            s.v0.y = ((V4 *)(p + 0x10))->y - s.v10.y;
            s.v0.z = ((V4 *)(p + 0x10))->z - s.v10.z;
            s.v0.w = ((V4 *)(p + 0x10))->w;
        }
        if ((*(s32 *)(D_001D52FC[0] + 0x1A4) & *(s32 *)(hero + 0x1210)) == 0) {
            break;
        }
        if (*(u8 **)(hero + 0xAC0) == 0) {
            break;
        }
        D_001DCFDC_sda = (*(s32 *)(hero + 0x360) != 0) ? 10 : 3;
        m[0x20] = 2;
        func_L01_004EA7D8(-1);
        break;
    case 2:
        if (func_0038CAD0(&D_001DCFDC_sda) == 0) {
            break;
        }
        *(s32 *)(s.pk + 0x14) = 0x10000;
        *(s32 *)(s.pk + 0x20) = 1;
        *(f32 *)(s.pk + 0x1C) = *(f32 *)(D_L01_002C5600 + D_001425D2[0] * 0xF0 + 0x6C);
        *(Q16 *)(s.pk + 0x0) = *(Q16 *)&s.v0;
        *(u8 **)(s.pk + 0x10) = m;
        *(s32 *)(hero + 0xC00) = 0;
        func_0038CFB8(s.pk, s.pk, 1.0f);
        *(u8 *)(s.pk + 0x19) = 2;
        *(f32 *)(s.pk + 0x8) = 1.0f;
        *(f32 *)(s.pk + 0xC) = 5627.9248046875f;
        *(u16 *)(s.pk + 0x1A) = *(u16 *)(m + 0xAA);
        *(u8 *)(s.pk + 0x18) = 3;
        func_L01_00446978(*(u8 **)(hero + 0xAC0), s.pk);
        m[0x20] = 3;
        if (*(s32 *)(hero + 0x360) != 0) {
            D_001DCFDC_sda = 12;
            func_L01_0033D940(m, *(u8 **)(hero + 0xAC0), 6);
            func_L01_0033D940(m, *(u8 **)(hero + 0xAC0), 6);
            func_L01_0033D940(m, *(u8 **)(hero + 0xAC0), 6);
        } else {
            D_001DCFDC_sda = 2;
            func_L01_0033D940(m, *(u8 **)(hero + 0xAC0), 2);
            func_L01_0033D940(m, *(u8 **)(hero + 0xAC0), 2);
            func_L01_0033D940(m, *(u8 **)(hero + 0xAC0), 2);
        }
        *(s32 *)(hero + 0xAC0) = 0;
        break;
    case 3:
        if (func_0038CAD0(&D_001DCFDC_sda) != 0) {
            *(f32 *)(hero + 0xC00) = 1.0f;
            D_001DCFDC_sda = 6;
            m[0x20] = 4;
        }
        break;
    case 4:
        if (func_0038CAD0(&D_001DCFDC_sda) != 0) {
            m[0x20] = 1;
        }
        break;
    }
    func_L01_0033DBE8(m);
    func_L01_00404A10(func_L01_0033D780, m);
}
