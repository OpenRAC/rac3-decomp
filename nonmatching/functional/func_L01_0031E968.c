/* functional: medium. Written from the PAL assembly (no earlier draft). Homing shot (a seeker bolt): flies and collides (Move struct, mode 3), steers its velocity towards the nearest live class-5 enemy, damages what it touches (damage record layout as func_L01_0031DFD8), explodes with a func_L01_003303B8 effect and removes itself. All 43 retail jal targets and $gp loads match; stack frame and scheduling differ. One odd retail test is kept as is: the spin kick only runs when fabs(random angle) < 1e-5. */
#include "vu0.h"
typedef int Q_0031E968 __attribute__((mode(TI)));
typedef struct {
    Q_0031E968 start, end, velocity;
    u8 *hit;
    s32 *options;
    s32 mode;
    f32 radius, factor0, factor1;
    s32 flags, unknown;
    s32 out90, out94;
    s32 field98;
    s32 pad9C;
} Move_0031E968;
typedef struct {
    f32 dir[4];
    u8 *owner;
    u32 kind;
    u8 type, flag;
    u16 klass;
    f32 power;
    s32 enabled;
} Dmg_0031E968;
extern u8 D_001DC8C8[12];
extern u8 D_001425C0[];
extern u8 *D_L01_001EEA80[];
extern s32 D_L01_001D673C __attribute__((section(".data")));
extern s32 D_L01_001D6740 __attribute__((section(".data")));
extern f32 D_L01_001DC8A0, D_L01_001DC8AC, D_L01_001DC8B0, D_L01_001DC8BC, D_L01_001DC8C0;
extern s32 D_L01_001DAFEC;
__asm__(".extern D_L01_001DC8A0, 4");
__asm__(".extern D_L01_001DC8AC, 4");
__asm__(".extern D_L01_001DC8B0, 4");
__asm__(".extern D_L01_001DC8BC, 4");
__asm__(".extern D_L01_001DC8C0, 4");
__asm__(".extern D_L01_001DAFEC, 4");
void func_L01_0031E968(u8 *obj) {
    extern void func_003C5180(void *, void *, s32);
    extern s32 func_L01_004CB2D8(void);
    extern void func_L01_004CAB30(void *, void *);
    extern void func_L01_004C8688(s32, void *, s32);
    extern void func_L01_004C7D40(void *, void *, f32);
    extern s32 func_L01_004C7E70(Move_0031E968 *, s32);
    extern s32 func_L01_004CB018(s32);
    extern void func_0038D850(void *, void *, void *);
    extern s32 func_003D4D00(void *, s32, u8 *, void *, f32);
    extern s32 func_003C4B50(u8 *);
    extern f32 *func_00382348(u8 *);
    extern f32 func_0038CF00(void *, void *);
    extern void func_0038CE20(void *, void *, f32);
    extern f32 func_0038CE68(void *, void *);
    extern f32 func_0038CEA8(void *);
    extern void func_0038CF68(f32 *, s32, f32);
    extern f32 func_L01_00443A18(f32, f32);
    extern f32 func_003824E0(f32, f32);
    extern s32 func_0038CB00(s32);
    extern void func_L01_0031B090(u8 *, s32, s32);
    extern void func_L01_003303B8(float, u8 *,
                                  s32, s32, s32, s32, s32, s32, s32,
                                  s32, s32, s32, s32, s32, s32, s32,
                                  s32,
                                  s32, s32, s32, s32, s32, s32, s32, s32, s32, s32,
                                  float, float, float);
    extern void func_L01_004C8668(s32);
    extern void func_003C2880(Moby_0031BEF0 *);
    extern void func_L01_004471A8(u8 *, f32);
    Q_0031E968 normal;
    Q_0031E968 old;
    Q_0031E968 tmp130, tmp140, tmp150, tmp160, tmp170;
    u8 optbuf[12];
    Move_0031E968 move;
    Dmg_0031E968 dmg;
    u8 *vars = *(u8 **)(obj + 0x68);
    f32 *pos = (f32 *)(obj + 0x10);
    f32 *vel = (f32 *)vars;
    s32 res, r, hit, n, i, idx;
    f32 radius, best, speed, ang;
    f32 *hp;
    u8 *o;
    func_003C5180(pos, &normal, 1);
    if (func_L01_004CB2D8()) func_L01_004CAB30(pos, pos);
    switch (obj[0x20]) {
    case 0:
        old = *(Q_0031E968 *)pos;
        pos[0] += vel[0];
        pos[1] += vel[1];
        pos[2] += vel[2];
        func_L01_004C8688(*(s32 *)(vars + 0x28), vars, 0);
        func_L01_004C7D40(pos, vars, 0.0058400002f);
        *(u64 *)optbuf = *(u64 *)D_001DC8C8;
        *(s32 *)(optbuf + 8) = *(s32 *)(D_001DC8C8 + 8);
        move.start = old;
        move.end = *(Q_0031E968 *)pos;
        move.velocity = *(Q_0031E968 *)vars;
        move.hit = obj;
        move.options = (s32 *)optbuf;
        move.mode = 3;
        move.radius = *(s32 *)(vars + 0x24) ? D_L01_001DC8BC : D_L01_001DC8AC;
        move.factor0 = (D_L01_001DC8A0 - 1.0f) * 1.2f + 1.0f;
        move.factor1 = 1.5f;
        move.flags = 0;
        move.unknown = 0;
        move.field98 = 0;
        res = func_L01_004C7E70(&move, -1);
        r = func_L01_004CB018(move.out94);
        *(Q_0031E968 *)pos = move.end;
        *(Q_0031E968 *)vars = move.velocity;
        func_0038D850(obj + 0xC0, obj + 0xC0, vars + 0x10);
        func_0038D850(obj + 0xD0, obj + 0xD0, vars + 0x10);
        func_0038D850(obj + 0xE0, obj + 0xE0, vars + 0x10);
        if (res > 0) {
            /* homing: steer towards the nearest live enemy of class 5 */
            n = func_003D4D00(pos, 1, (u8 *)D_001A71A0[0], 0, 7.0f);
            idx = -1;
            if (n != 0) {
                best = 10000.0f;
                for (i = 0; i < n; i++) {
                    o = D_L01_001EEA80[i];
                    if (o[0x31] == 0) continue;
                    if (func_003C4B50(o) != 0) continue;
                    hp = func_00382348(o);
                    if (hp == 0) continue;
                    if (*hp <= 0.0f) continue;
                    if (o == 0) continue;
                    if (*(u8 **)(o + 0x24) == 0) continue;
                    if ((*(u8 **)(o + 0x24))[0x46] != 5) continue;
                    ang = func_0038CF00(o + 0x10, pos);
                    if (ang < best) {
                        best = ang;
                        idx = i;
                    }
                }
                if (idx >= 0) {
                    o = D_L01_001EEA80[idx];
                    hp = func_00382348(o);
                    *(Q_0031E968 *)&dmg = *(Q_0031E968 *)(o + 0x10);
                    if (D_L01_001D673C != 0) {
                        func_0038CE20(&tmp130, o + 0xE0, hp[4]);
                        ((f32 *)&dmg)[0] += ((f32 *)&tmp130)[0];
                        ((f32 *)&dmg)[1] += ((f32 *)&tmp130)[1];
                        ((f32 *)&dmg)[2] += ((f32 *)&tmp130)[2];
                    } else {
                        ((f32 *)&dmg)[2] += hp[4];
                    }
                    func_0038CE20(&tmp130, &normal, func_0038CE68(&normal, vars));
                    ((f32 *)&tmp140)[0] = vel[0] - ((f32 *)&tmp130)[0];
                    ((f32 *)&tmp140)[1] = vel[1] - ((f32 *)&tmp130)[1];
                    ((f32 *)&tmp140)[2] = vel[2] - ((f32 *)&tmp130)[2];
                    ((f32 *)&tmp140)[3] = vel[3];
                    speed = func_0038CEA8(&tmp140);
                    if (speed != 0.0f) {
                        ((f32 *)&tmp150)[0] = ((f32 *)&dmg)[0] - pos[0];
                        ((f32 *)&tmp150)[1] = ((f32 *)&dmg)[1] - pos[1];
                        ((f32 *)&tmp150)[2] = ((f32 *)&dmg)[2] - pos[2];
                        func_0038CE20(&tmp160, &normal, func_0038CE68(&tmp150, &normal));
                        ((f32 *)&tmp170)[0] = ((f32 *)&tmp150)[0] - ((f32 *)&tmp160)[0];
                        ((f32 *)&tmp170)[1] = ((f32 *)&tmp150)[1] - ((f32 *)&tmp160)[1];
                        ((f32 *)&tmp170)[2] = ((f32 *)&tmp150)[2] - ((f32 *)&tmp160)[2];
                        if (speed < 0.08000001f) speed = 0.08000001f;
                        func_0038CF68((f32 *)&tmp170, (s32)&tmp170, speed);
                        vel[0] = ((f32 *)&tmp170)[0] + ((f32 *)&tmp130)[0];
                        vel[1] = ((f32 *)&tmp170)[1] + ((f32 *)&tmp130)[1];
                        vel[2] = ((f32 *)&tmp170)[2] + ((f32 *)&tmp130)[2];
                    }
                }
            }
            /* random sideways kick of the spin vector */
            *(Q_0031E968 *)&dmg = *(Q_0031E968 *)vars;
            ((s32 *)&dmg)[2] = 0;
            func_0038CE90((f32 *)&dmg, (f32 *)&dmg, (f32 *)&normal);
            func_0038CF68((f32 *)&dmg, (s32)&dmg, 1.0f);
            ang = func_L01_00443A18(0.0f, 0.5235988f);
            if (fabs_asm(ang) < 0.00001f) {
                func_003C4840((f32 *)&tmp130, (u8 *)&normal, ang);
                func_0038D850(&dmg, &dmg, &tmp130);
            }
            func_003C4840((f32 *)(vars + 0x10), (u8 *)&dmg, func_003824E0(0.06283185631036758f, 0.12566371262073517f));
            func_003A52A0(0, 0, obj);
        }
        /* damage record for whatever the shot touches */
        *(Q_0031E968 *)&dmg = *(Q_0031E968 *)vars;
        dmg.owner = obj;
        dmg.kind = 0x01030000;
        dmg.power = *(f32 *)((u8 *)D_L01_002C5600 + D_001425C0[0x13] * 0xF0 + 0x6C);
        if (*(s32 *)(vars + 0x2C))
            dmg.power = *(f32 *)((u8 *)D_L01_002C5600 + D_001425C0[0x3F] * 0xF0 + 0x6C) * 0.1f;
        hit = 0;
        dmg.enabled = 1;
        func_0038CF68(dmg.dir, (s32)dmg.dir, 1.0f);
        radius = 2.0f;
        dmg.dir[3] = 5627.9248046875f;
        dmg.type = 3;
        dmg.flag = 1;
        dmg.klass = *(u16 *)(obj + 0xAA);
        if (*(s32 *)(vars + 0x24)) radius = 7.0f;
        if (func_0038CB00((s32)(vars + 0x20))) {
            hit = 1;
        } else if (res > 0 && (u32)(r - 1) < 2) {
            hit = 1;
        } else if (*(s16 *)(vars + 0x22) == 0) {
            n = func_003D4D00(pos, 1, (u8 *)D_001A71A0[0], 0, radius);
            for (i = 0; i < n; i++) {
                s32 immune;
                o = D_L01_001EEA80[i];
                hp = func_00382348(o);
                immune = func_003C4B50(o);
                if (immune == 0) {
                    if (hp == 0) continue;
                    if (!(0.0f < *hp)) continue;
                    if (*(s16 *)((u8 *)hp + 6) != 0) continue;
                }
                if (*(s32 *)(vars + 0x2C) == 0 && o != 0) {
                    s32 k = *(s16 *)(o + 0xAA);
                    if (k == 0x19DF || k == 0x19F1 || k == 0x1BC5 || k == 0x1A18 || k == 0x1A1C ||
                        k == 0x1A1F || k == 0x1A13 || k == 0x1666 || k == 0x1AFD || k == 0x1A0A ||
                        k == 0x16CB || k == 0x1BD9)
                        dmg.power *= 0.5f;
                }
                ((void (*)(u8 *, void *))func_L01_00446978)(o, &dmg);
                hit = 1;
                if (immune == 0) {
                    if (*(s32 *)(vars + 0x24) == 0) func_L01_0031B090(o, 0x13, *(s32 *)(obj + 0xB8));
                    else func_L01_0031B090(o, 0xA6, *(s32 *)(obj + 0xB8));
                }
                break;
            }
        } else {
            s32 t = *(s16 *)(vars + 0x22) - 1;
            *(s16 *)(vars + 0x22) = t;
            if (t < 0) *(s16 *)(vars + 0x22) = 0;
        }
        if (hit) {
            f32 scale = 0.6f;
            s32 sdk;
            func_003A52A0(1, 0, obj);
            if (*(s32 *)(vars + 0x24)) scale = 1.2f;
            sdk = D_L01_001DAFEC;
            if (*(s32 *)(vars + 0x2C)) scale = 1.0f;
            func_L01_003303B8(scale, (u8 *)pos, 0, 6, 5, 6, 8, 10, 0,
                0, 0, 0, 0, 0, 0, 0,
                sdk,
                0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0,
                0.0f, 0.0f, 0.0f);
            func_L01_004C8668(*(s32 *)(vars + 0x28));
            func_003C2880((Moby_0031BEF0 *)obj);
            return;
        }
        break;
    case 2:
        func_L01_004C8668(*(s32 *)(vars + 0x28));
        func_003C2880((Moby_0031BEF0 *)obj);
        return;
    default:
        break;
    }
    if (D_L01_001D673C == 0 && D_L01_001D6740 == 0)
        func_L01_004471A8(obj, *(s32 *)(vars + 0x24) ? D_L01_001DC8C0 : D_L01_001DC8B0);
}
