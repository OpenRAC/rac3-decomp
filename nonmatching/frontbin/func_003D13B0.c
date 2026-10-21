/* US draft of func_003D13B0 (rac3-uya-decomp func_003CBE40, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: unmapped symbols: func_003CC950 func_003CCB40 func_003CCFB0 func_003CD250. */


/* localdecomp:start func_003D13B0 */
__asm__(".extern D_001DA6F0, 4");
__asm__(".extern D_001D9340, 4");

typedef struct { s32 x0; void *x4; s32 x8; s32 xC; } Q_003CBE40;
typedef struct {
    s32 x0;
    s32 x4;
    f32 x8;
    f32 xC;
    f32 x10;
    f32 x14;
    f32 x18;
    u8 pad1C[4];
    u8 x20[0x10];
} R_003CBE40;
typedef struct { u8 pad[0x150]; s16 x150; s16 x152; } V_003CBE40;

extern Q_003CBE40 *D_001DA050[1];
extern s32 D_001DA6F0;
extern s32 D_001D9340;
extern volatile s32 D_001D9344;
extern f32 D_001DA6E0;
extern f32 D_001DA6E4;
extern u8 D_001D5477;
extern u8 D_1420B0[];
extern u8 D_003801F0[];
extern V_003CBE40 D_1CFEC0;
extern s32 D_1A1ED0[];

extern void func_003D1030();
extern void func_003D11E0();
extern void func_003D0EC8(void *, f32);
extern void func_003D1E28(f32 *, f32 *);
extern s32 func_003CCB40(s32, s32);
extern void func_003CC950(s32, s32);
extern void func_003CCFB0(s32, s32);
extern void func_003D2380(s32, s32);
extern void func_003CD250(s32);
extern void func_003A9440(s32, unsigned long);

void func_003D13B0(R_003CBE40 *q) {
    R_003CBE40 *r;
    Q_003CBE40 *start;
    s32 a, b, k, res, n;
    f32 v0[4];
    f32 v1[4];

    func_003D1030();
    r = q;
    D_001DA050[0]->x0 = 0x30000007;
    D_001DA050[0]->x4 = D_1420B0;
    D_001DA050[0]->x8 = 0x13000000;
    D_001DA050[0]->xC = 0x50000007;
    (++D_001DA050[0])->x0 = 0x30000003;
    D_001DA050[0]->x4 = D_003801F0;
    D_001DA050[0]->x8 = 0x13000000;
    D_001DA050[0]->xC = 0x50000003;
    start = D_001DA050[0] + 1;
    D_001DA6E0 = (D_1CFEC0.x150 >> 1) - 0x800;
    D_001DA6E4 = (D_1CFEC0.x152 >> 1) - 0x800;
    D_001DA050[0] = D_001DA050[0] + 2;
    if (D_001D5477) {
        b = 1;
        a = 2;
    } else {
        b = 2;
        a = 1;
    }
    while (r->x0 != 0) {
        q++;
        func_003D0EC8(r->x20, 1000.0f);
        v1[0] = v0[0] = r->x10;
        v1[1] = v0[1] = r->x14;
        v1[2] = v0[2] = r->x18;
        v0[3] = -r->x8 - r->xC;
        v1[3] = -r->x8 + r->xC;
        for (k = 0; k < r->x0; k++) {
            q = (R_003CBE40 *)func_003D0FD8((s16 *)q);
            func_003D1E28(v0, v1);
            if (r->x4 != 0) {
                res = func_003CCB40(0x70000000, D_001DA6F0);
            } else {
                func_003CC950(0x70000000, D_001DA6F0);
                res = 0;
            }
            if (res != 0) {
                func_003CCFB0(a, D_001D9344);
                func_003CCFB0(b, D_001D9340);
                if (res & 0x20) {
                    func_003CD250(D_001D9340);
                }
            } else {
                func_003D2380(a, D_001D9344);
                func_003D2380(b, D_001D9340);
            }
        }
        r = q;
    }
    n = D_001DA050[0] - start - 1;
    if (n > 0) {
        start->x0 = n | 0x10000000;
        start->x4 = 0;
        start->x8 = 0;
        start->xC = n | 0x50000000;
    } else {
        D_001DA050[0]--;
    }
    func_003A9440(0x4C, 0x80000 | (D_1A1ED0[1] >> 13));
    func_003A9440(0x42, (0x8000L << 22) | 0x64);
    func_003D11E0(0);
    func_003A9440(0x47, 0x5360B);
    func_003A9440(0x42, (0x8000L << 24) | 0x44);
}
/* localdecomp:end func_003D13B0 */
