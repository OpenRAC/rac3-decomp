/* func_L01_00341910 (Claude wave 14 r61, 2026-11-28). First draft kept here. */
/* func_L01_00341910 (PAL, levels), near miss (wave 14 r61, fresh entry): 471 differences with divs 2 injected
   (retail has two nops before its one div.s; 575 for the first plain-C port of the functional draft).
   This is the functional draft rebuilt on retail: the slot release as an inline helper (three sites), the level
   byte as D_001425C0[0x16] (retail's lui/addiu/lbu 0x16 form), the stat counter through a pointer local
   (pd = D_00142DE0), D_001A4BE0 held in a short-lived pointer per region, the particle offsets through
   o + 0x20, the colour preset written before the player-offset block, the damage record's damage read through a
   record type (lwc1 0x6C), the r != 0 arm first, one variable per loop (a shared counter took $s3 from v), and
   the lightning head as p = v10 (retail stores v10 to p's slot at the join; the functional draft's "head zeroed"
   branch is a misread: v1 is reloaded from v10 in the delay slots before that branch). No zeroing.
   Declarations this needs in the file: func_003A52A0 returns s32 (retail stores its result in v->slot; the
   file declares it void at its later prototype, whose other callers ignore the value), func_L01_00404808 gets
   func_L01_003424B0 for its void (*)(void) parameter as the file's func_L01_00340C68 already passes
   func_L01_003411A8, and D_L01_00221098 is read as a block-scope u8 *[] (the file's later declaration is the
   Table_00342D18 struct of func_L01_00342D18).
   Left: register allocation in the particle, damage, target and lightning loops is a permutation of retail's
   (retail: &D_L01_001E1950 $s2, the two D_L01_001E1970 walkers $fp/$s6, counter $s7, colour $s5, life $s0;
   damage count in $t1; target-section base in $s0), the particle field stores are scheduled after retail's early
   D_L01_001DD280/284/288 loads, the target section reaches its lq of v10 by bnel likely slots, and retail
   computes the D_L01_00279480[i] row address three times (two madd, one mult from D_L01_00279470) where ours
   shares one mult (about eight instructions shorter there). NEEDS divs row 'func_L01_00341910 2'. */
#include "common.h"

