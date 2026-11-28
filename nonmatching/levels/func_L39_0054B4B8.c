/* PAL near miss (wave 13, r23), first matching-oriented draft of a fresh entry (built from retail over the
 * functional draft nonmatching/functional/func_L39_0054B4B8.c): 870 words differ in its file's context with
 * the file's flags (measured with the divs row `func_L39_0054B4B8 2` injected: one div.s, not in
 * config/levels/divs_nops.txt yet). The count is positional: this draft is 884 words against 893, and an
 * LCS alignment by mnemonic matches about 830 of them.
 * What it has: the projectile vars as a struct whose 0x68..0x6F word is a 64-bit bitfield unit (`long w68 :
 * 32` and four `u8 :8`), so `b6D == 0 && b6F == 0` and `b6C == 2 && b6D == 0` merge into retail's ld/and
 * tests; the target-state test as two compares (no range fold); the stack layout of retail (q0, v10, v20,
 * v30 .. v80, the 0x30-byte sweep descriptor at 0x90, vC0, the LOD out-float at 0xD0) with the network
 * message written into v80/vC0 as retail does; the vu0.h helpers in retail's load orders; the switch on
 * b6C with case 2 first (retail's body order); the chained `mat[1].w = mat[2].w = mat[0].w = 0.0f`
 * (mtc1 + three swc1); the cfg entry through an inline Entry() like func_L39_0054AC10 (one lui hoisted);
 * the hit-record struct D_L39_0025F740 (hit 0x18, count 0x1C, pos 0x20, normal 0x40); the duplicated
 * cleanup tails (goto into the hit block, a second copy after the timeout test).
 * Left: the frame is 0x170 against 0x190: retail spills two VU0 values to 0xE0/0xF0 around the
 * v60 = v50 + ex->v40 / v70 = v60 - o->pos pair (its scheduler hoists the o->pos load), which this
 * compile does not; register choices (tgt in s4, not s5; flagA = 1 stored before the first call); retail
 * keeps &v80 in s1 for the messages and the later calls; the 2/4 message kind as movn here, a branch in
 * retail; the order of the three message byte stores and of the D_001A5CD0 base loads.
 */
#include "common.h"

/* localdecomp:start func_L39_0054B4B8 */
struct M_0054B4B8;

typedef struct {
    u8 pad0[0xA0];
    V4_0054AC10 pos;
    u8 padB0[0x23A0 - 0xB0];
    V4_0054AC10 v23A0;
    u8 pad23B0[0x2524 - 0x23B0];
    struct M_0054B4B8 *w2524;
    u8 pad2528[0x2544 - 0x2528];
    s32 w2544;
    s32 w2548;
} G_0054B4B8;

typedef struct {
    f32 x;
    f32 y;
    f32 z;
    struct M_0054B4B8 *w0C;
    struct M_0054B4B8 *target;
    f32 f14;
    f32 f18;
    f32 f1C;
    f32 f20;
    s16 h24;
    u8 b26;
    u8 b27;
    f32 f28;
    s32 slot;
    V4_0054AC10 v30;
    V4_0054AC10 v40;
    s32 w50;
    s32 w54;
    G_0054B4B8 *owner;
    f32 f5C;
    f32 f60;
    s32 w64;
    long w68 : 32;
    u8 b6C : 8;
    u8 b6D : 8;
    u8 b6E : 8;
    u8 b6F : 8;
} P_0054B4B8;

typedef struct M_0054B4B8 {
    u8 pad0[0x10];
    V4_0054AC10 pos;
    u8 state;
    u8 pad21[0x68 - 0x21];
    P_0054B4B8 *vars;
    u8 pad6C[0xAA - 0x6C];
    u16 hAA;
    u8 padAC[0xBC - 0xAC];
    u8 bBC;
    u8 padBD[3];
    V4_0054AC10 mat[3];
} M_0054B4B8;

