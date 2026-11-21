/* functional: medium. Multiplayer target picker: finds the best target for an attacker at obj within radius (and optional z limit): scans the 40-record candidate table (nearest valid entry within radius, radius*2 when its object equals a3), then the 8 players (alive per func_L39_006481F8, not a1, protected-value checks: Dec(+0x19E6)!=0x14 and DecF(+0x2476)>0; position from the player's carried object or its +0x2524 object), then in mode 0 a fallback object from the current-slot lookup; returns the nearest candidate's id, or falls back to func_L40_0053DE38 when none and a2 is set. The scrambled-value reads reuse the matched Dec helper shape (pool D_L40_003BFE20, stride 255); float read is the float variant of it. Compiles; whole function differs in regalloc/scheduling only (not verified block by block with a gate). */
typedef int Q_0053E1A8 __attribute__((mode(TI)));

typedef union Buf_0053E1A8 {
    unsigned char b[8];
    unsigned int w[2];
    float f[2];
} Buf_0053E1A8;

typedef struct Rec_0053E1A8 {
    int w0;
    int w1;
    unsigned char *w2;
} Rec_0053E1A8;

extern unsigned char D_L40_003BFE20[];
extern Rec_0053E1A8 D_L40_003478D0[];
extern unsigned char *D_L40_00249330[];
extern unsigned char *D_L40_00241640[];
extern unsigned char *D_L40_0035746C[];
extern float func_L01_0040E570(void *, void *);
extern int func_L39_006481F8(void *);
extern int *func_L39_0061D7B0(void *);
extern int func_L40_0053DE38(int, unsigned char *, float);

static __inline__ unsigned int Dec_0053E1A8(unsigned char *q) {
    unsigned int b;

    if (*q == 0) {
        b = 0;
    } else {
        Buf_0053E1A8 buf;
        unsigned char *dp;
        unsigned int a;
        int n;
        int k;
        int m;
        int j;

        n = *q;
        k = ((unsigned int)q - n) & 7;
        m = n + 1;
        dp = buf.b;
        for (j = 0; j < 40; j += 5) {
            *dp++ = D_L40_003BFE20[m + ((k + j) & 7) * 255];
        }
        a = buf.w[0] ^ (unsigned int)q;
        b = buf.w[1] ^ a;
        buf.w[0] = a;
        buf.w[1] = b;
    }
    return b;
}

static __inline__ float DecF_0053E1A8(unsigned char *q) {
    float r;

    if (*q == 0) {
        r = 0.0f;
    } else {
        Buf_0053E1A8 buf;
        unsigned char *dp;
        unsigned int a;
        int n;
        int k;
        int m;
        int j;

        n = *q;
        k = ((unsigned int)q - n) & 7;
        m = n + 1;
        dp = buf.b;
        for (j = 0; j < 40; j += 5) {
            *dp++ = D_L40_003BFE20[m + ((k + j) & 7) * 255];
        }
        a = buf.w[0] ^ (unsigned int)q;
        buf.w[0] = a;
        buf.w[1] = buf.w[1] ^ a;
        r = buf.f[1];
    }
    return r;
}

