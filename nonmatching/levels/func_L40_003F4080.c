/* func_L40_003F4080 (levels 39-53, src/levels/shared/L40_003F2E88.c): near miss, 21 aligned rows.
   API swarm Sonnet draft + Opus finisher. Left: the slot pointer D_1FE020 + (idx << 7) is not
   CSEd (retail computes it once into $v0, base in $a1); writing it through one pointer variable
   CSEs it but flips the hoisted float constants (2.0/0.0/6.0/-1.0/3.0 into $f22..$f26) and the
   index register. Two sw ordering rows around the 005B8978 call. */
typedef struct N_003F4080 {
    u8 p0[8];
    s32 type;
    s32 wC;
    s32 time;
    s32 w14;
    s32 data[4];
    u8 p28[0x84 - 0x28];
    struct N_003F4080 *next;
} N_003F4080;
typedef struct { s32 w[4]; } B_003F4080;
typedef struct { u8 pad[0x128]; s32 w128; } G_003F4080;
typedef struct { f32 x, y, z, w; } V_003F4080;

extern G_003F4080 D_1A5CD0;
extern u8 D_1FE020[];
__asm__(".extern D_L40_00242930, 16");
extern V_003F4080 D_L40_00242930 __attribute__((section(".sdata")));
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003C3A10(u8 *, s32, s32, s32);
extern u32 func_L40_0053F018(u8 *);
extern s32 func_L40_0053F038(u8 *, s32);
extern s32 func_L40_0053F068(u8 *, s32, s32);
extern s32 func_L40_0053E760(s32, void *, s32, s32);
extern u8 *func_L39_0061BF38(s32);
extern void func_L39_005F3088(s32);
extern void func_L40_0053F6E0(u8 *);
extern void func_L39_005F2FF8(void *, s32);
extern N_003F4080 *func_L39_0066C3C8(N_003F4080 *, N_003F4080 **);
extern void func_L39_005B8978(u8 *, void *, void *, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32);
extern void func_L01_00451FE0(void *m, s32 a, void *b, f32 x1, f32 x2, f32 x3, f32 x4, s32 e,
                              f32 x5, f32 x6, s32 f, s32 g, s32 c, s32 d, f32 x0, f32 one,
                              s32 h, s32 k);

void func_L40_003F4080(s32 a0, u8 *self) {
    u8 *mv = *(u8 **)(self + 0x90);
    N_003F4080 *p = *(N_003F4080 **)(mv + 0x38);
    u8 *v = *(u8 **)(self + 0x68);
    s32 *q;
    s32 m1;
    s32 i;
    u8 *slot;
    u8 *e;

    while (p != 0) {
        q = &p->type;
        if (q[2] > D_1A5CD0.w128) {
            p = p->next;
            continue;
        }
        switch (p->type) {
        case 1:
            switch (q[3]) {
            case 0:
                func_L01_004450F0(self, 7, -1);
                if (self[0x43] != 2) {
                    func_003C3A10(self, 2, 0, 6);
                }
                *(B_003F4080 *)(v + 0x220) = *(B_003F4080 *)p->data;
                p = func_L39_0066C3C8(p, (N_003F4080 **)(mv + 0x38));
                continue;
            case 2:
                *(f32 *)(v + 0x230) = 0.8f;
                *(f32 *)(v + 0x238) = 0.5f;
                if (self[0x43] != 2) {
                    func_003C3A10(self, 2, 0, 3);
                }
                func_L01_004450F0(self, 3, -1);
                if (func_L40_0053F018(self) == 0) {
                    *(s32 *)(v + 0x2A4) = 1;
                }
                p = func_L39_0066C3C8(p, (N_003F4080 **)(mv + 0x38));
                continue;
            case 3:
                func_L01_004450F0(self, 4, -1);
                if (self[0x43] != 3) {
                    func_003C3A10(self, 3, 0, 3);
                }
                if (func_L40_0053F018(self) == 0) {
                    *(s32 *)(v + 0x2A4) = 10;
                }
                p = func_L39_0066C3C8(p, (N_003F4080 **)(mv + 0x38));
                continue;
            case 1:
                func_L01_004450F0(self, 2, -1);
                *(f32 *)(v + 0x230) = 0.8f;
                *(f32 *)(v + 0x238) = 0.1f;
                if (self[0x43] != 2) {
                    func_003C3A10(self, 2, 0, 6);
                }
                *(s32 *)(v + 0x2E0) = p->data[0];
                if (func_L40_0053F018(self) == 0) {
                    *(s32 *)(v + 0x2A4) = 4;
                    *(s32 *)(v + 0x2C0) = *(s32 *)(v + 0x2E0);
                }
                p = func_L39_0066C3C8(p, (N_003F4080 **)(mv + 0x38));
                if (*(s32 *)(v + 0x2E0) != -1) {
                    for (i = 0; i < 4; i++) {
                        e = func_L39_0061BF38(i);
                        if (*(s32 *)e == *(s32 *)(v + 0x2E0)) {
                            func_L40_0053F038(self, q[2]);
                        }
                    }
                    if (i == 8) {
                        func_L40_0053F068(self, **(s32 **)(e + 0x2558), q[2]);
                    }
                }
                continue;
            default:
                p = func_L39_0066C3C8(p, (N_003F4080 **)(mv + 0x38));
                continue;
            }
            break;
        case 2: {
            m1 = -1;
            {
                s32 idx = *(s32 *)(v + 0x2CC);
                if (idx != m1) {
                    if (*(u8 **)(D_1FE020 + (idx << 7) + 0xDC) == self && D_1FE020[(idx << 7) + 0xD0]) {
                        func_L39_005F3088(idx);
                    }
                }
            }
            m1 = -1;
            *(s32 *)(v + 0x2CC) = m1;
            func_L39_005B8978(self, v + 0x2B0, self + 0x10, 5, 2, 4, 2.0f, 0.0f, 2.0f, 1.0f, 9.0f, 1.0f, 0.0f, -1, 0, 1, m1, 0, 0x1010001);
            func_L01_00451FE0(self, 15, &D_L40_00242930, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
            func_L40_0053F6E0(self);
            func_L01_004450F0(self, 0x25, -1);
            *(s32 *)(self + 0x98) = 0;
            *(u16 *)(self + 0x34) = (*(u16 *)(self + 0x34) | 0x41) & 0xEFFF;
            func_L39_005F2FF8(self, 1);
            return;
        }
        default:
            break;
        }
        p = func_L39_0066C3C8(p, (N_003F4080 **)(mv + 0x38));
    }
    if (*(s32 *)(v + 0x2E0) != 0) {
        func_L40_0053E760(*(s32 *)(v + 0x2E0), v + 0x2D0, -1, 0);
    }
}