typedef struct {
    u8 pad0[0x18];
    M_0054B4B8 *hit;
    s32 count;
    V4_0054AC10 pos;
    V4_0054AC10 nrm;
} H_0054B4B8;

typedef struct {
    u8 pad0[4];
    s32 w4;
    s32 w8;
    u8 padC[0x170 - 0xC];
    s32 w170;
    u8 pad174[0x7D4 - 0x174];
    u8 b7D4;
} N_0054B4B8;

typedef struct {
    u8 pad0[0x21];
    s8 b21;
    u8 pad22[0x30 - 0x22];
    f32 f30;
    u8 pad34[0x80 - 0x34];
} C_0054B4B8;

typedef struct {
    V4_0054AC10 v;
    M_0054B4B8 *o;
    s32 w14;
    u8 b18;
    u8 b19;
    u16 h1A;
    f32 f1C;
    s32 w20;
    s32 w24;
    s32 w28;
    s32 w2C;
} D_0054B4B8;

extern C_0054B4B8 D_L39_0049C890_0054B4B8[];

static __inline__ C_0054B4B8 *Entry_0054B4B8(s32 i) {
    return &D_L39_0049C890_0054B4B8[i];
}

extern G_0054B4B8 *D_L39_0024CE20[];
extern H_0054B4B8 D_L39_0025F740;
extern N_0054B4B8 D_001A5CD0_0054B4B8;
extern s32 D_L39_002405B0;
__asm__(".extern D_L39_002405B0, 16");
extern s32 D_L39_0024112C;
__asm__(".extern D_L39_0024112C, 4");

