/* functional: medium. No draft; written from asm and read against it block by block. 425 diff words (regalloc, 7 saved FP regs). Omitted a 7-iteration empty nop delay loop (no effect). Format strings D_001DB738/740/748 read from the ELF ('\'', '.', 'x%d'). Medium: callee return types of the 8-byte field accessors (004CC748/50/58) are inferred as pointers */
typedef struct Obj_004D1700 Obj_004D1700;
typedef struct {
    u8 pad[8];
    void (*fn8)(Obj_004D1700 *);
} Vt_004D1700;
struct Obj_004D1700 {
    u8 pad[36];
    Vt_004D1700 *vt;
    u8 pad2[20];
};

extern s32 D_L01_002D15F0[];
extern f32 D_L01_001E7580[];
extern s32 D_00142660[];
extern u8 D_00143950[];
extern u8 D_001DB738[];
extern u8 D_001DB740[];
extern u8 D_001DB748[];
extern u32 D_001DB71C_sda;
extern u32 D_001DB720_sda;
extern u32 D_001DB724_sda;
extern u32 D_001DB728_sda;
extern u32 D_001DB72C_sda;
extern u32 D_001DB730_sda;
extern s32 D_001DB348_sda;
extern s32 D_001DB34C_sda;
extern u32 D_001DB350_sda;
extern void func_003873C0(void);
extern void func_L01_004CB540(u8);
extern void func_003A9440(s32, s32);
extern u32 *func_L01_004CC758(u8 *);
extern f32 *func_L01_004CC750(u8 *);
extern f32 *func_L01_004CC748(u8 *);
extern void func_003AB398(u8 *);
extern void func_003AB890(u8 *);
extern void func_003ABAC8(u8 *);
extern void func_003AAF00(u8 *, s32);
extern long func_00389598(s32);
extern void func_L01_00412BC0(s32, s32, s32, f32, f32, f32);
extern s32 func_L01_004129E0(s32, s32, s32, s32, s32);
extern s32 func_0011B2E8(char *, char *, ...);

