/* functional: medium. Written from the retail assembly (no draft). Camera/aim follow target for the hero struct: picks the active target record (D_001A4BE0 + 0x3C0), probes it with the three record helpers and updates the offset vectors at +0x3B0/+0x500/+0x100. Not byte checked; vector stores keep retail's whole-quad copies. */
/* localdecomp:start func_L01_00511B50 */
static __inline__ void v4_sub(void *d, void *a, void *b) {
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
            : "=m"(*(vu0_v4 *)d) : "m"(*(vu0_v4 *)a), "m"(*(vu0_v4 *)b) : "vf1", "vf2");
}
static __inline__ void v4_add(void *d, void *a, void *b) {
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
            : "=m"(*(vu0_v4 *)d) : "m"(*(vu0_v4 *)a), "m"(*(vu0_v4 *)b) : "vf1", "vf2");
}
static __inline__ void qzero_511B50(vu0_v4 *p) {
    p->x = 0.0f; p->y = 0.0f; p->z = 0.0f; p->w = 0.0f;
}
typedef struct {
    u8 pad0[0x80];
    vu0_v4 v80;
    vu0_v4 v90;               /* 0x90; .z (0x98) is the angle the tail turns toward */
    vu0_v4 vA0[6];
    vu0_v4 v100;              /* 0x100; .w (0x10C) receives the turn delta */
    u8 pad110[0x150 - 0x110];
    vu0_v4 v150;
    vu0_v4 v160;
    u8 pad170[0x1A4 - 0x170];
    f32 f1A4;
    u8 pad1A8[0x1B8 - 0x1A8];
    s32 w1B8;
    u8 pad1BC[0x216 - 0x1BC];
    s16 h216;
    u8 pad218[0x226 - 0x218];
    s16 h226;
    u8 pad228[0x284 - 0x228];
    f32 f284;
    u8 pad288[0x35C - 0x288];
    s32 w35C;
    u8 pad360[0x36E - 0x360];
    s16 h36E;
    vu0_v4 v370;
    vu0_v4 v380;
    vu0_v4 v390;
    u8 pad3A0[0x3B0 - 0x3A0];
    vu0_v4 v3B0;
    s32 w3C0;
    s32 w3C4;
    u8 pad3C8[0x46C - 0x3C8];
    u8 b46C;
    u8 pad46D[0x47C - 0x46D];
    s16 h47C;
    u8 pad47E[0x500 - 0x47E];
    vu0_v4 v500;
    u8 pad510[0x524 - 0x510];
    f32 f524;
    u8 pad528[0x538 - 0x528];
    s32 w538;
    u8 pad53C[0x25C0 - 0x53C];
    u8 *moby;                 /* 0x25C0 */
    s32 w25C4;
    u8 pad25C8[4];
    s32 w25CC;
    u8 pad25D0[0x25E4 - 0x25D0];
    u8 b25E4;
    u8 b25E5;
} G_00511B50;
extern D_001A4BE0_t D_001A4BE0;

