/* functional: medium. Medium: long function, not byte checked; unverified guesses are names only (target/lock semantics). Upper 64 bits of $3 residue in head vector assumed 0. */
typedef struct {
    f32 lastTime;      /* 0x00: last frame value seen from func_L01_004C93D8 */
    s16 age;           /* 0x04 */
    s16 pad6;
    s32 color;         /* 0x08 */
    s32 slot;          /* 0x0C: -1 or the func_003A52A0 handle */
    f32 f10;           /* 0x10 */
    s32 flag14;        /* 0x14 */
    s16 timers[4];     /* 0x18 */
    s32 targets[4];    /* 0x20 */
} Vars_00341910;
extern s32 D_001DD240_sda;
extern f32 D_001DD248_sda;
extern f32 D_001DD258_sda;
extern f32 D_001DD260_sda;
extern s32 D_001DD278_sda;
extern s32 D_001DD27C_sda;
extern f32 D_001DD280_sda;
extern s32 D_001DD284_sda;
extern s32 D_001DD288_sda;
extern f32 D_001DD28C_sda;
extern s32 D_001DD294_sda;
extern s32 D_001DD298_sda;
__asm__(".extern D_001DD240_sda, 4");
__asm__(".extern D_001DD248_sda, 4");
__asm__(".extern D_001DD258_sda, 4");
__asm__(".extern D_001DD260_sda, 4");
__asm__(".extern D_001DD278_sda, 4");
__asm__(".extern D_001DD27C_sda, 4");
__asm__(".extern D_001DD280_sda, 4");
__asm__(".extern D_001DD284_sda, 4");
__asm__(".extern D_001DD288_sda, 4");
__asm__(".extern D_001DD28C_sda, 4");
__asm__(".extern D_001DD294_sda, 4");
__asm__(".extern D_001DD298_sda, 4");
extern s32 D_L01_001D6694;
extern s32 D_L01_001DD25C;
extern u8 D_001A4BE0[];
extern u8 D_001425D6[];
extern S_00341C10 D_L01_002C5600[];
extern u8 *D_L01_00221098[];
extern u8 D_001A4C60[];
extern u8 D_001A30B0[];
extern u8 D_00142DE0[];
extern u8 D_001D66B0[];
extern u8 *D_L01_001EEA80[];
extern s32 D_L01_001E1950[];
extern s32 D_L01_001E1970[];
extern s16 D_L01_001E1990[];
extern s16 D_L01_001E19A0[];
extern s16 D_L01_001E19B0[];
extern vu0_v4 D_L01_00279480[][10];
extern vu0_v4 D_L01_001E29C0;
extern s32 func_L01_004AA710(void *, s32);
extern void func_L01_004C93B0(void);
extern void func_L01_004C94B0(void);
extern s32 func_L01_0040E050(void *);
extern s32 func_0038CB00(void *);
extern s32 func_0038CAD0(void *);
extern s32 func_0038DBD8(s32, s32, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038D890(void *, void *, void *, f32);
extern s32 func_00382498(s32, s32);
extern f32 func_00382538(void);
extern void func_00382760(void *, f32, f32, f32);
extern void func_00382580(void *, f32, f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_003D4D00(void *, s32, f32, void *, s32);
extern u8 *func_L01_0046CA28(void *, s32, s32, s32);
extern void func_L01_00446978(void *, void *);
extern void func_L01_00343658(void *, s32);
extern s32 func_L01_0034E558(void *, s32, void *, s32, s32);
extern u8 *func_00382348(void *);
extern s32 func_L01_003415F8(s32);
extern void func_L01_003424B0(u8 *);
extern f32 func_L01_004C93D8(void);
typedef struct { vu0_v4 dir; u8 *source; s32 w14; u8 b18; u8 b19; u16 h1A; f32 f1C; s32 w20; } Dmg_00341910;

void func_L01_00341910(u8 *self) {
    Vars_00341910 *v;
    s32 level;
    f32 t;
    u8 *base;
    s32 i, j, n, k;
    s32 life;
    f32 sign;
    vu0_v4 v10, p, tmp;
    Dmg_00341910 dmg;
    vu0_v4 head, tmp2;
    s32 last;
    u8 *r;
    u8 *obj;
    s32 *pf;

    if (D_L01_001D6694 != 0) {
        return;
    }
    v = *(Vars_00341910 **)(self + 0x68);
    *(vu0_q *)(self + 0x10) = *(vu0_q *)D_001A4C60;
    func_L01_004C93B0();
    if (D_L01_001D6694 == 0 && *(s32 *)(D_001A4C60 + 0x2544) != 0x74) {
        if (func_L01_004AA710(self, v->slot) == 0) {
            v->slot = func_003A52A0(3, 4, self);
        }
    } else if (func_L01_004AA710(self, v->slot) != 0) {
        if (v->slot != -1) {
            u8 *rec = D_001A30B0 + (v->slot << 7);
            if (*(u8 **)(rec + 0xDC) == self && rec[0xD0] != 0) {
                func_003A4F28(v->slot);
            }
        }
        v->slot = -1;
    }
    level = D_L01_002C5600[D_001425D6[0]].b;
    if (level >= 4 && *(s16 *)(self + 0xAA) == 0xA5C && func_L01_004C93D8() == 0.0f) {
        s32 saved = D_001DD298_sda;
        D_001DD298_sda = 0;
        if (func_L01_003415F8(level) != 0) {
            if (v->slot != -1) {
                u8 *rec = D_001A30B0 + (v->slot << 7);
                if (*(u8 **)(rec + 0xDC) == self && rec[0xD0] != 0) {
                    func_003A4F28(v->slot);
                }
            }
            v->slot = -1;
            func_003A52A0(2, 0, self);
            D_001DD298_sda = 0;
            func_003C2880((Obj *)self);
            return;
        }
        D_001DD298_sda = saved;
    }
    t = func_L01_004C93D8();
    if (func_L01_00343850(t) == 0 || D_L01_001DD25C == 0x28) {
        if (v->slot != -1) {
            u8 *rec = D_001A30B0 + (v->slot << 7);
            if (*(u8 **)(rec + 0xDC) == self && rec[0xD0] != 0) {
                func_003A4F28(v->slot);
            }
        }
        v->slot = -1;
        D_L01_001DD25C = 0;
        func_L01_004C94B0();
        func_003A52A0(2, 0, self);
        D_001DD298_sda = 0;
        func_003C2880((Obj *)self);
        return;
    }
    if (t != v->lastTime) {
        f32 d = v->lastTime - t;
        if (d < 0.0f) {
            d = -d;
        }
        *(s32 *)(D_00142DE0 + 0x58) += (s32)d << 5;
        v->lastTime = t;
        v->age = (D_001DD294_sda * 5 + 2) / 6;
    }
    {
        f32 ratio = (f32)v->age / (f32)((D_001DD294_sda * 5 + 2) / 6);
        s32 c0, c1;
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
    base = D_001A4BE0;
    func_0038CE20(&tmp, *(u8 **)(base + 0x25C0) + 0xE0, 0.75f);
    {
        vu0_v4 *pos = (vu0_v4 *)(self + 0x10);
        vu0_v4 *src = (vu0_v4 *)(base + 0x80);
        *pos = *src;
        pos->x += tmp.x; pos->y += tmp.y; pos->z += tmp.z; /* vadd.xyz keeps w of base+0x80 */
    }
    func_003C2F58(*(s32 *)(base + 0x25C0), 10, &v10);
    {
        s32 col = (level < 2) ? 0x4080FF : 0xFF8040;
        for (j = 0; j < 8; j++) {
            if (D_L01_001E1950[j] == 0) {
                f32 r1, r2;
                u8 *o;
                n = func_00382498(D_001DD278_sda, D_001DD27C_sda);
                life = (n * 5 + 2) / 6;
                r1 = func_00382538();
                r2 = func_00382538();
                func_00382760(&p, D_001DD260_sda, r1, r2);
                p.x += v10.x; p.y += v10.y; p.z += v10.z;
                o = func_L01_0046CA28(&p, life, 2, 1);
                D_L01_001E1950[j] = (s32)o;
                if (o != 0) {
                    *(f32 *)(o + 0x30) = *(f32 *)(o + 0x10) - *(f32 *)(self + 0x10);
                    *(f32 *)(o + 0x34) = *(f32 *)(o + 0x14) - *(f32 *)(self + 0x14);
                    *(f32 *)(o + 0x38) = *(f32 *)(o + 0x18) - *(f32 *)(self + 0x18);
                    *(u8 **)(o + 0x24) = self;
                    *(s32 *)(o + 4) = D_001DD284_sda | col;
                    *(f32 *)(o + 0xC) = D_001DD280_sda * 210000.0f;
                    o[2] = D_L01_00221098[D_001DD288_sda][1];
                    D_L01_001E1970[j] = life;
                }
                o = func_L01_0046CA28(&p, life, 2, 1);
                if (o != 0) {
                    *(f32 *)(o + 0x30) = *(f32 *)(o + 0x10) - *(f32 *)(self + 0x10);
                    *(f32 *)(o + 0x34) = *(f32 *)(o + 0x14) - *(f32 *)(self + 0x14);
                    *(f32 *)(o + 0x38) = *(f32 *)(o + 0x18) - *(f32 *)(self + 0x18);
                    *(u8 **)(o + 0x24) = self;
                    *(s32 *)(o + 4) = 0x307F7F7F;
                    *(f32 *)(o + 0xC) = (D_001DD280_sda * 210000.0f) * 0.3f;
                    o[2] = D_L01_00221098[D_001DD288_sda][1];
                }
            } else if (func_0038CAD0(&D_L01_001E1970[j]) != 0) {
                D_L01_001E1950[j] = 0;
            }
        }
    }
    func_0038CAD0(&v->flag14);
    last = 0;
    for (i = 0; i < 4; i++) {
        if (func_0038CB00(&v->timers[i]) != 0) {
            v->targets[i] = 0;
            last = i;
        }
    }
    if (func_L01_0040E050(&v->f10) != 0 && level < 4) {
        n = func_003D4D00(self + 0x10, 1, D_001DD248_sda * 0.3f, *(void **)(base + 0x25C0), 0);
        if (n != 0) {
            dmg.dir.w = 5627.9248f;
            dmg.source = self;
            dmg.w14 = 0x10000;
            dmg.b18 = 3;
            dmg.b19 = 2;
            dmg.h1A = *(u16 *)(self + 0xAA);
            dmg.f1C = *(f32 *)((u8 *)&D_L01_002C5600[D_001425D6[0]] + 0x6C);
            dmg.w20 = 1;
            for (k = 0; k < n; k++) {
                obj = D_L01_001EEA80[k];
                if (obj == 0 || obj[0x31] == 0 || obj[0x20] == 0xFE || obj[0x20] == 0xFD
                    || *(u8 **)(obj + 0x24) == 0 || (*(u8 **)(obj + 0x24))[0x46] != 5) {
                    continue;
                }
                r = func_00382348(obj);
                if (r == 0) {
                    p = *(vu0_v4 *)(obj + 0x10);
                } else {
                    if (*(f32 *)r <= 0.0f) {
                        continue;
                    }
                    func_0038CE20(&tmp2, self + 0xE0, *(f32 *)(r + 0x10));
                    p = *(vu0_v4 *)(obj + 0x10);
                    p.x += tmp2.x; p.y += tmp2.y; p.z += tmp2.z;
                }
                dmg.dir = p;
                dmg.dir.x -= *(f32 *)(self + 0x10);
                dmg.dir.y -= *(f32 *)(self + 0x14);
                dmg.dir.z -= *(f32 *)(self + 0x18);
                func_0038CF68(&dmg.dir, &dmg.dir, 1.0f);
                func_L01_00446978(obj, &dmg);
                func_0038CE20(&tmp2, &dmg.dir, D_001DD248_sda * 0.3f);
                p = tmp2;
                p.x = *(f32 *)(self + 0x10) + tmp2.x;
                p.y = *(f32 *)(self + 0x14) + tmp2.y;
                p.z = *(f32 *)(self + 0x18) + tmp2.z;
                p.w = *(f32 *)(self + 0x1C);
                func_L01_00343658(&p, v->color);
                v->f10 = 0.5f;
            }
        }
    }
    head = v10;
    if (D_L01_001D6694 == 0 && level >= 4 && v->flag14 == 0) {
        if (base[0x25ED] != 0 || *(s32 *)(base + 0x1220) < 0x13) {
            /* retail stores $3 (== 0) here: x,y are 0; z,w are register residue, taken as 0 */
            head.x = 0.0f; head.y = 0.0f; head.z = 0.0f; head.w = 0.0f;
        } else {
            n = func_003D4D00(self + 0x10, 1, D_001DD258_sda, *(void **)(base + 0x25C0), 0);
            for (k = 0; k < n; k++) {
                s32 idx = -1;
                s32 q;
                obj = D_L01_001EEA80[k];
                if (obj == 0 || obj[0x31] == 0 || obj[0x20] == 0xFE || obj[0x20] == 0xFD
                    || *(u8 **)(obj + 0x24) == 0 || (*(u8 **)(obj + 0x24))[0x46] != 5) {
                    continue;
                }
                r = func_00382348(obj);
                if (r != 0 && *(f32 *)r <= 0.0f) {
                    continue;
                }
                if ((s32)obj == v->targets[0]) {
                    q = 0;
                } else {
                    if (v->targets[0] == 0) {
                        idx = 0;
                    }
                    for (q = 1; q < 4; q++) {
                        if ((s32)obj == v->targets[q]) {
                            break;
                        }
                        if (v->targets[q] == 0) {
                            idx = q;
                        }
                    }
                }
                if (q != 4) {
                    continue;
                }
                if (idx < 0) {
                    break;
                }
                v->targets[idx] = (s32)obj;
                if (func_L01_0034E558(obj, D_001DD240_sda, D_001D66B0, 0, 0) != 0) {
                    D_L01_001DD25C = D_L01_001DD25C + 1;
                    func_003A52A0(5, 0, self);
                    v->timers[last] = (func_00382498(0x14, 0x3C) * 5 + 2) / 6;
                }
                break;
            }
        }
    }
    sign = 1.0f;
    for (i = 0; i < 5; i++) {
        if (func_0038CB00(&D_L01_001E1990[i]) != 0) {
            D_L01_001E1990[i] = 0;
        }
        if (D_L01_001E1990[i] == 0) {
            life = (func_00382498(3, 0x2D) * 5 + 2) / 6;
            D_L01_001E19A0[i] = 0x40;
            D_L01_001E19B0[i] = life;
            D_L01_001E1990[i] = life;
            func_00382580(&dmg.dir, D_001DD28C_sda, D_001DD28C_sda);
            D_L01_00279480[i][0] = head;
            D_L01_00279480[i][0].w = 0.04f;
            sign = 1.0f;
            for (j = 0; j < 9; j++) {
                f32 ang;
                tmp = D_L01_00279480[i][j];
                tmp.x -= D_L01_001E29C0.x; tmp.y -= D_L01_001E29C0.y; tmp.z -= D_L01_001E29C0.z;
                ang = func_003824E0(0.0873f, 1.309f);
                func_0038D890(&dmg.dir, &dmg.dir, &tmp, ang * sign);
                sign = -sign;
                D_L01_00279480[i][j + 1] = D_L01_00279480[i][j];
                D_L01_00279480[i][j + 1].x += dmg.dir.x;
                D_L01_00279480[i][j + 1].y += dmg.dir.y;
                D_L01_00279480[i][j + 1].z += dmg.dir.z;
                D_L01_00279480[i][j + 1].w = 0.04f;
            }
        }
    }
    func_L01_00404808((void (*)(void))func_L01_003424B0, (char *)self);
}
