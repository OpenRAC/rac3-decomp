/* functional: high. Same reads/writes/calls in same order; only compiler scheduling and lui$at addressing differ. Note: case 2 divides 0.01f by a vector length with no zero guard, as retail. */
typedef struct { s32 w0; s32 w4; f32 f8; f32 fC; f32 f10; } Ent_0048BA38;
typedef struct { s32 id; u8 flag; u8 pad[0xA3]; Ent_0048BA38 *ent; s32 padAC; } Slot_0048BA38;
extern Slot_0048BA38 D_L01_00233DD8[];
extern f32 D_L01_001D8A5C;
extern f32 D_L01_001D8A60;
extern f32 D_L01_001D8A58;
extern s32 D_L01_001D8A18;
extern s32 D_L01_001D8A1C;
extern s32 D_L01_001D8A2C;
extern s32 D_L01_001D8A30;
extern s32 D_L01_001D8A34;
extern s32 D_L01_001D8A38;
extern s32 D_L01_001D8A24;
extern s32 D_L01_001D8A20;
extern s32 D_L01_001D8A14;
extern f32 D_L01_001E0890[];
extern f32 D_L01_001E0894[];
extern s32 D_L01_001E0898[];
extern s32 D_L01_001E089C[];
extern f32 D_L01_001E08A0[];
extern f32 D_L01_001E08A4[];
extern s32 D_L01_001E08A8[];
extern s32 D_L01_001E08AC[];
extern s32 D_L01_001E08D0[];
extern void func_L01_00517190(s32, s32);
extern f32 func_0038CEA8(void *);
extern void func_L01_0048BF00(void);

void func_L01_0048BA38(s32 state) {
    f32 sign = 1.0f;
    f32 d;
    f32 len;
    s32 n;
    Ent_0048BA38 *e;
    f32 v[4];

    if ((u32)state < 5) {
        switch (state) {
        case 0:
            func_L01_0048BF00();
            D_L01_001D8A2C = D_L01_001D8A34;
            e = D_L01_00233DD8[D_L01_001D8A34].ent;
            D_L01_001E0890[0] = e->f8;
            D_L01_001E0898[0] = 0;
            D_L01_001E0894[0] = e->fC;
            D_L01_001E089C[0] = 0;
            D_L01_001D8A5C = e->f10;
            func_L01_00517190(0x13000F, e->w0);
            D_L01_001D8A1C = D_L01_001D8A18;
            break;
        case 1:
        case 4:
            func_L01_0048BF00();
            if (state == 1) {
                D_L01_001D8A58 = 3.5f;
            } else {
                D_L01_001D8A30 = D_L01_001D8A34;
                D_L01_001D8A58 = D_L01_00233DD8[D_L01_001D8A34].ent->f10;
            }
            d = D_L01_001D8A58 - D_L01_001D8A5C;
            if (d < 0.0f) {
                d = -d;
                sign = -1.0f;
            }
            n = (s32)(d / 0.1f);
            if (n < 16) {
                D_L01_001D8A60 = sign * 0.1f;
            } else {
                D_L01_001D8A60 = sign * (d / 15.0f);
            }
            break;
        case 2:
            func_L01_0048BF00();
            D_L01_001D8A38 = D_L01_001D8A34;
            e = D_L01_00233DD8[D_L01_001D8A34].ent;
            v[0] = e->f8;
            v[1] = e->fC;
            v[2] = 0.0f;
            v[3] = 1.0f;
            D_L01_001E08A0[0] = e->f8 - D_L01_001E0890[0];
            D_L01_001E08A4[0] = e->fC - D_L01_001E0894[0];
            D_L01_001E08A8[0] = 0;
            D_L01_001E08AC[0] = 0;
            len = func_0038CEA8(D_L01_001E08A0);
            n = (s32)(len / 0.01f);
            D_L01_001D8A24 = n;
            if (n >= 16) {
                D_L01_001E08A0[0] = D_L01_001E08A0[0] / 15.0f;
                D_L01_001D8A14 = 15;
                D_L01_001E08A4[0] = D_L01_001E08A4[0] / 15.0f;
                D_L01_001D8A24 = 15;
                D_L01_001E08D0[0] = state;
                return;
            }
            D_L01_001D8A14 = (30 - n) >> 1;
            d = 0.01f / len;
            D_L01_001E08A4[0] = D_L01_001E08A4[0] * d;
            D_L01_001E08A0[0] = D_L01_001E08A0[0] * d;
            break;
        case 3:
            func_L01_0048BF00();
            e = D_L01_00233DD8[D_L01_001D8A38].ent;
            D_L01_001E0890[0] = e->f8;
            D_L01_001E0894[0] = e->fC;
            D_L01_001D8A20 = D_L01_001D8A14 - 2;
            D_L01_001E0898[0] = 0;
            D_L01_001E089C[0] = 0;
            break;
        }
    }
    D_L01_001E08D0[0] = state;
}