extern f32 func_0038CEA8(void *);
extern f32 func_0038CF38(void *, void *);
extern void func_0038D850(void *, void *, void *);
extern f32 func_0038D0C8(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038D098(f32);
extern void func_L01_00446978(void *, void *);
extern s32 func_L39_005F33E0(s32, s32, void *);
extern f32 func_003C3D30(void *, s32, s32, f32);
extern void func_L01_00349998(void *, void *, void *, s32, f32);
extern void func_L39_0054C2B0(void *, void *, void *, s32);
extern void func_L39_0054C400(void *, void *, s32);
extern void func_L39_0054C7E8(void *, void *, void *, f32);
extern void func_L01_00399DE8(void *);
extern s32 func_L39_005BE900(void *, void *, f32);
extern void func_L01_00404A10(void *, void *);
extern s32 func_0038CB00(void *);
extern void func_L19_003B1A70(s32, void *, s32);
extern void func_L01_004C8668(s32);
extern void func_L01_0044BEC8(void *, void *);
extern void func_L39_0054ABC0(void *);
extern void func_003C2880(void *);
extern void func_0014AD08(s32, s32, s32, s32, s32, void *);

static __inline__ void send_0054B4B8(P_0054B4B8 *ex, s32 kind, s32 flags, u8 *msg) {
    msg[0] = ex->w64;
    msg[1] = kind;
    msg[2] = ex->w68;
    if (D_001A5CD0_0054B4B8.w170 == 0) {
        func_0014AD08(D_001A5CD0_0054B4B8.b7D4 | flags, D_001A5CD0_0054B4B8.w4, -1, D_L39_002405B0, 3, msg);
    }
}

void func_L39_0054B4B8(M_0054B4B8 *o) {
    V4_0054AC10 q0;
    V4_0054AC10 v10;
    V4_0054AC10 v20;
    V4_0054AC10 v30;
    V4_0054AC10 v40;
    V4_0054AC10 v50;
    V4_0054AC10 v60;
    V4_0054AC10 v70;
    V4_0054AC10 v80;
    D_0054B4B8 desc;
    V4_0054AC10 vC0;
    f32 vD0;
    P_0054B4B8 *ex;
    M_0054B4B8 *tgt;
    M_0054B4B8 *hitobj;
    C_0054B4B8 *cfg;
    f32 *hp;
    s32 flagA;
    s32 flagB;
    s32 flagC;
    s32 lod;
    s32 hitflag;
    s32 kind;
    s32 id;
    s32 i;
    f32 gain;
    f32 turn;
    f32 deg;
    f32 dot;
    f32 len;
    f32 len0;
    f32 dist;
    f32 a;
    f32 b;
    f32 d;

    ex = o->vars;
    q0 = o->pos;
    tgt = ex->target;
    func_L39_005BC330(&o->pos, &v10, 1);
    flagA = 1;
    if (tgt != 0) {
        hp = func_00382348(tgt);
        if (tgt->state == 0xFE) {
            goto dead;
        }
        if (tgt->state == 0xFD || (hp != 0 && hp[0] <= 0.0f)) {
        dead:
            ex->target = 0;
            tgt = 0;
        } else {
            v20 = tgt->pos;
            if (hp != 0) {
                func_0038CE20((u128_t *)&v30, (u128_t *)&tgt->mat[2], hp[4]);
                vec_add_ab(&v20, &v20, &v30);
            }
        }
    }
    flagB = 0;
    flagC = 0;
    if (ex->w64 != -1 && ex->b6D == 0 && ex->b6F == 0 && ex->b6C != 2 && ex->b6C != 4) {
        flagA = 0;
    }

    if (tgt != 0 && ((D_L39_0024112C & 3) != 0 || (ex->b6C == 2 && ex->b6D == 0)) && ex->h24 < 0x128
        && (s8)tgt->state >= 0 && ex->b26 != 0) {
        v30.x = ex->x;
        v30.y = ex->y;
        v30.z = ex->z;
        v30.w = 0.0f;
        gain = 2.0f;
        turn = 0.0187199991f;
        deg = 15.0f;
        vec_sub_ba(&v40, &v20, &v30);
        vec_add_ab(&v50, &v20, &v40);
        len0 = func_0038CEA8(&v40);
        vec_add_ab(&v60, &v50, &ex->v40);
        vec_sub_ba(&v70, &v60, &o->pos);
        if (ex->w64 != -1 && ex->b6D == 0) {
            switch (ex->b6C) {
            case 2:
                gain = -7.0f;
                turn = 6.28318548f;
                deg = 360.0f;
                flagA = 1;
                break;
            case 3:
                gain = 7.0f;
                break;
            case 4:
                flagA = 1;
                gain = 7.0f;
                break;
            }
        }
        dot = func_0038CE68(&ex->v30, &v70);
        len = func_0038CEA8(&v70);
        dist = func_0038CF00(&v20, &o->pos);
        if (gain < dot && len != 0.0f && len0 != 0.0f) {
            V4_0054AC10 *ax = &v80;
            len0 = o->mat[0].z;
            func_0038CE90(&v80, &v70, &ex->v30);
            func_0038CF68(&v80, &v80, 1.0f);
            len = func_0038CEA8(&ex->v30) * func_0038CEA8(&v70);
            if (len == 0.0f) {
                o->mat[0] = ex->v30;
            } else {
                a = 1.57079637f - func_0038D0C8(dot / len);
                b = deg * 0.0174532924f;
                if (b < a) {
                    a = b;
                } else {
                    b = -b;
                    if (a < b) {
                        a = b;
                    }
                }
                len = a * 0.5f * ex->f60;
                func_0038CE20((u128_t *)ax, (u128_t *)ax, func_0038D0B0(len));
                v80.w = func_0038D098(len);
                func_0038D850(&o->mat[0], &ex->v30, ax);
            }
            d = o->mat[0].z - len0;
            if (turn < fabs_asm(d)) {
                if (0.0f < d) {
                    o->mat[0].z = len0 + turn;
                } else {
                    o->mat[0].z = len0 - turn;
                }
            }
            func_0038CE90(&o->mat[1], &o->mat[0], &v10);
            func_0038CF68(&o->mat[1], &o->mat[1], 1.0f);
            func_0038CE90(&o->mat[2], &o->mat[1], &o->mat[0]);
            ex->v30 = o->mat[0];
            if (dist <= ex->f18 && flagA != 0) {
                if (func_003D3CB0(&o->pos, &v20, 0x12, ex->owner->w2524, 0) == 0) {
                    D_L39_0025F740.pos = v20;
                    D_L39_0025F740.count = -1;
                    flagB = 1;
                    D_L39_0025F740.hit = tgt;
                }
            }
        } else if (dot < 0.0f) {
            ex->b6E = 1;
            if (ex->w64 != 0 && ex->b6D != 0 && ex->b6C == 0) {
                send_0054B4B8(ex, 3, 0x80, (u8 *)&v80);
                ex->b6C = 3;
            }
        }
        func_L39_0054C7E8(o, &v20, &v40, dist);
    } else {
        func_L19_003B1A70(ex->w50, &ex->v30, 0);
        o->mat[0] = ex->v30;
        func_0038CE90(&o->mat[1], &o->mat[0], &v10);
        func_0038CF68(&o->mat[1], &o->mat[1], 1.0f);
        func_0038CE90(&o->mat[2], &o->mat[1], &o->mat[0]);
    }

    if (tgt != 0) {
        ex->x = v20.x;
        ex->y = v20.y;
        ex->z = v20.z;
    }
    o->mat[1].w = o->mat[2].w = o->mat[0].w = 0.0f;
    func_0038CE20((u128_t *)&v30, (u128_t *)&o->mat[0], ex->f18);
    vec_add_ab(&o->pos, &o->pos, &v30);
    if (o->pos.x < 2.0f || 1021.0f < o->pos.x || o->pos.y < 2.0f || 1021.0f < o->pos.y || o->pos.z < 2.0f
        || 1021.0f < o->pos.z) {
        goto cleanup;
    }
    func_L01_00399D78((u8 *)o, (u8 *)&v40);
    {
        V4_0054AC10 *trail = (V4_0054AC10 *)(D_L39_003BE020 + (ex->slot << 6));
        for (i = 3; i > 0; i--) {
            trail[i] = trail[i - 1];
        }
        trail[0] = v40;
    }
    v50 = o->pos;
    v50.w = 1.0f;
    lod = 4;
    if (func_L39_005BE900(&v50, &vD0, 96.0f) != -1) {
        lod = 1;
        if (!(vD0 < 1024.0f)) {
            lod = 3;
            if (vD0 < 4096.0f) {
                lod = 2;
            }
        }
    }
    ex->b27++;
    if (lod < 4) {
        if (ex->b27 >= 4) {
            func_L01_00404A10(func_L01_00399DE8, o);
        }
        func_L39_0054C400(o, &q0, lod);
    }
    v60 = o->pos;
    func_0038CE20((u128_t *)&v70, (u128_t *)&v10, -0.25f);
    vec_add_ba(&v70, &o->pos, &v70);
    if (func_003D3CB0(&v60, &v70, 2, 0, 0) != 0) {
        func_0038CE20((u128_t *)&v60, (u128_t *)&v10, 0.25f);
        vec_add_ba(&o->pos, &D_L39_0025F740.pos, &v60);
    }
    desc.o = o;
    hitflag = 0;
    desc.w14 = 0x1030001;
    if (func_L39_00648AE0(ex->owner, 4) != 0) {
        cfg = Entry_0054B4B8(Entry_0054B4B8(4)->b21);
    } else {
        cfg = Entry_0054B4B8(4);
    }
    desc.f1C = cfg->f30;
    desc.w20 = 1;
    desc.v = v30;
    kind = 0;
    func_0038CF68(&desc.v, &desc.v, 1.5f);
    desc.v.w = 5627.9248f;
    desc.b18 = 3;
    desc.b19 = 3;
    desc.h1A = o->hAA;
    desc.w28 = ex->w54;
    hitobj = ex->owner->w2524;
    if (flagA == 0) {
        kind = 2;
    } else if (ex->b6C == 3) {
        hitobj = tgt;
    }
    if (flagB == 0) {
        G_0054B4B8 *ent = D_L39_0024CE20[ex->owner->w2544];
        s32 r;
        id = -1;
        if (ent != 0) {
            id = ent->w2548;
        }
        func_L39_005FFDF8(id);
        r = func_003D3CB0(&q0, &o->pos, kind, hitobj, (s32)&desc);
        func_L39_005FFE78();
        if (r == 0) {
            goto after_hit;
        }
    }
    hitobj = 0;
    if (flagB != 0 && tgt != 0) {
        hitflag = 1;
        func_L01_00446978(tgt, &desc);
    }
    if (D_L39_0025F740.hit != 0) {
        if (D_L39_0025F740.hit != ex->owner->w2524 && D_L39_0025F740.hit != ex->w0C) {
            o->bBC = 2;
            hitobj = o;
            o->pos = D_L39_0025F740.pos;
            if (D_L39_0025F740.hit == tgt) {
                hitflag = 1;
            }
        }
    } else if (D_L39_0025F740.count > 0) {
        o->bBC = 1;
        o->pos = D_L39_0025F740.pos;
    }
after_hit:
    if (o->bBC == 0 && ex->b6C == 1) {
        flagC = 1;
        o->bBC = 1;
        D_L39_0025F740.pos = o->pos;
        D_L39_0025F740.hit = o;
        D_L39_0025F740.count = -1;
    }
    if (ex->b6E != 0 && ex->b6C == 2) {
        o->bBC = 1;
        D_L39_0025F740.pos = v20;
        D_L39_0025F740.count = -1;
        D_L39_0025F740.hit = tgt;
    }

    if (o->bBC != 0) {
        if (ex->w64 != -1) {
            if (ex->b6D != 0) {
                send_0054B4B8(ex, hitflag ? 2 : 4, 0xC0, (u8 *)&v80);
            } else if (ex->w68 == D_001A5CD0_0054B4B8.w8) {
                send_0054B4B8(ex, 1, 0x80, (u8 *)&v80);
            }
        }
        func_L39_005F33E0(0, 0, o);
        func_L39_005BC330(&o->pos, &v80, 1);
        i = 1;
        if (D_L39_0025F740.hit != 0 && D_L39_0025F740.count <= 0) {
            vec_sub_ba(&vC0, &ex->owner->v23A0, &o->pos);
            func_0038CF68(&vC0, &vC0, 1.0f);
        } else {
            func_0038CF68(&vC0, &D_L39_0025F740.nrm, 1.0f);
            if (0.100000001f <= fabs_asm(func_0038CE68(&vC0, &v80))) {
                i = 0;
            }
        }
        d = 0.0f;
        if (i != 0) {
            d = func_003C3D30(&o->pos, 0, 0, 0.5f);
        }
        func_L01_00349998(o, &o->pos, &vC0, lod, d);
        func_L39_0054C2B0(o, &v80, hitobj, flagC);
    cleanup:
        func_L01_0044BEC8(o, D_L39_0024C040);
        func_L01_004C8668(ex->w50);
        func_L39_0054ABC0(o);
        func_003C2880(o);
    } else {
        if (func_0038CB00(&ex->h24) == 0 && !(90.0f < func_0038CF38(&o->pos, &ex->owner->pos))) {
            return;
        }
        if (ex->w64 != -1 && ex->b6D != 0) {
            send_0054B4B8(ex, 4, 0x80, (u8 *)&vC0);
        }
        func_L01_0044BEC8(o, D_L39_0024C040);
        func_L01_004C8668(ex->w50);
        func_L39_0054ABC0(o);
        func_003C2880(o);
    }
}
/* localdecomp:end func_L39_0054B4B8 */
