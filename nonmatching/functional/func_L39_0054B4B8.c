/* functional: medium. Per-frame flight update of the multiplayer-menu homing projectile spawned by func_L39_0054AC10: validates its target, steers its direction (ex+0x30) towards the target with a clamped turn (state at ex+0x6C picks the gain: 3 and 4 use 7.0, 2 uses -7.0 with a full-turn clamp, others 2.0), moves it, culls it outside [2,1021] on any axis, shifts its 4-quad trail history, picks an effect LOD (1-4) from a terrain probe (func_L39_005BE900), sweeps for hits with func_003D3CB0 and reports impacts / timeouts to the net layer (func_0014AD08) and the hit handlers (func_L39_0054C2B0, func_L01_00349998). When the target is gone ex+0x10 is cleared and, as in retail, the target point sp+0x20 is only valid with a live target. */
typedef int q128_0054B4B8 __attribute__((mode(TI)));
extern u8 D_L39_0049C890_0054B4B8[];
extern u8 *D_L39_0024CE20[8] __attribute__((section(".sdata")));
extern s32 D_L39_0025F740[];
extern f32 D_L39_0025F760[4];
extern f32 D_L39_0025F780[4];
extern u8 D_L39_003BE020[];
extern s16 D_L39_0024C040[];
extern u8 D_001A5CD0_0054B4B8[];
extern s32 D_L39_002405B0;
__asm__(".extern D_L39_0024112C, 4");
extern s32 D_L39_0024112C;