int func_L40_0053E1A8(unsigned char *obj, int a1, int a2, int a3, float radius, float radius2, float zlimit) {
    float r2;
    float bestA;
    float bestB;
    float d;
    float dz;
    float vec[4] __attribute__((aligned(16)));
    Rec_0053E1A8 *rec;
    unsigned char *o;
    unsigned char *q;
    unsigned char *g;
    unsigned char *m;
    int bestIdx;
    int bestId;
    int i;
    int in;
    int w0;
    int *res;

    r2 = radius * radius;
    bestIdx = -1;
    bestA = 999999.0f;
    for (i = 0; i < 40; i++) {
        rec = &D_L40_003478D0[i];
        w0 = rec->w0;
        if (w0 == 0) {
            continue;
        }
        o = rec->w2;
        if (o[0x31] != 1) {
            continue;
        }
        if (*(int *)o != w0) {
            continue;
        }
        if (rec->w1 == a1) {
            continue;
        }
        q = *(unsigned char **)(o + 0x1C);
        if (*(short *)(q + 0xAA) == 0x109D) {
            if (*(int *)(*(unsigned char **)(q + 0x68) + 0x264) == 0x539) {
                continue;
            }
        }
        d = func_L01_0040E570(obj + 0x10, q + 0x10);
        if (*(int *)(rec->w2 + 0x1C) != a3) {
            in = d < r2;
        } else {
            in = d < r2 * 4.0f;
        }
        if (zlimit != -1.0f) {
            dz = *(float *)(obj + 0x18) - *(float *)(*(unsigned char **)(rec->w2 + 0x1C) + 0x18);
            if (dz < 0.0f) {
                dz = -dz;
            }
            if (zlimit < dz) {
                in = 0;
            }
        }
        if (in == 0) {
            continue;
        }
        if (!(d < bestA)) {
            continue;
        }
        bestA = d;
        bestIdx = i;
    }

    bestId = -1;
    bestB = 10000.0f;
    for (i = 0; i < 8; i++) {
        g = D_L40_00249330[i];
        if (g == 0) {
            continue;
        }
        if (func_L39_006481F8(g) == 0) {
            continue;
        }
        if (*(int *)(g + 0x2548) == a1) {
            continue;
        }
        if (Dec_0053E1A8(g + 0x19E6) == 0x14) {
            continue;
        }
        if (!(0.0f < DecF_0053E1A8(g + 0x2476))) {
            continue;
        }
        if (*(int *)(g + 0x2528) != 0 && *(int *)(*(unsigned char **)(g + 0x2528) + 0x2D0) != 0) {
            *(Q_0053E1A8 *)vec = *(Q_0053E1A8 *)(*(unsigned char **)(*(unsigned char **)(g + 0x2528) + 0x2D0) + 0x10);
        } else if (*(int *)(g + 0x2558) != 0 && *(int *)(g + 0x2524) != 0) {
            *(Q_0053E1A8 *)vec = *(Q_0053E1A8 *)(*(unsigned char **)(g + 0x2524) + 0x10);
        } else {
            vec[0] = 0.0f;
            vec[1] = 0.0f;
            vec[2] = 0.0f;
            vec[3] = 0.0f;
        }
        d = func_L01_0040E570(obj + 0x10, vec);
        in = 0;
        if ((*(int *)(g + 0x2528) != 0 && *(int *)(*(unsigned char **)(g + 0x2528) + 0x2D0) == a3) ||
            *(int *)(g + 0x2524) == a3) {
            in = d < r2 * 4.0f;
        } else {
            in = d < r2;
        }
        if (zlimit != -1.0f) {
            dz = *(float *)(obj + 0x18) - vec[2];
            if (dz < 0.0f) {
                dz = -dz;
            }
            if (zlimit < dz) {
                in = 0;
            }
        }
        if (in == 0) {
            continue;
        }
        if (!(d < bestB)) {
            continue;
        }
        bestId = *(int *)g;
        bestB = d;
    }

    if (*(int *)(D_L40_00241640[0] + 0x180) == 0) {
        int x;
        int y;

        if (a1 == 0) {
            x = *(int *)(D_L40_0035746C[0] + 0x44);
        } else {
            x = *(int *)(D_L40_0035746C[0] + 0x40);
        }
        if (x != -1) {
            m = D_L40_0024845C;
            y = *(int *)(*(unsigned char **)(m + (x << 8) + 0x68) + 0xB4);
            if (y != -1) {
                o = m + (y << 8);
                d = func_L01_0040E570(o + 0x10, obj + 0x10);
                if (d < r2 && d < bestB) {
                    dz = *(float *)(o + 0x18) - *(float *)(obj + 0x18);
                    if (dz < 0.0f) {
                        dz = -dz;
                    }
                    if (dz < 15.0f) {
                        res = func_L39_0061D7B0(o);
                        if (res != 0) {
                            bestId = *res;
                            bestB = d;
                        }
                    }
                }
            }
        }
    }

    if (bestIdx == -1 && bestId == -1) {
        if (a2 == 0) {
            return -1;
        }
        if (radius2 == -1.0f) {
            return func_L40_0053DE38(a1, obj, r2);
        }
        return func_L40_0053DE38(a1, obj, radius2 * radius2);
    }
    if (bestB < bestA) {
        return bestId;
    }
    return D_L40_003478D0[bestIdx].w0;
}
