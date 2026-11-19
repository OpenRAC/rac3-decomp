/* functional: high. Same calls, arguments and order as retail; only the placement of one lui/addiu string address load differs. Modeled on matched twin func_L01_00478BD0. */
typedef struct { u8 pad0[8]; void **f8; u8 padC[0x14]; f32 f20; f32 f24; } O_003B4840;
typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_003B4840;
extern f32 D_L01_001DE64C;
extern f32 D_L01_001DE650;
extern f32 D_L01_001DE654;
extern f32 D_L01_001DE658;
extern f32 D_L01_001DE65C;
extern f32 D_L01_001DE660;
extern f32 D_L01_001DE664;
extern f32 D_L01_001DE668;
extern f32 D_L01_001DE66C;
extern f32 D_L01_001DE670;
extern f32 D_L01_001DE674;
extern f32 D_L01_001DE678;
extern f32 D_L01_001DE67C;
extern f32 D_L01_001DE680;
extern f32 D_L01_001DE684;
extern f32 D_L01_001DE688;
extern f32 D_L01_001DE68C;
extern f32 D_L01_001DE690;
extern f32 D_L01_001DE694;
extern char D_L01_001DE720[];
extern s32 D_L01_001DC1E0;
extern S_003B4840 D_L01_001E15E0;
extern void func_L01_00516468(s32);
extern void func_003B5060(s32);
extern void func_003E5090(s32);
extern void func_003E5360(s32);
extern void func_003E51F8(s32);
extern s32 func_00392A18(void);
extern void func_L01_00517448(s32, s32, s32);
extern void func_L01_00516470(s32, f32, f32);
extern void func_L01_005169C8(s32, f32);
extern s32 func_L01_005170B8(s32, s32);
extern void func_L01_00517538(s32, f32, f32);
extern void func_L01_00517190(s32, s32);
extern void func_L01_00516FD8(s32, char *);
extern void func_L01_00516B90(s32, s32, s32);
extern void *func_003E6C08();
extern s32 func_003E6DE8();
extern void *func_003E6378(s32, s32);
extern void func_003EDAD0(void *, s32, s32);
extern void func_003E8630(s32, s32);
extern void func_003E8348(s32, s32);
extern s32 func_L01_003B4818(void *, u8 *);

void func_L01_003B4840(u8 *a0, u8 *a1) {
    O_003B4840 *p;
    void *q;
    s32 t;

    if (*(s32 *)(a1 + 36) == 0) {
        return;
    }
    func_L01_00516468(1);
    func_003B5060(0x140000);
    func_003E5090(0x140001);
    func_003E5090(0x140002);
    func_003E51F8(0x140003);
    func_003E5360(0x140004);
    if (func_L01_003B4818(a0, a1)) {
        func_003E51F8(0x140005);
        func_003E51F8(0x140006);
        func_003E5360(0x140007);
    }
    t = func_00392A18();
    func_L01_00517448(0x140001, t, 0x6A);
    t = func_00392A18();
    func_L01_00517448(0x140002, t, 0x6B);
    func_L01_00516470(0x140001, D_L01_001DE64C, D_L01_001DE650);
    func_L01_00516470(0x140002, D_L01_001DE64C, D_L01_001DE650);
    if (func_L01_003B4818(a0, a1)) {
        func_L01_005169C8(0x140001, D_L01_001DE680);
        func_L01_005169C8(0x140002, D_L01_001DE680);
    } else {
        func_L01_005169C8(0x140001, D_L01_001DE65C);
        func_L01_005169C8(0x140002, D_L01_001DE65C);
    }
    func_L01_005170B8(0x140001, 0x332299DE);
    func_L01_005170B8(0x140002, 0x331465B7);
    func_L01_00517538(0x140001, D_L01_001DE654, D_L01_001DE658);
    func_L01_00517538(0x140002, D_L01_001DE654, D_L01_001DE658);
    func_L01_00516470(0x140003, D_L01_001DE660, D_L01_001DE664);
    func_L01_005170B8(0x140003, 0x706EC8FF);
    func_L01_00517538(0x140003, D_L01_001DE668, D_L01_001DE66C);
    func_L01_00517190(0x140003, 0xEC5A);
    func_L01_00516470(0x140004, D_L01_001DE670, D_L01_001DE674);
    func_L01_005170B8(0x140004, 0x8066CCFF);
    func_L01_00517538(0x140004, D_L01_001DE678, D_L01_001DE67C);
    func_L01_00516FD8(0x140004, D_L01_001DE720);
    func_L01_00516B90(0x140004, 2, 3);
    if (D_L01_001E15E0.f4 != 0) { q = &D_L01_001E15E0; } else { q = func_003E6C08(); }
    p = (O_003B4840 *)func_003E6378(func_003E6DE8(q), 0x140004);
    if ((p == 0) || (((s32 (*)(void *, s32))p->f8[4])(p, D_L01_001DC1E0) == 0)) { p = 0; }
    func_003EDAD0(p, 0x40, 1);
    p->f20 = 0.00499999989f;
    p->f24 = 0.00499999989f;
    func_003E8630(0x140000, 0x140002);
    func_003E8630(0x140000, 0x140001);
    func_003E8630(0x140000, 0x140003);
    func_003E8630(0x140000, 0x140004);
    if (func_L01_003B4818(a0, a1)) {
        func_L01_00516470(0x140005, D_L01_001DE684, D_L01_001DE674);
        func_L01_00517538(0x140005, D_L01_001DE688, D_L01_001DE68C);
        func_L01_005170B8(0x140005, 0x332299DE);
        func_L01_00516B90(0x140005, 3, 3);
        func_L01_00516470(0x140006, D_L01_001DE694, D_L01_001DE664);
        func_L01_005170B8(0x140006, 0x706EC8FF);
        func_L01_00517538(0x140006, D_L01_001DE668, D_L01_001DE66C);
        func_L01_00517190(0x140006, 0xED55);
        func_L01_00516470(0x140007, D_L01_001DE690, D_L01_001DE674);
        func_L01_005170B8(0x140007, 0x8066CCFF);
        func_L01_00517538(0x140007, D_L01_001DE678, D_L01_001DE67C);
        func_L01_00516FD8(0x140007, D_L01_001DE720);
        func_L01_00516B90(0x140007, 3, 3);
        if (D_L01_001E15E0.f4 != 0) { q = &D_L01_001E15E0; } else { q = func_003E6C08(); }
        p = (O_003B4840 *)func_003E6378(func_003E6DE8(q), 0x140007);
        if ((p == 0) || (((s32 (*)(void *, s32))p->f8[4])(p, D_L01_001DC1E0) == 0)) { p = 0; }
        func_003EDAD0(p, 0x40, 1);
        p->f20 = 0.00499999989f;
        p->f24 = 0.00499999989f;
        func_003E8630(0x140000, 0x140005);
        func_003E8630(0x140000, 0x140006);
        func_003E8630(0x140000, 0x140007);
    }
    func_003E8348(0, 0x140000);
    func_L01_00516468(0);
}