/* localdecomp:start func_L01_00341910 */
typedef struct {
    f32 last;
    s16 age;
    s16 pad6;
    s32 color;
    s32 slot;
    f32 f10;
    s32 flag14;
    s16 timers[4];
    u8 *targets[4];
} Vars_00341910;
typedef struct { u8 a, b; u8 pad2[0x6A]; f32 damage; } Rec_00341910;
typedef struct { vu0_v4 dir; u8 *source; s32 flags; u8 kind; u8 sub; u16 id; f32 damage; s32 one; } Hit_00341910;
__asm__(".extern D_L01_001DD240, 4");
__asm__(".extern D_L01_001DD248, 4");
__asm__(".extern D_L01_001DD258, 4");
__asm__(".extern D_L01_001DD25C, 4");
__asm__(".extern D_L01_001DD260, 4");
__asm__(".extern D_L01_001DD278, 4");
__asm__(".extern D_L01_001DD27C, 4");
__asm__(".extern D_L01_001DD280, 4");
__asm__(".extern D_L01_001DD284, 4");
__asm__(".extern D_L01_001DD288, 4");
__asm__(".extern D_L01_001DD28C, 4");
__asm__(".extern D_L01_001DD294, 4");
__asm__(".extern D_L01_001DD298, 4");
extern s32 D_L01_001D6694;
extern s32 D_L01_001DD240;
extern f32 D_L01_001DD248;
extern f32 D_L01_001DD258;
extern s32 D_L01_001DD25C;
extern f32 D_L01_001DD260;
extern s32 D_L01_001DD278;
extern s32 D_L01_001DD27C;
extern f32 D_L01_001DD280;
extern u32 D_L01_001DD284;
extern s32 D_L01_001DD288;
extern f32 D_L01_001DD28C;
extern s32 D_L01_001DD294;
extern s32 D_L01_001DD298;
extern u8 D_001A4BE0[];
extern u8 D_001A4C60[];
extern u8 D_001425C0[];
extern S_00341C10 D_L01_002C5600[];
extern u8 D_001A30B0[];
extern u8 D_00142DE0[];
extern u8 D_L01_001D66B0[];
extern u8 *D_L01_001EEA80[];
extern s32 D_L01_001E1950[];
extern s32 D_L01_001E1970[];
extern s16 D_L01_001E1990[];
extern s16 D_L01_001E19A0[];
extern s16 D_L01_001E19B0[];
extern vu0_v4 D_L01_00279480[][10];
void func_L01_003424B0(u8 *self);
static __inline__ void stop_00341910(u8 *self, Vars_00341910 *v) {
    extern void func_003A4F28(s32);
    if (v->slot != -1) {
        u8 *rec = D_001A30B0 + (v->slot << 7);
        if (*(u8 **)(rec + 0xDC) == self && rec[0xD0] != 0)
            func_003A4F28(v->slot);
    }
    v->slot = -1;
}
void func_L01_00341910(u8 *self) {
    extern s32 func_003A52A0(s32, s32, void *);
    extern void func_L01_004C93B0(void);
    extern void func_L01_004C94B0(void);
    extern s32 func_L01_004AA710(u8 *, s32);
    extern f32 func_L01_004C93D8(void);
    extern s32 func_L01_003415F8(s32);
    extern s32 func_L01_00343850(f32 t);
    extern s32 func_0038CB00(void *);
    extern s32 func_0038CAD0(void *);
    extern void func_003C2F58(s32 a, s32 b, void *c);
    extern f32 func_00382538(void);
    extern void func_00382760(f32 *out, f32 length, f32 a, f32 b);
    extern u8 *func_L01_0046CA28(void *, s32, s32, s32);
    extern s32 func_L01_0040E050(void *);
    extern s32 func_003D4D00(f32, void *, s32, void *, s32);
    extern f32 *func_00382348(void *);
    extern void func_0038CF68(void *out, void *in, f32 s);
    extern void func_L01_00446978(void *, void *);
    extern void func_L01_00343658(vu0_q *at, s32 colour);
    extern s32 func_L01_0034E558(void *, s32, void *, s32, s32);
    extern void func_00382580(f32, f32, void *);
    extern void func_0038D890(void *, void *, void *, f32);
    extern u8 *D_L01_00221098[];
    vu0_v4 tmp, v10, p;
    Vars_00341910 *v;
    s32 level, j, last, c0, c1, col;
    f32 t;
    u8 *base;

    v = *(Vars_00341910 **)(self + 0x68);
    if (D_L01_001D6694 != 0) return;
    *(vu0_q *)(self + 0x10) = *(vu0_q *)D_001A4C60;
    func_L01_004C93B0();
    if (D_L01_001D6694 == 0 && *(s32 *)(D_001A4C60 + 0x2544) != 0x74) {
        if (func_L01_004AA710(self, v->slot) == 0)
            v->slot = func_003A52A0(3, 4, self);
    } else if (func_L01_004AA710(self, v->slot) != 0) {
        stop_00341910(self, v);
    }
    level = (D_L01_002C5600 + D_001425C0[0x16])->b;
    if (level >= 4 && *(s16 *)(self + 0xAA) == 0xA5C && func_L01_004C93D8() == 0.0f) {
        s32 saved = D_L01_001DD298;
        D_L01_001DD298 = 0;
        if (func_L01_003415F8(level)) {
            stop_00341910(self, v);
            func_003A52A0(2, 0, self);
            D_L01_001DD298 = 0;
            func_003C2880((Obj *)self);
            return;
        }
        D_L01_001DD298 = saved;
    }
    t = func_L01_004C93D8();
    if (func_L01_00343850(t) == 0 || D_L01_001DD25C == 0x28) {
        stop_00341910(self, v);
        D_L01_001DD25C = 0;
        func_L01_004C94B0();
        func_003A52A0(2, 0, self);
        D_L01_001DD298 = 0;
        func_003C2880((Obj *)self);
        return;
    }
    if (t != v->last) {
        u8 *pd = D_00142DE0;
        *(s32 *)(pd + 0x58) += (s32)fabs_asm(v->last - t) << 5;
        v->last = t;
        v->age = (D_L01_001DD294 * 5 + 2) / 6;
    }
    {
        f32 ratio = (f32)v->age / (f32)((D_L01_001DD294 * 5 + 2) / 6);
        if (level >= 4) {
            c0 = 0xA06565; c1 = 0x3030A0;
        } else if (level == 3) {
            c0 = 0x905020; c1 = 0x2040A0;
        } else if (level == 2) {
            c0 = 0x205020; c1 = 0x3030A0;
        } else if (level == 1) {
            c0 = 0x204090; c1 = 0xA04020;
        } else {
            c0 = 0x202090; c1 = 0xA02020;
        }
        v->color = func_0038DBD8(c0, c1, ratio);
    }
    func_0038CB00(&v->age);
    col = 0x4080FF;
    {
        u8 *base = D_001A4BE0;
        func_0038CE20(&tmp, *(u8 **)(base + 0x25C0) + 0xE0, 0.75f);
        vec_add_ab(self + 0x10, base + 0x80, &tmp);
        func_003C2F58(*(s32 *)(base + 0x25C0), 10, &v10);
    }
    if (level >= 2) col = 0xFF8040;
    for (j = 0; j < 8; j++) {
        if (D_L01_001E1950[j] == 0) {
            f32 r1, r2;
            s32 n, life;
            u8 *o;
            n = func_00382498(D_L01_001DD278, D_L01_001DD27C);
            life = (n * 5 + 2) / 6;
            r1 = func_00382538();
            r2 = func_00382538();
            func_00382760((f32 *)&p, D_L01_001DD260, r1, r2);
            vec_add_ab(&p, &p, &v10);
            o = func_L01_0046CA28(&p, life, 2, 1);
            D_L01_001E1950[j] = (s32)o;
            if (o) {
                u8 *pv = o + 0x20;
                u32 c = D_L01_001DD284 | col;
                f32 size = D_L01_001DD280 * 210000.0f;
                u8 *tex = D_L01_00221098[D_L01_001DD288];
                *(f32 *)(pv + 0x10) = *(f32 *)(o + 0x10) - *(f32 *)(self + 0x10);
                *(f32 *)(pv + 0x14) = *(f32 *)(o + 0x14) - *(f32 *)(self + 0x14);
                *(f32 *)(pv + 0x18) = *(f32 *)(o + 0x18) - *(f32 *)(self + 0x18);
                *(u8 **)(pv + 4) = self;
                *(u32 *)(o + 4) = c;
                *(f32 *)(o + 0xC) = size;
                o[2] = tex[1];
                D_L01_001E1970[j] = life;
            }
            o = func_L01_0046CA28(&p, life, 2, 1);
            if (o) {
                u8 *pv = o + 0x20;
                *(f32 *)(pv + 0x10) = *(f32 *)(o + 0x10) - *(f32 *)(self + 0x10);
                *(f32 *)(pv + 0x14) = *(f32 *)(o + 0x14) - *(f32 *)(self + 0x14);
                *(f32 *)(pv + 0x18) = *(f32 *)(o + 0x18) - *(f32 *)(self + 0x18);
                *(u8 **)(pv + 4) = self;
                *(u32 *)(o + 4) = 0x307F7F7F;
                *(f32 *)(o + 0xC) = D_L01_001DD280 * 210000.0f * 0.3f;
                o[2] = D_L01_00221098[D_L01_001DD288][1];
            }
        } else if (func_0038CAD0(&D_L01_001E1970[j])) {
            D_L01_001E1950[j] = 0;
        }
    }
    func_0038CAD0(&v->flag14);
    last = 0;
    {
        s32 i;
        for (i = 0; i < 4; i++) {
            if (func_0038CB00(&v->timers[i])) {
                v->targets[i] = 0;
                last = i;
            }
        }
    }
    if (func_L01_0040E050(&v->f10) && level < 4) {
        Hit_00341910 dmg;
        vu0_v4 tmp2, q;
        s32 i, n;
        u8 *obj;
        f32 *r;
        base = D_001A4BE0;
        n = func_003D4D00(D_L01_001DD248 * 0.3f, self + 0x10, 1, *(void **)(base + 0x25C0), 0);
        if (n) {
            dmg.dir.w = 5627.9248f;
            dmg.source = self;
            dmg.flags = 0x10000;
            dmg.kind = 3;
            dmg.sub = 2;
            dmg.id = *(u16 *)(self + 0xAA);
            dmg.damage = ((Rec_00341910 *)(D_L01_002C5600 + D_001425C0[0x16]))->damage;
            dmg.one = 1;
            for (i = 0; i < n; i++) {
                obj = D_L01_001EEA80[i];
                if (obj[0x31] == 0 || obj == 0 || obj[0x20] == 0xFE || obj[0x20] == 0xFD
                    || *(u8 **)(obj + 0x24) == 0 || (*(u8 **)(obj + 0x24))[0x46] != 5)
                    continue;
                r = func_00382348(obj);
                if (r != 0) {
                    if (*r <= 0.0f) continue;
                    func_0038CE20(&tmp2, self + 0xE0, r[4]);
                    vec_add_ab(&p, obj + 0x10, &tmp2);
                } else {
                    *(vu0_q *)&p = *(vu0_q *)(obj + 0x10);
                }
                vec_sub_ab(&dmg, &p, self + 0x10);
                func_0038CF68(&dmg, &dmg, 1.0f);
                func_L01_00446978(obj, &dmg);
                func_0038CE20(&tmp2, &dmg, D_L01_001DD248 * 0.3f);
                vec_add_ba(&q, self + 0x10, &tmp2);
                func_L01_00343658((vu0_q *)&q, v->color);
                v->f10 = 0.5f;
            }
        }
    }
    base = D_001A4BE0;
    if (D_L01_001D6694 == 0 && level >= 4 && v->flag14 == 0
        && base[0x25ED] == 0 && *(s32 *)(base + 0x1220) >= 0x13) {
        s32 i, n;
        u8 *obj;
        f32 *r;
        n = func_003D4D00(D_L01_001DD258, self + 0x10, 1, *(void **)(base + 0x25C0), 0);
        for (i = 0; i < n; i++) {
            s32 idx = -1;
            s32 k;
            obj = D_L01_001EEA80[i];
            if (obj[0x31] == 0 || obj == 0 || obj[0x20] == 0xFE || obj[0x20] == 0xFD
                || *(u8 **)(obj + 0x24) == 0 || (*(u8 **)(obj + 0x24))[0x46] != 5)
                continue;
            r = func_00382348(obj);
            if (r != 0 && *r <= 0.0f) continue;
            for (k = 0; k < 4; k++) {
                if (D_L01_001EEA80[i] == v->targets[k]) break;
                if (v->targets[k] == 0) idx = k;
            }
            if (k != 4) continue;
            if (idx < 0) break;
            v->targets[idx] = D_L01_001EEA80[i];
            if (func_L01_0034E558(v->targets[idx], D_L01_001DD240, D_L01_001D66B0, 0, 0)) {
                D_L01_001DD25C++;
                func_003A52A0(5, 0, self);
                v->timers[last] = (func_00382498(0x14, 0x3C) * 5 + 2) / 6;
            }
            break;
        }
    }
    p = v10;
    {
    s32 i;
    for (i = 0; i < 5; i++) {
        if (func_0038CB00(&D_L01_001E1990[i])) D_L01_001E1990[i] = 0;
        if (D_L01_001E1990[i] == 0) {
            vu0_v4 dir, rel;
            s32 j, life;
            f32 sign;
            life = (func_00382498(3, 0x2D) * 5 + 2) / 6;
            sign = 1.0f;
            D_L01_001E19A0[i] = 0x40;
            D_L01_001E19B0[i] = life;
            D_L01_001E1990[i] = life;
            func_00382580(D_L01_001DD28C, D_L01_001DD28C, &dir);
            D_L01_00279480[i][0] = p;
            D_L01_00279480[i][0].w = 0.04f;
            for (j = 1; j < 10; j++) {
                vec_sub_ab(&rel, &D_L01_00279480[i][j - 1], &D_L01_001E29C0);
                func_0038D890(&dir, &dir, &rel, func_003824E0(0.08726646f, 1.3089969f) * sign);
                sign = -sign;
                vec_add_ab(&D_L01_00279480[i][j], &D_L01_00279480[i][j - 1], &dir);
                D_L01_00279480[i][j].w = 0.04f;
            }
        }
    }
    }
    func_L01_00404808(func_L01_003424B0, (char *)self);
}
/* localdecomp:end func_L01_00341910 */
