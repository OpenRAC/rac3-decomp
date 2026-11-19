/* functional: medium. 348 diff words at the file's flags (scheduling/registers and a different block order); the dispatch (state 0 return, 1, 2, 3, 0x5A kill), the kill conditions (hero+0x1200 target type 0xC0, hero+0x25E4, bounds 2.0..1021.0 on m+0x10/14/18), the (x*5+2)/6 timer reloads, the gp slots and the func_L01_0044AF78 argument set (8 reg ints, 4 stack ints, 7 floats; stack words 5,-1,0,0x1010001 matched) checked against retail. Retail's dead copy of the old position into sp+0x20 in state 1 is omitted. */
typedef struct { f32 x, y, z, w; } V4;
typedef int Q16 __attribute__((mode(TI)));
extern u8 D_001A4BE0[];
extern u8 D_001A4EC0[];
extern u8 D_001D66B0[];
extern u8 D_L01_001EAA30[];
extern f32 D_001DD024_sda;
extern s32 D_001DD02C_sda;
extern s32 D_001DD03C_sda;
extern s32 D_001DD040_sda;
extern f32 D_001DD044_sda;
extern f32 D_001DD048_sda;
extern u8 *D_001DD04C_sda;
extern void func_003C2880(u8 *);
extern void func_003C5278(void *, void *, void *, f32);
extern f32 func_0038DAB8(f32, f32);
extern void func_L01_0033ED30(u8 *);
extern s32 func_0038CB00(void *);
extern s32 func_0038CAD0(void *);
extern f32 func_0038CE68(void *, void *);
extern void func_L01_00340248(u8 *);
extern void func_0038CDF8(void *, void *, void *, f32);
extern void func_L01_003402E8(u8 *);
extern void func_L01_0033F530(void *);
extern void func_L01_00404A10(void (*)(void *), void *);
extern s32 func_L01_003FB640(void *, s32, s32, f32);
extern void func_L01_0033F1F0(u8 *);
extern void func_L01_0033F388(u8 *);
extern void func_L01_0033EE50(u8 *);
extern void func_L01_0033EF90(u8 *);
extern void func_L01_0044AF78(u8 *, void *, void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32);