void func_L01_004D1700(u8 *obj) {
    f32 f20 = 0.0f;
    u8 *a0, *a1, *a2, *a3, *a4, *a5, *a6, *a7;
    u8 *A, *B, *C, *D;
    s32 i;
    f32 px, py, f25, f21, f24, f26, f23, f27;
    u32 color;
    s32 digits;
    s32 sel;
    u8 *cur;
    char buf[0x20];

    if (D_L01_002D15F0[0] == 0) {
        f20 = D_L01_001E7580[0x2C];
        if (f20 != 0.62f) {
            D_L01_001E7580[0x2C] = 0.62f;
            func_003873C0();
        }
        a0 = obj + 0x244;
        a1 = obj + 0x4D8;
        a2 = obj + 0x280;
        a3 = obj + 0x514;
        a4 = obj + 0x49C;
        a5 = obj + 0x550;
        a6 = obj + 0x58C;
        A = obj + 0x628;
        B = obj + 0x5C8;
        C = obj + 0x5F8;
        D = obj + 0xA90;
        *func_L01_004CC758(a0) = D_001DB71C_sda;
        *func_L01_004CC758(a1) = D_001DB720_sda;
        *func_L01_004CC758(a2) = D_001DB724_sda;
        *func_L01_004CC758(a3) = D_001DB728_sda;
        *func_L01_004CC758(a4) = D_001DB72C_sda;
        *func_L01_004CC758(a5) = D_001DB71C_sda;
        *func_L01_004CC758(a6) = D_001DB728_sda;
        func_L01_004CB540(1);
        func_003A9440(0x47, 0x513F1);
        func_003AB398(a0);
        func_003AB398(a1);
        func_003AB398(a2);
        func_003AB398(a3);
        func_003AB398(a4);
        func_003AB398(a5);
        func_003AB398(a6);
        {
            f32 *p;
            p = func_L01_004CC750(a0); *p = -*p;
            p = func_L01_004CC750(a1); *p = -*p;
            p = func_L01_004CC750(a2); *p = -*p;
            p = func_L01_004CC750(a3); *p = -*p;
            p = func_L01_004CC750(a4); *p = -*p;
            func_003AB398(a0);
            func_003AB398(a1);
            func_003AB398(a2);
            func_003AB398(a3);
            func_003AB398(a4);
            p = func_L01_004CC750(a0); *p = -*p;
            p = func_L01_004CC750(a1); *p = -*p;
            p = func_L01_004CC750(a2); *p = -*p;
            p = func_L01_004CC750(a3); *p = -*p;
            p = func_L01_004CC750(a4); *p = -*p;
        }
        func_003AB398(A);
        {
            u8 *e = obj + 0x664;
            for (i = 7; i >= 0; i--) {
                u32 *p = func_L01_004CC758(e);
                e += 0x30;
                *p = (*p & 0xFF000000) | (D_001DB730_sda & 0xFFFFFF);
            }
        }
        {
            u32 *p = func_L01_004CC758(B);
            *p = (*p & 0xFF000000) | 0x6EC8FF;
            p = func_L01_004CC758(C);
            *p = (*p & 0xFF000000) | 0x6EC8FF;
        }
        for (i = 0; i < 8; i++) {
            Obj_004D1700 *o = (Obj_004D1700 *)(obj + 0x664 + i * 0x30);
            o->vt->fn8(o);
        }
        func_003AB890(B);
        func_003AB890(C);
        *func_L01_004CC758(A) = 0x706EC8FF;
        if (D[0x28] == 0) {
            func_003AAF00(A, 0);
        }
        if (f20 != 0.62f) {
            D_L01_001E7580[0x2C] = f20;
            func_003873C0();
        }
    }
    func_L01_004CB540(0);
    cur = obj + 0x1D0;
    func_003AB398(obj + 0x140);
    func_003AB398(obj + 0x17C);
    func_003ABAC8(cur);
    func_003AB890(obj + 0x210);
    px = func_L01_004CC748(cur)[0];
    py = func_L01_004CC748(cur)[1];
    px = px + 32.0f;
    py = py + -10.0f;
    color = *func_L01_004CC758(cur);
    digits = 1;
    {
        s32 n = D_00142660[0];
        if (n >= 10) {
            do {
                n = n / 10;
                digits++;
            } while (n >= 10);
        }
    }
    {
        u8 b = D_00143950[0xB7];
        sel = 0;
        if (b != 3) {
            sel = (b != 5);
        }
    }
    func_0011B2E8(buf, (char *)(sel ? D_001DB738 : D_001DB740));
    f25 = (f32)digits;
    {
        s32 yoff = sel ? 0x15 : 0xA;
        s32 xoff = sel ? -0x22 : -0x1D;
        f21 = 3.0f;
        if (f21 < f25) {
            f24 = (f32)yoff;
            f27 = 11.6f;
            f26 = f21;
            f23 = px + (f32)xoff;
            f20 = f21 * f27;
            do {
                f32 t;
                f32 *zp;
                f32 xx;
                s32 v;
                f21 += f26;
                t = (f32)(s32)f20;
                xx = f23 - t;
                zp = func_L01_004CC750(cur);
                v = (s32)*(s32 *)(cur + 0x30);
                func_00389598(v);
                func_L01_00412BC0(color, (s32)buf, -1, xx, py + f24, *zp);
                f20 = f21 * f27;
            } while (f21 < f25);
        }
    }
    {
        u8 cnt = ((u8 *)D_00142660)[0x5A];
        s32 cnt1 = cnt + 1;
        if (cnt1 >= 2) {
            u32 alpha = color & 0xFF000000;
            u32 col2 = (D_001DB350_sda & 0xFFFFFF) | alpha;
            s32 xa = D_001DB348_sda;
            s32 ya = D_001DB34C_sda;
            char buf2[0x20];
            func_0011B2E8(buf2, (char *)D_001DB748, cnt1);
            func_L01_004129E0(xa, ya + 2, alpha, (s32)buf2, -1);
            func_L01_004129E0(xa + 2, ya, alpha, (s32)buf2, -1);
            func_L01_004129E0(xa + 2, ya + 2, alpha, (s32)buf2, -1);
            func_L01_004129E0(xa, ya, col2, (s32)buf2, -1);
        }
    }
}
