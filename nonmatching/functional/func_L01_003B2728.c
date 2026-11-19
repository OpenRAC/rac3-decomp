/* functional: high. Same reads, writes, vtable calls and order; only s2/s3 register assignment and tail branch layout differ (near miss). */
typedef struct {
    u8 p0[0x1C];
    s32 (*f1C)(void);
    u8 p20[0xC];
    void (*f2C)(void *, f32);
    s32 (*f30)(s32);
    s32 (*f34)(void);
    s32 (*f38)(void);
    s32 (*f3C)(s32);
    s32 (*f40)(void);
} V_003B2728;

typedef struct {
    u8 p0[0x10];
    s32 w10;
    u8 p14[0x18];
    f32 f2C;
    s32 w30;
    s32 w34;
    u8 p38[4];
    s32 w3C;
    u8 p40[0x10];
    u8 b50;
    u8 p51[0x13];
    s32 w64;
} P_003B2728;

typedef struct {
    u8 p0[0x20];
    u8 state;
    u8 p21[0x13];
    u16 h34;
    u8 p36[0x32];
    P_003B2728 *p68;
} M_003B2728;

extern u8 *D_L01_001E001C;
extern f32 D_L01_001DF950;
__asm__(".extern D_L01_001DF950, 16");
extern s32 D_001A7430[];
extern s32 D_00142668[];
extern V_003B2728 *func_L01_0043B548(s32, s32);
extern void func_L01_003B2DC8(void);
extern s32 func_L01_00327408(void);
extern void func_L01_00456230(void *, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_003B2AA0(void *, void *);

void func_L01_003B2728(M_003B2728 *m) {
    P_003B2728 *p = m->p68;
    V_003B2728 *v = func_L01_0043B548(0x19E1, 0x6C);
    s32 id;
    u8 *ent;

    func_L01_003B2DC8();
    if (p->w30 == 0) {
        D_001A7430[0] = D_00142668[0];
    }
    m->h34 &= 0xFFFD;
    id = -2;
    if (p->w30 != 0) {
        id = -3;
        if (p->b50 == 0) {
            id = p->w34;
        }
    }
    if (!v->f30(id) && !func_L01_00327408()) {
        if (v->f34()) {
            D_L01_001DF950 = 2.0f;
            p->w64 = 0x11;
            func_L01_004450F0(m, 2, -1);
            return;
        }
    }
    if (p->w3C != -1) {
        ent = D_L01_001E001C + (p->w3C << 8);
        ent[0x30] = 0xFF;
        *(u16 *)(ent + 0x34) &= 0xFFFD;
        func_L01_00456230(ent, 1);
        func_L01_004450F0(m, 4, -1);
        D_L01_001DF950 = 2.0f;
        return;
    }
    if (id != -3) {
        if (!v->f30(id)) {
            if (v->f3C(id)) {
                D_L01_001DF950 = 2.0f;
                p->w64 = 0x11;
                func_L01_004450F0(m, 3, -1);
                return;
            }
        }
    }
    func_L01_003B2AA0(m, p);
}