void func_L01_0033E760(u8 *m) {
    u8 *hero = D_001A4BE0;
    u8 *p = *(u8 **)(m + 0x68);
    u8 *v;
    u16 fl;
    f32 x;
    f32 d;
    V4 zero;
    s32 st;

    v = *(u8 **)(hero + 0x1200);
    if (v == 0 || *(s16 *)(v + 0xAA) != 0xC0) {
        if (m[0x20] == 0) {
            func_003C2880(m);
            return;
        }
    }
    if (hero[0x25E4] != 0) {
        if (m[0x20] == 0) {
            func_003C2880(m);
            return;
        }
    }
    fl = *(u16 *)(m + 0x34);
    if ((hero[0x25E5] != 0 || hero[0x25F0] != 0) && m[0x20] == 0) {
        fl |= 0x41;
    } else {
        fl &= 0xFFBE;
    }
    *(u16 *)(m + 0x34) = fl;
    st = m[0x20];
    if (st == 2) {
        goto state2;
    }
    if (st < 3) {
        if (st == 1) {
            goto state1;
        }
        return;
    }
    if (st == 3) {
        goto state3;
    }
    if (st == 0x5A) {
        func_003C2880(m);
    }
    return;

state1:
    {
        V4 *mp = (V4 *)(m + 0x10);
        V4 *pv = (V4 *)(p + 0x30);
        mp->x = mp->x + pv->x;
        mp->y = mp->y + pv->y;
        mp->z = mp->z + pv->z;
    }
    func_003C5278(m + 0x10, p + 0x30, p + 0x30, D_001DD024_sda * 0.00040000002f);
    *(f32 *)(m + 0xF0) = func_0038DAB8(*(f32 *)(m + 0xF0), *(f32 *)(p + 0xC));
    *(f32 *)(m + 0xF4) = func_0038DAB8(*(f32 *)(m + 0xF4), *(f32 *)(p + 0x10));
    func_L01_0033ED30(m);
    if (func_0038CB00(p + 4) != 0) {
        func_003C2880(m);
        return;
    }
    x = *(f32 *)(m + 0x10);
    if (x < 2.0f || 1021.0f < x) {
        func_003C2880(m);
        return;
    }
    x = *(f32 *)(m + 0x14);
    if (x < 2.0f || 1021.0f < x) {
        func_003C2880(m);
        return;
    }
    x = *(f32 *)(m + 0x18);
    if (x < 2.0f || 1021.0f < x) {
        func_003C2880(m);
        return;
    }
    d = func_0038CE68(D_001A4EC0, p + 0x30);
    if (!(0.0f < d)) {
        return;
    }
    if (func_0038CB00(p + 6) == 0) {
        return;
    }
    m[0x20] = 2;
    *(s16 *)(p + 8) = (D_001DD02C_sda * 5 + 2) / 6;
    *(s16 *)(p + 0xA) = (D_001DD03C_sda * 5 + 2) / 6;
    *(Q16 *)(p + 0x20) = *(Q16 *)(p + 0x30);
    func_L01_00340248(m);
    return;

state2:
    func_0038CDF8(p + 0x30, D_001D66B0, p + 0x20,
                  (f32)*(s16 *)(p + 0xA) / (f32)((D_001DD03C_sda * 5 + 2) / 6));
    {
        V4 *mp = (V4 *)(m + 0x10);
        V4 *pv = (V4 *)(p + 0x30);
        mp->x = mp->x + pv->x;
        mp->y = mp->y + pv->y;
        mp->z = mp->z + pv->z;
    }
    *(f32 *)(m + 0xF0) = func_0038DAB8(*(f32 *)(m + 0xF0), *(f32 *)(p + 0xC));
    *(f32 *)(m + 0xF4) = func_0038DAB8(*(f32 *)(m + 0xF4), *(f32 *)(p + 0x10));
    func_L01_003402E8(m);
    func_L01_00404A10(func_L01_0033F530, m);
    if (func_L01_003FB640(m + 0x10, 0, *(s32 *)(hero + 0x25C0), 0.25f) != 0) {
        *(Q16 *)(m + 0x10) = *(Q16 *)D_L01_001EAA30;
    }
    x = *(f32 *)(m + 0x10);
    if (x < 2.0f || 1021.0f < x) {
        func_003C2880(m);
        return;
    }
    x = *(f32 *)(m + 0x14);
    if (x < 2.0f || 1021.0f < x) {
        func_003C2880(m);
        return;
    }
    x = *(f32 *)(m + 0x18);
    if (x < 2.0f || 1021.0f < x) {
        func_003C2880(m);
        return;
    }
    if (func_0038CB00(p + 0xA) == 0) {
        return;
    }
    if (D_001DD04C_sda != 0) {
        return;
    }
    m[0x20] = 3;
    *(s32 *)(p + 0x14) = (D_001DD040_sda * 5 + 2) / 6;
    D_001DD04C_sda = m;
    func_L01_0033F1F0(m);
    return;

state3:
    *(f32 *)(m + 0xF0) = func_0038DAB8(*(f32 *)(m + 0xF0), *(f32 *)(p + 0xC));
    *(f32 *)(m + 0xF4) = func_0038DAB8(*(f32 *)(m + 0xF4), *(f32 *)(p + 0x10));
    func_L01_003402E8(m);
    func_L01_0033F388(m);
    if (*(s16 *)(p + 8) >= 0x32) {
        func_L01_0033EF90(m);
    }
    func_L01_00404A10(func_L01_0033F530, m);
    func_0038CAD0(p + 0x14);
    if (*(s32 *)(p + 0x14) != 0) {
        f32 t = (f32)*(s32 *)(p + 0x14) / (f32)((D_001DD040_sda * 5 + 2) / 6);
        if (func_L01_003FB640(m + 0x10, 2, *(s32 *)(hero + 0x25C0),
                              D_001DD048_sda + (D_001DD044_sda - D_001DD048_sda) * t) != 0) {
            *(Q16 *)(m + 0x10) = *(Q16 *)D_L01_001EAA30;
        }
    }
    func_L01_0033EE50(m);
    if (func_0038CB00(p + 8) == 0) {
        return;
    }
    *(unsigned long *)&zero = 0;
    *((unsigned long *)&zero + 1) = 0;
    func_L01_0044AF78(m, &zero, m + 0x10, 5, 2, 4, -1, 1, 5, -1, 0, 0x1010001, 0.0f, 0.0f, 4.0f, 2.0f, 9.0f, 1.0f, 15.0f);
    D_001DD04C_sda = 0;
    m[0x20] = 0x5A;
}
