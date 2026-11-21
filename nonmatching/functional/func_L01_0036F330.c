/* functional: high. Written from the PAL asm (no draft); sibling of the matched holo_glove_update (func_L01_003727B8). Control flow, all constants, $gp globals and call arguments verified block by block. Unknowns: func_L01_004501E8's 2 out/aux words (sp+0x50/+0x54, passed as an s32 buffer) and its 24-byte config blob (D_L01_001DD910 / D_L01_001DD928, copied to the local that is also the aim vector buffer, as retail does). */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) Vec_0036F330;
typedef struct { u8 b[24]; } Blob_0036F330;
typedef struct {
    u8 pad0[0x20];
    u8 phase;
    u8 pad21[0x42 - 0x21];
    u8 b42;
    u8 b43;
    u8 pad44[0x60 - 0x44];
    u8 flags60;
    u8 pad61[0x68 - 0x61];
    void *vars;
    u8 pad6C[0x7C - 0x6C];
    s16 bangles;
} Moby_0036F330;
typedef struct {
    u8 pad0[0x20];
    f32 timer;
    s32 w24;
    s32 w28;
    s32 w2C;
} Vars_0036F330;
typedef struct {
    u8 pad0[0x1D8];
    s32 f1D8;
    u8 pad1DC[0x1210 - 0x1DC];
    s32 fire_button;
    u8 pad1214[0x1220 - 0x1214];
    s32 f1220;
    u8 pad1224[0x1430 - 0x1224];
    u8 *f1430;
    u8 pad1434[0x25C0 - 0x1434];
    u8 *camera;
    s32 state;
    u8 pad25C8[0x25E9 - 0x25C8];
    u8 b25E9;
    u8 pad25EA[0x25ED - 0x25EA];
    u8 no_firing;
    u8 pad25EE[0x28BC - 0x25EE];
    s32 aiming_fire_wait;
} Hero_0036F330;
typedef struct { u8 pad0[0x1A0]; s32 w1A0; s32 w1A4; } Pad_0036F330;
typedef struct { u8 p0; u8 kind; u8 p2[0x4E]; f32 f50; u8 p54[0xF0 - 0x54]; } Row_0036F330;
extern Hero_0036F330 D_001A4BE0;
extern Pad_0036F330 *D_001D52FC;
extern Row_0036F330 D_L01_002C5600[];
extern u8 D_001425C0[];
extern u8 D_00142A60[];
extern u8 D_001DAFF0;
extern s32 D_001D673C;
extern s32 D_001D545C;
extern s32 D_001E1D28;
extern u8 D_002B39C0[];
extern u8 D_L01_001DD910[];
extern u8 D_L01_001DD928[];
extern f32 D_L01_001DD900;
__asm__(".extern D_L01_001DD900, 4");
extern f32 D_L01_001DD904;
__asm__(".extern D_L01_001DD904, 4");
extern f32 D_L01_001DD908;
__asm__(".extern D_L01_001DD908, 4");
extern f32 D_L01_001DD90C;
__asm__(".extern D_L01_001DD90C, 4");
static __inline__ void sub_0036F330(Vec_0036F330 *d, Vec_0036F330 *a, Vec_0036F330 *b) {
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(*d) : "m"(*a), "m"(*b) : "vf1", "vf2");
}
void func_L01_0036F330(Moby_0036F330 *moby) {
    extern void func_003C2F58(s32, s32, void *);
    extern void func_L01_00444F38(void *, s32, s32, s32, s32);
    extern f32 *func_00382348(void *);
    extern f32 func_0038CF00(void *, void *);
    extern s32 func_0038CAD0(s32 *);
    extern u8 *func_L01_004501E8(void *, void *, void *, s32, s32, s32, s32, void *, s32, s32, s32, f32, f32, f32, f32, f32);
    extern void func_L01_0036FA50(void *, void *, void *, void *, f32, f32, f32, f32);
    extern s32 func_L01_004C7A18(f32, void *, void *, void *, void *, void *, s32, s32);
    extern void func_L01_004EAA80(void);
    extern s32 func_L01_005118D0(s32, s32);
    extern void func_L01_004EA7D8(s32);
    extern s32 func_L01_003F2058(void *, s32);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_0038D890(void *, void *, void *, f32);
    extern f32 func_0038CEA8(void *);
    extern void func_L01_00362610(void *, void *, void *, s32, s32);
    extern void func_003A52A0(s32, s32, void *);
    extern s32 func_L01_005119E0(s32);
    extern void func_L01_003F2278(s32, s32);
    extern void func_L01_0040E050(void *);
    extern void func_L01_00404A10(void *, void *);
    extern void func_L01_0036F9F8(void *);
    Vec_0036F330 pos;
    Vec_0036F330 buf[2];
    s32 aux[2];
    Vars_0036F330 *vars = moby->vars;
    u8 *target;
    u8 kind;
    s32 can_fire;
    f32 *p;
    f32 t;

    func_003C2F58((s32)moby, 0, &pos);
    if (moby->b42 == moby->b43) {
        if (moby->flags60 & 2)
            func_L01_00444F38(moby, 1, 0, 2, 0);
    }
    if (D_L01_002C5600[D_001425C0[0x77]].kind >= 2)
        D_00142A60[0x77] |= 0x20;
    target = 0;
    if (D_001A4BE0.f1430 && D_001A4BE0.f1430[0x20] != 0xFE && D_001A4BE0.f1430[0x20] != 0xFD) {
        p = func_00382348(D_001A4BE0.f1430);
        if (p && *p > 0.0f) {
            if (func_0038CF00(D_001A4BE0.f1430 + 0x10, (u8 *)moby + 0x10) < D_L01_001DD900)
                target = D_001A4BE0.f1430;
        }
    }
    kind = D_L01_002C5600[D_001425C0[0x77]].kind;
    if (kind == 2)
        moby->bangles = 3;
    else if (kind == 1)
        moby->bangles = kind;
    else if (kind >= 3)
        moby->bangles = 7;
    can_fire = 1;
    if (D_001A4BE0.state == 0x1D || D_001A4BE0.state == 1) {
        can_fire = func_0038CAD0(&D_001A4BE0.aiming_fire_wait) != 0;
    } else {
        D_001A4BE0.aiming_fire_wait = 0x21;
        if (!target) {
            *(Blob_0036F330 *)buf = *(Blob_0036F330 *)D_L01_001DD910;
            target = func_L01_004501E8(&pos, (u8 *)&D_001A4BE0 + 0x6F0, &aux[0], 0, 0, 0, 0, buf, 1, -1, 0,
                                       0.39269909262657166f, 1.5707963705062866f, 11.100000381469727f, 0.0f, 0.0f);
        }
    }
    if (D_001DAFF0 && D_001D545C == 5) {
        *(Blob_0036F330 *)buf = *(Blob_0036F330 *)D_L01_001DD928;
        target = func_L01_004501E8(&pos, (u8 *)&D_001A4BE0 + 0x6F0, &aux[1], 0, 0, 0, 0, buf, 1, -1, 0,
                                   0.8726646304130554f, 1.0471975803375244f, 30.0f, 0.0f, 0.0f);
        D_L01_001DD900 = 30.0f;
        D_L01_001DD90C = 20.0f;
    } else {
        t = 12.0f;
        if (D_001D673C)
            t = 6.0f;
        D_L01_001DD900 = t;
        D_L01_001DD90C = 12.5f;
    }
    func_L01_0036FA50(buf, &pos, target, 0, D_L01_001DD904, D_L01_001DD900,
                      D_L01_001DD90C * 0.020000001415610313f, D_L01_001DD908 * 0.0004000000189989805f);
    vars->w24 = func_L01_004C7A18(0.0052000004798173904f, &pos, buf, vars, (u8 *)vars + 0x10, moby, 0, 0);
    switch (moby->phase) {
    case 0:
        moby->phase = 1;
        vars->w2C = -1;
        vars->timer = 0.0f;
        vars->w28 = 0;
        /* fallthrough */
    case 1:
        if (D_001A4BE0.f1D8 >= 0x12)
            func_L01_004EAA80();
        if (can_fire && vars->timer == 0.0f && !D_001A4BE0.no_firing
            && (D_001D52FC->w1A0 & D_001A4BE0.fire_button) && D_001A4BE0.f1220 >= 0x13) {
            if (func_L01_005118D0(-1, 1)) {
                D_001E1D28 = 1;
                func_L01_004EA7D8(-1);
                vars->w2C = func_L01_003F2058(D_002B39C0, 0);
                func_L01_00444F38(moby, 2, 0, 2, 0);
                if (target && *(s16 *)(target + 0xAA) == 0x1A13 && D_001DAFF0) {
                    sub_0036F330(buf, (Vec_0036F330 *)(target + 0x10), &pos);
                    func_0038CF68(buf, buf, 0.7000000476837158f);
                    func_0038D890(buf, buf, D_001A4BE0.camera + 0xD0, -0.15707963705062866f);
                } else if (!D_001DAFF0 && (!target || *(s16 *)(target + 0xAA) == 0x1A13)) {
                    if (func_0038CEA8(buf) > 0.6000000238418579f)
                        func_0038CF68(buf, buf, 0.4400000274181366f);
                }
                func_L01_00362610(&pos, buf, moby, 0, 0);
                func_003A52A0(0, 0, moby);
                vars->timer = 1.0f / D_L01_002C5600[D_001425C0[0x77]].f50;
            } else {
                if ((D_001D52FC->w1A4 & D_001A4BE0.fire_button) || D_001E1D28 == 1) {
                    func_003A52A0(1, 0, moby);
                    D_001E1D28 = 0;
                }
            }
            if ((D_001D52FC->w1A0 & D_001A4BE0.fire_button) && func_L01_005119E0(-1) && D_001A4BE0.b25E9)
                break;
            if (vars->w2C >= 0) {
                func_L01_003F2278(vars->w2C, 0);
                vars->w2C = -1;
            }
        }
        break;
    default:
        break;
    }
    func_L01_0040E050((u8 *)vars + 0x20);
    func_L01_00404A10(func_L01_0036F9F8, moby);
}
