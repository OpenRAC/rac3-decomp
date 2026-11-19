/* functional: high. Compiles; ~whole-function diff is regalloc/scheduling. Every branch (bounds kills, e==0, flag 0x1000/type 5, hero or 0x1366 owner, real hit) traced against the asm, including delay-slot stores (p->w24=0 happens in the delay slot of the e==0 and type!=5 branches). Uses file context S_277090/D_L01_00277090 (declared earlier in the file) and vu0_q. */
extern s32 func_L01_0040E050(void *);
extern s32 func_L01_004CB2D8(void);
extern void func_L01_004CAB30(void *, void *);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_00446760(void *, void *, s32, void *, f32);
extern void func_L01_00446978(void *, void *);
extern void func_L01_0034C9F0(void *, s32, s32);
extern void func_L01_0032DED0(void *, s32);
extern u8 D_001EAA20[];
extern u8 *D_001EAA18[];
extern u8 D_001A4BE0[];
extern u8 D_001425C0[];
extern u8 D_L01_002C5600[];

void func_L01_0032CB38(u8 *obj) {
    u8 *vars = *(u8 **)(obj + 0x68);
    S_277090 *p;
    s32 i;
    f32 old[4] __attribute__((aligned(16)));
    f32 dir[4] __attribute__((aligned(16)));
    u8 hit[0x20] __attribute__((aligned(16)));
    u8 *e;
    u8 *q;
    s32 snd;

    for (i = 0; i < 100; i++) {
        p = &D_L01_00277090[i];
        if (p->w24 != (s32)obj) {
            continue;
        }
        if (func_L01_0040E050((u8 *)p + 0x20) != 0 ||
            ((f32 *)p)[0] < 2.0f || 1021.0f < ((f32 *)p)[0] ||
            ((f32 *)p)[1] < 2.0f || 1021.0f < ((f32 *)p)[1] ||
            ((f32 *)p)[2] < 2.0f || 1021.0f < ((f32 *)p)[2]) {
            p->w24 = 0;
            *(u16 *)(vars + 0x66) = *(u16 *)(vars + 0x66) - 1;
            continue;
        }
        *(vu0_q *)old = p->q0;
        vec_add_ab(p, p, &p->q10);
        if (func_L01_004CB2D8() != 0) {
            func_L01_004CAB30(p, p);
        }
        if (func_003D3CB0(old, p, 0, obj, 0) == 0) {
            continue;
        }
        e = D_001EAA18[0];
        if (e == 0) {
            p->w24 = 0;
            snd = 3;
        } else if ((*(u16 *)(e + 0x34) & 0x1000) == 0 && (*(u8 **)(e + 0x24))[0x46] != 5) {
            p->w24 = 0;
            snd = 3;
        } else if (e == *(u8 **)(D_001A4BE0 + 0x25C0) || *(s16 *)(e + 0xAA) == 0x1366) {
            p->w24 = 0;
            snd = 3;
        } else {
            func_0038CF68(dir, &p->q10, 1.0f);
            q = D_L01_002C5600 + D_001425C0[0x15] * 0xF0;
            if (q[1] >= 2) {
                func_L01_00446760(hit, obj, 0x10010000, dir, *(f32 *)(q + 0x6C));
            } else {
                func_L01_00446760(hit, obj, 0x10000, dir, *(f32 *)(q + 0x6C));
            }
            hit[0x18] = 1;
            hit[0x19] = 3;
            *(u16 *)(hit + 0x1A) = *(u16 *)(obj + 0xAA);
            func_L01_00446978(e, hit);
            func_L01_0034C9F0(e, 0x15, *(s32 *)(obj + 0xB8));
            p->w24 = 0;
            snd = 6;
        }
        *(u16 *)(vars + 0x66) = *(u16 *)(vars + 0x66) - 1;
        func_L01_0032DED0(D_001EAA20, snd);
    }
}