void func_L01_00511B50(void) {
    extern u8 *func_003C4D58(s32);
    extern s32 func_L01_0044C638(u8 *, s32, void *, void *, void *, void *);
    extern s32 func_L01_0044C998(u8 *, s32, void *, void *, void *, void *);
    extern s32 func_L01_0044CB18(u8 *, s32, void *, void *, void *, void *);
    extern f32 func_0038CEA8(void *);
    extern void func_0038CFB8(f32 *, f32 *, f32);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern f32 func_0038D160(f32, f32);
    extern f32 func_0038DAB8(f32, f32);
    extern f32 func_0038DB00(f32, f32);
    extern void func_003C4138(f32 *, f32, f32);
    G_00511B50 *g = (G_00511B50 *)&D_001A4BE0;
    s32 active = 0;
    s32 flag = 0;
    f32 yaw = 0.0f;
    f32 keep = g->v90.z;
    u8 *rec;
    vu0_v4 t0, t10, t20, t30, t40, t50, t60, t70, t80, t90, tA0;
    f32 st[2];

    if (g->w25CC == 0 || g->w25CC == 12) {
        flag = (g->w25C4 != 0x68);
    }
    if (g->w25CC == 4) {
        if (g->b46C != 0) {
            flag = 1;
        }
    }
    if (g->h36E == 0) {
        if (g->w35C != 0) {
            active = 1;
            if (g->w3C0 != g->w35C) {
                g->w3C4 &= ~1;
            }
            g->w3C0 = g->w35C;
        } else {
            g->w3C0 = 0;
            g->w3C4 &= ~3;
        }
    } else if (g->w25C4 == 0x1B && g->w538 != 0) {
        g->w3C0 = g->w538;
        active = 1;
    } else if (g->w25CC == 3 && g->w538 != 0) {
        g->w3C0 = g->w538;
        active = 1;
    } else if (g->w3C0 != 0) {
        yaw = (f32)g->h36E;
        active = 1;
        if (g->w25CC == 4 && !(g->w1B8 < g->h47C - 1)) {
            if (yaw < 2.0f) {
                yaw = 2.0f;
            }
        }
    } else {
        g->w3C0 = 0;
        g->w3C4 &= ~3;
    }
    if (active == 0) {
        return;
    }
    rec = func_003C4D58(g->w3C0);
    if (rec == 0) {
        return;
    }
    {
        s32 cond = 0;
        if (flag != 0) {
            if (func_0038CEA8(&g->v160) == 0.0f && g->h36E == 0 && g->h216 == 0) {
                cond = 1;
            }
        }
        if (g->w25CC == 3) {
            cond = 1;
        }
        if (cond != 0) {
            if (!(g->w3C4 & 1)) {
                if (g->w25CC == 3) {
                    f32 pi = 3.1415925f;
                    t20 = g->v500;
                    t20.x += func_0038D098(func_0038DAB8(g->f524, pi)) * g->f284;
                    t20.y += func_0038D0B0(func_0038DAB8(g->f524, pi)) * g->f284;
                    if (g->b25E4 == 0) {
                        t20.z = t20.z - -1.43f;
                    } else {
                        t20.z = t20.z - -2.5f;
                    }
                    func_L01_0044C638(g->moby, g->w3C0, &g->v500, &g->v90, &t30, &t40);
                    func_L01_0044C638(g->moby, g->w3C0, &t20, &g->v90, &t20, &t40);
                    func_L01_0044CB18(g->moby, g->w3C0, &g->v500, &g->v90, &g->v370, &t40);
                    func_L01_0044CB18(g->moby, g->w3C0, &t20, &g->v90, &g->v390, &t40);
                } else {
                    if (*(s32 *)(rec + 0x3C) & 4) {
                        func_L01_0044CB18(g->moby, g->w3C0, &g->v80, &g->v90, &g->v370, &t20);
                    } else {
                        func_L01_0044C638(g->moby, g->w3C0, &g->v80, &g->v90, &t30, &t40);
                        func_L01_0044CB18(g->moby, g->w3C0, &t30, &t40, &g->v370, &t20);
                    }
                }
                g->w3C4 |= 1;
            }
        } else {
            g->w3C4 &= ~1;
        }
    }
    if (flag != 0) {
        if (g->f1A4 != 0.0f) {
            g->w3C4 &= ~2;
        } else if (g->h36E != 0) {
            g->w3C4 &= ~2;
        } else if (!(g->w3C4 & 2)) {
            func_L01_0044CB18(g->moby, g->w3C0, &g->v80, &g->v90, &t20, &g->v380);
            g->w3C4 |= 2;
        }
    } else {
        g->w3C4 &= ~2;
    }
    qzero_511B50(&t20);
    qzero_511B50(&t30);
    if (g->w3C4 & 3) {
        active = 2;
    }
    if (yaw != 0.0f) {
        s32 flags3C;
        st[1] = ((f32 (*)(void *))func_0038CED8)(&g->v3B0);
        flags3C = *(s32 *)(rec + 0x3C);
        st[0] = g->v3B0.z;
        if (!(flags3C & 2)) {
            f32 limit = 2.0f;
            if (flags3C & 0x10) {
                limit = 20.0f;
            }
            if (g->b25E4 == 5) {
                if (limit < 23.0f) {
                    limit = 23.0f;
                }
            }
            func_003C4138(&st[0], 0.0f, yaw * 0.010000001f);
            limit = limit * 0.00040000002f;
            func_003C4138(&st[1], 0.0f, limit * yaw);
            if (g->b25E4 == 5 && g->w25CC == 4) {
                if (st[0] < 0.0f) {
                    st[0] = 0.0f;
                }
            }
            func_0038CFB8((f32 *)&t20, (f32 *)&g->v3B0, st[1]);
            t20.z = st[0];
        } else if (g->w3C0 != 0) {
            func_L01_0044C638(g->moby, g->w3C0, &g->v80, &g->v90, &t0, &t10);
            if (g->h226 == 0) {
                g->v90 = t10;
            }
            v4_sub(&t20, &t0, &g->v80);
            g->v3B0 = t20;
        } else {
            t20 = g->v3B0;
        }
        t30 = t20;
    } else if (active == 1) {
        func_L01_0044C638(g->moby, g->w3C0, &g->v80, &g->v90, &t0, &t10);
        if (g->h226 == 0) {
            g->v90 = t10;
        }
        v4_sub(&t20, &t0, &g->v80);
        g->v3B0 = t20;
    } else if (active == 2) {
        func_L01_0044C638(g->moby, g->w3C0, &g->v80, &g->v90, &t40, &t50);
        func_L01_0044C998(g->moby, g->w3C0, &g->v370, &g->v380, &t60, &t70);
        func_L01_0044C998(g->moby, g->w3C0, &g->v390, &g->v380, &t80, &t90);
        if (g->h226 == 0) {
            if ((g->w25C4 == 1 || g->w25C4 == 0x1D) && g->b25E5 != 0) {
                g->v90.z = t50.z;
            } else if (g->w3C4 & 2) {
                g->v90.z = t70.z;
            } else {
                g->v90.z = t50.z;
            }
        }
        if (g->w3C4 & 1) {
            if (g->w25CC == 3) {
                tA0.x = func_0038D098(g->f524) * 0.45f;
                tA0.y = func_0038D0B0(g->f524) * 0.45f;
                tA0.z = 0.0f;
                v4_add(&tA0, &tA0, &t80);
                if (g->b25E4 == 0) {
                    tA0.z = tA0.z + -1.43f;
                } else {
                    tA0.z = tA0.z + -2.5f;
                }
                v4_sub(&t20, &t40, &g->v80);
                g->v500 = tA0;
                g->f524 = func_0038D160(t60.x - t80.x, t60.y - t80.y);
            } else {
                f32 len;
                v4_sub(&t20, &t60, &g->v80);
                len = func_0038CEA8(&t20);
                if (len < 0.0001f) {
                    qzero_511B50(&t20);
                    g->v80 = t60;
                } else if (2.0f < len) {
                    qzero_511B50(&t20);
                    g->w3C4 &= ~3;
                }
                v4_add(&g->v500, &g->v500, &t20);
                v4_sub(&tA0, &t20, &g->v150);
                if (0.1f < func_0038CEA8(&tA0)) {
                    g->w3C4 &= ~1;
                }
            }
        } else {
            v4_sub(&t20, &t40, &g->v80);
            t30 = t20;
        }
        g->v3B0 = t20;
    }
    v4_add(&g->v100, &g->v100, &t20);
    g->v100.w = func_0038DB00(g->v90.z, keep);
}
/* localdecomp:end func_L01_00511B50 */