extern void func_L39_005BC330(void *, void *, s32);
extern f32 *func_00382348(void *);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038CEA8(void *);
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038CF00(void *, void *);
extern f32 func_0038CF38(void *, void *);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038D850(void *, void *, void *);
extern f32 func_0038D0C8(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038D098(f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern s32 func_L39_00648AE0(void *, s32);
extern void func_L39_005FFDF8(s32);
extern void func_L39_005FFE78(void);
extern void func_L01_00446978(void *, void *);
extern s32 func_L39_005F33E0(s32, s32, void *);
extern f32 func_003C3D30(void *, s32, s32, f32);
extern void func_L01_00349998(void *, void *, void *, s32, f32);
extern void func_L39_0054C2B0(void *, void *, void *, s32);
extern void func_L39_0054C400(void *, void *, s32);
extern void func_L39_0054C7E8(void *, void *, void *, f32);
extern void func_L01_00399D78(void *, void *);
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

/* d.xyz = a.xyz + b.xyz, d.w = a.w (vadd.xyz into a's register) */
static __inline__ void vadd_0054B4B8(f32 *d, f32 *a, f32 *b) {
    f32 w = a[3];
    d[0] = a[0] + b[0];
    d[1] = a[1] + b[1];
    d[2] = a[2] + b[2];
    d[3] = w;
}

static __inline__ void vsub_0054B4B8(f32 *d, f32 *a, f32 *b) {
    f32 w = a[3];
    d[0] = a[0] - b[0];
    d[1] = a[1] - b[1];
    d[2] = a[2] - b[2];
    d[3] = w;
}

static __inline__ void send_0054B4B8(u8 *ex, s32 kind, s32 flags) {
    u8 msg[16];
    msg[0] = ex[0x64];
    msg[1] = (u8)kind;
    msg[2] = ex[0x68];
    if (*(s32 *)(D_001A5CD0_0054B4B8 + 0x170) == 0) {
        func_0014AD08(D_001A5CD0_0054B4B8[0x7D4] | flags, *(s32 *)(D_001A5CD0_0054B4B8 + 4), -1, D_L39_002405B0, 3, msg);
    }
}

void func_L39_0054B4B8(u8 *o) {
    u8 *ex = *(u8 **)(o + 0x68);
    u8 *tgt;
    u8 *hitobj;
    u8 *cfg;
    u8 *g;
    f32 *hp;
    f32 q0[4] __attribute__((aligned(16)));
    f32 v10[4] __attribute__((aligned(16)));
    f32 v20[4] __attribute__((aligned(16)));
    f32 v30[4] __attribute__((aligned(16)));
    f32 v40[4] __attribute__((aligned(16)));
    f32 v50[4] __attribute__((aligned(16)));
    f32 v60[4] __attribute__((aligned(16)));
    f32 v70[4] __attribute__((aligned(16)));
    f32 v80[4] __attribute__((aligned(16)));
    f32 vC0[4] __attribute__((aligned(16)));
    f32 vE0[4] __attribute__((aligned(16)));
    f32 vF0[4] __attribute__((aligned(16)));
    f32 vD0;
    u8 desc[0x30] __attribute__((aligned(16)));
    s32 flagA;
    s32 flagB;
    s32 flagC;
    s32 lod;
    s32 hit;
    s32 hitflag;
    s32 kind;
    s32 id;
    s32 i;
    s32 cap;
    f32 f20, f21, f22, f23, f24, f25, f26, f0, f1, f2, ang;

    *(q128_0054B4B8 *)q0 = *(q128_0054B4B8 *)(o + 0x10);
    tgt = *(u8 **)(ex + 0x10);
    func_L39_005BC330(o + 0x10, v10, 1);
    flagA = 1;
    flagB = 0;
    flagC = 0;
    v20[0] = 0.0f;
    v20[1] = 0.0f;
    v20[2] = 0.0f;
    v20[3] = 0.0f;
    if (tgt != 0) {
        hp = func_00382348(tgt);
        if (tgt[0x20] == 0xFE || tgt[0x20] == 0xFD || (hp != 0 && hp[0] <= 0.0f)) {
            *(s32 *)(ex + 0x10) = 0;
            tgt = 0;
        } else {
            v20[0] = *(f32 *)(tgt + 0x10);
            v20[1] = *(f32 *)(tgt + 0x14);
            v20[2] = *(f32 *)(tgt + 0x18);
            v20[3] = *(f32 *)(tgt + 0x1C);
            if (hp != 0) {
                func_0038CE20(v30, tgt + 0xE0, hp[4]);
                vadd_0054B4B8(v20, v20, v30);
            }
        }
    }
    if (*(s32 *)(ex + 0x64) != -1 && ex[0x6D] == 0 && ex[0x6F] == 0 && ex[0x6C] != 2 && ex[0x6C] != 4) {
        flagA = 0;
    }

    if (tgt != 0
        && ((D_L39_0024112C & 3) != 0 || (ex[0x6C] == 2 && ex[0x6D] == 0))
        && *(s16 *)(ex + 0x24) < 0x128
        && (s8)tgt[0x20] >= 0
        && ex[0x26] != 0) {
        /* homing */
        v30[0] = *(f32 *)ex;
        v30[1] = *(f32 *)(ex + 4);
        v30[2] = *(f32 *)(ex + 8);
        v30[3] = 0.0f;
        f22 = 2.0f;
        f24 = 0.0187199991f;
        f26 = 15.0f;
        vsub_0054B4B8(v40, v20, v30);
        vadd_0054B4B8(v50, v20, v40);
        f23 = func_0038CEA8(v40);
        *(q128_0054B4B8 *)vF0 = *(q128_0054B4B8 *)v50;
        *(q128_0054B4B8 *)vE0 = *(q128_0054B4B8 *)(o + 0x10);
        v60[0] = vF0[0] + *(f32 *)(ex + 0x40);
        v60[1] = vF0[1] + *(f32 *)(ex + 0x44);
        v60[2] = vF0[2] + *(f32 *)(ex + 0x48);
        v60[3] = *(f32 *)(ex + 0x4C);
        vsub_0054B4B8(v70, v60, vE0);
        if (*(s32 *)(ex + 0x64) != -1 && ex[0x6D] == 0) {
            switch (ex[0x6C]) {
            case 3:
                f22 = 7.0f;
                break;
            case 2:
                f22 = -7.0f;
                f24 = 6.28318548f;
                f26 = 360.0f;
                flagA = 1;
                break;
            case 4:
                flagA = 1;
                f22 = 7.0f;
                break;
            default:
                break;
            }
        }
        f21 = func_0038CE68(ex + 0x30, v70);
        f20 = func_0038CEA8(v70);
        f25 = func_0038CF00(v20, o + 0x10);
        if (f22 < f21 && f20 != 0.0f && f23 != 0.0f) {
            f23 = *(f32 *)(o + 0xC8);
            func_0038CE90(v80, v70, ex + 0x30);
            func_0038CF68(v80, v80, 1.0f);
            f20 = func_0038CEA8(ex + 0x30) * func_0038CEA8(v70);
            if (f20 == 0.0f) {
                *(q128_0054B4B8 *)(o + 0xC0) = *(q128_0054B4B8 *)(ex + 0x30);
            } else {
                f1 = 1.57079637f - func_0038D0C8(f21 / f20);
                f0 = f26 * 0.0174532924f;
                if (f0 < f1) {
                    f1 = f0;
                } else {
                    f0 = -f0;
                    if (f1 < f0) {
                        f1 = f0;
                    }
                }
                f20 = (f1 * 0.5f) * *(f32 *)(ex + 0x60);
                f0 = func_0038D0B0(f20);
                func_0038CE20(v80, v80, f0);
                v80[3] = func_0038D098(f20);
                func_0038D850(o + 0xC0, ex + 0x30, v80);
            }
            f0 = *(f32 *)(o + 0xC8);
            f2 = f0 - f23;
            f1 = fabs_asm(f2);
            if (f24 < f1) {
                if (0.0f < f2) {
                    f0 = f23 + f24;
                } else {
                    f0 = f23 - f24;
                }
                *(f32 *)(o + 0xC8) = f0;
            }
            func_0038CE90(o + 0xD0, o + 0xC0, v10);
            func_0038CF68(o + 0xD0, o + 0xD0, 1.0f);
            func_0038CE90(o + 0xE0, o + 0xD0, o + 0xC0);
            f0 = *(f32 *)(ex + 0x18);
            *(q128_0054B4B8 *)(ex + 0x30) = *(q128_0054B4B8 *)(o + 0xC0);
            if (f25 <= f0 && flagA != 0) {
                if (func_003D3CB0(o + 0x10, v20, 0x12, *(void **)(*(u8 **)(ex + 0x58) + 0x2524), 0) == 0) {
                    *(q128_0054B4B8 *)D_L39_0025F760 = *(q128_0054B4B8 *)v20;
                    D_L39_0025F740[7] = -1;
                    flagB = 1;
                    D_L39_0025F740[6] = (s32)tgt;
                }
            }
        } else {
            f0 = 0.0f;
            if (f21 < f0) {
                ex[0x6E] = 1;
                if (*(s32 *)(ex + 0x64) != 0) {
                    if (ex[0x6D] != 0 && ex[0x6C] == 0) {
                        send_0054B4B8(ex, 3, 0x80);
                        ex[0x6C] = 3;
                    }
                }
            }
        }
        func_L39_0054C7E8(o, v20, v40, f25);
    } else {
        func_L19_003B1A70(*(s32 *)(ex + 0x50), ex + 0x30, 0);
        *(q128_0054B4B8 *)(o + 0xC0) = *(q128_0054B4B8 *)(ex + 0x30);
        func_0038CE90(o + 0xD0, o + 0xC0, v10);
        func_0038CF68(o + 0xD0, o + 0xD0, 1.0f);
        func_0038CE90(o + 0xE0, o + 0xD0, o + 0xC0);
    }

    if (tgt != 0) {
        *(f32 *)ex = v20[0];
        *(f32 *)(ex + 4) = v20[1];
        *(f32 *)(ex + 8) = v20[2];
    }
    *(f32 *)(o + 0xCC) = 0.0f;
    *(f32 *)(o + 0xEC) = 0.0f;
    *(f32 *)(o + 0xDC) = 0.0f;
    func_0038CE20(v30, o + 0xC0, *(f32 *)(ex + 0x18));
    vadd_0054B4B8((f32 *)(o + 0x10), (f32 *)(o + 0x10), v30);
    if (*(f32 *)(o + 0x10) < 2.0f || 1021.0f < *(f32 *)(o + 0x10)
        || *(f32 *)(o + 0x14) < 2.0f || 1021.0f < *(f32 *)(o + 0x14)
        || *(f32 *)(o + 0x18) < 2.0f || 1021.0f < *(f32 *)(o + 0x18)) {
        goto cleanup;
    }
    func_L01_00399D78(o, v40);
    {
        u8 *trail = D_L39_003BE020 + (*(s32 *)(ex + 0x2C) << 6);
        for (i = 3; i > 0; i--) {
            *(q128_0054B4B8 *)(trail + i * 0x10) = *(q128_0054B4B8 *)(trail + (i - 1) * 0x10);
        }
        *(q128_0054B4B8 *)trail = *(q128_0054B4B8 *)v40;
    }
    *(q128_0054B4B8 *)v50 = *(q128_0054B4B8 *)(o + 0x10);
    v50[3] = 1.0f;
    id = func_L39_005BE900(v50, &vD0, 96.0f);
    lod = 4;
    if (id != -1) {
        lod = 1;
        if (!(vD0 < 1024.0f)) {
            lod = 3;
            if (vD0 < 4096.0f) {
                lod = 2;
            }
        }
    }
    ex[0x27]++;
    if (lod < 4) {
        if (ex[0x27] >= 4) {
            func_L01_00404A10(func_L01_00399DE8, o);
        }
        func_L39_0054C400(o, q0, lod);
    }
    *(q128_0054B4B8 *)v60 = *(q128_0054B4B8 *)(o + 0x10);
    func_0038CE20(v70, v10, -0.25f);
    vadd_0054B4B8(v70, (f32 *)(o + 0x10), v70);
    if (func_003D3CB0(v60, v70, 2, 0, 0) != 0) {
        func_0038CE20(v60, v10, 0.25f);
        vadd_0054B4B8((f32 *)(o + 0x10), D_L39_0025F760, v60);
    }
    hitflag = 0;
    g = *(u8 **)(ex + 0x58);
    if (func_L39_00648AE0(g, 4) != 0) {
        cfg = D_L39_0049C890_0054B4B8 + ((s8)D_L39_0049C890_0054B4B8[0x221] << 7);
    } else {
        cfg = D_L39_0049C890_0054B4B8 + 0x200;
    }
    *(q128_0054B4B8 *)desc = *(q128_0054B4B8 *)v30;
    func_0038CF68(desc, desc, 1.5f);
    *(f32 *)(desc + 0xC) = 5627.9248f;
    *(u8 **)(desc + 0x10) = o;
    *(s32 *)(desc + 0x14) = 0x1030001;
    desc[0x18] = 3;
    desc[0x19] = 3;
    *(u16 *)(desc + 0x1A) = *(u16 *)(o + 0xAA);
    *(f32 *)(desc + 0x1C) = *(f32 *)(cfg + 0x30);
    *(s32 *)(desc + 0x20) = 1;
    *(s32 *)(desc + 0x28) = *(s32 *)(ex + 0x54);
    kind = 0;
    hitobj = *(u8 **)(g + 0x2524);
    if (flagA == 0) {
        kind = 2;
    } else if (ex[0x6C] == 3) {
        hitobj = tgt;
    }
    if (flagB == 0) {
        s32 r;
        u8 *ent = D_L39_0024CE20[*(s32 *)(g + 0x2544)];
        id = -1;
        if (ent != 0) {
            id = *(s32 *)(ent + 0x2548);
        }
        func_L39_005FFDF8(id);
        r = func_003D3CB0(q0, o + 0x10, kind, hitobj, (s32)desc);
        func_L39_005FFE78();
        if (r == 0) {
            goto after_hit;
        }
    }
    hitobj = 0;
    if (flagB != 0 && tgt != 0) {
        hitflag = 1;
        func_L01_00446978(tgt, desc);
    }
    if (D_L39_0025F740[6] == 0) {
        if (D_L39_0025F740[7] > 0) {
            o[0xBC] = 1;
            *(q128_0054B4B8 *)(o + 0x10) = *(q128_0054B4B8 *)(D_L39_0025F740 + 8);
        }
    } else if ((u8 *)D_L39_0025F740[6] == *(u8 **)(*(u8 **)(ex + 0x58) + 0x2524)) {
        /* hit the owner: ignored */
    } else if ((u8 *)D_L39_0025F740[6] == *(u8 **)(ex + 0xC)) {
        /* hit the shooter: ignored */
    } else {
        o[0xBC] = 2;
        hitobj = o;
        *(q128_0054B4B8 *)(o + 0x10) = *(q128_0054B4B8 *)(D_L39_0025F740 + 8);
        if ((u8 *)D_L39_0025F740[6] == tgt) {
            hitflag = 1;
        }
    }
after_hit:
    if (o[0xBC] == 0 && ex[0x6C] == 1) {
        flagC = 1;
        o[0xBC] = 1;
        *(q128_0054B4B8 *)D_L39_0025F760 = *(q128_0054B4B8 *)(o + 0x10);
        D_L39_0025F740[6] = (s32)o;
        D_L39_0025F740[7] = -1;
    }
    if (ex[0x6E] != 0 && ex[0x6C] == 2) {
        o[0xBC] = 1;
        *(q128_0054B4B8 *)D_L39_0025F760 = *(q128_0054B4B8 *)v20;
        D_L39_0025F740[7] = -1;
        D_L39_0025F740[6] = (s32)tgt;
    }

    if (o[0xBC] != 0) {
        if (*(s32 *)(ex + 0x64) != -1) {
            if (ex[0x6D] != 0) {
                send_0054B4B8(ex, hitflag ? 4 : 2, 0xC0);
            } else if (*(s32 *)(ex + 0x68) == *(s32 *)(D_001A5CD0_0054B4B8 + 8)) {
                send_0054B4B8(ex, 1, 0x80);
            }
        }
        func_L39_005F33E0(0, 0, o);
        func_L39_005BC330(o + 0x10, v80, 1);
        i = 1;
        if (D_L39_0025F740[6] != 0 && D_L39_0025F740[7] <= 0) {
            vsub_0054B4B8(vC0, (f32 *)(*(u8 **)(ex + 0x58) + 0x23A0), (f32 *)(o + 0x10));
            func_0038CF68(vC0, vC0, 1.0f);
        } else {
            func_0038CF68(vC0, D_L39_0025F780, 1.0f);
            f0 = func_0038CE68(vC0, v80);
            if (0.100000001f <= fabs_asm(f0)) {
                i = 0;
            }
        }
        f0 = 0.0f;
        if (i != 0) {
            f0 = func_003C3D30(o + 0x10, 0, 0, 0.5f);
        }
        func_L01_00349998(o, o + 0x10, vC0, lod, f0);
        func_L39_0054C2B0(o, v80, hitobj, flagC);
        goto cleanup;
    }
    if (func_0038CB00(ex + 0x24) == 0) {
        if (!(90.0f < func_0038CF38(o + 0x10, *(u8 **)(ex + 0x58) + 0xA0))) {
            return;
        }
    }
    if (*(s32 *)(ex + 0x64) != -1 && ex[0x6D] != 0) {
        send_0054B4B8(ex, 4, 0x80);
    }
    func_L01_0044BEC8(o, D_L39_0024C040);
    func_L01_004C8668(*(s32 *)(ex + 0x50));
    func_L39_0054ABC0(o);
    func_003C2880(o);
    return;
cleanup:
    func_L01_0044BEC8(o, D_L39_0024C040);
    func_L01_004C8668(*(s32 *)(ex + 0x50));
    func_L39_0054ABC0(o);
    func_003C2880(o);
}
