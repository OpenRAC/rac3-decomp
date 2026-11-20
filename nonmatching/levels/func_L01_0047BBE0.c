/* Matches PAL byte for byte with check.py at its 34 places (round 18, sonnet xhigh), but the full level build rejects it:
 * func_L01_0047BBE0, its word at +0x498: the instruction differs (levels 01-36 alike). check.py masks that word (a relocated field);
 * tools/level_symbols.py compares it with the real symbol of each level, so a callee/global name or its address is wrong. Look at the
 * retail word at +0x498 (asm/levels/*/nonmatchings/func_L01_0047BBE0.s) and at which symbol the C uses there.
 */
/* localdecomp:start func_L01_0047BBE0 */
typedef struct {
    s32 pad0[4];
    s32 (*f10)(void *, s32);
} VT_0047BBE0;
typedef struct {
    u8 pad0[8];
    VT_0047BBE0 *vt;
    u8 pad0C[0x3E];
    s16 f4A;
} Obj_0047BBE0;
typedef struct {
    u8 pad0[4];
    s32 f4;
} Tab_0047BBE0;

extern u8 D_L01_001D80CD;
extern s32 D_L01_001E0500_0047BBE0[2];
extern Tab_0047BBE0 D_L01_001E15E0_0047BBE0[];
extern f32 D_L01_001D8170;
extern f32 D_L01_001D8174;
extern s32 D_L01_001DC1B0_0047BBE0;
__asm__(".extern D_L01_001D80CD, 1");
__asm__(".extern D_L01_001D8170, 4");
__asm__(".extern D_L01_001D8174, 4");
__asm__(".extern D_L01_001DC1B0_0047BBE0, 4");

extern void func_L01_00516468_0047BBE0(s32);
extern void func_0038CB78(void *, s32, s32);
extern void func_003B5060(s32);
extern void func_003E5090(s32);
extern void func_003E51F8(s32);
extern void func_003E5360(s32);
extern void func_003E8FE8(s32, s32, s32, f32, f32, f32, f32);
extern void func_003E7AC8(s32, s32);
extern s32 func_00392A18(void);
extern void func_L01_00517448(s32, s32, s32);
extern void func_L01_00516470(s32, f32, f32);
extern void func_L01_00517538(s32, f32, f32);
extern s32 func_L01_005170B8(s32, s32);
extern s32 func_L01_00516FD8(s32, s32);
extern void func_L01_00516B90(s32, s32, s32);
extern void func_L01_00516AA0(s32, s32, s32);
extern Tab_0047BBE0 *func_003E6C08(void);
extern Tab_0047BBE0 *func_003E6DE8(Tab_0047BBE0 *);
extern Obj_0047BBE0 *func_003E6378(Tab_0047BBE0 *, s32);
extern void func_003E9138(s32, s32, s32, f32, f32, f32, f32);
extern void func_003E8630(s32, s32);
extern void func_003E8348(s32, s32);
extern void func_003E6FF0(s32, s32);

void func_L01_0047BBE0(s32 a0) {
    Tab_0047BBE0 *t;
    Obj_0047BBE0 *o;
    Obj_0047BBE0 *p;

    D_L01_001D80CD = 1;
    func_L01_00516468_0047BBE0(1);
    func_0038CB78(D_L01_001E0500_0047BBE0, 0, 0x18);
    func_003B5060(0x20000);
    func_003E5090(0x20001);
    func_003E5090(0x20002);
    func_003E5090(0x20008);
    func_003E5090(0x20009);
    func_003E51F8(0x20004);
    func_003E51F8(0x20005);
    func_003E51F8(0x20006);
    func_003E5360(0x20003);
    func_003E5090(0x20007);
    func_003E8FE8(0x2000B, 0, 0x8066CCFF, 0.28f, 0.123f, 0.75f, 0.75f);
    func_003E7AC8(0x2000B, 1);
    func_L01_00517448(0x20002, func_00392A18(), 0x1F);
    func_L01_00517448(0x20001, func_00392A18(), 0x20);
    func_L01_00517448(0x20007, func_00392A18(), 0x6F);
    func_L01_00517448(0x20008, func_00392A18(), 0x4E);
    func_L01_00517448(0x20009, func_00392A18(), 0x4F);
    func_L01_00516470(0x20004, 0.0745f, 0.086666f);
    func_L01_00516470(0x20005, 0.074f, 0.189f);
    func_L01_00516470(0x20006, 0.074f, 0.258f);
    func_L01_00516470(0x20009, 0.412f, 0.422f);
    func_L01_00516470(0x20008, 0.412f, 0.422f);
    func_L01_00516470(0x20003, D_L01_001D8170, D_L01_001D8174);
    func_L01_00516470(0x20007, 0.494f, 0.495f);
    func_L01_00517538(0x20009, 0.8f, 0.78f);
    func_L01_00517538(0x20008, 0.8f, 0.78f);
    func_L01_00517538(0x20001, 1.0f, 1.0f);
    func_L01_00517538(0x20002, 1.0f, 1.0f);
    func_L01_00517538(0x20004, 0.057749998f, 0.07107692f);
    func_L01_00517538(0x20005, 0.040599998f, 0.04996923f);
    func_L01_00517538(0x20006, 0.040599998f, 0.04996923f);
    func_L01_00517538(0x20003, 1.0f, 1.0f);
    func_L01_005170B8(0x20001, 0x331465B7);
    func_L01_005170B8(0x20002, 0x332299DE);
    func_L01_005170B8(0x20004, 0x706EC8FF);
    func_L01_005170B8(0x20003, 0x7075D5FF);
    func_L01_005170B8(0x20007, 0x706EC8FF);
    func_L01_005170B8(0x20009, 0x331465B7);
    func_L01_005170B8(0x20008, 0x332299DE);
    func_L01_005170B8(0x20005, 0x506EC8FF);
    func_L01_005170B8(0x20006, 0x306EC8FF);
    func_L01_005169C8(0x20007, 0.0f);
    func_L01_00516FD8(0x20003, (s32)D_L01_001E0500_0047BBE0);
    func_L01_00516B90(0x20003, 3, 1);
    func_L01_00516AA0(0x20003, 0x40, 1);
    func_L01_0047B798(0, 0);
    func_L01_0047B798(0, 1);
    func_L01_0047B798(0, 2);
    t = D_L01_001E15E0_0047BBE0;
    if (t->f4 == 0) {
        t = func_003E6C08();
    }
    t = func_003E6DE8(t);
    o = func_003E6378(t, 0x20004);
    if (o != 0 && o->vt->f10(o, D_L01_001DC1B0_0047BBE0) != 0) {
        p = o;
    } else {
        p = 0;
    }
    p->f4A = 0;
    func_003E9138(0x2000A, 0x332299DE, 0, 0.074f, 0.224f, 0.05f, 0.005f);
    func_003E8630(0x20000, 0x20001);
    func_003E8630(0x20000, 0x20002);
    func_003E8630(0x20000, 0x20009);
    func_003E8630(0x20000, 0x20008);
    func_003E8630(0x20000, 0x2000A);
    func_003E8630(0x20000, 0x20004);
    func_003E8630(0x20000, 0x20005);
    func_003E8630(0x20000, 0x20006);
    func_003E8630(0x20000, 0x20003);
    func_003E8630(0x20000, 0x20007);
    func_003E8630(0x20000, 0x2000B);
    func_003E8348(6, 0x20000);
    func_003E6FF0(a0, 1);
    func_L01_00516468_0047BBE0(0);
}
/* localdecomp:end func_L01_0047BBE0 */
