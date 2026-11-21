/* functional: high. Builds the multiplayer-menu lobby/score screen (a0 = menu object): runs the two-step func_003B43B0/func_L39_00602240/func_L39_005DBEE8 setup twice, marks D_001D81DC_sda, registers widgets 0x50000..0x50024 (func_003B5060 / func_003E51F8 / func_003E5360), places and colours the header 0x50006, sets its flag word through the manager's looked-up child (dynamic-cast pattern: the +0x50 store goes through that pointer, or null as in retail), two text widgets 0x50023/0x50024 (strings 0x12A5/0x12A6), widgets 0x50007/0x50008 (colour tables D_L39_0049A008/10), the two player slot widgets 0x50009/0x5000A (position from func_L39_005DC4C0 of D_L39_00352940's +0x40/+0x44 entries, colour D_L39_00499FF8/FF0 with alpha 0x60), the 8 row widgets 0x5000B..0x50012 (shown only when func_L39_005DC4C0 of the +0x60.. entries succeeds), 0x5001B..0x50022 and 0x50013..0x5001A; links groups 0x50001..0x50005 into 0x50000, calls func_003E8348(0x17, 0x50000), func_003E6FF0(a0, 1), func_L39_005DBF90(-1) and func_L01_004D2110(0). Constants are retail's bit patterns as decimals; same call order. */
/* localdecomp:start func_L39_005DC648 */
typedef struct {
    u8 pad[0x20C];
    u8 *p20C;
} L39Main_5DC648;
typedef struct { u8 p0[4]; s32 f4; } L39Mgr_5DC648;

extern L39Main_5DC648 D_L39_00352940;
extern L39Mgr_5DC648 D_L39_0024CD50 __attribute__((section(".data")));
extern u8 D_L39_0049A018[];
extern u8 D_L39_0049A008[];
extern u8 D_L39_0049A010[];
extern u8 D_L39_00499FF8[];
extern u8 D_L39_00499FF0[];
extern u8 D_001D81DC_sda;
extern s32 D_001DA5F0_sda;

extern s32 func_003B43B0(s32);
extern s32 func_L39_00602240(s32);
extern void func_L39_005DBEE8(s32, s32, s32);
extern void func_L01_004D2110(s32);
extern void func_L01_00484A80(s32);
extern s32 func_003B5060(s32);
extern s32 func_003E51F8(s32);
extern void func_003E5360(s32);
extern void func_L01_00516470(s32, f32, f32);
extern void func_L01_00517538(s32, f32, f32);
extern s32 func_L01_005170B8(s32, s32);
extern void *func_003E6C08(void);
extern s32 func_003E6DE8(void *);
extern void *func_003E6378(s32, s32);
extern s32 func_L01_00517190(s32, s32);
extern s32 func_00381FF0(s32);
extern s32 func_L01_00516FD8(s32, s32);
extern void func_L01_00516728(s32, f32, f32);
extern void func_L01_00516C78(s32, s32, s32);
extern void func_L01_005168F0(s32, f32);
extern f32 func_L39_005DD390(s32);
extern void func_003E8630(s32, s32);
extern s32 func_003E8348(s32, s32);
extern void func_003E6FF0(s32, s32);
extern void func_L39_005DBF90(s32);

static s32 L39_5DC648_col(u8 *d, s32 hi) {
    return d[0] | (d[1] << 8) | (d[2] << 16) | hi;
}

