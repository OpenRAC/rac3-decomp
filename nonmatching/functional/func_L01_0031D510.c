/* functional: medium. Written from PAL assembly, no earlier draft; compiles in file context, all 35 retail jal targets and all $gp-relative loads match retail (checked by symbol), frame differs and scheduling differs. Tail "explode then remove" is duplicated instead of shared. Damage record layout (dir[4], owner, kind, type/flag/klass, power, enabled) as func_L01_0031DFD8. */
/* functional: medium. Written from the PAL assembly (no earlier draft). Thrown-ball style moby update: state 0 flies and collides, state 1 spins in place, state 2 removes it. The random-looking spark loop and the bounce branch are transcribed block by block; the collision request struct follows Move_0038F728's layout. */
typedef int Q_0031D510 __attribute__((mode(TI)));
typedef struct {
    Q_0031D510 start, end, velocity;
    u8 *hit;
    s32 *options;
    s32 mode;
    f32 radius, factor0, factor1;
    s32 flags, unknown;
    s32 out90, out94;
    s32 field98;
    s32 pad9C;
} Move_0031D510;
typedef struct {
    f32 dir[4];
    u8 *owner;
    u32 kind;
    u8 type, flag;
    u16 klass;
    f32 power;
    s32 enabled;
} Dmg_0031D510;
extern u8 D_001DC898[8];
extern u8 D_001425C0[];
extern u8 D_L01_002C5600[];
extern Q_0031D510 D_L01_001EAA30[];
extern u8 *D_001A71A0[];
extern u8 D_L01_001D66B0[] __attribute__((section(".sdata")));
extern s32 D_L01_001D673C __attribute__((section(".data")));
extern s32 D_L01_001D6740 __attribute__((section(".data")));
extern f32 D_L01_001DC870, D_L01_001DC878, D_L01_001DC880, D_L01_001DC884, D_L01_001DC88C, D_L01_001DC890;
extern s32 D_L01_001DC894;
__asm__(".extern D_L01_001DC870, 4");
__asm__(".extern D_L01_001DC878, 4");
__asm__(".extern D_L01_001DC880, 4");
__asm__(".extern D_L01_001DC884, 4");
__asm__(".extern D_L01_001DC88C, 4");
__asm__(".extern D_L01_001DC890, 4");
__asm__(".extern D_L01_001DC894, 4");
void func_L01_0031D510(u8 *obj) {
    extern void func_003C5180(void *, void *, s32);
    extern s32 func_L01_004CB2D8(void);
    extern void func_L01_004CAB30(void *, void *);
    extern void func_L01_004C8688(s32, void *, s32);
    extern void func_L01_004C7D40(void *, void *, f32);
    extern s32 func_0038CAD0(s32);
    extern void func_003C4098(void *, void *, void *, f32);
    extern s32 func_00382468(s32);
    extern u8 *func_L01_004669B0(f32, f32, f32, f32, u8 *, s32, f32 *, u32, s32);
    extern s32 func_L01_004C7E70(Move_0031D510 *, s32);
    extern s32 func_L01_004CB018(s32);
    extern void func_0038D850(void *, void *, void *);
    extern void func_0038CF68(f32 *, s32, f32);
    extern s32 func_003D4D00(void *, s32, u8 *, void *, f32);
    extern void func_0038CE90(void *, void *, void *);
    extern f32 func_003824E0(f32, f32);
    extern void func_003C4840(void *, void *, f32);
    extern void func_003A52A0(s32, s32, void *);
    extern void func_L01_00451290(void *, void *, s32);
    extern f32 func_0038CE68(void *, void *);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_L01_0031DB70(u8 *);
    extern void func_003C2880(Moby_0031BEF0 *);
    extern void func_L01_004471A8(u8 *, f32);
    Q_0031D510 normal;
    Q_0031D510 old;
    Q_0031D510 cur;
    Q_0031D510 spin;
    Q_0031D510 tmp1, tmp2;
    u8 optbuf[8];
    Move_0031D510 move;
    Dmg_0031D510 dmg;
    u8 *vars = *(u8 **)(obj + 0x68);
    f32 *pos = (f32 *)(obj + 0x10);
    f32 *vel = (f32 *)vars;
    s32 res, i, r;
    f32 f20, f3;
    func_003C5180(pos, &normal, 1);
    if (func_L01_004CB2D8()) func_L01_004CAB30(pos, pos);
    switch (obj[0x20]) {
    case 0:
        old = *(Q_0031D510 *)pos;
        pos[0] += vel[0];
        pos[1] += vel[1];
        pos[2] += vel[2];
        func_L01_004C8688(*(s32 *)(vars + 0x30), vars, 0);
        func_L01_004C7D40(pos, vars, 0.0058400002f);
        func_0038CAD0((s32)(vars + 0x28));
        if (*(s32 *)(vars + 0x28) != 0) {
            for (i = 0; i < 3; i++) {
                u8 *p;
                s32 life, sign;
                f32 size;
                cur = *(Q_0031D510 *)pos;
                func_003C4098(&tmp1, &old, &cur, (f32)i * 0.3333f);
                life = func_00382468(6);
                sign = func_00382468(2);
                size = (f32)*(s32 *)(vars + 0x28) / 42.0f * 65000.0f + 10000.0f;
                p = func_L01_004669B0(0.025f, 1.0f, 1.0f, size, (u8 *)&tmp1, sign ? -life : life, (f32 *)D_L01_001D66B0, 0x80808080, 1);
                if (p) {
                    *(s16 *)(p + 0xA) = 42;
                    *(s32 *)(p + 0x24) = 2;
                    p[0x2A] = 0x7F;
                    p[0x2B] = p[0xA];
                }
            }
        }
        *(u64 *)optbuf = *(u64 *)D_001DC898;
        f3 = 1.5f;
        if ((f32)*(s32 *)(vars + 0x24) == 3.0f) f3 = 0.0f;
        f20 = *(s32 *)(vars + 0x2C) ? D_L01_001DC88C : D_L01_001DC880;
        move.start = old;
        move.end = *(Q_0031D510 *)pos;
        move.velocity = *(Q_0031D510 *)vars;
        move.hit = obj;
        move.options = (s32 *)optbuf;
        move.mode = 2;
        move.radius = f20;
        move.factor0 = (D_L01_001DC870 - 1.0f) * 1.2f + 1.0f;
        move.factor1 = f3;
        move.flags = 0;
        move.unknown = 0;
        move.field98 = 0;
        res = func_L01_004C7E70(&move, -1);
        r = func_L01_004CB018(move.out94);
        if (res > 0 && (u32)(r - 1) < 2) goto explode;
        *(Q_0031D510 *)pos = move.end;
        *(Q_0031D510 *)vars = move.velocity;
        func_0038D850(obj + 0xC0, obj + 0xC0, vars + 0x10);
        func_0038D850(obj + 0xD0, obj + 0xD0, vars + 0x10);
        func_0038D850(obj + 0xE0, obj + 0xE0, vars + 0x10);
        *(Q_0031D510 *)dmg.dir = *(Q_0031D510 *)vars;
        dmg.owner = obj;
        dmg.kind = 0x01030000;
        dmg.power = *(f32 *)(D_L01_002C5600 + D_001425C0[0x13] * 0xF0 + 0x6C);
        dmg.enabled = 1;
        func_0038CF68((f32 *)&dmg, (s32)&dmg, 1.0f);
        dmg.dir[3] = 5627.9248046875f;
        dmg.type = 3;
        dmg.klass = *(u16 *)(obj + 0xAA);
        dmg.flag = 1;
        if (func_003D4D00(pos, 1, D_001A71A0[0], &dmg, f20 + 0.5f)) goto explode;
        if (res > 0) {
            spin = *(Q_0031D510 *)vars;
            ((s32 *)&spin)[2] = 0;
            func_0038CE90(&spin, &spin, &normal);
            func_0038CF68((f32 *)&spin, (s32)&spin, 1.0f);
            func_003C4840(vars + 0x10, &spin, func_003824E0(0.06283185631036758f, 0.12566371262073517f));
            func_003A52A0(1, 0, obj);
            *(s32 *)(vars + 0x24) += 1;
            if (*(s32 *)(vars + 0x24) >= 4) {
                *(Q_0031D510 *)pos = D_L01_001EAA30[0];
                obj[0x20] = 1;
                *(s32 *)(vars + 0x20) = (D_L01_001DC894 * 5 + 2) / 6;
                f20 = D_L01_001DC878 * 0.06283185631036758f;
                if (*(s32 *)(vars + 0x2C)) f20 *= D_L01_001DC884;
                func_L01_00451290(obj, &tmp1, 1);
                func_0038CE20(&tmp2, &tmp1, func_0038CE68(&tmp1, vars));
                vel[0] -= ((f32 *)&tmp2)[0];
                vel[1] -= ((f32 *)&tmp2)[1];
                vel[2] -= ((f32 *)&tmp2)[2];
                func_0038CF68((f32 *)vars, (s32)vars, f20);
                *(Q_0031D510 *)(vars + 0x10) = spin;
                *(f32 *)(vars + 0x1C) = 0.06283185631036758f;
            }
        }
        break;
    case 1: {
        f32 drag;
        pos[0] += vel[0];
        pos[1] += vel[1];
        pos[2] += vel[2];
        func_003C4840(&spin, vars + 0x10, *(f32 *)(vars + 0x1C));
        func_0038D850(obj + 0xC0, obj + 0xC0, &spin);
        func_0038D850(obj + 0xD0, obj + 0xD0, &spin);
        func_0038D850(obj + 0xE0, obj + 0xE0, &spin);
        drag = (D_L01_001DC890 - 1.0f) * 1.2f + 1.0f;
        *(f32 *)(vars + 0x1C) *= drag;
        func_0038CE20(vars, vars, drag);
        if (func_0038CAD0((s32)(vars + 0x20))) goto explode;
        break;
    }
    case 2:
        func_003C2880((Moby_0031BEF0 *)obj);
        return;
    default:
        break;
    }
    if (D_L01_001D673C == 0 && D_L01_001D6740 == 0)
        func_L01_004471A8(obj, *(s32 *)(vars + 0x2C) ? D_L01_001DC878 * D_L01_001DC884 : D_L01_001DC878);
    return;
explode:
    func_L01_0031DB70(obj);
    func_003C2880((Moby_0031BEF0 *)obj);
}
