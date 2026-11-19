/* functional: high. Not byte-near (register/stack-slot allocation and constant pool vs immediates differ) but same instruction count and call order. Omits the 8-iteration busy-wait (7 down to 0, five nops per pass, no side effects) that retail has before the colour setup (it would need volatile/asm; timing only). */
typedef struct {
    u8 pad0[0x2544];
    s32 i2544;
} P_006068A0;

typedef struct {
    u8 pad0[0xB0];
    f32 fB0;
} V_006068A0;

extern u8 D_L39_004840A0[];
extern V_006068A0 D_L39_0025D6C0;
extern u8 **D_L39_0024BD48[];
extern s32 D_L39_002456B0;
extern s32 D_L39_002456B4;
extern s32 D_L39_002456B8;
extern s32 D_L39_002456BC;
extern s32 D_L39_002456C0;
extern u32 D_L39_002456C4;

extern P_006068A0 *func_L39_0061BF38(s32);
extern void func_L39_005872D8(void);
extern u32 *func_L39_006010E0(void *);
extern f32 *func_L39_006010D8(void *);
extern void func_L39_006015C0(void *);
extern void func_L39_00602258(s32, s32, u32 *, u32 *, u32 *);
extern void func_L01_00430110(s32);
extern void func_003A9440(s32, unsigned long);
extern void func_003AAF00(void *, s32);
extern void func_003AB890(void *);

typedef void (*Vfn_006068A0)(void *);

void func_L39_006068A0(u8 *ui, s32 pl) {
    P_006068A0 *p;
    f32 f20;
    u8 *e0, *e1, *e2, *e3, *e4, *e5, *e6, *e7;
    u8 *n28, *n5C8, *n5F8, *nA90;
    u32 maskc;
    u32 c0, c1;
    s32 i, off;
    u32 t0, t4;
    u32 *r;

    p = func_L39_0061BF38(pl);
    if (*(s32 *)(D_L39_004840A0 + p->i2544 * 0x1C) == 0) {
        f20 = D_L39_0025D6C0.fB0;
        if (f20 != 0.62f) {
            D_L39_0025D6C0.fB0 = 0.62f;
            func_L39_005872D8();
        }
        e0 = ui + 0x244;
        e1 = ui + 0x4D8;
        e2 = ui + 0x280;
        e3 = ui + 0x514;
        e4 = ui + 0x49C;
        e5 = ui + 0x550;
        e6 = ui + 0x58C;
        e7 = ui + 0x664;
        n28 = ui + 0x628;
        n5C8 = ui + 0x5C8;
        n5F8 = ui + 0x5F8;
        nA90 = ui + 0xA90;
        *func_L39_006010E0(e0) = D_L39_002456B0;
        *func_L39_006010E0(e1) = D_L39_002456B4;
        maskc = 0x00FF0000;
        *func_L39_006010E0(e2) = D_L39_002456B8;
        maskc |= 0xFFFF;
        *func_L39_006010E0(e3) = D_L39_002456BC;
        *func_L39_006010E0(e4) = D_L39_002456C0;
        *func_L39_006010E0(e5) = D_L39_002456B0;
        *func_L39_006010E0(e6) = D_L39_002456BC;
        func_L01_00430110(1);
        func_003A9440(0x47, 0x513F1);
        func_L39_006015C0(e0);
        func_L39_006015C0(e1);
        func_L39_006015C0(e2);
        func_L39_006015C0(e3);
        func_L39_006015C0(e4);
        func_L39_006015C0(e5);
        func_L39_006015C0(e6);
        {
            f32 *q;
            q = func_L39_006010D8(e0); *q = -*q;
            q = func_L39_006010D8(e1); *q = -*q;
            q = func_L39_006010D8(e2); *q = -*q;
            q = func_L39_006010D8(e3); *q = -*q;
            q = func_L39_006010D8(e4); *q = -*q;
            func_L39_006015C0(e0);
            func_L39_006015C0(e1);
            func_L39_006015C0(e2);
            func_L39_006015C0(e3);
            func_L39_006015C0(e4);
            q = func_L39_006010D8(e0); *q = -*q;
            q = func_L39_006010D8(e1); *q = -*q;
            q = func_L39_006010D8(e2); *q = -*q;
            q = func_L39_006010D8(e3); *q = -*q;
            q = func_L39_006010D8(e4); *q = -*q;
            func_L39_006015C0(n28);
        }
        off = 0;
        for (i = 7; i >= 0; i--) {
            if (D_L39_0024BD48[pl] != 0 && *(s32 *)((u8 *)*D_L39_0024BD48[pl] + off + 0x18) > 0) {
                func_L39_00602258(pl, *(s32 *)((u8 *)*D_L39_0024BD48[pl] + off + 0x18), &c0, &c1, &D_L39_002456C4);
            }
            r = func_L39_006010E0(e7);
            e7 += 0x30;
            off += 0x1C;
            *r = (*r & 0xFF000000) | (D_L39_002456C4 & maskc);
        }
        r = func_L39_006010E0(n5C8);
        *r = (*r & 0xFF000000) | 0x6EC8FF;
        r = func_L39_006010E0(n5F8);
        *r = (*r & 0xFF000000) | 0x6EC8FF;
        for (i = 0; i < 8; i++) {
            u8 *obj = ui + 0x664 + i * 0x30;
            (*(Vfn_006068A0 *)(*(u8 **)(obj + 0x24) + 8))(obj);
        }
        func_003AB890(n5C8);
        func_003AB890(n5F8);
        *func_L39_006010E0(n28) = 0x706EC8FF;
        if (nA90[0x28] == 0) {
            func_003AAF00(n28, 0);
        }
        if (f20 != 0.62f) {
            D_L39_0025D6C0.fB0 = f20;
            func_L39_005872D8();
        }
    }
    func_L01_00430110(0);
}
