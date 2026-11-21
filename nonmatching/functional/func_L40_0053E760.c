/* functional: medium. Looks up the object for an entity id and writes its 16-byte position to *out: first the object of func_L39_0066C1F0(id) (position of its linked object +0x1C, z raised 0.35 for type 0x109D, returns that object), else the player func_L39_0061BFB0(id) when its protected values pass (Dec(+0x19E4)!=0x39, Dec(+0x19E6)!=0x14, DecF(+0x2476)>0) and its sub-objects are valid (position of the carried object +0x2D0 when its +0x308 health is positive, else of +0x2524), else a virtual-call lookup (vtable +0x10 of func_L39_0061D1D8(id)); with a3 set also accepts a type 2..5 object. Compiles; branch layout and regalloc differ. */
typedef int Q_0053E760 __attribute__((mode(TI)));

typedef union Buf_0053E760 {
    unsigned char b[8];
    unsigned int w[2];
    float f[2];
} Buf_0053E760;

extern unsigned char D_L40_003BFE20[];
extern unsigned char *func_L39_0066C1F0(int);
extern unsigned char *func_L39_0061BFB0(int);
extern unsigned char *func_L39_0061D1D8(int);

static __inline__ unsigned int Dec_0053E760(unsigned char *q) {
    unsigned int b;

    if (*q == 0) {
        b = 0;
    } else {
        Buf_0053E760 buf;
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

static __inline__ float DecF_0053E760(unsigned char *q) {
    float r;

    if (*q == 0) {
        r = 0.0f;
    } else {
        Buf_0053E760 buf;
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

static __inline__ unsigned char *Virt_0053E760(int id) {
    unsigned char *x = func_L39_0061D1D8(id);
    unsigned char *(**vt)(unsigned char *);

    if (x == 0) {
        return 0;
    }
    vt = *(unsigned char *(***)(unsigned char *))(x + 0x14);
    return vt[4](x);
}

unsigned char *func_L40_0053E760(int id, Q_0053E760 *out, int a2, int a3) {
    unsigned char *r5;
    unsigned char *p;
    unsigned char *s;
    unsigned char *o;
    unsigned char *t;
    unsigned char *v;

    r5 = func_L39_0066C1F0(id);
    if (r5 != 0) {
        if (r5[0x31] != 0 && *(int *)(r5 + 0x18) != a2 && *(int *)(*(unsigned char **)(r5 + 0x1C) + 0x98) != 0) {
            *out = *(Q_0053E760 *)(*(unsigned char **)(r5 + 0x1C) + 0x10);
            if (*(short *)(*(unsigned char **)(r5 + 0x1C) + 0xAA) == 0x109D) {
                *(float *)((unsigned char *)out + 8) = *(float *)((unsigned char *)out + 8) + 0.35f;
            }
            return *(unsigned char **)(r5 + 0x1C);
        }
        return 0;
    }
    p = func_L39_0061BFB0(id);
    if (p != 0 && Dec_0053E760(p + 0x19E4) != 0x39 && Dec_0053E760(p + 0x19E6) != 0x14 &&
        0.0f < DecF_0053E760(p + 0x2476) && *(int *)(p + 0x2558) != 0 &&
        *(int *)(*(unsigned char **)(p + 0x2558) + 4) != 0 &&
        *(int *)(*(unsigned char **)(*(unsigned char **)(p + 0x2558) + 4) + 0x40) != a2) {
        o = *(unsigned char **)(p + 0x2528);
        if (o != 0 && *(unsigned char **)(o + 0x2D0) != 0) {
            if (*(float *)(o + 0x308) <= 0.0f) {
                return 0;
            }
            t = *(unsigned char **)(o + 0x2D0);
            *out = *(Q_0053E760 *)(t + 0x10);
            return *(unsigned char **)(o + 0x2D0);
        }
        t = *(unsigned char **)(p + 0x2524);
        *out = *(Q_0053E760 *)(t + 0x10);
        return *(unsigned char **)(p + 0x2524);
    }
    v = Virt_0053E760(id);
    if (v != 0) {
        *out = *(Q_0053E760 *)(v + 0x10);
        return v;
    }
    if (a3 == 0) {
        return 0;
    }
    if (p != 0) {
        return 0;
    }
    v = Virt_0053E760(id);
    if (v == 0) {
        return 0;
    }
    if ((unsigned char)(v[0x20] - 2) < 4) {
        *out = *(Q_0053E760 *)(v + 0x10);
        return v;
    }
    return 0;
}
