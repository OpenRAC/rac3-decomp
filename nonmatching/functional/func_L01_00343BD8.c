/* functional: medium. Medium: not byte-checked; long, all branches read against asm once. Open: D_001D673C_sda (gp-0x6174) semantics unknown (a global flag switching aim computation); func_L01_004512E8 second arg inferred. */
typedef struct {
    vu0_v4 velocity;      /* 0x00 */
    vu0_v4 trail[4];      /* 0x10..0x4F: position history, newest first */
    u8 *target;           /* 0x50 */
    s32 unk_54;           /* 0x54 */
    f32 wander_a;         /* 0x58 */
    f32 wander_b;         /* 0x5C */
    f32 speed;            /* 0x60 */
    f32 phase64;          /* 0x64 */
    f32 max_speed;        /* 0x68 */
    s16 light;            /* 0x6C (low half: puff counter) and 0x6E (light handle) */
    s16 light_h;
    f32 accel;            /* 0x70 */
    f32 unk_74;           /* 0x74 */
    u8 rgba[4];           /* 0x78 */
    u8 search;            /* 0x7C */
    u8 trail_timer;       /* 0x7D */
    u16 life;             /* 0x7E */
    u8 weave;             /* 0x80 */
    u8 unk_81;            /* 0x81 */
    u8 pad82[2];
    f32 weave_phase;      /* 0x84 */
    f32 weave_rate;       /* 0x88 */
} Missile_00343BD8;
typedef struct { vu0_v4 dir; u8 *source; s32 w14; u8 b18; u8 b19; u16 h1A; f32 f1C; s32 w20; } Hit_00343BD8;
extern s32 D_001D673C_sda;
__asm__(".extern D_001D673C_sda, 4");
extern s32 D_L01_001D6740;
extern s32 D_L01_001DAFEC;
extern s32 D_L01_001EAA18;
extern u8 D_L01_001EAA30[];
extern s32 D_001A71A0[];
extern s16 D_001A4F48[];
extern s32 D_L01_001DD2A0[];
extern u8 D_001A4BE0[];
extern u8 D_001A4C60[];
extern u8 *D_L01_001EEA80[];
extern s32 func_13D3E0(void);
extern void func_L01_004C84D8(s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038D000(void *, void *, void *);
extern void func_0038D890(void *, void *, void *, f32);
extern f32 func_0038CEA8(void *);
extern f32 func_0038CF00(void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038DB00(f32, f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_0038CAD0(void *);
extern void func_L01_004CAB30(void *, void *);
extern void func_L01_004CAC40(void *, void *);
extern s32 func_003D4D00(void *, s32, f32, void *, s32);
extern s32 func_L01_004C8258(s32, u8 *);
extern void func_L01_004C81F0(s32, u8 *, s32);
extern s32 func_L01_003FB640(f32, void *, s32, u8 *);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern void func_L01_00446760(void *, void *, s32, void *, f32);
extern void func_L01_00446978(void *, void *);
extern void func_L01_0034C9F0(u8 *, s32, u8 *);
extern void func_003A52A0(s32, s32, void *);
extern s32 func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                             s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_0044BB30(void *, void *, s32, f32, f32);
extern void func_L01_00451290(void *, void *, s32);
extern void func_L01_004512E8(void *, void *);
extern u8 *func_00382348(void *);
extern void func_L01_0044C3C0(void *, void *, void *, void *, void *, s32, f32, f32, f32, f32);
extern f32 func_L01_0040E548(void *, void *);
extern s32 func_L01_004CB2D8(void);
extern u8 *func_L01_00473268(u8 *, u8 *, s32, s32, s32, f32);
extern void func_L01_004C8668(s32);
extern void func_L01_004C8598(s32);
extern void func_L01_004C8688(s32, void *, s32);
extern void func_L01_00404A10(void (*)(void *), void *);
extern void func_L01_00344C78(char *);

void func_L01_00343BD8(u8 *self) {
    Missile_00343BD8 *v = *(Missile_00343BD8 **)(self + 0x68);
    vu0_v4 vA0, vB0, tmpC0, tmpD0, aim, tmpF0, oldpos;
    Hit_00343BD8 info;
    s32 state, tmp110, tmp114, tmp118;
    s32 k, n, hit, flag;
    f32 d, len;
    u8 *base;

    vA0.x = 0.0f; vA0.y = 0.0f; vA0.z = 1.0f; vA0.w = 0.0f;
    vB0.x = -0.3f; vB0.y = 0.0f; vB0.z = 0.0f; vB0.w = 1.0f;
    func_L01_004C84D8((s32)self);
    *(u16 *)(self + 0x96) += 1;
    state = self[0x20];
    if (state == 2) {
        func_L01_004C8668(v->light_h);
        func_L01_004C8598(D_001A71A0[0]);
        func_003C2880((Obj *)self);
        return;
    }
    if (state != 1 && state != 0) {
        goto finish;
    }
    if (state == 0) {
        s32 r;
        self[0x20] = 1;
        r = func_13D3E0();
        *(s32 *)&v->phase64 = 0;
        v->light = r % 2;
        func_0038CF68(self + 0xC0, v, 1.0f);
        func_0038CE90(self + 0xD0, self + 0xC0, &vA0);
        func_0038CF68(self + 0xD0, self + 0xD0, 1.0f);
        func_0038CE90(self + 0xE0, self + 0xD0, self + 0xC0);
        func_0038D000(&vB0, &vB0, self + 0xC0);
        func_L01_004CAB30(self + 0x10, self + 0x10);
        func_L01_004CAC40(v, v);
        vB0.x += *(f32 *)(self + 0x10); vB0.y += *(f32 *)(self + 0x14); vB0.z += *(f32 *)(self + 0x18);
        func_0038CF68(&tmpC0, &vB0, 0.01f);
        v->trail[0] = vB0;
        for (k = 0; k < 3; k++) {
            v->trail[k + 1] = v->trail[k];
            v->trail[k + 1].x += tmpC0.x; v->trail[k + 1].y += tmpC0.y; v->trail[k + 1].z += tmpC0.z;
        }
        v->trail_timer = 2;
    }
    /* 343D7C: per-frame update */
    v->phase64 = v->phase64 - 0.1f;
    if (v->phase64 <= -8.0f) {
        v->phase64 = v->phase64 + 8.0f;
    }
    base = D_001A4BE0;
    if (v->target != 0) {
        if (v->search == 0) {
            if ((s8)v->target[0x20] < 0 || *(s32 *)(v->target + 0x98) == 0 || v->target == self) {
                v->target = 0;
            }
            if (v->target == 0) {
                if (v->weave != 0 && *(u16 *)(self + 0x96) >= 0x33) {
                    n = func_003D4D00(self + 0x10, 0, 30.0f, self, 0);
                } else {
                    n = func_003D4D00(self + 0x10, 0, 15.0f, self, 0);
                }
                for (k = 0; k < n; k++) {
                    u8 *obj = D_L01_001EEA80[k];
                    s16 cls;
                    if (!(*(u16 *)(obj + 0x34) & 0x1000)) {
                        continue;
                    }
                    cls = *(s16 *)(obj + 0xAA);
                    if (cls == 0xA7E || cls == 0x1ADA || cls == 0 || cls == 0x1853) {
                        continue;
                    }
                    if (obj == *(u8 **)(base + 0x25C0)) {
                        continue;
                    }
                    if ((*(u8 **)(obj + 0x24))[0x46] != 5) {
                        continue;
                    }
                    if (func_L01_004C8258(*(s32 *)(base + 0x25C0), obj) != 0) {
                        func_L01_004C81F0(*(s32 *)(base + 0x25C0), obj, 0xC8);
                        v->target = obj;
                        break;
                    }
                }
            }
        }
    }
    oldpos = *(vu0_v4 *)(self + 0x10);
    func_0038CF68(self + 0xC0, v, 1.0f);
    func_0038CE90(self + 0xD0, self + 0xC0, &vA0);
    func_0038CF68(self + 0xD0, self + 0xD0, 1.0f);
    func_0038CE90(self + 0xE0, self + 0xD0, self + 0xC0);
    if (v->weave != 0) {
        f32 k1 = 0.017453294f;
        len = func_0038CEA8(v);
        tmpD0 = *(vu0_v4 *)(self + 0xC0);
        v->weave_phase = func_0038DAB8(v->weave_phase, v->weave_rate * k1);
        func_0038D890(v, &tmpD0, self + 0xD0, v->weave_phase * k1);
        func_0038D890(v, v, self + 0xE0, v->weave_phase * k1);
        func_0038CF68(v, v, len);
    }
    *(f32 *)(self + 0x10) += v->velocity.x;
    *(f32 *)(self + 0x14) += v->velocity.y;
    *(f32 *)(self + 0x18) += v->velocity.z;
    tmp110 = v->life;
    if (func_0038CAD0(&tmp110) != 0) {
        self[0x20] = 2;
        *(u16 *)(self + 0x34) |= 0x41;
    }
    v->life = (u16)tmp110;
    if (*(f32 *)(self + 0x10) < 2.0f || *(f32 *)(self + 0x10) > 1021.0f
        || *(f32 *)(self + 0x14) < 2.0f || *(f32 *)(self + 0x14) > 1021.0f
        || *(f32 *)(self + 0x18) < 2.0f || *(f32 *)(self + 0x18) > 1021.0f) {
        self[0x20] = 2;
        *(vu0_v4 *)(self + 0x10) = oldpos;
        *(u16 *)(self + 0x34) |= 0x41;
    }
    vB0.x = -0.3f; vB0.y = 0.0f; vB0.z = 0.0f; vB0.w = 1.0f;
    func_0038D000(&vB0, &vB0, self + 0xC0);
    vB0.x += *(f32 *)(self + 0x10); vB0.y += *(f32 *)(self + 0x14); vB0.z += *(f32 *)(self + 0x18);
    func_L01_004CAB30(&vB0, &vB0);
    *(f32 *)(self + 0xD4) *= 0.5f;
    *(f32 *)(self + 0xE8) *= 0.5f;
    if (v->weave != 0 && *(u16 *)(self + 0x96) < 0xD) {
        hit = 0;
    } else {
        hit = func_L01_003FB640(0.25f, self + 0x10, 0x10, self) != 0;
        if (!hit) {
            hit = func_003D3CB0(&oldpos, self + 0x10, 0x10, self, 0) != 0;
        }
    }
    if (hit && D_L01_001EAA18 != 0) {
        s16 hc = *(s16 *)(*(u8 **)&D_L01_001EAA18 + 0xAA);
        if ((u16)(hc - 0x1366) < 2 || hc == 0x1ADA || hc == 0 || hc == 0x1853) {
            hit = 0;
        }
    }
    if (hit) {
        n = func_003D4D00(self + 0x10, 0, 1.0f, self, 0);
        for (k = 0; k < n; k++) {
            u8 *obj = D_L01_001EEA80[k];
            u16 fl = *(u16 *)(obj + 0x34);
            s16 cls;
            if (!(fl & 0x1000)) {
                if (!(fl & 0x4000)) {
                    continue;
                }
                cls = *(s16 *)(obj + 0xAA);
                if (cls == 0x1ADA || cls == 0 || cls == 0x1853) {
                    continue;
                }
            }
            if (v->weave != 0) {
                func_L01_00446760(&info, *(void **)(self + 0xB8), 0x110000, v, v->unk_74);
            } else if (v->unk_81 != 0) {
                func_L01_00446760(&info, *(void **)(self + 0xB8), 0x110000, v, v->unk_74);
            } else {
                func_L01_00446760(&info, self, 0x110000, v, v->unk_74);
            }
            info.b18 = 5;
            info.b19 = 3;
            info.h1A = *(u16 *)(self + 0xAA);
            func_L01_00446978(obj, &info);
            if (v->weave == 0) {
                func_L01_0034C9F0(obj, 0xA2, *(u8 **)(self + 0xB8));
            }
        }
        if (v->weave != 0) {
            func_003A52A0(0, 0, self);
            func_L01_003303B8(D_L01_001EAA30, 0, 1, 1, 1, 1, 1, 0, 0.4f, 0.0f, 0.0f, 2.0f,
                              0, 1, 0, 0, 0, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF,
                              0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
        } else {
            func_L01_0044BB30(self, D_L01_001EAA30, 0, 1.0f, 13.0f);
        }
        self[0x20] = 2;
        *(u16 *)(self + 0x34) |= 0x41;
    }
    /* 3444C0: speed and steering */
    if (v->max_speed < v->speed) {
        func_0038CF68(v, v, v->max_speed * 0.02f);
    } else {
        func_0038CF68(v, v, v->speed * 0.02f);
    }
    v->speed = v->speed + v->accel * 1.44f;
    if (v->target != 0) {
        u8 *r = func_00382348(v->target);
        func_L01_00451290(v->target, &tmpD0, 1);
        flag = D_001D673C_sda;
        if (flag != 0) {
            func_L01_004512E8(self, &tmpF0);
            func_0038CF68(&tmpF0, &tmpF0, 1.0f);
            aim = tmpF0;
            aim.x += *(f32 *)(v->target + 0x10); aim.y += *(f32 *)(v->target + 0x14); aim.z += *(f32 *)(v->target + 0x18);
        } else if (r != 0) {
            func_0038CE20(&aim, v->target + 0xE0, *(f32 *)(r + 0x10));
            aim.x += *(f32 *)(v->target + 0x10); aim.y += *(f32 *)(v->target + 0x14); aim.z += *(f32 *)(v->target + 0x18);
        } else {
            aim = *(vu0_v4 *)(v->target + 0x10);
        }
        d = func_0038CF00(self + 0x10, &aim);
        {
            f32 lim = 0.25f;
            if (v->rgba[3] != 0) {
                lim = 1.5f;
            }
            if (d < lim) {
                d = 0.0f;
            }
        }
        if (D_001D673C_sda == 0 && D_L01_001D6740 == 0 && D_001A4F48[0] == 0) {
            f32 sn, w;
            sn = func_0038D0B0(v->wander_b);
            w = d * 0.7488f;
            if (0.7488f < w) {
                w = sn * 0.7488f;
            } else {
                w = sn * w;
            }
            aim.y += w;
            sn = func_0038D098(v->wander_b);
            w = d * 0.7519f;
            if (0.7519f < w) {
                w = sn * 0.7519f;
            } else {
                w = sn * w;
            }
            aim.x -= w;
            sn = func_0038D0B0(v->wander_a);
            w = d * 0.5f;
            if (0.5f < w) {
                w = (sn + 1.0f) * 0.5f;
            } else {
                w = (sn + 1.0f) * w;
            }
            aim.z += w;
        }
        if (v->rgba[3] != 0) {
            func_L01_0044C3C0(self + 0x10, v, &aim, &v->unk_54, &tmpD0, 0, 0.036f, 0.2400f, 0.0f, 1.0f);
        } else {
            func_L01_0044C3C0(self + 0x10, v, &aim, &v->unk_54, &tmpD0, 0, 0.036f, 0.2400f, 0.0f, 0.25f);
        }
    }
    d = func_0038CF00(self + 0x10, &oldpos);
    tmp114 = v->rgba[2];
    if (func_0038CAD0(&tmp114) != 0 || v->rgba[2] == 0) {
        s32 puff = 0;
        if (v->weave != 0 && func_L01_0040E548(self + 0x10, D_001A4C60) > 900.0f) {
            puff = 1;
        }
        if (!puff && func_L01_004CB2D8() == 0) {
            func_L01_00473268(self, (u8 *)&tmpD0, D_L01_001DD2A0[v->light % 2], v->rgba[0], v->rgba[1], d * 0.5f);
        }
        v->light = v->light + 1;
    }
    v->rgba[2] = (u8)tmp114;
    v->wander_b = func_0038DAB8(v->wander_b, func_003824E0(0.01f, 0.1f));
    v->wander_a = func_0038DB00(v->wander_a, func_003824E0(0.025f, 0.25f));
    tmp118 = v->trail_timer;
    if (D_L01_001DAFEC != 0) {
        for (k = 3; k > 0; k--) {
            v->trail[k] = v->trail[k - 1];
            func_L01_004CAB30(&v->trail[k], &v->trail[k]);
        }
        v->trail[0] = vB0;
    } else if (func_0038CAD0(&tmp118) != 0) {
        for (k = 3; k > 0; k--) {
            v->trail[k] = v->trail[k - 1];
        }
        v->trail[0] = vB0;
        tmp118 = 2;
    }
    v->trail_timer = (u8)tmp118;
finish:
    if (self != 0 && self[0x20] != 0xFE && self[0x20] != 0xFD) {
        func_L01_004CAB30(self + 0x10, self + 0x10);
        func_L01_004CAC40(v, v);
        func_L01_004C8688(v->light_h, v, 0);
    }
    func_L01_00404A10((void (*)(void *))func_L01_00344C78, self);
}