void func_L39_005DC648(s32 a0) {
    s32 xy[4];
    s32 id;
    s32 off;
    u8 *c;
    u8 *s;
    void *mgr;
    f32 f20, f21, f22, f23;

    func_L39_005DBEE8(func_003B43B0(0), func_L39_00602240(0), 0);
    D_001D81DC_sda = 1;
    func_L01_004D2110(1);
    func_L39_005DBEE8(func_003B43B0(0), func_L39_00602240(0), 0);
    func_L01_00484A80(0x50000);
    func_003B5060(0x50001);
    func_003B5060(0x50002);
    func_003B5060(0x50003);
    func_003B5060(0x50004);
    func_003B5060(0x50005);
    func_003E51F8(0x50006);
    func_003E51F8(0x50007);
    func_003E51F8(0x50009);
    func_003E51F8(0x5000A);
    func_003E51F8(0x5000B);
    func_003E51F8(0x5000C);
    func_003E51F8(0x5000D);
    func_003E51F8(0x5000E);
    func_003E51F8(0x5000F);
    func_003E51F8(0x50010);
    func_003E51F8(0x50011);
    func_003E51F8(0x50012);
    func_003E51F8(0x50008);
    func_003E51F8(0x50013);
    func_003E51F8(0x50014);
    func_003E51F8(0x50015);
    func_003E51F8(0x50016);
    func_003E51F8(0x50017);
    func_003E51F8(0x50018);
    func_003E51F8(0x50019);
    func_003E51F8(0x5001A);
    func_003E51F8(0x5001B);
    func_003E51F8(0x5001C);
    func_003E51F8(0x5001D);
    func_003E51F8(0x5001E);
    func_003E51F8(0x5001F);
    func_003E51F8(0x50020);
    func_003E51F8(0x50021);
    func_003E51F8(0x50022);
    func_003E5360(0x50023);
    func_003E5360(0x50024);
    func_L01_00516470(0x50006, 0.5f, 0.52f);
    func_L01_005170B8(0x50006, L39_5DC648_col(D_L39_0049A018, D_L39_0049A018[3] << 24));
    func_L01_00517538(0x50006, 0.8f, 0.7f);
    if (D_L39_0024CD50.f4 != 0) {
        mgr = &D_L39_0024CD50;
    } else {
        mgr = func_003E6C08();
    }
    c = func_003E6378(func_003E6DE8(mgr), 0x50006);
    if (c != 0) {
        if ((*(s32 (**)(void *, s32))(*(s32 *)(c + 8) + 0x10))(c, D_001DA5F0_sda) == 0) {
            c = 0;
        }
    }
    f21 = 0.5f;
    *(s32 *)(c + 0x50) = func_003B43B0(0);
    f20 = 0.0f;
    func_L01_00517190(0x50006, 1);
    f23 = 0.05f;
    f22 = 0.062000003f;
    func_L01_00516FD8(0x50023, func_00381FF0(0x12A5));
    func_L01_00516FD8(0x50024, func_00381FF0(0x12A6));
    func_L01_005170B8(0x50023, 0x8066CCFF);
    func_L01_005170B8(0x50024, 0x8066CCFF);
    func_L01_00516470(0x50023, f21, 0.9f);
    func_L01_00516470(0x50024, f21, 0.14f);
    func_L01_00516AA0(0x50023, 1, 0);
    func_L01_00516AA0(0x50024, 1, 0);
    func_L01_00516AA0(0x50023, 0x40, 1);
    func_L01_00516AA0(0x50024, 0x40, 1);
    func_L01_00516470(0x50007, f20, f20);
    func_L01_005170B8(0x50007, L39_5DC648_col(D_L39_0049A008, D_L39_0049A008[3] << 24));
    func_L01_00517538(0x50007, 0.075f, 0.093f);
    func_L01_00517190(0x50007, 0xED1C);
    func_L01_00516AA0(0x50007, 1, 1);
    func_L01_00516470(0x50008, f20, f20);
    func_L01_005170B8(0x50008, L39_5DC648_col(D_L39_0049A010, D_L39_0049A010[3] << 24));
    func_L01_00517538(0x50008, f23, f22);
    func_L01_00517190(0x50008, 0xED1C);
    func_L01_00516AA0(0x50008, 1, 1);

    s = D_L39_00352940.p20C;
    func_L39_005DC4C0(*(s32 *)(s + 0x40), &xy[0], &xy[1]);
    func_L01_00516470(0x50009, *(f32 *)&xy[0], *(f32 *)&xy[1]);
    func_L01_00517538(0x50009, f23, f22);
    func_L01_00516AA0(0x50009, 1, 1);
    func_L01_00516AA0(0x50009, 0x40, 1);
    func_L01_00516728(0x50009, 0.002f, 0.002f);
    func_L01_00516C78(0x50009, 3, 3);
    func_L01_00517190(0x50009, 0xED33);
    func_L01_005168F0(0x50009, func_L39_005DD390(*(s32 *)(D_L39_00352940.p20C + 0x40)));
    if (*(s32 *)(D_L39_00352940.p20C + 0x88) != 0) {
        func_L01_005170B8(0x50009, L39_5DC648_col(D_L39_00499FF8, 0x60000000));
    } else {
        func_L01_005170B8(0x50009, L39_5DC648_col(D_L39_00499FF0, 0x60000000));
    }

    func_L39_005DC4C0(*(s32 *)(D_L39_00352940.p20C + 0x44), &xy[2], &xy[3]);
    func_L01_00516470(0x5000A, *(f32 *)&xy[2], *(f32 *)&xy[3]);
    func_L01_00517538(0x5000A, 0.05f, 0.062000003f);
    func_L01_00516AA0(0x5000A, 1, 1);
    func_L01_00516AA0(0x5000A, 0x40, 1);
    func_L01_00516728(0x5000A, 0.002f, 0.002f);
    func_L01_00516C78(0x5000A, 3, 3);
    func_L01_00517190(0x5000A, 0xED33);
    func_L01_005168F0(0x5000A, func_L39_005DD390(*(s32 *)(D_L39_00352940.p20C + 0x44)));
    func_L01_005170B8(0x5000A, L39_5DC648_col(D_L39_00499FF8, 0x60000000));
    if (*(s32 *)(D_L39_00352940.p20C + 0x8C) != 0) {
        func_L01_005170B8(0x5000A, L39_5DC648_col(D_L39_00499FF8, 0x60000000));
    } else {
        func_L01_005170B8(0x5000A, L39_5DC648_col(D_L39_00499FF0, 0x60000000));
    }

    f20 = 0.002f;
    off = 0;
    id = 0x5000B;
    do {
        s32 ok = func_L39_005DC4C0(*(s32 *)(D_L39_00352940.p20C + off + 0x60), &xy[0], &xy[1]);
        if (ok != 0) {
            func_L01_00516470(id, *(f32 *)&xy[0], *(f32 *)&xy[1]);
            func_L01_00516AA0(id, 1, 1);
        } else {
            func_L01_00516AA0(id, 1, 0);
        }
        func_L01_00517538(id, 0.05f, 0.062000003f);
        off += 4;
        func_L01_00516C78(id, 3, 3);
        func_L01_00516AA0(id, 0x40, 1);
        func_L01_00516728(id, f20, f20);
        func_L01_00517190(id, 0xED34);
        id++;
    } while (id <= 0x50012);

    id = 0x5001B;
    do {
        func_L01_00517538(id, 0.05f, 0.062000003f);
        func_L01_00516AA0(id, 1, 0);
        func_L01_00516AA0(id, 0x40, 1);
        func_L01_00516728(id, f20, f20);
        func_L01_00516C78(id, 3, 3);
        func_L01_00517190(id, 0xED36);
        id++;
    } while (id <= 0x50022);

    id = 0x50013;
    do {
        func_L01_00517538(id, 0.035f, 0.0434f);
        func_L01_00516AA0(id, 1, 0);
        func_L01_00516AA0(id, 0x40, 1);
        func_L01_00516728(id, f20, f20);
        func_L01_00516C78(id, 3, 3);
        func_L01_00517190(id, 0xED35);
        id++;
    } while (id <= 0x5001A);

    func_003E8630(0x50001, 0x50006);
    func_003E8630(0x50001, 0x50007);
    func_003E8630(0x50001, 0x50008);
    func_003E8630(0x50001, 0x50009);
    func_003E8630(0x50001, 0x5000A);
    id = 0x5000B;
    do {
        func_003E8630(0x50002, id);
        id++;
    } while (id <= 0x50012);
    id = 0x5001B;
    do {
        func_003E8630(0x50003, id);
        id++;
    } while (id <= 0x50022);
    id = 0x50013;
    do {
        func_003E8630(0x50004, id);
        id++;
    } while (id <= 0x5001A);
    func_003E8630(0x50005, 0x50023);
    func_003E8630(0x50005, 0x50024);
    func_003E8630(0x50000, 0x50001);
    func_003E8630(0x50000, 0x50002);
    func_003E8630(0x50000, 0x50003);
    func_003E8630(0x50000, 0x50004);
    func_003E8630(0x50000, 0x50005);
    func_003E8348(0x17, 0x50000);
    func_003E6FF0(a0, 1);
    func_L39_005DBF90(-1);
    func_L01_004D2110(0);
}
/* localdecomp:end func_L39_005DC648 */
