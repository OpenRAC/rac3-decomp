/* functional: high. Multiplayer-menu panel setup (a0 = menu object): marks the current player's slot, clears a 4-byte block, registers the widget ids 0x90000..0x90006 (0x90001/2 as one kind, 0x90003..6 as another), fills two with strings (func_L39_00611AC8 with func_00392A18 results, texts 0x52 and 0x53), sets sizes/positions per widget (two layouts depending on *D_00241120 == 2), colours, then clears the flag halfword (+0x4A) of the three child widgets 0x90003..0x90005 looked up through the manager (D_L39_0024CD50, or func_003E6C08 when it has no object; the +0x4A store goes through the looked-up pointer or null exactly as retail's dynamic-cast pattern), links all six to widget 0x90000, and ends by running func_003E8348(7, 0x90000), func_003E6FF0(a0, 1) and func_L39_005D6AE0. Float constants are retail's bit patterns written as decimals. */
/* localdecomp:start func_L39_005D6DC8 */
extern u8 D_001D7EE8_sda[];
extern u8 D_L39_0024C278[];
extern f32 D_001D7F00_sda;
extern f32 D_001D7F04_sda;
extern s32 D_001DA5F0_sda;
typedef struct { u8 p0[4]; s32 f4; } L39Mgr_5D6DC8;
extern L39Mgr_5D6DC8 D_L39_0024CD50 __attribute__((section(".data")));
extern void func_L01_004D2110(s32);
extern s32 func_003B5060(s32);
extern void func_003E5090(s32);
extern s32 func_003E51F8(s32);
extern s32 func_00392A18(void);
extern s32 func_L39_00611AC8(s32, s32, s32);
extern void func_L01_00517538(s32, f32, f32);
extern s32 func_L01_005170B8(s32, s32);
extern s32 func_L01_00516C78(s32, s32, s32);
extern void *func_003E6C08(void);
extern s32 func_003E6DE8(void *);
extern void *func_003E6378(s32, s32);
extern void func_003E8630(s32, s32);
extern s32 func_003E8348(s32, s32);
extern s32 func_L01_00517688(void);
extern void func_0038CB78(void *, s32, s32);
extern void func_003E6FF0(s32, s32);

static u8 *L39_005D6DC8_child(s32 id) {
    void *mgr;
    u8 *p;

    if (D_L39_0024CD50.f4 != 0) {
        mgr = &D_L39_0024CD50;
    } else {
        mgr = func_003E6C08();
    }
    p = func_003E6378(func_003E6DE8(mgr), id);
    if (p != 0 && (*(s32 (**)(void *, s32))(*(s32 *)(p + 8) + 0x10))(p, D_001DA5F0_sda) != 0) {
        return p;
    }
    return 0;
}

void func_L39_005D6DC8(s32 a0) {
    f32 f20, f21;
    s32 pl;

    pl = func_L01_00517688();
    D_001D7EE8_sda[pl] = 1;
    func_L01_004D2110(1);
    func_0038CB78(D_L39_0024C278, 0, 4);
    func_003B5060(0x90000);
    func_003E5090(0x90001);
    func_003E5090(0x90002);
    func_003E51F8(0x90006);
    func_003E51F8(0x90003);
    func_003E51F8(0x90004);
    func_003E51F8(0x90005);
    func_L39_00611AC8(0x90002, func_00392A18(), 0x52);
    func_L39_00611AC8(0x90001, func_00392A18(), 0x53);
    if (*D_00241120 == 2) {
        f21 = 0.085f;
        func_L01_00516470(0x90002, D_001D7F00_sda, D_001D7F04_sda);
        func_L01_00516470(0x90001, D_001D7F00_sda, D_001D7F04_sda);
        func_L01_00516470(0x90006, 0.358f, 0.095f);
        func_L01_00517538(0x90006, 0.28f, 0.07f);
    } else {
        f21 = 0.068f;
        func_L01_00516470(0x90006, 0.358f, 0.074f);
        func_L01_00517538(0x90006, 0.28f, 0.048f);
    }
    func_L01_00516470(0x90003, 0.52799f, f21);
    f20 = 0.035f;
    func_L01_00516470(0x90004, 0.48049f, f21);
    func_L01_00516470(0x90005, 0.43747f, f21);
    func_L01_005170B8(0x90001, 0x331465B7);
    func_L01_005170B8(0x90002, 0x332299DE);
    func_L01_005170B8(0x90003, 0x8066CCFF);
    func_L01_005170B8(0x90004, 0x706EC8FF);
    func_L01_005170B8(0x90005, 0x8066CCFF);
    func_L01_00517538(0x90003, f20, f20);
    func_L01_00517538(0x90004, f20, f20);
    func_L01_00517538(0x90005, f20, f20);
    func_L01_00516AA0(0x90003, 0x40, 1);
    func_L01_00516AA0(0x90004, 0x40, 1);
    func_L01_00516AA0(0x90005, 0x40, 1);
    func_L01_005170B8(0x90006, 0x3666CCFF);
    func_L01_00516C78(0x90006, 1, 3);
    func_L01_00517190(0x90003, 0xED1C);
    *(s16 *)(L39_005D6DC8_child(0x90003) + 0x4A) = 0;
    func_L01_00517190(0x90004, 0xED1D);
    *(s16 *)(L39_005D6DC8_child(0x90004) + 0x4A) = 0;
    func_L01_00517190(0x90005, 0xED1E);
    *(s16 *)(L39_005D6DC8_child(0x90005) + 0x4A) = 0;
    func_003E8630(0x90000, 0x90001);
    func_003E8630(0x90000, 0x90002);
    func_003E8630(0x90000, 0x90006);
    func_003E8630(0x90000, 0x90003);
    func_003E8630(0x90000, 0x90004);
    func_003E8630(0x90000, 0x90005);
    func_003E8348(7, 0x90000);
    func_003E6FF0(a0, 1);
    func_L39_005D6AE0();
    func_L01_004D2110(0);
}
/* localdecomp:end func_L39_005D6DC8 */
